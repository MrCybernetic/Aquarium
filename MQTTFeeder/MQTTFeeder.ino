#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <ESP8266mDNS.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>
#include "secrets.h"

const char *mqtt_server = "llmpi";
const char *HostName = "Feeder_MQTT_01";
const char *topic_Feeder = "FEEDER";
const char *topic_Feeder_OK = "FEEDER_OK";

WiFiClient espClient;
PubSubClient client(espClient);

void callback(String topic, byte *message, unsigned int length)
{
    String messageTemp;
    for (int i = 0; i < length; i++)
    {
        messageTemp += (char)message[i];
    }

    if (topic == topic_Feeder && messageTemp == "ON")
    {
        digitalWrite(0, HIGH);
        unsigned long start = millis();
        while (millis() - start < 20000)
        {
            client.loop();
            delay(10);
        }
        digitalWrite(0, LOW);
        client.publish(topic_Feeder_OK, "Feeder activated", true);
    }
}

void setup_wifi()
{
    Serial.println("Setting up WiFi...");
    WiFi.mode(WIFI_STA);
    WiFi.setHostname(HostName);
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED)
    {
        Serial.print(".");
        delay(500);
    }
    Serial.println("");
    Serial.println("WiFi connected");
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());
}

void setup_OTA()
{
    Serial.println("Setting up OTA...");
    // Port defaults to 8266
    // ArduinoOTA.setPort(8266);

    // Hostname defaults to esp8266-[ChipID]
    ArduinoOTA.setHostname(HostName);
    Serial.print("OTA Hostname: ");
    Serial.println(HostName);

    // No authentication by default
    // ArduinoOTA.setPassword("admin");

    ArduinoOTA.onStart([]()
                       {
        String type;
        if (ArduinoOTA.getCommand() == U_FLASH) {
            type = "sketch";
        } else { // U_FS
            type = "filesystem";
        }
        Serial.println("Start updating " + type); });

    ArduinoOTA.onEnd([]()
                     { Serial.println("\nUpdate complete"); });

    ArduinoOTA.onProgress([](unsigned int progress, unsigned int total)
                          { Serial.printf("Progress: %u%%\r", (progress / (total / 100))); });

    ArduinoOTA.onError([](ota_error_t error)
                       {
        Serial.printf("Error[%u]: ", error);
        if (error == OTA_AUTH_ERROR) {
            Serial.println("Auth Failed");
        } else if (error == OTA_BEGIN_ERROR) {
            Serial.println("Begin Failed");
        } else if (error == OTA_CONNECT_ERROR) {
            Serial.println("Connect Failed");
        } else if (error == OTA_RECEIVE_ERROR) {
            Serial.println("Receive Failed");
        } else if (error == OTA_END_ERROR) {
            Serial.println("End Failed");
        } });

    ArduinoOTA.begin();
    Serial.println("OTA Ready");
}

void reconnect()
{
    // Remove setCleanSession as it's not available in the PubSubClient library
    String clientId = "ESP8266Client-Feeder01";
    Serial.println("Attempting MQTT connection...");
    while (!client.connected())
    {
        // Using connect with clean session parameter (false = persistent session)
        if (client.connect(clientId.c_str(), NULL, NULL, NULL, 0, false, NULL))
        {
            Serial.println("MQTT connected");
            client.subscribe(topic_Feeder);
            Serial.println("Subscribed to topic: " + String(topic_Feeder));
        }
        else
        {
            Serial.print("MQTT connection failed, rc=");
            Serial.print(client.state());
            Serial.println(" Retrying in 2 seconds...");
            delay(2000);
        }
    }
}

void setup()
{
    Serial.begin(115200);
    Serial.println("\n\nMQTT Feeder with OTA Starting...With Changes");
    setup_wifi();
    setup_OTA();
    client.setServer(mqtt_server, 1883);
    client.setCallback(callback);
    pinMode(0, OUTPUT);
    digitalWrite(0, LOW);
    Serial.println("Setup complete");
}

void loop()
{
    ArduinoOTA.handle();

    if (!client.connected())
    {
        reconnect();
    }
    client.loop();
}
