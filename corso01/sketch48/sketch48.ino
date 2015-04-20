/* Prof. Michele Maffucci
   19.04.2014

   Utilizzo del ponte H L293D
   per pilotare mediante pulsante e trimmer
   direzione e velocita' di rotazione
   di un motorino in CC
   
   Collegamenti
   L293D > Arduino

   pin 1: pin 11
   pin 2: pin 10
   pin 3: motore
   pin 4 - pin 5 - pin 12 - pin 13: GND
   pin 6: motore
   pin 7: pin 9
   pin 8: Vin
   pin 9 - pin 16: +Vcc
*/

const int pinEnableA = 11;       // collegato al pin 1 dell'L293D
const int pinIngresso1 = 10;     // collegato al pin 2 dell'L293D
const int pinIngresso2 = 9;      // collegato al pin 7 dell'L293D
const int cambioDirezione = 7;   // collegato al pulsante
const int pinTrimmer = 0;        // collegato al trimmer

void setup()
{
  pinMode(pinIngresso1, OUTPUT);  // pin di controllo senso di rotazione - motore 1
  pinMode(pinIngresso2, OUTPUT);  // pin di controllo senso di rotazione - motore 1
  pinMode(pinEnableA, OUTPUT);    // pin enable - motore 1
  pinMode(cambioDirezione, INPUT_PULLUP); // abilitazione della resistenza di pull-up
}

void loop()
{
  int velocita = analogRead(pinTrimmer);                // lettura dell'impostazione dal trimmer
  int velocitaMotore = map(velocita, 0, 1023, 0, 255);  // rimappiamo i valori in un intervallo idoneo per il PWM
  boolean retromarcia = digitalRead(cambioDirezione);   // viene conservato il valore imposto dal pulsante
  impostaMotore(velocitaMotore, retromarcia);           // funzione che imposta velocita' e direzione del motore
}

void impostaMotore(int velocita, boolean retromarcia)
{
  analogWrite(pinEnableA, velocita);                    // viene passato il valore del PWM
  digitalWrite(pinIngresso1, ! retromarcia);            // inversione di marcia
  digitalWrite(pinIngresso2, retromarcia);              // inversione di marcia
}
