#include <iostream>
#include <vector>

class Tree {
  std::string name = "Empty";
  std::vector<Tree*> branchs;

public:
  void generationTree(int minBig, int maxBig, int minMid, int maxMid) {
    std::srand((unsigned int)time(nullptr));
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
  tr->find(fName);
  tr->generationTree(1, 1, 1, 1);
  std::cout << "FIND. Enter name: ";
  std::cin >> fName;
  tr->find(fName);
  return 0;
}