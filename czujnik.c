#include <LiquidCrystal.h> //Do��czenie bilbioteki
LiquidCrystal lcd(2, 3, 4, 5, 6, 7); //Informacja o pod��czeniu nowego wy�wietlacza
 int Trig = 10;  //pin 2 Arduino po��czony z pinem Trigger czujnika
int Echo = 11;  //pin 3 Arduino po��czony z pinem Echo czujnika
int CM;        //odleg�o�� w cm
long CZAS;     //d�ugo�� powrotnego impulsu w uS
void setup() {
  lcd.begin(16, 2); //Deklaracja typu
  pinMode(Trig, OUTPUT);                     
  pinMode(Echo, INPUT);
}
 
void loop() {
  
  lcd.setCursor(3, 0); // wyswietlenie od 3 krateczki
  lcd.print("Odleglosc:");
  pomiar_odleglosci(); //pomiar odleg�o�ci
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
  CM = CZAS / 58;                //szeroko�� odbitego impulsu w uS podzielone przez 58 to odleglosc w cm - dokumentacja
}
