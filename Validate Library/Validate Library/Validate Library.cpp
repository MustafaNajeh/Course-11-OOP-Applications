#include "clsDate.h";
#include "clsInputValidate.h";
#include <iostream>
using namespace std;

int main()
{

    cout << clsInputValidate::IsNumberBetween(5, 1, 10) <<endl;
    cout << clsInputValidate::IsNumberBetween(5.8, 1.6, 10.2) << endl;
 
    cout << clsInputValidate::IsDateBetween(clsDate(),
                                             clsDate(2026, 5, 30),
                                              clsDate(2026, 6, 1)) << endl;

    cout << clsInputValidate::IsDateBetween(clsDate(),
                                            clsDate(2026, 6, 1),
                                            clsDate(2026,5, 30)) << endl;
    
    cout << "Please enter a Number:\n";
    int x = clsInputValidate::ReadIntNumber("Number is Not Valid ,Enter Agin");
    cout << "x = " << x << endl;

    cout << "please enter Number between 1 and 5 :\n";
    int y = clsInputValidate::ReadIntNumberBetween(1, 5, "Number is not with in range , try agin");
    cout << "y = " << y << endl;


    cout << "Please enter a Number:\n";
    double a = clsInputValidate::ReadDoubleNumber("Number is Not Valid ,Enter Agin");
    cout << "a = " << a << endl;

    cout << "please enter Number between 1 and 5 :\n";
    double b = clsInputValidate::ReadDoubleNumberBetween(1.9, 5.1, "Number is not with in range , try agin");
    cout << "b = " << b << endl;

    cout << clsInputValidate::IsVaildeDate(clsDate(2022, 1, 33))<<endl;




    system("pause>0");
    return 0;
}