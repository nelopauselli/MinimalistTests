# Minimalist Tests
Minimalist framework to testing C++ **and** Arduino

## Arduino
See [Arduino example](/examples/Testing_setup_and_loop/Testing_setup_and_loop.ino) 

### 1. Include 
```cpp
#include "MinimalistTests.h"
```
### 2. Create a TestSuite
```cpp
  TestSuite suite = TestSuite("My tests group");
```
this code is creating a TestSuite named **My tests group**

### 3. Run test cases
```cpp
  suite.test("My sum test", testSum1p1e2);
  suite.test("My millis test", testMillis);
```
this code is running two test case named **My sum test** and **My millis test**, calling to **testSum1p1e2** and to **testMillis** respectively

### 4. Function with the test code
```cpp
void testSum1p1e2(TestContext &context){
	context.assertTrue(1+1==2, "1+1 should be equal 2");
}

void testMillis(TestContext &context){
	context.assertTrue(millis() > 0, "millis() should be greater than 0");
}
```
Here is two function with test code, they receive a parameter of type TestContext by **reference**, it contains methods as assertTrue to do assertions
