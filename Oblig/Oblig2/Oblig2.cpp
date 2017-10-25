#include <iostream>
using namespace std;

int main (){


	int dager, nedbor, totalnedbor, mintemp, mintotal, maxtemp, maxtotal; 

	// Deklarerer intane for dager i måneden, nedbørsmengde, total nedbør,
	// minimumstemperatur ein bestemt dag, samanlagt minimumstemperatur, 
	// makstemperatur ein bestemt dag og samanlagt makstemperatur, 

	float minsnitt, maxsnitt, nedborsnitt;

	// Deklarerer floatene for minimumstemperatursnitt, maksimumstemperatursnitt
	// og gjennomsnittlig nedbør

	char restart; 

	// Deklarerer char som blir brukt om brukaren vil kjøre programmet på nytt

	const int MINIMUMTEMP = -70; 
	const int MAXIMUMTEMP = 70;
	const int MAXNEDBOR = 0; 
	const int MINNEDBOR = 200;

	// Conster for maksimums- og minimumsverdiane som blir brukt 

	do{

	//do-while-loop, så loopen køyrer minst ein gong

	totalnedbor = 0.00F; 
	mintotal = 0.00F; 
	maxtotal = 0.00F; 

	// nullstiller desse variablane i tilfellet brukaren vil kjøre programmet på nytt

	cout << "Velkommen til dette programmet, skriv inn kor mange dager det er i månaden: ";
	cin >> dager; 


	if (dager < 28 || dager > 31){
		while(dager < 28 || dager > 31){
			cout << "\nDet kan berre vere mellom 28 og 31, skriv inn eit nytt tal: ";
			cin >> dager;
		}
	}

	// Sjekker fyrst med if-statement om dager har gyldig verdi, om det ikkje
	// er tilfellet så kjører while-loopen til verdien blir gyldig

	for (int i = 1; i <= dager; i++){

		//Startar ein for-loop som kjører like mange gonger som det er dager

		cout << "\nSkriv inn minimumstemperaturen for den " << i << ". dagen i månaden: ";
		cin >> mintemp; 
		if (mintemp < MINIMUMTEMP || mintemp > MAXIMUMTEMP){
			while(mintemp < -70 || mintemp > 70){
				cout << "Mintemp kan berre vere mellom -70 og 70"
				<< "\nSkriv inn eit nytt tal: ";
				cin >> mintemp;

			}
		}

		// If-statement som sjekker om mintemp har gyldig verdi, om den ikkje 
		// er det så kjører while-loopen til verdien blir gyldig

		mintotal += mintemp;

		// Legg til mintemp i mintotal

		cout << "Skriv inn makstemperaturen for den " << i << ". dagen i månaden: ";
		cin >> maxtemp; 
		if (maxtemp < mintemp || maxtemp > MAXIMUMTEMP){
			while(maxtemp < mintemp || maxtemp > 70){
				cout << "Maxtemp kan berre vere mellom " << mintemp << " og 70"
				<< "\nSkriv inn eit nytt tal: ";
				cin >> maxtemp;
			}
		}

		// If-statement som sjekker om maxtemp har gyldig verdi, om den ikkje
		// er det, så kjører while-loopen til brukaren setter inn ein gyldig
		// verdi

		maxtotal += maxtemp;

		// Legg maxtemp til i maxtotal

		cout << "Skriv inn nedbøren for den " << i << ". dagen i månaden: ";
		cin >> nedbor; 
		if (nedbor < MINNEDBOR || nedbor > MAXNEDBOR){
			while(nedbor < 0 || nedbor > 200){
				cout << "Nedbørsmengden kan berre vere mellom 0 og 200"
				<< "\n skriv inn eit nytt tal: "; 
				cin >> nedbor; 
			}
		}

		// If-statement som sjekker om nedbor har gyldig verdi. Om den ikkje
		// er det, så kjører while-loopen til brukaren setter inn ein gyldig
		// verdi

		totalnedbor += nedbor; 

		// legg til nedbor i totalnedbor

	}

	minsnitt = (float)mintotal/dager; 
	maxsnitt = (float)maxtotal/dager; 
	nedborsnitt = (float)totalnedbor/dager; 

	// Reknar ut snittet. 

	cout << "Gjennomsnittleg mintemp denne månaden er " << minsnitt 
	<< "\nGjennomsnittleg maxtemp denne månanden er " << maxsnitt
	<< "\nGjennomsnittleg nedbør denne månaden er " << nedborsnitt
	<< "\nTotal nedbør for denne månaden er " << totalnedbor<<;  

	cout << "Om du vil gjere omrekningane for ein ny månad, trykk j: ";
	cin >> restart; 

	}while(restart == 'j' || restart == "J");

	//Sjekker om input er j eller J. Om det er tilfellet, kjør do-loopen på nytt

	cout << "Ha ein fin dag videre\n"; 

	return 0;
}