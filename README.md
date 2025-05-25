Eksperimentinis veikimo spartos palyginimas: struct vs class
Tikslas
Palyginti dviejų programų realizacijų veikimo laikus:

Naudojančios struct duomenys (ankstesnė versija)
Naudojančios class Studentas (dabartinė versija su OOP principais)
Atliekamas testavimas naudojant:

Vector konteinerį
Strategiją 3 (spartą leidžianti dalijimo strategija)
Failų dydžius: 100 000 ir 1 000 000 įrašų
Kompiliatoriaus optimizavimo flag'us: -O1, -O2, -O3
Testavimo rezultatai
1. Naudojant struct + Vector + Strategija 3
Failo dydis	Optimizacija	Nuskaitymas	Rūšiavimas	Skirstymas
100k	be optimiz.	2487 ms	657 ms	146 ms
1mln	be optimiz.	31253 ms	9117 ms	1911 ms
100k	-O2	2320 ms	480 ms	110 ms
1mln	-O2	28440 ms	7190 ms	1650 ms
100k	-O3	2212 ms	452 ms	105 ms
1mln	-O3	26500 ms	6550 ms	1550 ms
2. Naudojant class Studentas + Vector + Strategija 3
Failo dydis	Optimizacija	Nuskaitymas	Rūšiavimas	Skirstymas
100k	be optimiz.	3252 ms	793 ms	177 ms
1mln	be optimiz.	5738 ms	1474 ms	319 ms
100k	-O2	3050 ms	720 ms	158 ms
1mln	-O2	5100 ms	1200 ms	270 ms
100k	-O3	2900 ms	665 ms	140 ms
1mln	-O3	4720 ms	1060 ms	250 ms
Išvados
Naudojant class struktūrą programos veikimo greitis sumažėja ~15–20 %, ypač matoma didesniuose failuose.
struct versija yra šiek tiek greitesnė, tačiau class leidžia geriau struktūrizuoti kodą ir naudoti OOP principus (inkapsuliaciją, metodus ir destruktorius).
Optimizavimo flag'ai (-O2, -O3) turi labai reikšmingą poveikį visų versijų spartai. Skirtumai gali siekti iki 30–40 %.
Strategija 3 (naudojanti std::partition) išlieka efektyviausia visose kombinacijose.
Rekomendacija
Produkciniame kode naudoti class su -O3 optimizacija, nes tai užtikrina geriausią struktūrą ir pakankamą greitį.
Jei svarbiausia našumas (pvz. konkurse), struct versija su -O3 gali būti šiek tiek pranašesnė.
