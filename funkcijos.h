#ifndef FUNKCIJOS_H
#define FUNKCIJOS_H
#include "studentas.h"

#include <iostream>
#include <vector>
#include <string>
#include "studentas.h"

using namespace std;

bool tikrintiVardaPavarde(const string& tekstas);
double vid(const vector<int>& N);
double mediana(vector<int> N);
int gautiPasirinkima();
bool noriTęsti();
void atliktiTestavimusSuVisaisFailais();


void skaitymas(vector<Studentas>& M);
void skaiciavimas(vector<Studentas>& M, int pasirinkimas);
void rikiuotiMokinius(vector<Studentas>& M, int pasirinkimas, bool atvirkstine);
void rasymas(const vector<Studentas>& M);
void rasymasIFaila(const vector<Studentas>& M);

void generuotiVardusPavardesIrPazymius(vector<Studentas>& M);
void generuotiPazymius(vector<Studentas>& M);
void skaitymasIsFailo(vector<Studentas>& M, const string& failoPavadinimas);

void generuotiFaila(const std::string& failoVardas, int kiekis);
void generuotiPasirinktaFaila();
void analizuotiPasirinktaFaila();
long long analizuotiFaila(const std::string& failoVardas);
void atliktiAnalize();

void testuotiVector(const std::string& failas);
void testuotiList(const std::string& failas);
void testuotiDeque(const std::string& failas);

void atliktiAnalizeStrategija2();
void testuotiStrategija2Vector(const std::string& failas);
void testuotiStrategija2List(const std::string& failas);
void testuotiStrategija2Deque(const std::string& failas);

void atliktiAnalizeStrategija3();
void testuotiStrategija3Vector(const std::string& failas);
void testuotiStrategija3List(const std::string& failas);
void testuotiStrategija3Deque(const std::string& failas);

#endif
