/* Prof. Michele Maffucci
   16.03.2014
 
   Uso della Serial.read() per inviare,
   tramite la Serial Monitor, comandi ad Arduino.
 
   Facciamo lampeggiare il led connesso al pin 13 ad una
   velocità proporzionale al numero inviato ad Arduino.
   Viene stampato sulla Serial Monitor il delay con cui lampeggia
   il LED
 
   Questo codice è di dominio pubblico 
 */

const int pinLed = 13;   // il pin a cui è collegato il LED
int indiceBlink=0;       // velocità con cui lampeggia il LED
int valore = 0;

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
      valore = (valore*10) + (ch -'0'); // calcolo per accumulare il valore che si sta digitando
                                        // es. inserendo 276
                                        // valore1 = 0*10+50-48=2
                                        // valore2 = 2*10+55-48=27
                                        // valore3 = 27*10+54-48=276
                         
    }
    // l'invio da tastiera corrisponde codice ASCII 10
    // vuol dire che abbiamo terminato la scrittura del numero ed abbiamo
    // premuto sull'invio
    else if (ch == 10)                  
    {
      indiceBlink = valore;              // il valore del delay
      Serial.println(indiceBlink);       // stampa sulla Serial Monitor del valore del delay
      valore=0;                          // si reimposta valore a 0 per un nuovo inserimento
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


