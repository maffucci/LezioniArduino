/* Prof. Michele Maffucci
   16.03.2014
 
   Uso di un led RGB a catodo comune
   Spegnimento graduale del LED Verde
 
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
  digitalWrite(VERDE, LOW);
  digitalWrite(BLU, LOW);
  digitalWrite(ROSSO, LOW);
}

// definizione di variabili globali
int ValVerde;

void loop() {
  // spegnimento graduale del verde

  // coordinate RGB del verde: 0, 255, 0

  ValVerde = 0;

  for( int i = 255 ; i > 0 ; i -= 1 ){

    ValVerde += 1;

    /* ad ogni ciclio la differenza
     255 - ValVerde AUMENTA
     provocando un graduale spegnimento del verde
     */

    analogWrite( VERDE, 255 - ValVerde );

    // attesa di 20 ms per percepire il colore
    delay( delayTime );
  }
}


