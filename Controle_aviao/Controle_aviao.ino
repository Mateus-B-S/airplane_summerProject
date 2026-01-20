//#include <Servo.h>

int YJ1 = A0;
int XJ1 = A1;
int YJ2 = A2;
//int XJ2 = A3;

int XJ1_val, YJ1_val /*, XJ2_val*/, YJ2_val;

//no joystick 1
int profundor = 6;
int asas = 10;

//no Joystick 2
//int leme = 9;
//int acelerador = 11;

//int prof_pos;
//int asas_pos;

//int leme_pos;
//int acel_pos;

//Servo prof_servo;
//Servo asas_servo;
//Servo leme_servo;
//Servo acel_servo;

void setup() {
  Serial.begin(9600);
  pinMode(XJ1, INPUT);
  pinMode(YJ1, INPUT);
  //pinMode(XJ2, INPUT);
  pinMode(YJ2, INPUT);

  //prof_servo.attach(profundor);
  //asas_servo.attach(asas);
  //leme_servo.attach(leme);
  //acel_servo.attach(acelerador);

};

void loop() {
  // put your main code here, to run repeatedly:

  XJ1_val = analogRead(XJ1);
  YJ1_val = analogRead(YJ1);
  XJ2_val = analogRead(XJ2);
  YJ2_val = analogRead(YJ2);

  Serial.print("asas: ");
  Serial.print(XJ1_val);
  Serial.print(" | profundor: ");
  Serial.print(YJ1_val);
  Serial.print(" | aceleracao: ");
  Serial.println(YJ2_val );


  /*No joystick 1, o X representa as asas, e o Y, o profundor
  asas_pos = map(XJ1_val, 0, 1023, 0, 180);
  prof_pos = map(YJ1_val, 0, 1023, 0, 180); //depois mudar os valores para algo mais coerente

  // No joystick 2, o X representa o leme, e o Y, o acelerador
  leme_pos = map(XJ2_val, 0, 1023, 0, 180);
  acel_pos = map(YJ2_val, 0, 1023, 0, 180);// denovo, mudar os valores para algo mais real

  asas_servo.write(asas_pos);
  prof_servo.write(prof_pos);
  leme_servo.write(leme_pos);
  acel_servo.write(acel_pos);


 */
  


 delay(100);
};

