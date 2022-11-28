#pragma once
#include "Header.h"

using namespace std;

namespace parentheses {	//	Не знаю можно лм так делать, но я так сделал
	short const count = 3;
	char in[count] = { '(', '[', '{' };
	char out[count] = { ')', ']', '}' };
}

int main() {
	string str = "{x(2-3)*[12-(3+5)^2]*y*x}/2";
	Stack<char> Arr(str.size());
	vector<char> opening;
	vector<char> closing;
	bool is_correct = 1;

	for (int i = 0; i < str.size(); i++) {
		for (int j = 0; j < parentheses::count; j++)
			if (str[i] == parentheses::in[j])
				Arr.Add(str[i]);
			else if (str[i] == parentheses::out[j] && parentheses::in[j] == Arr.Get())
				Arr.Extract();
			else if (str[i] == parentheses::out[j]) {
				is_correct = 0;
				break;
			}
		if (is_correct == 0) break;
	}

	switch (is_correct) {
	case 0:
		cout << "Uncorrect";
		break;
	case 1:
		cout << "Correct";
		break;
	default:
		break;
	}

	return 0;
}