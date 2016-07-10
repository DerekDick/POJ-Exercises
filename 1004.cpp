#include <iostream>

int main(int argc, char* argv[]) {
	double sum = 0.0, average = 0.0;

	//Input
	double current;
	while (std::cin >> current) {
		sum += current;
	}

	//Calculate
	average = sum / 12;

	//Output
	std::cout << '$' << average << std::endl;

	return 0;
}
