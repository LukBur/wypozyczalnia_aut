#include"setup.h"

class Klient{
private:
    string login;
    string haslo;
public:
    string imie;
    string nazwisko;
    string nr_tel;
    
    Klient *next;

    void setLogin(string login){
        this->login = login;
    }

    string getLogin(){
        return login;
    }

    void setHaslo(string haslo){
        this->haslo = haslo;
    }

    string getHaslo(){
        return haslo;
    }

    Klient(string login, string haslo, string imie, string nazwisko, string nr_tel) :
    login(login), haslo(haslo), imie(imie), nazwisko(nazwisko), nr_tel(nr_tel), next(nullptr) {};

};
