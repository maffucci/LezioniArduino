/* Prof. Michele Maffucci
   08.03.2014
   
   Fading
   
   Questo codice è di dominio pubblico
*/

#define LED 11              // LED collegato al pin digitale 11
int valoreFade = 0;         // variabile usata per contare in avanti e indietro

void setup()  { 
  pinMode(LED, OUTPUT);     // imposta il pin digitale come output
} 

void loop()  {
  // procede ciclicamente da 0 a 254 (fade in -> aumento luminosità)
  for (valoreFade = 0 ; valoreFade < 255; valoreFade++) { 
    analogWrite(LED, valoreFade);      //impostiamo la luminosità del LED
    delay(10);  
    // aspettiamo 10ms per percepire la viariazione di luminosità,
    //perché analogWrite è istantaneo                        
  } 
  // procede ciclicamente da 255 a 1 (fade out -> diminuzione della luminosità)
  for(valoreFade = 255 ; valoreFade > 0; valoreFade--) {
    analogWrite(LED, valoreFade);      //impostiamo la luminosità del LED
    delay(10);  
    // aspettiamo 10ms per percepire la viariazione di luminosità,
    //perché analogWrite è istantaneo                               
  } 
}
