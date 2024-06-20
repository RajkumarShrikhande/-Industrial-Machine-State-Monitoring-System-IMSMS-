#include <SPI.h>
#include <Ethernet.h>
#include <ThingSpeak.h>

//Analog sensor pins
const int potPin = A0;
const int ldrPin = A1;
const int lm35Pin = A2;

//ThingSpeak settings
const char *ssid = "jiofiber54";
const char *password = "Rajks@5781";
const char *thingSpeakApiKey = "BX52C2H2MZD6TSRD";
const char *thingSpeakAddress = "api.thingspeak.com";

EthernetClient client;

void setup() 
{
  Serial.begin(9600);

  // MAC address for your Ethernet shield
  byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };

  //Ethernet set up using DHCP
  if (Ethernet.begin(mac) == 0) 
  {
    Serial.println("Failed to configure Ethernet using DHCP");
  }

  //Initializing ThingSpeak
  ThingSpeak.begin(client);
}

void loop() 
{
  //Read sensor values
  int potValue = analogRead(potPin);
  int ldrValue = analogRead(ldrPin);
  int lm35Value = analogRead(lm35Pin);

  //Convert LM35 value to temperature in Celsius
  float temperature = ((lm35Value * 0.00488) * 100);

  //Print sensor values to serial monitor
  Serial.print("Potentiometer: ");
  Serial.println(potValue);
  Serial.print("LDR: ");
  Serial.println(ldrValue);
  Serial.print("LM35 Temperature: ");
  Serial.println(temperature);

  //Send sensor values to ThingSpeak
  ThingSpeak.setField(1, potValue);
  ThingSpeak.setField(2, ldrValue);
  ThingSpeak.setField(3, temperature);

  //Write to ThingSpeak
  int response = ThingSpeak.writeFields(2417531, "BX52C2H2MZD6TSRD");

  if (response == 200) 
  {
    Serial.println("Data sent to ThingSpeak successfully.");
  } 
  else 
  {
    Serial.println("Error sending data to ThingSpeak. HTTP error code " + String(response));
  }

  //Wait for 10 seconds before sending the next update
  delay(10000);
}
