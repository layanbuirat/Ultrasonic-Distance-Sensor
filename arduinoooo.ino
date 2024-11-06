// Define pins
const int trigPin = 11; // Trigger pin for ultrasonic sensor
const int echoPin = 10; // Echo pin for ultrasonic sensor
const int greenLedPin = 7; // Green LED pin
const int yellowLedPin = 6; // Yellow LED pin
const int redLedPin = 3; // Red LED pin

// Static distance ranges
const int rangeGreen = 20; // Green LED range
const int rangeYellow = 10; // Yellow LED range

void setup() {
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    pinMode(greenLedPin, OUTPUT);
    pinMode(yellowLedPin, OUTPUT);
    pinMode(redLedPin, OUTPUT);

    Serial.begin(9600); // Initialize serial communication for debugging
}

void loop() {
    long distance = measureDistance(); // Measure distance using the ultrasonic sensor

    // Print the distance to the Serial Monitor for debugging
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");

    // Control LEDs based on the distance ranges
    if (distance >= rangeGreen) {
        digitalWrite(greenLedPin, HIGH);
        digitalWrite(yellowLedPin, LOW);
        digitalWrite(redLedPin, LOW);
    } else if (distance > rangeYellow && distance < rangeGreen) {
        digitalWrite(greenLedPin, LOW);
        digitalWrite(yellowLedPin, HIGH);
        digitalWrite(redLedPin, LOW);
    } else{
        digitalWrite(greenLedPin, LOW);
        digitalWrite(yellowLedPin, LOW);
        digitalWrite(redLedPin, HIGH);
    }



    delay(100); // Short delay to avoid overwhelming the sensor
}

// Function to measure distance
long measureDistance() {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    long duration = pulseIn(echoPin, HIGH);
    long distance = duration * 0.034 / 2; // Calculate distance in cm
    return distance;
}
