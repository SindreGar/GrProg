//Sindre Garmo 
//Bitsec
//Studentnr 757694

#include <iostream>
#include <cctype>
using namespace std;

//Opprettar structen som blir brukt for brøk

struct Brok{
	int teller, nemner;  
};

int main(){

	//Deklarerer structane som skal bli brukt, og dei to char-variablane som
	//skal halde styr på kommandoane 

	Brok brok1, brok2, brok3, temp, temp1, temp2;

	char commando1, commando2;

	//bool-variabel som gjer at ei while-løkke lengre nede i koden køyrer

	bool loop = true;

	//For-loop som tek inn tellaren og nemnaren til dei forskjellie brøkane.
	//Putter input-infoen inn i ein temp, før temp-infoen blir overført
	//til brok1 fyrste gongen den looper, brok2 andre gongen den looper 
	//og brok3 tredje gongen den looper. 

	for (int i = 1; i < 4; i++){
		cout << "Skriv inn verdiene til Brøk " << i << ": ";
		cout << "\nTeller: ";
		cin >> temp1.teller;
		cout << "Nemner: ";
		cin >> temp1.nemner;
		while(temp1.nemner < 1){
			cout << "Nemnaren må vere større enn 0";
			cout << "Nemner: ";
			cin >> temp1.nemner; 
		}

		switch(i){
			case 1:
				brok1.teller = temp1.teller;
				brok1.nemner = temp1.nemner;
				break;
			case 2:
				brok2.teller = temp1.teller;
				brok2.nemner = temp1.nemner;
				break;
			case 3:
				brok3.teller = temp1.teller;
				brok3.nemner = temp1.nemner;
				break;
		}

	}

	cout << "Operer på brøkene:";
	cout << "\nA - nr1 og nr2";
	cout << "\nB - nr1 og nr3";
	cout << "\nC - nr2 og nr3";
	cout << "\nQ - slutt/quit";

	//

	while(loop == true){
		cout << "\nYnskje (A, B, C, Q): ";
		cin >> commando1;

		//toupper gjer at input alltid blir uppercase, noko som gjer at ein 
		//treng mindre kode for å sjekke om input er gyldig

		commando1 = toupper(commando1);

		//sjekker om commando1 har ein gyldig input. Om den ikkje har det
		//så blir brukaren spurt om å skrive inn ny input. 

		while(commando1 !='A' && commando1 != 'B' 
			&& commando1 != 'C' && commando1 != 'Q'){
			cout << "\nYnskje (A, B, C, Q): ";
			cin >> commando1;
			commando1 = toupper(commando1);
		}

		//Switch som utførar operasjon utifrå kommandoen den får inn
		//om commando1 er Q, så returnerar den 0, og avsluttar programmet. 

		switch(commando1){
			case 'A':
				temp1.teller = brok1.teller;
				temp1.nemner = brok1.nemner;
				temp2.teller = brok2.teller;
				temp2.nemner = brok2.nemner;
				break;
			case 'B':
				temp1.teller = brok1.teller;
				temp1.nemner = brok1.nemner;
				temp2.teller = brok3.teller;
				temp2.nemner = brok3.nemner;
				break;
			case 'C':
				temp1.teller = brok2.teller;
				temp1.nemner = brok2.nemner;
				temp2.teller = brok3.teller;
				temp2.nemner = brok3.nemner;
				break;
			case 'Q':
				return 0;

		}

		cout << "Ynskja operajon (+,-,*,/): ";
		cin >> commando2;

		//while-loop for å sjekke at input til commando2 blir gyldig. Om den
		//ikkje er gyldig, blir brukaren spurt om ny input. 

		while(commando2 != '+' && commando2 != '-' && commando2 != '*'
			&& commando2 != '/'){
			cout << "\nYnskja operajon (+,-,*,/): ";
			cin >> commando2;
		}

		//Switch som sjekkar kva for ein operasjon som skal utførast
		//og utførar gjeldande operasjon. 

		switch(commando2){
			case '+':
				temp.teller = 
				temp1.teller * temp2.nemner + temp1.nemner * temp2.teller;
				temp.nemner = temp1.nemner * temp2.nemner;
				break;
			case '-':
				temp.teller = 
				temp1.teller * temp2.nemner - temp1.nemner * temp2.teller;
				temp.nemner = temp1.nemner * temp2.nemner;
				break;
			case '*':
				temp.teller = temp1.teller * temp2.teller;
				temp.nemner = temp1.nemner * temp2.nemner;
				break;
			case '/':
				temp.teller = temp1.teller * temp2.nemner;
				temp.nemner = temp1.nemner * temp2.teller;
				break;
		}

		//skriver ut svaret

		cout << "Svaret er: " << temp1.teller << "/" << temp1.nemner 
		     << commando2 << temp2.teller << "/" << temp2.nemner << " = " 
		     << temp.teller << "/" << temp.nemner << endl;


	}

}