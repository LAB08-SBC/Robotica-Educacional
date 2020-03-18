int turn_delay = 10;
  
//L293 Connection   
  const int A1A = 14;//define pin 2 for A1A
  const int A1B = 15;//define pin 3 for A1B
  const int B1A = 16;//define pin 8 for B1A
  const int B1B = 17;//define pin 9 for B1B

//Sensor Connection
  const int left_sensor_pin =9;
  const int right_sensor_pin =10;

  int left_sensor_state;
  int right_sensor_state;

void setup() {
  pinMode(B1A,OUTPUT);// define pin as output
  pinMode(B1B,OUTPUT);
  
  pinMode(A1A,OUTPUT);
  pinMode(A1B,OUTPUT);    
  delay(3000);
  
}

void motorA(char d)
{
  if(d =='R'){
    digitalWrite(A1A,LOW);
    digitalWrite(A1B,HIGH); 
  }else if (d =='L'){
    digitalWrite(A1A,HIGH);
    digitalWrite(A1B,LOW);    
  }else{
    //Robojax.com L9110 Motor Tutorial
    // Turn motor OFF
    digitalWrite(A1A,LOW);
    digitalWrite(A1B,LOW);    
  }
}

void motorB(char d)
{

    if(d =='R'){
      digitalWrite(B1A,LOW);
      digitalWrite(B1B,HIGH); 
    }else if(d =='L'){
      digitalWrite(B1A,HIGH);
      digitalWrite(B1B,LOW);    
    }else{
    //Robojax.com L9110 Motor Tutorial
    // Turn motor OFF      
      digitalWrite(B1A,LOW);
      digitalWrite(B1B,LOW);     
    }

}

void loop() {
  
left_sensor_state = digitalRead(left_sensor_pin);
right_sensor_state = digitalRead(right_sensor_pin);

if(right_sensor_state == HIGH && left_sensor_state == LOW)
{

    motorA('L');// Turn motor A to RIGHT
    motorB('O');// Stop motor B
  }
if(right_sensor_state == LOW && left_sensor_state == HIGH)
{  
    motorA('O');// Stop motor A
    motorB('L');// Turn motor B to RIGHT

  delay(turn_delay);
  }

if(right_sensor_state == LOW && left_sensor_state == LOW)
{
    motorA('L');// Turn motor A to RIGHT
    motorB('L');// Turn motor B to RIGHT

  delay(turn_delay);
  
  }

if(right_sensor_state == HIGH && left_sensor_state == HIGH)
{ 
  Serial.println("stop");
  
    motorA('O');// Stop motor A 
    motorB('O');// Stop motor B

  }
}
