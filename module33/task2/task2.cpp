#include <iostream>
#include <ctime>
#include <limits>

class winException : public std::exception {};
class loseException : public std::exception {};

int fishing(int sect, int* pond) {
    if (sect > 8 || sect < 0) {
        throw std::invalid_argument("Wrong sector number");
    } else {
        if (pond[sect] == 1) {
            throw winException();
        } else if (pond[sect] == 2) {
            throw loseException();
        } else {
            return 1;
        }

    }
}

int main() {
    int position[4] = { 10 };
    int pond[9] = { 0 };
    int sector;
    int tryes = 1;

    std::srand(std::time(nullptr));
    for (int i = 0; i < 4; ++i) {
        int index = std::rand() % 9;
        for (auto& a : position) {
            if (a == index) {
                --i;
                break;
            }
        }
        position[i] = index;
        if (i == 0) {
            pond[index] = 1;
        } else {
            pond[index] = 2;
        }
    }

    std::cout << "Start game\nEnter pond sector: 0-8" << std::endl;
    while (true) {
        std::cin >> sector;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            throw std::invalid_argument("Incorrect input, repeat!");
        } else {
            try {
                tryes += fishing(sector, pond);
            }
            catch (const winException& x) {
                std::cout << "You win! Catch the fish. Tryes: " << tryes;
                break;
            }
            catch (const loseException& x) {
                std::cout << "You lose! Catched the boot!";
                break;
            }
            catch (const std::invalid_argument& x) {
                std::cout << x.what() << std::endl;
            }
        }
        std::cout << "Tryes: " << tryes << ". Enter pond sector: 0-8" << std::endl;
    }
}