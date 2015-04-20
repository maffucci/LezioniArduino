/* Prof. Michele Maffucci
   18.04.2014
   
   Controllo rotazione servo con trimmer
   
   Utilizzo di un servomotore
   Modello: SM-S2309S da 9.9g
   Angolo di rotazione: +/- 60 gradi
   Momento torcente a 4,8 V: 1.1 kg-cm
   Momento torcente a 6 V: 1.3 kg-cm
   
*/

#include <Servo.h>

Servo myservo;  // crea un oggetto Servo

int pinTrimmer = 0;  // pin analogico a cui viene connesso il trimmer
int valore;          // variabile usata per memorizzare il lavolre di ingresso

void setup()
{
  myservo.attach(11);  // collegamento del servo sul pin 11
}

void loop()
{
  valore = analogRead(pinTrimmer);        // legge il valore dl trimmer
  valore = map(valore, 0, 1023, 0, 120);  // cambiamento di coordinate per poter essere usato con il servo
  myservo.write(valore);                  // la posizione viene impostata sul valore scalato
  delay(20);                              // attesa per permettere al server di raggoingere la posizione
}
