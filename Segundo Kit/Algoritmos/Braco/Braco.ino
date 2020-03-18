#include <Servo.h>

Servo dedos;
Servo avanco;
Servo elevacao;

int ang = 0;
int ang_a = 30;
int ang_e = 20;
;    // variable to store the servo position

void setup() {
  dedos.attach(4);
  avanco.attach(5);
  elevacao.attach(6);
  ;// attaches the servo on pin 9 to the servo object
}

void loop() {
  for (ang = 0; ang <= 80; ang += 1) { // movimento do 0 ao 80 grau
    // in steps of 1 degree
    dedos.write(ang);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (ang = 80; ang >= 0; ang -= 1) { // movimento do 80 ao 0 grau
    dedos.write(ang);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (ang_a = 30; ang_a <= 90; ang_a += 1) { // movimento do 0 ao 80 grau
    // in steps of 1 degree
    avanco.write(ang_a);
    delay(15);                       // waits 15ms for the servo to reach the position
  }
     for (ang_e = 20; ang_e <= 110; ang_e += 1) { // movimento do 0 ao 80 grau
    // in steps of 1 degree
    elevacao.write(ang_e);
    delay(15);                       // waits 15ms for the servo to reach the position
  }
     for (ang_e = 110; ang_e <= 20; ang_e -= 1) { // movimento do 0 ao 80 grau
    // in steps of 1 degree
    elevacao.write(ang_e);
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  
   for (ang_a = 90; ang_a <= 110; ang_a += 1) { // movimento do 0 ao 80 grau
    // in steps of 1 degree
    avanco.write(ang_a);
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  
  for (ang_a = 110; ang_a >= 30; ang_a -= 1) { // movimento do 80 ao 0 grau
    avanco.write(ang_a);
  }
}
