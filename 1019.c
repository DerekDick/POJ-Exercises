#include <stdio.h>

unsigned long length(int n);

int main(int argc, char* argv[]) {
	//Input and output in loops
	int t = 0, current = 0, result = 0;
	for (scanf("%d", &t); t > 0; t--) {
		scanf("%d", &current);
		if (current <= 45) {
			int i = 0;
			while (current > length(i)) {
				i++;
			}
			result = current - length(i - 1);
		}
		else if (current <= 9045) {
			int i = 10;
			while (current > length(i)) {
				i++;
			}
			int left = current - length(i - 1);
			if (left <= 9) {
				result = left;
			}
			else {
				int number = 9 + (left - 9 - 1) / 2 + 1;
				if (left % 2) {
					result = number % 10;
				}
				else {
					result = number / 10;
				}
			}
		}
		else if (current <= 1395495) {
			int i = 100;
			while (current > length(i)) {
				i++;
			}
			int left = current - length(i - 1);
			if (left <= 9) {
				result = left;
			}
			else if (left <= 189) {
				int number = 9 + (left - 9 - 1) / 2 + 1;
				if (left % 2) {
					result = number % 10;
				}
				else {
					result = number / 10;
				}
			}
			else {
				int number = 99 + (left - 189 - 1) / 3 + 1;
				if (left % 3 == 0) {
					result = number % 10;
				}
				else if (left % 3 == 1) {
					result = number / 100;
				}
				else {
					result = (number % 100) / 10;
				}
			}
		}
		else if (current <= 189414495) {
			int i = 1000;
			while (current > length(i)) {
				i++;
			}
			int left = current - length(i - 1);
			if (left <= 9) {
				result = left;
			}
			else if (left <= 189) {
				int number = 9 + (left - 9 - 1) / 2 + 1;
				if (left % 2) {
					result = number % 10;
				}
				else {
					result = number / 10;
				}
			}
			else if (left <= 2889) {
				int number = 99 + (left - 189 - 1) / 3 + 1;
				if (left % 3 == 0) {
					result = number % 10;
				}
				else if (left % 3 == 1) {
					result = number / 100;
				}
				else {
					result = (number % 100) / 10;
				}
			}
			else {
				int number = 999 + (left - 2889 - 1) / 4 + 1;
				if (left % 4 == 0) {
					result = (number % 100)/ 10;
				}
				else if (left % 4 == 1) {
					result = number % 10;
				}
				else if (left % 4 == 2) {
					result = number / 1000;
				}
				else {
					result = (number % 1000) / 100;
				}
			}
		}
		else {
			int i = 10000;
			while (current > length(i)) {
				i++;
			}
			int left = current - length(i - 1);
			if (left <= 9) {
				result = left;
			}
			else if (left <= 189) {
				int number = 9 + (left - 9 - 1) / 2 + 1;
				if (left % 2) {
					result = number % 10;
				}
				else {
					result = number / 10;
				}
			}
			else if (left <= 2889) {
				int number = 99 + (left - 189 - 1) / 3 + 1;
				if (left % 3 == 0) {
					result = number % 10;
				}
				else if (left % 3 == 1) {
					result = number / 100;
				}
				else {
					result = (number % 100) / 10;
				}
			}
			else if (left <= 38889) {
				int number = 999 + (left - 2889 - 1) / 4 + 1;
				if (left % 4 == 0) {
					result = (number % 100)/ 10;
				}
				else if (left % 4 == 1) {
					result = number % 10;
				}
				else if (left % 4 == 2) {
					result = number / 1000;
				}
				else {
					result = (number % 1000) / 100;
				}
			}
			else {
				int number = 9999 + (left - 38889 - 1) / 5 + 1;
				if (left % 5 == 0) {
					result = number / 10000;
				}
				else if (left % 5 == 1) {
					result = (number % 10000) / 1000;
				}
				else if (left % 5 == 2) {
					result = (number % 1000) / 100;
				}
				else if (left % 5 == 3) {
					result = (number % 100) / 10;
				}
				else {
					result = number % 10;
				}
			}
		}
		printf("%d\n", result);
	}
	
	return 0;
}

unsigned long length(int n) {
	if (n <= 9) {
		return n * (n + 1) / 2;
	}
	else if (n <= 99) {
		return n * (n - 8) + 36;
	}
	else if (n <= 999) {
		return n * (3 * n - 213) / 2 + 4887;
	}
	else if (n <= 9999) {
		return n * (2 * n - 1105) + 503388;
	}
	else if (n <= 99999) {
		return n * (5.0 * n - 22207.0) / 2.0 + 50488389; //Pay attention, if we use int here, there may be integer overflow in expression!!!
	}
	else {
		printf("!!!!!\n"); //Exception, just for debugging
		return -1;
	}
}
