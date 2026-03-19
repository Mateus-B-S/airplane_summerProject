#include <SPI.h>
#include <RF24.h>
#include <nRF24L01.h>



int YVector_JoystickOne = A0;
int XVector_JoystickOne = A1;
int YVector_JoystickTwo = A2;
int XVector_JoystickTwo = A3;

int XVector_JoystickOne_val, YVector_JoystickOne_val /*, XVector_JoystickTwo_val*/, YVector_JoystickTwo_val;

//"mensagem" mandada pelo trasmissor e que irá ser recebida pelo receptor (no avião), PRECISA SER O MESMO VALOR!!
const byte endereco[6] ="00001";



RF24 radio(9, 10);

struct Dados {
  int profundor;
  int asas;
  int motor;
};

Dados comando;

void resetComandos() {  //inializa os motores para suas posições certas.
  comando.profundor = 120;
  comando.asas = 0;
  comando.motor = 0;
};

void setup() {
  pinMode(XVector_JoystickOne, INPUT);
  pinMode(YVector_JoystickOne, INPUT);
  //pinMode(XVector_JoystickTwo, INPUT);
  pinMode(YVector_JoystickTwo, INPUT);
  radio.begin();
  radio.setAutoAck(false);  //não verifica se recebeu os dados automaticamente, fazendo a comunicação mais rápida
  radio.setDataRate(RF24_250KBPS);
  radio.openWritingPipe(endereco);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
  resetComandos();
};


void loop() {
  // put your main code here, to run repeatedly:

  XVector_JoystickOne_val = analogRead(XVector_JoystickOne);
  YVector_JoystickOne_val = analogRead(YVector_JoystickOne);
  //XVector_JoystickTwo_val = analogRead(XVector_JoystickTwo);
  YVector_JoystickTwo_val = analogRead(YVector_JoystickTwo);

  comando.profundor = YVector_JoystickOne_val;
  comando.asas = XVector_JoystickOne_val;
  comando.motor = YVector_JoystickTwo_val;

  

  radio.write(&comando, sizeof(Dados));


  delay(15);
};