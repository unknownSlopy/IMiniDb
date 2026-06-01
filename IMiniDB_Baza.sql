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

DELETE FROM korisnik
WHERE email LIKE "jslopar%"

SELECT * FROM korisnik
SELECT * FROM Filmovi
SELECT * FROM recenzija

ALTER TABLE recenzija 
ADD CONSTRAINT fk_recenzija_korisnik 
FOREIGN KEY (korisnik_id) REFERENCES korisnik(id);

UPDATE Filmovi SET poster = NULL WHERE imdbID = 'tt0103064';

ALTER TABLE recenzija MODIFY film_id INT DEFAULT NULL;
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

select * from korisnik
SELECT * FROM recenzija
inner join korisnik on korisnik.id = recenzija.korisnik_id


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

CREATE TABLE oscar (
    id INTEGER PRIMARY KEY AUTO_INCREMENT,
    godina INTEGER,
    kategorija TEXT,
    film TEXT,
    pobjednik TEXT
);

select * from oscar

INSERT INTO oscar (godina, kategorija, film, pobjednik) VALUES
(2024, 'Best Picture',           'Oppenheimer',          'Christopher Nolan'),
(2024, 'Best Actor',             'Oppenheimer',           'Cillian Murphy'),
(2024, 'Best Actress',           'Poor Things',           'Emma Stone'),
(2024, 'Best Director',          'Oppenheimer',           'Christopher Nolan'),
(2024, 'Best Supporting Actor',  'American Fiction',      'Robert Downey Jr.'),
(2024, 'Best Supporting Actress','Oppenheimer',           'Da Vine Joy Randolph'),

(2023, 'Best Picture',           'Everything Everywhere All at Once', 'Daniel Kwan & Daniel Scheinert'),
(2023, 'Best Actor',             'The Whale',             'Brendan Fraser'),
(2023, 'Best Actress',           'Everything Everywhere All at Once', 'Michelle Yeoh'),
(2023, 'Best Director',          'Everything Everywhere All at Once', 'Daniel Kwan & Daniel Scheinert'),
(2023, 'Best Supporting Actor',  'The Banshees of Inisherin', 'Ke Huy Quan'),
(2023, 'Best Supporting Actress','Everything Everywhere All at Once', 'Jamie Lee Curtis'),

(2022, 'Best Picture',           'CODA',                  'Sian Heder'),
(2022, 'Best Actor',             'The Father',            'Anthony Hopkins'),
(2022, 'Best Actress',           'Nomadland',             'Frances McDormand'),
(2022, 'Best Director',          'Nomadland',             'Chloe Zhao'),
(2022, 'Best Supporting Actor',  'Judas and the Black Messiah', 'Troy Kotsur'),
(2022, 'Best Supporting Actress','Argylle',               'Ariana DeBose'),

(2021, 'Best Picture',           'Parasite',              'Bong Joon-ho'),
(2021, 'Best Actor',             'Joker',                 'Joaquin Phoenix'),
(2021, 'Best Actress',           'Judy',                  'Renee Zellweger'),
(2021, 'Best Director',          'Parasite',              'Bong Joon-ho'),
(2021, 'Best Supporting Actor',  'Once Upon a Time in Hollywood', 'Brad Pitt'),
(2021, 'Best Supporting Actress','Jojo Rabbit',           'Laura Dern'),

(2020, 'Best Picture',           'Green Book',            'Peter Farrelly'),
(2020, 'Best Actor',             'Bohemian Rhapsody',     'Rami Malek'),
(2020, 'Best Actress',           'The Favourite',         'Olivia Colman'),
(2020, 'Best Director',          'Roma',                  'Alfonso Cuaron'),
(2020, 'Best Supporting Actor',  'Green Book',            'Mahershala Ali'),
(2020, 'Best Supporting Actress','If Beale Street Could Talk', 'Regina King');

