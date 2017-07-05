/*
Blink-a-tron patterns for 6 LED arcade buttons
(c) 2015 Ryan Bates, RetroBuiltGames.com
edited by Benjamin Vitters (2017)
*/
//LED pin connections for Teensy 2.0++
//change these for your arduino compatible device
const int led0 = 4;
const int led1 = 5;
const int led2 = 6;
const int led3 = 7;
const int led4 = 8;
const int led5 = 9;
// button/switch used to cycle between 'demo mode' and 
//'non-seizure light pattern mode' when playing arcade
const int buttonPin = 2;

int buttonState = 3; //variable for reading button state
 
//variables used to adjust pattern speeds (all in millis delays)
const int  ledx = 1;
const int  delaytime = 40;
const int  delaytimeX = 120;
const int  delayloop = 15;
const int  masterDelay = 20;  //changes speed of ALL Blink patterns: must be a multiple of 5
const int fadeIncriment = 10;
const int fadeIncriment2 = 10;  //determines how long the fade cycles; must be a multple of 255 
void setup() {                
 
pinMode(led0, OUTPUT);
pinMode(led1, OUTPUT); 
pinMode(led2, OUTPUT); 
pinMode(led3, OUTPUT); 
pinMode(led4, OUTPUT); 
pinMode(led5, OUTPUT);
pinMode(buttonPin, INPUT);
/* The arcade button layout is as follows:
        (5)(4)(3)
        (0)(1)(2)
 There for if want to illuminate the buttons starting at button#5 
 and go clockwise the order is 543210
*/
  Serial.begin(9600);
  Serial.println("Lights on");
}

//pattern routine that loops forever; arrange, copy, remove these to make your 'light show'
  //scrollup();         
  //scrolldown();
  //lightup();           
  //lightdown();
  //scrollpairup();    
  //scrollpairdown();
  //loopforward();
  //loopreverse();
  //loopspeedUpFwd();    
  //loopspeedDwnRvs();
  //strobethreeUP();     
  //strobethreeDWN();
  //strobecrisscross();  
  //strobecircle();
  //zigzag1();           
  //oneoffloop();
  //fade();           
  //fade features are for PWM pins only
  //fadethree();      
  //fadecross();
  //fadecrossreverse();

void loop(){
char c = Serial.read();
if(c == 'a'){
  scrollpairup();    
  scrollpairdown();
  loopforward();
  Serial.println("Inserted coin");
}
if(c =='s'){
  scrollup();          scrolldown();
  strobecrisscross();  
  fadecrossreverse(); 
  Serial.println("BigBox startup");
}
if(c =='g'){
  scrollup();          scrolldown();
  strobecircle();
  Serial.println("Game started");  
}
if(c =='l'){
  scrollup();          scrolldown();
  lightup();           lightdown();
  scrollpairup();    
  scrollpairdown();
  loopforward();       
  loopreverse();
  loopspeedUpFwd();    loopspeedDwnRvs();
  strobethreeUP();     
  strobethreeDWN();
  strobecrisscross();  strobecircle();
  zigzag1();           
  oneoffloop();
  fade();           //fade features are for PWM pins only
  fadethree();      
  fadecross();
  fadecrossreverse();
  Serial.println("Light showoff");  
}
 else {
 digitalWrite(led0, HIGH);   
 digitalWrite(led3, HIGH);   
 digitalWrite(led1, HIGH);   
 digitalWrite(led4, HIGH);   
 digitalWrite(led2, HIGH);   
 digitalWrite(led5, HIGH);  }
 
}
// LED patterns are below.-------------------------------------------------------------------
void oneoffloop() 
 {  for (int loopspeed = 1 ; loopspeed <=201; loopspeed +=masterDelay) {
 digitalWrite(led5, LOW);   digitalWrite(led4, HIGH);   digitalWrite(led3, HIGH);  
 digitalWrite(led2, HIGH);  digitalWrite(led1, HIGH);   digitalWrite(led0, HIGH);  
      delay(loopspeed);
 digitalWrite(led5, HIGH);   digitalWrite(led4, LOW);   digitalWrite(led3, HIGH);  
 digitalWrite(led2, HIGH);  digitalWrite(led1, HIGH);   digitalWrite(led0, HIGH);  
      delay(loopspeed);     
 digitalWrite(led5, HIGH);   digitalWrite(led4, HIGH);   digitalWrite(led3, LOW);  
 digitalWrite(led2, HIGH);  digitalWrite(led1, HIGH);   digitalWrite(led0, HIGH);  
      delay(loopspeed);    
 digitalWrite(led5, HIGH);   digitalWrite(led4, HIGH);   digitalWrite(led3, HIGH);  
 digitalWrite(led2, LOW);  digitalWrite(led1, HIGH);   digitalWrite(led0, HIGH);  
      delay(loopspeed); 
 digitalWrite(led5, HIGH);   digitalWrite(led4, HIGH);   digitalWrite(led3, HIGH);  
 digitalWrite(led2, HIGH);  digitalWrite(led1, LOW);   digitalWrite(led0, HIGH);  
      delay(loopspeed);    
 digitalWrite(led5, HIGH);   digitalWrite(led4, HIGH);   digitalWrite(led3, HIGH);  
 digitalWrite(led2, HIGH);  digitalWrite(led1, HIGH);   digitalWrite(led0, LOW);  
      delay(loopspeed); }
}
void zigzag1()
 { for (int loopspeed = 1 ; loopspeed <=151; loopspeed +=masterDelay) {
  digitalWrite(led5, HIGH);  delay(loopspeed);   digitalWrite(led5, LOW); 
  digitalWrite(led0, HIGH);  delay(loopspeed);   digitalWrite(led0, LOW);
  digitalWrite(led1, HIGH);  delay(loopspeed);   digitalWrite(led1, LOW);
  digitalWrite(led4, HIGH);  delay(loopspeed);   digitalWrite(led4, LOW);
  digitalWrite(led3, HIGH);  delay(loopspeed);   digitalWrite(led3, LOW);
  digitalWrite(led2, HIGH);  delay(loopspeed);   digitalWrite(led2, LOW);
  digitalWrite(led3, HIGH);  delay(loopspeed);   digitalWrite(led3, LOW);
  digitalWrite(led4, HIGH);  delay(loopspeed);   digitalWrite(led4, LOW);
  digitalWrite(led1, HIGH);  delay(loopspeed);   digitalWrite(led1, LOW);
  digitalWrite(led0, HIGH);  delay(loopspeed);   digitalWrite(led0, LOW);
                           }
 }
  
void strobecircle() //lights up 2 on top 1 on botton then mirrors pattren
{ for (int loopspeed = 1 ; loopspeed <=201; loopspeed +=masterDelay) {
  digitalWrite(led5, HIGH);   digitalWrite(led3, HIGH);  digitalWrite(led1, HIGH); 
      delay(loopspeed);  
  digitalWrite(led5, LOW);   digitalWrite(led3, LOW);   digitalWrite(led1, LOW);  
      delay(loopspeed); 
  digitalWrite(led0, HIGH);   digitalWrite(led4, HIGH);   digitalWrite(led2, HIGH); 
      delay(loopspeed);  
  digitalWrite(led0, LOW);   digitalWrite(led4, LOW);   digitalWrite(led2, LOW); 
      delay(loopspeed);                                        }
 }
void strobecrisscross() // lights up set up 4 then 2.
{ for (int loopspeed = 1 ; loopspeed <=201; loopspeed +=masterDelay) {
  digitalWrite(led5, HIGH);   digitalWrite(led3, HIGH);  digitalWrite(led0, HIGH);  digitalWrite(led2, HIGH); 
      delay(loopspeed);  
  digitalWrite(led5, LOW);   digitalWrite(led3, LOW);   digitalWrite(led0, LOW); digitalWrite(led2, LOW); 
      delay(loopspeed); 
  digitalWrite(led4, HIGH);   digitalWrite(led1, HIGH);  
      delay(loopspeed);  
  digitalWrite(led4, LOW);   digitalWrite(led1, LOW);  
      delay(loopspeed);                                        }
 }

void strobethreeDWN() //lights a row of 3 buttons with increaseing strobe speed
{ for (int loopspeed = 1 ; loopspeed <=201; loopspeed +=masterDelay) {
  digitalWrite(led5, HIGH);   digitalWrite(led4, HIGH);  digitalWrite(led3, HIGH);  
      delay(loopspeed);  
  digitalWrite(led5, LOW);    digitalWrite(led4, LOW);   digitalWrite(led3, LOW); 
      delay(loopspeed); 
  digitalWrite(led2, HIGH);   digitalWrite(led1, HIGH);  digitalWrite(led0, HIGH);  
      delay(loopspeed);  
  digitalWrite(led2, LOW);    digitalWrite(led1, LOW);   digitalWrite(led0, LOW); 
      delay(loopspeed);                                        }
 }

void strobethreeUP() //lights a row of 3 buttons with increaseing strobe speed
{ for (int loopspeed = 201 ; loopspeed >=1; loopspeed -=masterDelay) {
  digitalWrite(led5, HIGH);   digitalWrite(led4, HIGH);  digitalWrite(led3, HIGH);  
      delay(loopspeed);  
  digitalWrite(led5, LOW);    digitalWrite(led4, LOW);   digitalWrite(led3, LOW); 
      delay(loopspeed); 
  digitalWrite(led2, HIGH);   digitalWrite(led1, HIGH);  digitalWrite(led0, HIGH);  
      delay(loopspeed);  
  digitalWrite(led2, LOW);    digitalWrite(led1, LOW);   digitalWrite(led0, LOW); 
      delay(loopspeed);                                        }
 } 

//scrolls thru buttons and decreases speed for every cycle
void loopspeedDwnRvs() 
{ for (int loopspeed = 1 ; loopspeed <=101; loopspeed +=masterDelay) {
  digitalWrite(led5, HIGH);     delay(loopspeed);              
  digitalWrite(led5, LOW);      delay(loopspeed);  
  digitalWrite(led4, HIGH);     delay(loopspeed);              
  digitalWrite(led4, LOW);      delay(loopspeed);
  digitalWrite(led3, HIGH);     delay(loopspeed);              
  digitalWrite(led3, LOW);      delay(loopspeed);  
  digitalWrite(led2, HIGH);     delay(loopspeed);              
  digitalWrite(led2, LOW);      delay(loopspeed);  
  digitalWrite(led1, HIGH);     delay(loopspeed);              
  digitalWrite(led1, LOW);      delay(loopspeed);  
  digitalWrite(led0, HIGH);     delay(loopspeed);              
  digitalWrite(led0, LOW);      delay(loopspeed);                 }
 
} 
 

//scrolls thru buttons and increases speed for every cycle
void loopspeedUpFwd() 
{ for (int loopspeed = 101 ; loopspeed >=1; loopspeed -=masterDelay) {
  digitalWrite(led5, HIGH);     delay(loopspeed);              
  digitalWrite(led5, LOW);      delay(loopspeed);  
  digitalWrite(led4, HIGH);     delay(loopspeed);              
  digitalWrite(led4, LOW);      delay(loopspeed);
  digitalWrite(led3, HIGH);     delay(loopspeed);              
  digitalWrite(led3, LOW);      delay(loopspeed);  
  digitalWrite(led2, HIGH);     delay(loopspeed);              
  digitalWrite(led2, LOW);      delay(loopspeed);  
  digitalWrite(led1, HIGH);     delay(loopspeed);              
  digitalWrite(led1, LOW);      delay(loopspeed);  
  digitalWrite(led0, HIGH);     delay(loopspeed);              
  digitalWrite(led0, LOW);      delay(loopspeed);                 }
 
} 
 
 

void loopreverse() 
{ for (int loopcount = 0 ; loopcount <=8; loopcount +=1) {
  digitalWrite(led5, HIGH);     delay(delayloop);              
  digitalWrite(led5, LOW);      delay(delayloop);  
  digitalWrite(led4, HIGH);     delay(delayloop);              
  digitalWrite(led4, LOW);      delay(delayloop);
  digitalWrite(led3, HIGH);     delay(delayloop);              
  digitalWrite(led3, LOW);      delay(delayloop);  
  digitalWrite(led2, HIGH);     delay(delayloop);              
  digitalWrite(led2, LOW);      delay(delayloop);  
  digitalWrite(led1, HIGH);     delay(delayloop);              
  digitalWrite(led1, LOW);      delay(delayloop);  
  digitalWrite(led0, HIGH);     delay(delayloop);              
  digitalWrite(led0, LOW);      delay(delayloop);                             }
 
} 
 
void loopforward(){
  for (int loopcount = 0 ; loopcount <=8; loopcount +=1) {
  digitalWrite(led0, HIGH);     delay(delayloop);              
  digitalWrite(led0, LOW);      delay(delayloop);  
  digitalWrite(led1, HIGH);     delay(delayloop);              
  digitalWrite(led1, LOW);      delay(delayloop);
  digitalWrite(led2, HIGH);     delay(delayloop);              
  digitalWrite(led2, LOW);      delay(delayloop);  
  digitalWrite(led3, HIGH);     delay(delayloop);              
  digitalWrite(led3, LOW);      delay(delayloop);  
  digitalWrite(led4, HIGH);     delay(delayloop);              
  digitalWrite(led4, LOW);      delay(delayloop);  
  digitalWrite(led5, HIGH);     delay(delayloop);              
  digitalWrite(led5, LOW);      delay(delayloop);       }
}
void scrollpairup() {
 digitalWrite(led0, HIGH);   delay(delaytimeX);
 digitalWrite(led3, HIGH);   delay(delaytimeX);  
 digitalWrite(led1, HIGH);   delay(delaytimeX);
 digitalWrite(led4, HIGH);   delay(delaytimeX);
 digitalWrite(led2, HIGH);   delay(delaytimeX);
 digitalWrite(led5, HIGH);   delay(delaytimeX);  
}
void scrollpairdown(){
 digitalWrite(led0, LOW);   delay(delaytimeX);
 digitalWrite(led3, LOW);   delay(delaytimeX);  
 digitalWrite(led1, LOW);   delay(delaytimeX);
 digitalWrite(led4, LOW);   delay(delaytimeX);
 digitalWrite(led2, LOW);   delay(delaytimeX);
 digitalWrite(led5, LOW);   delay(delaytimeX);    
}
void lightdown() {
 digitalWrite(led5, LOW);   delay(delaytimeX);
 digitalWrite(led4, LOW);   delay(delaytimeX);
 digitalWrite(led3, LOW);   delay(delaytimeX);  
 digitalWrite(led2, LOW);   delay(delaytimeX);
 digitalWrite(led1, LOW);   delay(delaytimeX);
}

void lightup() {
 digitalWrite(led0, HIGH);   delay(delaytimeX);
 digitalWrite(led1, HIGH);   delay(delaytimeX);  
 digitalWrite(led2, HIGH);   delay(delaytimeX);
 digitalWrite(led3, HIGH);   delay(delaytimeX);
 digitalWrite(led4, HIGH);   delay(delaytimeX);
 digitalWrite(led5, HIGH);   delay(delaytimeX); 
}
void scrollup() {
  digitalWrite(led0, HIGH);     delay(delaytime);              
  digitalWrite(led0, LOW);      delay(delaytime);  
  digitalWrite(led1, HIGH);     delay(delaytime);              
  digitalWrite(led1, LOW);      delay(delaytime);
  digitalWrite(led2, HIGH);     delay(delaytime);              
  digitalWrite(led2, LOW);      delay(delaytime);  
  digitalWrite(led3, HIGH);     delay(delaytime);              
  digitalWrite(led3, LOW);      delay(delaytime);  
  digitalWrite(led4, HIGH);     delay(delaytime);              
  digitalWrite(led4, LOW);      delay(delaytime);  
  digitalWrite(led5, HIGH);     delay(delaytime);              
  digitalWrite(led5, LOW);      delay(delaytime); 
}
void scrolldown() {
  digitalWrite(led4, HIGH);     delay(delaytime);              
  digitalWrite(led4, LOW);      delay(delaytime);  
  digitalWrite(led3, HIGH);     delay(delaytime);              
  digitalWrite(led3, LOW);      delay(delaytime);   
  digitalWrite(led2, HIGH);     delay(delaytime);              
  digitalWrite(led2, LOW);      delay(delaytime);  
  digitalWrite(led1, HIGH);     delay(delaytime);              
  digitalWrite(led1, LOW);      delay(delaytime);
 }
 
 void test() {
   digitalWrite(led3, HIGH);
 }
 void fadecrossreverse(){
 for(int fadeValue = 0 ; fadeValue <= 255; fadeValue +=fadeIncriment2) { 
    analogWrite(led2, fadeValue);  
    analogWrite(led3, fadeValue);   delay(30);      } 
    
 for(int fadeValue = 255 ; fadeValue >= 0; fadeValue -=fadeIncriment2) { 
    analogWrite(led2, fadeValue);  
    analogWrite(led3, fadeValue);    delay(30);     }
      
 for(int fadeValue = 0 ; fadeValue <= 255; fadeValue +=fadeIncriment2) { 
    analogWrite(led1, fadeValue);  
    analogWrite(led4, fadeValue);    delay(30);     } 
      
 for(int fadeValue = 255 ; fadeValue >= 0; fadeValue -=fadeIncriment2) { 
    analogWrite(led1, fadeValue);  
    analogWrite(led4, fadeValue);    delay(30);      }
  
 for(int fadeValue = 0 ; fadeValue <= 255; fadeValue +=fadeIncriment2) { 
    analogWrite(led0, fadeValue);  
    analogWrite(led5, fadeValue);    delay(30);       } 
    
 for(int fadeValue = 255 ; fadeValue >= 0; fadeValue -=fadeIncriment2) { 
    analogWrite(led0, fadeValue);  
    analogWrite(led5, fadeValue);    delay(30);       }
}
void fadecross(){
   for(int fadeValue = 0 ; fadeValue <= 255; fadeValue +=fadeIncriment2) { 
    analogWrite(led0, fadeValue);  
    analogWrite(led5, fadeValue); 
      delay(30);   
      } 
  for(int fadeValue = 255 ; fadeValue >= 0; fadeValue -=fadeIncriment2) { 
    analogWrite(led0, fadeValue);  
    analogWrite(led5, fadeValue);    
      delay(30);                                            }
      
       for(int fadeValue = 0 ; fadeValue <= 255; fadeValue +=fadeIncriment2) { 
    analogWrite(led1, fadeValue);  
    analogWrite(led4, fadeValue); 
      delay(30);                                           } 
  for(int fadeValue = 255 ; fadeValue >= 0; fadeValue -=fadeIncriment2) { 
    analogWrite(led1, fadeValue);  
    analogWrite(led4, fadeValue);         
      delay(30);                                          }
  
         for(int fadeValue = 0 ; fadeValue <= 255; fadeValue +=fadeIncriment2) { 
    analogWrite(led2, fadeValue);  
    analogWrite(led3, fadeValue); 
      delay(30);                                           } 
  for(int fadeValue = 255 ; fadeValue >= 0; fadeValue -=fadeIncriment2) { 
    analogWrite(led2, fadeValue);  
    analogWrite(led3, fadeValue);         
      delay(30);                                          } 
}
void fadethree() {
   for(int fadeValue = 0 ; fadeValue <= 255; fadeValue +=fadeIncriment2) { 
    analogWrite(led0, fadeValue);  
    analogWrite(led1, fadeValue); 
    analogWrite(led2, fadeValue); 
      delay(30);                                           } 
  for(int fadeValue = 255 ; fadeValue >= 0; fadeValue -=fadeIncriment2) { 
    analogWrite(led0, fadeValue);  
    analogWrite(led1, fadeValue); 
    analogWrite(led2, fadeValue);          
      delay(30);                                            }
      
       for(int fadeValue = 0 ; fadeValue <= 255; fadeValue +=fadeIncriment2) { 
    analogWrite(led3, fadeValue);  
    analogWrite(led4, fadeValue); 
    analogWrite(led5, fadeValue); 
      delay(30);                                           } 
  for(int fadeValue = 255 ; fadeValue >= 0; fadeValue -=fadeIncriment2) { 
    analogWrite(led3, fadeValue);  
    analogWrite(led4, fadeValue); 
    analogWrite(led5, fadeValue);          
      delay(30);                                          }
}

void fade()  { 
    for(int fadeValue = 0 ; fadeValue <= 255; fadeValue +=fadeIncriment) { 
    analogWrite(led0, fadeValue);           delay(30);                                           } 
  for(int fadeValue = 255 ; fadeValue >= 0; fadeValue -=fadeIncriment) { 
     analogWrite(led0, fadeValue);          delay(30);      }                      
                                                             
  for(int fadeValue = 0 ; fadeValue <= 255; fadeValue +=fadeIncriment) { 
    analogWrite(led1, fadeValue);           delay(30);                                           } 
  for(int fadeValue = 255 ; fadeValue >= 0; fadeValue -=fadeIncriment) { 
     analogWrite(led1, fadeValue);          delay(30);      }                      
                                                            
   for(int fadeValue = 0 ; fadeValue <= 255; fadeValue +=fadeIncriment) { 
    analogWrite(led2, fadeValue);           delay(30);                                           } 
  for(int fadeValue = 255 ; fadeValue >= 0; fadeValue -=fadeIncriment) { 
     analogWrite(led2, fadeValue);          delay(30);       }                     
                                                                 
    for(int fadeValue = 0 ; fadeValue <= 255; fadeValue +=fadeIncriment) { 
    analogWrite(led3, fadeValue);           delay(30);                                           } 
  for(int fadeValue = 255 ; fadeValue >= 0; fadeValue -=fadeIncriment) { 
    analogWrite(led3, fadeValue);           delay(30);       }                     
                                                                                                                  
   for(int fadeValue = 0 ; fadeValue <= 255; fadeValue +=fadeIncriment) { 
    analogWrite(led4, fadeValue);           delay(30);                                           } 
  for(int fadeValue = 255 ; fadeValue >= 0; fadeValue -=fadeIncriment) { 
    analogWrite(led4, fadeValue);           delay(30);        }                     
                                                            
  for(int fadeValue = 0 ; fadeValue <= 255; fadeValue +=fadeIncriment) { 
    analogWrite(led5, fadeValue);           delay(30);                                           } 
  for(int fadeValue = 255 ; fadeValue >= 0; fadeValue -=fadeIncriment) { 
    analogWrite(led5, fadeValue);           delay(30);       }                     
                                                             
}
