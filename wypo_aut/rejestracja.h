#include <fstream>
#include <iostream>
#include <sstream>
#include "klient.h" // Include necessary headers

void Rejestracja(Klient*& klient) {
    ifstream file("klienci.txt");
    if (!file.is_open()) {
        cerr << "Error opening the file!" << endl;
        return;
    }

    string imie;
    string nazwisko;
    int nr_tel;

    cout << "podaj imie: ";
    cin >> imie;
    cout << "podaj nazwisko: ";
    cin >> nazwisko;
    cout << "podaj numer telefonu: ";
    cin >> nr_tel;

    Klient* tmp = klient;
    int IN = 0; // te same imiona i nazwiska - różne id

    string generatedLogin = imie.substr(0, 3) + nazwisko.substr(0, 3);

    string line;
    while (getline(file, line)) {
        if (line.find("login: " + generatedLogin) != string::npos) {
            IN++;
        }
    }
    file.close();

    if (IN > 0) {
        generatedLogin += to_string(IN);
    } else {
        generatedLogin += "0";
    }

    Klient* newClient = new Klient(generatedLogin, "", imie, nazwisko, nr_tel);

    if (klient == nullptr) {
        klient = newClient;
    } else {
        tmp = klient;
        while (tmp->next != nullptr) {
            tmp = tmp->next;
        }
        tmp->next = newClient;
    }

    ofstream outFile("klienci.txt", ios::app);
    if (!outFile.is_open()) {
        cerr << "Error opening the file for writing!" << endl;
        return;
    }

    cout << "Twoj login to: " << generatedLogin << endl;
    outFile << "login: " << generatedLogin << ", nr telefonu: " << nr_tel << endl;
    outFile.close();
}