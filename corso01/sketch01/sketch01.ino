/*  
  Esercizio 1
  Variate il tempo di accensione e spegnimento, con tempi uguali
  di accensione e spegnimento (superiore ad 1 secondo).
  
  Variazioni e commenti:
  Prof. Michele Maffucci
  05.03.2014 
 
  Per maggiori informazioni sulle istruzioni
  usate in questo codice:
 
  http://wp.me/p4kwmk-1Ps
 
  Questo codice è di dominio pubblico 
 */
 
// Sulla maggior parte delle schede Arduino
// il pin 13 è connesso il LED L che si trova sulla scheda
// assegnamo al pin 13 il nome "led"

int led = 13;

// La routine setup viene eseguita solo una volta
// ed ogni volta che riavviamo la scheda premendo il pulsante
// di reset oppure diamo alimentazione alla scheda.

void setup() {                
  // inizializzazione dei pin digitali come output.
  pinMode(led, OUTPUT);     
}

// la routine loop funzionerà indefinitivamente
void loop() {
  digitalWrite(led, HIGH);   // accende il LED (livello di tensione HIGH)
  delay(2000);               // attesa di 2 secondo
  digitalWrite(led, LOW);    // spegne il LED (livello di tensione LOW)
  delay(2000);               // attesa di 2 secondo
}
