#pragma once
#include <array>
#include <string>


class Row {
public:
	Row(int offset);
	bool& operator[](int index);
	bool operator[](int index) const;
	bool GetIndexed(int index);
	void Print(char end_char = '\n');
	std::string ToString();
private:
	int _offset;
	std::array<bool, 16> _word{};
};