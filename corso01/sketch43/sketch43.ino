/* Prof. Michele Maffucci
   19.04.2014

   Utilizzo di un servomotore
   Modello: SM-S4303R da 41g
   Angolo di rotazione: 360 gradi
   Momento torcente a 4,8 V: 3.3 kg-cm
   Momento torcente a 6 V: 5.1 kg-cm

   Accelerazione e decelerazione in senso orario
   e antiorario di un servo a 360 gradi

*/

#include <Servo.h>  // libreria servo

Servo servoSx;  // crea un oggetto servo per controllare il servomotore sinistro
Servo servoDx;  // crea un oggetto servo per controllare il servomotore destro

int angolo = 0;    // variable in cui memorizzare la posizione del servo
                                                 
void setup()
{
  Serial.begin(9600); // inizializzazione della porta seriale
  servoSx.attach(9);  // collegamento del servo di sinistra al pin 9
  servoDx.attach(10); // collegamento del servo di sinistra al pin 10
}

void loop()
{
  for(angolo = 0; angolo < 180; angolo += 1)   // conteggio da 90 a 180 gradi
  {                                            // in passi da 1 grado
                                               // a 90 gradi il servo si ferma
    servoSx.write(angolo);                     // ruota il servo alla velocita' "angolo"
    servoDx.write(180-angolo);                 // va nella direzione opposta
    delay(100);                                // aspetta 100ms tra i comandi impartiti al servo
                                               // e per percepire l'accelerazione
  }  
 
  for(angolo = 180; angolo >= 0; angolo -= 1) // conteggio da 180 a 90 gradi
  {                                            // in passi da 1 grado
                                               // a 90 gradi il servo si ferma
    servoSx.write(angolo);                     // ruota il servo alla velocita' "angolo"
    servoDx.write(180-angolo);                 // va nella direzione opposta
    delay(100);                                // aspetta 100ms tra i comandi impartiti al servo
                                               // e per percepire la decelerazionze
 } 
}
