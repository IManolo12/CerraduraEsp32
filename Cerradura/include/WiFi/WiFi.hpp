#ifndef WIFI_HPP
#define WIFI_HPP
#include "Libraries.h"

#define API_KEY "5akhikuhv63rirVd1xstbzlVQflXBZzQotMCF2f0"
#define DATABASE_URL "https://montajes-esp32-default-rtdb.firebaseio.com/"

#define  ssid "Alberto"
#define password "123456789"

bool valor = true;
bool flag_conectado = false;
int contador_segundos;


FirebaseData fbdo;
FirebaseConfig config;



void Init_WiFi();

#endif