/**********************************************************************************
 *                                                                                *
 *                       BENGALA ELETRONICA MICROCONTROLADA                       *
 *                            ANA CLARA AMORIM                                    *
 *                                                                                *
 *********************************************************************************/

#include <Ultrasonic.h>

#define pino_trigger  12
#define pino_echo     13
#define pino_pwm      3
#define pino_forte    11
#define digital 8
#define modo 9



Ultrasonic ultrasonic(pino_trigger, pino_echo);

void setup()
  {
  Serial.begin(9600);
  Serial.print("ANA CLARA AMORIM");
  Serial.print("\n\n");
  Serial.print("BENGALA ELETRONICA MICROCONTROLADA");
  Serial.print("\n\nLendo dados do sensor...\n\n");
  pinMode(8, INPUT);
  pinMode(9, OUTPUT);
  }

void loop()
  {
  float cm;
  long microsec = ultrasonic.timing();

  cm = ultrasonic.convert(microsec, Ultrasonic::CM);
  
  Serial.print("Distancia em cm: ");
  Serial.print(cm);

  delay(500); //tempo para estabilizar leitura 

  if(cm<50){                                    //ATIVAR VIBRAÇÃO FORTE
    analogWrite(pino_pwm, 183);                 //183: 3,6V
    analogWrite(pino_forte, 183);               //183: 3,6V  
    delay(300);                                 //tempo on
    }

  if((cm>=51)&&(cm<80)){                        //ATIVA VIBRAÇÃO DUPLA DE BAIXA INTENSIDADE
    analogWrite(pino_pwm, 133);                 //133: 2,6V
    analogWrite(pino_forte, 133);               //133: 2,6V
    delay(300);                                 //tempo on
    }

    if((cm>=81)&&(cm<100)){                      //ATIVA VIBRAÇÃO ÚNICA
    analogWrite(pino_pwm, 103);                  //133: 2,6V
    analogWrite(pino_forte, 0);                  //133: 0V
    delay(300);                                  //tempo on
    }

    if(cm>=100.1){                               //DESATIVA VIBRAÇÕES
    analogWrite(pino_pwm, 0);                    //133: 0V
    analogWrite(pino_forte, 0);                  //133: 0V
    }

     if(
       int val = digitalRead(digital); // le o valor na entrada
  if (val == HIGH) 
  {
   analogWrite(pino_pwm, 183); 
    delay(500);
    delay(500);
    digitalWrite(modo,HIGH); //Liga o BUZZER 
  }
  else
  {
    digitalWrite(modo, LOW); // Desliga BUZZER 
  }
  }
