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
  if (Serial.available()>0) {
    String cadena = Serial.readStringUntil('\n'); // Lee la cadena hasta el salto de línea

    // Busca la posición de los símbolos "#", "$", "%", y "&"
    int posicionNum1 = cadena.indexOf('#');
    int posicionNum2 = cadena.indexOf('$');
    int posicionNum3 = cadena.indexOf('%');
    int posicionNum4 = cadena.indexOf('&');

    // Verifica si se encontraron todos los símbolos
    if (posicionNum1 != -1 && posicionNum2 != -1 && posicionNum3 != -1 && posicionNum4 != -1) {
      // Usa substring para extraer los números que siguen a los símbolos
      String numeroStr1 = cadena.substring(posicionNum1 + 1, posicionNum2);
      String numeroStr2 = cadena.substring(posicionNum2 + 1, posicionNum3);
      String numeroStr3 = cadena.substring(posicionNum3 + 1, posicionNum4);
      String numeroStr4 = cadena.substring(posicionNum4 + 1);

      // Convierte los números de tipo String a int
       int numero1 = numeroStr1.toInt();
       int numero2 = numeroStr2.toInt();
       int numero3 = numeroStr3.toInt();
       int numero4 = numeroStr4.toInt();

      // Imprime los números encontrados
      Serial.print("Veleta Lima" + String(numero3)); //#
      Serial.println(" Veleta Nazca" + String(numero4));//&

      digitalWrite(numero1,LOW);
      digitalWrite(numero4,LOW);

      delay(numero2);

      digitalWrite(numero1,HIGH);
      digitalWrite(numero4,HIGH);

      delay(numero3);
      
      myservo.write(numero2); 
      
    } else {
      Serial.println("No hay conexión");
      delay(10);

    }
  }
      for (int thisPin = 2; thisPin < 20; thisPin++) {
      digitalWrite(thisPin, HIGH);}
}


// int actuators[] = {13,12,11,10,9,8,7,6,5,4,3,2,14,15,16,17,21,20};

// void setup() {
//   for (auto i:actuators) {
//     pinMode(i, OUTPUT);
//     digitalWrite(i, HIGH);
//   }
// }

// void loop() {
//   for (auto i:actuators) {
//     digitalWrite(i, LOW);  
//     delay(2000);            
//     digitalWrite(i, HIGH); 
//     delay(2000);            
//   }
// }







