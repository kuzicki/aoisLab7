#include "Row.h"
#include <iostream>
#include <algorithm>

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

void Row::Set(std::string_view word) {
	if (word.size() != 16)
		throw std::exception("invalid argument");

	for (int i = 0; i < 16; i++) {
		_word[i] = word[i] != '0';
	}
}

int Row::GetPos() {
	return _offset;
}

void Row::SetWord(std::string_view word) {
	if (word.size() != 16)
		throw std::exception("invalid argument");

	for (int i = 0; i < 16; i++) {
		_word[(i + _offset) % 16] = word[i] != '0';
	}
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