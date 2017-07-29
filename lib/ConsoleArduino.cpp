#include "Console.h"
#include "Arduino.h"

#ifndef CONSOLE_ARDUINO_CLASS
#define CONSOLE_ARDUINO_CLASS

class ConsoleArduino : public Console
{
  public:
    void info(const char *message)
    {
        Serial.print("[INFO] ");
        Serial.println(message);
    }
    void error(const char *message)
    {
        Serial.print("[ERROR] ");
        Serial.println(message);
    }
    void warning(const char *message)
    {
        Serial.print("[WARN] ");
        Serial.println(message);
    }
};

ConsoleArduino Console;

#endif // CONSOLE_ARDUINO_CLASS
