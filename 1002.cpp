#include <iostream>
#include <string>
#include <cstring> //isalpha(); isalnum()
#include <map>

char convert(char c);
void standardize(std::string & str);

int main(int argc, char* argv[]) {
	std::map<std::string, int> telephoneNums;
	
	//Input
	int n;
	std::string current;
	std::cin >> n;
	while (std::cin >> current) {
		standardize(current);
		telephoneNums[current]++;
	}

	//Output
	bool noDuplicates = true;
	for (std::map<std::string, int>::iterator iter = telephoneNums.begin(); iter != telephoneNums.end(); iter++) {
		if (iter->second > 1) {
			std::cout << iter->first << ' ' << iter->second << std::endl;
			noDuplicates = false;
		}
	}
	if (noDuplicates) {
		std::cout << "No duplicates." << std::endl;
	}

	return 0;
}

char convert(char c) {
	if (!isalpha(c))
		return c;
	else if (c >= 'A' && c <= 'C')
		c = '2';
	else if (c >= 'D' && c <= 'F')
		c = '3';
	else if (c >= 'G' && c <= 'I')
		c = '4';
	else if (c >= 'J' && c <= 'L')
		c = '5';
	else if (c >= 'M' && c <= 'O')
		c = '6';
	else if (c == 'P' || c == 'R' || c == 'S')
		c = '7';
	else if (c >= 'T' && c <= 'V')
		c = '8';
	else if (c >= 'W' && c <= 'Y')
		c = '9';

	return c;
}

void standardize(std::string & str) {
	char temp[9] = "";
	int length = str.length();
	for (int i = 0, j = 0; i < length; i++) {
		char c = str[i];
		if (isalnum(c)) {
			temp[j++] = convert(c);
		}
		if (j == 3) {
			temp[j++] = '-';
		}
	}
	str = std::string(temp);

	return;
}
