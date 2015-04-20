/* Prof. Michele Maffucci
   19.04.2014

   Utilizzo del ponte H L293D
   per pilotare da tastiera il senso
   di rotazione e la velocita' di due motori in CC
   
   Collegamenti
   L293D > Arduino

   pin 1 - pin 9
   pin 16: +Vcc
   pin 2: pin 4 Arduino
   pin 3: motore 1
   pin 4 - pin 5 - pin 12 - pin 13: GND
   pin 6: motore 1
   pin 7: 4 Arduino
   pin 8: Vin Arduino
   pin 9 - pin 10
   pin 10: pin 7
   pin 11: motore 2
   pin 14: motore 2
   pin 15: pin 6
*/

// Pin di input del ponte H
const int pinIngresso1 = 5; // collegato al pin 3 dell'L293D
const int pinIngresso2 = 4; // collegato al pin 6 dell'L293D
const int pinIngresso3 = 7; // collegato al pin 11 dell'L293D
const int pinIngresso4 = 6; // collegato al pin 14 dell'L293D
const int pinEnableA = 9;   // collegato al pin 1 dell'L293D
const int pinEnableB = 10;  // collegato al pin 9 dell'L293D

void setup()
{
  Serial.begin(9600);             // inizializzazione della porta seriale
  pinMode(pinIngresso1, OUTPUT);  // pin di controllo senso di rotazione - motore 1
  pinMode(pinIngresso2, OUTPUT);  // pin di controllo senso di rotazione - motore 1
  pinMode(pinIngresso3, OUTPUT);  // pin di controllo senso di rotazione - motore 2
  pinMode(pinIngresso4, OUTPUT);  // pin di controllo senso di rotazione - motore 2
  
  // i pin pinEnableA (corrispondente al 9) e pinEnableB (corrispondente al 10) sono di tipo PWM
  pinMode(pinEnableA, OUTPUT);  // pin enable - motore 1
  pinMode(pinEnableB, OUTPUT);  // pin enable - motore 2
  
  Serial.println("O - A - senso di rotazione dei motori");
  Serial.println("-------------------------------------");
  Serial.println("da 0 a 9 - velocita' motori");
  Serial.println("-------------------------------------");
}

void loop()
{
  if ( Serial.available()) {               // verifica disponibilia' di un carattere sulla serial
 
    char carattere = Serial.read();        // legge il carattere inserito
 
    if (isDigit(carattere)) {
    int velocita = map(carattere, '0', '9', 0, 255);  // rimappa i valori tra 0 e 9, nell'intervallo 0, 255 
                                                      // per impostare il duty cyicle
    analogWrite(pinEnableA, velocita);                // imposta la velocita' per il motore 1
    analogWrite(pinEnableB, velocita);                // imposta la velocita' per il motore 2
    Serial.println(velocita);                          // stampa sulla serial monitor la velocita' dei motori
    }
    else if (carattere == 'O')                 // rotazione oraria
    {
      Serial.println("Rotazione oraria");
      // motore 1
      digitalWrite(pinIngresso1,LOW);
      digitalWrite(pinIngresso2,HIGH);
      // motore 2
      digitalWrite(pinIngresso3,LOW);
      digitalWrite(pinIngresso4,HIGH);      
    }
    else if (carattere == 'A')                // rotazione antioraria
    {
      Serial.println("Rotazione antioraria");
      // motore 1
      digitalWrite(pinIngresso1,HIGH);
      digitalWrite(pinIngresso2,LOW);
      // motore 2
      digitalWrite(pinIngresso3,HIGH);
      digitalWrite(pinIngresso4,LOW);
    }
    else
    {
      Serial.println("Carattere non consentito");   // altri caratteri non sono consentiti
      Serial.print(carattere);                      // stampa il carattere inserito
    }
  }
}
