#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	float number, answer;

	cout << "Enter a number: ";
	cin >> number;
	answer = sqrt(number);
	cout << "Square root is " << answer << endl;
	return 0;
}