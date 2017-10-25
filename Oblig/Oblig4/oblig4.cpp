//  Fil:  FRODEH \ CPP \ OBIGER \ OBLIG_4.TPL
//
//  Skjellettet/template for obligatorisk oppgave nr.4 i  C++ -programmering.
//  Omhandler/"dekker" kap.2-6 i læreboka.


                             //  INCLUDE:
#include <iostream>          //  cout, cin
#include <cctype>            //  toupper

using namespace std;

                             //  KLASSE:
class Tid {                  //  Klasse inneholdende data om:
  private:
    int dag, maaned, aar;     //    - en gitt dato  og
    int time, minutt, sekund; //    - et gitt tidspunkt (klokkeslett).

    bool  skuddaar(int aa);                    //  Hentet/kopiert RETT
    int   dagnummer(int da, int ma, int aa);   //     fra OPPG_20.

  public:
    Tid();                    //  2x constructorer:
    Tid(int tt, int mm, int ss);
    void skrivDato();         //  På formen:  dd/mm-aaaa
    void skrivTidspunkt();    //  På formen:  tt:mm:ss
    void skrivTid();          //  På formen:  dd/mm-aaaa   tt:mm:ss
    void lesDato();           //  Leser inn ny dato.
    void lesTidspunkt();      //  Leser inn nytt tidspunkt.
    void lesTid();            //  Leser inn ny dato og nytt tidspunkt.
    bool likDato(const Tid t);             // Er datoene like eller ei.
    Tid  tidspunktForskjell(const Tid tt); // Tiden mellom to tidspkt samme dag
    int  datoForskjell(const Tid tt);  //  Antall dager mellom to datoer.
};

                             //  DEKLARASJON AV FUNKSJONER:
void skrivMeny();
char lesKommando();
int  les(const int min, const int max);



//  ********************  H O V E D P R O G R A M M E T:  *******************
int main()  {
  Tid tid1, tid2, tid3;  //  Tre tid-objekter.

  char valg;             //  Brukerens valg/ønske/kommando.
  int nr;                //  Hvilken av tid1 og tid2 det skal endres på.

  skrivMeny();           //  Skriver/viser bruker-menyen.
  valg = lesKommando();  //  Leser brukerens valg/ønske/kommando.

  while (valg != 'Q'  &&  valg != 'A')  {  //  Så lenge ikke avslutte:
    switch (valg)  {
      case 'S':    /*  Lag innmaten   */   break;
  
      case 'D':    /*  Lag innmaten   */   break;

      case 'P':    /*  Lag innmaten   */   break;

      case 'T':    /*  Lag innmaten   */   break;

      case 'X':    /*  Lag innmaten   */   break;

      case 'Y':    /*  Lag innmaten   */   break;

      default:   skrivMeny();   break;
    }
    valg = lesKommando(); //  Leser igjen brukerens valg/ønske/kommando.
  }
  cout << "\n\n";
  return 0;
}


//  *******************  DEFINISJON AV KLASSE-FUNKSJONER:  ********************
                                   
                                   //  IDENTISK TIL OPPG_20:
bool Tid :: skuddaar(int aa)  {    //  Sjekker om et visst år er skuddår:
                                   //  Skuddår dersom: (delelig med 400) ELLER
                                   //    (delelig med 4 OG ikke med 100)
  return ((aa % 400 == 0)  || ((aa % 4 == 0) && (aa % 100) != 0));
}
                                   //  IDENTISK TIL OPPG_20:
                     //  Ut fra datoens input, så returneres (om mulig)
                     //    denne datoens dagnummer i året, ellers returneres 0.
int Tid :: dagnummer(int da, int ma, int aa)  {
                                   //  Setter opp antall dager i månedene.
                                   //   Verdien for februar settes senere.
  int dagerPrMaaned[12] = { 31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
  int totalDagnr, i;

  if (aa < 1600  ||  aa > 2100) return 0;    //  Ulovlig år.
  if (ma < 1     ||  ma > 12)   return 0;    //  Ulovlig måned.
                                   //  Ut fra om året er skuddår eller ei,
                                   //    så settes verdien for februar:
  dagerPrMaaned[1] = (skuddaar(aa))  ?  29 : 28;
  if (da < 1 ||  da > dagerPrMaaned[ma-1])  return 0;  // Ulovlig dag:
                                   //  Garantert at er en lovlig dato !!
  totalDagnr = da;
  for (i = 0;  i < ma-1;  i++)             // Regner ut datoens dagnummer.
     totalDagnr += dagerPrMaaned[i];

  return totalDagnr;                       // Returnerer dagnummeret.
}


Tid :: Tid()                       //  2x constructorer, som setter verdier:
  {dag = 1; maaned = 1; aar = 2000; time = 0; minutt = 0; sekund = 0;   }

Tid :: Tid(int tt, int mm, int ss)
  {   dag = 1; maaned = 1; aar = 2000; time = tt, minutt = mm, sekund = ss;   }

void Tid :: skrivDato()            //  På formen:  dd/mm-aaaa
  {cout << dag << "/" << maaned << "-" << aar;}

void Tid :: skrivTidspunkt()       //  På formen:  tt:mm:ss
  {
    if(time < 10){
    cout << "0";
    }
    cout << time << ":";
    if(minutt < 10){
      cout << "0";
    }
    cout << minutt << ":";
    if(sekund < 10){
      cout <<"0";
    }
    cout << sekund;

}

void Tid :: skrivTid()             //  På formen:  dd/mm-aaaa   tt:mm:ss
  {
    skrivDato();
    cout << "   ";
    skrivTidspunkt();
  }

void Tid :: lesDato()              //  Leser inn ny dato:
  {
    skrivDato();
    cout << "Skriv inn årstall: "; aar = les(1600, 2100);
    cout << "Skriv inn måned: "; maaned = les(1, 12);
    cout << "Skriv inn dag: "; dag = les(1, 31);
    while(dagnummer(dag, maaned, aar) == 0){
      cout << "Ugyldig dag, skriv inn på nytt: "; dag = les(1, 31);
    }
  }

void Tid :: lesTidspunkt()         //  Leser inn nytt tidspunkt:
  {
    skrivTidspunkt();
    cout << "Skriv inn time: "; time = les(0, 23);
    cout << "Skriv inn minutt: "; minutt =  les(0, 59);
    cout << "Skriv inn sekund: "; sekund = les(0, 59);
  }

void Tid :: lesTid()               //  Leser inn ny dato og nytt tidspunkt:
  {
    skrivTid();
    lesDato();
    lesTidspunkt();
  }

bool Tid :: likDato(const Tid t)   //  Er to datoer like eller ei:
  {   /*  Lag innmaten  */   }

Tid Tid :: tidspunktForskjell(const Tid tt)  // Forskjellen mellom to tidspkt:
{   /*  Lag innmaten  */   }
                                   
int Tid :: datoForskjell(const Tid tt)      //  Antall dager mellom to datoer:
  {   /*  Lag innmaten  */   }



//  ***********************  DEFINISJON AV FUNKSJONER:  ***********************

void skrivMeny()  {          //  Skriver brukerens valg/muligheter/meny:
  cout << "\n\nFølgende kommandoer er aktuelle:\n";
  cout << "\tS   - Skriv begge tidene\n";
  cout << "\tD   - Dato-innlesning\n";
  cout << "\tP   - Tidspunkt-innlesning\n";
  cout << "\tT   - Tid-innlesning (= Dato + Tidspunkt)\n";
  cout << "\tX   - Tidspunkt-forskjell (når samme dato)\n";
  cout << "\tY   - Dato-forskjell\n";
  cout << "\tQ/A - Quit / Avslutt\n";
}


char lesKommando()  {        //  Leser brukerens valg/ønske/kommando:
  char ch;                   //  Innskrevet tegn.
  cout << "\n\nGi kommando (S, D, P, T, X, Y, Q/A):  ";  //  Ber om ett tegn.
  cin >> ch;    ch = toupper(ch);        //  Leser og upcaser tegn.
  return ch;                 //  Returnerer tegn/kommando.
}

                             //  Leser inn og returnerer verdi i [MIN, MAX]:
int les(const int min, const int max)  {
  int tall;                  //  Innskrevet tallverdi.
  cin >> tall;               //  Leser tall.
  while (tall < min  ||  tall > max)  {    //  Utenfor gyldig intervall:
     cout << "\ti intervallet (" << min << '-' << max << "):  ";
     cin >> tall;
  }
  return tall;               //  Returnerer akseptert (gyldig) tall
}