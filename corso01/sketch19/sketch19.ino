/* Prof. Michele Maffucci
   15.03.2014
 
   Regolazione luminosità LED mediante
   trimmer
   si utilizza la funzione map
 
   Questo codice è di dominio pubblico 
*/

// variabile in cui verrà memorizzato il valore presente sul pin A0
int misura = 0;

// pin a cui è connesso il LED
int pinLed = 11;

// variabile in cui conservare il valore inserito su A0
int val = 0;

// variabile in cui memorizzare il Duty Cycle
int inputVal = 0;

void setup(){
  pinMode(pinLed, OUTPUT); // definizione di ledPin come output
}

void loop(){
  // analogRead leggerà il valore su A0 restituendo un valore tra 0 e 1023
  // per approfondimenti si consulti il link: http://wp.me/p4kwmk-1Qd
  val = analogRead(misura);

  // analogWrite() accetta come secondo parametro (PWM) valori tra 0 e 254
  // pertanto "rimappiamo" i valori letti da analogRead() nell'intervallo
  // tra 0 e 254 usando la funzione map
  // per approfondimenti si consulti il link: http://wp.me/p4kwmk-1Tu
  inputVal = map(val, 0, 1023, 0, 254);
  
  // accendiamo il LED con un valore del Duty Cycle pari a val
  analogWrite(pinLed,inputVal);
}
