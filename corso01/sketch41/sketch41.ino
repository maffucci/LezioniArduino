
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

byte posizione = 0;        // variabile per posizione corrente del servo
byte controlloLimite = 0;  // variabile per il controllo del raggiungimento di uno dei limiti (0, 60, 120)

void setup()
{
  myservo.attach(11);           // collega il servo al pin 11 all'oggetto servo
  Serial.begin(9600);           // inizializzazione della porta seriale
  pinMode(ledMassimo, OUTPUT);  // ledMassimo definito come OUTPUT
  pinMode(ledMedio, OUTPUT);    // ledMedio definito come OUTPUT
  pinMode(ledMinimo, OUTPUT);   // ledMinimo definito come OUTPUT
  pinMode(pinBuzzer, OUTPUT);   // pinBuzzer definito come OUTPUT
}

void loop()
{
  if (Serial.available())
  {
    byte passo = Serial.read();
    
    // fino a quando non si raggiunge l'angolo minimo, premendo "1" viene decrementata l'angolo
    if (passo == '1') // premendo '1' decremento la variabile fino al valore minimo 20
    {
      if (posizione >= 20) // fino a quando la posizione maggiore di 20 gradi puo' diminuire
      {
        posizione = posizione - 20;
        Serial.println("Mi sono spostato di 20 gradi indietro");
        controllaPosizione(posizione);
      }
    }

    // fino a quando non si raggiunge l'angolo massimo, premendo "2" viene incrementato l'angolo
    else if (passo == '2') // premendo '2' aumento la variabile fino al valore massimo 120
    {
      if (posizione < 120) // fino a quando la posizione minore di 120 gradi puo' diminuire
      {
        posizione = posizione + 20;
        Serial.println("Mi sono spostato di 20 gradi in avanti");
        controlloLimite = posizione;
        controllaPosizione(controlloLimite);
      }
    }
  }
  myservo.write (posizione);
}

// la funzione verificaAngolo riceve come input un "angoloRaggiunto" e in funzione di questo
// accende il LED ed emette la nota corrispondente al valore che gli  stato passato

void controllaPosizione(int angoloRaggiunto) {
  switch (angoloRaggiunto) {
    case 0:                                  // controllo raggiungimento 0 gradi
      digitalWrite(ledMinimo, HIGH);
      digitalWrite(ledMedio, LOW);
      digitalWrite(ledMassimo, LOW);
      suona(notaLA, durataNotaLA);
      controlloLimite=0;
      break;
    case 60:                                 // controllo raggiungimento 60 gradi
      digitalWrite(ledMinimo, LOW);
      digitalWrite(ledMedio, HIGH);
      digitalWrite(ledMassimo, LOW);
      suona(notaDO, durataNotaDO);
      controlloLimite=0;
      break;
    case 120:                                // controllo raggiungimento 120 gradi
      digitalWrite(ledMinimo, LOW);
      digitalWrite(ledMedio, LOW);
      digitalWrite(ledMassimo, HIGH);
      suona(notaRE, durataNotaRE);
      controlloLimite=0;
      break;
      default:
      digitalWrite(ledMinimo, LOW);
      digitalWrite(ledMedio, LOW);
      digitalWrite(ledMassimo, LOW);  
  }
}

// La funzione suona emette la nota "notaEmessa" per la durata "durataNota"

void suona(int notaEmessa, int durataNota) {
  tone(pinBuzzer, notaEmessa, durataNota);
}
