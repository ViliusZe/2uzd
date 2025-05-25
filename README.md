# Projekto versija v1.5

## Aprašymas

Šioje versijoje `v1.5` įgyvendinta objektinio programavimo plėtra, naudojant paveldėjimą ir abstrakčią klasę. Sukurta abstrakti bazinė klasė `Zmogus`, iš kurios paveldima klasė `Studentas`.

## Pagrindiniai pakeitimai

- Sukurta abstrakti bazinė klasė `Zmogus`, turinti laukus `vardas` ir `pavarde`.
- `Zmogus` turi grynai virtualius metodus `getVardas()` ir `getPavarde()`, todėl negalima sukurti `Zmogus` objekto.
- Klasė `Studentas` paveldi iš `Zmogus` ir implementuoja visus abstrakčius metodus.
- Išlaikyta 1.2 versijos logika ir struktūra.
- `Studentas` palaiko „Rule of Five“ (konstruktorius, kopijavimo/perkėlimo konstruktoriai ir operatoriai, destruktorius).
- Visi egzistuojantys testai (nuskaitymas, rūšiavimas, skirstymas ir kt.) veikia be keitimų.

## Klasės struktūra

```
Zmogus (abstrakti)
 └── Studentas
       - vector<int> ndPazymiai
       - int egzaminas
       - double galutinis
       + skaiciuotiGalutini()
       + getVardas(), getPavarde()
```

## Demonstracija

```cpp
// Negalima kurti Zmogus objekto, ši eilutė sukeltų klaidą:
// Zmogus z("Vardenis", "Pavardenis"); // error: cannot instantiate abstract class

// Galima kurti tik Studentas objektus:
std::vector<int> nd = {10, 9, 8};
Studentas s("Jonas", "Jonaitis", nd, 10);
s.skaiciuotiGalutini(true);
std::cout << s.getVardas() << " " << s.getPavarde() << " " << s.getGalutinis();
```

## Testavimas

- Veikia su visais testais nuo versijos `v1.2`
- Patikrinta:
  - Konstrukcija ir destrukcija
  - Kopijavimas ir perkėlimas
  - Galutinio balo skaičiavimas
  - Failų nuskaitymas, rūšiavimas, skirstymas
  - Skirstymo strategijos (1–3) su vector/list/deque

## Naudojimas

1. Paleisti `main.cpp` (`v2.cpp`) ir pasirinkti funkciją.
2. Duomenys gali būti įvedami, generuojami arba nuskaitomi iš failo.
3. Rezultatai rodomi konsolėje arba išsaugomi į failą.
