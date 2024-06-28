#include <AFMotor.h>
#include <SoftwareSerial.h>
#include <DFPlayerMini_Fast.h>

float max=28.3;
    
#define led A5
#define NOTE_B0 31

SoftwareSerial mySoftwareSerial(A1,A2); // RX, TX
DFPlayerMini_Fast myMP3;

int melody[] = {
    // Nada "bib" sederhana:
    NOTE_B0,
};

// inisialisasi motor
AF_DCMotor motor1(1); 
AF_DCMotor motor2(2);
AF_DCMotor motor3(3); 
AF_DCMotor motor4(4);

int kecepatan = 9; // Nilai default kecepatan

void setup() 
{        
  Serial.begin(9600);  //Set Baud Rate
   pinMode(led,OUTPUT);
    mySoftwareSerial.begin(9600);  
    myMP3.begin(mySoftwareSerial);
    myMP3.volume(15);
  
    
}

void loop() 
    {  
  if(Serial.available() > 0) 
  {
    char data = Serial.read();
        Serial.println(data);
     if(data=='U')
        {
            lampuOn();
           // musik();
            }
        else if(data=='u')
        {digitalWrite(led,LOW);}
    //Kontrol Motor
    if(data == 'F') //Maju
    {
      maju();
    }
    else if(data == 'B') //Mundur
    {
      mundur();
    }
    else if(data == 'L') //Belok Kiri
    {
      belokKiri();
    }
    else if(data == 'R') //Belok Kanan
    {
      belokKanan();
    }
    else if(data == 'I') //Maju Kiri
    {
      majuKiri();
    }
    else if(data == 'G') //Maju Kanan
    {
      majuKanan();
    }
    else if(data == 'J') //Mundur Kiri
    {
      mundurKiri();
    }
    else if(data == 'H') //Mundur Kanan
    {
      mundurKanan();
    }
    else if(data == 'S') //Berhenti
    {
      berhenti();
    }
        else if(data == 'V') //MUSIK
    {
      musik();
    }
     
    else if(data >= '0' && data <= '9') //Skala Kecepatan
    {
      kecepatan = data - '0'; // Simpan skala kecepatan dalam variabel kecepatan
      setKecepatan(kecepatan * max); // Skala kecepatan dari 0 (0*25.5) hingga 255 (9*25.5)
     
    }
  }
    
      
}

void setKecepatan(float kecepatan)
{
  motor1.setSpeed(kecepatan);
  motor2.setSpeed(kecepatan);
  motor3.setSpeed(kecepatan);
  motor4.setSpeed(kecepatan);
}

void maju()
{
  setKecepatan(kecepatan * max);
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}

void mundur()
{
  setKecepatan(kecepatan * max);
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
}

void belokKiri()
{
  //setKecepatan(kecepatan * 28);
     motor3.setSpeed((kecepatan-2)*max);
  motor3.run(BACKWARD);
     motor4.setSpeed((kecepatan-2)*max);
  motor4.run(BACKWARD);
    
     motor1.setSpeed((kecepatan)*max);  motor1.run(FORWARD);
     motor2.setSpeed((kecepatan)*max);
  motor2.run(FORWARD);
}

void belokKanan()
{
 // setKecepatan(kecepatan * 28);
   motor3.setSpeed((kecepatan-2)*max); 
  motor3.run(FORWARD);
    motor4.setSpeed((kecepatan-2)*max);
  motor4.run(FORWARD);
    
    motor2.setSpeed(kecepatan*max);
  motor2.run(BACKWARD);
     motor1.setSpeed(kecepatan*max);
  motor1.run(BACKWARD);
}

void majuKanan()
{
  setKecepatan(kecepatan * max);
  motor3.run(RELEASE);
  motor2.run(RELEASE);
    
  motor1.run(FORWARD);
  motor4.run(FORWARD);
}

void majuKiri()
{
  setKecepatan(kecepatan * max);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
    
  motor1.run(RELEASE);
  motor4.run(RELEASE);
}

void mundurKiri()
{
  setKecepatan(kecepatan * max);
  motor1.run(RELEASE);
  motor4.run(RELEASE);
  motor3.run(BACKWARD);
  motor2.run(BACKWARD);
}

void mundurKanan()
{
  setKecepatan(kecepatan * max);
  motor1.run(BACKWARD);
  motor4.run(BACKWARD);
  motor3.run(RELEASE);
  motor2.run(RELEASE);
}

void berhenti()
{
      motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}

void musik() {
   myMP3.play(random(1,7));
    
}

void lampuOn(){
    digitalWrite(led,HIGH);
    }
