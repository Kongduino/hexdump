#include <Adafruit_TinyUSB.h>
#include <hexdump.h>

char buffer[] = "This is a random buffer to demonstrate hexDump()...";

void setup() {
  Serial.begin(115200);
  hexDump((uint8_t *)buffer, strlen(buffer));
}

void loop() {
}
