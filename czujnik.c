#include <LiquidCrystal.h> //Dołączenie bilbioteki
LiquidCrystal lcd(2, 3, 4, 5, 6, 7); //Informacja o podłączeniu nowego wyświetlacza
 int Trig = 10;  //pin 2 Arduino połączony z pinem Trigger czujnika
int Echo = 11;  //pin 3 Arduino połączony z pinem Echo czujnika
int CM;        //odległość w cm
long CZAS;     //długość powrotnego impulsu w uS
void setup() {
  lcd.begin(16, 2); //Deklaracja typu
  pinMode(Trig, OUTPUT);                     
  pinMode(Echo, INPUT);
}
 
void loop() {
  
  lcd.setCursor(3, 0); // wyswietlenie od 3 krateczki
  lcd.print("Odleglosc:");
  pomiar_odleglosci(); //pomiar odległości
  lcd.setCursor(6, 1);
   lcd.print(CM);
  lcd.setCursor(9, 1);

}
void pomiar_odleglosci ()
{
  digitalWrite(Trig, HIGH);       //ustawienie stanu wysokiego na 10 uS - impuls inicjalizujacy - patrz dokumentacja
  delayMicroseconds(10);
  digitalWrite(Trig, LOW);
  CZAS = pulseIn(Echo, HIGH);
  CM = CZAS / 58;                //szerokość odbitego impulsu w uS podzielone przez 58 to odleglosc w cm - dokumentacja
}
