CREATE DATABASE Movie_Theaters;

GO

USE Movie_Theaters;

GO

CREATE TABLE Movies
(
	Code INT NOT NULL,
	Title VARCHAR(100),
	Rating VARCHAR(10),
	PRIMARY KEY(Code)
);

CREATE TABLE MovieTheaters
(
	Code INT NOT NULL,
	Name VARCHAR(100),
	Movie INT,
	PRIMARY KEY(Code)
);

GO

ALTER TABLE MovieTheaters ADD
	CONSTRAINT FK_MovieTheaters_Movie
	FOREIGN KEY(Movie) REFERENCES Movies(Code);

GO

INSERT INTO Movies(Code,Title,Rating) VALUES(9,'Citizen King','G');
INSERT INTO Movies(Code,Title,Rating) VALUES(1,'Citizen Kane','PG');
INSERT INTO Movies(Code,Title,Rating) VALUES(2,'Singin'' in the Rain','G');
INSERT INTO Movies(Code,Title,Rating) VALUES(3,'The Wizard of Oz','G');
INSERT INTO Movies(Code,Title,Rating) VALUES(4,'The Quiet Man',NULL);
INSERT INTO Movies(Code,Title,Rating) VALUES(5,'North by Northwest',NULL);
INSERT INTO Movies(Code,Title,Rating) VALUES(6,'The Last Tango in Paris','NC-17');
INSERT INTO Movies(Code,Title,Rating) VALUES(7,'Some Like it Hot','PG-13');
INSERT INTO Movies(Code,Title,Rating) VALUES(8,'A Night at the Opera',NULL);

GO

INSERT INTO MovieTheaters(Code,Name,Movie) VALUES(1,'Odeon',5);
INSERT INTO MovieTheaters(Code,Name,Movie) VALUES(2,'Imperial',1);
INSERT INTO MovieTheaters(Code,Name,Movie) VALUES(3,'Majestic',NULL);
INSERT INTO MovieTheaters(Code,Name,Movie) VALUES(4,'Royale',6);
INSERT INTO MovieTheaters(Code,Name,Movie) VALUES(5,'Paraiso',3);
INSERT INTO MovieTheaters(Code,Name,Movie) VALUES(6,'Nickelodeon',NULL);

GO

-- 1. Select the title of all movies.
SELECT Title
FROM Movies;

-- 2. Show all the distinct ratings in the database.
SELECT DISTINCT Rating
FROM Movies;

-- 3. Show all unrated movies.
SELECT Title
FROM Movies
WHERE Rating IS NULL;

-- 4. Select all movie theaters that are not currently showing a movie.
SELECT Name
FROM MovieTheaters
WHERE Movie IS NULL;

-- 5. Select all data from all movie theaters and, additionally, the data from the movie that is being shown in the theater
-- (if one is being shown).
SELECT *
FROM MovieTheaters mt LEFT JOIN Movies m on mt.Movie = m.Code;

-- 6. Select all data from all movies and, if that movie is being shown in a theater, show the data from the theater.
SELECT *
FROM Movies m LEFT JOIN MovieTheaters mt on m.Code = mt.Movie;

-- 7. Show the titles of movies not currently being shown in any theaters.
SELECT m.Title
FROM Movies m LEFT JOIN MovieTheaters mt on m.Code = mt.Movie
WHERE mt.Movie IS NULL;

-- 8. Add the unrated movie "One, Two, Three".
INSERT INTO Movies(Title, Rating, Code) VALUES
	('One, Two, Three', NULL, 10);

-- 9. Set the rating of all unrated movies to "G".
UPDATE Movies
	SET Rating = 'G'
	WHERE Rating IS NULL;

SELECT * FROM Movies;

-- 10. Remove movie theaters projecting movies rated "NC-17".

DELETE FROM MovieTheaters
	WHERE Movie in (SELECT Code
		FROM Movies
		WHERE Rating = 'NC-17');

SELECT * FROM MovieTheaters;