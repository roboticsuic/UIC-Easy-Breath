# UIC Easy Breath
## PROJECT: **Bioengineered breathing assistant for COVID-19**
This project is based on the manufacture of a breathing assistant for COVID-19, a device designed to help those suffering severe breathing difficulties while affected by COVID-19. The aim of this project is to report how we created an electric device with the ability to provide sufficient oxygen to those patients.

The overall mechanism consists in... (not finished)

The project is developed on the basis of a previous project that we found in Thingiverse (https://www.thingiverse.com/thing:4255247), where we got the breathing assistant model that we decided to print in 3D. In addition, we printed two extra pieces: (1) a display adapted box, where we will fit the display and place all the electronics of the mechanism; and (2) an extra support for the pump end.


_Objectives_: 
- Learn the basics of 3D printing and electronics in order to create a bioengineered breathing assistant for COVID-19.
- Create an accessible and fast 3D printed device in order to cover the urgent necessities during the pandemia.
- Use motors and electronic devices in order to understand its functions.


_Materials_:
- **For 3D printing**:
  - PLA (for the most solid structures; PLA has good tensile strength, rigid and a detailed and glossy surface quality)
  - TPU (for the junctions; TPU has a great flexibility and an excellent impact to resistance)
  - Ultimaker 2+ (3D printer)
  - Sandpaper
- **For the electronics of the hand**:
  - Arduino MKR 1000 WIFI
  - Servo motor "9g"
  - Cthulhu Shield sensor
  - Arduino cables
  - Straw / 3D printed tube
  - Fishing line
- **Softwares**:
  - Unity 3D (to create animations and represent how the prosthetic hand works)
  - SolidWorks (to create some pieces that we need)
  - Ultimaker Cura (to adjust setting parameters of the 3D printer)
  
  
_Definitions_:

**MKR 1000 WIFI**:
- Price: €26.50 [https://store.arduino.cc/arduino-mkr1000-wifi].
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

**Servo Motor**:
- RC plane "9g" servo motor. 
- We took it from: https://grabcad.com/library/9g-servo-motor-1 (modelled and rendered in Solidworks)

![servo-motor](https://github.com/roboticsuic/UICduinohand/blob/master/3D%20files/images/servo%20motor.png)
- Tiny and lightweight with high output power. 
- Servo can rotate approximately 180 degrees (90 in each direction), and works just like the standard kinds but smaller. 
- You can use any servo code, hardware or library to control these servos. 
- Good for beginners who want to make stuff move without building a motor controller with feedback and gear box, specially since it will fit in small places. 
- It comes with a 3 horns (arms) and hardware.

![dimensionsservo](https://github.com/roboticsuic/UICduinohand/blob/master/3D%20files/images/dimensionsservo.png)
**Cthulhu Shield sensor**: 

The Cthulhu Shield is an open-source Arduino Uno compatible sensory substitution/sensory augmentation device. It uses an 18 electrode grid to tactile display signals on the tongue. The electrodes on the array can be activated with patterns of electrical pulses to depolarize nerve membranes in the tongue to create different types of touch sensations. You can use these touch sensations to draw shapes or simple images on the tongue, feel different sound frequencies, or receive turn by turn directions with your tongue.
Additionally, the Cthulhu Shield can sense whether or not your tongue is in contact with different electrodes using capacitive sensing. You can use the Cthulhu Shield to send keystrokes to your computer, control the cursor, or even control a mobility device.

Good video explanation: https://www.youtube.com/watch?time_continue=197&v=wd38Go9tbds&feature=emb_title

_Results_:

For this project, we just wanted to create a movement of close/open the hand, therefore with one servo we have enough to move all the fingers at the same time. However, as the fingers are in different positions we need to use a straw or a 3D printed tube (_depending on the circumstances of the quarantine, because the best option is a 3D printed tube because offers better resistance, but if we are not able to use the 3D printer of the lab then a straw is also useful_) to guide the fishing line of each finger to the servo motor.

We decided to use the same thread material that is used in fishing because is transparent (_hence give a better view of the prosthetic hand_) and offers better elasticity than others. Moreover, the length of the fishing line needed depends on the size of your prosthetic hand, in our case we will need --- cm.

On the other side, to distribute the motor servos, the Arduino MKR and the guide tubes inside the box of the prosthetic hand, we have plenty of options, for example: use a vertical servo and a drum to role the thread, use a vertical servo and a gripper... But due the design of the box we had limitations in which option to choose, hence the option that we choosed is to use a horitzontal servo (_because the height of the box is not high enough_) that goes from 0-180 degrees with a guide tube. See the image bellow:

![hole hand ensambled](https://github.com/roboticsuic/UICduinohand/blob/master/3D%20files/images/holeprothetic.jpg)

![scheme of how hand works](https://github.com/roboticsuic/UICduinohand/blob/master/3D%20files/images/scheme%20of%20how%20hand%20works.png)



Doing reference to the code and the scheme, the code is designed to be able to maintain a certain position of the hand until the MKR recieve a new input to change the position, in that way, we avoid the patient to exercise compression force in the Cthulhu constantly generating fatigue. To continue as we don't have in thinkercad nor in physic the Cthulhu sensor, we used two buttons to simulate the Cthulhu sensor function of closing and opening the prosthetic hand.

With this code our aim is to control a servo motor with 2 buttons that simulate the Cthulhu sensor function. In this case, one button is to move the hand from 0º to 180º (to open the hand) and the other one is to move the hand from 180º to 0º (to close the hand). In the case of the Cthulhu sensor, one electrode will be to open the hand and another to close it. 

Now, we are going to explain the **schematic image** which shows the connection of the Arduino with the electronic elements:

![servo with two pushbuttons](https://github.com/roboticsuic/UICduinohand/blob/master/code%20schematics/servo%20with%20two%20pushbuttons.png)


  - As we can see, the 5V is connected to the positive pole of the servo as a supplying power. 
  - The ground (GND) is connected to the ground black cable as a reference to all other electronic parts, where the electrical level is at 0 V. 
   - The other cable is the signal to move the servo motor to the required angle, that signal corresponds to a PWM (Pulse Width Modulation, a technique for getting analog results with digital means). This cable is connected to the pin 2. 

Then, we have to connect the 2 buttons and 2 resistances for increasing or decreasing the angle. Negative poles are connected to GND and positive ones are connected to pins 8 and 9 with a resistance respectively. 

Regarding the **code**: 

At first, we have to implement the _Servo.h_ library and we have declared the function Servo called as _mi_servo_. 
Then, we declare 3 variables integer. The first one indicates the initial position (which in this case is 0º) and the second and third ones refers to the buttons that increase or decrease the angle.

After this, _void setup_ is used to configure the initial parameters:
    - _mi_servo.attach (2,750,1800)_: We use the attach function to attach the servo variable to a pin, where 2 refers to the pin 2 connected to the servo. In PWM, 750 ms represents 0º and 1800 ms represents 180º. It is a conversion from servo pulses to degrees.
   - Then, we configure the input pins with _pinMode_.
   - Initialize your servo motor with the function ’’.write’’, in this case it will move 90º.

In the _void loop_, we have 2 conditions ‘’if’’.
- _digitalRead_ function: It asks for the pin 8 and it is activated with a LOW state. And with ‘grados++’ you start increasing the degrees. The following condition if is to protect the servo motor, it is a condition for the motor to not exceed the 180º.

- The second big condition is the same but it corresponds to the pin9, and ‘grados - -' reduces the degrees. And the following condition guarantee to get to 0º and to not exceed it. 
- _mi_servo.write(grados)_: It writes a new angle in degrees.
- _delay(10)_; It is used to write between degrees and present a good lecture in Arduino and the servo.


In **SolidWorks**, a computer assisted design software to model 3D parts and assemblies and 2D plans, we mainly use it to take measurements of some parts to be able to think how we would put all the electronic part. Once we decided that we were going to use only one servo and specifically the model chosen, we had to modify the box where we put the electronics to optimize the space and put an arduino mkr (although the use of smaller arduinos to control servos would be a more suitable option). Also with Solidworks we design a inner guide of the box and a hole hiding to route the lines and to make them not entangled between themselves when they are pulled by the servo, to make the movement of closing the hand and then the movement of opening. 
Once we had all the pieces that we need, we adjusted the printing settings with Ultimaker Cura and finally we printed all the pieces with _Ultimaker 2+_.

  _Printing setting for PLA_:
  - Extruder temperature: 180ºC - 210ºC
  - Cooling fan: 100%
  - Min. layer height: 0.08 - 0.2mm
  - Bed. temperature: 60ºC
  - Speed: 40 - 80mm/s → For hand and arm printing we reduced the speed to 20mm/s as these were larger pieces and we wanted to avoid bad cooling.
  - Support: not needed
  - Top/Bottom pattern: ZigZag
  
  _Printing setting for TPU_:    
  - Extruder temperature: 220ºC - 260ºC
  - Cooling fan: without
  - Min. layer height: ≥0.1mm
  - Bed temperature: 40ºC
  - Speed: 15 - 40mm/s
  - To print TPU we have to store it in an airtight container with desiccant Dry filament before printing.
  
For a better final result of the 3D printed pieces we used sandpaper to polish them. 

With **Unity**, we tried to do to a real-time visualization of how the prosthetic hand works. This involved the use of the real-time engine of Unity linked with 3D rigging programs (in this case Blender was the idea). The idea was to open and close the animated hand depending on the input of the Arduino program mentioned avobe. Due to limited knowledge on Unity and some technical problems, finally, this couldn't be accomplished. Instead a 3D view of the completed hand has been done in Blender to show the final result of the prosthetics: 

![hole_hand](https://github.com/roboticsuic/UICduinohand/blob/master/3D%20files/hole_hand.JPG)

_Conclusions_:

We could conclude this project by saying that we have learned different variables to take into account when creating a prosthesis. We have been able to program with Arduino, seeing how we must create the circuit and the code, facing the circumstances that we had, simulating with buttons the function of the sensor to close and open the hand. And we have put the design into practice, whether it is at the level of computer aided design for 3D mechanical modeling, or for creating virtual reality visualizations.
On the other hand, talking about what we are trying to replace, in this case the hand, we saw that it has many movements, of which we have focused only on recreating one of them. As a future project, we think it would be great to be able to incorporate more and more movements, perhaps progressively, to give those who require the prosthesis a high degree of freedom.
Also we have been able to see that the language sensor we have used in the project can have many uses, including the development of sensory substitution. It is very interesting to contemplate the idea that sensory substitution tools and techniques take the sensory information normally received in one organ can be presented in another way to another sensory organ. So we would be talking about recovering the sensory information that has been lost, and learning to process it through another organ.

Most importantly, we believe that the **simplest human happiness comes from physical activity**, and we have been able to provide an option to reclaim it.
