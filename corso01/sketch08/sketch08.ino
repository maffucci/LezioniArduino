/*
  Prof. Michele Maffucci
  08.03.2014 
 
 Controllo dell'accensione di due LED mediante pulsanti
 
 Questo codice è di dominio pubblico 
 */

int LED01 = 8;                  // LED01 collegato al pin digitale 8
int LED02 = 6;                  // LED02 collegato al pin digitale 6

int BUTTON01 = 7;               // pin di input dove è collegato il pulsante 01
int BUTTON02 = 5;               // pin di input dove è collegato il pulsante 02

int val01 = 0;                  // si userà val01 per conservare lo stato del 
// pin di input a cui è collegato il pulsante 01

int val02 = 0;                  // si userà val02 per conservare lo stato del 
// pin di input a cui è collegato il pulsante 02

void setup() {
  pinMode(LED01, OUTPUT);       // imposta il pin digitale come output
  pinMode(BUTTON01, INPUT);     // imposta il pin digitale come input
  pinMode(LED02, OUTPUT);       // imposta il pin digitale come output
  pinMode(BUTTON02, INPUT);     // imposta il pin digitale come input
}

void loop() {
  val01 = digitalRead(BUTTON01);  // legge il valore dell'input e lo conserva
  val02 = digitalRead(BUTTON01);  // legge il valore dell'input e lo conserva

  // controlla che l'input sia HIGH (pulsante premuto)
  if (val01 == HIGH) {
    digitalWrite(LED01, HIGH);   // accende il LED (livello di tensione HIGH)
    delay(1000);                 // attesa di 1 secondo
    digitalWrite(LED01, LOW);    // spegne il LED (livello di tensione LOW)
    delay(1000);                 // attesa di 1 secondo
  }
  else {
    digitalWrite(LED01, LOW);    // spegne il LED
  }
  if (val02 == HIGH) {
    digitalWrite(LED02, HIGH);   // accende il LED (livello di tensione HIGH)
    delay(250);                  // attesa di 250 millisecond
    digitalWrite(LED02, LOW);    // spegne il LED (livello di tensione LOW)
    delay(250);                  // attesa di 250 millisecond
  }
  else {
    digitalWrite(LED02, LOW);    // spegne il LED
  }
}
