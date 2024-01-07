#include"rejestracja.h"
#include"logowanie.h"

int main(){
    int opcja;
    bool active = true;
    bool login_ok;
    Klient* baza;
    
    cout<<"Witamy w wypozyczalni aut!"<<endl;
    cout<<"=========================="<<endl;
    cout<<"0. Wyjdz z wypozyczalni\t1. Rejestracja\t2. Logowanie"<<endl;
    cout<<"Wybierz opcje: ";
    cin>>opcja;

    while(active){
        switch(opcja){
            case 0:
                cout<<"Do zobaczenia :)";
                exit(0);
            case 1:
                baza = nullptr;
                rejestracja(baza);
                break;
            
            case 2:
            logowanie(login_ok);
            if (login_ok) {
                ifstream file("klienci.txt");
                if (!file.is_open()) {
                    cerr << "Error opening file!" << endl;
                    break;
                }

                string line;
                string wyp_auta = "wypozyczone_auta:";

                cout << "Twoje auta:" << endl;
                bool found = false;

                while (getline(file, line)) {
                    size_t pos = line.find(wyp_auta);
                    if (pos != string::npos) {
                        // Found the "wypozyczone_auta:" substring in the line
                        found = true;
                        string auta = line.substr(pos + wyp_auta.length());
                        cout << auta << endl; // Display the rented cars for each line
                    }
                }

                if (!found) {
                    cout << "Brak wypozyczonych aut." << endl;
                }
            } else {
                break;
            }
        }
        cout<<"Kontynuowac? TAK(t/T):NIE(n/N)"<<endl;
        cin>>co;
        if(co == 't' || co == 'T'){
            active = true;
            cout<<"0. Wyjdz z wypozyczalni\t1. Rejestracja\t2. Logowanie"<<endl;
            cout<<"Wybierz opcje: ";
            cin>>opcja;
        } else {
            cout<<"Do zobaczenia :)";
            active = false;
        }
    }
    
}
