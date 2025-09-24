//Librairy  2.8" TFT LCD
#include <SPI.h>          // f.k. for Arduino-1.5.2
#include "Adafruit_GFX.h"// Hardware-specific library
#include <MCUFRIEND_kbv.h>
MCUFRIEND_kbv tft;
#define LCD_CS A3 
#define LCD_CD A2 
#define LCD_WR A1 
#define LCD_RD A0 
#define LCD_RESET A4
#define	BLACK   0x0000
#define	BLUE    0x001F
#define	RED     0xF800
#define	GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF
// SD & RTC Labraries
#include <RTClib.h>
#include <SD.h>
#include <SPI.h>
#include <DHT.h>
RTC_DS1307 rtc;
//DHT libraries
#include "DHT.h"
#define DHTPIN22 24
#define DHTPIN21 22
#define DHTTYPE22 DHT22   // DHT 22 (AM2302), AM2321
#define DHTTYPE21 DHT21
DHT dht22(DHTPIN22, DHTTYPE22); // Initialize DHT sensor for normal 16mhz Arduino
DHT dht21(DHTPIN21, DHTTYPE21);
// Variable Definitions for DhT
float temp_internal;    // Stores internal temperature value
float hum_internal;     // Stores internal humidity value
float temp_external;    // Stores external temperature value
float hum_external;     // Stores external humidity value
// Variable Definitions for moisture
float soil1;
float soil2;
float soil3;
float soil4;
//variable for Maping values of Moisture
float pre1;
float pre2;
float pre3;
float pre4;
// Actuation Module for Temperature and Humidity Control
int Relay1_Heater1 = 26;   
int Relay2_Heater2 = 28;  
int Relay3_AirOut1 = 30;    
int Relay4_AirIn1 = 31;
int Relay5_AirIn2 = 32;
int Relay6_AirOut2 = 33;
//Set value for Temperature
const int TEMP_THRESHOLD_UPPER = 30; // upper threshold of temperature
const int TEMP_THRESHOLD_LOWER = 27; // lower threshold of temperature
//Set value for Humidity
const int HUM_THRESHOLD_UPPER = 90; // upper threshold of Humidity
const int HUM_THRESHOLD_LOWER = 75; // lower threshold of Humidity
//variable for soil moisture first range of plante in a tray  1
#define sensor1 A10 
#define sensor2 A11 
// set of values sensor num_1 and sensor num_2
const int wet_sensor1 = 210;
const int dry_sensor1 = 590;
// set of values sensor num_2
const int wet_sensor2 = 210;
const int dry_sensor2 = 590;
// cut_of value for sensor 1 and 2
const int CUT_OFF_MOISTURE_PERCENATGE_1 = 65;
//variable for soil moisture second range of plante in a tray  2
#define sensor3 A12 
#define sensor4 A13
// set of values sensor num_3
const int wet_sensor3 = 210;
const int dry_sensor3 = 490;
// set of values sensor num_4
const int wet_sensor4 = 210;
const int dry_sensor4 = 490;
// cut_of value for sensor 1 and 2
const int CUT_OFF_MOISTURE_PERCENATGE_2 = 90;
// Actuation Module for Irrigation Control
int Relay7_solenoid1 = 34;
int Relay8_solenoid2 = 35;
// Light pin & variable ldr
#define light  A15
int lampe_relay = 36;
int ldr;
// CO2 variables definition
#define InputCo2  A14 //MQ135 analogsensor for CO2 reading
int Carbon;
//GSM Module setting
#include <SoftwareSerial.h>
SoftwareSerial gprsSerial(14, 15);
#include <String.h> 
// interval required for recording 
long curent;
long last;
long thresh = 60000;
//int i = 1;
int manytimes = 1;
int total;
int kath = 5000;
// Name file
File MyFile;

void logger();
void temp();
void hum();
void soilMoisture1();
void soilMoisture2();
void LDR();
void CarbonDioxyde(); 
void display();
void cloudData();
void affich();
void ShowSerialData();







