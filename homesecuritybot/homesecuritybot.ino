#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>


const char* ssid = "Srijit2.4";// Enter your WIFI SSID
const char* password = "9434978002";// Enter your WIFI Password


#define BOTtoken "6279484336:AAFwdFmfoAr0O5q_ZOFKlW7dcZkQQKon3CQ" // Enter the bottoken you got from botfather
#define CHAT_ID "1052745341" // Enter your chatID you got from chatid bot


X509List cert(TELEGRAM_CERTIFICATE_ROOT);
WiFiClientSecure client;
UniversalTelegramBot bot(BOTtoken, client);

int const trigPin = 4;
int const echoPin = 5;
int const buzzPin = 12;
const int LED1 = 13;

void setup()
{
  Serial.begin(115200);
  configTime(0, 0, "pool.ntp.org");      
  client.setTrustAnchors(&cert);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  int a = 0;
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
    a++;
  }
  
pinMode(trigPin, OUTPUT); 
pinMode(echoPin, INPUT);
pinMode(buzzPin, OUTPUT);
pinMode(LED1 , OUTPUT);

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  bot.sendMessage(CHAT_ID, "Wifi Connected!", "");
  bot.sendMessage(CHAT_ID, "System has Started!!", "");

}
void loop()
{

int duration, distance;
digitalWrite(trigPin, HIGH);
delay(1);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance = (duration/2) / 29.1;

if (distance <= 10 && distance >= 0) {
digitalWrite(buzzPin, HIGH);
digitalWrite(LED1, HIGH);
bot.sendMessage(CHAT_ID, "ALERT! MOTION DETECTED!!", "");

} else {
digitalWrite(buzzPin, LOW);
digitalWrite(LED1, LOW);
}

}
