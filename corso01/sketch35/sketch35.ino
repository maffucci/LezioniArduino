/* Prof. Michele Maffucci
   26.03.2014
 
   Rilevare la temperatura con
   sensore di temperatura
   TMP36
   Aumentare la precisione di lettura
   usando il riferimento interno di 1,1 V
   e facendo una media tra 8 rilevazioni
 
   Questo codice è di dominio pubblico
 
*/

int valore = 0;                   // valore restituito dall'analogRead()
float temperatura = 0;            // variabile per conservare
                                  // la temperatura rilevata

float misure[8];                    // array in cui memorizzare 8 valori
                              
void setup()
{
  Serial.begin(9600);         // inizializzazione della porta seriale
  analogReference(INTERNAL);  // viene indicato al convertitore AD che la tensione
                              // di riferimento non è più 5V ma quella interna
                              // ma il valore INTERNO di 1,1 V
}
 
void loop()
{

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
  Serial.println(temperatura);                 // stampa sulla Serial monitor
                                               // il valore letto dal sensore
  delay(1000);                                 // intervallo di 1 secondo
}


