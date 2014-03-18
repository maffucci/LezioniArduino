/* Prof. Michele Maffucci
   16.03.2014
 
   Crepuscolare con LDR
 
   Questo codice è di dominio pubblico 
*/

// variabile in cui verrà memorizzato il valore presente sul pin A0
const int misura = A0;

// pin a cui è connesso il LED
const int pinLed = 11;

// variabile in cui memorizzare il valore letto dal sensore
int inputVal = 0;

void setup() {            
  // Serial.begin(rate) inizializzazione della seriale
  // Per maggiori informazioni si consulti il link: http://wp.me/p4kwmk-211
  Serial.begin(9600);
  
  // definizione di ledPin come output  
  pinMode(pinLed, OUTPUT);
}

void loop() {
  // analogRead leggerà il valore su A0 restituendo un valore tra 0 e 1023
  // per approfondimenti si consulti il link: http://wp.me/p4kwmk-1Qd
  inputVal = analogRead(misura);

  // la Serial.println(data) stampa i dati sulla porta seriale
  // (invia i dati alla seriale e li visualizza) seguito da un
  // ritorno a capo automatico ed un avanzamento linea.
  Serial.print("Valore letto dal sensore = ");  // stampa ciò che è incluso tra ""
  Serial.print(inputVal);                       // stampa inputVal
  Serial.print("; LED = " );                    // stampa inputVal

  if(inputVal < 250){
    Serial.println("ACCESO");                  // stampa ciò che è incluso tra ACCESO
    digitalWrite(pinLed, HIGH);                // accende il LED

  }
  else{
    Serial.println("SPENTO");                  // stampa ciò che è incluso tra SPENTO
    digitalWrite(pinLed, LOW);                 // spegne il LED
  }
  delay(2);                                    // attesa di 2 millisecondi
}
