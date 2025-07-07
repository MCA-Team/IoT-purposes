#include <ESP8266WiFi.h>
#include <PubSubClient.h>

const char* ssid = "xxxxxx";
const char* password = "yyyyy";
const char* mqtt_server = "zzzzz";

WiFiClient espClient;
PubSubClient client(espClient);

void setup_wifi() {
  delay(10);
  Serial.println("Connexion au WiFi...");
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  // Connected
  Serial.println("");
  Serial.println("WiFi connected");
  
  // Print IP address and other info
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  Serial.print("Subnet Mask: ");
  Serial.println(WiFi.subnetMask());

  Serial.print("Gateway IP: ");
  Serial.println(WiFi.gatewayIP());

  Serial.print("MAC Address: ");
  Serial.println(WiFi.macAddress());
}

void reconnect() {
  while (!client.connected()) {
    Serial.print("Connexion au broker MQTT...");
    if (client.connect("wemosClient")) {
      Serial.println("connecté");
    } else {
      Serial.print("échec, rc=");
      Serial.print(client.state());
      Serial.print("\n");
      delay(5000);
    }
  }
}

void setup() {
  Serial.begin(115200);
  setup_wifi();
  client.setServer(mqtt_server, 1885);
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  // Données internes
  long uptime = millis() / 1000;
  int rssi = WiFi.RSSI();
  int heap = ESP.getFreeHeap();

  // Donnée simulée
  int temperature = random(20, 30);

  // Format JSON simple
  String payload = "{";
  payload += "\"uptime\":" + String(uptime) + ",";
  payload += "\"rssi\":" + String(rssi) + ",";
  payload += "\"heap\":" + String(heap) + ",";
  payload += "\"temperature\":" + String(temperature);
  payload += "}";

  client.publish("wemos/status", payload.c_str());
  Serial.print("Message published !\n");
  Serial.print(payload+"\n");

  delay(5000);  // Toutes les 5 secondes
}











