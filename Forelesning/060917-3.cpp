#include <iostream>
using namespace std;

const int N = 5;

int main()
{
	int i, tall, sum = 0;

	do {
		cout << "Tast et tall (0 = avslutt): "; cin >> tall;
		sum += tall;
	} while (tall != 0);

	cout << "\n\nSummen er " << sum << '\n';
	return 0;
}
