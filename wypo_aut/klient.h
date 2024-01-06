#include"setup.h"

class Klient{
    string login;
    string haslo;
public:
    string imie;
    string nazwisko;
    int nr_tel;
    Klient *next;

    void setLogin(string login){
        this->login = login;
    }

    string getLogin(){
        return login;
    }

    Klient(string login, string haslo, string imie, string nazwisko, const int nr_tel) :
    login(login), haslo(haslo), imie(imie), nazwisko(nazwisko), nr_tel(nr_tel), next(nullptr) {};
};

Klient* baza = nullptr;