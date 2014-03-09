/*  
 Esercizio 6b
 Realizziamo una sequenza di accensione e spegnimento alternato
 da destra e sinistra e viceversa di 10 LED
 
 Variazioni e commenti:
 Prof. Michele Maffucci
 09.03.2014 
 
 Questo codice è di dominio pubblico 
 */

// creazione di un array di 10 pin a cui vanno collegati i LED
// per ulteriori informazioni sull'uso degli array si consulti il seguente link:
// http://wp.me/p4kwmk-26e
// per ulteriori informazioni sui tipi byte si consulti il seguente link:
// http://wp.me/p4kwmk-1zF
byte ledPin[] = {4, 5, 6, 7, 8, 9, 10, 11, 12, 13};

// intervallo di accensione/spegnimento
int ritardoLed = 100;

// indicatore di direzione di accensione
int direzione = 1;

// indice dell'array per l'accensione del LED
int ledCorrente = 0;

// variabile in cui memorizzare il tempo di accensione di Arduino
// per ulteriori informazioni sui tipi unsigned long si consulti il seguente link:
// http://wp.me/p4kwmk-1zF
unsigned long tempoTrascorso;

void setup() {                
  // impostiamo tutti i pin ad output
  for (int x=0; x<10; x++) {
    pinMode(ledPin[x], OUTPUT);
    tempoTrascorso = millis();
    // per ulteriori informazioni sull'uso di millis() si consulti il seguente link:
    // http://wp.me/p4kwmk-1QG
  }
}

void loop() {
  // Se sono passati "ritardoLed" millisecondi dall'ultimo cambiamento
  if ((millis() - tempoTrascorso) > ritardoLed) {
    cambiaStatoLed();
    tempoTrascorso = millis();
  }
}

void cambiaStatoLed() {
  // spegne tutti i LED
  for (int x=0; x<10; x++) {
    digitalWrite(ledPin[x], LOW);
  }
  // accende il LED corrente
  digitalWrite(ledPin[ledCorrente], HIGH);
  // incrementa la variabile direzione by the direction value
  ledCorrente += direzione;
  // cambia la direzione se si arriva alla fine
  if (ledCorrente == 9) {
    direzione = -1;
  }
  if (ledCorrente == 0) {
    direzione = 1;
  }
}
