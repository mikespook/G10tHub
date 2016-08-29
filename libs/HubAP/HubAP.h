#ifndef HUB_AP_H
#define HUB_AP_H

#include <SPI.h>
#include <ESP8266WiFi.h>
#include <EEPROM.h>

#define HUB_AP_STATE_INIT 0
#define HUB_AP_STATE_SETUP 1
#define HUB_AP_STATE_ERROR 0xff

#include "Config.h"
#include "SetupService.h"

// handler function 
typedef uint8_t (*StateHandler)(uint8_t, void * ...);

// main class
class HubAPClass {
	public:
		HubAPClass();
		
		// call this in loop() and handle the return value
		uint8_t loop(void *...);
		void setup();
		void flashLED(int);
		void add(uint8_t, StateHandler);
		// int call(char * api, char **pn, char **pv);
		void setState(uint8_t);

		void reset();
	private:
		uint8_t _state = HUB_AP_STATE_INIT;
		uint8_t _macAddr[6];

		StateHandler _states[UINT8_MAX] = { NULL };
		void _connectWiFi();
};

static HubAPClass HubAP;
#endif // HUB_AP_H
