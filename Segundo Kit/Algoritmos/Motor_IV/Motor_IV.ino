const int motorA1 = 14;
const int motorA2  =15;
const int motorB1 = 16;
const int motorB2 = 17;
int SensorIV = 18;

void setup() {
  // put your setup code here, to run once:
  pinMode( motorA1 , OUTPUT);
  pinMode( motorA2 , OUTPUT);

  pinMode( motorB1 , OUTPUT);
  pinMode( motorB2 , OUTPUT);
  pinMode(SensorIV, INPUT); 
}

void loop() {
  int statusSensor = digitalRead (SensorIV);
  if(statusSensor == 1){ //SE A LEITURA DO PINO FOR IGUAL A LOW, FAZ
   digitalWrite( motorA1 , HIGH);
   digitalWrite( motorA2 , LOW);

   digitalWrite( motorB1 , HIGH);
   digitalWrite( motorB2 , LOW);
   
  }else{
   digitalWrite( motorA1 , HIGH);
   digitalWrite( motorA2 , HIGH);

   digitalWrite( motorB1 , HIGH);
   digitalWrite( motorB2 , HIGH);
  }
}
