#include <vcl.h>
#include <System.Hash.hpp>
#pragma hdrstop
#include "DataTypes.h"

// ================================================================== KORISNIK ==================================================================
void Korisnik::setIme(AnsiString _ime){
	if (_ime.IsEmpty())
		throw Exception("Ime ne smije biti prazno!");
	ime = _ime;
}

void Korisnik::setPrezime(AnsiString _prezime){
	if (_prezime.IsEmpty())
		throw Exception("Prezime ne smije biti prazno!");
	prezime = _prezime;
}

void Korisnik::setKorisnickoIme(AnsiString _korIme){
	if (_korIme.IsEmpty())
		throw Exception("Korisničko ime ne smije biti prazno!");
	korIme = _korIme;
}
void Korisnik::setEmail(AnsiString _email){
	if (_email.IsEmpty())
		throw Exception("E-mail ne smije biti prazan!");
	email = _email;
}
void Korisnik::setLozinka(AnsiString _lozinka)
{
    if(_lozinka.IsEmpty())
        throw Exception("Lozinka ne smije biti prazna!");

    // Sol = korisničko ime (promjenjiva sol)
	String sol = korIme;

    // Papar
    String papri[] = {"P0", "P1", "P2", "P3", "P4"};
    String papar = papri[0];

    // Hash = SHA-256(lozinka + sol + papar)
    lozinkaHash = THashSHA2::GetHashString(_lozinka + sol + papar);
}

AnsiString Korisnik::getIme() const {
    return ime;
}

AnsiString Korisnik::getPrezime() const {
    return prezime;
}

AnsiString Korisnik::getKorIme() const {
    return korIme;
}

AnsiString Korisnik::getEmail() const {
    return email;
}

AnsiString Korisnik::getLozinkaHash() const {
    return lozinkaHash;
}


Korisnik::Korisnik(int id, AnsiString korIme, AnsiString email, AnsiString lozinka) : id(id), korIme(korIme), email(email){
	this->lozinkaHash  = hashirajLozinku(lozinka);
}

bool Korisnik::prijava(AnsiString lozinka){
    return lozinkaHash == hashirajLozinku(lozinka);
}

AnsiString Korisnik::hashirajLozinku(AnsiString lozinka){
	// kriptiranje ...
    return lozinka;
}




// ================================================================== ADMINISTRATOR ==================================================================
Admin::Admin(int id, AnsiString username, AnsiString email, AnsiString lozinka, int razina, AnsiString odjel)
	: Korisnik(id, username, email, lozinka), razina(razina), odjel(odjel)
{

}



// ================================================================== FILM ==================================================================

Film::Film(int id, AnsiString naslov, int godina, int trajanje, AnsiString opis) : id(id), naslov(naslov), godina(godina), trajanje(trajanje), opis(opis)
{
	if (godina < 1888 || godina > 2026)
		this->godina = 2026;
    else
		this->godina = godina;
}

// --- dodatni konstruktor za puni zapis iz OMDb-a ---
Film::Film(int id, AnsiString imdbID, AnsiString naslov, int godina,
           int trajanje, AnsiString opis, AnsiString zanr,
           AnsiString redatelj, AnsiString glumci,
           double imdbRating, AnsiString posterUrl)
    : id(id), naslov(naslov), trajanje(trajanje), opis(opis),
      imdbID(imdbID), zanr(zanr), redatelj(redatelj), glumci(glumci),
      imdbRating(imdbRating), posterUrl(posterUrl),
      imdbVotes(0), metascore(0), ratingRT(0.0)
{
    // ista validacija godine kao u postojećem konstruktoru
    if (godina < 1888 || godina > 2026)
        this->godina = 2026;
    else
        this->godina = godina;
}

int Film::GetId()               { return id; }
AnsiString Film::GetNaslov()    { return naslov; }
int Film::GetGodina()           { return godina; }
int Film::GetTrajanje()         { return trajanje; }
AnsiString Film::GetOpis()      { return opis; }
System::Sysutils::TBytes Film::GetPoster() {
    return poster;
}



// --- dodani getteri ---
AnsiString Film::GetImdbID()     { return imdbID; }
AnsiString Film::GetRated()      { return rated; }
AnsiString Film::GetReleased()   { return released; }
AnsiString Film::GetZanr()       { return zanr; }
AnsiString Film::GetRedatelj()   { return redatelj; }
AnsiString Film::GetScenarist()  { return scenarist; }
AnsiString Film::GetGlumci()     { return glumci; }
AnsiString Film::GetJezik()      { return jezik; }
AnsiString Film::GetDrzava()     { return drzava; }
AnsiString Film::GetNagrade()    { return nagrade; }
AnsiString Film::GetPosterUrl()  { return posterUrl; }
AnsiString Film::GetTip()        { return tip; }
AnsiString Film::GetBoxOffice()  { return boxOffice; }
double     Film::GetImdbRating() { return imdbRating; }
int        Film::GetImdbVotes()  { return imdbVotes; }
int        Film::GetMetascore()  { return metascore; }
double     Film::GetRatingRT()   { return ratingRT; }

// --- dodani setteri ---
void Film::SetImdbID(AnsiString v)     { imdbID = v; }
void Film::SetRated(AnsiString v)      { rated = v; }
void Film::SetReleased(AnsiString v)   { released = v; }
void Film::SetZanr(AnsiString v)       { zanr = v; }
void Film::SetRedatelj(AnsiString v)   { redatelj = v; }
void Film::SetScenarist(AnsiString v)  { scenarist = v; }
void Film::SetGlumci(AnsiString v)     { glumci = v; }
void Film::SetJezik(AnsiString v)      { jezik = v; }
void Film::SetDrzava(AnsiString v)     { drzava = v; }
void Film::SetNagrade(AnsiString v)    { nagrade = v; }
void Film::SetPosterUrl(AnsiString v)  { posterUrl = v; }
void Film::SetTip(AnsiString v)        { tip = v; }
void Film::SetBoxOffice(AnsiString v)  { boxOffice = v; }
void Film::SetImdbRating(double v)     { imdbRating = v; }
void Film::SetImdbVotes(int v)         { imdbVotes = v; }
void Film::SetMetascore(int v)         { metascore = v; }
void Film::SetRatingRT(double v)       { ratingRT = v; }

float Film::izracunajOcjenu() {
    // dohvati sve recenzije za ovaj film iz baze i izračunaj prosjek
    // else return 0.0;
}



// ================================================================== RECENZIJA ==================================================================
Recenzija::Recenzija(int filmId, int korisnikId, AnsiString tekst, int ocjena) : filmId(filmId), korisnikId(korisnikId), tekst(tekst)
{
    if (ocjena < 1 || ocjena > 10)
        this->ocjena = 1;
    else
        this->ocjena = ocjena;

	this->datum = Now();
}

bool Recenzija::validiraj() {
    if (tekst.IsEmpty()) return false;
    if (ocjena < 1 || ocjena > 10) return false;
    return true;
}



// ================================================================== WATCHLISTA ==================================================================
Watchlista::Watchlista(int korisnikId, AnsiString naziv, bool javna)
    : id(korisnikId), naziv(naziv), javna(javna)
{
    this->datumKreiranja = Now();
    this->filmovi = new TList();
}

Watchlista::~Watchlista() {
    delete filmovi;
}

void Watchlista::dodajFilm(Film* film) {
    // duplikati ...
    for (int i = 0; i < filmovi->Count; i++) {
        if (filmovi->Items[i] == film) {
            ShowMessage("Film je već na watchlisti!");
            return;
        }
    }
    filmovi->Add(film);
}
