#include <stc15f2k60s2.h>
#include <intrins.h>

sbit ebl =P2^0;
sbit mac = P2^1;
sbit mac2 = P2^2;
sbit ebl2 = P0^3;
sbit ebl3 = P0^4;
long count;

void Delay1000ms()		//@11.0592MHz
{
	unsigned char i, j, k;

	_nop_();
	_nop_();
	i = 43;
	j = 6;
	k = 203;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}

void Delay100ms()		//@11.0592MHz
{
	unsigned char i, j, k;

	_nop_();
	_nop_();
	i = 5;
	j = 52;
	k = 195;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}

void init(){
	P2 = 0x80;
	P0 = 0x02;
	P2 = 0xa0;
	P0 = 0x00;
	P2 = 0xc0;
	P0 = 0x00;
	P2 = 0xe0;
	P0 = 0x00;
	
	mac=0;
	mac2 = 0;
	ebl =1;
	ebl2=1;
	ebl3=1;
}
	
	
void main(){
	
	init();
	Delay1000ms();
	while(1){

		if(ebl){
					ebl =1;
				ebl2=1;
			mac = 1;
			mac2 = 0;//�����ʼ����
			while(ebl2){
			};//ֱ��ebl2�ӵ�
			
			mac = 0;
			mac2  =0;//���ֹͣ
			
			while(ebl);//���űպ�
			
			mac2 = 1;
			mac =0; //�����ת
			
			while(ebl3);//�ȴ�������λ
			Delay100ms();
			
			mac = 0;
			mac2 =0;//ֹͣ
			
			//while(ebl);
			Delay1000ms();Delay1000ms();
			
		}
		else{
			mac=0;
			mac2=0;
		}
	}
}
