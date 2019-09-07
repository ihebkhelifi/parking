#include <Arduino.h>
#include "A4988.h"
#include <Adafruit_TFTLCD.h> 
#include <Adafruit_GFX.h>    
#include <TouchScreen.h>

#define MOTOR_STEPS 200

// All the wires needed for full functionality
#define DIR 32
#define STEP 34 


A4988 stepper(MOTOR_STEPS, DIR, STEP);

#define LCD_CS A3 
#define LCD_CD A2 
#define LCD_WR A1 
#define LCD_RD A0 
#define LCD_RESET A4 
#define TS_MINX 941
#define TS_MINY 185
#define TS_MAXX 205
#define TS_MAXY 908

#define YP A2  // must be an analog pin, use "An" notation!
#define XM A3  // must be an analog pin, use "An" notation!
#define YM 8   // can be a digital pin
#define XP 9   // can be a digital pin
#define BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF

Adafruit_TFTLCD tft(LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET);
TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);

int a=0;
int t=0;
char cp;
int tab[]={0,0,0,0,0,0};
int etat;



void setup() {  
  stepper.setRPM(30);
  tft.reset();
  tft.begin(0x9341);
  tft.setRotation(1);
  homescreen();
  cp='0';

}

void loop() 
{
    TSPoint p = ts.getPoint();  //Get touch point
    if (p.z > ts.pressureThreshhold) {   
      p.x = map(p.x, TS_MAXX, TS_MINX, 0, 320);
      p.y = map(p.y, TS_MAXY, TS_MINY, 0, 240);

      if(p.x>60 && p.x<260 && p.y>120 && p.y<160 && digitalRead(22)==HIGH)
      // The user has pressed inside the red rectangle
      {
      
      //This is important, because the libraries are sharing pins
      pinMode(XM, OUTPUT);
      pinMode(YP, OUTPUT);

          for (int i = 0 ; i < 6 ; i++)
      {
         if(tab[i]==0){
            etat=i;
            break;
          }
    
      }

      if(a>0){
      //Erase the screen
      tft.fillScreen(BLACK);
    
      //Draw frame
      tft.drawRect(0,0,319,240,WHITE);
    
      tft.setCursor(40,50);
      tft.setTextColor(WHITE);
      tft.setTextSize(3);
      tft.println("Bienvenue vous ");
      tft.setCursor(30,100);
      tft.setTextColor(WHITE);
      tft.setTextSize(3);
      tft.print("pouvez entrer");

      if(digitalRead(22)==HIGH && t==0){
      
      t=1;
      delay(1000);
      }
      
while (t!=2)
{
    if(digitalRead(24)==HIGH){
    t++;}
} 
      if(digitalRead(24)==HIGH && t==2)
      
      t=0;
      
     
  delay(10000);
      
      tab[etat]=1;

          //Erase the screen
    tft.fillScreen(BLACK);
    
    //Draw frame
    tft.drawRect(0,0,319,240,WHITE);
    
    tft.setCursor(40,50);
    tft.setTextColor(WHITE);
    tft.setTextSize(3);
    tft.println("Votre place ");
    tft.setCursor(30,100);
    tft.setTextColor(WHITE);
    tft.setTextSize(3);
    tft.print("est num:"); tft.print(etat+1);
      
      }
      else{
      //Erase the screen
      tft.fillScreen(BLACK);
    
      //Draw frame
      tft.drawRect(0,0,319,240,WHITE);
      tft.setCursor(40,50);
      tft.setTextColor(WHITE);
      tft.setTextSize(3);
      tft.println("Desole il n y a");
      tft.setCursor(30,100);
      tft.setTextColor(WHITE);
      tft.setTextSize(3);
      tft.print("plus de place");
      }
 
      delay(3000);
      homescreen();
      
      }
      


      //S1
      if(p.x>20 && p.x<80 && p.y>150 && p.y<190)
      // The user has pressed inside the red rectangle
      {
      //This is important, because the libraries are sharing pins
      pinMode(XM, OUTPUT);
      pinMode(YP, OUTPUT);

      if(tab[0]==1){
      //Erase the screen
      tft.fillScreen(BLACK);
    
      //Draw frame
      tft.drawRect(0,0,319,240,WHITE);
    
      tft.setCursor(40,50);
      tft.setTextColor(WHITE);
      tft.setTextSize(3);
      tft.println("vous pouvez");
      tft.setCursor(30,100);
      tft.setTextColor(WHITE);
      tft.setTextSize(3);
      tft.print("sortir du S1");

      
    while(t!=1){
      if(digitalRead(24)==HIGH)
      t++;
      delay(1000);
    }
      
while (t!=2)
{
    if(digitalRead(22)==HIGH){
    t++;}
} 
      if(digitalRead(22)==HIGH && t==2){
      tab[0]=0;
      t=0;}
      }
      else{
        //Erase the screen
      tft.fillScreen(BLACK);
    
      //Draw frame
      tft.drawRect(0,0,319,240,WHITE);
    
      tft.setCursor(40,50);
      tft.setTextColor(WHITE);
      tft.setTextSize(3);
      tft.println("La place est");
      tft.setCursor(30,100);
      tft.setTextColor(WHITE);
      tft.setTextSize(3);
      tft.print("deja vide");
        
      }

      delay(3000);
      homescreen();
      }


      //S2
      if(p.x>120 && p.x<180 && p.y>150 && p.y<190)
      // The user has pressed inside the red rectangle
      {
      //This is important, because the libraries are sharing pins
      pinMode(XM, OUTPUT);
      pinMode(YP, OUTPUT);

             if(tab[1]==1){
      //Erase the screen
      tft.fillScreen(BLACK);
    
      //Draw frame
      tft.drawRect(0,0,319,240,WHITE);
    
      tft.setCursor(40,50);
      tft.setTextColor(WHITE);
      tft.setTextSize(3);
      tft.println("vous pouvez");
      tft.setCursor(30,100);
      tft.setTextColor(WHITE);
      tft.setTextSize(3);
      tft.print("sortir du S2");

      
    while(t!=1){
      if(digitalRead(24)==HIGH)
      t++;
      delay(1000);
    }
      
while (t!=2)
{
    if(digitalRead(22)==HIGH){
    t++;}
} 
      if(digitalRead(22)==HIGH && t==2){
      tab[1]=0;
      t=0;}
      }
      else{
        //Erase the screen
      tft.fillScreen(BLACK);
    
      //Draw frame
      tft.drawRect(0,0,319,240,WHITE);
    
      tft.setCursor(40,50);
      tft.setTextColor(WHITE);
      tft.setTextSize(3);
      tft.println("La place est");
      tft.setCursor(30,100);
      tft.setTextColor(WHITE);
      tft.setTextSize(3);
      tft.print("déja vide");
        
      }
      delay(3000);
      homescreen();
      }

      //S3
      if(p.x>220 && p.x<280 && p.y>150 && p.y<190)
      // The user has pressed inside the red rectangle
      {
      //This is important, because the libraries are sharing pins
      pinMode(XM, OUTPUT);
      pinMode(YP, OUTPUT);

            if(tab[2]==1){
      //Erase the screen
      tft.fillScreen(BLACK);
    
      //Draw frame
      tft.drawRect(0,0,319,240,WHITE);
    
      tft.setCursor(40,50);
      tft.setTextColor(WHITE);
      tft.setTextSize(3);
      tft.println("vous pouvez");
      tft.setCursor(30,100);
      tft.setTextColor(WHITE);
      tft.setTextSize(3);
      tft.print("sortir du S3");

      
    while(t!=1){
      if(digitalRead(24)==HIGH)
      t++;
      delay(1000);
    }
      
while (t!=2)
{
    if(digitalRead(22)==HIGH){
    t++;}
} 
      if(digitalRead(22)==HIGH && t==2){
      tab[2]=0;
      t=0;}
      }
      else{
        //Erase the screen
      tft.fillScreen(BLACK);
    
      //Draw frame
      tft.drawRect(0,0,319,240,WHITE);
    
      tft.setCursor(40,50);
      tft.setTextColor(WHITE);
      tft.setTextSize(3);
      tft.println("La place est");
      tft.setCursor(30,100);
      tft.setTextColor(WHITE);
      tft.setTextSize(3);
      tft.print("déja vide");
        
      }
      delay(3000);
      homescreen();
      }


      //S4
      if(p.x>20 && p.x<80 && p.y>195 && p.y<235)
      // The user has pressed inside the red rectangle
      {
      //This is important, because the libraries are sharing pins
      pinMode(XM, OUTPUT);
      pinMode(YP, OUTPUT);

           if(tab[3]==1){
      //Erase the screen
      tft.fillScreen(BLACK);
    
      //Draw frame
      tft.drawRect(0,0,319,240,WHITE);
    
      tft.setCursor(40,50);
      tft.setTextColor(WHITE);
      tft.setTextSize(3);
      tft.println("vous pouvez");
      tft.setCursor(30,100);
      tft.setTextColor(WHITE);
      tft.setTextSize(3);
      tft.print("sortir du S4");

      
    while(t!=1){
      if(digitalRead(24)==HIGH)
      t++;
      delay(1000);
    }
      
while (t!=2)
{
    if(digitalRead(22)==HIGH){
    t++;}
} 
      if(digitalRead(22)==HIGH && t==2){
      tab[3]=0;
      t=0;}
      }
      else{
        //Erase the screen
      tft.fillScreen(BLACK);
    
      //Draw frame
      tft.drawRect(0,0,319,240,WHITE);
    
      tft.setCursor(40,50);
      tft.setTextColor(WHITE);
      tft.setTextSize(3);
      tft.println("La place est");
      tft.setCursor(30,100);
      tft.setTextColor(WHITE);
      tft.setTextSize(3);
      tft.print("déja vide");
        
      }
      delay(3000);
      homescreen();
      }


      //S5
      if(p.x>120 && p.x<180 && p.y>195 && p.y<235)
      // The user has pressed inside the red rectangle
      {
      //This is important, because the libraries are sharing pins
      pinMode(XM, OUTPUT);
      pinMode(YP, OUTPUT);

            if(tab[4]==1){
      //Erase the screen
      tft.fillScreen(BLACK);
    
      //Draw frame
      tft.drawRect(0,0,319,240,WHITE);
    
      tft.setCursor(40,50);
      tft.setTextColor(WHITE);
      tft.setTextSize(3);
      tft.println("vous pouvez");
      tft.setCursor(30,100);
      tft.setTextColor(WHITE);
      tft.setTextSize(3);
      tft.print("sortir du S5");

      
    while(t!=1){
      if(digitalRead(24)==HIGH)
      t++;
      delay(1000);
    }
      
while (t!=2)
{
    if(digitalRead(22)==HIGH){
    t++;}
} 
      if(digitalRead(22)==HIGH && t==2){
      tab[4]=0;
      t=0;}
      }
      else{
        //Erase the screen
      tft.fillScreen(BLACK);
    
      //Draw frame
      tft.drawRect(0,0,319,240,WHITE);
    
      tft.setCursor(40,50);
      tft.setTextColor(WHITE);
      tft.setTextSize(3);
      tft.println("La place est");
      tft.setCursor(30,100);
      tft.setTextColor(WHITE);
      tft.setTextSize(3);
      tft.print("déja vide");
        
      }
      delay(3000);
      homescreen();
      }

      //S6
      if(p.x>220 && p.x<280 && p.y>195 && p.y<235)
      // The user has pressed inside the red rectangle
      {
      //This is important, because the libraries are sharing pins
      pinMode(XM, OUTPUT);
      pinMode(YP, OUTPUT);

            if(tab[5]==1){
      //Erase the screen
      tft.fillScreen(BLACK);
    
      //Draw frame
      tft.drawRect(0,0,319,240,WHITE);
    
      tft.setCursor(40,50);
      tft.setTextColor(WHITE);
      tft.setTextSize(3);
      tft.println("vous pouvez");
      tft.setCursor(30,100);
      tft.setTextColor(WHITE);
      tft.setTextSize(3);
      tft.print("sortir du S6");

      
    while(t!=1){
      if(digitalRead(24)==HIGH)
      t++;
      delay(1000);
    }
      
while (t!=2)
{
    if(digitalRead(22)==HIGH){
    t++;}
} 
      if(digitalRead(22)==HIGH && t==2){
      tab[5]=0;
      t=0;}
      }
      else{
        //Erase the screen
      tft.fillScreen(BLACK);
    
      //Draw frame
      tft.drawRect(0,0,319,240,WHITE);
    
      tft.setCursor(40,50);
      tft.setTextColor(WHITE);
      tft.setTextSize(3);
      tft.println("La place est");
      tft.setCursor(30,100);
      tft.setTextColor(WHITE);
      tft.setTextSize(3);
      tft.print("déja vide");
        
      }
      delay(3000);
      homescreen();
      }
    

    }  


}


void homescreen(){
    tft.fillScreen(BLACK);
  //Draw white frame
  tft.drawRect(0,0,319,240,WHITE);
  
  //Print "Bienvenue" Text
  tft.setCursor(60,20);
  tft.setTextColor(WHITE);
  tft.setTextSize(4);
  tft.print("Bienvenue");
  a=0;
  for (int i = 0 ; i < 6 ; i++){
    if(tab[i]==0)
    a++;
    }
  
  //Print "Place" text 
  tft.setCursor(25,65);
  tft.setTextColor(RED);
  tft.setTextSize(3);
  tft.print("Places libres: "); tft.print(a);
  
  //Create Green Button
  tft.fillRect(60,100, 200, 40, GREEN);
  tft.drawRect(60,100,200,40,WHITE);
  tft.setCursor(110,108);
  tft.setTextColor(WHITE);
  tft.setTextSize(3);
  tft.print("Entrer");

  //Create Red Button
  tft.fillRect(20,150,60,40, RED);
  tft.drawRect(20,150,60,40,WHITE);
  tft.setCursor(35,158);
  tft.setTextColor(WHITE);
  tft.setTextSize(3);
  tft.print("S1");

  //Create Red Button
  tft.fillRect(120,150,60,40, RED);
  tft.drawRect(120,150,60,40,WHITE);
  tft.setCursor(135,158);
  tft.setTextColor(WHITE);
  tft.setTextSize(3);
  tft.print("S2");

  //Create Red Button
  tft.fillRect(220,150,60,40, RED);
  tft.drawRect(220,150,60,40,WHITE);
  tft.setCursor(235,158);
  tft.setTextColor(WHITE);
  tft.setTextSize(3);
  tft.print("S3");

  //Create Red Button
  tft.fillRect(20,195,60,40, RED);
  tft.drawRect(20,195,60,40,WHITE);
  tft.setCursor(35,203);
  tft.setTextColor(WHITE);
  tft.setTextSize(3);
  tft.print("S4");

  //Create Red Button
  tft.fillRect(120,195,60,40, RED);
  tft.drawRect(120,195,60,40,WHITE);
  tft.setCursor(135,203);
  tft.setTextColor(WHITE);
  tft.setTextSize(3);
  tft.print("S5");

  //Create Red Button
  tft.fillRect(220,195,60,40, RED);
  tft.drawRect(220,195,60,40,WHITE);
  tft.setCursor(235,203);
  tft.setTextColor(WHITE);
  tft.setTextSize(3);
  tft.print("S6");
  
}


