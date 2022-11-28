#include "../include/Huella/Huella.cpp"
#include "../include/KeyPad/KeyPad.cpp"
#include "../include/WiFi/WiFi.cpp"



#define ledV2 18
#define ledR2 5
#define ledV1 23
#define ledR1 19

float Lectura_adc;
float volts;

String stringValue;
String contra_correcta;
String contra_ingresada;
bool veri1;
bool val1 = 0;

int pulsador1 = 0;

void contra_Veri(void);
void huella_veri(void);
void comparacion(void);

int pulsador2;
int Dato_Huella;

void setup() 
{
  pinMode(ledV1,OUTPUT);
  pinMode(ledR1,OUTPUT);
  Init_WiFi();
  Init_Huella();
  Serial.begin(9600);

}

void loop(){
  compRecvControl=!val1;
  while(val1==0){
  contra_Veri();
  comparacion(); 
  }
  Bucle();
  if(Veri2==1){
    digitalWrite(ledV2,HIGH);
    delay(5000);
    digitalWrite(ledV2,LOW);
  }
  else if (Veri2==0){
    digitalWrite(ledR2,HIGH);
    delay(5000);
    digitalWrite(ledR2,LOW);
  }
/*if (veri1 == 1 && veri2 == 1){
  digitalWrite(LedA,HIGH);
  //Programar accionar del servo motor.
  //Por ahora usamos un led azul para indicar que se abrió la puerta
}
*/

}

void contra_Veri(){
  char key = teclado.getKey();
  if (key != NO_KEY){
    Serial.println(key);
    delay(1000);
    if(key!='D')contra_ingresada += key;
    if(key=='D'){
      pulsador1 = 1;
    }
  }
    
  }
  

  
void comparacion(){
  if(pulsador1==1){
    Firebase.RTDB.getString(&fbdo, "/User/pass");
    contra_correcta = fbdo.stringData();
    Serial.println(contra_correcta);
    if(contra_ingresada == contra_correcta){
      Serial.println("Correcta");
      digitalWrite(ledV1,HIGH);
      Firebase.RTDB.setString(&fbdo, "/User/alarma",0);
      delay(5000);
      digitalWrite(ledV1,LOW);
      val1=1;
      }
    else{
      Serial.println("Incorrecta");
      digitalWrite(ledR1,HIGH);
      Firebase.RTDB.setString(&fbdo, "/User/alarma",1);
      delay(5000);
      digitalWrite(ledR1,LOW);
    }
      contra_ingresada = "";
      pulsador1 = 0;
    }
  }

