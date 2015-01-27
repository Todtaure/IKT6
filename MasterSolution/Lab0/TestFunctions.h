#include <cstdlib>
#include <math.h>
#include <iostream>
#include <time.h>

static class CalcPi
{
public:
	CalcPi(int N)
	{
		std::cout << "Calculate PI with N = " << N << std::endl;
		std::cout << calculatePi(N);
	}

private:
	float calculatePi(int N)
	{
		srand(time(NULL));
		int successCount = 0;
		float x, y, result, ratio;

		for (int i = 1; i < N; i++)
		{
			x = getRandom();
			y = getRandom();

			result = sqrt((x*x + y*y));

			if (result < 1.0)
			{
				successCount++;
			}
		}

		ratio = (float)successCount / N;

		return ratio * 4;
	}

	float getRandom()
	{		
		return (roundf(((float)rand() / RAND_MAX) * 1000) / 1000.0);
	}
};