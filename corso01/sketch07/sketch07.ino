/*
  Prof. Michele Maffucci
  07.03.2014 
 
  Accensione del LED alla pressione del pulsante
 
  Questo codice è di dominio pubblico 
*/

int LED = 8;                    // LED collegato al pin digitale 8
int BUTTON = 7;                 // pin di input dove è collegato il pulsante

int val = 0;                    // si userà val per conservare lo stato del 
                                // pin di input a cui è collegato il pulsante

void setup() {
  pinMode(LED, OUTPUT);         // imposta il pin digitale come output
  pinMode(BUTTON, INPUT);       // imposta il pin digitale come input
}

void loop() {
  val = digitalRead(BUTTON);    // legge il valore dell'input e lo conserva

  // controlla che l'input sia HIGH (pulsante premuto)
  if (val == HIGH) {
    digitalWrite(LED, HIGH);   // accende il LED (livello di tensione HIGH)
  }
  else {
    digitalWrite(LED, LOW);    // spegne il LED
  }
}
