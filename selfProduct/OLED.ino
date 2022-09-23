#include "oledfonted.h"
#include <arduino-timer.h>
#include <time.h>
#define LED_BUILTIN 5
auto timer = timer_create_default(); // create a timer with default settings
#define uchar unsigned char
#define uint unsigned int
#define SCL 22
#define SDA 21
#define delayTime 0
float para = 1;
uchar status = 5;
uchar last_status = 1;
int j = -8;
uint flag = 0;
uchar bk = 1;
uchar df = 1;
uchar ligg = 3;
int randn;
int sza;
int chuang[6];
void iicStart(){
  digitalWrite(SCL,1);
  delayMicroseconds(delayTime);
  digitalWrite(SDA,1);
  delayMicroseconds(delayTime);
  digitalWrite(SDA,0);
  delayMicroseconds(delayTime);
  digitalWrite(SCL,0);
}

void iicStop(){
  digitalWrite(SDA,0);
  delayMicroseconds(delayTime);
  digitalWrite(SCL,1);
  delayMicroseconds(delayTime);
  digitalWrite(SDA,1);
  delayMicroseconds(delayTime);
  digitalWrite(SCL,0);
}

void waitAck(){
  digitalWrite(SCL,1);
  delayMicroseconds(delayTime);
  digitalWrite(SCL,0);
  
}

void iicWr(uchar dat){
  uchar i;
	for(i=0;i<8;i++){
		digitalWrite(SDA,dat&0x80);
		delayMicroseconds(delayTime);
		digitalWrite(SCL,1);
		delayMicroseconds(delayTime);
		digitalWrite(SCL,0);
		delayMicroseconds(delayTime);
		dat<<=1;
	}
}

void oledCmd(unsigned char cmd){
	iicStart();
	iicWr(0x78);
	waitAck();
	iicWr(0x00);
	waitAck();
	iicWr(cmd);
	waitAck();
	iicStop();
}

void oledDat(unsigned char dat){
	iicStart();
	iicWr(0x78);
	waitAck();
	iicWr(0x40);
	waitAck();
	iicWr(dat);
	waitAck();
	iicStop();
}

void oledInit(){
	oledCmd(0xae);
	oledCmd(0x00);
	oledCmd(0x01);
	oledCmd(0x40);
	oledCmd(0xb0);
	oledCmd(0x81);
	oledCmd(0xff);
	//oledCmd(0x22);
	oledCmd(0xa1);
	oledCmd(0xa6);
	oledCmd(0xa8);
	oledCmd(0x3f);
	oledCmd(0xc8);
	oledCmd(0xd3);
	oledCmd(0x00);
	oledCmd(0xd5);
	oledCmd(0x80);
	oledCmd(0xd8);
	oledCmd(0x05);
	oledCmd(0xd9);
	oledCmd(0xf1);
	oledCmd(0xda);
	oledCmd(0x12);
	oledCmd(0xdb);
	oledCmd(0x30);
	oledCmd(0x8d);
	oledCmd(0x14);
	oledCmd(0xaf);
}

void clear(){
	uchar n,m;
	for(n=0;n<8;n++){
		oledCmd(0xb0+n);
		oledCmd(0x00);		oledCmd(0x10);
		for(m=0;m<128;m++){
		 oledDat(0x00);}
	}
}

void setPos(unsigned char x, unsigned char y){
	//y/=8;
	oledCmd(0xb0+y);
	oledCmd(x%16);
	oledCmd((x/16)|0x10);
}

void clr(const unsigned char *dat,uchar width,uchar height,uchar xp,uchar yp){
	int n,m;
	int k = 0;
	height-=1;
	for(n=0;n<=height/8;n++){
		setPos(xp,yp+n);
		for(m=0;m<width;m++){
		 oledDat(dat[k]);
			k++;
		}

	 }
}

void two(const unsigned char a[],const unsigned char b[]){
	
	clr(a,32,32,89,0);
	clr(b,32,32,57,0);
}

void eat(){
  int randNum = random(0,20);
  int ioo = random(0,2);
  clr(xiao,64,16,64,6);
  if(ioo)clr(wai,16,16,96,6);
  switch (randNum){
    case 0:{two(mi,xian);};break;
		case 1:{two(hua,jia);};break;
		case 2:{two(men,ji);};break;
		case 3:{two(chao3,fan);};break;
		case 4:{two(chao1,shi);};break;
		case 5:{two(Tan,kao);};break;
		case 6:{two(ji,bao);};break;
		case 7:{two(jiao,zi);};break;
		case 8:{two(luo,si);};break;
		case 9:{two(mi,fen);};break;
		case 10:{two(chao3,fan);};break;
		case 11:{two(chao3,ji);};break;
		case 12:{two(pao,mian);};break;
		case 13:{two(pao,fan);};break;
		case 14:{two(gai,mian);};break;
		case 15:{two(gai,fan);};break;
		case 16:{two(gai,fan);};break;
		case 17:{two(Tan,fan);};break;
		case 18:{two(Tan,fen);};break;
		case 19:{two(Tan,mian);};break;
	}
}

void play(){
  int randNum = random(0,5);
  clr(wanshenme,16,32,0,4);
  switch (randNum){
    case 0:{clr(g5,56,64,27,0);};break;
		case 1:{clr(ow2,50,64,30,0);};break;
		case 2:{clr(witness,53,64,30,0);};break;
		case 3:{clr(fh,49,64,32,0);};break;
		case 4:{clr(nier,63,63,25,0);};break;
		//case 5:{two(Tan,kao);};break;
  }
}
void numd(){
	randn = random(0,6);
	//randn%=6;
	if(chuang[randn] == 0){
		chuang[randn] = 1;
		return;
	}
	else{
		for(sza=0;sza<6;sza++){
		    if(chuang[sza] != 1){	
		    	break;
			}
			if(sza ==5 && chuang[sza]==1){
				for(sza = 0;sza<6;sza++){
					chuang[sza]=0;
				}
			}
		}
	numd();	
	}	
}
void maifan(){
  clr(sheidaifan,12,64,115,0);
  clr(haochuang,12,24,60,5);
  numd();
  switch(randn){
    case 0:{clr(yi1,35,32,65,0);};break;
    case 1:{clr(er1,35,30,65,0);};break;
    case 2:{clr(san1,35,32,65,0);};break;
    case 3:{clr(si1,37,40,65,0);};break;
    case 4:{clr(wu1,40,40,60,0);};break;
    case 5:{clr(liu1,35,32,65,0);};break;
  };
}

bool interrupt(void *) {
    int x,y,z;
  x = analogRead(A3);
  y = analogRead(A7);
  z = analogRead(A6);
  if(z>2200*para || z<1600*para){status = 5;}
  else if(x<1600*para && y <2160*para && y >1600*para){status = 1;}
  else if(x>=1600*para&&x<=2170*para&&y<1600*para){status = 2;}
  else if(x>2170*para && y>=1600*para && y<2160*para){status = 3;}
  else if(x>1600*para && x<=2170 *para&&y>=2160*para){status = 4;}
  flag++;
  
  if(flag>19)flag=0;
  digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN)); // toggle the LED
  if(status != last_status){
    if(flag%10 == 0){last_status = status;
      switch(status){
        case 1:{clear();clr(s76 ,28,59,100,0);}break;
        case 2:{
                clear();
                clr(w76,24,64,104,0);
                play();
                }break;
        case 3:{
                clear();
                clr(dva,45,64,0,0);
                clr(dvaf,23,24,11,1);                 
                eat();
                }break;
        case 4:{clear();
                clr(hammer,32,64,8,0);
                maifan();}break;
        case 5:{clear();clr(yun,38,36,17,0);
                clr(yun,38,36,73,0);
                clr(face,61,15,33,6);}break;
      }
    }
    
  }else{
    switch (status){
      case 1:{setPos(ligg+100,1);
              oledDat(s76[28+ligg]);
              oledDat(s76[29+ligg]|0x80);
              setPos(ligg+100,2);
              oledDat(s76[56+ligg]);
              oledDat(s76[57+ligg]|0x02);
              ligg++;
              if(ligg>19)
              ligg=3;
              }break;
      case 2:{
              		setPos(120,7);
              		if(j<0){
              			oledDat(feidan[0]>>(-j));
              			oledDat(feidan[1]>>(-j));
              			oledDat(feidan[2]>>(-j));
              		}else{
              			oledDat(feidan[0]<<(j));
              			oledDat(feidan[1]<<(j));
              			oledDat(feidan[2]<<(j));
              		}
              		j++;
              		if(j>6)j = -8;       		
      }break;
      case 3:{
              if(flag%10 == 0){
                if(df){
                    clr(dvaf,23,24,11,1);df = 0;
                }else{
                  clr(dvaf2,23,24,11,1);df = 1;
                }
              }
      }break;
      case 4:{
        if(flag%10 == 0){
                if(bk){clr(brk,8,16,0,0);bk=0;}
		            else{clr(brk2,8,16,0,0);bk=1;}
              }
      }break;
    }
  }
  return true;
}

void setup()   
{  
    Serial.begin(9600);
    pinMode(SCL,OUTPUT);
    pinMode(SDA,OUTPUT);
    pinMode(LED_BUILTIN, OUTPUT);
    timer.every(100, interrupt);
    oledInit();
    clear();
    //clr(yun,38,36,17,0);
	  //clr(yun,38,36,73,0);
    //clr(face,61,15,33,6);
    clr(s76 ,28,59,100,0);
   // clr(dva,45,64,0,0);
   // clr(dvaf,23,24,11,1);
    //clr(hammer,32,64,8,0);
    //clr(w76,24,64,104,0);
    //clr(feidan,3,8,120,7);
    //clr(brk,8,16,0,0);

}

void loop()
{ 
  timer.tick();
  //Serial.println("666");
  //delay(1000);


}
