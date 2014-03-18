/* Prof. Michele Maffucci
   18.03.2014
 
   Realizzazione Theremin comandato
   dalla luce.
 
   Tratto dall'esempio:  Examples > 10.StarterKit > p07_Keyboard
   
   Questo codice è di dominio pubblico 
*/

// array delle frequenze delle note
// c, d, e, f
int notes[] = {262, 294, 330, 349};

int pinPiezzo = 9;

void setup() {
  // inizializzazione seriale
  Serial.begin(9600);
  pinMode(pinPiezzo, OUTPUT);
}

void loop() {
  // variabile locale in cui memorizzare i valori sul pin A0
  int keyVal = analogRead(A0);
  // stampa i valori di A0 sulla Serial Monitor
  Serial.println(keyVal);
  
  // suona la nota corrispondente a ciascun valore di A0
  if(keyVal == 1023){
    // emette la prima nota sul pin 8 presente nell'array
    tone(pinPiezzo, notes[0]);
  }
  else if(keyVal >= 990 && keyVal <= 1010){
    // emette la seconda nota sul pin 8 presente nell'array
    tone(pinPiezzo, notes[1]);
  }
  else if(keyVal >= 505 && keyVal <= 515){
    // emette la terza bota sul pin 8 presente nell'array
    tone(pinPiezzo, notes[2]);
  }
  else if(keyVal >= 5 && keyVal <= 10){
    // emette la quarta nota sul pin 8 presente nell'array
    tone(pinPiezzo, notes[3]);
  }
  else{
    // se i valori sono fuori dall'intervallo non emette suoni
    noTone(pinPiezzo);
  }
}
