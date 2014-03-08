/* Prof. Michele Maffucci
   08.03.2014
   
   Utilizzo della funzione analgoWrite() - (duty cycle 75%)
   
   Questo codice è di dominio pubblico
*/

#define LED 11           // LED collegato al pin digitale 11

void setup() {
  pinMode(LED, OUTPUT);  // imposta il pin digitale come output
}

void loop() {
  analogWrite(LED, 191); // accende il LED
}
