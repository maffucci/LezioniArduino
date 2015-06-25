/* Prof. Michele Maffucci
   16.03.2014
 
   Uso di un led RGB ad anodo comune
   Spegnimento graduale in sequenza
   dei LED: verde, rosso, blu
 
   Questo codice è di dominio pubblico 
*/

// pin a cui collegare i piedini del LED RGB
const int VERDE = 9;
const int BLU = 10;
const int ROSSO = 11;

// tempo di transizione colore
const int delayTime = 20;

void setup() {

  // imposta il pin digitale come output
  pinMode(VERDE, OUTPUT);
  pinMode(BLU, OUTPUT);
  pinMode(ROSSO, OUTPUT);


  // si impostano ad HIGH i pin VERDE, BLU, ROSSO
  // inizialmente il led RGB sarà spento
  digitalWrite(VERDE, HIGH);
  digitalWrite(BLU, HIGH);
  digitalWrite(ROSSO, HIGH);
}

// definizione di variabili globali
int ValVerde;
int ValRosso;
int ValBlu;

void loop() {
  // spegnimento graduale del verde

  // coordinate RGB del verde: 0, 255, 0

  ValVerde = 255;

  for( int i = 0 ; i < 255 ; i += 1 ){

    ValVerde -= 1;

    /* ad ogni ciclio la differenza
     255 - ValVerde AUMENTA
     provocando un graduale spegnimento del verde
     */

    analogWrite( VERDE, 255 - ValVerde );

    // attesa di 20 ms per percepire il colore
    delay( delayTime );
  }
  
  // spegnimento graduale del rosso

  // coordinate RGB del rosso: 255, 0, 0

  ValRosso = 255;

  for( int i = 0 ; i < 255 ; i += 1 ){

    ValRosso -= 1;

    /* ad ogni ciclio la differenza
     255 - ValRosso AUMENTA
     provocando un graduale spegnimento del rosso
     */

    analogWrite( ROSSO, 255 - ValRosso );

    // attesa di 20 ms per percepire il colore
    delay( delayTime );
  }
  // spegnimento graduale del blu

  // coordinate RGB del rosso: 0, 0, 255

  ValBlu = 255;

  for( int i = 0 ; i < 255 ; i += 1 ){

    ValBlu -= 1;

    /* ad ogni ciclio la differenza
     255 - ValBlu AUMENTA
     provocando un graduale spegnimento del rosso
     */

    analogWrite( BLU, 255 - ValBlu );

    // attesa di 20 ms per percepire il colore
    delay( delayTime );
  } 
}


