#include <bitset>
#include <iostream>
#include <sstream>

enum mang {
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
      hour >= 16 || hour == 0)
    if (statusNew.test(mangLigthIn)) {
      text += "Light inside: ON";
      int lightTemp = 5000;
      if (hour >= 16 && hour < 20) {
        lightTemp -= 460 * (hour - 15);
      } else if (hour >= 20) {
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
      text += "conditioner: ON\n";
    } else {
      text += "conditioner: OFF\n";
    }
  return text;
}

std::bitset<7> event(std::bitset<7> status, int hour) {
  double sensTempOut;
  double sensTempIn;
  std::string sensMotion;
  std::string sensLigth;

  std::cout << "Enter sensor (Temp OUT, Temp IN, Motion, Ligth): ";
  std::string input;
  std::stringstream sens;
  getline(std::cin, input);
  sens << input;
  sens >> sensTempOut >> sensTempIn >> sensMotion >> sensLigth;

  if (sensTempOut < 0) {
    status.set(mangHeatingWater);
  }

  if (sensTempOut > 5) {
    status.reset(mangHeatingWater);
  }

  if (sensMotion == "yes" && (hour > 16 || hour < 5)) {
    status.set(mangLigthOut);
  } else {
    status.reset(mangLigthOut);
  }

  if (sensTempIn < 22) {
    status.set(mangHeatingHome);
  }

  if (sensTempIn >= 25) {
    status.reset(mangHeatingHome);
  }

  if (sensTempIn >= 30) {
    status.set(mangCondi);
  }

  if (sensTempIn < 30 && status.test(mangCondi)) {
    status.reset(mangCondi);
  }

  if (sensLigth == "on") {
    status.set(mangLigthIn);
  } else {
    status.reset(mangLigthIn);
  }
  return status;
}

int main() {
  std::bitset<7> statusOld = 0b1111110;
  std::bitset<7> statusNew = 0b0000001;
  std::cout << "System initialization" << std::endl << std::endl;
  std::cout << statusText(statusOld, statusNew, 0) << std::endl;

  for (int hour = 0, day = 1; day < 3; hour++) {
    if (hour > 23) {
      ++day;
      hour = 0;
    }
    statusOld = statusNew;
    std::cout << day << "day " << hour << " hour" << std::endl;
    statusNew = event(statusOld, hour);
    std::cout << statusText(statusOld, statusNew, hour);
  }
  return 0;
}