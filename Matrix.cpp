#include "Matrix.h"
#include <iostream>

std::string Matrix::ToString() {
	std::string result;
	for (int i = 0; i < 16; i++) {
		for (int j = 0; j < 16; j++) {
			result += _matrix[j].GetIndexed(i) ? "1 " : "0 ";
		}
		result += "\n";
	}
	return result;
}

void Matrix::Conjunction(int firstIndex, int secondIndex, int resultIndex) {
	for (int i = 0; i < 16; i++) {
		_matrix[resultIndex][i] = _matrix[firstIndex][i] && _matrix[secondIndex][i];
	}
}

void Matrix::RepeatFirst(int firstIndex, int secondIndex, int resultIndex) {
	for (int i = 0; i < 16; i++) {
		_matrix[resultIndex][i] = _matrix[firstIndex][i];
	}
}

void Matrix::NegateFirst(int firstIndex, int secondIndex, int resultIndex) {
	for (int i = 0; i < 16; i++) {
		_matrix[resultIndex][i] = !_matrix[firstIndex][i];
	}
}

void Matrix::Sheffer(int firstIndex, int secondIndex, int resultIndex) {
	for (int i = 0; i < 16; i++) {
		_matrix[resultIndex][i] = !(_matrix[firstIndex][i] && _matrix[secondIndex][i]);
	}
}

void Matrix::AddAB(std::string_view condition) {
	int condSize = condition.size();
	if (condSize != 3)
		throw std::exception("The condition is not of size 3!");

	for (int i = 0; i < _matrix.size(); i++) {
		bool isValid = true;
		for (int j = 0; j < condSize; j++) {
			bool condValue = condition[j] == '1' ? true : false;
			if (condValue != _matrix[i][j]) {
				isValid = false;
				break;
			}
		}
		if (isValid) {
			_applyAddAB(i);
		}
	}
}

int Matrix::FindLess(std::string_view argument) {
	if (argument.size() != 16)
		throw std::exception("The argument length have to be exactly 16!");

	std::vector<Row> found;
	for (int i = 0; i < 16; i++) {
		auto [g, l] = _calculateGL(argument, i);
		if (g == false && l == true) {
			found.push_back(_matrix[i]);
		}
	}
	if (!found.size())
		return -1;
	int max = 0;
	for (int i = 1; i < found.size(); i++) {
		std::string new_argument = _formArgument(found[max]);
		auto [g, l] = _calculateGL(argument, found[i].GetPos());
		if (g == false && l == true) {
			max = i;
		}
	}
	return found[max].GetPos();
}

std::string Matrix::_formArgument(const Row& row) {
	std::string result = "";
	for (int i = 0; i < 16; i++) {
		result += row[i] ? "1" : "0";
	}
	return result;
}

int Matrix::FindMore(std::string_view argument) {
	if (argument.size() != 16)
		throw std::exception("The argument length have to be exactly 16!");

	std::vector<Row> found;
	for (int i = 0; i < 16; i++) {
		auto [g, l] = _calculateGL(argument, i);
		if (g == true && l == false) {
			found.push_back(_matrix[i]);
		}
	}
	if (!found.size())
		return -1;
	int min = 0;
	for (int i = 1; i < found.size(); i++) {
		std::string new_argument = _formArgument(found[min]);
		auto [g, l] = _calculateGL(argument, found[i].GetPos());
		if (g == true && l == false) {
			min = i;
		}
	}
	return found[min].GetPos();
}

Row& Matrix::operator[](int index) {
	return _matrix[index];
}

std::pair<bool, bool>
Matrix::_calculateGL(std::string_view argument, int wordIndex) {
	std::array<bool, 17> g{};
	std::array<bool, 17> l{};
	for (int i = 15; i >= 0; i--) {
		bool aValue = argument[i] == '1' ? true : false;
		g[i] = g[i + 1] || (!aValue && _matrix[wordIndex][i] && !l[i + 1]);
		l[i] = l[i + 1] || (aValue && !_matrix[wordIndex][i] && !g[i + 1]);
	}
	return std::make_pair(g[0], l[0]);
}

void Matrix::_applyAddAB(int index) {
	bool carry = false;
	int result = 0;
	for (int i = 3; i >= 0; i--) {
		result = _matrix[index][i + 3] + _matrix[index][i + 7] + carry;
		_matrix[index][i + 12] = result % 2;
		carry = result / 2;
	}
	_matrix[index][11] = carry;
}