#include <algorithm>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <vector>

void Day02(const std::string& input) {
}

int32_t main() {
	std::ifstream inputFile("Day02.dat");
	std::string input;
    while (!inputFile.eof()) {
		input += inputFile.get();
	}  

	Day02(input);

	return 0;
}
