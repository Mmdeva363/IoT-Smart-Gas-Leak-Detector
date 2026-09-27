#define BLYNK_TEMPLATE_ID "TMPL6uLZAhLa2"
#define BLYNK_TEMPLATE_NAME "مشروع مستشعر الغاز"
#define BLYNK_AUTH_TOKEN "syGkVkG3p3vlcCyn4Juk5HOJL38QTKOL"
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
 
char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "Hadeeli Phone";
char pass[] = "0123456788";

const int mq135Pin = A0;
const int ledPin = D1;
const int buzzerPin = D2;
int threshold = 800;

void setup() {
  Serial.begin(74880);
  Serial.println("Hello! I am working!");
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  Blynk.begin(auth, ssid, pass);
}

void loop() {
  Blynk.run();
  int gasValue = analogRead(mq135Pin);
  Blynk.virtualWrite(V0, gasValue);

  if (gasValue > threshold) {
    digitalWrite(ledPin, HIGH);
    digitalWrite(buzzerPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
    digitalWrite(buzzerPin, LOW);
  }
  delay(1000);
}