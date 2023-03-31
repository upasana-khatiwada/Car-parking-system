#include<Servo.h>
#include <LiquidCrystal.h>;
const int rs = 6, en = 7,d4 = A0, d5 = A1, d6 = A2, d7 = A3, ct=9;
//en=7,rs=6,d4 = a0, d5 = a1, d6 = a2, d7 = a3,
LiquidCrystal mylcd(rs, en, d4, d5, d6, d7);

  Servo myservo1;


int s1=0,s2=0,s3=0,s4=0;
int slot=4;

 

void setup() {

  analogWrite(ct,50);

mylcd.begin(16,2);
mylcd.print("Welcome to");
mylcd.setCursor(0, 1);
mylcd.print("parking system");
delay(1000);
mylcd.clear();
Read_sensor();
int totalSlot =s1+s2+s3+s4;
slot=slot-totalSlot;


  myservo1.attach(13);

  
 pinMode(12,INPUT_PULLUP);

 //for 4 ota sensor ko input
 pinMode(2,INPUT_PULLUP);
 pinMode(3,INPUT_PULLUP);
 pinMode(4,INPUT_PULLUP);
 pinMode(5,INPUT_PULLUP);

 
 pinMode(13,OUTPUT); 
 // put your setup code here, to run once:
}

void loop() {
  Read_sensor();
  
  // mylcd.setCursor(0,1);
  // mylcd.print("Have Slot");

  // mylcd.setCursor(10,1);
  // mylcd.print(slot);


  
mylcd.setCursor (0,0);
// mylcd.clear();
if(s1==0){mylcd.print("1:Fill ");}
     else{mylcd.print("1:Empty");}

mylcd.setCursor (8,0);
if(s2==0){mylcd.print("2:Fill ");}
     else{mylcd.print("2:Empty");}

mylcd.setCursor (0,1);
if(s3==0){mylcd.print("3:Fill ");}
     else{mylcd.print("3:Empty");}

mylcd.setCursor (8,1);
if(s4==0){mylcd.print("4:Fill ");}
     else{mylcd.print("4:Empty");}



  if(digitalRead(12))
  {
    
    
     
     myservo1.write(90);//toll up
    //  delay(1500);
      
  }
 
else{
  myservo1.write(0);

  delay(2000);



    
}




  
Read_sensor();
  
  
 


//for car exit--------------


  
  // put your main code here, to run repeatedly:

}

void Read_sensor()
{
  s1 = 0;
  s2 = 0;
  s3 = 0;
  s4 = 0;

  if(digitalRead(2))
  {
    s1 = 1;
  }
  if(digitalRead(3))
  {
    s2 = 1;
  }
  if(digitalRead(4))
  {
    s3 = 1;
  }
  if(digitalRead(5))
  {
    s4 = 1;
  }
}

