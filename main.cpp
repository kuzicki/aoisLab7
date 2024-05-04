#include <iostream>
#include "Matrix.h"

int main() {
	Matrix m;
	for (int i = 0; i < 16; i++) {
		m[i].SetWord("1101011001101101");
	}

	m[0].SetWord("1000001111000000");
	m[3].SetWord("1000001001110000");
	std::cout << m.ToString() << std::endl;
	int result = m.FindLess("1000111011101100");
	int expected = 3;
	std::cout << result << std::endl;
}