const int trigPin = 9; // Blanco

const int echoPin = 8; // Café

const int buzzerPin = 10; // Verde

const int ledPin = 11; // Morado

const int botonPin = 7; // Blanco


void setup() {

Serial.begin(9600);

pinMode(trigPin, OUTPUT);

pinMode(echoPin, INPUT);

pinMode(buzzerPin, OUTPUT);

pinMode(ledPin, OUTPUT);

pinMode(botonPin, INPUT_PULLUP);


// PRUEBA INICIAL: Debe sonar 1 segundo al encender

tone(buzzerPin, 1000, 1000);

}


void loop() {

long duration;

int distance;


digitalWrite(trigPin, LOW);

delayMicroseconds(2);

digitalWrite(trigPin, HIGH);

delayMicroseconds(10);

digitalWrite(trigPin, LOW);


duration = pulseIn(echoPin, HIGH, 30000);

distance = duration * 0.034 / 2;


Serial.print("Distancia: ");

Serial.print(distance);

Serial.println(" cm");


// Si la distancia es menor a 20cm o presionas el botón

if ((distance > 0 && distance < 20) || digitalRead(botonPin) == LOW) {

digitalWrite(ledPin, HIGH);

tone(buzzerPin, 1000); // Activa el sonido

} else {

digitalWrite(ledPin, LOW);

noTone(buzzerPin); // Apaga el sonido

}

delay(100);

}
