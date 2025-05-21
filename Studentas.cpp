#include "studentas.h"
#include <numeric>
#include <algorithm>
#include <iostream>
#include <iomanip>
std::ostream& operator<<(std::ostream& os, const Studentas& s) {
    os << s.getPavarde() << " " << s.getVardas() << " " << s.getGalutinis();
    return os;
}
Studentas::Studentas() : egzaminas(0), galutinis(0.0) {}

Studentas::Studentas(const std::string& v, const std::string& p, const std::vector<int>& nd, int egz)
    : vardas(v), pavarde(p), ndPazymiai(nd), egzaminas(egz), galutinis(0.0) {
}

std::string Studentas::getVardas() const { return vardas; }
std::string Studentas::getPavarde() const { return pavarde; }
const std::vector<int>& Studentas::getNdPazymiai() const { return ndPazymiai; }
int Studentas::getEgzaminas() const { return egzaminas; }
double Studentas::getGalutinis() const { return galutinis; }

void Studentas::setEgzaminas(int egz) { egzaminas = egz; }
void Studentas::setNdPazymiai(const std::vector<int>& nd) { ndPazymiai = nd; }

void Studentas::skaiciuotiGalutini(bool naudotiVidurki) {
    double pagrindas = naudotiVidurki
        ? skaiciuotiVidurki(ndPazymiai)
        : skaiciuotiMediana(ndPazymiai);
    galutinis = 0.4 * pagrindas + 0.6 * egzaminas;
}

double Studentas::skaiciuotiVidurki(const std::vector<int>& pazymiai) {
    if (pazymiai.empty()) return 0.0;
    return std::accumulate(pazymiai.begin(), pazymiai.end(), 0.0) / pazymiai.size();
}

double Studentas::skaiciuotiMediana(std::vector<int> pazymiai) {
    if (pazymiai.empty()) return 0.0;
    std::sort(pazymiai.begin(), pazymiai.end());
    size_t n = pazymiai.size();
    return (n % 2 == 0)
        ? (pazymiai[n / 2 - 1] + pazymiai[n / 2]) / 2.0
        : pazymiai[n / 2];
}

