#include <iostream>
#include <string>
#include <vector>
#include <algorithm> //std::swap()

int inversion(std::string str);

template <typename T1, typename T2>
void sort2Vectors(std::vector<T1> & vecToSort, std::vector<T2> & vecAssociated) {
	/*This template function is used to sort a vector and another vector associated with it at the same time*/
	int length = vecToSort.size();
	for (int i = 0; i < length - 1; i++) {
		for (int j = length - 1; j > i; j--) {
			if (vecToSort[j] < vecToSort[j - 1]) {
				std::swap(vecToSort[j], vecToSort[j - 1]);
				std::swap(vecAssociated[j], vecAssociated[j - 1]);
			}
		}
	}

	return;
}

int main(int argc, char* argv[]) {
	int length = 0, n = 0;
	std::vector<std::string> DNAs;
	std::vector<int> inversions;

	//Input
	std::cin >> length >> n;
	std::string current;
	while (std::cin >> current) {
		DNAs.push_back(current);
		inversions.push_back(inversion(current));
	}

	//Sorting
	sort2Vectors(inversions, DNAs);

	//Output
	for (std::vector<std::string>::iterator iter = DNAs.begin(); iter != DNAs.end(); iter++) {
		std::cout << *iter << std::endl;
	}

	return 0;
}

int inversion(std::string str) {
	int inversion = 0;
	for (std::string::iterator iter = str.begin(); iter != str.end(); iter++) {
		for (std::string::iterator it = str.begin(); it != iter; it++) {
			if (*it > *iter) {
				inversion++;
			}
		}
	}

	return inversion;
}
