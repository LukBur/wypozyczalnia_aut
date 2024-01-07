#include"setup.h"

bool logowanie(bool login_ok) {
    ifstream file("klienci.txt");

    if (!file.is_open()) {
        cerr << "Błąd w dostępie do bazy klientów" << endl;
        return true;
    }

    bool uzytkownikIstnieje = false;
    string login;
    string haslo;
    string line;
    string imie;

    cout << "Podaj login: ";
    cin >> login;

    cout << "Podaj haslo: ";
    cin >> haslo;

    string loginPrefix = "login:" + login + ",";
    string passwordPrefix = "haslo:" + haslo + ",";

    while (getline(file, line)) {
        if (line.find(loginPrefix) != string::npos) {
            uzytkownikIstnieje = true;
            if (line.find(passwordPrefix) != string::npos) {
                size_t pos = line.find("imie:");
                if (pos != string::npos) {
                    imie = line.substr(pos + 5);
                    size_t commaPos = imie.find(",");
                    if (commaPos != string::npos) {
                        imie = imie.substr(0, commaPos);
                        cout << "Witaj " << imie << "!" << endl;
                        login_ok = true;
                        return login_ok;
                    }
                }
            }
        }
    }

    cout << "Bledne haslo lub nazwa uzytkownika." << endl;
    login_ok = false;
    return login_ok;
}
