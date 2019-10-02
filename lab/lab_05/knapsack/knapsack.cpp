#include <iostream>
#include <algorithm>

// Pljačkaš provaljuje u kuću i pronalazi različite vrijedne predmete: nakit,
// novčanik, TV i umjetničku sliku, ali sa sobom ima torbu
// ograničenog kapaciteta. Svaki od predmeta koje je pronašao ima određenu
// vrijednost i masu, te pljačkaš mora brzo odlučiti koje predmete uzeti tako
// da dobije najveću ukupnuvrijednost. U slučaju da je imao torbu neograničeno
// velikog kapaciteta, mogao bi uzeti sve predmete i pobjeći. Međutim, kako sa
// sobom ima torbu kapacitetaukupno 16kg, mora razmisliti o predmetima koje će
// uzeti.

int knapsack(int limit, int * weights, int * values, int n)
{
	if (limit == 0 || n == 0)
		return 0;
	if (weights[n-1] > limit)
		return knapsack(limit, values, weights, n-1);
	else 
		return std::max(
        values[n-1] + knapsack(limit - weights[n-1], weights, values, n - 1),
				knapsack(limit, weights, values, n - 1)
        );
}

int main()
{
	int weights[] =   { 2,  6, 10,  8};
	int values[] =    {30, 18, 20, 10};

  std::cout << knapsack(16, weights, values, 4) << std::endl;

  return 0;
}
