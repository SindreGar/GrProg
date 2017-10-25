#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	int int1;
	float float1;
	char char1, char2;

	cout << "Skriv inn eit heiltal: ";
	cin >> int1;
	cout << "Skriv inn eit flyttal: ";
	cin >> float1;
	cout << "Skriv inn eit tekn: "; 
	cin >> char1; 
	cout << "Skriv inn enda eit tekn: "; 
	cin >> char2;

	cout << '\n' << char2 << setw(8) << char1 << setw(8) << float1 << setw(8) << int1 << endl;
	return 0;
}