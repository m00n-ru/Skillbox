#include <iostream>
#include <sstream>
#include <bitset>

enum mang : const int {
  mangAllHome = 0,
  mangElectHome,
  mangLigthIn,
  mangLigthOut,
  mangHeatingHome,
  mangHeatingWater,
  mangCondi
};

std::string statusText(std::bitset<8> status) {
	std::string text;
	if (!status.test(mangAllHome)) {
		text += "Power OFF";
	} else {
		text += "Power ON \n";
		if (status.test(mangElectHome)) {
			text += "Electrical outlets: ON\n";
		} else {
			text += "Electrical outlets: OFF\n";
		}
		if (status.test(mangLigthIn)) {
			text += "Light inside: ON\n";
		} else {
			text += "Light inside: OFF\n";
		}
		if (status.test(mangLigthOut)) {
			text += "Light outside: ON\n";
		} else {
			text += "Light outside: OFF\n";
		}
		if (status.test(mangHeatingHome)) {
			text += "Heating home: ON\n";
		} else {
			text += "Heating home: OFF\n";
		}
		if (status.test(mangHeatingWater)) {
			text += "Heating waterpipe: ON\n";
		} else {
			text += "Heating waterpipe: OFF\n";
		}
		if (status.test(mangCondi)) {
			text += "conditioner: On\n";
		} else {
			text += "conditioner: OFF\n";
		}
	}
	return text;
}


int main() {
  //double sensTempOut;
  //double sensTempIn;
  //std::string sensMotion;
  //std::string sensLigth;

	std::bitset<8> status{0b00101011};


  //std::cout << "Enter sensor (Temp IN, Temp OUT, Motion, Ligth): ";
  //std::string input;
  //std::stringstream sens;
  //getline(std::cin, input);
  //sens << input;
  //sens >> sensTempOut >> sensTempIn >> sensMotion >> sensLigth;

	std::cout << statusText(status);

  return 0;
}