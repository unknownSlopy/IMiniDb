# IMiniDb

> Desktop aplikacija po uzoru na IMDb, razvijena u sklopu predmeta **Napredne Tehnike Programiranja (NTP)**.

Aplikacija je namijenjena ljubiteljima filma i recenzentima. Omogućuje pretraživanje filmova putem OMDb REST API-ja, upravljanje osobnim listama filmova, pisanje recenzija te pregled Oscar nagrada kroz lokalni SOAP web servis. Napisana je u C++ Builderu u kombinaciji s MySQL bazom podataka.

> Napomena: repozitoriju nedostaju mape `_history` i `_recovery`.

---

## Tehnologije

- **C++ Builder** (Embarcadero RAD Studio)
- **MySQL** — pohrana korisnika, filmova i recenzija
- **OMDb API** — dohvat podataka o filmovima s interneta
- **FastReport** — generiranje i izvoz izvještaja u PDF
- **Indy (TIdHTTPWebBrokerBridge)** — lokalni SOAP web servis
- **TNetHTTPClient** — HTTP preuzimanje postera filmova
- **TRESTClient / TRESTRequest / TRESTResponse** — REST komunikacija
- **TurboPower LockBox** — kriptografija (simetrično šifriranje)
- **FireDAC (FDConnection, FDQuery, FDTable)** — pristup bazi podataka

---

## Pokretanje

### Preduvjeti

- Embarcadero RAD Studio (C++ Builder)
- MySQL Server (lokalni ili udaljeni)
- FastReport komponenta
- TurboPower LockBox

### Postavljanje baze podataka

1. Pokreni MySQL Server
2. Kreiraj tablice: `korisnik`, `recenzije`, `Filmovi`, `oscar`
3. U aplikaciji postavi konekcijski string na svoju instancu baze (`FDConnectionIMiniDB`)

### OMDb API ključ

Registriraj se na [omdbapi.com](http://www.omdbapi.com/), dohvati besplatni API ključ i unesi ga u aplikaciju. Bez ispravnog ključa servis odbija sve zahtjeve.

### SOAP servis (Oscar podaci)

Prije pokretanja glavne aplikacije potrebno je pokrenuti zasebnu aplikaciju **Oscari_soap** koja posluživanje SOAP zahtjeva na `http://localhost:4125/soap/IOscars`.

---

## Funkcionalnosti

Za detaljan pregled svih funkcionalnosti pogledaj [FUNKCIONALNOSTI.md](FUNKCIONALNOSTI.md).

- Registracija i prijava s hashiranjem lozinki (SHA-256, promjenjiva sol + papar)
- Pregled i uvoz filmova putem OMDb REST API-ja
- Automatsko preuzimanje postera paralelnim dretvama
- Omiljeni filmovi — lokalna XML pohrana
- Watchlista — JSON pohrana filmova za gledanje
- Recenzije — JSON + MySQL pohrana
- Sortiranje, filtriranje i pregled filmova iz baze
- Izvještaji u PDF formatu (FastReport, master-detail)
- Oscar podaci putem lokalnog SOAP web servisa
- Višejezičnost (Hrvatski i Engleski)
- Postavke kroz INI datoteku i Windows registar

---

## Biblioteke

Za detaljan pregled svih biblioteka pogledaj [FUNKCIONALNOSTI.md](FUNKCIONALNOSTI.md).

- **SLib.lib** — statička biblioteka (parsiranje OMDb podataka)
- **dynamic.dll** — dinamička biblioteka (obrada teksta, DLL dijalozi, logo resurs)

---


## Autor

Projekt izrađen u sklopu kolegija **Napredne Tehnike Programiranja**  
