# UIC Easy Breath
## PROJECT: **Bioengineered breathing assistant for COVID-19**


At the end of 2019 a global pandemic changed our lives: we weren’t able to leave home, couldn’t hang out with friends… What is more, the medical services collapsed due to the big necessity of medical attention for COVID patients.

This project is based on the manufacture of a breathing assistant for COVID-19, a device designed to help those suffering severe breathing difficulties while affected by this virus. The aim of this project is to report how we created an electric device with the ability to provide sufficient oxygen to those patients.

The overall mechanism consists in a 3D printed breathing machine structure connected to several electrical devices and all derived from an Arduino MKR 1000.

The project is developed on the basis of a previous project that we found in Thingiverse (https://www.thingiverse.com/thing:4255247), where we got the breathing assistant model that we decided to print in 3D. In addition, we modified some of the previous pieces and also printed extra ones. For instance,  a display adapted box to place all the electronics of the mechanism



_1. Objectives_: 

- Learn the basics of 3D printing and electronics in order to create a bioengineered breathing assistant for COVID-19.
- Create an accessible and fast 3D printed device in order to cover the urgent necessities during the COVID pandemic.
- Use motors and electronic devices in order to understand its functions.
- Be able to generate an Arduino code able to mimic the movements of the preexisting breathing machines, with the corresponding sensor.


_2. Materials_: 

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
   - Electric limit switch.
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

_3. Definitions_:

**MKR 1000 WIFI**:
- Price: 26.50€ [https://store.arduino.cc/arduino-mkr1000-wifi].
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

**Sensor Pressure**:
- Price: 16,08€ [https://www.mouser.es/ProductDetail/Honeywell/ABPLANN001PG2A5?qs=eRmS5dli9yMyiL1FOruxZA==&gclid=Cj0KCQjwkZiFBhD9ARIsAGxFX8CNozi2j3QXyoOwybug7ET6ZLqn-7Bz02wLNBLJneNBi7AFd-qP9poaAvDyEALw_wcB]
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

![Pinouts_PressureSensor](https://github.com/roboticsuic/UIC-Easy-Breath/blob/main/Extra/Pinouts_PressureSensor.png)

**Screen SparkFun SerLCD**
- Price: 16,37€.
- Size: 16x2mm, RGB on Black Display.
- Manufactures: SparkFun.
- Source: 3.3V.
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
- Voltage: 4 V.
- Resistance: 3.3 Ohm per bobbin.
 
![Stepper%20motor%20NEMA%2017](https://github.com/roboticsuic/UIC-Easy-Breath/blob/main/Extra/Stepper%20motor%20NEMA%2017.jpg)

**Driver TB6600**
- Price: 18.90€.
- Input current: 0-5.0 A.
- Output current: 0.5 - 4A.
- Power: 160W
- Temperature: -10 - 45 degrees.
- Weight: 200g.
- Dimensions: 96x56x33mm.

![DriverTB6600](https://github.com/roboticsuic/UIC-Easy-Breath/blob/main/Extra/DriverTB6600.jpg)


**Voltage conversor**


_4. Code_: 


_5. Softwares_: 

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
