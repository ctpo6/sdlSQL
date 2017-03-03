set noexec off
go

use master
go

declare @dbName nvarchar(64) = 'sdlSQL'

if exists
(
	select * from sys.databases where name = @dbName
)
begin
	raiserror('Database already created',16,1)
	set noexec on
end


declare
	@version int
	,@dataPath nvarchar(512)
	,@logPath nvarchar(512) 

set @version = 
	convert(int,
		left(
			convert(nvarchar(128), serverproperty('ProductVersion')),
			charindex('.',convert(nvarchar(128), serverproperty('ProductVersion'))) - 1
		)
	)

select 
    @dataPath = convert(nvarchar(512),serverproperty('InstanceDefaultDataPath'))
    , @logPath = convert(nvarchar(512),serverproperty('InstanceDefaultLogPath'))

-- Creating database in the same folder with master
if @dataPath is null
	select @dataPath = substring(physical_name, 1, len(physical_name) - charindex('\', reverse(physical_name))) + '\'
	from master.sys.database_files 
	where file_id = 1

if @logPath is null
	select @logPath = substring(physical_name, 1, len(physical_name) - charindex('\', reverse(physical_name))) + '\'
	from master.sys.database_files 
	where file_id = 2
	
if @dataPath is null or @logPath is null
begin
	raiserror('Cannot obtain path for data and/or log file',16,1)
	set noexec on
end

if right(@dataPath, 1) <> '\'
	select @dataPath = @dataPath + '\'
if right(@logPath, 1) <> '\'
	select @logPath = @logPath + '\'
	
declare
	@SQL nvarchar(max)


select @SQL = 
	replace
	(
		replace(
            replace (
N'create database [%DB%]
on primary (name=N''%DB%'', filename=N''%DATA%%DB%.mdf'', size=10MB, filegrowth = 10MB)
log on (name=N''%DB%_log'', filename=N''%LOG%%DB%.ldf'', size=10MB, filegrowth = 10MB);

alter database [%DB%] set recovery simple
'
                , '%DB%', @dbName
            ), '%DATA%', @dataPath
		), '%LOG%', @logPath
	)

raiserror('Creating database %s',0,1,@dbName) with nowait
raiserror('Data Path: %s',0,1,@dataPath) with nowait
raiserror('Log Path: %s',0,1,@logPath) with nowait
raiserror('Statement:',0,1) with nowait
raiserror(@sql,0,1) with nowait

exec sp_executesql @sql
go
