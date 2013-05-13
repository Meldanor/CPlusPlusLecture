#include "Functions.h"
#include <iostream>
#include <fstream>
#include <sstream>

std::string readFileToString(const std::string& filename) {
	std::ifstream ifs(filename.c_str(), std::ifstream::in);
	std::string line;
	std::stringstream stringBuffer;
	if (ifs && ifs.is_open()) {
		while (ifs.good()) {
			getline(ifs, line);
			stringBuffer << line;
		}
		ifs.close();
	}
	return stringBuffer.str();
}

Table itemArrayFromCSV(const std::string& csv) {

	int start = 0;
	unsigned int row = 0;
	bool isQuotationmark = false;
	Table t;
	for (unsigned int i = 0; i < csv.size(); ++i) {
		char c = csv.at(i);
		if (c == '"') {
			isQuotationmark = !isQuotationmark;
		}
		if (!isQuotationmark && c == ';') {
			std::string tmp(csv, start, (i - start));
			if (t.size() <= row) {
				std::vector<std::string> tmp2;
				t.push_back(tmp2);
			}

			t.at(row).push_back(tmp);
			start = i + 1;
		}
		if (c == '\n') {
			++row;
		}
	}
	std::string tmp(csv, start, (csv.length() - start));
	t.at(row).push_back(tmp);
	return t;

//	regex_t regex;
//	int regRes = regcomp(&regex, ";", 0);
//	if (regRes != 0) {
//		perror("Error while compiling regex!");
//	}
//	size_t nmatch = csv.length();
//	regmatch_t *pmatch = (regmatch_t*) (malloc(
//			sizeof(regmatch_t) * csv.length()));
//	// Execute the regex
//	regRes = regexec(&regex, csv.c_str(), nmatch, pmatch, 0);
////	printf("With the whole expression, "
////			"a matched substring \"%.*s\" is found at position %d to %d.\n",
////			pmatch[0].rm_eo - pmatch[0].rm_so, &csv.c_str()[pmatch[0].rm_so],
////			pmatch[0].rm_so, pmatch[0].rm_eo - 1);
//
//	std::string test;
//	test = extractString(&pmatch[0], NULL, csv.c_str());
//	std::cout << test << std::endl;
//	test = extractString(&pmatch[1], &pmatch[0], csv.c_str());
//	std::cout << test << std::endl;
//
//	printf("With the whole expression, "
//			"a matched substring \"%.*s\" is found at position %d to %d.\n",
//			pmatch[1].rm_eo - pmatch[1].rm_so, &csv.c_str()[pmatch[1].rm_so],
//			pmatch[1].rm_so, pmatch[1].rm_eo - 1);
//
//	regfree(&regex);
}

//std::string extractString(regmatch_t* cur, regmatch_t* prev,
//		const char* string) {
//	if (prev == NULL) {
//		std::string matchedString(string, 0, cur->rm_so);
//		return matchedString;
//	} else {
//		std::string matchedString(string, prev->rm_so, cur->rm_so - prev->rm_eo);
//		return matchedString;
//	}
//
//}

void printTable(const Table& table) {
	for (unsigned int i = 0; i < table.size(); ++i) {
		for (unsigned int j = 0; j < table.at(i).size(); ++j) {
			std::cout << table.at(i).at(j) << '\t';
		}
		std::cout << std::endl;
	}
}
