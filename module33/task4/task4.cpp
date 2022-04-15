#include <iostream>
#include <vector>

template<typename T>
T average(const std::vector<T>& vec) {
    T aver = 0;
    if (!vec.empty()) {
        for (auto& a : vec) {
            aver += a;
        }
        aver /= vec.size();
    }
    return aver;
}

template<typename T>
void input(std::vector<T>& vec) {
    int count = 0;
    T val;
    while (count < 3) {
        std::cout << "Fill the array [";
        std::cout << count++ << "]: ";
        std::cin >> val;
        vec.push_back(val);
    }
}

template<typename T>
void mainFun() {
    std::vector<T> vec;
    input<T>(vec);
    T a = average(vec);
    std::cout << "average = " << a << std::endl;
}

int main() {
    std::cout << "int" << std::endl;
    mainFun<int>();
    std::cout << "\ndouble" << std::endl;
    mainFun<double>();
    std::cout << "\nunsigned long" << std::endl;
    mainFun<unsigned long>();
}