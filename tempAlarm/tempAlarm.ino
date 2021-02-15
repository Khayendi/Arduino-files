int led = 4;
int photoresistor=0;
void setup() {
  // put your setup code here, to run once:
pinMode(8, OUTPUT);// configure pin of buzzer
pinMode(4, OUTPUT);
 Serial.begin(9600);// configure baud rate to 9600 bps 
 
}

void loop() {
  // put your main code here, to run repeatedly:
float sinVal;
int toneVal;
unsigned long tepTimer ; 

int val;//save the value of LM35
 double data;// save the converted value of temperature
 val=analogRead(0);//Connect LM35 to analog pin and read value from it
 data = (double) val * (5/10.24);//Convert the voltage value to temperature value

 if(data>50){//If temperature is higher than 20, the buzzer starts to make sound.
  digitalWrite(led, HIGH);
   for(int x=0; x<180; x++){
 //Convert sin function to radian
 sinVal = (sin(x*(3.1412/180)));
 //Use sin function to generate frequency of sound
 toneVal = 2000+(int(sinVal*1000));
 //Configure the buzzer pin 8
 tone(8, toneVal);
 delay(2);
 }
 } else { // If the temperature is lower than 27, turn off the buzzer
  digitalWrite(led,LOW);
 noTone(8); // Turn off the buzzer
 }
 if(millis() - tepTimer > 50){// Every 500 ms, serial port outputs temperature value.
 tepTimer = millis();
 Serial.print("temperature: "); // Serial port outputs temperature
 Serial.print(data);// Serial port outputs temperature value
 Serial.println("C");// Serial port output temperature unit
 }
}
