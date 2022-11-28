#include "Libraries.h"

#include <Adafruit_Fingerprint.h>
#include <HardwareSerial.h>
#if (defined(__AVR__) || defined(ESP8266)) && !defined(__AVR_ATmega2560__)
// For UNO and others without hardware serial, we must use software serial...
// pin #2 is IN from sensor (GREEN wire)
// pin #3 is OUT from arduino  (WHITE wire)
// Set up the serial port to use softwareserial..

#else
// On Leonardo/M0/etc, others with hardware serial, use hardware serial!
// #0 is green wire, #1 is white
//#define mySerial Serial1

#endif

HardwareSerial mySerial(2); // <------ IÑAKI SI ANDA CON LOS TX RX (16, 17) DEL ESP32 PERFECTO,
// SI NO USA LOS PINES DEL I2C:
// PINES I2C ESP32: SDA(GPIO 21)-----AZUL, SCL(GPIO 22)-----AMARILLO

Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);

uint8_t id;

bool Veri2;
bool compRecvControl = true;
uint8_t fpComparision();
uint8_t getFingerprintEnroll();
void Init_Huella();
uint8_t readnumber(void);
void enrollingFP();
void Bucle();
