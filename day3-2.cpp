// AoC2017.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int matrix[515][515];

int main()
{
	int stepsLeft = 1;
	int stepsNorm = 1;

	int maxValue = 265149; 
	int value = 1, x = 258, y = 258;
	int xStep = 1, yStep = 0;
	bool increase = false;

	for (int i = 0; i < 515; ++i) //setting array
		for (int j = 0; j < 515; ++j)
			matrix[i][j] = 0;

	matrix[258][258] = 1;

	while (value < maxValue)
	{
		value = matrix[x-1][y-1] + matrix[x][y-1] + matrix[x+1][y-1] + matrix[x+1][y] + matrix[x-1][y] + matrix[x-1][y+1] + matrix[x][y+1] + matrix[x+1][y+1];
		if (x == 258 && y == 258)
			matrix[x][y] = 1;
		else
			matrix[x][y] = value;

		--stepsLeft;
		x += xStep;
		y += yStep;
		
		if (stepsLeft == 0)
		{
			if (xStep == 1)
			{
				xStep = 0;
				yStep = 1;
			}
			else if (yStep == 1)
			{
				xStep = -1;
				yStep = 0;
			}
			else if (xStep == -1)
			{
				xStep = 0;
				yStep = -1;
			}
			else 
			{
				xStep = 1;
				yStep = 0;
			}

			if (increase) 
			{
				increase = false;
				++stepsNorm;
			}
			else
				increase = true;

			stepsLeft = stepsNorm;
		}
	}
	cout << value << endl;

	system("Pause");


    return 0;
}

