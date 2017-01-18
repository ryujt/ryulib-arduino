#include <RH_ASK.h>
#include <SPI.h>

RH_ASK sender;

void setup()
{
}

void loop()
{
    char *msg = "Hi";
    driver.send((uint8_t *)msg, strlen(msg));
    driver.waitPacketSent();
    delay(100);
}
