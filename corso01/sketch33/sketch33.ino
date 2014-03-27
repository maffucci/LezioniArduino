/* Prof. Michele Maffucci
   26.03.2014
 
   Rilevare la temperatura con
   sensore di temperatura
   TMP36
   Aumentare la precisione di lettura
   usando il riferimento esterno di 3,3 V
 
   Questo codice è di dominio pubblico
 
*/

int valore = 0;               // valore restituito dall'analogRead()
float temperatura = 0;        // variabile per conservare
                              // la temperatura rilevata
void setup()
{
  Serial.begin(9600);         // inizializzazione della porta seriale
  analogReference(EXTERNAL);  // viene indicato al convertitore AD che la tensione
                              // di riferimento non è più 5V ma quella ESTERNA
                              // di 3,3 V
}
 
void loop()
{

  valore = analogRead(0);     // valore letto dal sensore
  
  // calcola la proporzione
  // il valore restituito da analogRead() è un numero compreso tra
  // 0 e 1024 pertanto ciascuna unità vale 3,3/1024 = 0,322 mV
  // da cui valore misurato (volt) = val * 0,322 mV
  
  temperatura = (0.322*valore-50);
  Serial.println(temperatura);     // stampa sulla Serial monitor
                                   // il valore letto dal sensore
  delay(1000);                     // intervallo di 1 secondo
}


