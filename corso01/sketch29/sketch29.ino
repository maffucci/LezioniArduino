/* Prof. Michele Maffucci
   16.03.2014
 
   Realizzazione Theremin comandato
   dalla luce.
 
   Questo codice è di dominio pubblico 
 */

// variabile usata per conservare il valore rilevato dal sensore
int valoreSensore;

// variabile usata per calibrare il valore minimo
int valoreBasso = 1023;

// variabile usata per calibrare il valore massimo
int valoreAlto = 0;

// il pin a cui è collegato il LED
const int pinLed = 13;

void setup()
{
  pinMode(pinLed, OUTPUT); // imposta il pin come output
  
  // viene segnalato che incomincia la fase di calibrazione
  digitalWrite(pinLed, HIGH);
  // calibrazione per i primi cinque secondi dopo l'avvio del programma
  // millis() Restituisce il numero di millisecondi da quando la scheda
  // Arduino ha incominciato l’esecuzione del programma corrente.
  // Il tipo di dato è un unsigned long.
  // Nota: questo valore va in overflow (supera il limite della memoria)
  // per cui ricomincia da zero dopo circa 9 ore.
  
  // per calibrare muovere la mano sopra il sensore
  
  while (millis()<5000) {
    // registra il massimo valore rilevato
    valoreSensore = analogRead(A0);
    if (valoreSensore > valoreAlto) {
      valoreAlto = valoreSensore;
    }
    // registra il valore minimo rilevato
    if (valoreSensore < valoreBasso) {
      valoreBasso = valoreSensore;
    }
  }
  // spegne il LED collegato al pin 13, in questo modo
  // si segnala che è terminata la fase di calibrazione
  digitalWrite(pinLed, LOW);
}

void loop() {
  // legge il valore da A0 e lo memorizza nella variabile
  valoreSensore = analogRead(A0);

  // mappa i valori letti dal sensore nell'intervallo 50, 4000
  int tono = map(valoreSensore, valoreBasso, valoreAlto, 50, 4000);

  // suona un tono per 20 millisecondi sul pin 8
  // la funzione tone(pin, frequenza, durata) ha tre argomenti:
  // pin: il piedino su cui inviare il tono
  // frequenza: frequenza del tono emesso
  // durata: durata in millisecondi del tono emesso
  tone(8, tono, 20);

  // attesa di 10 millisecondi prima che venga riprodotto il successivo tono
  delay(10);
}



