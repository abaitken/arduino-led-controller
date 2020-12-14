// #include "network.h"
// #include <SoftwareSerial.h>
// #include "secrets.h"
// #include "leds.h"

// #define _ESPLOGLEVEL_ 0
// #include <WiFiEsp.h>

// #define SERIAL_ESP 9600
// #define DPIN_ESP_RX 2
// #define DPIN_ESP_TX 3

// SoftwareSerial EspSerial(DPIN_ESP_RX, DPIN_ESP_TX); // RX, TX

// void SetupNetwork()
// {
//     g_leds[INDICATOR_NETWORK] = CRGB::Red;
//     FastLED.show();

//     EspSerial.begin(SERIAL_ESP);
//     WiFi.init(&EspSerial);

//     if (WiFi.status() == WL_NO_SHIELD)
//     {
//         while (true)
//             delay(1000);
//     }

//     g_leds[INDICATOR_NETWORK] = CRGB::Orange;
//     FastLED.show();

//     int status = WL_IDLE_STATUS;
//     while (status != WL_CONNECTED)
//     {
//         status = WiFi.begin(WIFI_SSID, WIFI_PASS);
//     }
    
//     g_leds[INDICATOR_NETWORK] = CRGB::Green;
//     FastLED.show();
// }