 #include <Wire.h>//library that communicates with the IC2
#include <SerLCD.h> //library that communicates with the SCREEN
SerLCD lcd; // Communicates the screen with the IC2
#include <Honeywell_ABP.h>//library of the PRESSURE SENSOR
// refer to datasheet for parameters

Honeywell_ABP abp( //parameters of the sensor
  0x28,   // I2C address
  0,      // minimum pressure
  1,      // maximum pressure
  "psi"   // pressure unit (pounds per square inch)
);

//defines pins
const int stepPin = 6;  //PULSE- 
const int finalcarrera = 7; //Electric limit switch
const int buzzer = 1; //Buzzer
const int enaNeg= 8; //ENA- (off line control enable-)
const int dirNeg= 10; //DIRECTION-
int Scl=12; //includes sensor and screen. Clock
int Sda=11; //includes sensor and screen. Data
int sensorValue=0; //value 0 of sensor at the beginning
int inputpinSensor=9; //input pin of the sensor
int presion=0; //value 0 of pressure at the beginning
 


//Variables
const int stepsxrev = 6400; //steps of motor revolution 
const int mmxrev= 8; //displacement milimeters of the spindle per revolution 

int stepdelayInsp = 0;    //microsegundos entre paso y paso - Inspiración
int stepdelayExp = 0;     //microsegundos entre paso y paso - Expiración
int stepdelay = 0;        //microsegundos entre paso y paso - General

int targetsteps = 0;         // pasos necesarios para llegar al punto marcado

int t1 = 500;               //tiempo de espera Inspiración (milisegundos)
int t2 = 500;               //tiempo de espera Expiración (milisegundos)

int disp = 0 ;              //desplazamiento
int RPM = 0;                //Respiraciones por minuto
int ratio = 2 ;             //Ratio inspiracion/expiracion 
int ratioDen = 2 ;          //Para el calculo Ratio inspiracion/expiracion
int tCiclo = 0;             //Tiempo de ciclo
int tInsp = 0;              //Tiempo inspiración
int tExp = 0;               //Tiempo expiración

int i = 0;                  //contar resp min
unsigned long start, finish, elapsed, over;    //Para calcular el tiempo
float h, m, s;


void setup() {
  //Iniciamos comunicación con el puerto serie
  Serial.begin(9600); //
  Serial.setTimeout(100);

  //Sets the pins as Outputs
  pinMode(stepPin,OUTPUT);
  pinMode(dirNeg,OUTPUT);
  pinMode(finalcarrera,INPUT_PULLUP);
  pinMode(buzzer,OUTPUT);
  pinMode(enaNeg, OUTPUT);

  pinMode(Scl,INPUT);
  pinMode(Sda,INPUT);
  
  Wire.begin(); // open I2C communication

  lcd.begin(Wire); //Set up the LCD for I2C communication

  lcd.setBacklight(255, 255, 255); //Set backlight to bright white
  lcd.setContrast(5); //Set contrast. Lower to 0 for higher contrast.


   //Leemos valor de desplazamiento+
   lcd.clear(); //Clear the display - this moves the cursor to home position as well
  lcd.print("DESPLAZAMIENTO  mm (50 - 80):");
  while (!Serial.available() > 0);   // Esperamos valor
   {
      disp = Serial.readString().toInt();
    
      lcd.clear();
      lcd.print("DESPLAZAMIENTO  SELEC: ");
      lcd.print(disp);
      lcd.print(" ");
    }
 delay(3000);

 //Leemos valor respiraciones minuto
 lcd.clear(); //Clear the display - this moves the cursor to home position as well
 lcd.print("RESPIRACIONES MINUTO (10 - 20):");
 while (!Serial.available() > 0);   // Esperamos valor
  {
      RPM = Serial.readString().toInt();
      
      lcd.clear();
      lcd.print("RESPIRACIONES   SELEC: ");
      lcd.print(RPM);
      lcd.print(" ");
    }
delay(3000);

   //Leemos valor Ratio I/E
 lcd.clear(); //Clear the display - this moves the cursor to home position as well
 lcd.print("RATIO I/E       (1, 2, 3, 4):");
 while (!Serial.available() > 0);   // Esperamos valor
  {
      ratio = Serial.readString().toInt();
      
      lcd.clear();
      lcd.print("RATIO I/E       SELEC: 1:");
      lcd.print(ratio);
      lcd.print(" ");
    }
delay(3000);


    //Calculos iniciales
    lcd.clear();
    tCiclo = (60000/RPM) ;
    lcd.print("Tiempo de ciclo: ");
    lcd.print(tCiclo);
    delay(3000);
    
    lcd.clear();
    ratioDen = 1+ratio;
    tInsp = (tCiclo/ratioDen) ;
    lcd.print("Tiempo de Inspiracion: ");
    lcd.println(tInsp);
    delay(3000);
    
    lcd.clear();
    tExp = ((tCiclo*ratio)/ratioDen) ;
    lcd.print("Tiempo de Expiracion: ");
    lcd.println(tExp);
    delay(3000);
 
    lcd.clear();
    targetsteps = (disp)*(stepsxrev/mmxrev);   //Pasos para el desplazamiento
    lcd.print("Pasos necesarios: ");
    lcd.println(targetsteps);
    delay(3000);
    //Si queremos velocidades diferentes de Inspiración y Expiración
    //stepdelayInsp = (((float)tInsp*1000)/((float)targetsteps*2)) ;   //microsegundos entre paso y paso - Inspiración
    //Serial.println(stepdelayInsp);
    //stepdelayExp = (((float)tExp*1000)/((float)targetsteps*2)) ;     //microsegundos entre paso y paso - Expriración
    //Serial.println(stepdelayExp);

    //Misma velocidad Inspiración/Expiración
    lcd.clear();
    stepdelay = (((float)tInsp*1000)/((float)targetsteps*2)) ;   //microsegundos entre paso y paso - Insp y Exp
    lcd.print("Delay pasos: ");
    lcd.println(stepdelay);
    stepdelayInsp = stepdelay;
    stepdelayExp = stepdelay;
    delay(3000);
}   

void loop() {
  
    //test para contar el tiempo
    i= i + 1; // int limit = 32 bits = 2.147.483.647
    lcd.clear();
    lcd.print("Respiracion num: ");
    lcd.println(i);
    delay(3000);

         //INSPIRACIÓN
     lcd.clear();
     lcd.print("INHALACION ");
     
     for(int i = 0; i < targetsteps; i++) { //loop de movimiento de 0 a pasos necesairos
        digitalWrite(dirNeg,HIGH); //inicia movimiento en sentido X negativo
        digitalWrite(enaNeg,HIGH);
        digitalWrite(stepPin,HIGH);
        delayMicroseconds(stepdelayInsp);
        digitalWrite(stepPin,LOW);
        delayMicroseconds(stepdelayInsp);        
      }
      

      //Comprobamos que el final de carrera no está pulsado -> LOW significa que está pulsado 
      while (digitalRead(finalcarrera)==LOW)  {
        lcd.println(); 
        lcd.println();
        lcd.clear();
        lcd.println("ERROR!!!");                //Crear alarma que pare la máquina
        lcd.println();
        tone(buzzer, 1200); // Send 1KHz sound signal...
        delay(500);        // ...for 1 sec
        noTone(buzzer);     // Stop sound...
        delay(500);        // ...for 1sec
      }
      
      //delay (t1);     //Espera -> modificar pasos

      //EXPIRACIÓN - Hasta final de carrera
      lcd.clear();
      lcd.print(" ->  EXHALACION ");
           
     while(digitalRead(finalcarrera)==HIGH) { //loop de movimiento de 0 a pasos necesairos
        digitalWrite(dirNeg,LOW); //inicia movimiento en sentido X positivo
        digitalWrite(enaNeg,HIGH);
        digitalWrite(stepPin,HIGH);
        delayMicroseconds(stepdelayExp);
        digitalWrite(stepPin,LOW);
        delayMicroseconds(stepdelayExp);        
      }
     
     presion=abp.pressure()* 70,308890742557;
        // update sensor reading
        abp.update();
      
        // print sensor reading via serial
        lcd.clear();
        lcd.print("Presion PEEP:   ");
        lcd.print(presion);
        lcd.print(" ");
        lcd.println("cmH2O");
        delay (1500);
        while (presion>10){
          tone(buzzer, 1200); // Send 1KHz sound signal...
          delay(500);        // ...for 1 sec
          noTone(buzzer);     // Stop sound...
          delay(500);        // ...for 1sec
        }     
  

      
      
lcd.clear();

}
