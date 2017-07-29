#include <iostream>
#include <windows.h>
#include "Console.h"

#ifndef CONSOLE_WINDOWS_CLASS
#define CONSOLE_WINDOWS_CLASS

using namespace std;


class ConsoleWindows : public Console
{
public:
    void info(const char *message)
    {
        short color = getConsoleColor();
        setConsoleColor(2);
        cout << message << endl;
        setConsoleColor(color);
    }
    void error(const char *message)
    {
        short color = getConsoleColor();
        setConsoleColor(12);
        cout << message << endl;
        setConsoleColor(color);
    }
    void warning(const char *message)
    {
        short color = getConsoleColor();
        setConsoleColor(6);
        cout << message << endl;
        setConsoleColor(color);
    }
private:
    short getConsoleColor()
    {
        CONSOLE_SCREEN_BUFFER_INFO info;
        if (!GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info))
            return 0;
        short ret = info.wAttributes;
        return ret;
    }

    void setConsoleColor(short color)
    {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, color);
    }
};

ConsoleWindows Console;

#endif // CONSOLE_WINDOWS_CLASS
