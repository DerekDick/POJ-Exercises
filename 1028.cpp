#include <iostream>
#include <stack>
#include <string>

int main(int argc, char* argv[]) {
	std::stack<std::string> forward, backward;

	//Input and output in loops
	std::string command, url = "http://www.acm.org/";
	while (std::cin >> command) {
		//VISIT
		if (command == "VISIT") {
			backward.push(url);
			std::cin >> url;
			while (!forward.empty()) {
				forward.pop();
			}
			std::cout << url << std::endl;
		}
		//BACK
		else if (command == "BACK") {
			if (backward.empty()) {
				std::cout << "Ignored" << std::endl;
				continue;
			}
			forward.push(url);
			url = backward.top();
			backward.pop();
			std::cout << url << std::endl;
		}
		//FORWARD
		else if (command == "FORWARD") {
			if (forward.empty()) {
				std::cout << "Ignored" << std::endl;
				continue;
			}
			backward.push(url);
			url = forward.top();
			forward.pop();
			std::cout << url << std::endl;
		}
		//QUIT
		else {
			break;
		}
	}

	return 0;
}
