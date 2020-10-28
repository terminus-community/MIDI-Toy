#include "WiFi.h"
#include "ESPAsyncWebServer.h"
#include "esp_log.h"

AsyncWebServer server(80);
const char *ssid = "MIDI toy";
const char *password = "60951484";

int program = 1; // Piano

void setup() {
  Serial.begin(115200);
  Serial2.begin(31250);

  WiFi.softAP(ssid, password);
  Serial.println("Soft AP ready.");
  Serial.println(WiFi.softAPIP());

  server.on("/on", HTTP_GET, [](AsyncWebServerRequest * request) {
    if (request->hasParam("pitch") && request->hasParam("velocity"))
    {
      midi_note_on(
        constrain(request->getParam("pitch")->value().toInt(), 0, 127),
        constrain(request->getParam("velocity")->value().toInt(), 0, 127)
      );
      request->send(200, "text/plain", "ACK");
    } else {
      request->send(200, "text/plain", "Bad format");
    }
  });

  server.on("/off", HTTP_GET, [](AsyncWebServerRequest * request) {
    if (request->hasParam("pitch") && request->hasParam("velocity"))
    {
      midi_note_off(
        constrain(request->getParam("pitch")->value().toInt(), 0, 127),
        constrain(request->getParam("velocity")->value().toInt(), 0, 127)
      );
      request->send(200, "text/plain", "ACK");
    } else {
      request->send(200, "text/plain", "Bad format");
    }
  });

  server.on("/ins", HTTP_GET, [](AsyncWebServerRequest * request) {
    if (request->hasParam("patch")) {
      // I do not clamp zero, maybe I will regret it.
      midi_patch_change(
        constrain(request->getParam("patch")->value().toInt(), 0, 128)
      );
      request->send(200, "text/plain", "ACK");
    } else {
      request->send(200, "text/plain", "Bad format");
    }
  });

  server.on("/start", HTTP_GET, [](AsyncWebServerRequest * request) {
    midi_start();
    request->send(200, "text/plain", "ACK");
  });

  server.on("/stop", HTTP_GET, [](AsyncWebServerRequest * request) {
    midi_stop();
    request->send(200, "text/plain", "ACK");
  });

  server.on("/reset", HTTP_GET, [](AsyncWebServerRequest * request) {
    midi_reset();
    request->send(200, "text/plain", "ACK");
  });

  server.on("/", HTTP_GET, [](AsyncWebServerRequest * request) {
    request->send(200, "text/plain", "Commands: on, off, ins");
  });

  server.begin();
}

void loop() {}

void midi_note_off(int pitch, int velocity) {
  Serial2.write(0x80);
  Serial2.write(pitch);
  Serial2.write(velocity);
}

void midi_note_on(int pitch, int velocity) {
  Serial2.write(0x90);
  Serial2.write(pitch);
  Serial2.write(velocity);
}

void midi_patch_change(int patch) {
  Serial2.write(0xC0);
  Serial2.write(patch);
}

void midi_start() {
  Serial2.write(0xFA);
}

void midi_stop() {
  Serial2.write(0xFC);
}

void midi_reset() {
  Serial2.write(0xFF);
}
