#pragma once
#include <iostream>
#include <cstdlib>
#include "clsDate.h"
using namespace std;

class clsUtil
{

public :

	static void Srand() {
		srand((unsigned)time(NULL));
	}

	static void PrintDigist(int Num) {

		int Riminder = 0;
		while (Num > 0) {

			Riminder = Num % 10;
			Num /= 10;
			cout << Riminder << endl;
		}

	}

	static int ReverseNumber(int Num) {
		int Num2 = 0;
		int Riminder = 0;

		while (Num > 0) {

			Riminder = Num % 10;
			Num /= 10;

			Num2 = Num2 * 10 + Riminder;

		}
		return Num2;
	}

	static int DigitFrequency(int Num, short DigitToCheck) {
		int Riminder = 0;
		int Frequency = 0;

		while (Num > 0) {

			Riminder = Num % 10;
			Num /= 10;

			cout << Riminder << endl;

			if (DigitToCheck == Riminder)
			{
				Frequency++;
			}

		}
		return Frequency;
	}

	static bool GuessPassword(string word) {

		cout << endl;

		string letter = "";
		int counter = 0;

		for (int i = 65; i <= 90; i++) {

			for (int j = 65; j <= 90; j++) {

				for (int h = 65; h <= 90; h++) {

					letter = letter + char(i);
					letter = letter + char(j);
					letter = letter + char(h);

					counter++;
					cout << "Trial [" << counter << "] :" << letter << endl;

					if (letter == word) {

						cout << "Passwoed is " << letter << endl;;
						cout << "Found After " << counter << " trials" << endl;

						return true;
					}
					letter = "";

				}

			}

		}


		return false;
	}

	static string EncryptText(string Text, short EncryotionKey) {

		for (int i = 0; i < Text.length(); i++) {

			Text[i] = char(int(Text[i])) + EncryotionKey;
		}


		return Text;
	}

	static string DecryptText(string Text, short EncryotionKey) {

		for (int i = 0; i < Text.length(); i++) {

			Text[i] = char(int(Text[i])) - EncryotionKey;
		}


		return Text;
	}

	static int RandomNum(int from, int to) {


		int randnum = rand() % (to - from + 1) + from;
		return randnum;


	}

	 enum enRandChar {
	Small=1,Capital=2,Digits=3,
	Specialchar=4,Mix=5
};

	static char GetRandomChar(enRandChar Rand) {

		if (Rand == enRandChar::Mix) {
			Rand = enRandChar(RandomNum(1, 3));
		}


	switch (Rand) {

	case enRandChar::Capital:
	{
		return char (RandomNum(65, 90));
		break;
	}
	case enRandChar::Small:
	{
		return char(RandomNum(97,122));
		break;
	}
	case enRandChar::Digits:
	{
		return char(RandomNum(48,57));
		break;
	}
	case enRandChar::Specialchar:
	{
		return char(RandomNum(32,47));
		break;
	}

	}
}

	static string GetRandomWord(enRandChar CharType, short Length) {

		string word = "";

		for (int i = 1; i <= Length; i++) {


			word += GetRandomChar(CharType);


		}

		return word;

	}

	static void FillArrayWithRandomWord(string array[100], int& length,enRandChar CharType, short Length) {


		for (int i = 0; i < length; i++) {

			array[i] = GetRandomWord( CharType,  Length);

		}
	}

	static void ReadArray(int arr[100], int& length) {

		cout << "\nEnter number of elements:\n";
		cin >> length;

		cout << "\nEnter array elements: \n";

		for (int i = 0; i < length; i++)
		{
			cout << "Element [" << i + 1 << "] : ";
			cin >> arr[i];
		}
		cout << endl;
	}

	static 	void PrintArray(int array[100], int& length) {

		for (int i = 0; i < length; i++) {

			cout << array[i] << " ";
		}

	}

	static int CheakRepetedNum(int array[100], int& length, int NumberCheck) {

		int count = 0;
		for (int i = 0; i < length; i++) {

			if (NumberCheck == array[i]) {

				count++;

			}


		}
		return count;


	}

	static void FillArrayWithRandomNumber(int array[100], int& length,short from , short to) {

		for (int i = 0; i < length; i++) {

			array[i] = RandomNum(from, to);

		}
	}

	static int MinimumArray(int array[100], int& length) {

		int Mini = 0;
		Mini = array[0];
		for (int i = 0; i < length; i++) {

			if (array[i] < Mini) {


				Mini = array[i];


			}

		}
		return Mini;
	}

	static void CopyArray(int arrSours[100], int arrDest[100], int& length) {

		for (int i = 0; i < length; i++) {

			arrDest[i] = arrSours[i];

		}

	}

	static void swap(int& num1, int& num2)
	{
		int temp;
		temp = num1;
		num1 = num2;
		num2 = temp;
	}

	static void swap(string& string1, string& string2)
	{
		string temp;
		temp = string1;
		string1 = string2;
		string2 = temp;
	}

	static void swap(double& double1, double& double2)
	{
		double temp;
		temp = double1;
		double1 = double2;
		double2 = temp;
	}

	static void swap(clsDate& Date1, clsDate& Date2)
	{
		clsDate temp;
		temp = Date1;
		Date1 = Date2;
		Date2 = temp;
	}

	static void shuffleArray(int arrSours[100], int length) {


		for (int i = 0; i < length; i++) {

			swap(arrSours[i], arrSours[RandomNum(i, length) - 1]);

		}

	}

	static void shuffleArray(string arrSours[100], int length) {


		for (int i = 0; i < length; i++) {

			swap(arrSours[i], arrSours[RandomNum(i, length) - 1]);

		}

	}

	static void ReversCopyArray(int arrSours[100], int arrDest[100], int& length) {


		for (int i = 0; i < length; i++) {

			arrDest[i] = arrSours[i];
			arrDest[i] = arrSours[length - 1 - i];

		}

	}

	static string GenratingKeys(enRandChar Rand)
	{
		string Key = "";

		Key = GetRandomWord(Rand, 4) + "-";
		Key += GetRandomWord(Rand, 4) + "-";
		Key += GetRandomWord(Rand, 4) + "-";
		Key += GetRandomWord(Rand, 4);

		return Key;
	}

	static 	void PrintGenrateKeys(int NumberOfKeys,enRandChar Rand) {

		for (int i = 1; i <= NumberOfKeys; i++) {

			cout << "key [" << i << "] : " <<
				GenratingKeys(Rand) << endl;

		}

	}

	static void KeysWithArrays(string arr[100], int& length,enRandChar Rand) {

		for (int i = 0; i < length; i++) {

			arr[i] = GenratingKeys(Rand);

		}

	}

	static void PrintStringArray(string arr[100], int& length) {


		for (int i = 0; i < length; i++) {

			cout << "Array [" << i << "] : ";
			cout << arr[i] << "\n";
		}


	}

	static string Tabs(short Number) {

		string t = "";

		for (int i = 1; i <= Number; i++) {

			t += "\t";

		}

		return t;

	}


	static string NumbersToText(int num) {

		if (num == 0) {
			return "";
		}

		if (num >= 1 && num <= 19) {

			string arr[] = { "","Own","Tow","Three","Four","Five"
				,"Six","Seven","Eight","Nine","Ten"
				,"Eleven","Tewlv","Thirteen","Fourteen","Fifteen",
				"Sixteen","Seventeen","Eighteen","Ninteen" };

			return arr[num] + " ";
		}

		if (num >= 20 && num <= 99)
		{
			string arr[] = { "","","Tewnty","Thierty","Fourty",
				"Fifty","Sixty","Seventy","Eighty","Ninty" };

			return arr[num / 10] + " " + NumbersToText(num % 10);



		}

		if (num >= 100 && num <= 199) {
			return "own handerd " + NumbersToText(num % 100);


		}
		if (num >= 200 && num <= 999) {

			return NumbersToText(num / 100) + "hundreds " + NumbersToText(num % 100);
		}


		if (num >= 1000 && num <= 1999) {
			return "own thounsend " + NumbersToText(num % 1000);
		}


		if (num >= 2000 && num <= 999999) {
			return NumbersToText(num / 1000) + "thounsends " + NumbersToText(num % 1000);
		}

		if (num >= 1000000 && num <= 1999999) {
			return "own Million " + NumbersToText(num % 1000000);
		}
		if (num >= 2000000 && num <= 199999999) {

			return NumbersToText(num / 1000000) + "Millions " + NumbersToText(num % 1000000);

		}
		if (num >= 1000000000 && num <= 1999999999) {
			return "own Billion " + NumbersToText(num % 1000000000);
		}
		if (num >= 2000000000 && num <= 199999999999) {

			return NumbersToText(num / 1000000) + "Billions " + NumbersToText(num % 1000000);

		}
	}


};

