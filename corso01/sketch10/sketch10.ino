/*
  Prof. Michele Maffucci
  08.03.2014 
  
   Antirimbalzo
   pulsante collegato al pin 7 LED al pin 8
   La logica di antirimbalzo impedisce il fraintendimento
   dello stato del pulsante.
   
   Questo codice è di dominio pubblico
*/

const int LED = 8;                    // LED collegato al pin digitale 8
const int BUTTON = 7;                 // pin di input dove è collegato il pulsante
const int ritardoRimbalzo = 10;       // millisecondi di attesa fino alla stabilità

// antirimbalzo restituisce lo stato quando l'interruttore è stabile
boolean antirimbalzo(int pin)
{
  boolean stato;
  boolean precedenteStato;

  precedenteStato = digitalRead(pin); // memorizza lo statoprecedente
  for(int contatore=0; contatore < ritardoRimbalzo; contatore++)
  {
      delay(1);                      // attende per 1 millisecondo
      stato = digitalRead(pin);      // legge il pin
      if( stato != precedenteStato)
      {   
         contatore = 0;              // resetta il contatore se lo stato e cambiato    
         precedenteStato = stato;    // salva lo stato corrente
      }
  }
  // a questo punto lo stato è stabile e viene restituito
  return stato;
}

void setup()
{
  pinMode(BUTTON, INPUT);
  pinMode(LED, OUTPUT);
}

void loop()
{
  int stato = antirimbalzo(BUTTON);
  digitalWrite(LED, stato);
}
