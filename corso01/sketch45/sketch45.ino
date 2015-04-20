/* Prof. Michele Maffucci
   19.04.2014

   Utilizzo del ponte H L293D
   per pilotare da tastiers il senso
   di rotazione di un motore in CC
   
   Collegamenti
   L293D > Arduino

   pin 1 - pin 9 - pin 16: +Vcc
   pin 2: pin 4 Arduino
   pin 3: motore
   pin 4 - pin 5 - pin 12 - pin 13: GND
   pin 6: motore
   pin 7: 4 Arduino
   pin 8: Vin Arduino  
*/

// Pin di input del ponte H
const int pinIngresso1 = 5; // collegato al pin 3 dell'L293D
const int pinIngresso2 = 4; // collegato al pin 6 dell'L293D

void setup()
{
  Serial.begin(9600);             // inizializzazione della porta seriale
  pinMode(pinIngresso1, OUTPUT);  // pin di controllo senso di rotazione
  pinMode(pinIngresso2, OUTPUT);  // pin di controllo senso di rotazione
  Serial.println("1 - 2 impostano la direzione, qualsiasi altro pulsante ferma il motore");
  Serial.println("----------------------------------------------------------------------");
}

void loop()
{
  if ( Serial.available()) {        // verifica disponibilia' di un carattere sulla serial
    char ch = Serial.read();        // legge il carattere inserito
    if (ch == '1')                  // rotazione oraria
    {
      Serial.println("Rotazione oraria");
      digitalWrite(pinIngresso1,LOW);
      digitalWrite(pinIngresso2,HIGH);
    }
    else if (ch == '2')              // rotazione antioraria
    {
      Serial.println("Rotazione antioraria");
      digitalWrite(pinIngresso1,HIGH);
      digitalWrite(pinIngresso2,LOW);
    }
    else
    {
      Serial.println("Motore fermo");   // ferma il motore
      digitalWrite(pinIngresso1,LOW);
      digitalWrite(pinIngresso2,LOW);
    }
  }
}
