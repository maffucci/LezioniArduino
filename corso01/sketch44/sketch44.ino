/* Prof. Michele Maffucci
   19.04.2014

   Utilizzo di un servomotore
   Modello: SM-S4303R da 41g
   Angolo di rotazione: 360 gradi
   Momento torcente a 4,8 V: 3.3 kg-cm
   Momento torcente a 6 V: 5.1 kg-cm

   Controllo rotazione servomotore 360 gradi
   mediante input da tastiera.

*/

#include <Servo.h>  // libreria servo

Servo servoSx;  // crea un oggetto servo per controllare il servomotore sinistro
Servo servoDx;  // crea un oggetto servo per controllare il servomotore destro

void setup()
{
  Serial.begin(9600); // inizializzazione della porta seriale
  servoSx.attach(9);  // collegamento del servo di sinistra al pin 9
  servoDx.attach(10); // collegamento del servo di sinistra al pin 10

// menu' di utilizzo

  Serial.println("---------- menu' ----------");
  Serial.println("pulsante 1 - vai avanti");
  Serial.println("pulsante 2 - vai indietro");
  Serial.println("pulsante 3 - fermati");
  Serial.println("---------------------------");
}

void loop()
{
  if (Serial.available())          // verifica disponibilia' di un carattere sulla serial
  {
    byte rotazione = Serial.read(); // legge il valore inserito

 // se 1 viene chiamata la funzione avanti e inviato messaggio sulla serial
    if (rotazione == '1')
    {
      avanti();
      Serial.println("Sto andando avanti");
    }
 // se 2 viene chiamata la funzione indietro e inviato messaggio sulla serial
    if (rotazione == '2')
    {
      indietro();
      Serial.println("Sto andando indietro");
    }
 // se 3 viene chiamata la funzione ferma e inviato messaggio sulla serial
    if (rotazione == '3')
    {
      ferma();
      Serial.println("Sono fermo");
    }
  }
}

void avanti() {
  servoSx.write(0);
  servoDx.write(180);
}

void indietro() {
  servoSx.write(180);
  servoDx.write(0);
}

void ferma() {
  servoSx.write(90);
  servoDx.write(90);
}



