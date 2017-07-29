#include <stdlib.h>

#ifdef WIN32
#include "ConsoleWindows.cpp"
#endif // WIN32
#ifdef ARDUINO
#include "ConsoleArduino.cpp"
#endif // ARDUINO

using namespace std;

#ifndef TEST_CONTEXT_CLASS
#define TEST_CONTEXT_CLASS

class TestContext
{
public:
    static int level;

    TestContext(const char *name)
    {
        tests = 0;
        fails = 0;
        success = 0;

        Console.info(indent(level, "Running ", name));
        _name = name;
        level++;
    }

    ~TestContext()
    {
        level--;
        Console.info(indent(level, _name, " complete."));
        report();
    }

    void assertTrue(bool assertion, const char* message)
    {
        tests++;
        if(!assertion)
        {
            fail(message);
        }
        else
        {
            success++;
        }
    }
    void fail(const char *message)
    {
        fails++;

        Console.error(indent(2, message));
    }

    void add(TestContext *other)
    {
        tests += other->tests;
        fails += other->fails;
        success += other->success;
    }
private:
    char *indent(int level, const char *input)
    {
        int size = level + strlen(input)+1;
        char *buffer = new char[size];
        strcpy(buffer, "");

        for(int i=0; i<level; i++)
            strcat(buffer, "\t");
        strcat(buffer, input);

        buffer[size-1] = '\0';
        return buffer;
    }

    char *indent(int level, const char *input1, const char *input2)
    {
        int size = level + strlen(input1) + strlen(input2)+1;
        char *buffer = new char[size];
        strcpy(buffer, "");

        for(int i=0; i<level; i++)
            strcat(buffer, "\t");
        strcat(buffer, input1);
        strcat(buffer, input2);

        buffer[size-1] = '\0';
        return buffer;
    }

    char *indent(int level, const char *input1, const char *input2, const char *input3, const char *input4, const char *input5, const char *input6)
    {
        int size = level + strlen(input1) + strlen(input2) + strlen(input3)+ strlen(input4)+ strlen(input5) + strlen(input6)+1;
        char *buffer = new char[size];
        strcpy(buffer, "");

        for(int i=0; i<level; i++)
            strcat(buffer, "\t");

        strcat(buffer, input1);
        strcat(buffer, input2);
        strcat(buffer, input3);
        strcat(buffer, input4);
        strcat(buffer, input5);
        strcat(buffer, input6);

        buffer[size-1] = '\0';
        return buffer;
    }

    void report()
    {
        char testsBuffer[16];
        itoa(tests, testsBuffer, 10);
        char failsBuffer[16];
        itoa(fails, failsBuffer, 10);
        char successBuffer[16];
        itoa(success, successBuffer, 10);

        const char *message = indent(level, testsBuffer, " tests, ", failsBuffer, " fails, ", successBuffer, " success.");

        if(fails > 0)
            Console.error(message);
        else if(success > 0)
            Console.info(message);
        else
            Console.warning(message);
    }

    const char *_name;
    int tests;
    int fails;
    int success;

};

int TestContext::level = 0;

#endif // TEST_CONTEXT_CLASS
