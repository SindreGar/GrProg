//Array av objekter
//Strenger/tekster/char-array
//Strenger som klassemedlem

class Distance
	{
	private:
		int feet;
		float inches;
	public:
		void getdist()
		{
		cout << "\n 	Enter feet: "; cin >> feet;
		cout << "		Enter inches: "; cin >> inches;
		}
		void showdist() const{
			cout << feet << "\'-" << inches;
		}
	}

int main(){
	Distance dist[100];
	int n=0;
	char ans;

	do{
		cout << "Enter Distance number " << n+1;
		dist[n++].getdist();
		cout << "Enter another (y/n)?: ";
		cin >> ans;
	}while(ans)
}