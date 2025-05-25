#ifndef STUDENTAS_H
#define STUDENTAS_H

#include "Zmogus.h"
#include <string>
#include <vector>
#include <iostream>

class Studentas : public Zmogus {
private:
    std::vector<int> ndPazymiai;
    int egzaminas;
    double galutinis;

public:
    // --- Rule of Five ---
    Studentas();
    Studentas(const std::string& v, const std::string& p, const std::vector<int>& nd, int egz);

    // Kopijavimo konstruktorius
    Studentas(const Studentas& other);

    // Perkėlimo konstruktorius
    Studentas(Studentas&& other) noexcept;

    // Kopijavimo priskyrimo operatorius
    Studentas& operator=(const Studentas& other);

    // Perkėlimo priskyrimo operatorius
    Studentas& operator=(Studentas&& other) noexcept;

    // Destruktorius
    ~Studentas();

    // --- Implementuojami abstraktūs metodai iš Zmogus ---
    std::string getVardas() const override;
    std::string getPavarde() const override;

    // Getteriai
    const std::vector<int>& getNdPazymiai() const;
    int getEgzaminas() const;
    double getGalutinis() const;

    // Setteriai
    void setEgzaminas(int egz);
    void setNdPazymiai(const std::vector<int>& nd);

    // Apskaičiavimas
    void skaiciuotiGalutini(bool naudotiVidurki);

    // Pagalbinės statinės funkcijos
    static double skaiciuotiVidurki(const std::vector<int>& pazymiai);
    static double skaiciuotiMediana(std::vector<int> pazymiai);

    // Įvesties / išvesties operatoriai
    friend std::ostream& operator<<(std::ostream& os, const Studentas& s);
    friend std::istream& operator>>(std::istream& is, Studentas& s);
};

#endif

