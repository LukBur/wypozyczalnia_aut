#include"setup.h"
#include<algorithm>

void logowanie() {
    ifstream file("klienci.txt");

    if (!file.is_open()) {
        cerr << "Błąd w dostępie do bazy klientów" << endl;
        return;
    }

    bool uzytkownikIstnieje = false;
    string login;
    string haslo;
    string line;

    cout << "Podaj login: ";
    login = "KonBug0";

    while (getline(file, line)) {
        string desiredLogin = line.find("login: " + login) != string::npos;
        if (desiredLogin == login) {
            uzytkownikIstnieje = true; // Update the flag as the user is found
            cout << "Podaj haslo: ";
            haslo = "konradino13pl";
            size_t pos = line.find("haslo: ");
            if (pos != string::npos) {
                string password = line.substr(pos + 7);
                password.erase(remove(password.begin(), password.end(), ' '), password.end());
                if (password == haslo) {
                    cout << "Logowanie powiodlo sie" << endl;
                } else {
                    cout << "Bledne haslo lub nazwa uzytkownika." << endl;
                }
                break; // Exit the loop after processing the user login
            }
        }
    }

    if (!uzytkownikIstnieje) {
        cout << "Użytkownik nie istnieje." << endl;
    }
}
