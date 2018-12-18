#include "SearchFunctions.h"
#include "Result.h"
#include <iostream>
#include <vector>
#include <algorithm> 

void SearchFunctions::nearestNeighbour(BaseImage wally, BaseImage ref)
{
	// NNS Logic to be inserted here
}


void SearchFunctions::search(RefImage* wally, LargeImage* ref, const int size)
{
	std::vector<Result> results;
	std::cout << "Finding Wally" << std::endl;
	for (int k = 0; k < ref->sizeR - wally->sizeR; k++)
	{
		for (int j = 0; j < ref->sizeC - wally->sizeC; j++)
		{
			results.push_back(Result::Result(linear(wally, ref, j, k), j, k));
		}
	}
	std::cout << "Sorting results..." << std::endl;
	std::sort(results.begin(), results.end(), CompareResult);
	for (int i = 0; i < 10; i++)
	{
		std::cout << "SSD Value: " << results[i].value << " "  <<
			"X: "<< results[i].x << " Y: " << results[i].y << std::endl;
	}
}

double SearchFunctions::linear(RefImage* wally, LargeImage* ref, int j, int k)
{
	double sosd = 0.0;
	for (int x = j; x < j + wally->sizeC; x++)
	{
		for (int y = k; y < k + wally->sizeR; y++)
		{
			if (wally->getImgValue(x - j, y - k) != 255.0)
			{
				sosd += std::pow(wally->getImgValue(x - j, y - k) - ref->getImgValue(x, y), 2.0);
			}
		}
	}
	return sosd;
}

