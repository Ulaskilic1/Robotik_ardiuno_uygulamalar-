#define Sag_Motor 7// Motor pinlerini tanımlıyoruz
#define Sag_Motor2 6
#define Sag_MotorEn 9
#define Sol_Motor 5
#define Sol_Motor2 4
#define Sol_MotorEn 3
#define Sensor4 A0
#define Sensor3 A1
#define Sensor2 A2
#define Sensor1 A3

void setup() {


  pinMode(Sol_Motor, OUTPUT);
  pinMode(Sol_Motor2, OUTPUT);
  pinMode(Sol_MotorEn, OUTPUT); //Motorlarımızı çıkış olarak tanımlıyoruz.
  pinMode(Sag_Motor, OUTPUT);
  pinMode(Sag_Motor2, OUTPUT);
  pinMode(Sag_MotorEn, OUTPUT);
  pinMode(Sensor4, INPUT);
  pinMode(Sensor3, INPUT);
  pinMode(Sensor2, INPUT);
  pinMode(Sensor1, INPUT);

  Serial.begin(9600);

}

void loop() {

  Serial.println(digitalRead(Sensor1));

  if (digitalRead(Sensor3) == 0 && digitalRead(Sensor2) == 0)//düz
  {
    Serial.println("if1");
    ileri(150, 150);
  }
  else if (digitalRead(Sensor1) == 0 && digitalRead(Sensor2) == 0) //çizgini sağına kayarsa
  {
    Serial.println("if2");
    sol(70, 70);
  }
  else if (digitalRead(Sensor3) == 0 && digitalRead(Sensor4) == 0) //çizgini oluna kayarsa
  {
    Serial.println("if3");
    sag(70, 70);
  }
  else if (digitalRead(Sensor1) == 0) //çizgini sağına kayarsa
  {
    Serial.println("if4");
    sol(120, 120);
  }
  else if (digitalRead(Sensor4) == 0) //çizgini oluna kayarsa
  {
    Serial.println("if5");
    sag(120, 120);
  }

}

void ileri(int Sagpwm, int Solpwm) { // Robotun ileri yönde hareketi için fonksiyon tanımlıyoruz.

  digitalWrite(Sag_Motor, Sagpwm); // Sağ motorun ileri hareketi aktif
  digitalWrite(Sag_Motor2, LOW); // Sağ motorun geri hareketi pasif
  analogWrite(Sag_MotorEn, Sagpwm); // Sağ motorun hızı

  digitalWrite(Sol_Motor, Solpwm); // Sol motorun ileri hareketi aktif
  digitalWrite(Sol_Motor2, LOW); // Sol motorun geri hareketi pasif
  analogWrite(Sol_MotorEn, Solpwm); // Sol motorun hızı

}


void sag(int Sagpwm, int Solpwm) { // Robotun sağa dönme hareketi için fonksiyon tanımlıyoruz.

  digitalWrite(Sag_Motor, Sagpwm); // Sağ motorun ileri hareketi aktif
  digitalWrite(Sag_Motor2, LOW); // Sağ motorun geri hareketi pasif
  analogWrite(Sag_MotorEn, Sagpwm); // Sağ motorun hızı

  digitalWrite(Sol_Motor, LOW); // Sol motorun ileri hareketi aktif
  digitalWrite(Sol_Motor2, Solpwm); // Sol motorun geri hareketi pasif
  analogWrite(Sol_MotorEn, Solpwm); // Sol motorun hızı

}


void sol(int Sagpwm, int Solpwm) { // Robotun sağa dönme hareketi için fonksiyon tanımlıyoruz.

  digitalWrite(Sag_Motor, LOW); // Sağ motorun ileri hareketi aktif
  digitalWrite(Sag_Motor2, Sagpwm); // Sağ motorun geri hareketi pasif
  analogWrite(Sag_MotorEn, Sagpwm); // Sağ motorun hızı

  digitalWrite(Sol_Motor, Solpwm); // Sol motorun ileri hareketi aktif
  digitalWrite(Sol_Motor2, LOW); // Sol motorun geri hareketi pasif
  analogWrite(Sol_MotorEn, Solpwm); // Sol motorun hızı

}

