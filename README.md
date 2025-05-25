# README – v1.2 versija: Studentas klasės patobulinimas

## Užduoties aprašymas

Praplėskite v1.1 versiją, sukurkite šaką `v1.2` ir realizuokite visus reikiamus "Rule of Five" bei įvesties/išvesties operatorius `Studentas` klasei. Visi šie metodai turi būti pilnai realizuoti. Net jei kai kurie operatoriai nenaudojami tiesiogiai programoje, jie turi būti tinkamai įgyvendinti, nes tai svarbu būsimiems naudotojams.

Taip pat turi būti parengtas paprastas testas, kuris tikrina, ar visi metodai veikia teisingai. Galiausiai būtina sukurti `v1.2` šakos release versiją.


## Rule of Five ir perdengtų metodų aprašymas

### Realizuoti metodai `Studentas` klasėje:

| Metodas                       | Tipas                             | Aprašymas                                  |
| ----------------------------- | --------------------------------- | ------------------------------------------ |
| `Studentas()`                 | Konstruktorius                    | Numatytoji būsena                          |
| `Studentas(const Studentas&)` | Kopijavimo konstruktorius         | Kopijuoja objektą                          |
| `Studentas(Studentas&&)`      | Perkėlimo konstruktorius          | Perkelia objektą                           |
| `operator=(const Studentas&)` | Kopijavimo priskyrimo operatorius | Kopijuoja reikšmes                         |
| `operator=(Studentas&&)`      | Perkėlimo priskyrimo operatorius  | Perkelia reikšmes                          |
| `~Studentas()`                | Destruktorius                     | Išvalo išteklius                           |
| `operator>>`                  | Įvestis                           | Leidžia įvesti studentą per `cin` ar failą |
| `operator<<`                  | Išvestis                          | Leidžia išvesti studentą į `cout` ar failą |

## Duomenų įvedimo/išvedimo galimybės

* **Rankinis įvedimas** per meniu pasirinkimą
* **Automatinis generavimas** naudojant `generuotiPazymius`, `generuotiVardusPavardesIrPazymius`
* **Failų nuskaitymas** su `skaitymasIsFailo()`
* **Rezultatų išvedimas į konsolę** su `rasymas()`
* **Rezultatų išvedimas į failą** su `rasymasIFaila()`

## Testavimo funkcija

Funkcija `testuotiStudenta()` tikrina:

* Kopijavimo konstruktorių
* Perkėlimo konstruktorių
* Priskyrimo operatorius (abiem būdais)
* Galutinio balo skaičiavimą
* `operator<<` veikimą

### Testavimo pavyzdys

```cpp
void testuotiStudenta() {
    std::vector<int> nd = { 10, 9, 8 };
    Studentas s1("Jonas", "Jonaitis", nd, 10);
    s1.skaiciuotiGalutini(true); // ← svarbu!

    Studentas s2 = s1;
    Studentas s3 = std::move(s1);

    Studentas s4;
    s4 = s2;

    Studentas s5;
    s5 = std::move(s3);

    std::cout << "Testas:" << std::endl;
    std::cout << s2 << std::endl;
    std::cout << s4 << std::endl;
    std::cout << s5 << std::endl;
}
```![Screenshot (43)](https://github.com/user-attachments/assets/294f2ec2-69dc-4121-84da-294c79392753)



## Programos veikimo nuotrauka

Pridėta terminalo testavimo išvesties nuotrauka:



## Išvada

* Visi reikalavimai v1.2 versijai įgyvendinti programiškai
* Klasė `Studentas` atitinka gerąsias C++ praktikas (Rule of Five, OOP)

Šis README dokumentas atspindi visus v1.2 tikslus ir pagrindinius vertinimo kriterijus.
