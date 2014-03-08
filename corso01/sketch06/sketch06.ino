/*
  Prof. Michele Maffucci
  05.03.2014 
 
 Esercizio 6
 Realizzare un semaforo,
 utilizzando tre LED (che chiameremo pinRosso, pinGiallo, pinVerde)
 rispettivamente rosso, giallo, verde.
 
 Utilizzare un qualsiasi pin digitale dal 3 al 12
 (nell’esempio è stato usato il pin 12, 11, 10) fissare i tempi
 di accensione e spegnimento ad 1 secondo.
 
 - durata del rosso 10 secondi
 - durata del verde 10 secondi
 - durata del giallo 5 secondi
 
 Questo codice è di dominio pubblico 
 */

int delayRV = 10000;                  // durata rosso e verde
int delayG = 5000;                    // durata giallo

int pinRosso = 10;
int pinGiallo = 9;
int pinVerde = 8;

void setup() {
  // inizializzazione dei pin digitali come output.
  pinMode(pinRosso, OUTPUT);
  pinMode(pinGiallo, OUTPUT);
  pinMode(pinVerde, OUTPUT);
}

void loop() {

  digitalWrite(pinRosso, HIGH);         // accensione del rosso
  delay(delayRV);                       // durata accensione di 10 secondi
  digitalWrite(pinRosso, LOW);          //spegne il rosso

  digitalWrite(pinVerde, HIGH);         // accende il verde
  delay(delayRV);                       // durata accensione di 10 secondi

  digitalWrite(pinGiallo, HIGH);        // accende il giallo
  delay(delayG);                        // aspettare 5 secondi
  digitalWrite(pinVerde, LOW);          //spegne il verde
  digitalWrite(pinGiallo, LOW);         //spegne il giallo
}

