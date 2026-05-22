// ALARMA DE PROXIMIDAD CON ARDUINO //
// Sensor HC-SR04 + LED + Buzzer + Botón para desactivar buzzer

const int trigPin = 8;
const int echoPin = 9;
const int buzzerPin = 4;
const int ledPin = 10;
const int botonPin = 2; // Botón para apagar buzzer

long duracion;
int distancia;
bool buzzerActivo = true; // Estado del buzzer
bool estadoAnteriorBoton = HIGH;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(botonPin, INPUT_PULLUP); // Botón conectado a GND de forma segura
  
  Serial.begin(9600);
}

void loop() {
  // Leer botón
  bool estadoBoton = digitalRead(botonPin);

  // Detectar pulsación del botón
  if (estadoAnteriorBoton == HIGH && estadoBoton == LOW) {
    buzzerActivo = !buzzerActivo; // Cambia entre activado y desactivado
    delay(200); // Antirrebote simple
  }
  estadoAnteriorBoton = estadoBoton;

  // Limpiar el pin TRIG
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  // Enviar pulso ultrasónico
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Leer el tiempo del ECHO
  duracion = pulseIn(echoPin, HIGH, 30000);

  // Calcular distancia en centímetros
  distancia = duracion * 0.034 / 2;

  // Mostrar distancia y estado del buzzer en el Monitor Serie
  Serial.print("Distancia: ");
  Serial.print(distancia);
  Serial.print(" cm | Buzzer: ");
  if (buzzerActivo) {
    Serial.println("ACTIVO");
  } else {
    Serial.println("DESACTIVADO");
  }

  // Si algo se acerca a menos de 20 cm, activa la alarma
  if (distancia > 0 && distancia < 20) {
    digitalWrite(ledPin, HIGH); // El LED enciende para alumbrar
    if (buzzerActivo) {
      tone(buzzerPin, 1000); // Suena el buzzer
    } else {
      noTone(buzzerPin); // Se apaga si presionas el botón
    }
  } else {
    digitalWrite(ledPin, LOW); // Si no hay nada, el LED se apaga
    noTone(buzzerPin);         // El buzzer se apaga
  }

  delay(100);
}
