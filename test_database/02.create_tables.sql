use sdlSQL;
go

drop table dbo.Customers;
go
drop table dbo.Orders;
go
drop table dbo.OrderDetails;
go

CREATE TABLE dbo.Customers
(
  custid       INT          NOT NULL IDENTITY,
  companyname  NVARCHAR(40) NOT NULL,
  contactname  NVARCHAR(30) NOT NULL,
  city         NVARCHAR(30) NOT NULL,
  CONSTRAINT PK_Customers PRIMARY KEY(custid)
);
go

SET IDENTITY_INSERT dbo.Customers ON;
INSERT INTO dbo.Customers(custid, companyname, contactname, city)
  VALUES(1, 'Customer NRZBB', 'Allen, Michael', 'Berlin');
INSERT INTO dbo.Customers(custid, companyname, contactname, city)
  VALUES(2, 'Customer MLTDN', 'Hassall, Mark', 'Mexico');
INSERT INTO dbo.Customers(custid, companyname, contactname, city)
  VALUES(3, 'Customer KBUDE', 'Peoples, John', 'Mexico');
INSERT INTO dbo.Customers(custid, companyname, contactname, city)
  VALUES(4, 'Customer HFBZG', 'Arndt, Torsten', 'London');
INSERT INTO dbo.Customers(custid, companyname, contactname, city)
  VALUES(5, 'Customer HGVLZ', 'Higginbotham, Tom', 'Paris');
INSERT INTO dbo.Customers(custid, companyname, contactname, city)
  VALUES(6, 'Customer XHXJV', 'Poland, Carole', 'Berlin');
INSERT INTO dbo.Customers(custid, companyname, contactname, city)
  VALUES(7, 'Customer QXVLA', 'Bansal, Dushyant', 'Strasbourg');
INSERT INTO dbo.Customers(custid, companyname, contactname, city)
  VALUES(8, 'Customer QUHWH', 'Ilyina, Julia', 'Madrid');
INSERT INTO dbo.Customers(custid, companyname, contactname, city)
  VALUES(9, 'Customer RTXGC', 'Raghav, Amritansh', 'Paris');
INSERT INTO dbo.Customers(custid, companyname, contactname, city)
  VALUES(10, 'Customer EEALV', 'Bassols, Pilar Colome', 'Tsawassen');
SET IDENTITY_INSERT dbo.Customers OFF;
go


CREATE TABLE dbo.Orders
(
  orderid        INT          NOT NULL IDENTITY,
  custid         INT          NULL,
  shipname       NVARCHAR(40) NOT NULL,
  shipcountry    NVARCHAR(15) NOT NULL,
  CONSTRAINT PK_Orders PRIMARY KEY(orderid)
);
go

SET IDENTITY_INSERT dbo.Orders ON;
INSERT INTO dbo.Orders(orderid, custid, shipname, shipcountry)
  VALUES(1, 1, 'Ship to 85-B', 'France');
INSERT INTO dbo.Orders(orderid, custid, shipname, shipcountry)
  VALUES(2, 2, 'Ship to 79-C', 'Germany');
INSERT INTO dbo.Orders(orderid, custid, shipname, shipcountry)
  VALUES(3, 3, 'Destination SCQXA', 'Brazil');
INSERT INTO dbo.Orders(orderid, custid, shipname, shipcountry)
  VALUES(4, 4, 'Ship to 84-A', 'France');
INSERT INTO dbo.Orders(orderid, custid, shipname, shipcountry)
  VALUES(5, 5, 'Ship to 76-B', N'Belgium');
INSERT INTO dbo.Orders(orderid, custid, shipname, shipcountry)
  VALUES(6, 6, 'Destination JPAIY', N'Brazil');
INSERT INTO dbo.Orders(orderid, custid, shipname, shipcountry)
  VALUES(7, 7, 'Destination YUJRD', 'Switzerland');
INSERT INTO dbo.Orders(orderid, custid, shipname, shipcountry)
  VALUES(8, 8, 'Ship to 68-A', 'Switzerland');
INSERT INTO dbo.Orders(orderid, custid, shipname, shipcountry)
  VALUES(9, 9, 'Ship to 88-B', 'Brazil');
INSERT INTO dbo.Orders(orderid, custid, shipname, shipcountry)
  VALUES(10, 10, 'Destination JYDLM', 'Venezuela');
INSERT INTO dbo.Orders(orderid, custid, shipname, shipcountry)
  VALUES(11, 2, 'Destination RVDMF', 'Austria');
INSERT INTO dbo.Orders(orderid, custid, shipname, shipcountry)
  VALUES(12, 1, 'Destination LGGCH', 'Mexico');
INSERT INTO dbo.Orders(orderid, custid, shipname, shipcountry)
  VALUES(13, 5, 'Ship to 56-A', 'Germany');
INSERT INTO dbo.Orders(orderid, custid, shipname, shipcountry)
  VALUES(14, 6, 'Ship to 61-B', 'Brazil');
INSERT INTO dbo.Orders(orderid, custid, shipname, shipcountry)
  VALUES(15, 6, 'Ship to 65-B', 'USA');
SET IDENTITY_INSERT dbo.Orders OFF;
go


CREATE TABLE dbo.OrderDetails
(
  orderid   INT           NOT NULL,
  productid INT           NOT NULL,
  unitprice INT           NOT NULL,
  CONSTRAINT PK_OrderDetails PRIMARY KEY(orderid)
);
go

INSERT INTO dbo.OrderDetails(orderid, productid, unitprice)
  VALUES(1, 11, 14);
INSERT INTO dbo.OrderDetails(orderid, productid, unitprice)
  VALUES(2, 42, 9);
INSERT INTO dbo.OrderDetails(orderid, productid, unitprice)
  VALUES(3, 72, 34);
INSERT INTO dbo.OrderDetails(orderid, productid, unitprice)
  VALUES(4, 14, 18);
INSERT INTO dbo.OrderDetails(orderid, productid, unitprice)
  VALUES(5, 51, 42);
INSERT INTO dbo.OrderDetails(orderid, productid, unitprice)
  VALUES(6, 41, 7);
INSERT INTO dbo.OrderDetails(orderid, productid, unitprice)
  VALUES(7, 51, 42);
INSERT INTO dbo.OrderDetails(orderid, productid, unitprice)
  VALUES(8, 65, 16);
INSERT INTO dbo.OrderDetails(orderid, productid, unitprice)
  VALUES(9, 22, 16);
INSERT INTO dbo.OrderDetails(orderid, productid, unitprice)
  VALUES(10, 57, 15);
INSERT INTO dbo.OrderDetails(orderid, productid, unitprice)
  VALUES(11, 65, 16);
INSERT INTO dbo.OrderDetails(orderid, productid, unitprice)
  VALUES(12, 20, 64);
INSERT INTO dbo.OrderDetails(orderid, productid, unitprice)
  VALUES(13, 33, 2);
INSERT INTO dbo.OrderDetails(orderid, productid, unitprice)
  VALUES(14, 60, 27);
go
