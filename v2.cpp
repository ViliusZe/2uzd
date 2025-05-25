// main.cpp – pritaikytas Studentas klasei
#include "studentas.h"
#include <iostream>
#include <vector>
#include <stdexcept>
#include "funkcijos.h"
void testuotiStudenta();


int main() {
    std::vector<Studentas> M;
    std::string failoPavadinimas = "duomenys.txt";
    char isvestis;
    int pasirinkimas;

    try {
        do {
            std::cout << "Pasirinkite viena is ju:" << std::endl;
            std::cout << "1. Įvesti mokinių duomenis" << std::endl;
            std::cout << "2. Sugeneruoti tik pažymius" << std::endl;
            std::cout << "3. Sugeneruoti visus duomenis" << std::endl;
            std::cout << "4. Skaityti duomenis iš failo" << std::endl;
            std::cout << "5. Generuoti testinius failus" << std::endl;
            std::cout << "6. Analizuoti pasirinktą sugeneruotą failą" << std::endl;
            std::cout << "7. Atlikti analizės tyrimą" << std::endl;
            std::cout << "8. Atlikti testavimus su vector decode ir list" << std::endl;
            std::cout << "9. Atlikti analizės tyrimą (Strategija 2)\n";
            std::cout << "10. Atlikti analizės tyrimą (Strategija 3)\n";
            std::cout << "11. Testuoti Studentas klasę (Rule of Five)" << std::endl;
            std::cout << "12. Baigti" << std::endl;

            std::cin >> pasirinkimas;
            if (std::cin.fail()) throw std::runtime_error("Neteisingas ivesties formatas.");
            M.clear();

            switch (pasirinkimas) {
                
            case 1:
                skaitymas(M);
                skaiciavimas(M, gautiPasirinkima());
                rasymas(M);
                break;
            case 2:
                generuotiPazymius(M);
                skaiciavimas(M, gautiPasirinkima());
                rasymas(M);
                break;

            case 3:
                generuotiVardusPavardesIrPazymius(M);
                skaiciavimas(M, gautiPasirinkima());
                rasymas(M);
                break;
            case 4:
                skaitymasIsFailo(M, failoPavadinimas);
                skaiciavimas(M, gautiPasirinkima());
                std::cout << "Isvestis i faila ar konsole? (f/k): ";
                std::cin >> isvestis;
                if (isvestis == 'f' || isvestis == 'F') rasymasIFaila(M);
                else rasymas(M);
                break;
            case 5:
                generuotiPasirinktaFaila();
                break;

            case 6:
                analizuotiPasirinktaFaila();
                break;
            case 7:
                atliktiAnalize();
                break;
            case 8:
                atliktiTestavimusSuVisaisFailais();
                break;
            case 9:
                atliktiAnalizeStrategija2();
                break;
            case 10:
                atliktiAnalizeStrategija3();
                break;
            case 11:
                testuotiStudenta();
                break;
            case 12:
                std::cout << "Baigiama programa.\n";
                return 0;
            
            default:
                std::cout << "Blogas pasirinkimas.\n";
            }
        } while (true);

    }
    catch (const std::runtime_error& e) {
        std::cerr << "Klaida: " << e.what() << std::endl;
    }
    


    return 0;
}
void testuotiStudenta() {
    
    //Zmogus z("Test", "Testavicius"); // ← negalima, nes klasė abstrakti(testas)

    std::vector<int> nd = { 10, 9, 8 };
    Studentas s1("Jonas", "Jonaitis", nd, 10);
    s1.skaiciuotiGalutini(true);

    Studentas s2 = s1;
    Studentas s3 = std::move(s1);

    Studentas s4;
    s4 = s2;

    Studentas s5;
    s5 = std::move(s3);

    std::cout << "Testas:\n";
    std::cout << s2 << "\n";
    std::cout << s4 << "\n";
    std::cout << s5 << "\n";
}

