#include <iostream>
#include "clsUtil.h";
#include "clsDate.h"
using namespace std;

int main()
{
    clsUtil::Srand();

    cout << clsUtil::RandomNum(1, 10) << endl;
    cout << clsUtil::GetRandomChar(clsUtil::Capital) << endl;
    cout << clsUtil::GetRandomWord(clsUtil::Mix, 8) << endl;
    cout << clsUtil::GenratingKeys(clsUtil::Mix) << endl;
    clsUtil::PrintGenrateKeys(10, clsUtil::Mix);

    cout << "\n";
    int x = 20, y = 10;
    clsUtil::swap(x, y);
    cout << x << endl;
    cout << y << endl;

    double a = 20.232, b = 10.484;
    clsUtil::swap(a, b);
    cout << a << endl;
    cout << b << endl;

    string Name1 = "Mustafa", Name2 = "Ali";
    clsUtil::swap(Name1, Name2);
    cout << Name1 << endl;
    cout << Name2 << endl;

    clsDate d1(2022, 12, 10), d2;
    clsUtil::swap(d1, d2);
    d1.Print();
    d2.Print();

    int arr[5];
    int lenght = 5;
    clsUtil::FillArrayWithRandomNumber(arr, lenght, 30, 50);
    cout << "array after fill :\n";
    for (int i = 0; i < lenght; i++) {
        cout << arr[i] << endl;
    }

    string arrstring[5] ;
    clsUtil::FillArrayWithRandomWord(arrstring, lenght,clsUtil::Capital,8);
    cout << "array after fill :\n";
    for (int i = 0; i < lenght; i++) {
        cout << arrstring[i] << endl;
    }


    int arrsh[5] = {1,2,3,4,5};
    clsUtil::shuffleArray(arrsh,lenght);
    for (int i = 0; i < lenght; i++) {
        cout << arrsh[i] << endl;
    }

    string arrstringsh[5] = { "Mustafa","Ali","Mohammad","Salih","Omar" };
    clsUtil::shuffleArray(arrstringsh, lenght);
    for (int i = 0; i < lenght; i++) {
        cout << arrstringsh[i] << endl;
    }

    cout << "hi 5" << clsUtil::Tabs(5) << "tabs\n";


    const short EncryotionKey = 2;
    string Text = "Mohammed";
    string AfterEncrytion = clsUtil::EncryptText(Text, EncryotionKey);
    string AfterDecrytion = clsUtil::DecryptText(AfterEncrytion, EncryotionKey);


    cout << "Text Befor Encrytion : " << Text << endl;
    cout << "Text After Encrytion : " << AfterEncrytion << endl;
    cout << "Text After Decrytion : " << AfterDecrytion << endl;

    system("pause>0");
    return 0;
}