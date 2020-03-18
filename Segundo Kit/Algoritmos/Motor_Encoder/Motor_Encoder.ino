int pino_e = 2;
int pino_d = 3;

const int motorA1 =  14;
const int motorA2  = 15;
const int motorB1 =  16;
const int motorB2 =  17;

int rpm_e;
volatile byte pulsos_e;
unsigned long timeold_e;

int rpm_d;
volatile byte pulsos_d;
unsigned long timeold_d;

//Altere o numero abaixo de acordo com o seu disco encoder
unsigned int pulsos_por_volta = 20;

void contador_e(){  //Incrementa contador  
  pulsos_e++;
}

void contador_d(){  //Incrementa contador  
  pulsos_d++;
}

void setup(){ 
  
  pinMode( motorA1 , OUTPUT);
  pinMode( motorA2 , OUTPUT);

  pinMode( motorB1 , OUTPUT);
  pinMode( motorB2 , OUTPUT);
  
  Serial.begin(9600);  //Pino do sensor como entrada  
  
  pinMode(pino_e, INPUT);  //Interrupcao 0 - pino digital 2  
  pinMode(pino_d, INPUT);  //Interrupcao 0 - pino digital 3  

//Aciona o contador a cada pulso
  
 attachInterrupt(0, contador_e, FALLING); 
 pulsos_e = 0;  
 rpm_e = 0; 
 timeold_e = 0;

 attachInterrupt(digitalPinToInterrupt(3), contador_d, FALLING); 
 pulsos_d = 0;  
 rpm_d = 0; 
 timeold_d = 0;
}

void loop(){ 
 //Atualiza contador a cada segundo 
  digitalWrite(motorA1 , HIGH);
  digitalWrite(motorA2 , LOW);

  digitalWrite(motorB1 , HIGH);
  digitalWrite(motorB2 , LOW);
  
  //Atualiza contador da esquerda a cada segundo 
 if (millis() - timeold_e >= 1000)  {   //Desabilita interrupcao durante o calculo   
  detachInterrupt(0);    
  rpm_e = (60 * 1000 / pulsos_por_volta ) / (millis() - timeold_e) * pulsos_e;  
  timeold_e = millis();    
  pulsos_e = 0;   
  //Mostra o valor de RPM do motor da esquerda no serial monitor  
  Serial.print("RPM Esquerda = ");    
  Serial.println(rpm_e, DEC);    //Habilita interrupcao  
  attachInterrupt(0, contador_e, FALLING); 
 
  //Desabilita interrupcao durante o calculo   
  detachInterrupt(digitalPinToInterrupt(3));    
  rpm_d = (60 * 1000 / pulsos_por_volta ) / (millis() - timeold_d) * pulsos_d;  
  timeold_d = millis();    
  pulsos_d = 0;   
  //Mostra o valor de RPM do motor da direita no serial monitor  
  Serial.print("RPM Direita = ");    
  Serial.println(rpm_d, DEC);    //Habilita interrupcao  
  attachInterrupt(digitalPinToInterrupt(3), contador_d, FALLING); 
  }
}
