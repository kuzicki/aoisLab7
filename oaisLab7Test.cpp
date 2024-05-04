#include "pch.h"
#include "CppUnitTest.h"
#include "Matrix.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace oaisLab7Test
{
	TEST_CLASS(oaisLab7Test)
	{
	public:
		TEST_METHOD(ChangeBit) {
			Matrix m;
			m[7][3] = 1;
			std::string exp = "0000000000100000";
			Assert::AreEqual(exp, m[7].ToString());
		}

		TEST_METHOD(ChangeBits) {
			Matrix m;
			m[15][3] = 1;
			m[15][5] = 1;
			std::string exp = "0010100000000000";
			Assert::AreEqual(exp, m[15].ToString());
		}

		TEST_METHOD(AddAB)
		{
			Matrix m;
			m[0][0] = 1;
			m[0][3] = 1;
			m[0][4] = 1;
			m[0][7] = 1;
			m.AddAB("100");
			std::string exp = "1001100100010100";
			Assert::AreEqual(exp, m[0].ToString());
		}

		TEST_METHOD(AddABOffset)
		{
			Matrix m;
			m[4][0] = 1;
			m[4][3] = 1;
			m[4][4] = 1;
			m[4][7] = 1;
			m.AddAB("100");
			std::string exp = "0100100110010001";
			Assert::AreEqual(exp, m[4].ToString());
		}

		TEST_METHOD(AddABWrongArgument)
		{
			Matrix m;
			m[10][0] = 1;
			m[10][3] = 1;
			m[10][7] = 1;
			m[0][0] = 1;
			m[0][3] = 1;
			m[0][7] = 1;
			Assert::ExpectException<std::exception>([&] {m.AddAB("1000"); });
		}

		TEST_METHOD(RepeatFirst)
		{
			Matrix m;
			m[10][0] = 1;
			m[10][3] = 1;
			m[10][7] = 1;
			m[0][0] = 1;
			m[0][3] = 1;
			m[0][7] = 1;
			m.RepeatFirst(0, 10, 11);
			std::string exp = "0010000000010010";
			Assert::AreEqual(exp, m[11].ToString());
		}
		TEST_METHOD(Conjuction)
		{
			Matrix m;
			m[10][1] = 1;
			m[10][3] = 1;
			m[10][7] = 1;
			m[0][0] = 1;
			m[0][3] = 1;
			m[0][7] = 1;
			m.Conjunction(0, 10, 11);
			std::string exp = "0010000000000010";
			Assert::AreEqual(exp, m[11].ToString());
		}

		TEST_METHOD(NegateFirst)
		{
			Matrix m;
			m[10][0] = 1;
			m[10][3] = 1;
			m[10][7] = 1;
			m[0][0] = 1;
			m[0][3] = 1;
			m[0][7] = 1;
			m.NegateFirst(0, 10, 11);
			std::string exp = "1101111111101101";
			Assert::AreEqual(exp, m[11].ToString());
		}

		TEST_METHOD(Sheffer)
		{
			Matrix m;
			m[10][1] = 1;
			m[10][3] = 1;
			m[10][7] = 1;
			m[0][0] = 1;
			m[0][3] = 1;
			m[0][7] = 1;
			m.Sheffer(0, 10, 11);
			std::string exp = "1101111111111101";
			Assert::AreEqual(exp, m[11].ToString());
		}

		TEST_METHOD(FindLess)
		{
			Matrix m;
			for (int i = 0; i < 16; i++) {
				m[i].SetWord("1101011001101101");
			}
			
			m[0].SetWord("1000001111000000");
			m[3].SetWord("1000001001110000");
			int result = m.FindLess("1000111011101100");
			int expected = 3;
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(FindMore)
		{
			Matrix m;
			for (int i = 0; i < 16; i++) {
				m[i].SetWord("1101010000000000");
			}

			m[0].SetWord("1000001111001001");
			m[3].SetWord("1000001001110000");
			int result = m.FindMore("1000111010000000");
			int expected = 3;
			Assert::AreEqual(expected, result);
		}
	};
}
