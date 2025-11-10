#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

void reverse_strings(std::vector<std::string>& words) {
	for (std::string& w : words) {
		std::reverse(w.begin(), w.end());
	}
}

int main() {
	std::vector<std::string> words = { "hello", "world", "c++" };

	std::cout << "Prije: ";
	for (const auto& w : words) std::cout << w << " ";
	std::cout << "\n";

	reverse_strings(words);

	std::cout << "Nakon: ";
	for (const auto& w : words) std::cout << w << " ";
	std::cout << "\n";

	return 0;
}
