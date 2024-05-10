#include <Servo.h>

Servo myservo;

void setup() {
  Serial.begin(9600);
  for (int thisPin = 2; thisPin < 20; thisPin++) {
    pinMode(thisPin, OUTPUT);
  }

  myservo.attach(22);
}

void loop() {
  if (Serial.available() > 0) {
    String cadena = Serial.readStringUntil('\n');

    int posicionNum1 = cadena.indexOf('#');
    int posicionNum2 = cadena.indexOf('$');
    int posicionNum3 = cadena.indexOf('%');
    int posicionNum4 = cadena.indexOf('&');

    if (posicionNum1 != -1 && posicionNum2 != -1 && posicionNum3 != -1 &&
        posicionNum4 != -1) {
      String numeroStr1 = cadena.substring(posicionNum1 + 1, posicionNum2);
      String numeroStr2 = cadena.substring(posicionNum2 + 1, posicionNum3);
      String numeroStr3 = cadena.substring(posicionNum3 + 1, posicionNum4);
      String numeroStr4 = cadena.substring(posicionNum4 + 1);

      int numero1 = numeroStr1.toInt();
      int numero2 = numeroStr2.toInt();
      int numero3 = numeroStr3.toInt();
      int numero4 = numeroStr4.toInt();

      Serial.print("Veleta Lima" + String(numero3));      // #
      Serial.println(" Veleta Nazca" + String(numero4));  //&

      digitalWrite(numero1, LOW);
      digitalWrite(numero4, LOW);

      delay(numero2);

      digitalWrite(numero1, HIGH);
      digitalWrite(numero4, HIGH);

      delay(numero3);

      myservo.write(numero2);

    } else {
      Serial.println("No hay conexión");
      delay(10);
    }
  }
  for (int thisPin = 2; thisPin < 20; thisPin++) {
    digitalWrite(thisPin, HIGH);
  }
}

// // int actuators[] = {13,12,11,10,9,8,7,6,5,4,3,2,14,15,16,17,21,20};

// void setup() {
//   myservo.attach(22);
//   for (auto i:actuators) {
//     pinMode(i, OUTPUT);
//     digitalWrite(i, HIGH);
//   }
// }

// void loop() {
//   for (auto i:actuators) {
//     myservo.write(180);
//     delay(100);
//     digitalWrite(i, LOW);
//     for (int i=180;i>=0;i--) {
//       myservo.write(i);
//       delay(11);
//     }
//     // delay(100);
//     digitalWrite(i, HIGH);
//     delay(100);

//   }
// }
