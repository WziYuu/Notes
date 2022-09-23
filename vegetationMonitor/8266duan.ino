#define BLINKER_WIFI
#include <Blinker.h>
#include <math.h>
#include "DHT.h"
#define DHTPIN D4       //DHT11 out引脚
#define DHTTYPE DHT11   // DHT 11
#define SmokePin A0
#define PIN D0

int Empty[4] = {0,0,0,0};
int Light[4] = {0,0,0,0};
int Smoke[4] = {0,0,0,0};
int mainX[4] = {0,0,0,0};
int mainY[4] = {0,0,0,0};
int mainZ[4] = {0,0,0,0};
float Lig;
float Smok;
float Emp;

DHT dht(DHTPIN, DHTTYPE);
float temperature=0.0;//当前温度数据
float humidity =0.0;  //当前湿度数据

float xAngle,yAngle,zAngle;
char auth[] = "a05c521360cd";    // key
char ssid[] = "Smile:)";    // wifi name 
char pswd[] = "smilewww";    // wifi passpord 

// 新建组件对象
BlinkerButton Button1("btn-refresh");   //刷新
BlinkerButton Button2("btn-alarm");     //报警
BlinkerButton Button3("btn-overAlarm");     //报警

BlinkerNumber Number1("num-tem");       //温度
BlinkerNumber Number2("num-hum");       //湿度
BlinkerNumber Number3("num-som");       //烟度
BlinkerNumber Number4("num-xAng");       //角度
BlinkerNumber Number5("num-yAng");       //角度
BlinkerNumber Number6("num-zAng");       //角度
BlinkerNumber Number7("num-lig");       //光度


// void getSmoke(){
//   Smoke = analogRead(SmokePin);
//   Number3.print(Smoke);
//   Serial.print("烟度:");
//   Serial.println(Smoke);
// }

float toAngle(float a){
  a = a - 1450;
  a = a / 4.4444;
  return a;
}

int getAnal(int temp[]){
  int s = Serial.available();
  int total;
  if(s>0){
    int i=0;
    for(i=0;i<4;i++){
    temp[i]=0;
    }
    while(s--)
    {
      temp[s] = Serial.read()-48;
    }
    while(Serial.read()>=0);
  }
  total = temp[3]*1000+temp[2]*100+temp[1]*10+temp[0];
  delay(500);

  return total;
}
void getLig(){
  Serial.print('L');
  zAngle = getAnal(Light);
  zAngle = toAngle(zAngle);
  //Serial.println(Lig);
 // delay(50);
}

void getSmo(){
  Serial.print('s');
  Lig = getAnal(Smoke);

  Lig = Lig/4.096f;
  //Serial.println(Smok);
 // delay(50);
}
void getX(){
  float s;
  Serial.print('x');
  Smok = getAnal(mainX);
  s = Smok*5/4096;
  Smok = pow(11.5478*35.904*s/(25.5-5.1*s),0.6549);
  //Serial.println(Lig);
 // delay(50);
}
void getY(){
  Serial.print('y');
  xAngle = getAnal(mainY);
  xAngle = toAngle(xAngle);
  //Serial.println(Lig);
 // delay(50);
}
void getZ(){
  Serial.print('z');
  yAngle = getAnal(mainZ);
  yAngle = toAngle(yAngle);
  //Serial.println(Lig);
 // delay(50);
}
void getDat(){
  getLig();
  getSmo();
  getX();
  getY();
  getZ();
  
}

void overAla(){
  Button3.color("#87CEFA");
  Button3.text("正常");
  Button3.print("on");
  
}

void dataRead(const String & data)
{
  Number1.print(temperature);
  Number2.print(humidity);
  Number3.print(Smok);
  Number4.print(xAngle);
  Number5.print(yAngle);
  Number6.print(zAngle);
  Number7.print(Lig);

    Serial.println("dataRead更新数据");
}


void button1_callback(const String & state) {  //刷新温湿度数据
    temperature = dht.readTemperature();
    humidity = dht.readHumidity();
    // getSmoke();
    getDat();
    Number1.print(temperature);
    Number2.print(humidity); 
    Serial.print("Refresh温度:");
    Serial.print(temperature);
    Serial.print("湿度:");
    Serial.println(humidity);
}
void button2_callback(const String & state){
    Serial.println("Alarm");
}
void dataStorage()//建立存储数据对象 
{
    Blinker.dataStorage("num-tem", temperature);
    Blinker.dataStorage("num-hum", humidity);
    Blinker.dataStorage("num-som", Smok);
    Blinker.dataStorage("num-lig", Lig);
    Blinker.dataStorage("num-xAng", xAngle);
    Blinker.dataStorage("num-yAng", yAngle);
    Blinker.dataStorage("num-zAng", zAngle);
}

void rtData() //开启实时数据
{
    Blinker.sendRtData("num-tem", temperature);
    Blinker.sendRtData("num-hum", humidity);
    Blinker.sendRtData("num-som", Smok);
    Blinker.sendRtData("num-lig", Lig);
    Blinker.sendRtData("num-xAng", xAngle);
    Blinker.sendRtData("num-yAng", yAngle);
    Blinker.sendRtData("num-zAng", zAngle);
    Blinker.printRtData();
    Serial.print("rtData温度:");
    Serial.print(temperature);
    Serial.print("湿度:");
    Serial.println(humidity);
}

void heartbeat() //心跳包
{
    Blinker.print("num-tem", temperature);
    Blinker.print("num-hum", humidity);
    Blinker.print("num-som", Smok);
    Blinker.print("num-lig", Lig);

    Blinker.print("num-xAng", xAngle);
    Blinker.print("num-yAng", yAngle);
    Blinker.print("num-zAng", zAngle);
    Serial.print("heartbeat");
}
void setup() {
    dht.begin();
    Serial.begin(9600);
    BLINKER_DEBUG.stream(Serial);
    Blinker.begin(auth, ssid, pswd);
    Button1.attach(button1_callback);
    Button2.attach(button2_callback);
    Blinker.attachHeartbeat(heartbeat);//注册心跳包 
    Blinker.attachData(dataRead);
    Blinker.attachRTData(rtData);
    Blinker.attachDataStorage(dataStorage);

}
void loop() 
{
  Blinker.run();
  Serial.println("Loop");
  temperature = dht.readTemperature();//获取温度
  humidity = dht.readHumidity();//获取湿度
  overAla();
  getDat();
  //警报
  if(humidity<30)
  {
    Button2.color("#87CEFA");
    Button2.text("轻度");
    Button2.print("on");
  }else if(humidity<50)
  {
    Button2.color("#4169E1");
    Button2.text("中度");
    Button2.print("on");
  }else if(humidity<80)
  {
    Button2.color("#191970");
    Button2.text("重度");
    Button2.print("on");
  }

  temperature = dht.readTemperature();
  humidity = dht.readHumidity();
  Number1.print(temperature);
  Number2.print(humidity);
  Number3.print(Smok);
  Number4.print(xAngle);
  Number5.print(yAngle);
  Number6.print(zAngle);
  Number7.print(Lig);

  Blinker.delay(100);
  
}