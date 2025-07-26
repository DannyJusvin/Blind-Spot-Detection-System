#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Wire.h>

// OLED setup
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1  // Required for Wokwi

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Ultrasonic Sensor Pins
const int trigLeft = 2;
const int echoLeft = 3;
const int trigRight = 4;
const int echoRight = 5;

// LED Pins
const int ledLeft = 6;
const int ledRight = 7;

// Buzzer Pins (optional)
const int buzzerLeft = 8;
const int buzzerRight = 9;

const int threshold = 30; // cm

void setup() {
  Serial.begin(9600);

  pinMode(trigLeft, OUTPUT);
  pinMode(echoLeft, INPUT);
  pinMode(trigRight, OUTPUT);
  pinMode(echoRight, INPUT);

  pinMode(ledLeft, OUTPUT);
  pinMode(ledRight, OUTPUT);
  pinMode(buzzerLeft, OUTPUT);
  pinMode(buzzerRight, OUTPUT);

  // OLED INIT
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
    Serial.println(F("SSD1306 allocation failed"));
    while (true);
  }
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
}

long getDistanceCM(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  long distance = duration * 0.034 / 2;

  return distance;
}

void loop() {
  long leftDistance = getDistanceCM(trigLeft, echoLeft);
  long rightDistance = getDistanceCM(trigRight, echoRight);

  // Serial Monitor Output
  Serial.print("Left: ");
  Serial.print(leftDistance);
  Serial.print(" cm\tRight: ");
  Serial.print(rightDistance);
  Serial.println(" cm");

  // LED & Buzzer Alerts
  digitalWrite(ledLeft, (leftDistance > 0 && leftDistance <= threshold) ? HIGH : LOW);
  digitalWrite(buzzerLeft, (leftDistance > 0 && leftDistance <= threshold) ? HIGH : LOW);

  digitalWrite(ledRight, (rightDistance > 0 && rightDistance <= threshold) ? HIGH : LOW);
  digitalWrite(buzzerRight, (rightDistance > 0 && rightDistance <= threshold) ? HIGH : LOW);

  // OLED Display Output
  display.clearDisplay();
  display.setCursor(0, 0);
  display.println("Blind Spot Monitor");
  display.println("-------------------");
  display.print("Left : ");
  display.print(leftDistance);
  display.println(" cm");

  display.print("Right: ");
  display.print(rightDistance);
  display.println(" cm");

  if (leftDistance <= threshold || rightDistance <= threshold) {
    display.println();
    display.setTextColor(SSD1306_BLACK, SSD1306_WHITE);  // Inverted
    display.print("  ALERT: Vehicle Near  ");
    display.setTextColor(SSD1306_WHITE);  // Back to normal
  }

  display.display();
  delay(300);
}
