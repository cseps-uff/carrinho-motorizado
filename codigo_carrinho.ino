#define in1 5
#define in2 6
#define ena 3

#define velmin 50
#define velmax 200
char direcao = 'f';

int vel =0;
int mapvel =0;
String leitura = "0";


void setup() {
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(ena,OUTPUT);
  Serial.begin(115200);
  Serial.println(vel);

}


void andar(int velocidade,char sentido){
  if (sentido == 'f'){   //frente
    digitalWrite(in1,1);
    digitalWrite(in2,0);
  }
  else if (sentido == 'r'){
    digitalWrite(in1,0);
    digitalWrite(in2,1);
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


void loop() {
  leitura = Serial.readString();
  leitura.trim();
  if (leitura == "1"){   //frente
    if (direcao == 'f'){
      andar(vel,direcao);
    }
    else {
      digitalWrite(in1,0);
      digitalWrite(in2,0);
      direcao = 'f';
      vel=0;
    }
    Serial.print(leitura);
    analogWrite(ena,vel);
    Serial.print("   ");
    Serial.print(vel);
    Serial.println("");
  }
  else if (leitura == "2"){  //costas
  if (direcao == 'r'){
    andar(vel,direcao);
    }
  else {
    digitalWrite(in1,0);
    digitalWrite(in2,0);
    direcao = 'r';
    vel=0;
    }
    Serial.print(leitura);
    analogWrite(ena,vel);
    Serial.print("   ");
    Serial.print(vel);
    Serial.println("");
  }
  else if (leitura == "3"){  //parar
    frear();
    Serial.print(leitura);
    analogWrite(ena,vel);
    Serial.print("   ");
    Serial.print(vel);
    Serial.println("");
  }
  
  

}