#include <iostream>
using namespace std;

int main()
{
	float rad, area; // float-variable
	const float PI = 3.14159F; // float-variabel som er konstant, denne kan ikkje brukar endre. Konstanter SKAL skrivast i store bokstavar 

	cout << "Enter radius of circle: ";
	cin >> rad;

	area = PI * rad * rad;
	cout << "Area is " << area << endl;
	return 0;
}