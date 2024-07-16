# Wi-Fi Enabled Digital Clock

This project involves the development of a Wi-Fi enabled digital clock using an ESP8266 microcontroller and a 16x2 LCD display with an I2C module. The clock synchronizes time via NTP (Network Time Protocol) to ensure accurate and automatic timekeeping. This README file provides instructions on setting up and using the digital clock.

## Table of Contents
1. [Introduction](#introduction)
2. [Features](#features)
3. [Components Required](#components-required)
4. [Circuit Diagram](#circuit-diagram)
5. [Setup and Installation](#setup-and-installation)
6. [Usage](#usage)
7. [Troubleshooting](#troubleshooting)
8. [Contributing](#contributing)
9. [License](#license)

## Introduction
The Wi-Fi enabled digital clock is designed to display the current time accurately by synchronizing with an NTP server. The clock uses an ESP8266 microcontroller to connect to a Wi-Fi network and fetch the current time, which is then displayed on a 16x2 LCD with an I2C module.

## Features
- **Wi-Fi Connectivity**: Leverages Wi-Fi to connect to NTP servers for real-time clock updates.
- **Accurate Timekeeping**: Ensures precise time display through NTP synchronization.
- **Clear Display**: Utilizes a 16x2 LCD with an I2C module for efficient communication and clear time display.

## Components Required
- ESP8266 microcontroller
- 16x2 LCD display
- I2C module for the LCD
- Jumper wires
- Breadboard or PCB
- USB cable for programming and power

## Circuit Diagram
![Circuit Diagram](link-to-circuit-diagram-image)

## Setup and Installation
1. **Hardware Connections**:
   - Connect the ESP8266 to the I2C module as follows:
     - VCC to 3.3V
     - GND to GND
     - SDA to D2
     - SCL to D1
   - Connect the I2C module to the 16x2 LCD display.

2. **Software Setup**:
   - Install the Arduino IDE from [here](https://www.arduino.cc/en/Main/Software).
   - Add the ESP8266 board to the Arduino IDE. Instructions can be found [here](https://github.com/esp8266/Arduino#installing-with-boards-manager).
   - Install the required libraries:
     - `Wire.h` for I2C communication
     - `LiquidCrystal_I2C.h` for the LCD display
     - `NTPClient.h` for NTP synchronization

3. **Upload the Code**:
   - Open the Arduino IDE and load the provided sketch (code).
   - Modify the Wi-Fi credentials and NTP server details in the sketch.
   - Select the correct board and port from the Tools menu.
   - Upload the code to the ESP8266.

## Usage
- **Power On**: Connect the ESP8266 to a power source using a USB cable.
- **Wi-Fi Connection**: The ESP8266 will connect to the specified Wi-Fi network.
- **Time Display**: The current time will be fetched from the NTP server and displayed on the 16x2 LCD.

## Troubleshooting
- **No Display on LCD**: Check the connections between the ESP8266, I2C module, and LCD. Ensure the correct I2C address is used in the code.
- **Wi-Fi Connection Issues**: Verify the Wi-Fi credentials and ensure the network is available.
- **Incorrect Time**: Ensure the correct NTP server and time zone settings are configured in the code.

## Contributing
Contributions are welcome! Please open an issue or submit a pull request for any improvements or bug fixes.

## License
This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
