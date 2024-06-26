#pragma once
#include "Row.h"
#include <array>
#include <string>
#include <vector>
#include <string_view>

class Matrix {
public:
	Matrix() { }
	void PrintAll();
	std::string ToString();

	void Conjunction(int firstIndex, int secondIndex, int resultIndex);
	void RepeatFirst(int firstIndex, int secondIndex, int resultIndex);
	void NegateFirst(int firstIndex, int secondIndex, int resultIndex);
	void Sheffer(int firstIndex, int secondIndex, int resultIndex);
	void AddAB(std::string_view condition);

	int FindLess(std::string_view argument);
	int FindMore(std::string_view argument);
	Row& operator[](int index);

private:
	std::pair<bool, bool> _calculateGL(std::string_view argument, int wordIndex);
	void _applyAddAB(int index);
	std::string _formArgument(const Row& row);

private:
	std::array<Row, 16> _matrix{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 };
};