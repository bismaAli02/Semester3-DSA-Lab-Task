#include <iostream>
#include <cmath>
using namespace std;
class ComplexNumbers
{
    double realNumber;
    double imaginaryNumber;

public:
    ComplexNumbers()
    {
        realNumber = imaginaryNumber = 0;
    }
    ComplexNumbers(double realNumber)
    {
        this->realNumber = realNumber;
        imaginaryNumber = 0;
    }
    ComplexNumbers(double realNumber, double imaginaryNumber)
    {
        this->realNumber = realNumber;
        this->imaginaryNumber = imaginaryNumber;
    }
    ComplexNumbers(const ComplexNumbers &obj)
    {
        realNumber = obj.realNumber;
        imaginaryNumber = obj.imaginaryNumber;
    }

    ComplexNumbers addComplexNumber(ComplexNumbers c)
    {
        double realNo = realNumber + c.realNumber;
        double imaginaryNo = imaginaryNumber + c.imaginaryNumber;
        ComplexNumbers result = ComplexNumbers(realNo, imaginaryNo);
        return result;
    }

    ComplexNumbers subtractComplexNumber(ComplexNumbers c)
    {
        double realNo = realNumber - c.realNumber;
        double imaginaryNo = imaginaryNumber - c.imaginaryNumber;
        ComplexNumbers result = ComplexNumbers(realNo, imaginaryNo);
        return result;
    }

    ComplexNumbers conjugateOfComplexNumber(ComplexNumbers c)
    {
        double realNo = c.realNumber;
        double imaginaryNo = -c.imaginaryNumber;
        ComplexNumbers conjugate = ComplexNumbers(realNo, imaginaryNo);
        return conjugate;
    }

    ComplexNumbers multiplyComplexNumber(ComplexNumbers c)
    {
        double realNo = (realNumber * c.realNumber) - (imaginaryNumber * c.imaginaryNumber);
        double imaginaryNo = (realNumber * c.imaginaryNumber) + (c.realNumber * imaginaryNumber);
        ComplexNumbers result = ComplexNumbers(realNo, imaginaryNo);
        return result;
    }

    ComplexNumbers divideComplexNumber(ComplexNumbers c)
    {
        ComplexNumbers complex = conjugateOfComplexNumber(c);
        complex = multiplyComplexNumber(complex);
        double fraction = (c.realNumber * c.realNumber) + (c.imaginaryNumber * c.imaginaryNumber);
        complex.realNumber /= fraction;
        complex.imaginaryNumber /= fraction;
        return complex;
    }
};