#include "MinimalistTests.h"

void setup() {
  Serial.begin(9600);

  TestSuite suite = TestSuite("Mis tests en setup()");
  delay(10);
  suite.test("testing setup", setup_test);
  delay(10);
}

void loop() {
  TestSuite suite = TestSuite("Mis tests en loop()");
  suite.test("testing loop", loop_test);

  delay(10000);
}

void setup_test(TestContext &context){
  int a = 1;
	context.assertTrue(a==1, "a debía ser igual a 1");
}

void loop_test(TestContext &context){
	context.assertTrue(millis() > 0, "millis() debe ser mayor a cero");
}