/*
 * QuestionGame.cpp
 *
 *  Created on: 09.04.2013
 *      Author: Meldanor
 */

#include <iostream>
#include <cstdarg>
using namespace std;

void printQuestion(const char* text) {
	cout << text << endl;
}

void printOptions(int n, const char* text[])  {
	for (int i = 0 ; i < n ; ++i) {
		cout << '(' << (i+1) << ')' << text[i] << "   ";
	}
	cout << endl;
}

int getOption() {
	int a;
	cin >> a;
	return a;
}

int main(int argc, const char* args[]) {

	printQuestion("Sie gehen in einen Wald. Wo moechten Sie hin gehen?");
	const char* options[] =  {"Norden", "Osten", "Sueden", "Westen"};
	printOptions(4, options);
	int choose = getOption();
	cout << options[choose-1];

	return 0;
}





