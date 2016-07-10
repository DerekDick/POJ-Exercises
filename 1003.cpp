#include <iostream>

int main(int argc, char* argv[]) {
	double input;

	while (std::cin >> input) {
		int i = 0;
		double sum = 0.0;
		while (sum < input) {
			i++;
			sum += 1.0 / (i + 1);
		}
		if (input) {
			std::cout << i << " card(s)" << std::endl;
		}
	}

	return 0;
}
