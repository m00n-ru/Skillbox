#include <iostream>
#include <exception>
#include <map>
#include <iomanip>

struct Item {
    std::string idItem;
    int countItem;
    Item() : idItem("None"), countItem(0) {};
    bool enter();
};

class Basket {
    std::map<std::string, int>* shopDb;
    std::map<std::string, int> basket;
public:
    Basket(std::map<std::string, int>* Db) : shopDb(Db), basket() {};
    ~Basket() = default;
    void add(Item& item);
    void remove(Item& item);
    const std::map<std::string, int>* get_ptr() const {
        return &basket;
    }
};

bool Item::enter() {
    std::cout << "Enter article product or \"exit\" to complete: ";
    std::cin >> idItem;
    if (idItem == "exit") {
        return false;
    }
    while (true) {
        std::cout << "Enter count product: ";
        std::cin.exceptions(std::istream::failbit | std::istream::badbit);
        try {
            std::cin >> countItem;
        }
        catch (std::istream::failure) {
            std::cin.clear();
            std::cin.sync();
            std::cout << "Incorrect input, repeat!" << std::endl;
            continue;
        }
        if (countItem < 0) {
            std::cout << "Count < 0, repeat!" << std::endl;
        } else {
            break;
        }
    }
    return true;
}

void Basket::add(Item& item) {
    auto it = shopDb->find(item.idItem);
    if (it != shopDb->end()) {
        if (it->second >= item.countItem) {
            basket[item.idItem] = item.countItem;
            (*shopDb)[item.idItem] -= item.countItem;
            std::cout << "Item add" << std::endl;
        } else {
            throw std::invalid_argument("Not enough items\n");
        }
    } else {
        throw std::runtime_error("Item not found\n");
    }
}

void Basket::remove(Item& item) {
    auto it = basket.find(item.idItem);
    if (it != basket.end()) {
        if (it->second <= item.countItem) {
            basket.erase(it);
            (*shopDb)[item.idItem] += it->second;
        } else {
            basket[item.idItem] -= item.countItem;
            (*shopDb)[item.idItem] += item.countItem;
        }
        std::cout << "Item delete" << std::endl;
    } else {
        throw std::runtime_error("Item not found\n");
    }
}

void print(const std::map<std::string, int>& db) {
    for (auto& a : db) {
        std::cout << a.first << " -> " << a.second << std::endl;
    }
}

int main() {
    std::map<std::string, int> shop;
    Basket basket(&shop);
    Item item;

    std::cout << "Create DATABASE shop" << std::endl;
    while (item.enter()) {
        shop[item.idItem] = item.countItem;
    }

    std::cout << std::endl << "BASKET" << std::endl;
    while (true) {
        std::cout << std::endl << "1. add item" << std::endl;
        std::cout << "2. remove item" << std::endl;
        std::cout << "3. print" << std::endl;
        std::cout << "enter 1, 2 or 3: ";
        std::string entCh;
        std::cin >> entCh;
        if (entCh == "1") {
            item.enter();
            try {
                basket.add(item);
            }
            catch (std::exception& exc) {
                std::cout << exc.what();
            }
        } else if (entCh == "2") {
            item.enter();
            try {
                basket.remove(item);
            }
            catch (std::exception& exc) {
                std::cout << exc.what();
            }
        } else if (entCh == "3") {
            std::cout << std::endl << "SHOP" << std::endl;
            print(shop);
            std::cout << std::endl << "BASKET" << std::endl;
            print(*basket.get_ptr());

        } else {
            std::cout << "Incorrect input, repeat!" << std::endl;
        }
    }
}