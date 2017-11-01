#include <iostream>
using namespace std;

int main(){
	const int MAX = 80;
	char str[MAX];
	cout << "Enter a string: ";
	cin.getline(str, MAX);
	// >> blar seg forbi blanke tabulatorer og linjeskift!
	//Bruk derfor cin.getline
	cout << "You entered: " << str << endl;
	return 0;
}