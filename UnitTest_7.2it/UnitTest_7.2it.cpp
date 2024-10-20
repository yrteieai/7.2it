#include "pch.h"
#include "CppUnitTest.h"
#include "../7.2_it/7.2_it.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest72it
{
	TEST_CLASS(UnitTest72it)
	{
	public:

		TEST_METHOD(TestSwapMinMaxInRow)
		{
		
			const int k = 3;  
			const int n = 5; 

			int** matrix = new int* [k];
			for (int i = 0; i < k; i++)
				matrix[i] = new int[n];

			int testMatrix[k][n] = {
				{ 10, -5, 30, 60, 15 },
				{ 25, 40, -10, 5, 90 },
				{ 70, 85, -20, 15, 45 }
			};

			for (int i = 0; i < k; i++)
				for (int j = 0; j < n; j++)
					matrix[i][j] = testMatrix[i][j];

			SwapMinMaxInRow(matrix, k, n);

			int expectedMatrix[k][n] = {
				{ 10, 60, 30, -5, 15 },
				{ 25, 40, 90, 5, -10 },
				{ 70, -20, 85, 15, 45 }
			};

			for (int i = 0; i < k; i++) {
				for (int j = 0; j < n; j++) {
					Assert::AreEqual(expectedMatrix[i][j], matrix[i][j], L"SwapMinMaxInRow failed");
				}
			}

			for (int i = 0; i < k; i++)
				delete[] matrix[i];
			delete[] matrix;
		}
	};
}
