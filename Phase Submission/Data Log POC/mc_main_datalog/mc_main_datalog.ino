/*
  =================================================================
  Welcome to the DataLog Firmware POC for the Honda Hackathon 2020.
  This is presented by Team Nomad.
  =================================================================
  The Data Log will log the following data from the car to perform
  regression and other attributes relative to the Concept.
  - GPS
  - Engine Status
  - Temperature
  - Fuel Level
  - Coolant Level
  All the following data will be stored in an SD card that is used
  as the external memory of the OBC as data_log.txt
  =================================================================
*/

// Libraries
#include <SPI.h>
#include <SD.h>
#include <TinyGPS++.h>
#include <SoftwareSerial.h>
#define OPTIMAL_TEMP xyz // Optimal Value of Engine Temperature
#define OPTIMAL_COOL xyz // Optimal Value of Coolant Level
#define OPTIMAL_FUEL xyz // Optimal Value of Milage

// Initializations
File datalog;
SoftwareSerial GPS_con(10, 11); // Rx Tx
TinyGPSPlus gps;
void gps_log(void);
void car_sen_log(void);
void engine_chk(void);
void engine_log(void);
const int Eng_Stat = 0;
const int Temp_chk = A0;
const int Fuel_Level = A1;
const int Cool_Level = A2;
float engine_stat;

// Pin and Init Setup
void setup() {
  pinMode(Eng_Stat, INPUT);
  pinMode(Temp_chk, INPUT);
  pinMode(Fuel_Level, INPUT);
  pinMode(Cool_Level, INPUT);
  Serial.begin(9600);
  GPS_con.begin(9600);
  Serial.println("Initializing Firmware . . .");
  delay(1000);
  while (!Serial) {
    ;
  }
  Serial.println("Initializing SD Card for Data Log . . .");
  if (!SD.begin(4)) {
    Serial.println("SD Card Initialization Failed!");
    while (1);
  }
  Serial.println("SD Card Initialization Done.");
  Serial.println("Creating new Data Log File");
  datalog = SD.open("data_log.txt", FILE_WRITE);
  if (datalog) {
    Serial.println("Data Log File Created. . .");
  }
  else {
    Serial.println("Error. Data Log File NOT Created!");
    exit(0);
  }
}

// Main Function Loop
void loop() {
  if (digitalRead(Eng_Stat)) {
    Serial.println("Starting to Log Data on data_log.txt . . .");
    gps_log();
    car_sen_log();
    engine_chk();
    engine_log();
  }
  else {
    datalog.close();
  }
}

void gps_log() {
  while (GPS_con.available()) {
    gps.encode(GPS_con.read());
  }
  if (gps.location.isUpdated()) {
    datalog.print("SAT COUNT:"); datalog.print(gps.satellites.value()); datalog.print(", ");
    datalog.print("LAT:"); datalog.print(gps.location.lat(), 6); datalog.print(", ");
    datalog.print("LON:"); datalog.print(gps.location.lng(), 6); datalog.print(", ");
    datalog.print("KMPH:"); datalog.print(gps.speed.kmph()); datalog.print(", ");
    datalog.print("ALT:"); datalog.print(gps.altitude.meters()); datalog.print(", ");
  }
}

void car_sen_log() {
  datalog.print("TEMP:"); datalog.print(analogRead(Temp_chk)); datalog.print(", ");
  datalog.print("FUEL:"); datalog.print(analogRead(Fuel_Level)); datalog.print(", ");
  datalog.print("COOL:"); datalog.print(analogRead(Cool_Level)); datalog.print(", ");
}

// Statistical Analysis of Milage, Coolant Level and Engine Temperature
void engine_chk() {

}

void engine_log() {
  datalog.print("ENGINE STAT:"); datalog.println(engine_stat);
}
