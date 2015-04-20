/* Prof. Michele Maffucci
   18.04.2014

   Utilizzo di un servomotore
   Modello: SM-S2309S da 9.9g
   Angolo di rotazione: +/- 60 gradi
   Momento torcente a 4,8 V: 1.1 kg-cm
   Momento torcente a 6 V: 1.3 kg-cm

   La segnalazione del raggiungimento dell'angolo:
   minimo, medio e massimo avvenire mediante segnalazione
   visiva (con tre LED di colore diverso)
   e sonora (con nota divers)

*/

#include <Servo.h>

Servo myservo;          // crea un oggetto Servo per controllare un servomotore

int angolo = 0;         // variabile dove conservare la posizione del dervo
int angoloMax = 120;    // angolo massimo di rotazione del servo
                        // il servo utilizzato pu ruotare da -60 a +60 gradi
                        // Variare angoloMax secondo il servo posseduto

int ledMassimo = 5;     // pin a cui collegato il led che segnala l'angolo massimo
int ledMedio = 6;       // pin a cui collegato il led che segnala l'angolo medio
int ledMinimo = 7;      // pin a cui collegato il led che segnala l'angolo minimo

int pinBuzzer = 4;      // pin a cui collegato il buzzer
int notaLA = 440;       // frequenza della nota LA
int durataNotaLA = 200; // durata (in millisecondi) della durata della nota

int notaDO = 262;       // frequenza della nota DO
int durataNotaDO = 200; // durata (in millisecondi) della durata della nota

int notaRE = 294;       // frequenza della nota RE
int durataNotaRE = 200; // durata (in millisecondi) della durata della nota

void setup()
{
  myservo.attach(11);           // collega il servo al pin 11 all'oggetto servo
  pinMode(ledMassimo, OUTPUT);  // ledMassimo definito come OUTPUT
  pinMode(ledMedio, OUTPUT);    // ledMedio definito come OUTPUT
  pinMode(ledMinimo, OUTPUT);   // ledMinimo definito come OUTPUT
  pinMode(pinBuzzer, OUTPUT);   // pinBuzzer definito come OUTPUT
}

void loop()
{
  for (angolo = 0; angolo < angoloMax; angolo += 1) // va da 0 a 120 gradi
  {                                                 // in passi di 1 grado
                                                    // viene detto al servo di andare
    myservo.write(angolo);                          // alla posizione indicata da "angolo"
    verificaAngolo(angolo);
    delay(20);                                      // aspetta 20ms tra i comandi impartiti al servo
  }

  for (angolo = angoloMax; angolo >= 1; angolo -= 1)  // va da 120 a 0 gradi
  {                                                   // viene detto al servo di andare
                                                      // alla posizione indicata da "angolo"
    myservo.write(angolo);
    verificaAngolo(angolo);
    delay(20);                                        // aspetta 20ms tra i comandi impartiti al servo
  }
}

// la funzione verificaAngolo riceve come input un "angoloRaggiunto" e in funzione di questo
// accende il LED ed emette la nota corrispondente al valore che gli  stato passato

void verificaAngolo(int angoloRaggiunto) {
  switch (angoloRaggiunto) {
    case 0:
      digitalWrite(ledMinimo, HIGH);
      digitalWrite(ledMedio, LOW);
      digitalWrite(ledMassimo, LOW);
      suona(notaLA, durataNotaLA);
      break;
    case 60:
      digitalWrite(ledMinimo, LOW);
      digitalWrite(ledMedio, HIGH);
      digitalWrite(ledMassimo, LOW);
      suona(notaDO, durataNotaDO);
      break;
    case 120:
      digitalWrite(ledMinimo, LOW);
      digitalWrite(ledMedio, LOW);
      digitalWrite(ledMassimo, HIGH);
      suona(notaRE, durataNotaRE);
      break;
  }
}

// La funzione suona emette la nota "notaEmessa" per la durata "durataNota"

void suona(int notaEmessa, int durataNota) {
  tone(pinBuzzer, notaEmessa, durataNota);
}
