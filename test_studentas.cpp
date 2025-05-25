
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Studentas.h"

TEST_CASE("Rule of Five: konstruktorius, kopijavimas, perkėlimas") {
    std::vector<int> nd = {10, 9, 8};
    Studentas s1("Jonas", "Jonaitis", nd, 10);
    s1.skaiciuotiGalutini(true);

    SUBCASE("Kopijavimo konstruktorius") {
        Studentas s2 = s1;
        CHECK(s2.getVardas() == "Jonas");
        CHECK(s2.getPavarde() == "Jonaitis");
        CHECK(s2.getGalutinis() == doctest::Approx(s1.getGalutinis()));
    }

    SUBCASE("Perkėlimo konstruktorius") {
        Studentas s3 = std::move(s1);
        CHECK(s3.getVardas() == "Jonas");
        CHECK(s3.getPavarde() == "Jonaitis");
    }

    SUBCASE("Kopijavimo priskyrimas") {
        Studentas s2("A", "B", {}, 0);
        s2 = s1;
        CHECK(s2.getVardas() == "Jonas");
        CHECK(s2.getPavarde() == "Jonaitis");
    }

    SUBCASE("Perkėlimo priskyrimas") {
        Studentas s2("A", "B", {}, 0);
        s2 = std::move(s1);
        CHECK(s2.getVardas() == "Jonas");
        CHECK(s2.getPavarde() == "Jonaitis");
    }
}
