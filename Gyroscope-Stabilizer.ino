//Gyroscope stabilizer, Brandon Noble 2020

//Currently sensing angles and moving a servo to the same angle that is measured

//--------------------------------------------------------------------------------------------
#include <Servo.h>

Servo xServo;

#define x A0
  //0 deg ~651
  //90 deg ~687
  //-90 deg ~615
  
#define y A1
  //0 deg ~644
  //90 deg ~681
  //-90 deg ~606
  
#define z A2 //currently unused

double xRead;
double yRead;
int pos = 90; //default position of the servo (0-180, 90 in the middle)

//--------------------------------------------------------------------------------------------

void setup() {
  Serial.begin(9600); //enable serial communication, used to monitor on computer
  
  pinMode(x, INPUT); //configure pins for analog read
  pinMode(y, INPUT);
  pinMode(z, INPUT);
  xServo.attach(A5); //configure servo
  xServo.write(pos);

  digitalWrite(x, HIGH); //enable pull up resistors on the inputs
  digitalWrite(y, HIGH);
  digitalWrite(z, HIGH);
}

//--------------------------------------------------------------------------------------------

void loop() {

  //Average 50 analog readings to reduce noise in signal
  xRead = 0;
  yRead = 0;
  for(int i =0; i<50; i++) {
    xRead += analogRead(x);
    yRead += analogRead(y);
  }
  xRead /= 50;
  yRead /= 50;
  
  //----X AXIS----
  Serial.println("--X--");
  if(649 < xRead && xRead < 652) { //ignore if ~ 0 deg
    xServo.write(90);
    Serial.println(0);
  }
  else if(xRead >= 652) { //convert for + angle up to 90 deg
    pos = ( floor(90*((xRead-651.0)/(687.0-651.0))) );
    if(pos >= 90) //prevent servo from spinning too far
      pos=180;
    xServo.write(pos+90);
    Serial.println(pos);
  }
  else { //convert for - angle up to 90 deg
    pos = ( floor(-90-90*((615.0-xRead)/(651.0-615.0))) );
    if(pos <= -90) //prevent servo from spinning too far
      pos = -90;
    xServo.write(pos+90);
    Serial.println(pos);
  }

  //----Y AXIS----
  Serial.println("--Y--");
  if(642 < yRead && yRead < 646) { //ignore if ~ 0 deg
    Serial.println(0);
  }
  else if(yRead >= 646) { //convert for + angle up to 90 deg
    Serial.println( floor(90*((yRead-644.0)/(681.0-644.0))) );
  }
  else { //convert for - angle up to 90 deg
    Serial.println( floor(-90-90*((606.0-yRead)/(644.0-606.0))) );
  }
    
  delay(100); //short delay to help monitor data
}
