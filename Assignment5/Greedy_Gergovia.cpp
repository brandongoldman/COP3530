#include <iostream>

using namespace std;

const int MAX_NUM = 100001;

int main() 
{
	// number of inhabitants [2,100000]
	int inhabitants;
	int houseAddress;
	bool isWineSalesman = true;
	long long numOfWorkers, totalHouses;
	int houses[MAX_NUM];

	while (isWineSalesman)
	{
		cin >> inhabitants;

		if ((inhabitants < 2 && inhabitants != 0) || inhabitants > 100000)
		{
			isWineSalesman = false;
			cout << "Error out of bounds" << endl;
		}

		if (inhabitants == 0)
		{
			return 0;
		}

		// initialize values
		totalHouses = numOfWorkers = 0;

		// greedy approach will make this more space efficient
		for(int i = 0; i < inhabitants; i++)
		{
			cin >> houseAddress;
			houses[i] = houseAddress;
			numOfWorkers = numOfWorkers + abs(totalHouses); 	// abs to convert pos num
			totalHouses = totalHouses + houses[i];
		}

		if (isWineSalesman || !isWineSalesman)
		{
			cout << numOfWorkers << endl;
		}
	}

	return 0;
}
