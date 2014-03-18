/* Prof. Michele Maffucci
   18.03.2014
 
   Realizziamo un voltmetro
   per tensioni non superiori a 5V
   
   Utilizzare il numero 0 per spegnere il voltmetro
   ed il LED connesso al pin 13
   
   Utilizzare il numero 1 per visualizzare l atensione
   ed accendere il LED connesso al pin 13
 
   ATTENZIONE non collegare tensioni superiori
   a 5 V sui pin di Arduino
 
   Questo codice è di dominio pubblico
 
 */

// tensione di riferimento
const float voltRiferimento = 5.0;

// pin a cui è connessa la batteria
const int pinBatteria = A0;

// il pin a cui è collegato il LED
const int pinLed = 13;

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
      if (ch=='0')
      {
        Serial.println("Voltmetro spento");
        digitalWrite(pinLed, LOW);                     // spegne il LED
      } 
      if ( ch=='1' )
      {
        digitalWrite(pinLed, HIGH);                     // accende il LED
        int val = analogRead(pinBatteria);              // legge il valore da A0

        // calcola la proporzione
        // il valore restituito da analogRead() è un numero compreso tra
        // 0 e 1023 pertanto ciascuna unità vale 5/2023 = 4,89 mV
        // da cui valore misurato (volt) = val * 4,89 mV
        float volt = val * (voltRiferimento/1023.0);  
        Serial.print(volt);                             // stampa il valore
        Serial.println(" V");                           // stampa il valore
      }
    }
  }
}



