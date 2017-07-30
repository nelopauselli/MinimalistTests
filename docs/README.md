# Minimalist Tests
Framework minimalista de testing para C++ y Arduino

## Arduino
See [Arduino example](/examples/Testing_setup_and_loop/Testing_setup_and_loop.ino) 

### 1. Include 
```cpp
#include "MinimalistTests.h"
```
### Create a TestSuite
```cpp
  TestSuite suite = TestSuite("Name of tests group");
```
the code is creating a TestSuite called **Name of tests group**

### Test a case
```cpp
  suite.test("Test name", functionWithTestCode);
  suite.test("Other test", otherFunctionWithTestCode);
```
the code is run a test called **Test name** calling to **functionWithTestCode**

the code is run a test called **Other test** calling to **otherFunctionWithTestCode**

### Function with test code
```cpp
void functionWithTestCode(TestContext &context){
	context.assertTrue(1+1==2, "1+1 should be equal 2");
}

void otherFunctionWithTestCode(TestContext &context){
	context.assertTrue(millis() > 0, "millis() should be greater than 0");
}
```
Here is two function with test code, they receive a parameter of type TestContext by reference, it contains method as assertTrue to make asserts
