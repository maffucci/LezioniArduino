/* Prof. Michele Maffucci
   18.04.2014
   
   Utilizzo di un servomotore
   Modello: SM-S2309S da 9.9g
   Angolo di rotazione: +/- 60 gradi
   Momento torcente a 4,8 V: 1.1 kg-cm
   Momento torcente a 6 V: 1.3 kg-cm
*/

#include <Servo.h>

Servo myservo;  // crea un oggetto Servo per controllare un servomotore

int angolo = 0;      // variabile dove conservare la posizione del dervo
int angoloMax = 120; // angolo massimo di rotazione del servo
                     // il servo utilizzato pu ruotare da -60 a +60 gradi
                     // Variare angoloMax secondo il servo posseduto

void setup()
{
  myservo.attach(11);  // collega il servo al pin 11 all'oggetto servo
}


void loop()
{
  for(angolo = 0; angolo < angoloMax; angolo += 1)  // va da 0 a 120 gradi
  {                                                 // in passi di 1 grado
                                                    // viene detto al servo di andare
    myservo.write(angolo);                          // alla posizione indicata da "angolo"
    delay(20);                                      // aspetta 20ms tra i comandi impartiti al servo
  }
  for(angolo = angoloMax; angolo >= 1; angolo -= 1) // va da 120 a 0 gradi
  {
                                                    // viene detto al servo di andare
                                                    // alla posizione indicata da "angolo"
    myservo.write(angolo);            
    delay(20);                                      // aspetta 20ms tra i comandi impartiti al servo
  }
}


    

