#include "studentas.h"
#include "funkcijos.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <random>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <limits>
#include <chrono>
#include <cstdlib>
#include <numeric>



using namespace std;
using namespace std::chrono;

void atliktiTestavimusSuVisaisFailais() {
    vector<string> failai = {
        "studentai_1k.txt",
        "studentai_10k.txt",
        "studentai_100k.txt",
        "studentai_1mln.txt",
        "studentai_10mln.txt"
    };

    for (const auto& failas : failai) {
        testuotiVector(failas);
        testuotiList(failas);
        testuotiDeque(failas);
    }
}

bool tikrintiVardaPavarde(const string& tekstas) {
    return all_of(tekstas.begin(), tekstas.end(), ::isalpha);
}

double vid(const vector<int>& N) {
    return N.empty() ? 0.0 : accumulate(N.begin(), N.end(), 0.0) / N.size();
}

double mediana(vector<int> N) {
    if (N.empty()) return 0.0;
    sort(N.begin(), N.end());
    size_t n = N.size();
    return (n % 2 == 0) ? (N[n / 2 - 1] + N[n / 2]) / 2.0 : N[n / 2];
}

int gautiPasirinkima() {
    int pasirinkimas;
    while (true) {
        cout << "Jei norima skaiciuoti mokinio vidurkį, įveskite 1, jei medianą - 0:" << endl;
        cin >> pasirinkimas;
        if (!cin.fail() && (pasirinkimas == 0 || pasirinkimas == 1)) return pasirinkimas;
        cout << "Neteisingas pasirinkimas. Įveskite 1 arba 0.\n";
        cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

bool noriTęsti() {
    string ats;
    while (true) {
        cout << "Ar norite įvesti dar vieną mokinį? (Taip/Ne): ";
        cin >> ats;
        if (ats == "Taip" || ats == "taip") return true;
        if (ats == "Ne" || ats == "ne") return false;
        cout << "Neteisingas atsakymas.\n";
    }
}
void skaitymas(vector<Studentas>& M) {
    do {
        std::string vardas, pavarde;
        std::vector<int> pazymiai;
        int egzaminas;

        // Vardas
        do {
            cout << "Įveskite mokinio vardą: ";
            cin >> vardas;
        } while (!tikrintiVardaPavarde(vardas));

        // Pavardė
        do {
            cout << "Įveskite mokinio pavardę: ";
            cin >> pavarde;
        } while (!tikrintiVardaPavarde(pavarde));

        // Pažymiai
        cout << "Įveskite mokinio pažymius (baigti įveskite -1): ";
        int paz;
        while (cin >> paz && paz != -1) {
            if (paz >= 1 && paz <= 10) pazymiai.push_back(paz);
            else cout << "Leistinas pažymys tarp 1 ir 10. Bandykite dar kartą: ";
        }

        // Egzaminas
        do {
            cout << "Įveskite egzamino pažymį (1–10): ";
            cin >> egzaminas;
        } while (egzaminas < 1 || egzaminas > 10);

        // Sukuriamas objektas su konstruktoriumi
        Studentas s(vardas, pavarde, pazymiai, egzaminas);
        M.push_back(s);

    } while (noriTęsti());
}
void rikiuotiMokinius(vector<Studentas>& M, int pasirinkimas, bool atvirkstine) {
    if (pasirinkimas == 0) { // rūšiavimas pagal pavardę
        sort(M.begin(), M.end(), [&](const Studentas& a, const Studentas& b) {
            return atvirkstine ? a.getPavarde() > b.getPavarde() : a.getPavarde() < b.getPavarde();
            });
    }
    else if (pasirinkimas == 1) { // rūšiavimas pagal vardą
        sort(M.begin(), M.end(), [&](const Studentas& a, const Studentas& b) {
            return atvirkstine ? a.getVardas() > b.getVardas() : a.getVardas() < b.getVardas();
            });
    }
    else if (pasirinkimas == 2) { // rūšiavimas pagal galutinį rezultatą
        sort(M.begin(), M.end(), [&](const Studentas& a, const Studentas& b) {
            return atvirkstine ? a.getGalutinis() > b.getGalutinis() : a.getGalutinis() < b.getGalutinis();
            });
    }
}
void skaiciavimas(vector<Studentas>& M, int pasirinkimas) {
    for (auto& s : M) {
        s.skaiciuotiGalutini(pasirinkimas == 1);  // true jei vidurkis, false jei mediana
    }

    // Vartotojo pasirinkimas dėl rūšiavimo
    int rusiavimoPasirinkimas;
    bool atvirkstine;

    cout << "Pagal ką norite rūšiuoti?\n";
    cout << "0. Pavardė\n";
    cout << "1. Vardas\n";
    cout << "2. Galutinis pagal vidurkį arba medianą\n";
    cin >> rusiavimoPasirinkimas;

    cout << "Kaip norite rūšiuoti?\n";
    cout << "0. Didėjančiai\n";
    cout << "1. Mažėjančiai\n";
    cin >> atvirkstine;

    rikiuotiMokinius(M, rusiavimoPasirinkimas, atvirkstine);
}
void rasymas(const vector<Studentas>& M) {
    cout << left << setw(18) << "Pavardė" << setw(18) << "Vardas" << "Galutinis" << endl;
    cout << setw(50) << setfill('-') << "-" << endl;

    for (const auto& s : M) {
        cout << left << setw(17) << setfill(' ')
            << s.getPavarde() << setw(18)
            << s.getVardas() << fixed << setprecision(2)
            << s.getGalutinis() << endl;
    }
}
void generuotiVardusPavardesIrPazymius(vector<Studentas>& M) {
    vector<string> vyriskiVardai = { "Jonas", "Petras", "Marius", "Tomas", "Andrius" };
    vector<string> moteriskiVardai = { "Ona", "Eglė", "Ieva", "Rūta", "Laura" };
    vector<string> vyriskiPavardes = { "Kazlauskas", "Jankauskas", "Petravičius", "Navickas", "Butkus" };
    vector<string> moteriskiPavardes = { "Butkienė", "Vaitkevičienė", "Jankauskaitė", "Kazlauskaitė", "Petravičienė" };

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> vardas_distrib(0, 4);
    uniform_int_distribution<> pavarde_distrib(0, 4);
    uniform_int_distribution<> pazymys_distrib(1, 10);
    uniform_int_distribution<> lytis_distrib(0, 1);

    int mokiniuKiekis;
    cout << "Kiek mokinių norite sugeneruoti? ";
    while (true) {
        cin >> mokiniuKiekis;
        if (!cin.fail() && mokiniuKiekis > 0) break;
        cout << "Neteisingas skaičius. Bandykite dar kartą.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    for (int i = 0; i < mokiniuKiekis; i++) {
        string vardas, pavarde;
        vector<int> nd;
        int egzaminas;

        int lytis = lytis_distrib(gen);
        if (lytis == 0) {
            vardas = vyriskiVardai[vardas_distrib(gen)];
            pavarde = vyriskiPavardes[pavarde_distrib(gen)];
        }
        else {
            vardas = moteriskiVardai[vardas_distrib(gen)];
            pavarde = moteriskiPavardes[pavarde_distrib(gen)];
        }

        int kiek = rand() % 5 + 5; // nuo 5 iki 9 pažymių
        for (int j = 0; j < kiek; j++) {
            nd.push_back(pazymys_distrib(gen));
        }

        egzaminas = pazymys_distrib(gen);

        Studentas s(vardas, pavarde, nd, egzaminas);
        M.push_back(s);
    }
}
void generuotiPazymius(vector<Studentas>& M) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> pazymys_distrib(1, 10);

    do {
        string vardas, pavarde;
        int kiek;
        vector<int> pazymiai;
        int egzaminas;

        cout << "Įveskite mokinio vardą: ";
        cin >> vardas;

        cout << "Įveskite mokinio pavardę: ";
        cin >> pavarde;

        cout << "Įveskite pažymių kiekį: ";
        while (true) {
            cin >> kiek;
            if (!cin.fail() && kiek > 0 && kiek <= 20) break;
            cout << "Netinkamas kiekis (1–20). Bandykite dar kartą: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        for (int i = 0; i < kiek; ++i) {
            pazymiai.push_back(pazymys_distrib(gen));
        }

        egzaminas = pazymys_distrib(gen);

        Studentas s(vardas, pavarde, pazymiai, egzaminas);
        M.push_back(s);

    } while (noriTęsti());
}
void skaitymasIsFailo(vector<Studentas>& M, const string& failoPavadinimas) {
    ifstream failas(failoPavadinimas);
    if (!failas) {
        throw std::runtime_error("Nepavyko atidaryti failo: " + failoPavadinimas);
    }

    string eilute;
    getline(failas, eilute); // praleidžiama antraštė

    while (getline(failas, eilute)) {
        stringstream ss(eilute);
        string vardas, pavarde;
        vector<int> nd;
        int egzaminas;

        ss >> vardas >> pavarde;
        int pazymys;
        while (ss >> pazymys) {
            nd.push_back(pazymys);
        }

        if (!nd.empty()) {
            egzaminas = nd.back();
            nd.pop_back();

            Studentas s(vardas, pavarde, nd, egzaminas);
            M.push_back(s);
        }
    }

    failas.close();
}
void rasymasIFaila(const vector<Studentas>& M) {
    ofstream failas("rezultatai.txt");

    if (!failas) {
        cout << "Nepavyko atidaryti failo rašymui!" << endl;
        return;
    }

    failas << left << setw(18) << "Pavardė" << setw(18) << "Vardas" << "Galutinis" << endl;
    failas << setw(50) << setfill('-') << "-" << endl;

    for (const auto& s : M) {
        failas << left << setw(17) << setfill(' ')
            << s.getPavarde() << setw(18)
            << s.getVardas() << fixed << setprecision(2)
            << s.getGalutinis() << endl;
    }

    failas.close();
    cout << "Duomenys išrašyti į failą: rezultatai.txt" << endl;
}
void generuotiFaila(const std::string& failoVardas, int kiekis) {
    std::ofstream out(failoVardas);
    if (!out) {
        std::cerr << "Nepavyko sukurti failo: " << failoVardas << std::endl;
        return;
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> pazymiuKiekis(5, 15);
    std::uniform_int_distribution<> pazymys(1, 10);

    // Antraštė
    out << "Vardas Pavarde ";
    for (int i = 1; i <= 15; ++i) {
        out << "ND" << i << " ";
    }
    out << "Egzaminas\n";

    for (int i = 1; i <= kiekis; ++i) {
        out << "VardasNR" << i << " PavardeNR" << i << " ";

        int kiek = pazymiuKiekis(gen);
        for (int j = 0; j < kiek; ++j) {
            out << pazymys(gen) << " ";
        }

        out << pazymys(gen) << "\n"; // Egzaminas
    }

    out.close();
    std::cout << "Sugeneruotas failas: " << failoVardas << " (" << kiekis << " įrašų)\n";
}
void generuotiPasirinktaFaila() {
    int pasirinkimas;
    std::cout << "Pasirinkite, kiek įrašų turės sugeneruotas failas:\n";
    std::cout << "1 - 1 000 studentų\n";
    std::cout << "2 - 10 000 studentų\n";
    std::cout << "3 - 100 000 studentų\n";
    std::cout << "4 - 1 000 000 studentų\n";
    std::cout << "5 - 10 000 000 studentų\n";
    std::cin >> pasirinkimas;

    if (std::cin.fail()) {
        std::cerr << "Klaida: įvestas ne skaičius.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }

    switch (pasirinkimas) {
    case 1:
        generuotiFaila("studentai_1k.txt", 1000);
        break;
    case 2:
        generuotiFaila("studentai_10k.txt", 10000);
        break;
    case 3:
        generuotiFaila("studentai_100k.txt", 100000);
        break;
    case 4:
        generuotiFaila("studentai_1mln.txt", 1000000);
        break;
    case 5:
        generuotiFaila("studentai_10mln.txt", 10000000);
        break;
    default:
        std::cout << "Neteisingas pasirinkimas.\n";
    }
}
void analizuotiPasirinktaFaila() {
    int pasirinkimas;
    std::string failas;

    std::cout << "Pasirinkite, kurį failą analizuoti:\n";
    std::cout << "1 - studentai_1k.txt\n";
    std::cout << "2 - studentai_10k.txt\n";
    std::cout << "3 - studentai_100k.txt\n";
    std::cout << "4 - studentai_1mln.txt\n";
    std::cout << "5 - studentai_10mln.txt\n";
    std::cin >> pasirinkimas;

    if (std::cin.fail()) {
        std::cerr << "Klaida: įvestas ne skaičius.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }

    switch (pasirinkimas) {
    case 1: failas = "studentai_1k.txt"; break;
    case 2: failas = "studentai_10k.txt"; break;
    case 3: failas = "studentai_100k.txt"; break;
    case 4: failas = "studentai_1mln.txt"; break;
    case 5: failas = "studentai_10mln.txt"; break;
    default:
        std::cout << "Neteisingas pasirinkimas.\n";
        return;
    }

    analizuotiFaila(failas);  // Ši funkcija dar turi būti perrašyta su Studentas
}
long long analizuotiFaila(const std::string& failoVardas) {
    auto pradzia = high_resolution_clock::now();

    std::ifstream in(failoVardas);
    if (!in) {
        std::cerr << "Nepavyko atidaryti failo: " << failoVardas << std::endl;
        return -1;
    }

    std::string eilute;
    getline(in, eilute); // praleidžiama antraštė

    std::vector<Studentas> kietiakiai;
    std::vector<Studentas> vargsiukai;

    auto nuskaitymas_start = high_resolution_clock::now();

    while (getline(in, eilute)) {
        std::stringstream ss(eilute);
        std::string vardas, pavarde;
        std::vector<int> nd;
        int egzaminas;

        ss >> vardas >> pavarde;
        int pazymys;
        while (ss >> pazymys) {
            nd.push_back(pazymys);
        }

        if (nd.empty()) continue;

        egzaminas = nd.back();
        nd.pop_back();

        Studentas s(vardas, pavarde, nd, egzaminas);
        s.skaiciuotiGalutini(true); // naudokime vidurkį

        if (s.getGalutinis() < 5.0)
            vargsiukai.push_back(s);
        else
            kietiakiai.push_back(s);
    }

    in.close();

    auto nuskaitymas_end = high_resolution_clock::now();
    auto isvedimas_start = high_resolution_clock::now();

    std::ofstream out1("vargsiukai.txt");
    std::ofstream out2("kietiakiai.txt");

    for (const auto& s : vargsiukai)
        out1 << s.getPavarde() << " " << s.getVardas() << " " << s.getGalutinis() << "\n";

    for (const auto& s : kietiakiai)
        out2 << s.getPavarde() << " " << s.getVardas() << " " << s.getGalutinis() << "\n";

    out1.close();
    out2.close();

    auto isvedimas_end = high_resolution_clock::now();
    auto pabaiga = high_resolution_clock::now();

    auto t_nuskaitymas = duration_cast<milliseconds>(nuskaitymas_end - nuskaitymas_start).count();
    auto t_isvedimas = duration_cast<milliseconds>(isvedimas_end - isvedimas_start).count();
    auto t_visas = duration_cast<milliseconds>(pabaiga - pradzia).count();

    std::cout << "Analizė baigta: " << vargsiukai.size() << " vargšiukai, " << kietiakiai.size() << " kietiakiai.\n";
    std::cout << "---- Laiko analizė ----\n";
    std::cout << "Nuskaitymas + skirstymas: " << t_nuskaitymas << " ms\n";
    std::cout << "Išvedimas į failus: " << t_isvedimas << " ms\n";
    std::cout << "Bendras analizės laikas: " << t_visas / 1000.0 << " s\n";

    return t_visas;
}
void atliktiAnalize() {
    int tyrimas;
    std::cout << "Pasirinkite tyrimo tipą:\n";
    std::cout << "1 - Failo kūrimo greitis (be analizės)\n";
    std::cout << "2 - Pilna analizė: nuskaitymas, rūšiavimas, išvedimas\n";
    std::cin >> tyrimas;

    if (std::cin.fail() || (tyrimas != 1 && tyrimas != 2)) {
        std::cerr << "Klaida: įveskite 1 arba 2.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }

    std::vector<std::pair<std::string, int>> failai = {
        {"studentai_1k.txt", 1000},
        {"studentai_10k.txt", 10000},
        {"studentai_100k.txt", 100000},
        {"studentai_1mln.txt", 1000000},
        {"studentai_10mln.txt", 10000000}
    };

    for (const auto& [failas, kiekis] : failai) {
        std::cout << "\nFailas: " << failas << "\n";

        if (tyrimas == 1) {
            auto start = std::chrono::high_resolution_clock::now();
            generuotiFaila(failas, kiekis);
            auto end = std::chrono::high_resolution_clock::now();

            auto laikasMs = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
            std::cout << "Sukūrimo laikas: " << laikasMs << " ms (" << laikasMs / 1000.0 << " s)\n";

        }
        else if (tyrimas == 2) {
            long long trukme = analizuotiFaila(failas);
            if (trukme >= 0)
                std::cout << "Apdorota per: " << trukme / 1000.0 << " s\n";
        }
    }

    std::cout << "\nTyrimas baigtas.\n";
}
void atliktiAnalizeStrategija2() {
    std::vector<std::string> failai = {
        "studentai_1k.txt", "studentai_10k.txt", "studentai_100k.txt",
        "studentai_1mln.txt", "studentai_10mln.txt"
    };

    for (const auto& failas : failai) {
        testuotiStrategija2Vector(failas);
        testuotiStrategija2List(failas);
        testuotiStrategija2Deque(failas);
    }
}
void atliktiAnalizeStrategija3() {
    std::vector<std::string> failai = {
        "studentai_1k.txt", "studentai_10k.txt", "studentai_100k.txt",
        "studentai_1mln.txt", "studentai_10mln.txt"
    };

    for (const auto& failas : failai) {
        testuotiStrategija3Vector(failas);
        testuotiStrategija3List(failas);
        testuotiStrategija3Deque(failas);
    }
}
