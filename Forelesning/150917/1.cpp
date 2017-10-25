#include <iostream>
using namespace std;

struct Part{
	int modelnumber; 
	int partnumber; 
	float cost; 
}; 

int main(){
	Part part1; 

	part1.modelnumber = 6244;
	part1.partnumber = 373;
	part1.cost = 217.55F;

	cout << "Model " << part1.modelnumber; 
	cout <<", part " << part1.partnumber; 
	cout <<", cost $" << part1.cost << endl;

	return 0;
}