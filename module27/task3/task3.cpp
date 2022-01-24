#include <iostream>
#include <vector>

enum class Task_t {
  A,
  B,
  C
};

class Workers {
  Task_t  typeTask = Task_t::A;
  bool busy = false;
public:
  Workers() {
  }

  void set_task(int& task) {
    std::srand((unsigned int)(task));
    int numTask = rand() % 4;
    switch (numTask) {
      case 1:
        typeTask = Task_t::A;
        break;
      case 2:
        typeTask = Task_t::B;
        break;
      case 3:
        typeTask = Task_t::C;
        break;
    }
    busy = true;
  }

  bool get_busy() {
    return busy;
  }
};

class Managers {
  int idManager = 0;
  std::vector<Workers> workersInTeam;
  bool busyTeam = false;
  int freeWorker = 0;
public:
  Managers() {
  }

  Managers(int& id, int& numWorks) : idManager(id + 1), freeWorker(numWorks) {
    if (numWorks >= 0) {
      workersInTeam.resize(numWorks);
    }
    if (numWorks == 0) {
      busyTeam = true;
    }
  }

  void taskToTeam(int& task) {
    if (freeWorker > 0) {
      for (int i = freeWorker - 1; i >= 0 && i > freeWorker - task - 1; i--) {
        workersInTeam[i].set_task(task);
      }
    }
    this->set_busyTeam();
  }

  void set_busyTeam() {
    int count = 0;
    for (auto& i : workersInTeam) {
      if (!i.get_busy()) {
        ++count;
      }
    }
    freeWorker = count;
    if (freeWorker == 0) {
      busyTeam = true;
    }
  }

  bool get_busyTeam() {
    return busyTeam;
  }

  int get_id() {
    return idManager;
  }

  int get_freeWorker() {
    return freeWorker;
  }
};

class Company {
  int numTeams = 0;
  std::vector<Managers> teams;

public:
  Company() {
  }

  Company(int& num) : numTeams(num) {
    if (num >= 0) {
      teams.resize(num);
    }
  }

  void creatTeam(int& index, int numWorker) {
    if (index >= 0) {
      Managers mangTeam(index, numWorker);
      teams[index] = mangTeam;
    }
  }

  int get_numTeams() {
    return numTeams;
  }

  bool freeTeam() {
    for (auto& i : teams) {
      if (!i.get_busyTeam()) {
        return true;
      }
    }
    return false;
  }

  void tasksToTeam(int& decree) {
    for (auto& i : teams) {
      if (i.get_busyTeam()) {
        continue;
      }
      std::srand((unsigned int)(decree + i.get_id()));
      int task = rand() % i.get_freeWorker() + 1;
      i.taskToTeam(task);
    }

  }

  void stat() {
    for (auto& i : teams){
      std::cout << "Team" << i.get_id() + 1;
      std::cout << " free worker " << i.get_freeWorker() << std::endl;
    }
  }
};

int main() {
  int numTeams = 0;
  do {
    std::cout << "Enter number of teams: ";
    std::cin >> numTeams;
  } while (numTeams < 0);
  Company com(numTeams);

  for (int i = 0; i < com.get_numTeams(); i++) {
    int numWorker = 0;
    do {
      std::cout << "Enter number workers in " << i + 1 << " team: ";
      std::cin >> numWorker;
    } while (numWorker < 0);
    com.creatTeam(i, numWorker);
  }

  while (com.freeTeam()) {
    int decree = 0;
    std::cout << "Enter decree: ";
    std::cin >> decree;
    com.tasksToTeam(decree);
    std::cout << "_______________________" << std::endl;
    com.stat();
  }
  std::cout << "All teams busy" << std::endl;

  return 0;
}