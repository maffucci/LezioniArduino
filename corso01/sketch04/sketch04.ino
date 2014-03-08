/*  
  Esercizio 4
  Utilizzando un LED esterno (diverso dal LED L della scheda)
  ed una resistenza da collocare in serie al LED per limitare
  la corrente del circuito, far funzionare il programma Blink.
  Utilizzare un qualsiasi pin digitale dal 3 al 12
  (nell’esempio è stato usato il pin 12) e verificatene il
  funzionamento con tempi di accensione e spegnimento a piacere.
  
  Variazioni e commenti:
  Prof. Michele Maffucci
  05.03.2014 
 
  Per maggiori informazioni sulle istruzioni
  usate in questo codice:
 
  http://wp.me/p4kwmk-1Ps
 
  Questo codice è di dominio pubblico 
 */
 
// Sulla maggior parte delle schede Arduino
// il pin 12 è connesso il LED L che si trova sulla scheda
// assegnamo al pin 12 il nome "led"

int led = 12;

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
  delay(3000);               // attesa di 3 secondo
}
