# To interface Arduino Uno with an Ethernet Shield (W5500) and send data to ThingSpeak using three analog sensors (potentiometer, LDR, LM35).

# NOTE: This project is completed using PicSimLab simulator tool, NO REAL HARDWARE IS USED.
# You'll need to follow these steps:
# Hardware Setup:
- Connect the three analog sensors to the Arduino Uno:
- Potentiometer: Connect the middle pin to the analog pin (e.g., A0) and the other two pins to 5V and GND.
- LDR (Light Dependent Resistor): Connect one leg to the analog pin (e.g., A1) and the other to both 5V and GND.
- LM35 (Temperature Sensor): Connect the LM35's output pin to an analog pin (e.g., A2) and the other two pins to 5V and GND.
- Connect the Ethernet Shield (W5500) to the Arduino Uno.

# Install Required Libraries:
- Make sure you have the necessary libraries installed. You'll need the "Ethernet" library and the "ThingSpeak" library. You can install them using the Arduino Library Manager.

# Code:
- Use the following code as a starting point.
- Replace < yourSSID >, < yourPASSWORD >, and < your_API_KEY > with your Wi-Fi credentials and ThingSpeak API key.
