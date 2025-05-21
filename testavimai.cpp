#include "studentas.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <list>
#include <deque>
#include <numeric>
#include <chrono>
#include <algorithm> // reikalinga sort funkcijai
#include "funkcijos.h"

using namespace std;
using namespace std::chrono;

// Funkcija testuoja vector konteinerio našumą: nuskaitymą, rūšiavimą ir skirstymą
void testuotiVector(const string& failas) {
    vector<Studentas> visi, vargsiukai, kietiakiai;

    ifstream in(failas);
    string eilute;
    getline(in, eilute); // praleidžiama antraštė

    auto start_nuskaitymo = high_resolution_clock::now();

    while (getline(in, eilute)) {
        stringstream ss(eilute);
        string vardas, pavarde;
        vector<int> nd;
        int egz;

        ss >> vardas >> pavarde;
        int paz;
        while (ss >> paz) nd.push_back(paz);
        if (nd.size() < 1) continue;
        egz = nd.back();
        nd.pop_back();


        Studentas s(vardas, pavarde, nd, egz);
        s.skaiciuotiGalutini(true); // naudoti vidurkį
        visi.push_back(s);
    }

    auto end_nuskaitymo = high_resolution_clock::now();

    auto start_rusiavimo = high_resolution_clock::now();
    sort(visi.begin(), visi.end(), [](const Studentas& a, const Studentas& b) {
        return a.getGalutinis() < b.getGalutinis();
        });
    auto end_rusiavimo = high_resolution_clock::now();

    auto start_skirstymo = high_resolution_clock::now();
    for (const auto& s : visi) {
        if (s.getGalutinis() < 5.0) vargsiukai.push_back(s);
        else kietiakiai.push_back(s);
    }
    auto end_skirstymo = high_resolution_clock::now();

    cout << "\n[Vector] Failas: " << failas << "\n";
    cout << "Nuskaitymas: " << duration_cast<milliseconds>(end_nuskaitymo - start_nuskaitymo).count() << " ms\n";
    cout << "Rūšiavimas:   " << duration_cast<milliseconds>(end_rusiavimo - start_rusiavimo).count() << " ms\n";
    cout << "Skirstymas:   " << duration_cast<milliseconds>(end_skirstymo - start_skirstymo).count() << " ms\n";
}

//Testuoti List veikia taippat kaip ir Vektor tik list naudoja .sort(0 vietoje std::sort()
void testuotiList(const string& failas) {
    list<Studentas> visi, vargsiukai, kietiakiai;

    ifstream in(failas);
    string eilute;
    getline(in, eilute); // praleidžiama antraštė

    auto start_nuskaitymo = high_resolution_clock::now();

    while (getline(in, eilute)) {
        stringstream ss(eilute);
        string vardas, pavarde;
        vector<int> nd;
        int egz;

        ss >> vardas >> pavarde;
        int paz;
        while (ss >> paz) nd.push_back(paz);
        if (nd.size() < 1) continue;
        egz = nd.back();
        nd.pop_back();


        Studentas s(vardas, pavarde, nd, egz);
        s.skaiciuotiGalutini(true);
        visi.push_back(s);
    }

    auto end_nuskaitymo = high_resolution_clock::now();

    auto start_rusiavimo = high_resolution_clock::now();
    visi.sort([](const Studentas& a, const Studentas& b) {
        return a.getGalutinis() < b.getGalutinis();
        });
    auto end_rusiavimo = high_resolution_clock::now();

    auto start_skirstymo = high_resolution_clock::now();
    for (const auto& s : visi) {
        if (s.getGalutinis() < 5.0)
            vargsiukai.push_back(s);
        else
            kietiakiai.push_back(s);
    }
    auto end_skirstymo = high_resolution_clock::now();

    cout << "\n[List] Failas: " << failas << "\n";
    cout << "Nuskaitymas: " << duration_cast<milliseconds>(end_nuskaitymo - start_nuskaitymo).count() << " ms\n";
    cout << "Rūšiavimas:   " << duration_cast<milliseconds>(end_rusiavimo - start_rusiavimo).count() << " ms\n";
    cout << "Skirstymas:   " << duration_cast<milliseconds>(end_skirstymo - start_skirstymo).count() << " ms\n";
}

//Testuoti Deque veikia taippat kaip ir Vektor bet tinka dviem galams
void testuotiDeque(const string& failas) {
    deque<Studentas> visi, vargsiukai, kietiakiai;

    ifstream in(failas);
    string eilute;
    getline(in, eilute); // praleidžiama antraštė

    auto start_nuskaitymo = high_resolution_clock::now();

    while (getline(in, eilute)) {
        stringstream ss(eilute);
        string vardas, pavarde;
        vector<int> nd;
        int egz;

        ss >> vardas >> pavarde;
        int paz;
        while (ss >> paz) nd.push_back(paz);
        if (nd.size() < 1) continue;
        egz = nd.back();
        nd.pop_back();


        Studentas s(vardas, pavarde, nd, egz);
        s.skaiciuotiGalutini(true);
        visi.push_back(s);
    }

    auto end_nuskaitymo = high_resolution_clock::now();

    auto start_rusiavimo = high_resolution_clock::now();
    sort(visi.begin(), visi.end(), [](const Studentas& a, const Studentas& b) {
        return a.getGalutinis() < b.getGalutinis();
        });
    auto end_rusiavimo = high_resolution_clock::now();

    auto start_skirstymo = high_resolution_clock::now();
    for (const auto& s : visi) {
        if (s.getGalutinis() < 5.0)
            vargsiukai.push_back(s);
        else
            kietiakiai.push_back(s);
    }
    auto end_skirstymo = high_resolution_clock::now();

    cout << "\n[Deque] Failas: " << failas << "\n";
    cout << "Nuskaitymas: " << duration_cast<milliseconds>(end_nuskaitymo - start_nuskaitymo).count() << " ms\n";
    cout << "Rūšiavimas:   " << duration_cast<milliseconds>(end_rusiavimo - start_rusiavimo).count() << " ms\n";
    cout << "Skirstymas:   " << duration_cast<milliseconds>(end_skirstymo - start_skirstymo).count() << " ms\n";
}

// Skirstymas naudojant remove_if + erase (pašalina vargšiukus iš originalo)
void testuotiStrategija2Vector(const string& failas) {
    vector<Studentas> visi, vargsiukai;

    ifstream in(failas);
    string eilute;
    getline(in, eilute); // praleidžiama antraštė

    auto start_nuskaitymo = high_resolution_clock::now();

    while (getline(in, eilute)) {
        stringstream ss(eilute);
        string vardas, pavarde;
        vector<int> nd;
        int egz;

        ss >> vardas >> pavarde;
        int paz;
        while (ss >> paz) nd.push_back(paz);

        while (ss >> paz) nd.push_back(paz);
        if (nd.size() < 1) continue;
        egz = nd.back();
        nd.pop_back();


        Studentas s(vardas, pavarde, nd, egz);
        s.skaiciuotiGalutini(true);
        visi.push_back(s);
    }

    auto end_nuskaitymo = high_resolution_clock::now();

    auto start_rusiavimo = high_resolution_clock::now();
    // Galime palikti rūšiavimą tuščią arba pasinaudoti sort jei reikia pilnos analizės
    sort(visi.begin(), visi.end(), [](const Studentas& a, const Studentas& b) {
        return a.getGalutinis() < b.getGalutinis();
        });
    auto end_rusiavimo = high_resolution_clock::now();
    auto start_skirstymo = high_resolution_clock::now();
    auto it = remove_if(visi.begin(), visi.end(), [&](const Studentas& s) {
        if (s.getGalutinis() < 5.0) {
            vargsiukai.push_back(s);
            return true;
        }
        return false;
        });
    visi.erase(it, visi.end());
    auto end_skirstymo = high_resolution_clock::now();

    cout << "\n[Vector - Strategija 2] Failas: " << failas << "\n";
    cout << "Nuskaitymas: " << duration_cast<milliseconds>(end_nuskaitymo - start_nuskaitymo).count() << " ms\n";
    cout << "Rūšiavimas:   " << duration_cast<milliseconds>(end_rusiavimo - start_rusiavimo).count() << " ms\n";
    cout << "Skirstymas (su ištrynimu): " << duration_cast<milliseconds>(end_skirstymo - start_skirstymo).count() << " ms\n";
}

void testuotiStrategija2List(const string& failas) {
    list<Studentas> visi, vargsiukai;

    ifstream in(failas);
    string eilute;
    getline(in, eilute); // praleidžiama antraštė

    auto start_nuskaitymo = high_resolution_clock::now();

    while (getline(in, eilute)) {
        stringstream ss(eilute);
        string vardas, pavarde;
        vector<int> nd;
        int egz;

        ss >> vardas >> pavarde;
        int paz;
        while (ss >> paz) nd.push_back(paz);

        while (ss >> paz) nd.push_back(paz);
        if (nd.size() < 1) continue;
        egz = nd.back();
        nd.pop_back();


        Studentas s(vardas, pavarde, nd, egz);
        s.skaiciuotiGalutini(true);
        visi.push_back(s);
    }

    auto end_nuskaitymo = high_resolution_clock::now();
    auto start_rusiavimo = high_resolution_clock::now();
    visi.sort([](const Studentas& a, const Studentas& b) {
        return a.getGalutinis() < b.getGalutinis();
        });
    auto end_rusiavimo = high_resolution_clock::now();
    auto start_skirstymo = high_resolution_clock::now();
    for (auto it = visi.begin(); it != visi.end(); ) {
        if (it->getGalutinis() < 5.0) {
            vargsiukai.push_back(*it);
            it = visi.erase(it);
        }
        else {
            ++it;
        }
    }
    auto end_skirstymo = high_resolution_clock::now();

    cout << "\n[List - Strategija 2] Failas: " << failas << "\n";
    cout << "Nuskaitymas: " << duration_cast<milliseconds>(end_nuskaitymo - start_nuskaitymo).count() << " ms\n";
    cout << "Rūšiavimas:   " << duration_cast<milliseconds>(end_rusiavimo - start_rusiavimo).count() << " ms\n";
    cout << "Skirstymas (su ištrynimu): " << duration_cast<milliseconds>(end_skirstymo - start_skirstymo).count() << " ms\n";
}

void testuotiStrategija2Deque(const string& failas) {
    deque<Studentas> visi, vargsiukai;

    ifstream in(failas);
    string eilute;
    getline(in, eilute); // praleidžiama antraštė

    auto start_nuskaitymo = high_resolution_clock::now();

    while (getline(in, eilute)) {
        stringstream ss(eilute);
        string vardas, pavarde;
        vector<int> nd;
        int egz;

        ss >> vardas >> pavarde;
        int paz;
        while (ss >> paz) nd.push_back(paz);

        while (ss >> paz) nd.push_back(paz);
        if (nd.size() < 1) continue;
        egz = nd.back();
        nd.pop_back();


        Studentas s(vardas, pavarde, nd, egz);
        s.skaiciuotiGalutini(true);
        visi.push_back(s);
    }

    auto end_nuskaitymo = high_resolution_clock::now();
    auto start_rusiavimo = high_resolution_clock::now();
    sort(visi.begin(), visi.end(), [](const Studentas& a, const Studentas& b) {
        return a.getGalutinis() < b.getGalutinis();
        });
    auto end_rusiavimo = high_resolution_clock::now();

    auto start_skirstymo = high_resolution_clock::now();
    auto it = remove_if(visi.begin(), visi.end(), [&](const Studentas& s) {
        if (s.getGalutinis() < 5.0) {
            vargsiukai.push_back(s);
            return true;
        }
        return false;
        });
    visi.erase(it, visi.end());
    auto end_skirstymo = high_resolution_clock::now();

    cout << "\n[Deque - Strategija 2] Failas: " << failas << "\n";
    cout << "Nuskaitymas: " << duration_cast<milliseconds>(end_nuskaitymo - start_nuskaitymo).count() << " ms\n";
    cout << "Rūšiavimas:   " << duration_cast<milliseconds>(end_rusiavimo - start_rusiavimo).count() << " ms\n";
    cout << "Skirstymas (su ištrynimu): " << duration_cast<milliseconds>(end_skirstymo - start_skirstymo).count() << " ms\n";
}

// Naudoja std::partition – padalina vektorių į dvi grupes pagal sąlygą
void testuotiStrategija3Vector(const string& failas) {
    vector<Studentas> visi;

    ifstream in(failas);
    string eilute;
    getline(in, eilute); // praleidžiama antraštė

    auto start_nuskaitymo = high_resolution_clock::now();

    while (getline(in, eilute)) {
        stringstream ss(eilute);
        string vardas, pavarde;
        vector<int> nd;
        int egz;

        ss >> vardas >> pavarde;
        int paz;
        while (ss >> paz) nd.push_back(paz);

        while (ss >> paz) nd.push_back(paz);
        if (nd.size() < 1) continue;
        egz = nd.back();
        nd.pop_back();


        Studentas s(vardas, pavarde, nd, egz);
        s.skaiciuotiGalutini(true);
        visi.push_back(s);
    }

    auto end_nuskaitymo = high_resolution_clock::now();
    auto start_rusiavimo = high_resolution_clock::now();
    sort(visi.begin(), visi.end(), [](const Studentas& a, const Studentas& b) {
        return a.getGalutinis() < b.getGalutinis();
        });
    auto end_rusiavimo = high_resolution_clock::now();

    auto start_partition = high_resolution_clock::now();
    auto it = partition(visi.begin(), visi.end(), [](const Studentas& s) {
        return s.getGalutinis() >= 5.0;
        });

    vector<Studentas> kietiakiai(visi.begin(), it);
    vector<Studentas> vargsiukai(it, visi.end());
    auto end_partition = high_resolution_clock::now();

    cout << "\n[Vector - Strategija 3] Failas: " << failas << "\n";
    cout << "Nuskaitymas: " << duration_cast<milliseconds>(end_nuskaitymo - start_nuskaitymo).count() << " ms\n";
    cout << "Rūšiavimas:   " << duration_cast<milliseconds>(end_rusiavimo - start_rusiavimo).count() << " ms\n";
    cout << "Partition skirstymas: " << duration_cast<milliseconds>(end_partition - start_partition).count() << " ms\n";
}


void testuotiStrategija3List(const string& failas) {
    list<Studentas> visi;

    ifstream in(failas);
    string eilute;
    getline(in, eilute); // praleidžiama antraštė

    auto start_nuskaitymo = high_resolution_clock::now();

    while (getline(in, eilute)) {
        stringstream ss(eilute);
        string vardas, pavarde;
        vector<int> nd;
        int egz;

        ss >> vardas >> pavarde;
        int paz;
        while (ss >> paz) nd.push_back(paz);

        while (ss >> paz) nd.push_back(paz);
        if (nd.size() < 1) continue;
        egz = nd.back();
        nd.pop_back();


        Studentas s(vardas, pavarde, nd, egz);
        s.skaiciuotiGalutini(true);
        visi.push_back(s);
    }

    auto end_nuskaitymo = high_resolution_clock::now();
    auto start_rusiavimo = high_resolution_clock::now();
    visi.sort([](const Studentas& a, const Studentas& b) {
        return a.getGalutinis() < b.getGalutinis();
        });
    auto end_rusiavimo = high_resolution_clock::now();

    auto start_skirstymo = high_resolution_clock::now();
    list<Studentas> vargsiukai, kietiakiai;

    for (const auto& s : visi) {
        if (s.getGalutinis() < 5.0)
            vargsiukai.push_back(s);
        else
            kietiakiai.push_back(s);
    }
    auto end_skirstymo = high_resolution_clock::now();

    cout << "\n[List - Strategija 3] Failas: " << failas << "\n";
    cout << "Nuskaitymas: " << duration_cast<milliseconds>(end_nuskaitymo - start_nuskaitymo).count() << " ms\n";
    cout << "Rūšiavimas:   " << duration_cast<milliseconds>(end_rusiavimo - start_rusiavimo).count() << " ms\n";
    cout << "Efektyvus skirstymas: " << duration_cast<milliseconds>(end_skirstymo - start_skirstymo).count() << " ms\n";
}

void testuotiStrategija3Deque(const string& failas) {
    deque<Studentas> visi;

    ifstream in(failas);
    string eilute;
    getline(in, eilute); // praleidžiama antraštė

    auto start_nuskaitymo = high_resolution_clock::now();

    while (getline(in, eilute)) {
        stringstream ss(eilute);
        string vardas, pavarde;
        vector<int> nd;
        int egz;

        ss >> vardas >> pavarde;
        int paz;
        while (ss >> paz) nd.push_back(paz);

        while (ss >> paz) nd.push_back(paz);
        if (nd.size() < 1) continue;
        egz = nd.back();
        nd.pop_back();


        Studentas s(vardas, pavarde, nd, egz);
        s.skaiciuotiGalutini(true);
        visi.push_back(s);
    }

    auto end_nuskaitymo = high_resolution_clock::now();
    auto start_rusiavimo = high_resolution_clock::now();
    sort(visi.begin(), visi.end(), [](const Studentas& a, const Studentas& b) {
        return a.getGalutinis() < b.getGalutinis();
        });
    auto end_rusiavimo = high_resolution_clock::now();

    auto start_partition = high_resolution_clock::now();
    auto it = partition(visi.begin(), visi.end(), [](const Studentas& s) {
        return s.getGalutinis() >= 5.0;
        });

    deque<Studentas> kietiakiai(visi.begin(), it);
    deque<Studentas> vargsiukai(it, visi.end());
    auto end_partition = high_resolution_clock::now();

    cout << "\n[Deque - Strategija 3] Failas: " << failas << "\n";
    cout << "Nuskaitymas: " << duration_cast<milliseconds>(end_nuskaitymo - start_nuskaitymo).count() << " ms\n";
    cout << "Rūšiavimas:   " << duration_cast<milliseconds>(end_rusiavimo - start_rusiavimo).count() << " ms\n";
    cout << "Partition skirstymas: " << duration_cast<milliseconds>(end_partition - start_partition).count() << " ms\n";
}

