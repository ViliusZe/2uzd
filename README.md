# Projektas: Studentų analizės sistema

## Versija: v2.0

### Aprašymas

Versijoje v2.0 išplėsta programos architektūra:
- Įtraukta dokumentacija su **Doxygen** (HTML, LaTeX, PDF)
- Įgyvendinti **unit testai** naudojant `doctest` framework'ą
- Struktūra švari ir skirta naudoti bei plėsti
- Paruoštas diegimo failas (`Makefile` arba `CMakeLists.txt`)

---

## Releasai

| Versija | Pagrindiniai pakeitimai |
|---------|--------------------------|
| v1.0    | Veikianti analizės logika, failų generavimas |
| v1.5    | Klasės `Zmogus` ir `Studentas` su paveldėjimu |
| v2.0    | Doxygen dokumentacija, unit testai, diegimo sistema |

---

## Doxygen dokumentacija

- HTML dokumentacija: `docs/html/index.html`
- LaTeX dokumentacija: `docs/latex/refman.pdf` *(generuota su Overleaf)*
- Apima: `Studentas`, `Zmogus`, `funkcijos`, metodus, failus

---

## Unit testai

- Naudotas framework: `doctest`
- Failas: `test_studentas.cpp`
- Tikrinama:
  - Konstruktorius
  - Kopijavimo konstruktorius ir operatorius
  - Perkėlimo konstruktorius ir operatorius
  - Getteriai, `skaiciuotiGalutini()`

### Paleidimas:

```bash
g++ test_studentas.cpp Studentas.cpp -o testai -std=c++17
./testai
```

---

## Naudojimosi instrukcija

1. Paleisk `v2.cpp`
2. Vartotojas gali:
   - Įvesti duomenis ranka
   - Generuoti pažymius ar visus duomenis
   - Testuoti strategijas ir analizę
   - Paleisti testus atskirai

---

## Diegimo instrukcija

### Naudojant `Makefile` (Linux / Git Bash):
```bash
make
./programa
```

### Naudojant `g++` (Windows):
```bash
g++ v2.cpp Studentas.cpp funkcijos.cpp -o programa -std=c++17
programa.exe
```

### Unit testų paleidimas:
```bash
g++ test_studentas.cpp Studentas.cpp -o testai -std=c++17
testai.exe
```
![Screenshot (44)](https://github.com/user-attachments/assets/f9be8f31-cf60-4b59-931d-73effc80f96e)

---

## Repozitorijos struktūra

```
├── v2.cpp
├── Studentas.cpp/h
├── Zmogus.h
├── funkcijos.cpp/h
├── test_studentas.cpp
├── docs/
│   ├── html/
│   └── latex/
│       └── refman.pdf
├── Doxyfile
├── Makefile / CMakeLists.txt
└── README.md
```

---

## Pastabos

- Repozitorija neturi IDE failų, `.exe`, `.o`, `.obj`, `.vs` ir pan.
- Dokumentacija ir testai veikia su C++17
