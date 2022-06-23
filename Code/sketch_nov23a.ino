/*
 * @Authors
 * Ivan Olivari
 * Alexander Velez
 * Fabio Padilla
 */

/*
 Pin declaration and value declaration
 */
int m1 = 2;
int m1g = 3;
int m2 = 4;
int m2g = 5;
int sensorPin = A0;
int sensorPin1 = A1;
int sensorPin2 = A2;
int sensorValue = 0;
int sensorValue1 = 0;
int sensorValue2 = 0;
int trigger = 9;
int echo = 10;
long duration;
int distance;
//int buzzer=8

/*
 Stop method to shutdown the motors
 */
 
void Stop(){
   digitalWrite(m1,LOW);
  digitalWrite(m1g,LOW);
   digitalWrite(m2,LOW);
  digitalWrite(m2g,LOW);
}
/*
 * If the car moves to the left, the left tire 
 * will move forward and 
 * the right tire back to turn.
 */
void left(){
     digitalWrite(m1,LOW);
  digitalWrite(m1g,HIGH);
   digitalWrite(m2,HIGH);
  digitalWrite(m2g,LOW);
}
/*
 * If the car moves to the right, the right tire 
 * will move forward and 
 * the left tire back to turn.
 */
void right(){
     digitalWrite(m1,HIGH);
  digitalWrite(m1g,LOW);
   digitalWrite(m2,LOW);
  digitalWrite(m2g,HIGH);
}

/*
 * The tires of the car will move forward
 */
void front(){
    digitalWrite(m1,HIGH);
  digitalWrite(m1g,LOW);
   digitalWrite(m2,HIGH);
  digitalWrite(m2g,LOW);
}

/*
 * Here the outputs and inputs of the program and 
 * the serial number of the motors are declared.
 */
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); 
  pinMode(m1,OUTPUT);
  pinMode(m1g,OUTPUT);
  pinMode(m2,OUTPUT);
  pinMode(m2g,OUTPUT);
  //pinMode(buzzer,OUTPUT);
  pinMode(trigger,OUTPUT);
  pinMode(echo,INPUT);
}

void loop() {
do{
  //noTone();
  digitalWrite(trigger,LOW);
  delay(5);
  digitalWrite(trigger,HIGH);
  delayMicroseconds(15);
  digitalWrite(trigger,LOW);
  duration = pulseIn(echo,HIGH);
  distance = duration*0.034/2; //Formula for the conversion to centimeters.
  
  sensorValue = analogRead(sensorPin); 
  Serial.println("Sensor 1: ");
Serial.println(sensorValue);

//delay(5);
sensorValue1 = analogRead(sensorPin1); 
Serial.println("Sensor 2: ");
Serial.println(sensorValue1);

//delay(5);
sensorValue2 = analogRead(sensorPin2); 

Serial.println(sensorValue2);

//delay(5); 
Serial.println("Distance: ");
  Serial.println(distance);
if(sensorValue > 800) {

  front();
}

else if (sensorValue1 > 700){
  
  right();
}

else if(sensorValue2 > 800){
  
  left();
}
else {
  Stop();
}

}while(distance >15);

if(distance<14)
{
 //Tone(buzzer,100);
  Stop();
}

}
