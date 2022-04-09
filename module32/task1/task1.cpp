#include <iostream>
#include <fstream>
#include "json.hpp"

struct AboutFilm {
    std::string name = "The Godfather";
    int date = 1972;
    std::string companies = "Paramount Pictures";
    std::string country = "United States";
    std::string screenplay = "Mario Puzo";
    std::string directed = "Francis Ford Coppola";
    std::string produced = "Albert S. Ruddy";
    std::vector<std::string> starring = { {"Marlon Brando"},
                                          {"Al Pacino"},
                                          {"James Caan"},
                                          {"Richard Castellano"},
                                          {"Robert Duvall"}};
};

int main() {
    AboutFilm film;
    nlohmann::json object = {{"name" , film.name},
                             {"companies", film.companies},
                             {"date", film.date},
                             {"country", film.country},
                             {"screenplay", film.screenplay},
                             {"directed", film.directed},
                             {"producer", film.produced},
                             {"starring", film.starring}};

    std::ofstream file("film.json");
    file << std::setw(4) << object << "\n\n";
    file.close();
}