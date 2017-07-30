#include "MinimalistTests.h"

void setup()
{
  Serial.begin(9600);
  TestSuite suite = TestSuite("Tests de encriptacion");
  suite.test("Encriptar ABC", encryptABCTest);
  suite.test("Encriptar XXXX", encryptXXXXTest);
}

void loop() {}

/*
 * Esta es la función que quiero testear
 */
void encrypt(char *source, char *buffer)
{
  int length = strlen(source);
  for (int i = 0; i < length; i++)
  {
    char c = source[i];
    if (c != '\0')
      buffer[i] = (c + 2); // very very bad idea to encrypt.
    else
      break;
  }
  buffer[length] = '\0';
}

/*
 * Estos son los tests
 */
void encryptABCTest(TestContext &context)
{
  char buffer[16];
  encrypt("ABC", buffer);
  context.assertTrue(3 == strlen(buffer), "Tamaño incorrecto!");
  context.assertAreEqual("CDE", buffer, "Resultado incorrecto!");
}

void encryptXXXXTest(TestContext &context)
{
  char buffer[16];
  encrypt("XXXX", buffer);
  context.assertAreEqual("ZZZX", buffer);
}
