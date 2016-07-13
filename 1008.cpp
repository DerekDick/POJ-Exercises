#include <iostream>
#include <string>
#include <map>

int main(int argc, char* argv[]) {
	int n = 0;
	std::map<std::string, int> Haab;
	Haab["pop"] = 1;
	Haab["no"] = 2;
	Haab["zip"] = 3;
	Haab["zotz"] = 4;
	Haab["tzec"] = 5;
	Haab["xul"] = 6;
	Haab["yoxkin"] = 7;
	Haab["mol"] = 8;
	Haab["chen"] = 9;
	Haab["yax"] = 10;
	Haab["zac"] = 11;
	Haab["ceh"] = 12;
	Haab["mac"] = 13;
	Haab["kankin"] = 14;
	Haab["muan"] = 15;
	Haab["pax"] = 16;
	Haab["koyab"] = 17;
	Haab["cumhu"] = 18;
	std::map<int, std::string> Tzolkin;
	Tzolkin[1] = "imix";
	Tzolkin[2] = "ik";
	Tzolkin[3] = "akbal";
	Tzolkin[4] = "kan";
	Tzolkin[5] = "chicchan";
	Tzolkin[6] = "cimi";
	Tzolkin[7] = "manik";
	Tzolkin[8] = "lamat";
	Tzolkin[9] = "muluk";
	Tzolkin[10] = "ok";
	Tzolkin[11] = "chuen";
	Tzolkin[12] = "eb";
	Tzolkin[13] = "ben";
	Tzolkin[14] = "ix";
	Tzolkin[15] = "mem";
	Tzolkin[16] = "cib";
	Tzolkin[17] = "caban";
	Tzolkin[18] = "eznab";
	Tzolkin[19] = "canac";
	Tzolkin[0] = "ahau";


	//Input and output
	std::cin >> n;
	std::cout << n << std::endl;
	std::string month;
	int day = 0, year = 0;
	while (std::cin >> day) {
		std::cin.ignore(); //Ignore the dot
		std::cin >> month >> year;

		//Calculate the number of the total days from the beginning of the world
		int totalDays = 0;
		if (month == "uayet") {
			totalDays = 365 * year + 360 + day + 1;
		}
		else {
			totalDays = 365 * year + (Haab[month] - 1) * 20 + day + 1;
		}

		//Convert Haab calendar to Tzolkin calendar
		int yearConverted = (totalDays - 1) / 260;
		int dayConverted = totalDays % 13;
		if (dayConverted == 0) {
			dayConverted = 13;
		}
		std::string monthConverted = Tzolkin[totalDays % 20];

		//Output
		std::cout << dayConverted << ' ' << monthConverted << ' ' << yearConverted << std::endl;
	}

	return 0;
}
