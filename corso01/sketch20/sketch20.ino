/* Prof. Michele Maffucci
   15.03.2014
 
   Regolazione luminosità LED mediante
   trimmer; si utilizza la funzione map.
   Lettura valori sulla Serial Monitor
 
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
  // Serial.begin(rate) inizializzazione della seriale
  // Apre la porta seriale ed imposta la velocità di trasmissione (baud rate)
  // seriale per trasmettere i dati. La velocità di trasmissione tipica per
  // la comunicazione del computer è di 9600 bps (bps: boud rate per secondo)
  // Nota: attensione a non confondere la sigla bps con bit al secondo,
  // nel nostro caso parliamo di boud, cioè simboli e ad ogni simbolo possono
  // corrispondere più bit.
  // per maggiori informazioni si consulti il link: http://wp.me/p4kwmk-211
  Serial.begin(9600);
  
  // definizione di ledPin come output  
  pinMode(pinLed, OUTPUT); 
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
  
  // la Serial.println(data) stampa i dati sulla porta seriale
  // (invia i dati alla seriale e li visualizza) seguito da un
  // ritorno a capo automatico ed un avanzamento linea.
  
  Serial.print("Valore letto da analogRead() = ");  // stampa ciò che è incluso tra ""
  Serial.println(val);                              // stampa val
  Serial.print("Valore resitituito da map()  = ");  // stampa ciò che è incluso tra ""
  Serial.println(inputVal);                         // stampa inputVal
  Serial.println("");                               // va a capo
  delay(1000);                                      // attesa di 1 secondo per consentire la lettura
  
  // accendiamo il LED con un valore del Duty Cycle pari a val
  analogWrite(pinLed,inputVal);
}
