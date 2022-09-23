#define PIN 12

int Light;
int Smoke;
int x,y,z;
void setup() { 
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void getLight(){
  Light = analogRead(A0);
  Serial.print(Light,DEC);
}

void getSmoke(){
  Smoke = analogRead(A4);

  Serial.print(Smoke,DEC);
}

void getX(){
  x = analogRead(A3);
  Serial.print(x,DEC);

}

void getY(){
  y = analogRead(A7);
  Serial.print(y,DEC);

}

void getZ(){
  z = analogRead(A6);
  Serial.print(z,DEC);
}
void loop() {
  // put your main code here, to run repeatedly:
//
 int recv = Serial.available();
 if(recv>0){
   int r = Serial.read();
   //Serial.print(r);
  switch (r){
    case 'L':{getLight();}break;//5v
    case 's':{getSmoke();}break;//5v
    case 'x':{getX();}break;//3.3v
    case 'y':{getY();}break;
    case 'z':{getZ();}break;
    case 'E':{Serial.print("e");}break;
  }
  while(Serial.read()>=0);
 }


 // delay(500);
}
