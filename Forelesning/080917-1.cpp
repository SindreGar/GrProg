#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
	{
		char dir='a';
		int x=10, y=10;

		while(dir != '$')
		{
			cout << "\nTo exting program, input $";
			cout << "\nYour location is: " << x << ", " << y;

			if( x<5 || x>15)
				cout << "\nBeware: Dragons lurk here";

			cout << "\nEnter direction (n, s, e, w): ";
			

			cin >> dir;

			switch(dir)
			{
				case 'n': y--; break; 
				case 's': y++; break;
				case 'e': x++; break;
				case 'w': x--; break;
				case '$': cout << "Exiting\n"; break;
				default: cout << "Try again\n"; break;
			}

			if(x==7 && y==11)
			{
				cout << "\nYou found the treasure!\n";
				exit(0);
			}
		}
		return 0; 
}