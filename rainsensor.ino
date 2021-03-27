#include <AFMotor.h>
#include <DHT.h>
int rainSensor = 6;
const int DHTPIN = A2; 
const int DHTTYPE = DHT22;
DHT dht(DHTPIN, DHTTYPE);
AF_DCMotor motor1(1, MOTOR12_64KHZ);
AF_DCMotor motor2(2, MOTOR12_64KHZ);
void setup() {
  pinMode(rainSensor,INPUT);
  motor1.setSpeed(230);
  motor2.setSpeed(230);
  dht.begin();
  Serial.begin(9600);
}

void loop() {
  int value = digitalRead(rainSensor);
  float h = dht.readHumidity();
  if (value == HIGH||h ) {
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  } else {
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  }
  }
