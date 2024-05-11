#include <Servo.h>

Servo servo_flow;

int actuators[] = {13, 12, 11, 10, 9,  8,  7,  6,  5,
                   4,  3,  2,  14, 15, 16, 17, 21, 20};

void setup() {
  Serial.begin(9600);

  for (auto i : actuators) {
    pinMode(i, OUTPUT);
    digitalWrite(i, HIGH);
  }

  servo_flow.attach(22);
}

void loop() {
  if (Serial.available() > 0) {
    String line = Serial.readStringUntil('\n');

    int pos_num_1 = line.indexOf('#');
    int pos_num_2 = line.indexOf('$');
    int pos_num_3 = line.indexOf('%');
    int pos_num_4 = line.indexOf('&');

    if (pos_num_1 != -1 && pos_num_2 != -1 && pos_num_3 != -1 &&
        pos_num_4 != -1) {
      String numeroStr1 = line.substring(pos_num_1 + 1, pos_num_2);
      String numeroStr2 = line.substring(pos_num_2 + 1, pos_num_3);
      String numeroStr3 = line.substring(pos_num_3 + 1, pos_num_4);
      String numeroStr4 = line.substring(pos_num_4 + 1);

      int numero1 = numeroStr1.toInt();
      int numero2 = numeroStr2.toInt();
      int numero3 = numeroStr3.toInt();
      int numero4 = numeroStr4.toInt();

      digitalWrite(numero1, LOW);

      delay(map(numero2, 0, 30, 0, 3000));

      digitalWrite(numero1, HIGH);

      delay(map(numero3, 0, 360, 0, 1000));

      servo_flow.write(numero2);

    } else {
      Serial.println("No hay conexión");
      delay(100);
    }
  }

  for (int thisPin = 2; thisPin < 20; thisPin++) {
    digitalWrite(thisPin, HIGH);
  }

  for (auto i : actuators) {
    pinMode(i, OUTPUT);
    digitalWrite(i, HIGH);
  }
}
