CREATE DATABASE IMiniDB

-- =========================
-- KORISNICI
-- =========================
CREATE TABLE korisnik (
    id INT AUTO_INCREMENT PRIMARY KEY,
    ime VARCHAR(100),
    prezime VARCHAR(100),
    korisnicko_ime VARCHAR(100) UNIQUE NOT NULL,
    email VARCHAR(150) UNIQUE NOT NULL,
    lozinka_hash VARCHAR(255) NOT NULL
);



SELECT * FROM korisnik
SELECT * FROM Filmovi
WHERE poster IS NULL 
ALTER TABLE Filmovi ADD COLUMN poster MEDIUMBLOB;
UPDATE Filmovi SET poster = NULL;

-- FDQuerySelect 
SELECT naslov,godina,trajanje,opis,zanr,redatelj,boxOffice,imdbRating,imdbVotes FROM Filmovi
SELECT poster FROM Filmovi

-- FDQuerySortGodina
SELECT naslov,godina,trajanje,opis,zanr,redatelj,boxOffice,imdbRating,imdbVotes 
FROM Filmovi
ORDER BY godina ASC

-- FDQueryFilterOcjena
SELECT naslov,godina,trajanje,opis,zanr,redatelj,boxOffice,imdbRating,imdbVotes 
FROM Filmovi
WHERE imdbRating >= 8
ORDER BY imdbRating DESC


-- FDQueryIzracun
SELECT COUNT(naslov)
FROM filmovi

INSERT INTO korisnik(ime,prezime,korisnicko_ime,email,lozinka_hash)
VALUES ("jan", "slopar", "slopy_", "js@gmail.com", "lozinkahash")

SELECT * FROM recenzija

-- =========================
-- ADMIN (nasljeđuje korisnika)
-- =========================
CREATE TABLE ADMIN (
    korisnik_id INT PRIMARY KEY,
    razina INT,
    odjel VARCHAR(100),
    FOREIGN KEY (korisnik_id) REFERENCES korisnik(id) ON DELETE CASCADE
);
-- =========================
-- FILM
-- =========================

CREATE TABLE Filmovi (
    id           INT AUTO_INCREMENT PRIMARY KEY,
    imdbID       VARCHAR(20) UNIQUE,
    naslov       VARCHAR(255),
    godina       INT,
    trajanje     INT,
    opis         TEXT,
    zanr         VARCHAR(255),
    redatelj     VARCHAR(255),
    scenarist    TEXT,
    glumci       TEXT,
    jezik        VARCHAR(255),
    drzava       VARCHAR(255),
    nagrade      TEXT,
    posterUrl    VARCHAR(500),
    rated        VARCHAR(20),
    `released`   VARCHAR(30),
    tip          VARCHAR(20),
    boxOffice    VARCHAR(30),
    imdbRating   DOUBLE,
    imdbVotes    INT,
    metascore    INT,
    ratingRT     DOUBLE
);

-- =========================
-- RECENZIJA
-- =========================
CREATE TABLE recenzija (
    id INT AUTO_INCREMENT PRIMARY KEY,
    tekst TEXT,
    ocjena INT CHECK (ocjena BETWEEN 1 AND 10),
    datum DATETIME DEFAULT CURRENT_TIMESTAMP,
    korisnik_id INT,
    FOREIGN KEY (korisnik_id) REFERENCES korisnik(id) ON DELETE CASCADE
);

ALTER TABLE recenzija ADD COLUMN naslov VARCHAR(255) NOT NULL AFTER id;

SELECT * FROM recenzija

-- 1. popuni postojeće filmove
UPDATE recenzija r
JOIN Filmovi f ON f.naslov = r.naslov
SET r.film_id = f.id;

-- 2. Provjeri da su svi popunjeni
SELECT id, naslov, film_id FROM recenzija WHERE film_id = 0;

-- 3. Obriši naslov stupac (više nije potreban)
ALTER TABLE recenzija DROP COLUMN naslov;

-- 4. Učini film_id obaveznim
ALTER TABLE recenzija MODIFY COLUMN film_id INT NOT NULL;

-- 5. Dodaj FK
ALTER TABLE recenzija 
    ADD CONSTRAINT fk_recenzija_film 
    FOREIGN KEY (film_id) REFERENCES Filmovi(id) 
    ON DELETE CASCADE;



-- =========================
-- WATCHLISTA
-- =========================
/*
CREATE TABLE watchlista (
    id INT AUTO_INCREMENT PRIMARY KEY,
    korisnik_id INT,
    naziv VARCHAR(255),
    javna BOOLEAN,
    datum_kreiranja DATETIME DEFAULT CURRENT_TIMESTAMP,
    FOREIGN KEY (korisnik_id) REFERENCES korisnik(id) ON DELETE CASCADE
);*/


-- ============================
-- OSCAR -> Za primjenu SOAP-a
-- ============================

