#ifndef DataTypesH
#define DataTypesH

#include <System.hpp>
#include <System.Hash.hpp>

class Film;

class Korisnik {
    private:
        AnsiString hashirajLozinku(AnsiString lozinka);
    protected:
        int id;
        AnsiString ime, prezime, korIme, email, lozinkaHash;
    public:
        void setIme(AnsiString _ime);
        void setPrezime(AnsiString _prezime);
        void setKorisnickoIme(AnsiString _korIme);
        void setEmail(AnsiString _email);
		void setLozinka(AnsiString _lozinka);

        //int getId() const;
        AnsiString getIme() const;
        AnsiString getPrezime() const;
        AnsiString getKorIme() const;
        AnsiString getEmail() const;
		AnsiString getLozinkaHash() const;

        Korisnik() {}
        Korisnik(int id, AnsiString korIme, AnsiString email, AnsiString lozinka);
        bool prijava(AnsiString lozinka);
};

class Admin : protected Korisnik {
    private:
        int razina;
        AnsiString odjel;
    public:
        Admin() {}
        Admin(int id, AnsiString korIme, AnsiString email,
              AnsiString lozinka, int razina, AnsiString odjel);
        void dodajFilm(Film* film);
        void obrisiKorisnika(int korisnikId);
};

class Film {
    private:
        int id;
        AnsiString naslov;
        int godina;
        int trajanje;
        AnsiString opis;
        System::Sysutils::TBytes poster;

        AnsiString imdbID;
        AnsiString rated;
        AnsiString released;
        AnsiString zanr;
        AnsiString redatelj;
        AnsiString scenarist;
        AnsiString glumci;
        AnsiString jezik;
        AnsiString drzava;
        AnsiString nagrade;
        AnsiString posterUrl;
        AnsiString tip;
        AnsiString boxOffice;

        double imdbRating;
        int    imdbVotes;
        int    metascore;
        double ratingRT;

    public:
        // --- postojeći konstruktor (nepromijenjen) ---
        Film(int id, AnsiString naslov, int godina, int trajanje, AnsiString opis);

        // --- dodatni konstruktor za puni zapis iz OMDb-a ---
        Film(int id, AnsiString imdbID, AnsiString naslov, int godina,
             int trajanje, AnsiString opis, AnsiString zanr,
             AnsiString redatelj, AnsiString glumci,
             double imdbRating, AnsiString posterUrl);

        // --- postojeći getteri (nepromijenjeni) ---
        int GetId();
        AnsiString GetNaslov();
        int GetGodina();
        int GetTrajanje();
        AnsiString GetOpis();
        System::Sysutils::TBytes GetPoster();

        // --- dodani getteri ---
        AnsiString GetImdbID();
        AnsiString GetRated();
        AnsiString GetReleased();
        AnsiString GetZanr();
        AnsiString GetRedatelj();
        AnsiString GetScenarist();
        AnsiString GetGlumci();
        AnsiString GetJezik();
        AnsiString GetDrzava();
        AnsiString GetNagrade();
        AnsiString GetPosterUrl();
        AnsiString GetTip();
        AnsiString GetBoxOffice();
        double GetImdbRating();
        int    GetImdbVotes();
        int    GetMetascore();
        double GetRatingRT();

        // --- dodani setteri (da možeš puniti iz OMDb odgovora) ---
        void SetImdbID(AnsiString v);
        void SetRated(AnsiString v);
        void SetReleased(AnsiString v);
        void SetZanr(AnsiString v);
        void SetRedatelj(AnsiString v);
        void SetScenarist(AnsiString v);
        void SetGlumci(AnsiString v);
        void SetJezik(AnsiString v);
        void SetDrzava(AnsiString v);
        void SetNagrade(AnsiString v);
        void SetPosterUrl(AnsiString v);
        void SetTip(AnsiString v);
        void SetBoxOffice(AnsiString v);
        void SetImdbRating(double v);
        void SetImdbVotes(int v);
        void SetMetascore(int v);
        void SetRatingRT(double v);

        // --- postojeće metode (nepromijenjene) ---
        float izracunajOcjenu();
        AnsiString dohvatiDetalje();
        void ucitajPoster(AnsiString putanja);

        // --- dodana metoda: učitaj poster direktno s URL-a (Poster polje iz OMDb-a) ---
        void ucitajPosterSaUrla();
};

class Recenzija {
    private:
        int id;
        AnsiString tekst;
        int ocjena;
        TDateTime datum;
        int filmId;
        int korisnikId;
    public:
        Recenzija(int filmId, int korisnikId, AnsiString tekst, int ocjena);
        bool validiraj();
        void spremi();
};

class Watchlista {
    private:
        int id;
        AnsiString naziv;
        bool javna;
        TDateTime datumKreiranja;
        TList* filmovi;
    public:
        Watchlista(int korisnikId, AnsiString naziv, bool javna);
        ~Watchlista();
        void dodajFilm(Film* film);
        void ukloniFilm(int filmId);
        AnsiString izvezi();
};

#endif
