#ifndef HUB_AP_SETUP_SERVICE
#define HUB_AP_SETUP_SERVICE

#include <SPI.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

#include "HubAP.h"
#include "html.h"

#define HUB_AP_SETUP_BTN 15 

// setup service class
class SetupServiceClass {
	public:
		SetupServiceClass();
		
		uint8_t setup();
		void loop();
	private:
		void _handleRoot();
		void _handleSet();
		void _handleRestart();
		void _handleNotFound();
		void _handleReset();

		ESP8266WebServer _server;

};

static SetupServiceClass SetupService;

#endif // HUB_AP_SETUP_SERVICE
