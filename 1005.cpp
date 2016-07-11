#include <iostream>

#define PI 3.141593

int main(int argc, char* argv[]) {
	int n;
	double x, y;

	//Input and output
	std::cin >> n;
	for (int i = 1; i <= n; i++) {
		std::cin >> x >> y;
		double r2 = x*x + y*y;
		int year = 1;
		while (r2 > 100.0*year / PI) {
			year++;
		}
		std::cout << "Property " << i << ": This property will begin eroding in year " << year << '.' << std::endl;
	}
	std::cout << "END OF OUTPUT." << std::endl;

	return 0;
}
