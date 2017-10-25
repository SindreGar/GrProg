#include <iostream>
#include <iomanip>

using namespace std; 

int main(){
	int numb, cube;

	for (numb = 1; numb <= 10; numb++){
		cout << setw(4) << numb;
		cube = numb*numb*numb;
		cout << setw(6) << cube << '\n';
	}
	return 0;
}