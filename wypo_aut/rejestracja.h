#include"klient.h"

void rejestracja(Klient*& klient) {
    ifstream file("klienci.txt");

    if (!file.is_open()) {
        cerr << "Bład w dostepie do bazy klientów" << endl;
        return;
    }

    string haslo;
    string imie;
    string nazwisko;
    string nr_tel;

    cout << "podaj imie: ";
    cin >> imie;
    cout << "podaj nazwisko: ";
    cin >> nazwisko;
    cout << "podaj numer telefonu: ";
    cin >> nr_tel;

    Klient* tmp = klient;
    int IN = 0; // te same imiona i nazwiska - różne id

    string login = imie.substr(0, 3) + nazwisko.substr(0, 3);

    string line;
    while (getline(file, line)) {
        if (line.find("login:" + login) != string::npos) {
            IN++;
        }
    }
    file.close();

    if (IN > 0) {
        login += to_string(IN);
    } else {
        login += "0";
    }

    Klient* newClient = new Klient(login, "", imie, nazwisko, nr_tel);

    if (klient == nullptr) {
        klient = newClient;
    } else {
        tmp = klient;
        while (tmp->next != nullptr) {
            tmp = tmp->next;
        }
        tmp->next = newClient;
    }

    cout<<"Ustaw nowe haslo: ";
    cin>>haslo;
    klient->setHaslo(haslo);

    ofstream outFile("klienci.txt", ios::app);
    if (!outFile.is_open()) {
        cerr << "Error opening the file for writing!" << endl;
        return;
    }

    cout << "Twoj login to: " << login << endl;
    outFile <<"imie:"<<imie<<"nazwisko:"<<nazwisko<< "login:" << klient->getLogin() <<",haslo:" << klient->getHaslo() << ",nr_telefonu:" << nr_tel << ",wypozyczone auta:" << endl;
    outFile.close();
}
