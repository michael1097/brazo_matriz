#include <Servo.h>
#define pausa 40
Servo base,avance,altura,garra;

int mov[4][20]={{90,85,80,75,70,65,60,55,50,45,40,35,30,25,20,15,10,5,1},
                {90,95,100,105,110,115,120,125,130,135,140,145,150,155,160,165,170,175},
                {180,175,170,165,160,155,150,145,140,135,130,125,120},
                {47,45,43,41,39,37,35,33,31,29,27,25}};
int x,estado;
int boton=6;

void setup() {
  Serial.begin(9600);
  pinMode(boton,INPUT);
  base.attach(2);
  avance.attach(4);
  altura.attach(3);
  garra.attach(5);

  // Posicion inicial
  base.write(90);
  delay(1000);
  avance.write(90);
  delay(1000);
  altura.write(180);
  delay(1000);
  garra.write(47);

  
}  
void loop() {
  
  estado=digitalRead(boton);
  if(estado==1)
  {
    for(x=0;x<11;x++){
      garra.write(mov[3][x]);
      delay(pausa);
      Serial.println(garra.read());
    }
    for(x=0;x<12;x++){
      altura.write(mov[2][x]);
      delay(pausa);
      Serial.println(altura.read());
    }
    for(x=0;x<17;x++){
      avance.write(mov[1][x]);
      delay(pausa);
      Serial.println(avance.read());
    }
    
    
    for(x=11;x>0;x--){
      garra.write(mov[3][x]);
      delay(pausa);
      Serial.println(garra.read());  
    }
    for(x=0;x<18;x++){
      base.write(mov[0][x]);
      delay(pausa);
      Serial.println(base.read());
    }
    for(x=0;x<11;x++){
      garra.write(mov[3][x]);
      delay(pausa);
      Serial.println(garra.read());
    }
    //vuelta
    for(x=11;x>0;x--){
      garra.write(mov[3][x]);
      delay(pausa);
      Serial.println(garra.read());  
    }
    for(x=18;x>0;x--){
      base.write(mov[0][x]);
      delay(pausa);
      Serial.println(base.read());
    }
    for(x=12;x>0;x--){
      altura.write(mov[2][x]);
      delay(pausa);
      Serial.println(altura.read());
    }
    for(x=15;x>0;x--){
      avance.write(mov[1][x]);
      delay(pausa);
      Serial.println(avance.read());
    }
    
    
  }
}
