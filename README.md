##### **#** **Blind Spot Detection System using Ultrasonic Sensors \& OLED Display**



📄 **Description**



A dual-sensor embedded system that monitors and displays blind spot distances in real-time. HC-SR04 ultrasonic sensors placed on both the left and right sides detect nearby obstacles. If an object enters the defined blind spot zone (within 30 cm), corresponding LEDs and buzzers are triggered. A 0.96" I2C OLED screen displays live distance readings and a clear alert when necessary.



**##** ✨ **Features**



\- Real-time left/right distance tracking

\- I2C OLED interface using Adafruit\_SSD1306

\- Visual + audible alert system

\- Simulated 100% in Wokwi with accurate logic



**##** 🧠 **Skills \& Concepts**



\- Ultrasonic sensing (pulseIn, echo timing)

\- I2C communication (OLED display)

\- Conditional logic and alert control in Arduino

\- Real-time data formatting and display

\- Circuit design and simulation (Wokwi + KiCad)



**##** 🔧 **Tools Used**



\- \*\*Wokwi\*\* – Circuit simulation \& testing

\- \*\*Arduino IDE\*\* – Local code compilation/debugging

\- \*\*KiCad\*\* – Accurate schematic creation



**##** 📋 **Bill of Materials (BoM)**



| **Qty** | **Component**           | **Description**                        |

|-----|---------------------|------------------------------------|

| 1   | Arduino Uno R3      | Microcontroller                    |

| 2   | HC-SR04             | Ultrasonic Distance Sensor         |

| 1   | OLED Display        | SSD1306, I2C, 0.96", 4-pin         |

| 2   | LED (Red)           | Visual alert                       |

| 2   | Resistor (220Ω)     | For LEDs                           |

| 2   | Buzzer (5V Piezo)   | Audible alert                      |

| –   | Jumper Wires        | All connections                    |

| –   | Breadboard          | Optional, for real prototype     |



**##** 📐 **Circuit Diagram**



See 'BlindSpot\_Schematics.pdf' for the full KiCad schematic.



**##** 🔗 **Simulation**



\*\*Wokwi Project Link\*\*: \[https://wokwi.com/projects/437343000411654145]



---



> 💡 This project was built as part of an embedded systems portfolio to demonstrate sensor interfacing, I2C protocol integration, and real-time alert systems using Arduino.

