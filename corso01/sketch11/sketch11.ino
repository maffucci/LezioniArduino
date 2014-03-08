/* Prof. Michele Maffucci
   08.03.2014
   
   Utilizzo della funzione analgoWrite() - (duty cycle 0%)
   
   Questo codice è di dominio pubblico
*/

#define LED 11           // LED collegato al pin digitale 11

void setup() {
  pinMode(LED, OUTPUT);  // imposta il pin digitale come output
}

void loop() {
  analogWrite(LED, 0);   // accende il LED
}
