/*  
  Esercizio 5b
  Utilizzando due LED (che chiameremo LED01 e LED02)
  realizzare un doppio lampeggiatore con la seguente
  funzionalità:

   - 3 accensioni e spegnimenti del LED01 e
     successivamente 5 accensioni e spegnimenti del LED02.

  Utilizzare un qualsiasi pin digitale dal 3 al 12
  (nell’esempio è stato usato il pin 12 e 11) fissare i tempi
  di accensione e spegnimento ad 1 secondo.
  
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

int LED01 = 11;
int LED02 = 12;

// La routine setup viene eseguita solo una volta
// ed ogni volta che riavviamo la scheda premendo il pulsante
// di reset oppure diamo alimentazione alla scheda.

void setup() {                
  // inizializzazione dei pin digitali come output.
  pinMode(LED01, OUTPUT);     
  pinMode(LED02, OUTPUT);     
}

// la routine loop funzionerà indefinitivamente
void loop() {

// LED01 fase 1  
  digitalWrite(LED01, HIGH);   // accende il LED01 (livello di tensione HIGH)
  delay(1000);                 // attesa di 1 secondo
  digitalWrite(LED01, LOW);    // spegne il LED01 (livello di tensione LOW)
  delay(1000);                 // attesa di 1 secondo

// LED01 fase 2  
  digitalWrite(LED01, HIGH);   // accende il LED01 (livello di tensione HIGH)
  delay(1000);                 // attesa di 1 secondo
  digitalWrite(LED01, LOW);    // spegne il LED01 (livello di tensione LOW)
  delay(1000); 

// LED01 fase 3  
  digitalWrite(LED01, HIGH);   // accende il LED01 (livello di tensione HIGH)
  delay(1000);                 // attesa di 1 secondo
  digitalWrite(LED01, LOW);    // spegne il LED01 (livello di tensione LOW)
  delay(1000);

// LED02 fase 1  
  digitalWrite(LED02, HIGH);   // accende il LED02 (livello di tensione HIGH)
  delay(1000);                 // attesa di 1 secondo
  digitalWrite(LED02, LOW);    // spegne il LED02 (livello di tensione LOW)
  delay(1000);

// LED02 fase 2  
  digitalWrite(LED02, HIGH);   // accende il LED02 (livello di tensione HIGH)
  delay(1000);                 // attesa di 1 secondo
  digitalWrite(LED02, LOW);    // spegne il LED02 (livello di tensione LOW)
  delay(1000);

// LED02 fase 3  
  digitalWrite(LED02, HIGH);   // accende il LED02 (livello di tensione HIGH)
  delay(1000);                 // attesa di 1 secondo
  digitalWrite(LED02, LOW);    // spegne il LED02 (livello di tensione LOW)
  delay(1000);

// LED02 fase 4  
  digitalWrite(LED02, HIGH);   // accende il LED02 (livello di tensione HIGH)
  delay(1000);                 // attesa di 1 secondo
  digitalWrite(LED02, LOW);    // spegne il LED02 (livello di tensione LOW)
  delay(1000);

// LED02 fase 5  
  digitalWrite(LED02, HIGH);   // accende il LED02 (livello di tensione HIGH)
  delay(1000);                 // attesa di 1 secondo
  digitalWrite(LED02, LOW);    // spegne il LED02 (livello di tensione LOW)
  delay(1000);
}
