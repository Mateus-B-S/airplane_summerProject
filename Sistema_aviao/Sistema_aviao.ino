#include <Servo.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

int nivel_aceleracao;
int angulo_asas;
int angulo_profundor;
Servo motor;
Servo motor_asas;
Servo motor_profundor; 
unsigned long previousMillis = 0;  //timer inicial para o sinal pwm

const byte endereco[6] = "00001";

RF24 radio(9,10); //CE, CSN


struct Acoes {
  int profundor;
  int asas;
  int motor;
};

Acoes dados;

void resetarAcoes()
{
  dados.profundor = 300;   //ligeiramente para baixo
  dados.asas = 600;       //ligeiramente para direita
  dados.motor = 512;    // Centro (0-1023)
};


void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.setAutoAck(false);
  radio.setDataRate(RF24_250KBPS);
  radio.openReadingPipe(0,endereco);
  radio.setPALevel(RF24_PA_MIN);
  //we start the radio comunication
  radio.startListening();

  motor_profundor.attach(3);
  motor_asas.attach(5);
  motor.attach(6);
  resetarAcoes();
}

unsigned long ultimaVezRecebido = 0;


void loop() {
  // Verifica se recebeu dados do rádio
  if ( radio.available() ) {
    radio.read(&dados, sizeof(Acoes));
    ultimaVezRecebido = millis();
  }
  
  // Se passou mais de 500ms sem receber sinal, reseta
  if (millis() - ultimaVezRecebido > 500) {
    resetarAcoes();
  }
  
  // Mapeia os valores para o range dos servos
  angulo_profundor = map(dados.profundor, 0, 1023, 15, 120);
  angulo_asas = map(dados.asas, 0, 1023, 0, 130);
  nivel_aceleracao = map(dados.motor, 0, 1023, 15, 120);

  // Escreve os valores mapeados aos servos
  motor_profundor.write(angulo_profundor);
  motor_asas.write(angulo_asas);
  motor.write(nivel_aceleracao);
   
  Serial.print("Profundor: ");
  Serial.print(angulo_profundor);
  Serial.print("| asas: ");
  Serial.print(angulo_asas);
  Serial.print("| motor: ");
  Serial.println(nivel_aceleracao);
  
  delay(50);
}