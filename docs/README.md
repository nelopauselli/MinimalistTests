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
  TestSuite suite = TestSuite("Name of tests group");
```
the code is creating a TestSuite called **Name of tests group**

### 3. Run a test cases
```cpp
  suite.test("Test name", functionWithTestCode);
  suite.test("Other test", otherFunctionWithTestCode);
```
the code is run two test (called **Test name** and **Other test**) calling to **functionWithTestCode** and **otherFunctionWithTestCode**

### 4. Function with the test code
```cpp
void functionWithTestCode(TestContext &context){
	context.assertTrue(1+1==2, "1+1 should be equal 2");
}

void otherFunctionWithTestCode(TestContext &context){
	context.assertTrue(millis() > 0, "millis() should be greater than 0");
}
```
Here is two function with test code, they receive a parameter of type TestContext by reference, it contains method as assertTrue to make asserts
