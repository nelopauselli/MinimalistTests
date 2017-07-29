#include "MinimalistTests.h"

bool starting = false;
bool started = false;

void setup() {
  starting = true;

  Serial.begin(9600);

  TestSuite suite = TestSuite("My setup tests");
  suite.test("testing setup", setup_test);

  started = true;
}

void loop() {
  TestSuite suite = TestSuite("My loop tests");
  suite.test("testing loop", loop_test);

  delay(10000);
}

void setup_test(TestContext &context){
	context.isTrue(starting, "Setup should be rinning now");
	context.isTrue(!started, "Setup should run only once time");
}

void loop_test(TestContext &context){
	context.isTrue(millis() > 0, "Millis should be greater than 0");
}