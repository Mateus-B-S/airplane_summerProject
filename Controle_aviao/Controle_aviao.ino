//#include <Servo.h>

int YVector_JoystickOne = A0;
int XVector_JoystickOne = A1;
int YVector_JoystickTwo = A2;
//int XVector_JoystickTwo = A3;

int XVector_JoystickOne_val, YVector_JoystickOne_val /*, XVector_JoystickTwo_val*/, YVector_JoystickTwo_val;

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
  pinMode(XVector_JoystickOne, INPUT);
  pinMode(YVector_JoystickOne, INPUT);
  //pinMode(XVector_JoystickTwo, INPUT);
  pinMode(YVector_JoystickTwo, INPUT);

  //prof_servo.attach(profundor);
  //asas_servo.attach(asas);
  //leme_servo.attach(leme);
  //acel_servo.attach(acelerador);

};

void loop() {
  // put your main code here, to run repeatedly:

  XVector_JoystickOne_val = analogRead(XVector_JoystickOne);
  YVector_JoystickOne_val = analogRead(YVector_JoystickOne);
  XVector_JoystickTwo_val = analogRead(XVector_JoystickTwo);
  YVector_JoystickTwo_val = analogRead(YVector_JoystickTwo);

  Serial.print("asas: ");
  Serial.print(XVector_JoystickOne_val);
  Serial.print(" | profundor: ");
  Serial.print(YVector_JoystickOne_val);
  Serial.print(" | aceleracao: ");
  Serial.println(YVector_JoystickTwo_val );


  /*No joystick 1, o X representa as asas, e o Y, o profundor
  asas_pos = map(XVector_JoystickOne_val, 0, 1023, 0, 180);
  prof_pos = map(YVector_JoystickOne_val, 0, 1023, 0, 180); //depois mudar os valores para algo mais coerente

  // No joystick 2, o X representa o leme, e o Y, o acelerador
  leme_pos = map(XJ2_val, 0, 1023, 0, 180);
  acel_pos = map(YVector_JoystickTwo_val, 0, 1023, 0, 180);// denovo, mudar os valores para algo mais real

  asas_servo.write(asas_pos);
  prof_servo.write(prof_pos);
  leme_servo.write(leme_pos);
  acel_servo.write(acel_pos);


 */
  


 delay(100);
};
