#include <iostream>
#include <string>
#include <algorithm> //For std::reverse()

std::string add_long_short(const std::string & lhs, const std::string & rhs);
std::string add(const std::string & lhs, const std::string & rhs);
std::string multiple_long_single(const std::string & lhs, const char & rhs);
std::string multiple(const std::string & lhs, const std::string & rhs);
std::string power(const std::string & base, const int n);

int main(int argc, char* argv[]) {
	std::string result, a;
	int n = 0, pos = 0;

	std::string current;
	while (std::cin >> current >> n) {
		//Position the dot
		for (int i = 0; i < 6; i++) {
			if (current[i] == '.') {
				pos = i;
				break;
			}
		}
		//Get the number a
		a.clear();
		for (int i = 0; i < 6; i++) {
			if (i != pos) {
				a.push_back(current[i]);
			}
		}
		
		result = power(a, n);
		//Insert the dot
		result.insert(result.begin() + (result.length() - (5 - pos)*n), '.');
		//Delete useless zeroes
		while (*(result.begin()) == '0') {
			result.erase(result.begin());
		}
		while (*(result.end() - 1) == '0') {
			result.erase(result.end() - 1);
		}
		//If the result is an integer, delete the dot
		if (*(result.end() - 1) == '.') {
			result.erase(result.end() - 1);
		}
		//Output
		std::cout << result << std::endl;
	}

	return 0;
}

std::string add_long_short(const std::string & lhs, const std::string & rhs) {
	std::string result, left(lhs), right(rhs);
	std::reverse(left.begin(), left.end());
	std::reverse(right.begin(), right.end());

	int carry = '0', current = '0';
	for (std::string::const_iterator iter_l = left.begin(), iter_r = right.begin(); iter_l != left.end(); iter_l++) {
		if (iter_r != right.end()) {
			current = (*iter_l + *iter_r + carry - '0' * 3) % 10 + '0';
			result.push_back(current);
			carry = (*iter_l + *iter_r + carry - '0' * 3) / 10 + '0';
			iter_r++;
		}
		else {
			current = (*iter_l + carry - '0' * 2) % 10 + '0';
			result.push_back(current);
			carry = (*iter_l + carry - '0' * 2) / 10 + '0';
		}
	}
	if (carry != '0') {
		result.push_back(carry);
	}
	std::reverse(result.begin(), result.end());

	return result;
}

std::string add(const std::string & lhs, const std::string & rhs) {
	std::string result;

	int carry = 0, current = 0;
	if (lhs.size() >= rhs.size()) {
		result = add_long_short(lhs, rhs);
	}
	else {
		result = add_long_short(rhs, lhs);
	}

	return result;
}

std::string multiple_long_single(const std::string & lhs, const char & rhs) {
	std::string result, left(lhs);
	std::reverse(left.begin(), left.end());

	int length = lhs.length();
	int carry = '0', current = '0';
	int single = rhs - '0';
	for (int i = 0; i < length; i++) {
		current = ((left[i] - '0')*single + (carry - '0')) % 10 + '0';
		carry = ((left[i] - '0')*single + (carry - '0')) / 10 + '0';
		result.push_back(current);
	}
	if (carry != '0') {
		result.push_back(carry);
	}
	std::reverse(result.begin(), result.end());

	return result;
}

std::string multiple(const std::string & lhs, const std::string & rhs) {
	std::string result, temp, right(rhs);
	reverse(right.begin(), right.end());

	int length = rhs.length();
	for (int i = 0; i < length; i++) {
		temp = multiple_long_single(lhs, rhs[i]);
		for (int j = 0; j < length - i - 1; j++) {
			temp.push_back('0');
		}
		result = add(result, temp);
	}

	return result;
}

std::string power(const std::string & base, const int n) {
	std::string result = "1";
	for (int i = 0; i < n; i++) {
		result = multiple(result, base);
	}

	return result;
}
