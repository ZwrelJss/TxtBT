#include <LiquidCrystal.h> //Biblioteca que proporciona funciones y definiciones para controlar pantallas lcd
String inputString = "0";
String ori = "1";
String msj = "0";
LiquidCrystal lcd(7,6,5,4,3,2);
void setup() {
  Serial.begin(9600);
  lcd.begin(16,2);
}

void loop() {
  String inputString;
  if(Serial.available()){
    inputString = Serial.readStringUntil('\n'); // Leer la cadena de caracteres hasta encontrar un salto de línea
    inputString.trim(); // Eliminar espacios en blanco al inicio y al final de la cadena
    Serial.print(inputString);
    if(inputString == "1" || inputString == "2"){
      ori = inputString;
      //Serial.print("Entramos a seleccion");
    }else{  
      msj = inputString;
    }
  }
  if(ori == "1"){
    lcd.setCursor(0,0);
    lcd.print(msj);
    lcd.scrollDisplayLeft(); // Desplazar el contenido del LCD hacia la izquierda
    delay(300);
  }else{
    lcd.setCursor(0,0);
    lcd.print(msj);
    lcd.scrollDisplayRight(); // Desplazar el contenido del LCD hacia la izquierda
    delay(300);
  }
}
