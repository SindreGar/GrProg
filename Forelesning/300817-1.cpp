#include <iostream>
using namespace std;

int main()
{
	int ftemp;
	int ctemp;

	cout << "Enter temp in fahrenheit: ";
	cin >> ftemp;
	ctemp = (ftemp-32) * 5 / 9;
	cout << "Equivalent in Celcius is: " << ctemp << '\n';
	return 0;
}