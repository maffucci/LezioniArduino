/* Prof. Michele Maffucci
   26.03.2014
 
   Uso del display LCD 16x2 standard Hitachi HD44780
 
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

void setup() {
   //impostiamo il numero di colonne ed il numero di righe di lcd
  lcd.begin(16, 2);
  // Visualizzo il messaggio sul display
  lcd.print("Salve mondo!");
}

void loop() {
  // posiziona il cursore in colonna 0 e linea 1
  // (nota: la linea 1 e la seconda linea, poichè si conta incominciando da 0):
  lcd.setCursor(0, 1);
  // stampa il numero di secondi dall'ultimo reset
  lcd.print(millis()/1000);
}
