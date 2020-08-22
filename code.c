int Contrast=75;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); 

void setup() {


  pinMode(A3,INPUT);
  pinMode(A4,OUTPUT);
  pinMode(A5,OUTPUT);
  pinMode(8,OUTPUT);
  digitalWrite(A5,HIGH);
  digitalWrite(A4,LOW);
  Serial.begin(9600);

  analogWrite(6,Contrast);
  lcd.begin(16, 2);
     

  

}

void loop() {
 Serial.println(analogRead(A3));
 if(analogRead(A3) <= 700){
  
  
  digitalWrite(8, HIGH);
  lcd.setCursor(0, 0);
  lcd.print("OBSTACLE ALERT");

  }
 else {
  noTone(buzzer);
 }

  
  
  if (analogRead(A0) <= threshold) {
   lcd.setCursor(0, 1);
   lcd.print("ELEPHANT DET.");
   Serial.println(analogRead(A3));
   tone(8, 450);
    
  }
  
  else {
    noTone(buzzer);
  }
}
