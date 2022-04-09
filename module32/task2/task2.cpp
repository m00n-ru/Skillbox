#include <iostream>
#include <vector>
#include <fstream>
#include "json.hpp"

nlohmann::json::iterator find(nlohmann::json& db, std::string name) {
    auto it = db.begin();
    for (; it != db.end(); ++it) {
        std::vector<std::string> starring = it.value()["starring"];
        for (auto& a : starring) {
            if (a == name) {
                return it;
            }
        }
    }
    return it;
}

int main() {
    std::ifstream file("filmsBD.json");
    nlohmann::json fdb;
    file >> fdb;

    std::string name = "Al Pacino";

    std::cout << "Find starring in DB films:" << std::endl;

    nlohmann::json::iterator itFind;
    itFind = find(fdb, name);
    if (itFind != fdb.end()) {
        std::cout << name << std::endl;
        std::cout << "Films: " << itFind.key() << std::endl;
        std::cout << "Release dates: " << itFind.value()["date"].get<int>() << std::endl;
    } else {
        std::cout << "Not found" << std::endl;
    }
}
