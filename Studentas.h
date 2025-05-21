#ifndef STUDENTAS_H
#define STUDENTAS_H

#include <string>
#include <vector>

class Studentas {
private:
    std::string vardas;
    std::string pavarde;
    std::vector<int> ndPazymiai;
    int egzaminas;
    double galutinis;

public:
    // Konstruktoriai
    Studentas();
    Studentas(const std::string& v, const std::string& p, const std::vector<int>& nd, int egz);

    // Getteriai
    std::string getVardas() const;
    std::string getPavarde() const;
    const std::vector<int>& getNdPazymiai() const;
    int getEgzaminas() const;
    double getGalutinis() const;

    // Setteriai (jei reikės)
    void setEgzaminas(int egz);
    void setNdPazymiai(const std::vector<int>& nd);

    // Apskaičiavimas
    void skaiciuotiGalutini(bool naudotiVidurki);

    // Pagalbinės statinės funkcijos
    static double skaiciuotiVidurki(const std::vector<int>& pazymiai);
    static double skaiciuotiMediana(std::vector<int> pazymiai);
    
    friend std::ostream& operator<<(std::ostream& os, const Studentas& s);
};



#endif
