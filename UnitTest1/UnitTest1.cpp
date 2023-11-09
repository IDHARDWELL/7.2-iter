#include "pch.h"
#include "CppUnitTest.h"
#include "../FileName.cpp" // Вкажіть правильний шлях до вашого файлу з функцією Max

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMax)
		{
			const int n = 3;
			int** a = new int* [n];

			for (int i = 0; i < n; i++) {
				a[i] = new int[n];
			}
			a[0][0] = 10;
			a[0][1] = 5;
			a[0][2] = 8;
			a[1][0] = 2;
			a[1][1] = 15;
			a[1][2] = 7;
			a[2][0] = 12;
			a[2][1] = 9;
			a[2][2] = 6;
			int expectedMax = 8;
			int actualMax = Max(a, n);
			Assert::AreEqual(expectedMax, actualMax);
			for (int i = 0; i < n; i++) {
				delete[] a[i];
			}
			delete[] a;
		}
	};
}
