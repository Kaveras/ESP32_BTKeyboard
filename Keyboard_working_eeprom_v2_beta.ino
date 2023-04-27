#include <BleKeyboard.h>
#include <Preferences.h>

int type1;
char b1_1_0,b1_2_1,b1_3_2;
int b1_2_0,b1_3_0,b1_3_1,b1_4_0;


int type2;
char b2_1_0,b2_2_1,b2_3_2;
int b2_2_0,b2_3_0,b2_3_1,b2_4_0;

int type3;
char b3_1_0,b3_2_1,b3_3_2;
int b3_2_0,b3_3_0,b3_3_1,b3_4_0;

int type4;
char b4_1_0,b4_2_1,b4_3_2;
int b4_2_0,b4_3_0,b4_3_1,b4_4_0;

int type5;
char b5_1_0,b5_2_1,b5_3_2;
int b5_2_0,b5_3_0,b5_3_1,b5_4_0;

int type6;
char b6_1_0,b6_2_1,b6_3_2;
int b6_2_0,b6_3_0,b6_3_1,b6_4_0;

int type7;
char b7_1_0,b7_2_1,b7_3_2;
int b7_2_0,b7_3_0,b7_3_1,b7_4_0;

int type8;
char b8_1_0,b8_2_1,b8_3_2;
int b8_2_0,b8_3_0,b8_3_1,b8_4_0;



void button1();
void button2();
void button3();
void button4();
void button5();
void button6();
void button7();
void button8();

int sprawdz_str();


void buttonConf(String S1, String S2);

void buttonConf(String S1, String S2, String S3);

void buttonConf(String S1, String S2, String S3, String S4);


int space_p0,space_p1,space_p2=-1;

String S1,S2,S3,S4;

#define BUTTON_PIN1 4
#define BUTTON_PIN2 5
#define BUTTON_PIN3 27
#define BUTTON_PIN4 26
#define BUTTON_PIN5 25
#define BUTTON_PIN6 33
#define BUTTON_PIN7 32
#define BUTTON_PIN8 16

int lastState = HIGH; // the previous state from the input pin
int currentState;     // the current reading from the input pin

int lastState1 = HIGH; // the previous state from the input pin
int currentState1;     // the current reading from the input pin

int lastState2 = HIGH; // the previous state from the input pin
int currentState2;     // the current reading from the input pin

int lastState3 = HIGH; // the previous state from the input pin
int currentState3;     // the current reading from the input pin

int lastState4 = HIGH; // the previous state from the input pin
int currentState4;     // the current reading from the input pin

int lastState5 = HIGH; // the previous state from the input pin
int currentState5;     // the current reading from the input pin

int lastState6 = HIGH; // the previous state from the input pin
int currentState6;     // the current reading from the input pin

int lastState7 = HIGH; // the previous state from the input pin
int currentState7;     // the current reading from the input pin

Preferences preferences;
BleKeyboard bleKeyboard;

void setup() {
  Serial.begin(115200);
  Serial.read();
  Serial.println("Starting BLE work!");
  bleKeyboard.begin();
  pinMode(BUTTON_PIN1, INPUT_PULLUP);
  pinMode(BUTTON_PIN2, INPUT_PULLUP);
  pinMode(BUTTON_PIN3, INPUT_PULLUP);
  pinMode(BUTTON_PIN4, INPUT_PULLUP);
  pinMode(BUTTON_PIN5, INPUT_PULLUP);
  pinMode(BUTTON_PIN6, INPUT_PULLUP);
  pinMode(BUTTON_PIN7, INPUT_PULLUP);
  pinMode(BUTTON_PIN8, INPUT_PULLUP);
  button1();
  button2();
  button3();
  button4();
  button5();
  button6();
  button7();
  button8();
}

void loop() {
   // Serial.println(digitalRead(BUTTON_PIN1));
    //Serial.println(digitalRead(BUTTON_PIN2));

currentState = digitalRead(BUTTON_PIN1);
currentState1 = digitalRead(BUTTON_PIN2);
currentState2 = digitalRead(BUTTON_PIN3);
currentState3 = digitalRead(BUTTON_PIN4);
currentState4 = digitalRead(BUTTON_PIN5);
currentState5 = digitalRead(BUTTON_PIN6);
currentState6 = digitalRead(BUTTON_PIN7);
currentState7 = digitalRead(BUTTON_PIN8);


// check if data is available
  if (Serial.available() > 0) {
    // read the incoming string:
    String incomingString = Serial.readString();
    // prints the received data
    Serial.print("I received: ");
    Serial.println(incomingString);
    int tryb;
    tryb=sprawdz_str(incomingString);
    Serial.print("tryb: ");
    Serial.println(tryb);
    
    if(tryb==1){ 
      buttonConf(S1, S2);
      }
    if(tryb==2){
      buttonConf(S1, S2,S3);
      }
     if(tryb==3){
      buttonConf(S1, S2,S3,S4);
      }
     button1();
     button2();
     button3();
     button4();
     button5();
     button6();
     button7();
     button8();   
  }
if(bleKeyboard.isConnected()) {
   if(currentState!=lastState && !currentState){
   action1();}
   if(currentState1!=lastState1 && !currentState1){
   action2();}
   if(currentState2!=lastState2 && !currentState2){
   action3();}
   if(currentState3!=lastState3 && !currentState3){
   action4();}
   if(currentState4!=lastState4 && !currentState4){
   action5();}
   if(currentState5!=lastState5 && !currentState5){
   action6();}
   if(currentState6!=lastState6 && !currentState6){ //
   action7();}
   if(currentState7!=lastState7 && !currentState7){ // pin 35 i 34 maja odwrocona logike ? 
   action8();}

   lastState = currentState;
   lastState1 = currentState1;
   lastState2 = currentState2;
   lastState3 = currentState3;
   lastState4 = currentState4;
   lastState5 = currentState5;
   lastState6 = currentState6;
   lastState7 = currentState7;
}  
   /*char buf[30];
   S1.toCharArray(buf,6);
   preferences.begin(buf, false);
   int typ=preferences.getInt("Type");
   if(typ==1){
    Serial.println(preferences.getInt("Type"));
    Serial.println(preferences.getChar("Przycisk_t1_b1"));
    }
   if(typ==2){
    Serial.println(preferences.getInt("Type"));
    Serial.println(preferences.getInt("Przycisk_t2_b1"));
    Serial.println(preferences.getChar("Przycisk_t2_b2"));
    }
   if(typ==3){
    Serial.println(preferences.getInt("Type"));
    Serial.println(preferences.getInt("Przycisk_t3_b1"));
    Serial.println(preferences.getInt("Przycisk_t3_b2"));
    Serial.println(preferences.getChar("Przycisk_t3_b3"));
    }
   preferences.end();*/
   S1,S2,S3,S4="";
   delay(10);
}

void action1()
{
   Serial.println("przycisk 1 : ");
      if(type1==1)
      {
        bleKeyboard.write(b1_1_0);
      }
      if(type1==2)
      {
        bleKeyboard.press(b1_2_0);
        bleKeyboard.press(b1_2_1);
        bleKeyboard.releaseAll();
      }
      if(type1==3)
      {
        bleKeyboard.press(b1_3_0);
        bleKeyboard.press(b1_3_1);
        bleKeyboard.press(b1_3_2);
        bleKeyboard.releaseAll();
      }
      if(type1==4)
      {
        uint8_t mediaKey[2]={b1_4_0,0};
        bleKeyboard.write(mediaKey);
      }
}

void action2()
{
  Serial.println("przycisk 2 : ");
  //Serial.print("Type: ");
  //Serial.print(type2);
      if(type2==1)
      {
        bleKeyboard.write(b2_1_0);
      }
      if(type2==2)
      {
        bleKeyboard.press(b2_2_0);
        bleKeyboard.press(b2_2_1);
        bleKeyboard.releaseAll();
      }
      if(type2==3)
      {
        bleKeyboard.press(b2_3_0);
        bleKeyboard.press(b2_3_1);
        bleKeyboard.press(b2_3_2);
        bleKeyboard.releaseAll();
      }
      if(type2==4)
      {
        uint8_t mediaKey[2]={b2_4_0,0};
        Serial.print(mediaKey[0]);
        Serial.print(mediaKey[1]);
        Serial.print(b2_4_0);
        bleKeyboard.write(mediaKey);
      }
}

void action3()
{
  Serial.println("przycisk 3 : ");
      if(type3==1)
      {
        bleKeyboard.write(b3_1_0);
      }
      if(type3==2)
      {
        bleKeyboard.press(b3_2_0);
        bleKeyboard.press(b3_2_1);
        bleKeyboard.releaseAll();
      }
      if(type3==3)
      {
        bleKeyboard.press(b3_3_0);
        bleKeyboard.press(b3_3_1);
        bleKeyboard.press(b3_3_2);
        bleKeyboard.releaseAll();
      }
      if(type3==4)
      {
        uint8_t mediaKey[2]={b3_4_0,0};
        bleKeyboard.write(mediaKey);
      }
}

void action4()
{
  Serial.println("przycisk 4 : ");
      if(type4==1)
      {
        bleKeyboard.write(b4_1_0);
      }
      if(type4==2)
      {
        bleKeyboard.press(b4_2_0);
        bleKeyboard.press(b4_2_1);
        bleKeyboard.releaseAll();
      }
      if(type4==3)
      {
        bleKeyboard.press(b4_3_0);
        bleKeyboard.press(b4_3_1);
        bleKeyboard.press(b4_3_2);
        bleKeyboard.releaseAll();
      }
      if(type4==4)
      {
        uint8_t mediaKey[2]={b4_4_0,0};
        bleKeyboard.write(mediaKey);
      }
}

void action5()
{
  Serial.println("przycisk 5 : ");
      if(type5==1)
      {
        bleKeyboard.write(b5_1_0);
      }
      if(type5==2)
      {
        bleKeyboard.press(b5_2_0);
        bleKeyboard.press(b5_2_1);
        bleKeyboard.releaseAll();
      }
      if(type5==3)
      {
        bleKeyboard.press(b5_3_0);
        bleKeyboard.press(b5_3_1);
        bleKeyboard.press(b5_3_2);
        bleKeyboard.releaseAll();
      }
      if(type5==4)
      {
        uint8_t mediaKey[2]={b5_4_0,0};
        bleKeyboard.write(mediaKey);
      }
}

void action6()
{
  Serial.println("przycisk 6 : ");
      if(type6==1)
      {
        bleKeyboard.write(b6_1_0);
      }
      if(type6==2)
      {
        bleKeyboard.press(b6_2_0);
        bleKeyboard.press(b6_2_1);
        bleKeyboard.releaseAll();
      }
      if(type6==3)
      {
        bleKeyboard.press(b6_3_0);
        bleKeyboard.press(b6_3_1);
        bleKeyboard.press(b6_3_2);
        bleKeyboard.releaseAll();
      }
      if(type6==4)
      {
        uint8_t mediaKey[2]={b6_4_0,0};
        bleKeyboard.write(mediaKey);
      }
}

void action7()
{
  Serial.println("przycisk 7 : ");
      if(type7==1)
      {
        bleKeyboard.write(b7_1_0);
      }
      if(type7==2)
      {
        bleKeyboard.press(b7_2_0);
        bleKeyboard.press(b7_2_1);
        bleKeyboard.releaseAll();
      }
      if(type7==3)
      {
        bleKeyboard.press(b7_3_0);
        bleKeyboard.press(b7_3_1);
        bleKeyboard.press(b7_3_2);
        bleKeyboard.releaseAll();
      }
      if(type7==4)
      {
        uint8_t mediaKey[2]={b7_4_0,0};
        bleKeyboard.write(mediaKey);
      }
}

void action8()
{
  Serial.println("przycisk 8 : ");
      if(type8==1)
      {
        bleKeyboard.write(b8_1_0);
      }
      if(type8==2)
      {
        bleKeyboard.press(b8_2_0);
        bleKeyboard.press(b8_2_1);
        bleKeyboard.releaseAll();
      }
      if(type8==3)
      {
        bleKeyboard.press(b8_3_0);
        bleKeyboard.press(b8_3_1);
        bleKeyboard.press(b8_3_2);
        bleKeyboard.releaseAll();
      }
      if(type8==4)
      {
        uint8_t mediaKey[2]={b8_4_0,0};
        bleKeyboard.write(mediaKey);
      }
}
int sprawdz_str(String incstr){

    space_p0=incstr.indexOf(' ',0);
    space_p1=incstr.indexOf(' ',space_p0+1);
    if(space_p1>=0){
    space_p2=incstr.indexOf(' ',space_p1+1);
    }else{
      space_p2=-1;
      }
    
    if(space_p0<=0){
    Serial.print("bez spacji : ");
    S1=incstr.substring(0);
    Serial.println(S1);
    S2="";
    S3="";
    S4="";
    return 0;
    }
    if(space_p0>=0 && space_p1<=0){
    Serial.print("1 spacja 1 slowo : ");
    S1=incstr.substring(0,space_p0);
    Serial.println(S1);
    Serial.print("1 spacja 2 slowo : ");
    S2=incstr.substring(space_p0+1);
    Serial.println(S2);
    S3="";
    S4="";
    return 1;
    }
    if(space_p0>=0 && space_p1>=0 && space_p2<=0){
    Serial.print("2 spacje 1 slowo : ");
    S1=incstr.substring(0,space_p0);
    Serial.println(S1);
    Serial.print("2 spacje 2 slowo : ");
    S2=incstr.substring(space_p0+1,space_p1);
    Serial.println(S2);
    Serial.print("2 spacje 3 slowo : ");
    S3=incstr.substring(space_p1+1);
    Serial.println(S3);
    S4="";
    return 2;
    }
    if(space_p0>=0 && space_p1>=0 && space_p2>=0){
    Serial.print("3 spacje 1 slowo : ");
    S1=incstr.substring(0,space_p0);
    Serial.println(S1);
    Serial.print("3 spacje 2 slowo : ");
    S2=incstr.substring(space_p0+1,space_p1);
    Serial.println(S2);
    Serial.print("3 spacje 3 slowo : ");
    S3=incstr.substring(space_p1+1,space_p2);
    Serial.println(S3);
    Serial.print("3 spacje 4 slowo : ");
    S4=incstr.substring(space_p2+1);
    Serial.println(S4);
    return 3;
    }
  return 0;
}


void button1()
{
  preferences.begin("1", false);
  int type;
  type=preferences.getInt("Type");
  preferences.end();
  if(type==1){
    preferences.begin("1", false);
    type1=preferences.getInt("Type");
    b1_1_0=preferences.getChar("Przycisk_t1_b1");
    preferences.end();
    }
  if(type==2){
    preferences.begin("1", false);
    type1=preferences.getInt("Type");
    b1_2_0=preferences.getInt("Przycisk_t2_b1");
    b1_2_1=preferences.getChar("Przycisk_t2_b2");
    preferences.end();
    }
  if(type1==3){
    preferences.begin("1", false);
    type1=preferences.getInt("Type");
    b1_3_0=preferences.getInt("Przycisk_t3_b1");
    b1_3_1=preferences.getInt("Przycisk_t3_b2");
    b1_3_2=preferences.getChar("Przycisk_t3_b3");
    preferences.end();
    }
  if(type==4){
    preferences.begin("1", false);
    type1=preferences.getInt("Type");
    b1_4_0=preferences.getInt("Przycisk_t4_b1");
    preferences.end();
    }
  }

void button2()
{

  preferences.begin("2", false);
  int type;
  type=preferences.getInt("Type");
  preferences.end();
  
  if(type==1){
    preferences.begin("2", false);
    type2=preferences.getInt("Type");
    b2_1_0=preferences.getChar("Przycisk_t1_b1");
    preferences.end();
    }
  if(type==2){
    preferences.begin("2", false);
    type2=preferences.getInt("Type");
    b2_2_0=preferences.getInt("Przycisk_t2_b1");
    b2_2_1=preferences.getChar("Przycisk_t2_b2");
    preferences.end();
    }
  if(type==3){
    preferences.begin("2", false);
    type2=preferences.getInt("Type");
    b2_3_0=preferences.getInt("Przycisk_t3_b1");
    b2_3_1=preferences.getInt("Przycisk_t3_b2");
    b2_3_2=preferences.getChar("Przycisk_t3_b3");
    preferences.end();
    }
  if(type==4){
    preferences.begin("2", false);
    type2=preferences.getInt("Type");
    b2_4_0=preferences.getInt("Przycisk_t4_b1");
    preferences.end();
    }
  }

void button3()
{
  preferences.begin("3", false);
  int type;
  type=preferences.getInt("Type");
  preferences.end();
  
  if(type==1){
    preferences.begin("3", false);
    type3=preferences.getInt("Type");
    b3_1_0=preferences.getChar("Przycisk_t1_b1");
    preferences.end();
    }
  if(type==2){
    preferences.begin("3", false);
    type3=preferences.getInt("Type");
    b3_2_0=preferences.getInt("Przycisk_t2_b1");
    b3_2_1=preferences.getChar("Przycisk_t2_b2");
    preferences.end();
    }
  if(type==3){
    preferences.begin("3", false);
    type3=preferences.getInt("Type");
    b3_3_0=preferences.getInt("Przycisk_t3_b1");
    b3_3_1=preferences.getInt("Przycisk_t3_b2");
    b3_3_2=preferences.getChar("Przycisk_t3_b3");
    preferences.end();
    }
  if(type==4){
    preferences.begin("3", false);
    type3=preferences.getInt("Type");
    b3_4_0=preferences.getInt("Przycisk_t4_b1");
    preferences.end();
    }
  }

void button4()
{
  preferences.begin("4", false);
  int type;
  type=preferences.getInt("Type");
  preferences.end();
  
  if(type==1){
    preferences.begin("4", false);
    type4=preferences.getInt("Type");
    b4_1_0=preferences.getChar("Przycisk_t1_b1");
    preferences.end();
    }
  if(type==2){
    preferences.begin("4", false);
    type4=preferences.getInt("Type");
    b4_2_0=preferences.getInt("Przycisk_t2_b1");
    b4_2_1=preferences.getChar("Przycisk_t2_b2");
    preferences.end();
    }
  if(type==3){
    preferences.begin("4", false);
    type4=preferences.getInt("Type");
    b4_3_0=preferences.getInt("Przycisk_t3_b1");
    b4_3_1=preferences.getInt("Przycisk_t3_b2");
    b4_3_2=preferences.getChar("Przycisk_t3_b3");
    preferences.end();
    }
  if(type==4){
    preferences.begin("4", false);
    type4=preferences.getInt("Type");
    b4_4_0=preferences.getInt("Przycisk_t4_b1");
    preferences.end();
    }
  }

void button5()
{
  preferences.begin("5", false);
  int type;
  type=preferences.getInt("Type");
  preferences.end();
  
  if(type==1){
    preferences.begin("5", false);
    type5=preferences.getInt("Type");
    b5_1_0=preferences.getChar("Przycisk_t1_b1");
    preferences.end();
    }
  if(type==2){
    preferences.begin("5", false);
    type5=preferences.getInt("Type");
    b5_2_0=preferences.getInt("Przycisk_t2_b1");
    b5_2_1=preferences.getChar("Przycisk_t2_b2");
    preferences.end();
    }
  if(type==3){
    preferences.begin("5", false);
    type5=preferences.getInt("Type");
    b5_3_0=preferences.getInt("Przycisk_t3_b1");
    b5_3_1=preferences.getInt("Przycisk_t3_b2");
    b5_3_2=preferences.getChar("Przycisk_t3_b3");
    preferences.end();
    }
  if(type==4){
    preferences.begin("5", false);
    type5=preferences.getInt("Type");
    b5_4_0=preferences.getInt("Przycisk_t4_b1");
    preferences.end();
    }
  }

 void button6()
{
  preferences.begin("6", false);
  int type;
  type=preferences.getInt("Type");
  preferences.end();
  
  if(type==1){
    preferences.begin("6", false);
    type6=preferences.getInt("Type");
    b6_1_0=preferences.getChar("Przycisk_t1_b1");
    preferences.end();
    }
  if(type==2){
    preferences.begin("6", false);
    type6=preferences.getInt("Type");
    b6_2_0=preferences.getInt("Przycisk_t2_b1");
    b6_2_1=preferences.getChar("Przycisk_t2_b2");
    preferences.end();
    }
  if(type==3){
    preferences.begin("6", false);
    type6=preferences.getInt("Type");
    b6_3_0=preferences.getInt("Przycisk_t3_b1");
    b6_3_1=preferences.getInt("Przycisk_t3_b2");
    b6_3_2=preferences.getChar("Przycisk_t3_b3");
    preferences.end();
    }
  if(type==4){
    preferences.begin("6", false);
    type6=preferences.getInt("Type");
    b6_4_0=preferences.getInt("Przycisk_t4_b1");
    preferences.end();
    }
  }

 void button7()
{
  preferences.begin("7", false);
  int type;
  type=preferences.getInt("Type");
  preferences.end();
  
  if(type==1){
    preferences.begin("7", false);
    type7=preferences.getInt("Type");
    b7_1_0=preferences.getChar("Przycisk_t1_b1");
    preferences.end();
    }
  if(type==2){
    preferences.begin("7", false);
    type7=preferences.getInt("Type");
    b7_2_0=preferences.getInt("Przycisk_t2_b1");
    b7_2_1=preferences.getChar("Przycisk_t2_b2");
    preferences.end();
    }
  if(type==3){
    preferences.begin("7", false);
    type7=preferences.getInt("Type");
    b7_3_0=preferences.getInt("Przycisk_t3_b1");
    b7_3_1=preferences.getInt("Przycisk_t3_b2");
    b7_3_2=preferences.getChar("Przycisk_t3_b3");
    preferences.end();
    }
  if(type==4){
    preferences.begin("7", false);
    type7=preferences.getInt("Type");
    b7_4_0=preferences.getInt("Przycisk_t4_b1");
    preferences.end();
    }
  }

 void button8()
{
  preferences.begin("8", false);
  int type;
  type=preferences.getInt("Type");
  preferences.end();
  
  if(type==1){
    preferences.begin("8", false);
    type8=preferences.getInt("Type");
    b8_1_0=preferences.getChar("Przycisk_t1_b1");
    preferences.end();
    }
  if(type==2){
    preferences.begin("8", false);
    type8=preferences.getInt("Type");
    b8_2_0=preferences.getInt("Przycisk_t2_b1");
    b8_2_1=preferences.getChar("Przycisk_t2_b2");
    preferences.end();
    }
  if(type==3){
    preferences.begin("8", false);
    type8=preferences.getInt("Type");
    b8_3_0=preferences.getInt("Przycisk_t3_b1");
    b8_3_1=preferences.getInt("Przycisk_t3_b2");
    b8_3_2=preferences.getChar("Przycisk_t3_b3");
    preferences.end();
    }
  if(type==4){
    preferences.begin("8", false);
    type8=preferences.getInt("Type");
    b8_4_0=preferences.getInt("Przycisk_t4_b1");
    preferences.end();
    }
  }


void buttonConf(String S1, String S2)
{
      Serial.println("Tryb1");
      int but_nr=S1.toInt(); 
      Serial.print("Ktory przycisk: ");
      Serial.println(but_nr);
      //Serial.print("wynik definicji : ");
      //Serial.println(definicje(S2));
      
      if(definicje(S2)>0 && definicje(S2)<=64){
      Serial.print("PrzyciskMEDIA:  ");
      int mediaDef = definicje(S2);
      char buf[30];
      S1.toCharArray(buf,6);
      preferences.begin(buf, false);
      preferences.putInt("Type",4);
      preferences.putInt("Przycisk_t4_b1",mediaDef);
      preferences.end();
      
      }else{
      Serial.print("Przycisk:  ");
      char przycisk=S2[0];
      Serial.println(przycisk);
      char buf[30];
      S1.toCharArray(buf,6);
      preferences.begin(buf, false);
      preferences.putInt("Type",1);
      preferences.putChar("Przycisk_t1_b1",przycisk);
      preferences.end();
      }
  }

void buttonConf(String S1, String S2,String S3){
      //Serial.println("Tryb2");
      int but_nr=S1.toInt(); 
      //Serial.print("Ktory przycisk: ");
      //Serial.println(but_nr);
      //Serial.print("Ktora funkcja:  ");
      int defOut1=definicje(S2);
      
      //Serial.println(defOut1);
      char przycisk=S3[0];
      //Serial.println(przycisk);
      char buf[30];
      S1.toCharArray(buf,6);
      preferences.begin(buf, false);
      preferences.putInt("Type",2);
      preferences.putInt("Przycisk_t2_b1",defOut1);
      preferences.putChar("Przycisk_t2_b2",przycisk);
      preferences.end();
  }

void buttonConf(String S1, String S2,String S3,String S4){
     // Serial.println("Tryb2");
      int but_nr=S1.toInt(); 
      //Serial.print("Ktory przycisk: ");
      //Serial.println(but_nr);
     // Serial.print("Ktora funkcja:  ");
      int defOut3=definicje(S2);
     // Serial.println(przycisk);
      int defOut4=definicje(S3);
      char przycisk1=S4[0];
     // Serial.println(przycisk1);
      char buf[30];
      S1.toCharArray(buf,6);
      preferences.begin(buf, false);
      preferences.putInt("Type",3);
      preferences.putInt("Przycisk_t3_b1",defOut3);
      preferences.putInt("Przycisk_t3_b2",defOut4);
      preferences.putChar("Przycisk_t3_b3",przycisk1);
      preferences.end();
  
  }



int definicje(String str){
  if(str=="KEY_LEFT_CTRL")
    return 0x80;
  if(str=="KEY_LEFT_SHIFT")
    return 0x81;
  if(str=="KEY_LEFT_ALT")
    return 0x82;
  if(str=="KEY_LEFT_GUI")
    return 0x83;

  if(str=="KEY_RIGHT_CTRL")
    return 0x84;
    
  if(str== "KEY_RIGHT_SHIFT")
    return 0x85;
    
  if(str== "KEY_RIGHT_ALT")
    return 0x86;
    
  if(str== "KEY_RIGHT_GUI")
    return 0x87;
    
  if(str== "KEY_UP_ARROW")
    return 0xDA;
    
  if(str== "KEY_DOWN_ARROW")
    return 0xD9;
    
  if(str== "KEY_LEFT_ARROW")
    return 0xD8;
    
  if(str== "KEY_RIGHT_ARROW")
    return 0xD7;
    
  if(str== "KEY_BACKSPACE")
    return 0xB2;
    
  if(str== "KEY_TAB")
    return 0xB3;
    
  if(str== "KEY_RETURN")
    return 0xB0;
    
  if(str== "KEY_ESC")
    return 0xB1;
    
  if(str== "KEY_INSERT")
    return 0xD1;
    
  if(str== "KEY_PRTSC")
    return 0xCE;
    
  if(str== "KEY_DELETE")
    return 0xD4;
    
  if(str== "KEY_PAGE_UP")
    return 0xD3;
    
  if(str== "KEY_PAGE_DOWN")
    return 0xD6;
    
  if(str== "KEY_HOME")
    return 0xD2;
    
  if(str== "KEY_END")
    return 0xD5;
    
  if(str== "KEY_CAPS_LOCK")
    return 0xC1;
    
  if(str== "KEY_F1")
    return 0xC2;
    
  if(str== "KEY_F2")
    return 0xC3;
    
  if(str== "KEY_F3")
    return 0xC4;
    
  if(str== "KEY_F4")
    return 0xC5;
    
  if(str== "KEY_F5")
    return 0xC6;
    
  if(str== "KEY_F6")
    return 0xC7;
    
  if(str== "KEY_F7")
    return 0xC8;
    
  if(str== "KEY_F8")
    return 0xC9;
    
  if(str== "KEY_F9")
    return 0xCA;
    
  if(str== "KEY_F10")
    return 0xCB;
    
  if(str== "KEY_F11")
    return 0xCC;
    
  if(str== "KEY_F12")
    return 0xCD;
    
  if(str== "KEY_F13")
    return 0xF0;
    
  if(str== "KEY_F14")
    return 0xF1;
    
  if(str== "KEY_F15")
    return 0xF2;
    
  if(str== "KEY_F16")
    return 0xF3;
    
  if(str== "KEY_F17")
    return 0xF4;
    
  if(str== "KEY_F18")
    return 0xF5;
    
  if(str== "KEY_F19")
    return 0xF6;
    
  if(str== "KEY_F20")
    return 0xF7;
    
  if(str== "KEY_F21")
    return 0xF8;
    
  if(str== "KEY_F22")
    return 0xF9;
    
  if(str== "KEY_F23")
    return 0xFA;
    
  if(str== "KEY_F24")
    return 0xFB;
    
  if(str== "KEY_NUM_0")
    return 0xEA;
    
  if(str== "KEY_NUM_1")
    return 0xE1;
    
  if(str== "KEY_NUM_2")
    return 0xE2;
    
  if(str== "KEY_NUM_3")
    return 0xE3;
    
  if(str== "KEY_NUM_4")
    return 0xE4;
    
  if(str== "KEY_NUM_5")
    return 0xE5;
    
  if(str== "KEY_NUM_6")
    return 0xE6;
    
  if(str== "KEY_NUM_7")
    return 0xE7;
    
  if(str== "KEY_NUM_8")
    return 0xE8;
    
  if(str== "KEY_NUM_9")
    return 0xE9;
    
  if(str== "KEY_NUM_SLASH")
    return 0xDC;
    
  if(str== "KEY_NUM_ASTERISK")
    return 0xDD;
    
  if(str== "KEY_NUM_MINUS")
    return 0xDE;
    
  if(str== "KEY_NUM_PLUS")
    return 0xDF;
    
  if(str== "KEY_NUM_ENTER")
    return 0xE0;
    
  if(str== "KEY_NUM_PERIOD")
    return 0xEB;
    
  if(str== "KEY_MEDIA_NEXT_TRACK")
    return 1;

  if(str== "KEY_MEDIA_PREVIOUS_TRACK")
    return 2;

  if(str== "KEY_MEDIA_STOP")
    return 4;

  if(str== "KEY_MEDIA_PLAY_PAUSE")
    return 8;

  if(str== "KEY_MEDIA_MUTE")
    return 16;
    
  if(str== "KEY_MEDIA_VOLUME_UP")
    return 32;
    
  if(str== "KEY_MEDIA_VOLUME_DOWN")
    return 64;
    
   return 0;  
}
