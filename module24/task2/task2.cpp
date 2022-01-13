#include <iostream>
#include <ctime>
#include <iomanip>
#include <string>
#include <vector>
#include <sstream>

#pragma warning(disable : 4996)

struct Person {
  std::string name;
  std::tm birth_date {};
};

void add(std::vector<Person>& vec) {
  std::string name;
  std::time_t t = std::time(nullptr);

  std::cout << "Enter name: ";
  std::cin >> name;

  while ( name != "end" ) {
	Person per;
	per.name = name;
	std::cout << "Enter date of birth in format (YYYY/MM/DD): ";
	if ( !(std::cin >> std::get_time(&per.birth_date, "%Y/%m/%d")) ) {
	  std::cin.clear();
	  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	  std::cout << "Error!" << std::endl;
	  continue;
	}
	vec.push_back(per);
	std::cout << "Enter name: ";
	std::cin >> name;
  }
}

void remind(std::vector<Person>& vec) {
  std::time_t td = std::time(nullptr);
  std::tm day = *std::localtime(&td);
  std::stringstream b_today;
  std::stringstream future;
  std::tm tmp {};

  std::cout << "Current date: " << std::put_time(&day, "%Y/%m/%d") << std::endl;

  for ( Person p : vec ) {
	if ( p.birth_date.tm_mon == day.tm_mon && p.birth_date.tm_mday == day.tm_mday ) {
	  b_today << p.name << std::endl;
	} else if ( p.birth_date.tm_mon >= day.tm_mon ) {
	  if ( tmp.tm_year == 0 ) {
		tmp = p.birth_date;
		future << p.name << std::endl;
	  } else {
		if ( p.birth_date.tm_mon < tmp.tm_mon ) {
		  tmp = p.birth_date;
		  future.str("");
		  future << p.name << std::endl;
		} else if ( p.birth_date.tm_mon == tmp.tm_mon ) {
		  if ( p.birth_date.tm_mday == tmp.tm_mday ) {
			future << p.name << std::endl;
		  } else if ( p.birth_date.tm_mday < tmp.tm_mday ) {
			future.str("");
			future << p.name << std::endl;
		  }
		}
	  }
	}
  }
  std::cout << "Today birthday" <<std::endl;
  b_today >> std::cout.rdbuf();
  std::cout << "Future birthday" << std::endl;
  future >> std::cout.rdbuf();
}

int main() {
  std::vector<Person> book;

  add(book);
  remind(book);
}
