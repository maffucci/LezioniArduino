/* Prof. Michele Maffucci
   25.03.2014
 
   Rilevare il valore restituito dalla analogRead()
   utilizzando il sensore di temperatura TMP36
 
   Questo codice è di dominio pubblico
 
*/
 
void setup()
{
  Serial.begin(9600);         // inizializzazione della porta seriale

}
 
void loop()
{
  delay(1000);                // si effettuano rilevazioni
                              // ogni secondo
  int valore = analogRead(0);
  Serial.println(valore);     // stampa sulla Serial monitor
                              // il valore letto dal sensore
}


