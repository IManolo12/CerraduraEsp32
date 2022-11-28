#include "WiFi.hpp"


void Init_WiFi(){
    WiFi.begin(ssid,password);
    
    while((WiFi.status() != WL_CONNECTED) && (!flag_conectado)){//Status te devuelve un valor que indica el estado de la conexión asignado a una macro
      delay(1000);
      Serial.println(contador_segundos);
      contador_segundos++;
      if(contador_segundos == 60)flag_conectado = true;//Usado para que las lineas anterior no se repita infinitamente
    }
    if(WiFi.status() == WL_CONNECTED){
      digitalWrite(LED_BUILTIN,HIGH);
    }
    else{
      digitalWrite(LED_BUILTIN,LOW);
    }
      
    //Serial.printf ("Firebase Client v%s\n\n", FIREBASE_CLIENT_VERSION);
    config.api_key = API_KEY;
    config.database_url = DATABASE_URL;

    Firebase.begin(DATABASE_URL, API_KEY);
    Firebase.reconnectWiFi(true);

    Firebase.setDoubleDigits(5);
}