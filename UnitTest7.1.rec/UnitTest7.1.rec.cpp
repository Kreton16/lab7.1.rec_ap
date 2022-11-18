#include "pch.h"
#include "CppUnitTest.h"
#include "../pr7.1.rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest71rec
{
	TEST_CLASS(UnitTest71rec)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int** h = new int* [5];
			for (int i = 0; i < 5; i++)
				h[i] = new int[2];
			int Low = -26;
			int High = 23;
			for (int i = 0; i < 5; i++)
				for (int j = 0; j < 2; j++)
					h[i][j] = Low + rand() % (High - Low + 1);
			int S = 0, k = 0;
			Calc(h, 2, 5, S, k, 0, 0);
			int Check = S;
			Assert::AreEqual(Check, S);
		}
	};
}
