#include <Keypad.h>

#include <LiquidCrystal.h>

const byte ROWS = 4; //four rows

const byte COLS = 4; //three columns

char keys[ROWS][COLS] = {

  {'1','2','3','A'},

  {'4','5','6','B'},

  {'7','8','9','C'},

  {'*','0','#','D'}

};

byte rowPins[ROWS] = {A0, A1, A2, A3}; //connect to the row pinouts of the keypad

byte colPins[COLS] = {A4, A5, 2, 8}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

// 16x2 LCD

#define rs 10

#define en 9

#define d4 6 

#define d5 5

#define d6 4

#define d7 3

// initialize the library with the numbers of the interface pins

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

String password = "1174";

String mypassword;

int redled = 12;

int lock = 13;

int servo = 7;

int counter = 0;

int attempts = 0;

int max_attempts = 3;

 

void setup(){

  Serial.begin(9600);

  // set up the LCD's number of columns and rows:

  lcd.begin(16, 2);

 

  pinMode(redled, OUTPUT);

  pinMode(lock, OUTPUT);
pinMode(servo, OUTPUT);
 

  digitalWrite(redled, HIGH);

  digitalWrite(lock, HIGH);

  digitalWrite(servo, LOW);

 

  Serial.println("enter password");
lcd.setCursor(0,0);

lcd.println("GUPTA VASTRALAYA");
    lcd.setCursor(0,1);
        lcd.print("Enter Password:");

}

 

void loop()

{

 keypadfunction();

}

void keypadfunction()

{

char key = keypad.getKey();

 

  if (key){
          lcd.clear();
lcd.println("Enter Password:-");
 digitalWrite(servo, HIGH);


delay(10);

digitalWrite(servo,LOW);     

    Serial.println(key);

    counter = counter + 1;

    lcd.setCursor(counter, 1);

    lcd.print("*");

  }

  if (key == '1')

  {

    mypassword = mypassword + 1;  

  }

 

    if (key == '2')

  {

    mypassword = mypassword + 2; 

  }

 

  if (key == '3')

  {

    mypassword = mypassword + 3;

  }

 

   if (key == '4')

  {

 

    mypassword = mypassword + 4; 

  }

 

  if (key == '5')

  {

 

    mypassword = mypassword + 5;

  }

 

   if (key == '6')

  {

  

    mypassword = mypassword + 6;

  }

 

   if (key == '7')

  {

    mypassword = mypassword + 7;

  }

   if (key == '8')

  {

    mypassword = mypassword + 8;

  }

 

  if (key == '9')

  {

    mypassword = mypassword + 9;

  }

            

                 if (key == '0')

  {

    mypassword = mypassword + 0;

  }

 

  

        if (key == '*')

  {

    Serial.println(mypassword);

    

if ( password == mypassword )

{

lcd.clear();

lcd.println("Welcome To");

lcd.setCursor(0,1);

lcd.println("Gupta Vastralaya");

digitalWrite(lock, LOW);



delay(3000);

digitalWrite(lock,HIGH);



mypassword = "";

counter = 0;

lcd.clear();

lcd.setCursor(0,0);

lcd.println("GUPTA VASTRALAYA");
lcd.setCursor(0,1);
lcd.println("Enter Password");

}

else

{

Serial.println("wrong");

digitalWrite(lock, HIGH);

digitalWrite(servo,HIGH);
            delay(500);
digitalWrite(servo,LOW);
attempts = attempts + 1;

if (attempts >= max_attempts )

{

  lcd.clear();

  lcd.setCursor(0,0);

  lcd.print("Locked wait-1min");

 

digitalWrite(redled, LOW);
  digitalWrite(servo, HIGH);             
delay(60000);

digitalWrite(redled, HIGH);
  digitalWrite(servo, LOW);               
attempts = 0;

 

}

mypassword = "";

counter = 0;

lcd.clear();

lcd.setCursor(0,0);

lcd.print("Wrong Password");

delay(1000);

lcd.setCursor(0,1);

lcd.print("Max Attempts 3");

delay(1000);

lcd.clear();

lcd.println("GUPTA VASTRALAYA");
            lcd.setCursor(0,1);
lcd.println("Enter Password:-");



}

   

  } 

  

  

}

 

 



 
