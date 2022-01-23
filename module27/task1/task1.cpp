#include <iostream>
#include <vector>

//Лесные эльфы расположили свою деревню в лесу, прямо на деревьях.Нужно расселить эльфов по веткам деревьев, а затем подсчитать общее количество соседей определённого эльфа.
//
//Всего в лесу пять деревьев, на каждом из деревьев 3–5 основных больших ветвей.На каждой из них расположены ещё по 2 - 3 средние ветки.Дома эльфов построены только на больших и средних ветках.
//
//В начале программы пользователь размещает в каждом доме по одному эльфу.Делается это с помощью последовательного перебора всех имеющихся домов и запроса имени заселяемого эльфа через стандартный ввод.Если было введено None в качестве имени, то дом пропускается и не заселяется вообще никем.
//
//После этого требуется найти определённого эльфа по имени.Имя искомого эльфа вводится через стандартный ввод.Для данного эльфа, если таковой был найден, требуется вывести общее количество эльфов, живущих вместе с ним на одной большой ветви.
//
//Советы и рекомендации
//
//Реализуйте генерацию деревьев с помощью кода, используя случайные числа.Для организации структуры деревьев используйте указатель this.

class Tree {
  std::string name = "Empty";
  std::vector<Tree*> branchs;

public:
  void generationTree(int minBig, int maxBig, int minMid, int maxMid) {
    std::srand((unsigned int)std::time(nullptr));
    int countBigBranch = std::rand() % (maxBig - minBig + 1) + minBig;
    branchs.resize(countBigBranch);
    for (int i = 0; i < countBigBranch; i++) {
      branchs[i] = new Tree;
      std::cout << "Enter elf name on " << i + 1 << " big branch: ";
      std::cin >> branchs[i]->name;
      int countMidBranch = std::rand() % (maxMid - minMid + 1) + minMid;
      branchs[i]->branchs.resize(countMidBranch);
      for (int j = 0; j < countMidBranch; j++) {
        branchs[i]->branchs[j] = new Tree;
        std::cout << "Enter elf name on " << i + 1 << " big branch " << j + 1 << " middle branch: ";
        std::cin >> branchs[i]->branchs[j]->name;
      }
    }
  }

  void find(std::string& fName) {
    bool find = false;
    for (int i = 0; i < branchs.size(); i++) {
      int result = 0;
      if (branchs[i]->name == fName) {
        find = true;
      } else {
        if (branchs[i]->name != "None") {
          ++result;
        }
      }
      for (int j = 0; j < branchs[i]->branchs.size(); j++) {
        if (branchs[i]->branchs[j]->name == fName) {
          find = true;
        }

        if (branchs[i]->branchs[j]->name != "None" && branchs[i]->branchs[j]->name != fName) {
          ++result;
        }
      }
      if (find) {
        std::cout << fName << " found! This elf has " << result << " neighbors" << std::endl;
        return;
      }
    }
    std::cout << fName << " not found!" << std::endl;
  }
};

int main() {
  Tree* tr = new Tree;
  std::string fName;
  tr->generationTree(3, 5, 2, 3);
  std::cout << "FIND. Enter name: ";
  std::cin >> fName;
  tr->find(fName);
}