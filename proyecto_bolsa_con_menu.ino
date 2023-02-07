#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#include <Keypad.h>


LiquidCrystal_I2C lcd(0x27, 20, 4);


const byte ROWS = 4; //filas
const byte COLS = 4; //columnas
char hexaKeys[ROWS][COLS] = {
  {'1', '4', '7', '*'},
  {'2', '5', '8', '0'},
  {'3', '6', '9', '#'},
  {'A', 'B', 'C', 'D'},
};
byte rowPins[ROWS] = {9, 8, 7, 6}; //pines de filas
byte colPins[COLS] = {13, 12, 11, 10};// pines de columnas

//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);



int umbral = 600;
int lecturasensor1 = 0;
int lecturasensor2 = 0;
int lecturasensor3 = 0;
int lecturasensor4 = 0;
int cantidadgolpes = 0;





void setup() {
 pinMode(3,OUTPUT);
pinMode(2,INPUT);


pinMode(4,INPUT);
  lcd.init();
  lcd.init();
  lcd.backlight();//luz de fondo . lcd.noBackligh(); para los de fondo apagada
 
    lcd.setCursor(0,0);
    lcd.print("CONTADOR DE GOLPES");
    lcd.setCursor(0,1);
    lcd.print("seleccione tiempo");
    lcd.setCursor(0,2);
    lcd.print("1=1min,2=2min,");
    lcd.setCursor(0,3);
    lcd.print("3=3min,etc");


  
}
void loop() { 


  
  char customKey = customKeypad.getKey();
   if (customKey) {
      lcd.print(customKey); }

 



 
    if (customKey == '#') {
      digitalWrite(3,LOW);
      lcd.clear();}    

   if(customKey == 'A'){
    lcd.clear();
   
    lcd.setCursor(0,0);
    lcd.print("CONTADOR DE GOLPES");
    lcd.setCursor(0,1);
    lcd.print("seleccione tiempo");
    lcd.setCursor(0,2);
    lcd.print("1=1min,2=2min,");
    lcd.setCursor(0,3);
    lcd.print("3=3min,etc");
   
    }


   //1min
   
  if(customKey == '1'){
    for(int temp=0; temp<61;temp++){
      lcd.clear();
      digitalWrite(3,LOW);
      lcd.print("S1 ");
     lcd.print(lecturasensor1);
     lcd.setCursor(11,0);
     lcd.print("TEMP:1Min");//imprime tiempo seleccionado
     lcd.setCursor(0,1);
     lcd.print("S2 ");
     lcd.print(lecturasensor2);
     lcd.setCursor(13,1);  
     lcd.print(temp); 
     lcd.print(" Seg");
     
     lcd.setCursor(0,2);
     lcd.print("S3 ");
     lcd.print(lecturasensor3);
     lcd.setCursor(0,3);
     lcd.print("S4 ");
     lcd.print(lecturasensor4);
     lcd.setCursor(12,2);
     lcd.print("golpes");
     lcd.setCursor(12,3);
     lcd.print(cantidadgolpes);
 
 
      
      
  if (digitalRead(2)==HIGH ||digitalRead(4)==HIGH) {
 
    cantidadgolpes = cantidadgolpes + 1;
    }
      
   if(temp==60){
    digitalWrite(3,HIGH);}
     delay(1000);}
   
  
}

      


//se copiaria lo mismo para cada tecla del matricial solo cambiar los valores
  //2min
   
  if(customKey == '2'){
    for(int temp=0; temp<121;temp++){
      lcd.clear();
      lcd.print("S1 ");
     lcd.print(lecturasensor1);
     lcd.setCursor(11,0);
     lcd.print("TEMP:2Min");//imprime tiempo seleccionado
     lcd.setCursor(0,1);
     lcd.print("S2 ");
     lcd.print(lecturasensor2);
     lcd.setCursor(13,1);  
     lcd.print(temp); 
     lcd.print(" Seg");
     
     lcd.setCursor(0,2);
     lcd.print("S3 ");
     lcd.print(lecturasensor3);
     lcd.setCursor(0,3);
     lcd.print("S4 ");
     lcd.print(lecturasensor4);
     lcd.setCursor(12,2);
     lcd.print("golpes");
     lcd.setCursor(12,3);
     lcd.print(cantidadgolpes);
 
        if (digitalRead(2)==HIGH ||digitalRead(4)==HIGH) {
 
    cantidadgolpes = cantidadgolpes + 1;
    }
     if(temp==120){
    digitalWrite(3,HIGH);}
     delay(1000);}
   
   
       
      }

  //3min
   
  if(customKey == '3'){
    for(int temp=0; temp<181;temp++){
      lcd.clear();
      lcd.print("S1 ");
     lcd.print(lecturasensor1);
     lcd.setCursor(11,0);
     lcd.print("TEMP:3Min");//imprime tiempo seleccionado
     lcd.setCursor(0,1);
     lcd.print("S2 ");
     lcd.print(lecturasensor2);
     lcd.setCursor(13,1);  
     lcd.print(temp); 
     lcd.print(" Seg");
     
     lcd.setCursor(0,2);
     lcd.print("S3 ");
     lcd.print(lecturasensor3);
     lcd.setCursor(0,3);
     lcd.print("S4 ");
     lcd.print(lecturasensor4);
     lcd.setCursor(12,2);
     lcd.print("golpes");
     lcd.setCursor(12,3);
     lcd.print(cantidadgolpes);
 
       if (digitalRead(2)==HIGH ||digitalRead(4)==HIGH) {
 
    cantidadgolpes = cantidadgolpes + 1;
    }
    if(temp==180){
    digitalWrite(3,HIGH);}
     delay(1000);}
     
       
      }

  //4min
   
  if(customKey == '4'){
    for(int temp=0; temp<241;temp++){
      lcd.clear();
      lcd.print("S1 ");
     lcd.print(lecturasensor1);
     lcd.setCursor(11,0);
     lcd.print("TEMP:4Min");//imprime tiempo seleccionado
     lcd.setCursor(0,1);
     lcd.print("S2 ");
     lcd.print(lecturasensor2);
     lcd.setCursor(13,1);  
     lcd.print(temp); 
     lcd.print(" Seg");
     
     lcd.setCursor(0,2);
     lcd.print("S3 ");
     lcd.print(lecturasensor3);
     lcd.setCursor(0,3);
     lcd.print("S4 ");
     lcd.print(lecturasensor4);
     lcd.setCursor(12,2);
     lcd.print("golpes");
     lcd.setCursor(12,3);
     lcd.print(cantidadgolpes);
   if (digitalRead(2)==HIGH ||digitalRead(4)==HIGH) {
 
    cantidadgolpes = cantidadgolpes + 1;
    }
   
    if(temp==240){
    digitalWrite(3,HIGH);}
     delay(1000);}
       
      }
  //5min
   
  if(customKey == '5'){
    for(int temp=0; temp<301;temp++){
      lcd.clear();
      lcd.print("S1 ");
     lcd.print(lecturasensor1);
     lcd.setCursor(11,0);
     lcd.print("TEMP:5Min");//imprime tiempo seleccionado
     lcd.setCursor(0,1);
     lcd.print("S2 ");
     lcd.print(lecturasensor2);
     lcd.setCursor(13,1);  
     lcd.print(temp); 
     lcd.print(" Seg");
     
     lcd.setCursor(0,2);
     lcd.print("S3 ");
     lcd.print(lecturasensor3);
     lcd.setCursor(0,3);
     lcd.print("S4 ");
     lcd.print(lecturasensor4);
     lcd.setCursor(12,2);
     lcd.print("golpes");
     lcd.setCursor(12,3);
     lcd.print(cantidadgolpes);
 
        if (digitalRead(2)==HIGH ||digitalRead(4)==HIGH) {
 
    cantidadgolpes = cantidadgolpes + 1;
    }
     if(temp==300){
    digitalWrite(3,HIGH);}
     delay(1000);}
   
    
       
      }
  
   //6min
   
  if(customKey == '6'){
    for(int temp=0; temp<361;temp++){
      lcd.clear();
      lcd.print("S1 ");
     lcd.print(lecturasensor1);
     lcd.setCursor(11,0);
     lcd.print("TEMP:6Min");//imprime tiempo seleccionado
     lcd.setCursor(0,1);
     lcd.print("S2 ");
     lcd.print(lecturasensor2);
     lcd.setCursor(13,1);  
     lcd.print(temp); 
     lcd.print(" Seg");
     
     lcd.setCursor(0,2);
     lcd.print("S3 ");
     lcd.print(lecturasensor3);
     lcd.setCursor(0,3);
     lcd.print("S4 ");
     lcd.print(lecturasensor4);
     lcd.setCursor(12,2);
     lcd.print("golpes");
     lcd.setCursor(12,3);
     lcd.print(cantidadgolpes);
 
       if (digitalRead(2)==HIGH ||digitalRead(4)==HIGH) {
 
    cantidadgolpes = cantidadgolpes + 1;
    }
     if(temp==360){
    digitalWrite(3,HIGH);}
     delay(1000);}
   

       
      }
  //7min
   
  if(customKey == '7'){
    for(int temp=0; temp<=421;temp++){
      lcd.clear();
      lcd.print("S1 ");
     lcd.print(lecturasensor1);
     lcd.setCursor(11,0);
     lcd.print("TEMP:7Min");//imprime tiempo seleccionado
     lcd.setCursor(0,1);
     lcd.print("S2 ");
     lcd.print(lecturasensor2);
     lcd.setCursor(13,1);  
     lcd.print(temp); 
     lcd.print(" Seg");
     
     lcd.setCursor(0,2);
     lcd.print("S3 ");
     lcd.print(lecturasensor3);
     lcd.setCursor(0,3);
     lcd.print("S4 ");
     lcd.print(lecturasensor4);
     lcd.setCursor(12,2);
     lcd.print("golpes");
     lcd.setCursor(12,3);
     lcd.print(cantidadgolpes);
 
        if (digitalRead(2)==HIGH ||digitalRead(4)==HIGH) {
 
    cantidadgolpes = cantidadgolpes + 1;
    }
     if(temp==420){
    digitalWrite(3,HIGH);}
     delay(1000);}
   
  
       
      }
  //8min
   
  if(customKey == '8'){
    for(int temp=0; temp<481;temp++){
      lcd.clear();
      lcd.print("S1 ");
     lcd.print(lecturasensor1);
     lcd.setCursor(11,0);
     lcd.print("TEMP:8Min");//imprime tiempo seleccionado
     lcd.setCursor(0,1);
     lcd.print("S2 ");
     lcd.print(lecturasensor2);
     lcd.setCursor(13,1);  
     lcd.print(temp); 
     lcd.print(" Seg");
     
     lcd.setCursor(0,2);
     lcd.print("S3 ");
     lcd.print(lecturasensor3);
     lcd.setCursor(0,3);
     lcd.print("S4 ");
     lcd.print(lecturasensor4);
     lcd.setCursor(12,2);
     lcd.print("golpes");
     lcd.setCursor(12,3);
     lcd.print(cantidadgolpes);
    if (digitalRead(2)==HIGH ||digitalRead(4)==HIGH) {
 
    cantidadgolpes = cantidadgolpes + 1;
    }
     if(temp==480){
    digitalWrite(3,HIGH);}
     delay(1000);}
   
  
       
      }
       //9min
   
  if(customKey == '9'){
    for(int temp=0; temp<541;temp++){
      lcd.clear();
      lcd.print("S1 ");
     lcd.print(lecturasensor1);
     lcd.setCursor(11,0);
     lcd.print("TEMP:9Min");//imprime tiempo seleccionado
     lcd.setCursor(0,1);
     lcd.print("S2 ");
     lcd.print(lecturasensor2);
     lcd.setCursor(13,1);  
     lcd.print(temp); 
     lcd.print(" Seg");
     
     lcd.setCursor(0,2);
     lcd.print("S3 ");
     lcd.print(lecturasensor3);
     lcd.setCursor(0,3);
     lcd.print("S4 ");
     lcd.print(lecturasensor4);
     lcd.setCursor(12,2);
     lcd.print("golpes");
     lcd.setCursor(12,3);
     lcd.print(cantidadgolpes);
 
    if (digitalRead(2)==HIGH ||digitalRead(4)==HIGH) {
 
    cantidadgolpes = cantidadgolpes + 1;
    }
     if(temp==540){
    digitalWrite(3,HIGH);}
     delay(1000);}
   

       
      }
      }
      

