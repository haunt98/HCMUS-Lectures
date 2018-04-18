create database pap;
go
use pap;
go

CREATE TABLE Pieces (
  Code INTEGER PRIMARY KEY NOT NULL,
  Name VARCHAR(100) NOT NULL
);
 
CREATE TABLE Providers (
 Code VARCHAR(100) PRIMARY KEY NOT NULL,
 Name VARCHAR(100) NOT NULL
);

CREATE TABLE Provides (
  Piece INTEGER  
    CONSTRAINT fk_Pieces_Code REFERENCES Pieces(Code),
  Provider VARCHAR(100)
    CONSTRAINT fk_Providers_Code REFERENCES Providers(Code),
  Price INTEGER NOT NULL,
  PRIMARY KEY(Piece, Provider)
);

go

INSERT INTO Providers(Code, Name) VALUES('HAL','Clarke Enterprises');
INSERT INTO Providers(Code, Name) VALUES('RBT','Susan Calvin Corp.');
INSERT INTO Providers(Code, Name) VALUES('TNBC','Skellington Supplies');

INSERT INTO Pieces(Code, Name) VALUES(1,'Sprocket');
INSERT INTO Pieces(Code, Name) VALUES(2,'Screw');
INSERT INTO Pieces(Code, Name) VALUES(3,'Nut');
INSERT INTO Pieces(Code, Name) VALUES(4,'Bolt');

INSERT INTO Provides(Piece, Provider, Price) VALUES(1,'HAL',10);
INSERT INTO Provides(Piece, Provider, Price) VALUES(1,'RBT',15);
INSERT INTO Provides(Piece, Provider, Price) VALUES(2,'HAL',20);
INSERT INTO Provides(Piece, Provider, Price) VALUES(2,'RBT',15);
INSERT INTO Provides(Piece, Provider, Price) VALUES(2,'TNBC',14);
INSERT INTO Provides(Piece, Provider, Price) VALUES(3,'RBT',50);
INSERT INTO Provides(Piece, Provider, Price) VALUES(3,'TNBC',45);
INSERT INTO Provides(Piece, Provider, Price) VALUES(4,'HAL',5);
INSERT INTO Provides(Piece, Provider, Price) VALUES(4,'RBT',7);

go

-- 1. Select the name of all the pieces.
select name 
from pieces;

-- 2. Select all the providers' data..
select *
from provides;

-- 3. Obtain the average price of each piece (show only the piece code and the average price).
select piece, avg(price)
from provides
group by piece;

-- 4. Obtain the names of all providers who supply piece 1.
select r.name
from provides s join providers r on s.provider = r.code
where s.piece = 1

-- 5. Select the name of pieces provided by provider with code "HAL".
select pie.name
from pieces pie join provides pro on pie.code = pro.piece
where pro.provider = 'HAL'

-- 6. For each piece, find the most expensive offering of that piece and include the piece name, provider name, and price 
-- (note that there could be two providers who supply the same piece at the most expensive price).
select pie.name, pror.name, pro.price
from pieces pie join provides pro on pie.code = pro.piece
	join Providers pror on pror.code = pro.provider
where pro.price >= all(
	select pro2.price
	from pieces pie2 join provides pro2 on pie2.code = pro2.piece
		join Providers pror2 on pror2.code = pro2.provider
	where pie.code = pie2.code
)

-- 8. Increase all prices by one cent.
update provides
	set price = price + 1