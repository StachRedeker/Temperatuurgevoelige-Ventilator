/********************************
Automatische ventilator
Stach Redeker
2019
********************************/
#include <DHT.h> //  library

const int relayPin = 8;
const int DHTPIN = A0;

// Hij werkt met drie types sensoren
#define DHTTYPE DHT11   // DHT 11
//#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
//#define DHTTYPE DHT21   // DHT 21 (AM2301)

DHT dht(DHTPIN, DHTTYPE);// Initialiseer DHT sensor

/********************************/
void setup() {
  Serial.begin(9600);
  pinMode(relayPin, OUTPUT);
  dht.begin();
}

void loop()
{
  float h = dht.readHumidity();
  // Lees temp in Celsius (standaard)
  float t = dht.readTemperature();
  // Lees temp in Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

  // Check of het fout gaat.
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  Serial.print("Temperatuur = ");
  Serial.print(t);
  Serial.print(" *C ");
  Serial.print("Temperatuur = ");
  Serial.print(f);
  Serial.print(" *F ");
  Serial.print("Vochtigheid = ");
  Serial.print(h);
  Serial.print(" %\t ");
  Serial.println();

 // Onderstaande is alleen nuttig als je wat met de luchtvochtigheid wil doen
 // if (h >= 66) { // Verander triggerwaarde luchtvochtigheid hier
 //   digitalWrite(relayPin, LOW);
 // }
 // else {
//    digitalWrite(relayPin, HIGH);
 // }

 // Onderstaande is alleen nuttig als je wat met de temperatuur wil doen
  if (t >= 25) {// Verander triggerwaarde temperatuur hier
    digitalWrite(relayPin, HIGH);
  }
  else {
    digitalWrite(relayPin, LOW);
  }
  delay(100000);// 100 seconden delay tussen metingen, kun je veranderen om bijvoorbeeld energie te besparen
}
