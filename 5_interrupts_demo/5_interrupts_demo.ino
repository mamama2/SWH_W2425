/*
   Sketching mit Hardware
  DMP - SWH - WS2425
  - Interrupts Demo. Termin 5
 
  This project demonstrates how to debounce a pushbutton and avoid unexpected results
  by: Marcos Martinez
*/

const int Taster = 2;           // Der Taster wurde an Pin 2 angeschlossen
const int LED = 13;             // Die LED wurde an Pin 13 angeschlossen
volatile int TasterStatus = 0;  // Variable die den Status des Taster ausliest, wird der sog. "Vektor" 0 zugewiesen
// Taster Anschluss an Pin 2 entspricht dem Vektor 0   (hier der Fall)
// Taster Anschluss an Pin 3 entspricht dem Vektor 1

void setup() {
  pinMode(LED, OUTPUT);                           // Hier wird die LED als OUTPUT definiert
  pinMode(Taster, INPUT);                         // Hier wird der Taster als INPUT definiert
  attachInterrupt(0, TasterUnterbricht, CHANGE);  // Hier findet die Einbindung unseres Interrupt-Befehls statt
}
void loop() {
  // Hier leer, der eigentliche loop() Teil findet nun in der "void TasterUnterbricht()" statt
}
void TasterUnterbricht() {             // Sobald die Unterbrechung "TasterUnterbricht" (der Wert am Pin ändert sich [CHANGE])...
  TasterStatus = digitalRead(Taster);  // ... wird der TasterStatus neu definiert ("volatile"). Die neue Definition geschieht durch das Auslesen des Tasters an Pin 2. ...
  digitalWrite(LED, TasterStatus);     // ... [digitalWrite(pin,Status)] Nun wird die LED (Pin13) in den zuvor definierten Tasterstatus versetzt.
}
