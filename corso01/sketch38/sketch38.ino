/* Prof. Michele Maffucci
   26.03.2014
 
   Visualizare la temperatura rilevata con un TMP36
   con allarme di temperatura massima e minima
   su un display LCD 16x2 standard Hitachi HD44780
 
   Questo codice è di dominio pubblico

  Circuito:
 * pin RS collegato al pin digitale 12
 * pin E (Enable) collegato al pin digitale 11
 * pin D4 collegato al pin digitale 5
 * pin D5 collegato al pin digitale 4
 * pin D6 collegato al pin digitale 3
 * pin D7 collegato al pin digitale 2
 * pin R/W collegato al GND
 * pin 1 e pin 4 collegati a GND
 * pin 2 collegato a +Vcc
 * centrale del potenziometro/trimmer da 10 KOhm collegato al pin 3 del'LCD
 * pin SX potenziometro/trimmer collegato a +Vcc
 * pin DX potenziometro/trimmer collegato a GND
 * i pin SX e DX del potenziometro/trimmer possono essere interscambiati
*/

// includere la libreria:
#include <LiquidCrystal.h>

/*
   Viene creata l'istanza dell'oggetto LiquidCrystal chiamata lcd in cui
   sono indicati i pin dell'LCD collegati alle uscite digitali di Arduino
*/

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int valore = 0;                   // valore restituito dall'analogRead()
float temperatura = 0;            // variabile per conservare
                                  // la temperatura rilevata

int misure[8];                    // array in cui memorizzare 8 valori

float tempMax = 25;               // valore massimo di allarme della temperatura
float tempMin = 20;               // valore minimo di allarme della temperatura

void setup() {
  lcd.begin(16, 2);           //impostiamo il numero di colonne ed il numero di righe di lcd
  analogReference(INTERNAL);  // viene indicato al convertitore AD che la tensione
                              // di riferimento non è più 5V ma quella interna
                              // ma il valore INTERNO di 1,1 V
}

void loop() {
  // stampa della prima riga sull'LCD
  lcd.print("Temperatura...");
  // posiziona il cursore in colonna 0 e linea 1
  // (nota: la linea 1 e la seconda linea, poichè si conta incominciando da 0):
  lcd.setCursor(0, 1);

  for(int i=0;i<=7;i++) {                      // legge 8 misure di temperatura
  
  valore = analogRead(0);                      // valore letto dal sensore
  
  // calcola la proporzione
  // il valore restituito da analogRead() è un numero compreso tra
  // 0 e 1024 pertanto ciascuna unità vale 1,1/1024 = 0,107 mV
  // da cui valore misurato (volt) = val * 0,107 mV
  
  misure[i] = (0.107*valore-50);               // memorizzazione nella posizione i-esima
                                               // della temperatura
  temperatura = temperatura + misure[i];       // somma al valore letto quello precedente
}

  temperatura = temperatura/8.0;               // media dei valori letti

  // allarme se si supera la temperatura massima
  if (temperatura > tempMax) {
    allarmeMax(temperatura);
  }
  
  // allarme se si scende sotto la temperatura minima
  if (temperatura < tempMin) {
    allarmeMin(temperatura);
  }
  
  // nessun allarme se si è nell'intervallo
  if (temperatura > tempMin && temperatura < tempMax) {
    stampaTemperatura(temperatura);              // stampa la temperatura
  }
}

void stampaTemperatura(float temperatura){
  lcd.setCursor(0, 1);        // posiziona il cursore in colonna 0 riga 1
  lcd.print(temperatura);     // stampa la temperatura sull'LCD
  lcd.print((char)223);       // stampa il carattere °
  lcd.print("C");             // stampa il carattere C
  delay(1000);                // intervallo di 1 secondo
  lcd.clear();                // cancella lo schermo
}

void allarmeMax(float temperatura){
  lcd.clear();                     // cancella lo schermo
  lcd.setCursor(0, 0);             // posiziona il cursore in colonna 0 riga 0
  lcd.print("T. alta!");           // allarme temperatura alta  
  stampaTemperatura(temperatura);  // stampa la temperatura
}

void allarmeMin(float temperatura){
  lcd.clear();                     // cancella lo schermo
  lcd.setCursor(0, 0);             // posiziona il cursore in colonna 0 riga 0
  lcd.print("T. bassa!");          // allarme temperatura alta  
  stampaTemperatura(temperatura);  // stampa la temperatura
}
