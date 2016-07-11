#include <iostream>

int main(int argc, char* argv[]) {
	int p, e, i, d;

	//Input and output
	int count = 1;
	while (std::cin >> p >> e >> i >> d) {
		//Chech the end of input
		if (p == -1) {
			break;
		}

		//Calculate
		int day = 0;
		while (!(p == e && e  == i)) {
			while (p < e || p < i) {
				p += 23;
			}
			while (e < p || e < i) {
				e += 28;
			}
			while (i < e || i < p) {
				i += 33;
			}
		}
		day = p - d;
		if (day <= 0) {
			do {
				day += 21252;
			} while (day <= 0);
		}
		if (day > 21252) {
			do {
				day -= 21252;
			} while (day > 21252);
		}

		//Output
		std::cout << "Case "<< count++ << ": the next triple peak occurs in " << day << " days." << std::endl;
	}

	return 0;
}
