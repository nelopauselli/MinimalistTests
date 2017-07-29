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

        Console.running(level, name);
        _name = name;
        level++;
    }

    ~TestContext()
    {
        level--;
        Console.complete(level, _name, tests, fails, success);
    }

    void assertTrue(bool assertion, const char *message)
    {
        tests++;
        if (!assertion)
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
        Console.fail(level, message);
    }

    void add(TestContext *other)
    {
        tests += other->tests;
        fails += other->fails;
        success += other->success;
    }

  private:
    const char *_name;
    int tests;
    int fails;
    int success;
};

int TestContext::level = 0;

#endif // TEST_CONTEXT_CLASS
