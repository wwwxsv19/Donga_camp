#include <DHT.h>
#include <DHT_U.h>

DHT myone(7, DHT11);

void setup() {
  Serial.begin(9600);
  myone.begin();
}

void loop() {
  int temp = myone.readTemperature();
  int humi = myone.readHumidity();

  // 불쾌지수 ~
  float discom = (1.8 * temp) - (0.55 * (1 - humi / 100) * (1.8 * temp - 26)) + 32;

  Serial.print("temperature : ");
  Serial.print(temp);
  Serial.print("C");
  Serial.print(" / Humidity : ");
  Serial.print(humi);
  Serial.print("% / ");
  Serial.print("Good or Bad : ");
  Serial.println(discom);
  delay(1000);
}
