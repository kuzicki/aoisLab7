#include "Row.h"
#include <iostream>

Row::Row(int offset) : _offset(offset) { }

bool& Row::operator[](int index) {
	return _word[(index + _offset) % 16];
}

bool Row::operator[](int index) const {
	return _word[(index + _offset) % 16];
}

bool Row::GetIndexed(int index) {
	return _word[index];
}

void Row::Print(char end_char) {
	for (int i = 0; i < 16; i++) {
		std::cout << _word[i] << end_char;
	}
	std::cout << '\n';
}

std::string Row::ToString() {
	std::string result(16, '0');
	for (int i = 0; i < 16; i++) {
		if (_word[i] == true) {
			result[i] = '1';
		}
	}
	return result;
}