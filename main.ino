#include "/Users/archiejames/Desktop/Coding/Arduino Spyder Port/position.h"
#include "/Users/archiejames/Desktop/Coding/Arduino Spyder Port/body.h"
#include "/Users/archiejames/Desktop/Coding/Arduino Spyder Port/arm.h"

#include <SoftwareSerial.h>
#include <ServoEasing.h>

Body spyder;

struct Servo_Mod {
    Servo servo;
    float offset;
};

float currentTime;
float previousTime;
float CalculateDeltaTime(){
    currentTime = millis();
    currentTime /=1000;
    float delta_time = currentTime - previousTime;
    previousTime = currentTime;
    return delta_time;
}

int Degrees(float radians){
    int degrees = radians * 180/PI;
    return degrees;
}

float delta_time;

SoftwareSerial HM10(19, 18); // RX = 2, TX = 3

char appData;  
String inData = "";

ServoEasing servos[18];

void UpdateLegs() {
    // Set Leg group 1
    servos[6].write(spyder.arms[0].motor1_offset_angle - 180 + Degrees(spyder.arms[0].motor1_angle));
    servos[7].write(spyder.arms[0].motor2_offset_angle - Degrees(spyder.arms[0].motor2_angle));
    servos[8].write(spyder.arms[0].motor3_offset_angle - Degrees(spyder.arms[0].motor2_angle) + Degrees(spyder.arms[0].motor3_angle));

    servos[0].write(spyder.arms[1].motor1_offset_angle + 180 + Degrees(spyder.arms[1].motor1_angle));
    servos[1].write(spyder.arms[1].motor2_offset_angle - Degrees(spyder.arms[1].motor2_angle));
    servos[2].write(spyder.arms[1].motor3_offset_angle - Degrees(spyder.arms[1].motor2_angle) + Degrees(spyder.arms[1].motor3_angle));

    servos[12].write(spyder.arms[2].motor1_offset_angle + Degrees(spyder.arms[2].motor1_angle));
    servos[13].write(spyder.arms[2].motor2_offset_angle + Degrees(spyder.arms[2].motor2_angle));
    servos[14].write(spyder.arms[2].motor3_offset_angle + Degrees(spyder.arms[2].motor2_angle) - Degrees(spyder.arms[2].motor3_angle));

    // Set Leg group 2
    if (Degrees(spyder.arms[3].motor1_angle) < 0)
        servos[3].write(spyder.arms[3].motor1_offset_angle + 180 + Degrees(spyder.arms[3].motor1_angle));
    else 
        servos[3].write(spyder.arms[3].motor1_offset_angle - 180 + Degrees(spyder.arms[3].motor1_angle));
    servos[4].write(spyder.arms[3].motor2_offset_angle - Degrees(spyder.arms[3].motor2_angle));
    servos[5].write(spyder.arms[3].motor3_offset_angle - Degrees(spyder.arms[3].motor2_angle) + Degrees(spyder.arms[3].motor3_angle));
    
    servos[9].write(spyder.arms[4].motor1_offset_angle + Degrees(spyder.arms[4].motor1_angle));
    servos[10].write(spyder.arms[4].motor2_offset_angle + Degrees(spyder.arms[4].motor2_angle));
    servos[11].write(spyder.arms[4].motor3_offset_angle + Degrees(spyder.arms[4].motor2_angle) - Degrees(spyder.arms[4].motor3_angle));

    servos[15].write(spyder.arms[5].motor1_offset_angle + Degrees(spyder.arms[5].motor1_angle));
    servos[16].write(spyder.arms[5].motor2_offset_angle - Degrees(spyder.arms[5].motor2_angle));
    servos[17].write(spyder.arms[5].motor3_offset_angle - Degrees(spyder.arms[5].motor2_angle) + Degrees(spyder.arms[5].motor3_angle));
}

void EaseUpdateLegs(){
    // Set Leg group 1
    servos[6].easeTo(spyder.arms[0].motor1_offset_angle - 180 + Degrees(spyder.arms[0].motor1_angle));
    servos[7].easeTo(spyder.arms[0].motor2_offset_angle - Degrees(spyder.arms[0].motor2_angle));
    servos[8].easeTo(spyder.arms[0].motor3_offset_angle - Degrees(spyder.arms[0].motor2_angle) + Degrees(spyder.arms[0].motor3_angle));

    servos[0].easeTo(spyder.arms[1].motor1_offset_angle + 180 + Degrees(spyder.arms[1].motor1_angle));
    servos[1].easeTo(spyder.arms[1].motor2_offset_angle - Degrees(spyder.arms[1].motor2_angle));
    servos[2].easeTo(spyder.arms[1].motor3_offset_angle - Degrees(spyder.arms[1].motor2_angle) + Degrees(spyder.arms[1].motor3_angle));

    servos[12].easeTo(spyder.arms[2].motor1_offset_angle + Degrees(spyder.arms[2].motor1_angle));
    servos[13].easeTo(spyder.arms[2].motor2_offset_angle + Degrees(spyder.arms[2].motor2_angle));
    servos[14].easeTo(spyder.arms[2].motor3_offset_angle + Degrees(spyder.arms[2].motor2_angle) - Degrees(spyder.arms[2].motor3_angle));

    // Set Leg group 2
    if (Degrees(spyder.arms[3].motor1_angle) < 0)
        servos[3].easeTo(spyder.arms[3].motor1_offset_angle + 180 + Degrees(spyder.arms[3].motor1_angle));
    else 
        servos[3].easeTo(spyder.arms[3].motor1_offset_angle - 180 + Degrees(spyder.arms[3].motor1_angle));
    servos[4].easeTo(spyder.arms[3].motor2_offset_angle - Degrees(spyder.arms[3].motor2_angle));
    servos[5].easeTo(spyder.arms[3].motor3_offset_angle - Degrees(spyder.arms[3].motor2_angle) + Degrees(spyder.arms[3].motor3_angle));
    
    servos[9].easeTo(spyder.arms[4].motor1_offset_angle + Degrees(spyder.arms[4].motor1_angle));
    servos[10].easeTo(spyder.arms[4].motor2_offset_angle + Degrees(spyder.arms[4].motor2_angle));
    servos[11].easeTo(spyder.arms[4].motor3_offset_angle + Degrees(spyder.arms[4].motor2_angle) - Degrees(spyder.arms[4].motor3_angle));

    servos[15].easeTo(spyder.arms[5].motor1_offset_angle + Degrees(spyder.arms[5].motor1_angle));
    servos[16].easeTo(spyder.arms[5].motor2_offset_angle - Degrees(spyder.arms[5].motor2_angle));
    servos[17].easeTo(spyder.arms[5].motor3_offset_angle - Degrees(spyder.arms[5].motor2_angle) + Degrees(spyder.arms[5].motor3_angle));
}

void LegStartup() {
    // Set Leg group 1
    servos[6].write(spyder.arms[0].motor1_offset_angle);
    servos[7].write(spyder.arms[0].motor2_offset_angle);
    servos[8].write(spyder.arms[0].motor3_offset_angle);

    servos[0].write(spyder.arms[1].motor1_offset_angle );
    servos[1].write(spyder.arms[1].motor2_offset_angle );
    servos[2].write(spyder.arms[1].motor3_offset_angle );

    servos[12].write(spyder.arms[2].motor1_offset_angle);
    servos[13].write(spyder.arms[2].motor2_offset_angle);
    servos[14].write(spyder.arms[2].motor3_offset_angle);

    // Set Leg group 2
    servos[3].write(spyder.arms[3].motor1_offset_angle);
    servos[4].write(spyder.arms[3].motor2_offset_angle);
    servos[5].write(spyder.arms[3].motor3_offset_angle);
    
    servos[9].write(spyder.arms[4].motor1_offset_angle );
    servos[10].write(spyder.arms[4].motor2_offset_angle);
    servos[11].write(spyder.arms[4].motor3_offset_angle);

    servos[15].write(spyder.arms[5].motor1_offset_angle);
    servos[16].write(spyder.arms[5].motor2_offset_angle);
    servos[17].write(spyder.arms[5].motor3_offset_angle);
}

void setup (){
    Serial.begin(9600);
    Serial.println("SPYDER ROBOT STARTING...");
    // HM10.begin(9600); // set HM10 serial at 9600 baud rate
    // pinMode(LED_BUILTIN, OUTPUT);

    delay(2000);

    Serial.println("-- reading servo angle at pin 22");
    Serial.write(String(servos[0].read()).c_str());
    Serial.write("\n");
    
    Serial.println("-- initializing spyder at Position (0, 0, 0) with size 1.5 x 1.5");
    spyder.Init(Position(0,0,0), 1.5, 1.5);

    Serial.println("-- setting \"set 1\" motor offset angles");
    spyder.arms[0].motor1_offset_angle = 80;
    spyder.arms[0].motor2_offset_angle = 100;
    spyder.arms[0].motor3_offset_angle = 175;

    spyder.arms[1].motor1_offset_angle = 130;
    spyder.arms[1].motor2_offset_angle = 140;
    spyder.arms[1].motor3_offset_angle = 175;

    spyder.arms[2].motor1_offset_angle = 60;
    spyder.arms[2].motor2_offset_angle = 70;
    spyder.arms[2].motor3_offset_angle = 70;

    Serial.println("-- setting \"set 2\" motor offset angles");
    spyder.arms[3].motor1_offset_angle = 55;
    spyder.arms[3].motor2_offset_angle = 80;
    spyder.arms[3].motor3_offset_angle = 170;
    
    spyder.arms[4].motor1_offset_angle = 70;
    spyder.arms[4].motor2_offset_angle = 80;
    spyder.arms[4].motor3_offset_angle = 40;

    spyder.arms[5].motor1_offset_angle = 90;
    spyder.arms[5].motor2_offset_angle = 100;
    spyder.arms[5].motor3_offset_angle = 90;

    spyder.position.y = 0;

    spyder.Update(delta_time);

    int pointer = 0;
    Serial.println("-- attatching servos 22-40");
    int servo_pin = 22;
    while (servo_pin < 40) {
        int i = servo_pin - 22;
        servos[i].attach(servo_pin);
        LegStartup();
        if (pointer == 0) servo_pin += 2;
        if (pointer == 1) servo_pin -= 1;
        if (pointer == 2) {
            servo_pin += 2;
            pointer = -1;
        }
        pointer += 1;
        delay(500);
    }

    LegStartup();

    for (int i = 0; i < 18; i++){
        servos[i].setSpeed(70);
    }

    EaseUpdateLegs();

    while (spyder.position.y < 1) {
        spyder.position.y += 0.005;
        spyder.Update(delta_time);
        UpdateLegs();
    }

    delay(500);
}


void loop () {
    delta_time = CalculateDeltaTime();
    spyder.Update(delta_time);

    UpdateLegs();
    
    // if (spyder.position.y < 1.25) spyder.position.y += 0.01;
    // spyder.position.y = 1;
    spyder.walking = true;
    spyder.time = 1.5;
    spyder.walk.z = 0.5;


    // HM10.listen();  // listen the HM10 port
    // while (HM10.available() > 0) {   // if HM10 sends something then read
    //     appData = HM10.read();
    //     inData = String(appData);  // save the data in string format
    //     Serial.write(appData);
    //     Serial.write("working");
    //     digitalWrite(LED_BUILTIN, HIGH);
    // }

    // if (Serial.available() > 0) {
    //     char inData = (char)Serial.read();
    //     Serial.write(inData);
    //     if (inData == '0') {
    //         spyder.position.y -= 0.1;
    //         Serial.write("\nsuccess");
    //     }
    //     if (inData == '1') {
    //         spyder.position.y += 0.1;
    //         Serial.write("\nsuccess");
    //     }
    // }
}