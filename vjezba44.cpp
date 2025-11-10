#include <string>
#include <cctype>

std::string word_to_pig_latin(const std::string& word) {
	if (word.empty()) return word;

	std::string vowels = "aeiouAEIOU";

	
	if (vowels.find(word[0]) != std::string::npos) {
		return word + "hay";
	}

	
	return word.substr(1) + word[0] + "ay";
}
