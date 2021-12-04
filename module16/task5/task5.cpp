#include <bitset>
#include <iostream>
#include <sstream>

enum mang : const int {
  mangAllHome,
  mangElectHome,
  mangLigthIn,
  mangLigthOut,
  mangHeatingHome,
  mangHeatingWater,
  mangCondi
};

std::string statusText(std::bitset<7> statusOld, std::bitset<7> statusNew,
                       int hour) {
  std::string text;
  if (statusOld.test(mangAllHome) != statusNew.test(mangAllHome))
    if (!statusNew.test(mangAllHome)) {
      text += "Power OFF\n";
      statusNew = 0;
    } else {
      text += "Power ON\n";
    }

  if (statusOld.test(mangElectHome) != statusNew.test(mangElectHome))
    if (statusNew.test(mangElectHome)) {
      text += "Electrical outlets: ON\n";
    } else {
      text += "Electrical outlets: OFF\n";
    }
  if (statusOld.test(mangLigthIn) != statusNew.test(mangLigthIn) ||
      (hour >= 16 && hour <= 24))
    if (statusNew.test(mangLigthIn)) {
      text += "Light inside: ON";
      int lightTemp = 5000;
      if (hour >= 16 && hour < 20) {
        lightTemp -= 460 * (hour - 15);
      } else if (hour >= 20 && hour <= 23) {
        lightTemp = 2700;
      }
      text += " (LightTemperature = " + std::to_string(lightTemp) + ")\n";
    } else {
      text += "Light inside: OFF\n";
    }
  if (statusOld.test(mangLigthOut) != statusNew.test(mangLigthOut))
    if (statusNew.test(mangLigthOut)) {
      text += "Light outside: ON\n";
    } else {
      text += "Light outside: OFF\n";
    }
  if (statusOld.test(mangHeatingHome) != statusNew.test(mangHeatingHome))
    if (statusNew.test(mangHeatingHome)) {
      text += "Heating home: ON\n";
    } else {
      text += "Heating home: OFF\n";
    }
  if (statusOld.test(mangHeatingWater) != statusNew.test(mangHeatingWater))
    if (statusNew.test(mangHeatingWater)) {
      text += "Heating waterpipe: ON\n";
    } else {
      text += "Heating waterpipe: OFF\n";
    }
  if (statusOld.test(mangCondi) != statusNew.test(mangCondi))
    if (statusNew.test(mangCondi)) {
      text += "conditioner: On\n";
    } else {
      text += "conditioner: OFF\n";
    }
  return text;
}

int main() {
  // double sensTempOut;
  // double sensTempIn;
  // std::string sensMotion;
  // std::string sensLigth;

  std::bitset<7> statusOld{0b0101111};
  std::bitset<7> statusNew{0b0110111};

  // std::cout << "Enter sensor (Temp IN, Temp OUT, Motion, Ligth): ";
  // std::string input;
  // std::stringstream sens;
  // getline(std::cin, input);
  // sens << input;
  // sens >> sensTempOut >> sensTempIn >> sensMotion >> sensLigth;

  std::cout << statusText(statusOld, statusNew, 19);

  return 0;
}