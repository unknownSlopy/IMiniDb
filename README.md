# 🎬 IMiniDb

> Desktop aplikacija po uzoru na IMDb, razvijena u sklopu predmeta **Napredne Tehnike Programiranja (NTP)**.

Aplikacija omogućuje pretraživanje i upravljanje filmovima, pisanje recenzija te praćenje filmova putem watchliste. Podaci se dohvaćaju s javnog OMDb REST API-ja i pohranjuju u lokalnu MySQL bazu podataka.

---

## Tehnologije

- **C++ Builder** (Embarcadero Technologies)
- **MySQL** — pohrana korisnika, filmova i recenzija
- **OMDb API** — dohvat podataka o filmovima
- **FastReport** — generiranje izvještaja
- **Indy** — SOAP web servis (Oscari)

---

## Funkcionalnosti

- **Registracija i prijava** s hashiranjem lozinki (SHA-256, promjenjiva sol + papar)
- **Pregled filmova** dohvaćenih s OMDb API-ja s prikazom postera
- **Recenzije** — dodavanje, uređivanje i pregled recenzija filmova
- **Watchlista** — praćenje filmova koje želiš pogledati
- **Omiljeni filmovi** — lokalna XML pohrana omiljenih filmova
- **Izvještaji** — FastReport izvještaj korisnika i recenzija s izvozom u PDF
- **Višejezičnost** — Hrvatski i Engleski jezik
- **Oscar podaci** — lokalni SOAP web servis s bazom Oscar nagrada
- **Automatsko preuzimanje postera** paralelnim dretvama

---

## Pokretanje

### Preduvjeti

- C++ Builder (Embarcadero RAD Studio)
- MySQL Server
- FastReport komponenta
- TurboPower LockBox (kriptografija)

### Postavljanje baze

1. Pokreni MySQL Server
2. Uvezi SQL skriptu iz mape `db/` ili ručno kreiraj tablice: `korisnik`, `recenzije`, `Filmovi`, `oscar`
3. U aplikaciji postavi konekcijski string na svoju bazu (`FDConnectionIMiniDB`)

### Postavljanje OMDb API ključa

Registriraj se na [omdbapi.com](http://www.omdbapi.com/) i unesi svoj API ključ u odgovarajuće polje unutar aplikacije.

### Pokretanje SOAP servisa

Za Oscar funkcionalnost potrebno je pokrenuti zasebnu aplikaciju **Oscari_soap** prije pokretanja glavne aplikacije. Servis se pokreće na portu `4125`.

---

## Struktura projekta

```
IMiniDb/
├── DLL/                  # Dinamička biblioteka (dynamic.dll)
├── SLib/                 # Statička biblioteka (SLib.lib)
├── Oscari_soap/          # Lokalni SOAP web servis
├── postavke.ini          # Konfiguracija stilova i prijevoda
├── IMDB_demo.cpp         # Glavna aplikacija
└── DataTypes.h/.cpp      # Definicije klasa (Film, Korisnik, Recenzija, Watchlista)
```

> ⚠️ Napomena: repozitoriju nedostaju mape `_history` i `_recovery`.

---

##  Autor

Projekt izrađen u sklopu kolegija **Napredne Tehnike Programiranja**  

