#include <ESP32Servo.h>
#include <PS4Controller.h>


//alterar os pinos conforme necessidade do controlador ex esp32 ou aruino

#Define servoPin 18

#define in1 5
#define in2 6
#define ena 3

#define velmin 50
#define velmax 200

//alterar com o valor do controle
#define mac "1a:2b:3c:01:01:01"

char direcao = 'f';
int vel = 0;
int mapvel = 0;
String leitura = "0";
int posicaoVoltante = 90;


Servo volante;

void setup() {
  Serial.begin(115200);

  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(ena,OUTPUT);
  volante.attach(servoPin);
  volante.write(posicaoVoltante); //valor de refencia do angulo do cervo

  PS4.begin(mac);
}

void andar(int velocidade,char sentido){
  if (sentido == 'f'){   //frente
    digitalWrite(in1,HIGH);
    digitalWrite(in2,LOW);
  }
  else if (sentido == 'r'){
    digitalWrite(in1,LOW);
    digitalWrite(in2,HIGH);
  }
  if (vel<50){
    vel +=100;
  }
  else{
    vel+=50;
  }
}

void frear(){
  if (vel >= 50){
    vel-=50;
  }
}

void virar(int val){
if (val > 0 && (posicaoVoltante < 120))
{
  posicaoVoltante+=5;
  volante.write(posicaoVoltante);
}
if (val < 0 && (posicaoVoltante>60))
  {
    posicaoVoltante-=5;
  volante.write(posicaoVoltante);
  }
}

void loop() {
if(PS4.isConnected()){
  int x = PS4.LStickX(); // Valor do analógico esquerdo no eixo X (-128 a 127)
  int angulo = map(x,-128,127,60,120);
  volante.write(angulo);//posição do volante
  if (PS4.Square()) { // Ré
    if (direcao == 'r')
      andar(vel,direcao);
    else
    frear();
    if (vel == 0)
      direcao = 'r';
    
  } else if (PS4.Cross()) { // Acelera o motor para frente
      if (direcao == 'f'){
        andar(vel,direcao);
      }
      else {
        frear();
        if (vel == 0)
        direcao = 'f';
      }
  } else {
    // Se nenhum botão for pressionado, para o motor
    frear();
  }
/*
  leitura = Serial.readString();
  leitura.trim();
  if (leitura == "1"){   //Frente
    if (direcao == 'f'){
      andar(vel,direcao);
    }
    else {
      frear();
      if (vel == 0)
      direcao = 'f';
    }
    

  }

  else if (leitura == "2"){  //Ré
  if (direcao == 'r'){
    andar(vel,direcao);
    }
  else {
     frear();
    if (vel == 0)
      direcao = 'r';

    }
  }
  else if (leitura == "3")  //parar
    vel=0;
  */
//atualização de velocidade
analogWrite(ena,vel);

// bloco de leitrua
  if (leitura != ""){
    Serial.print(leitura);
    Serial.print("   ");
    Serial.print(vel);
    Serial.println("");
  }
  delay(50);
  
}else {
  Serial.println("Aguardando conexão com o controle.")
  delay(1000);
}
}