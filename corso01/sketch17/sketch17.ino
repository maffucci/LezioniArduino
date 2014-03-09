/* Prof. Michele Maffucci
   08.03.2014
 
   Effetto fuoco
   Si utilizzano tre pin digitali PWM per ricreare un
   effetto fiamma
 
   Questo codice è di dominio pubblico 
 */

// pin a cui collegare i LED
int ledPin1 = 9;
int ledPin2 = 10;
int ledPin3 = 11;

void setup() 
// imposta il pin digitale come output
{
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
}
void loop()
{
  // il secondo parametro della digitalWrite definisce
  // il duty cycle con cui si accenderà e spegnerà il LED
  // per ulteriori informazioni sull'uso dell'istruzione random si consulti il seguente link:
  // http://wp.me/p4kwmk-20C
  // random(120) restituisce un numero casuale nell'intervallo 0..120
  // poiché il valore del duty cycle ha come valore massimo 255
  // si avrà al massimo come secondo parametro della analogWrite 120+135=255

  analogWrite(ledPin1, random(120)+135);
  analogWrite(ledPin2, random(120)+135);
  analogWrite(ledPin3, random(120)+135);

  // intervallo casuale (con numeri tra 0 e 100) per avere intervalli
  // di accensione dei tre LED sempre diversi
  delay(random(100));
}
