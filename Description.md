# UIC Easy Breath
## PROJECT: **Bioengineered breathing assistant for COVID-19**


At the end of 2019 a global pandemic changed our lives: we weren’t able to leave home, couldn’t hang out with friends… What is more, the medical services collapsed due to the big necessity of medical attention for COVID patients.

This project is based on the manufacture of a breathing assistant for COVID-19, a device designed to help those suffering severe breathing difficulties while affected by this virus. The aim of this project is to report how we created an electric device with the ability to provide sufficient oxygen to those patients.

The overall mechanism consists in a 3D printed breathing machine structure connected to several electrical devices and all derived from an Arduino MKR 1000.

The project is developed on the basis of a previous project that we found in Thingiverse (https://www.thingiverse.com/thing:4255247), where we got the breathing assistant model that we decided to print in 3D. In addition, we modified some of the previous pieces and also printed extra ones. For instance,  a display adapted box to place all the electronics of the mechanism



**_1. Objectives:_**

- Learn the basics of 3D printing and electronics in order to create a bioengineered breathing assistant for COVID-19.
- Create an accessible and fast 3D printed device in order to cover the urgent necessities during the COVID pandemic.
- Use motors and electronic devices in order to understand its functions.
- Be able to generate an Arduino code able to mimic the movements of the preexisting breathing machines, with the corresponding sensor.


**_2. Materials:_**

- For 3D printing: 
   - Blue, white and grey PLA.


- Softwares:
   - _SolidWorks_, to create and modify pieces.
   - _Ultimaker Cura_, to adjust setting parameters of the 3D printer.
   - _Meshmixer_, to detail and modify already created pieces.
   - _Prusa Slicer_, to add supports to the pieces before printing.


- For the electronics of the breathing assistant:
   - Arduino MKR1000.
   - Stepper motor NEMA 17.
   - Spindle Igus step 25.
   - Screw spindle Igus step 25.
   - Driver TB6600.
   - Screen SparkFun SerLCD.
   - Energy source 24V (5A).
   - Power regulator step down (24V to 10V).
   - Mechanical limit switch.
   - Pressure sensor (001PG2A5).
   - Buzzer.
   - Voltage conversor.
   - Voltage source (2 outcomes).


 - For the respiratory circuit:
   - Ambu respiratory bag.
   - Two corrugated tubes.
   - APL valve.
   - Peep valve.
   - Directionality valves.
   - Filter.

**_3. Definitions_:**

**MKR 1000 WIFI**:
- Price: 26.50€ 
- Size: Length 61.5mm Width 25mm.
- Weight: 32gr.
- Microcontroller: SAMD21 Cortex-MO + 32bit low power ARM MCU.
- Board Power Supply (USB/VIN): 5V.
- Supported Battery: Li-Po single cell, 3.7V, 700mAh minimum.
- Circuit Operating Voltage: 3.3V
- Digital I/O Pins: 8.
- PWM Pins: 12 (0,1,2,3,4,5,6,7,8,10,A3 -or 18 -, A4 -or 19).
- UART: 1.
- SPI: 1.
- 12C: 1.
- Analog Input Pins: 7 (ADC 8/10/12 bit).
- Analog Output Pins: 1(DAC 10 bit).
- External Interrupts: 8(0,1,4,5,6,7,8,A1 -or 16-, A2 - or 17).
- DC current per I/O Pin: 7mA.
- Flash Memory: 256KB.
- SRAM: 32KB.
- EEPROM: no.
- Clock Speed: 32.768kHz (RTC), 48MHz.
- LED_BUILTIN: 6.
- Full-speed USB Device and embedded Host.
 ![ArduinoMKR1000](https://github.com/roboticsuic/UIC-Easy-Breath/blob/main/Extra/ArduinoMKR1000.jpg)


**Pressure Sensor**:
- Price: 16,08€
- Manufactures: Honeywell.
- Model: 001PG2A5.
- Output Type: I2C, Address 0x28.
- Supply Voltage:  5.0 Vdc.
- Use: Medical Ventilators.
- Pressure Range: 0 psi to 1 psi.
- Pressure: Gauge.
- Weight: 4,250 g.
- Max. tension: 5,25V.
- Min. tension: 4,75V.
- Pinouts: Check table below.
- ![Pinouts_PressureSensor](https://github.com/roboticsuic/UIC-Easy-Breath/blob/main/Extra/Pinouts_PressureSensor.png)

**Screen SparkFun SerLCD**
- Price: 16,37€.
- Dimensions: 16x2mm, RGB on Black Display.
- Manufactures: SparkFun.
- InPut Voltage: 3.3V.
- Weight: 2.2084 g.
- Connection: Qwiic.


![Screen%20SparkFun%20SerLCD%20%20](https://github.com/roboticsuic/UIC-Easy-Breath/blob/main/Extra/Screen%20SparkFun%20SerLCD%20%20.jpg)

**Stepper motor NEMA 17**
- Price: 21,66€.
- Size: 42.3x48mm, without including the axis.
- Weight: 350 g.
- Axis diameter: 5mm.
- Axis length: 25mm.
- Steps per turn: 200 (1.8º/step.
- Current: 1.2 Amps per winding.
- Voltage: 4V.
- Resistance: 3.3 Ohm per bobbin.
 
![Stepper%20motor%20NEMA%2017](https://github.com/roboticsuic/UIC-Easy-Breath/blob/main/Extra/Stepper%20motor%20NEMA%2017.jpg)

**Driver TB6600**
- Price: 18.90€.
- Input current: 0-5.0 A.
- Output current: 0.5 - 4A.
- Power: 160W
- Temperature: -10 to 45 degrees.
- Weight: 200g.
- Dimensions: 96x56x33mm.
- Connections: See picture above.

![DriverTB6600](https://github.com/roboticsuic/UIC-Easy-Breath/blob/main/Extra/DriverTB6600.png)

**XL4015 DC Voltage Converter**
- Price: 3€.
- Input Voltage: 4.5V - 38V.
- OutPut Volatge: 1.25 - 36.5V
- OutPut power: 75W.
- Current Voltage: 4,5A.
- Temperature: -40 to 85 degrees.
- Operating frequency: 180kHz.
- Dimensions: 62x38x15 mm.
- Short circuit protection: Yes
- Functions: Step-down converter with overcurrent protection.
![VolatgeConverter](https://github.com/roboticsuic/UIC-Easy-Breath/blob/main/Extra/VolatgeConverter.jpg)



**_4. Circuit_:**

This is the circuit we have proposed, nonetheless, conexions can be modified as one wishes:
![Connections](https://github.com/roboticsuic/UIC-Easy-Breath/blob/main/Extra/Connections.jpeg)


**Pressure sensor**

_See picture in definitions section._
- 3.3V corresponds to 5V
- SDA and SCL are connected to arduino
- The two remaining pins are not used

**XL4015 DC Voltage Converter**

_See picture in definitions section._ 
- IN+/- connected to voltage source 12V
- OUT+ connected to VIN arduino MK1000
- OUT- connected to GND arduino MK1000

**Driver TB6600 and Stepper motor NEMA 17**

_See picture in definitions section._   
- ENA- pin 8
- ENA+, DIR+, PULL+ → 3.3V 
- DIR- pin 10
- PULL- pin 6
- B- (black), B+ (green), A- (red), A+ (blue) → stepper motor
- GND, Vcc → voltage source 24V 

**Screen SparkFun SerLCD**
   
![Screen%20LCD](https://github.com/roboticsuic/UIC-Easy-Breath/blob/main/Extra/Screen%20LCD.PNG)
      
   
   
   
   
**Buzzer** 
   
![Buzzer](https://github.com/roboticsuic/UIC-Easy-Breath/blob/main/Extra/Buzzer.PNG)
  
   
   
   
   
   
   
   
   
   
   
**Limit Switch**
   
![Limit%20switch](https://github.com/roboticsuic/UIC-Easy-Breath/blob/main/Extra/Limit%20switch.PNG)

   
   
   
_Notes:_
We have used common conexions for several components which end up in the same pin.
- A common conexion for SDA and SLA for the pressure sensor and the screen in arduino pins.
- OUT- from the voltage conversor is connected to GND arduino, while GND connections in the pressure sensor, buzzer, limit switch and screen are commonly connected to the first one.
- Vcc pin from arduino is commonly connected to ENA+, DIR+, PULL+ and 3.3V pin from screen.






**_5. Code_:**
   
Here you will find the main explanation of our code. The entire code is in the _CODE_ folder.

   
_Libraries:_  
   - Wire: Communicates with the IC2.
   - SerLCD: Communicates with the screen.
   - Honeywell_ABP: Communicates with the pressure sensor.

_Medical calculations:_
   - Used to modulate the respirator depending on the patient’s needs.

_Communications with Monitor Serie:_     
   - Serial.begin(9600)→ 9600ms are the velocity that the massage is send to the Monitor Serie.
   - Serial.setTimeout(100)→ 100ms are the waiting time to print in the screen.

_Define Inputs&Output:_
  - pinMode(finalcarrera, INPUT_PULLUP)→ Pullup as monitor the state of a switch.
  - Scl→ Is the system clock.
  - Sda→ Is the system data.

_Screen communications with the Monitor Serie:_
   - Used for:
      - Displacement
      - Breathing per minute (rpm)
         - Total breathing counting; as is an integer, its limit is 32 bits or 2.147.483.647 rpm.
      - Ratio inhalation/expiration 

_Calculations during process:_
   - Inhalation_
      - digitalWrite(dirNeg, HIGH)→ High as the movement is in X negative.
   - Expiration:
      - digitalWrite(dirNeg, LOW)→ Low as the movement is in X positive.
            
_Limit switch and Buzzer:_
   - Used for:
      - If low:
          - It will show an error, as the machine is obstructed and isn’t working.
          - When an error, the buzzer sounds.
       - If high:
          - Is for the expiration movements.
          - When the limit switch is high, it means that the motor has reach the maximal position, and it turns to the other direction (X negative)

_Pressure Sensor:_
   - If no extra pressure: the sensor is working but without reporting the information on the screen.
   - If too much pressure: the sensor detects this increase. Without stopping the ventilator, there are some modifications:
         - The screen reports the number in cmH2O.
         - The buzzer sounds for 1 second.
          
   
   
   
   
**_6. Softwares_:**

**SolidWorks**

 _SolidWorks_ is modeling a computer-aided design (CAD) program that allowed us to create the breath assistant's structure quickly and precisely. The whole structure is composed of 12 different pieces and all of them have to fit with each other, as this project doesn’t contain any screws or ties. However, this part didn’t require a lot of time as all the 12 pieces were previously created by another Catalan University (UPC). A maximum of five days were required for printing the whole structure. The final outcome was the following: 
 
 ![Estructura_Respirador](https://github.com/roboticsuic/UIC-Easy-Breath/blob/main/3D%20files/Estructura_Respirador.JPG)
 

On the other hand, _SolidWorks_ was constantly used during our project due to the improvements that our group decided to do. To do that, we used the _SolidWorks_ program to create a new plane in the upper surface, and insert the corresponding text. The difficult part was to figure out which direction was the perfect one, due to the face-mask connector would be seen in the opposite direction. On the other hand, we also incorporare our logo in the frontal part of the box and our surnames in the lateral part of it.
![Piezas_Personalizadas](https://github.com/roboticsuic/UIC-Easy-Breath/blob/main/Extra/Piezas_Personalizadas.JPG)


Secondly, this program was also used to create the needed structure to connect the breath assistant with the medical tubs. To do it, we measured the most external part of both devices with a vernier caliper, and with such dimensions, we created the connector.
Thirdly, we decided that one of the initial 12 structures had to have all its surface with PLA. To do that, we create a new plan over the created, and we extrude it. 

Finally, we wanted to create a box to keep all the tools together and well-organized. But this box couldn’t be as the typical ones, but with a certain orientation in one of the faces as we also have a screen to fit inside of it. Therefore, the box had to be composed of different parts. First, we had to modify a preexisting project piece so the box could be attached to the breath machine. Secondly, the back part was created and also the laterals. Finally, the screen face  was designed with all the modifications needed to be able to use all buttons. As can be seen in the image below, all parts have rectangle holes or rectangular extrusions so they can be ansamble together and form the desired box.
In order to know if the box was designed properly, we assembled all the new pieces with Solid works, and the result is the following image.  
![Caja_Imprimida](https://github.com/roboticsuic/UIC-Easy-Breath/blob/main/3D%20files/Caja_Imprimida.JPG)

**Meshmixer**

_Meshmixer_ is a free software able to modify files in order to work with triangle meshes. We used it with the purpose of decreasing the adaptor’s resolution. This was due to the need to modify the structure to connect the tubes of the vent system. Moreover, we delete the preexisting letters on its surface to put on our own.

**Ultimaker Cura**

_Ultimaker Cura_ is a cutting software, which converts 3D models into G-code files, which will provide the 3D printer with all the necessary instructions for printing. It converts files in STL format to physical parts. All figures have been converted with Ultimaker Cura before printing. We adapt the printing parameters to improve the PLA printing.    

**Prusa Slicer**

_Prusa Slicer_, is a cutting software, which converts 3D models into G-code files, which will provide the 3D printer with all the necessary instructions for printing. We also used this software to print the adaptor but with the correct support in order to be printed accurately. See picture below.

![Meshmixer](https://github.com/roboticsuic/UIC-Easy-Breath/blob/main/3D%20files/Meshmixer.png)






**_7. Conclusions_:**

Once our final project is done, we can conclude the following statemnts:

The aim of the project was to create a mechanical ventilator that worked automatically and was able to surpass common errors without the help of a medical assistant. The structural parts were printed with a MK3 PRUSA 3D printer with PLA in blue and grey colors. The box that holds all the electronics is composed of five parts that bind together by holes and extrusions, has a hole for the cables to pass, and has the Easy Breath logo in the front. The Arduino used was the MKR1000 model that combines the switch, sensor pressure, I2C screen, driver, buzzer, voltage converter, and stepper motor. The whole structure is connected to a 24V and 12V power supply. Errors that the program described can solve include: the detection of an increase of pressure of over 10 cmH2O that it showed in the screen visually and by a sound by the buzzer, and the detection of an early click of the switch button before it is necessary, the buzzer will also make a sound.

The project holds all the objectives proposed from the beginning, solving other issues found during the process being so; the mechanical ventilator can be printed with a conventional printer machine, Arduino is a proper device to control heavy files and structured document helps to improve existents projects. The last one being the most important one, it is essential for a public finished project to show and be well documented having not only the datasheet but also the exact device models. As so, we have described and attached all the files we have used so the project can be reproduced step by step.

As for future changes and improvements, a reset function can be included in the code. The reset function is useful in extreme cases when an external object gets attached to the device, for instance. If a cable or object gets stuck in the route of the stepper motor movement, there is a need of restarting the code without disconnecting the device. In the project, this approach was solved by showing an error message in the screen or showing the pressure, as well as a warning buzzer, and continuing the loop without stopping. Another alternative to polishing the project is to add a more complex screen that has buttons to select or is tactile, this is so a laptop is no needed.
