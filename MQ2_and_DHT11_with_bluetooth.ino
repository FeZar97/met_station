#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

#define SIZE 10
#define DHTPIN 2

String remote_command;
DHT dht(DHTPIN, DHT11);
int gase[SIZE], temperature[SIZE], humidity[SIZE], i;

void setup(){
  pinMode(A0, INPUT);
  dht.begin();
  Serial.begin(9600);
}

void loop(){
  
  if(Serial.available()){
    remote_command = Serial.readString();

    if(remote_command == String("status") || remote_command == String("status\n") || remote_command == String("status\r\n") || remote_command == String("status\r")){

      for(i = 0; i < SIZE; i++){
        gase[i] = analogRead(A0);
        temperature[i] = int(dht.readTemperature());
        humidity[i] = int(dht.readHumidity());
        delay(45);
      }
      
      for(i = 0; i < SIZE; i++)
        if(i != SIZE - 1)
          Serial.print(String(gase[i]) + ',');
        else
          Serial.print(String(gase[i]) + '|');

      for(i = 0; i < SIZE; i++)
        if(i != SIZE - 1)
          Serial.print(String(temperature[i]) + ',');
        else
          Serial.print(String(temperature[i]) + '|');

      for(i = 0; i < SIZE; i++)
        if(i != SIZE - 1)
          Serial.print(String(humidity[i]) + ',');
        else
          Serial.print(String(humidity[i]) + ';');
      
      remote_command = "";
    }else{
        Serial.println("incorrect command");
    }
  }
}
