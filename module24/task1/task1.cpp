
#include <iostream>
#include <ctime>
#include <iomanip>
#include <vector>

#pragma warning(disable : 4996)

struct Task_struct {
	std::time_t start = 0;
	std::time_t end = 0;
	std::string name {};
};

void begin_task(std::vector<Task_struct>& task, bool& task_start) {
	std::time_t task_time = std::time(nullptr);
	Task_struct task_new;

	if( task_start ) {
		task.back().end = task_time;
	}

	std::cout << "Create new task, enter name: ";
	std::cin >> task_new.name;
	task_new.start = task_time;
	task.push_back(task_new);
	task_start = true;
}

void end_task(std::vector<Task_struct>& task, bool& task_start) {
	std::time_t task_time = std::time(nullptr);
	if( task.empty() ) {
		std::cout << "No created task" << std::endl;
	} else {
		std::cout << "Task ended: " << task.back().name << std::endl;
		task.back().end = task_time;
		task_start = false;
	}
}

void status_task(std::vector<Task_struct>& task) {
	std::cout << "Time" << std::setw(9) << "Task" << std::endl;
	for( Task_struct t : task ) {
		if( t.end != 0 ) {
			std::time_t b = t.end - t.start;
			std::cout << std::put_time(std::gmtime(&b), "%H:%M:%S ") << t.name << std::endl;
		} else {
			std::cout << "Carrunt task:" << std::endl;
			std::cout << t.name << std::endl;
		}
	}
	std::cout << std::endl;
}

int main() {
	std::string com;
	std::vector<Task_struct> task;
	bool task_start = false;

	while( true ) {
		std::cout << "Enter command: ";
		std::cin >> com;
		if( com == "begin" ) {
			begin_task(task, task_start);
		} else if( com == "end" ) {
			end_task(task, task_start);
		} else if( com == "status" ) {
			status_task(task);
		} else if( com == "exit" ) {
			std::cout << task.front().end;
			break;
		} else {
			std::cout << "Unknown command" << std::endl;
		}
	}
}