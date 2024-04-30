#include <iostream>
#include "Matrix.h"

int main() {
	Matrix m;
	m[0][0] = 1;
	m[0][1] = 0;
	m[0][3] = 1;
	m[0][7] = 1;
	m.NegateFirst(0, 1, 3);
	m.NegateFirst(1, 1, 3);
	m.AddAB("100");
	auto result = m.FindLess("1111111111111111");
	for (int i = 0; i < result.size(); i++) {
		std::cout << i << ". ";
		result[i].Print(' ');
	}
	result = m.FindMore("1110111111111111");
	for (int i = 0; i < result.size(); i++) {
		std::cout << i << ". ";
		result[i].Print(' ');
	}
	std::cout << m.ToString();
	std::cout << "Hello world!" << std::endl;
}