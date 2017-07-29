#include "../MinimalistTests.h"

int suma(int n1, int n2)
{
    return n1+n2;
}

void prueba1(TestContext& context)
{
    context.isTrue(suma(1, 1)==3, "se esperaba que 1+1 sea igual a 3");
}

void prueba2(TestContext& context)
{
    context.isTrue(suma(2, 2)==4, "se esperaba que 2+2 sea igual a 4");
}

void prueba_e(TestContext& context)
{
    throw 5;
}

int main()
{
    {
        TestSuite sumas = TestSuite("Sumas");
        sumas.test("Sumar 1 + 1 == 3", prueba1);
        sumas.test("Sumar 2 + 2 == 4", prueba2);
    }

    {
        TestSuite excepciones = TestSuite("Excepciones");
        excepciones.test("Manejo de excepciones enteras", prueba_e);
    }
}
