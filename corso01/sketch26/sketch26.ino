/* Prof. Michele Maffucci
   16.03.2014
 
   Uso della Serial.read() per inviare,
   tramite la Serial Monitor, comandi ad Arduino.
 
   Facciamo lampeggiare il led connesso al pin 13 ad una
   velocità proporzionale al numero (da 0 a 9) inviato ad Arduino.
   Viene stampato sulla Serial Monitor il delay con cui lampeggia
   il LED
 
   Questo codice è di dominio pubblico 
 */

const int pinLed = 13;   // il pin a cui è collegato il LED
int indiceBlink=0;       // velocità con cui lampeggia il LED

void setup()
{
  Serial.begin(9600);      // inizializzazione della porta seriale
  pinMode(pinLed, OUTPUT); // imposta il pin come output
}

void loop()
{
  if ( Serial.available())              // Viene controllato se è disponibile un carattere
  {
    char ch = Serial.read();            // definizione di una variabile di tipo char in cui memorizzare
                                        // il carattere inviato ad Arduino mediante la finestra Serial Monitor 
    if( isDigit(ch) )                   // si verifica se il carattere ASCII è un numero compreso tra 0 e 9
    {
      indiceBlink = (ch - '0');        // Il valore ASCII viene convertito in valore numerico
      indiceBlink = indiceBlink * 100; // il valore numerico viene moltiplicato per 100 millisecondi
    }
  }
  blink();
}

// il led lampeggia con una tempo di accensione e spegnimento determinato da indiceBlink
void blink()
{
  Serial.print("Sto lampeggiando con un delay di: ");  // stampa il testo compreso tra ""
  Serial.println(indiceBlink);                         // stampa indiceBlink e va a capo
  digitalWrite(pinLed,HIGH);
  delay(indiceBlink);                                  // ritardo che dipende da indiceBlink
  digitalWrite(pinLed,LOW);
  delay(indiceBlink);
}    

