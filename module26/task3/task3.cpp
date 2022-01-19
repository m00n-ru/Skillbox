#include <iostream>

// mon 80 50

class Window {
public:
  struct Coord {
    int x1 = 1;
    int y1 = 1;
    int x2 = 10;
    int y2 = 20;
  };

private:
  Coord coord;
  int h = 10;
  int w = 20;

public:
  void resize(int &hNew, int &wNew) {
    if ( coord.x1 + hNew - h < 0 || coord.y1 + wNew - w < 0 || coord.x2 + hNew - h > 50 || coord.y2 + wNew - w > 80) {
      std::cout << " | Error, beyond the display" << std::endl;
    } else {
      coord.x2 += (hNew - h);
      coord.y2 += (wNew - w);
    }
  }

  void move(int &xMove, int &yMove) {
    if (coord.x1 + xMove < 0 || coord.y1 + yMove < 0 || coord.x2 + xMove > 50 ||
        coord.y2 + yMove > 80) {
      std::cout << " | Error, beyond the display" << std::endl;
    } else {
      coord.x1 += xMove;
      coord.x2 += xMove;
      coord.y1 += yMove;
      coord.y2 += yMove;
    }
  }

  int get_x1() { return coord.x1; }

  int get_y1() { return coord.y1; }

  int get_x2() { return coord.x2; }

  int get_y2() { return coord.y2; }
};

class Display {
  int h = 50;
  int w = 80;

public:
  void resize(Window &win) {
    std::cout << "Enter new size: " << std::endl;
    std::cout << " | length: ";
    int hW;
    std::cin >> hW;
    std::cout << " | width: ";
    int wW;
    std::cin >> wW;
    win.resize(hW, wW);
  }

  void move(Window &win) {
    std::cout << "Enter new coordinations windows: " << std::endl;
    std::cout << " | x: ";
    int xN;
    std::cin >> xN;
    std::cout << " | y: ";
    int yN;
    std::cin >> yN;
    win.move(xN, yN);
  }

  void display(Window &win) {
    for (int i = 0; i < h + 1; ++i) {
      for (int j = 0; j < w + 1; ++j) {
        if (i >= win.get_y1() && i <= win.get_y2()) {
          if (j >= win.get_x1() && j <= win.get_x2()) {
            std::cout << '+';
          } else {
            std::cout << '0';
          }
        } else {
          std::cout << '0';
        }
      }
      std::cout << std::endl;
    }
  }
};

int main() {
  Window *win = new Window();
  Display *dis = new Display();

  while (true) {
    std::cout << "Enter command: ";
    std::string com;
    std::cin >> com;
    if (com == "move") {
      // ввод смешения окна mesa
      dis->move(*win);
    } else if (com == "resize") {
      dis->resize(*win);
      // новый размер окна mesa
    } else if (com == "display") {
      // вывод окна
      dis->display(*win);
    } else if (com == "close") {
      delete win;
      win = nullptr;
      delete dis;
      dis = nullptr;
      break;
    } else {
      std::cout << "Error, command" << std::endl;
    }
  }
}