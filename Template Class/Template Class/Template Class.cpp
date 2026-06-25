#include <iostream>
using namespace std;

template <class T>
class Calculator {
private:
    
    T N1, N2;
public:
    Calculator(T n1,T n2) {
        N1 = n1;
        N2 = n2;
    }

    T Add() {
        return N1 + N2;
    }

    T SubStract() {
        return N1 - N2;
    }

    T Multiply() {
        return N1 * N2;
    }

    T Divaid() {
        return N1 / N2;
    }

    void PrintResults() {
        cout << "Numbers: " << N1 << " and " << N2 << "." << endl;
        cout << N1 << " + " << N2 << " = " << Add() << endl;
        cout << N1 << " - " << N2 << " = " << SubStract() << endl;
        cout << N1 << " * " << N2 << " = " << Multiply() << endl;
        cout << N1 << " / " << N2 << " = " << Divaid() << endl;
    }

};

int main()
{
    Calculator <int> IntCalc(1, 2);
    Calculator <float> FloatCalc(5.2, 2.5);

    cout << "Float" << endl;
    FloatCalc.PrintResults();

    cout << "Int" << endl;
    IntCalc.PrintResults();


    
}
