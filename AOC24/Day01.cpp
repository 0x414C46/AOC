#include <algorithm>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <vector>

void Day01(std::string& input) {
	input.erase(std::remove(input.begin(), input.end(), ' '), input.end());
	input.erase(std::remove(input.begin(), input.end(), '\n'), input.end());	
	input.pop_back();

	std::vector<int32_t> left {};
	std::vector<int32_t> right {};

	for (int32_t i = 0; i < input.size(); i += 5) {
		std::string numStr = input.substr(i, 5);
		int32_t num = std::stoi(numStr);

		if (i == 0 || i % 10 == 0)
			left.push_back(num);
		else
			right.push_back(num);
	}

	std::stable_sort(left.begin(), left.end());
	std::stable_sort(right.begin(), right.end());

	int32_t part1 = 0;
	for (int32_t i = 0; i < std::min(left.size(), right.size()); i++)
		part1 += std::max(left[i], right[i]) - std::min(left[i], right[i]);

	int32_t part2 = 0;
	for (int32_t num : left) {
		int32_t rightCount = std::count(right.begin(), right.end(), num);
		part2 += num * rightCount;
	}

	std::cout << "Part 1: " << part1 << std::endl;
	std::cout << "Part 2: " << part2 << std::endl;
}

int32_t main() {
	std::ifstream inputFile("Day01.dat");
	std::string input;
    while (!inputFile.eof()) {
		input += inputFile.get();
	}  

	Day01(input);

	return 0;
}
