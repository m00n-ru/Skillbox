#include <iostream>
#include <vector>

template<typename T1, typename T2>
class Registr {
    std::vector<T1> keys;
    std::vector<T2> values;
public:
    ~Registr() = default;
    void add(T1& key, T2& val);
    void remove(T1& key);
    void print() const;
    std::vector<T2> find(T1& key);
};

template<typename T1, typename T2>
void Registr<T1, T2>::add(T1& key, T2& val) {
    keys.push_back(key);
    values.push_back(val);
}

template<typename T1, typename T2>
void Registr<T1, T2>::remove(T1& key) {
    auto itK = keys.begin();
    auto itV = values.begin();
    bool find = false;
    for (itK, itV; itK != keys.end() || itV != values.end(); ++itK, ++itV) {
        if (*itK == key) {
            keys.erase(itK);
            values.erase(itV);
            --itK;
            --itV;
            find = true;
        }
    }
    if (!find) {
        std::cout << "Not found key: " << key << std::endl;
    }
}

template<typename T1, typename T2>
void Registr<T1, T2>::print() const {
    auto itK = keys.begin();
    auto itV = values.begin();
    for (itK, itV; itK != keys.end() || itV != values.end(); ++itK, ++itV) {
        std::cout << *itK << " " << *itV << std::endl;
    }
}

template<typename T1, typename T2>
std::vector<T2> Registr<T1, T2>::find(T1& key) {
    std::vector<T2> valRasult;
    auto itK = keys.begin();
    auto itV = values.begin();
    bool find = false;
    for (itK, itV; itK != keys.end() || itV != values.end(); ++itK, ++itV) {
        if (*itK == key) {
            valRasult.push_back(*itV);
            find = true;
        }
    }
    if (!find) {
        std::cout << "Not found key: " << key << std::endl;
    }
    return valRasult;
}


int main() {
    std::string ch;
    Registr<int, std::string> reg;
    int a;
    std::string b;
    while (true) {
        std::cout << "1. add\n2. remove\n3. find\n4. print\nany key to exit:";
        std::cin >> ch;
        if (ch == "1") {
            std::cout << "Add element\nkey: ";
            std::cin >> a;
            std::cout << "value: ";
            std::cin >> b;
            reg.add(a, b);
        } else if (ch == "2") {
            std::cout << "Remove\nkey: ";
            std::cin >> a;
            reg.remove(a);
        } else if (ch == "3") {
            std::cout << "Find\nkey: ";
            std::cin >> a;
            std::vector<std::string> result = reg.find(a);
            for (auto& a : result) {
                std::cout << a << " ";
            }
            std::cout << std::endl;
        } else if (ch == "4") {
            std::cout << "Print\n";
            reg.print();
        } else {
            std::cout << "Exit";
            break;
        }
    }
}