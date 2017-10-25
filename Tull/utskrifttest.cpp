#include <iostream>
using namespace std;

int main(){
	int tt = 1;
	int mm = 1;
	int ss = 56;

	if(tt < 10){
		cout << "0";
	}

	cout << tt << ":";

	if(mm < 10){
		cout << "0";
	}

	cout << mm << ":";
	cout << ss;

	return 0;


}