//Sindre Garmo
//BITSEC
//Studentnr 757694
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
      case 'S':
        tid1.skrivTid();  //kaller skrivTid for tid1
        cout << "   ";
        tid2.skrivTid(); // kaller skrivTid for tid2
        break;
  
      case 'D':
        cout << "Vil du endre dato på tid 1 eller tid 2? "; nr = les(1,2); 
        //bruker les til å sjekke gyldig input
        if(nr == 1){
          tid1.lesDato(); // om nr=1, så kalles lesDato for tid1
        }
        if(nr == 2){
          tid2.lesDato(); // om nr=2, så kalles lesDato for tid2
        }
        break;

      case 'P':
        cout << "Vil du endre tidspunkt på tid 1 eller 2? "; nr = les(1,2);
        //bruker les til å sjekke gyldig input
        if(nr == 1){
          tid1.lesTidspunkt(); // om nr=1 så kalles lesTidspunkt for tid1
        }
        if(nr == 2){
          tid2.lesTidspunkt(); // om nr=2 så kalles lesTidspunkt for tid2
        }
        break;

      case 'T':
        cout << "Vil du endre dato og tidspunkt på tid 1 eller 2? "; nr = les(1,2);
        //bruker les til å sjekke gyldig input
        if(nr == 1){
          tid1.lesTid(); // om nr=1 så kalles lesTid for tid1
        }
        if(nr == 2){
          tid2.lesTid(); // om nr=2 så kalles lesTid for tid2
        }
        break;

      case 'X':
        if(tid1.likDato(tid2) == true){ // Bruker likDato til å sjekke om 
          //tid 1 og 2 er like, om det er tilfellet så blir resultatet av
          tid3 = tid1.tidspunktForskjell(tid2); //tidspunktForskjell lagra
          cout << "Forskjellen mellom tid 1 og tid 2 er "; //i tid3.
          tid3.skrivTidspunkt(); //Bruker så skrivTidspunkt til å sjå 
          //resultatet

        }else{
          cout << "Tid 1 og tid 2 er ikkje på same dato"; 
        }
        break;

      case 'Y':
        int antalldager; // Int for å lagre antall dager
        antalldager = tid1.datoForskjell(tid2); //forskjellen mellom tid1 og
        // tid to blir lagra i antalldager
        cout << "Det er " << antalldager << " dager imellom tid1 og tid 2";
        break;

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
  {
    dag = 1; 
    maaned = 1; 
    aar = 2000; 
    time = 0; 
    minutt = 0; 
    sekund = 0;   
  }

Tid :: Tid(int tt, int mm, int ss)
  {   
    dag = 1; 
    maaned = 1;
    aar = 2000; 
    time = tt, 
    minutt = mm, 
    sekund = ss;   
  }

void Tid :: skrivDato()            //  På formen:  dd/mm-aaaa
  {cout << dag << "/" << maaned << "-" << aar;}

void Tid :: skrivTidspunkt()       //  På formen:  tt:mm:ss
  {
    if(time < 10){ // sjekker om det er under 10 timer, om det er tilfellet
    cout << "0"; // så blir det printa ein ekstra 0 framfor 
    }
    cout << time << ":";
    if(minutt < 10){ // sjekker om det er under 10 minutt, om det er det
      cout << "0"; // så blir det printa ein ekstra 0 framfor
    }
    cout << minutt << ":";
    if(sekund < 10){ // sjekker om det er under 10 sekund, om det er det
      cout <<"0"; // så blir det printa ein ekstra 0 framfor
    }
    cout << sekund;

}

void Tid :: skrivTid()             //  På formen:  dd/mm-aaaa   tt:mm:ss
  {
    skrivDato(); // Kaller funksjonen skrivDato
    cout << "   ";
    skrivTidspunkt(); // Kaller funksjonen skrivTidspunkt
  }

void Tid :: lesDato()              //  Leser inn ny dato:
  {
    skrivDato();
    cout << "\nSkriv inn årstall: "; aar = les(1600, 2100); // bruker les
    // til å sjekke at aar blir gyldig
    cout << "Skriv inn måned: "; maaned = les(1, 12); // bruker les til å
    // sjekke at maaned blir gyldig
    cout << "Skriv inn dag: "; dag = les(1, 31); // bruker les til å sjekke
    // at dag blir gyldig
    while(dagnummer(dag, maaned, aar) == 0){ // sjekker om dagnummer returnerer
      // 0, gjer den det blir brukaren bedt om å skrive inn ny dag
      cout << "Ugyldig dag, skriv inn på nytt: "; dag = les(1, 31);
    }
  }

void Tid :: lesTidspunkt()         //  Leser inn nytt tidspunkt:
  {
    skrivTidspunkt();
    cout << "\nSkriv inn time: "; time = les(0, 23); // bruker les til å sjekke
    // om time er gyldig
    cout << "Skriv inn minutt: "; minutt =  les(0, 59); //bruker les til å
    //sjekke om minutt er gyldig
    cout << "Skriv inn sekund: "; sekund = les(0, 59); // bruker les til å
    //sjekke om sekund er gyldig
  }

void Tid :: lesTid()               //  Leser inn ny dato og nytt tidspunkt:
  {
    skrivTid();
    lesDato();
    lesTidspunkt();
  }

bool Tid :: likDato(const Tid t)   //  Er to datoer like eller ei:
//sjekker om aar, maaned og dag er like. Returnerer true om alle er like
//false om de ikke er det. 
  {
    if(t.aar != aar){
      return false;
    }
    if(t.maaned != maaned){
      return false;
    }
    if(t.dag != dag){
      return false;
    }
    else{
      return true;
    }
  }

Tid Tid :: tidspunktForskjell(const Tid tt)  // Forskjellen mellom to tidspkt:
  {
   int sekund1, sekund2, nysek, nyminutt, nytime, tempsek; //variabler som blir
   //brukt til å holde styr på sekunder

   sekund1 = tt.time * 3600 + tt.minutt * 60 + tt.sekund;
   //antall sekunder i tt
   sekund2 = time * 3600 + minutt * 60 + sekund;
   //antall sekunder i tiden der funksjonen kalles

   if(sekund2 > sekund1){ //gjer att sekund1 og sekund2 bytter plass om
    tempsek = sekund1; //sekund2 er større enn sekund1
    sekund1 = sekund2;
    sekund2 = tempsek;
   }

   nysek = sekund1 - sekund2; //regner ut differansen i sekund
   tempsek = (nysek - nysek%3600); //finner ut kor mange heile timer det er
   nytime = tempsek/3600; //gjer sekunda om til timer
   tempsek = (nysek - tempsek); //finn ut kor mange resterande sekund det er
   tempsek = (tempsek - tempsek%60); // finn ut kor mange minutt det er
   nyminutt = tempsek/60; // Gjer sekunda om til minutt
   nysek = nysek - nytime * 3600 - nyminutt * 60; //Finn ut dei resterande sekunda

   return Tid(nytime, nyminutt, nysek); //returnerar tidsobjekt

  }
                                   
int Tid :: datoForskjell(const Tid tt)      //  Antall dager mellom to datoer:
  {
    int dagerTid1, dagerTid2, dagerTemp, dagertotalt; //variablar for å lagre
    //dagar
    dagertotalt = 0; //set forkjsellen til 0

    dagerTid1 = dagnummer(dag, maaned, aar); //finn ut kor manger dagar det er
    // i tid
    dagerTid2 = dagnummer(tt.dag, tt.maaned, tt.aar); //finn ut kor mange dagar
    // Det er i tt

    if(aar == tt.aar){ // Om årstalla er like finn vi berre ut forskjellen
      if(dagerTid1 < dagerTid2){ // ved å ta differansen
        dagerTemp = dagerTid1; // bytter plass på dagerTid1 og dagerTid2 om
        dagerTid1 = dagerTid2; // nødvendig
        dagerTid2 = dagerTemp;
      }
      dagertotalt = dagerTid1 - dagerTid2;
      return dagertotalt; 
    }

    if(aar > tt.aar){ // om aar er større enn tt.aar gjer vi det slik
      for(int i = 0; tt.aar + i < aar; i++){ // tt.aar itirerar mot aar
        dagerTemp = dagnummer(31, 12, tt.aar +i); // og dagnummer finn ut kor
        dagertotalt = dagertotalt + dagerTemp; // mange dagar det er i kvar år
      }
      dagertotalt = dagerTid1 + dagertotalt - dagerTid2; //siste regnestykke for
      return dagertotalt; // å finne totalen, som blir returnert
    }

    if(aar < tt.aar){ //same prosessen her, berre at aar itererar mot tt.aar
      for(int i = 0; aar + i < tt.aar; i++){
        dagerTemp = dagnummer(31, 12, aar +i);
        dagertotalt = dagertotalt + dagerTemp;
      }
      dagertotalt = dagerTid2 + dagertotalt - dagerTid1;
      return dagertotalt;
    }

    

  }
    



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