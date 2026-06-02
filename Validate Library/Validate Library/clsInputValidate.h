#pragma once
#include <iostream>
#include "clsDate.h";
using namespace std;

class clsInputValidate
{

public :
	static bool IsNumberBetween(int Number ,int From, int To) {

		return (Number >= From && Number <= To);

	}
	
	static bool IsNumberBetween(double Number, double From, double To) {

		if ((Number >= From && Number <= To)) {
			return true;
		}
		return false;
	}

	static bool IsNumberBetween(short Number, short From, short To) {

		return (Number >= From && Number <= To);

	}

	static bool IsNumberBetween(float Number, float From, float To) {

		return (Number >= From && Number <= To);

	}

	static bool IsDateBetween(clsDate Date, clsDate DateFrom, clsDate DateTo) {

		return (clsDate::IsDate1AfterDate2(Date, DateFrom) || clsDate::IsDate1EqualDate2(Date, DateFrom)) &&
			(clsDate::IsDate1BeforDate2(Date, DateTo) || clsDate::IsDate1EqualDate2(Date, DateFrom)) ? true :

			(clsDate::IsDate1AfterDate2(Date, DateTo) || clsDate::IsDate1EqualDate2(Date, DateFrom)) &&
			(clsDate::IsDate1BeforDate2(Date, DateFrom) || clsDate::IsDate1EqualDate2(Date, DateFrom)) ? true : false;

	}

	static int ReadIntNumber(string Massge = "Number is Not Valid ,Enter Agin") {
		int Number = 0;

		while ((!(cin >> Number))) {

			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << Massge << endl;
		}
		return Number;

	}

	static int ReadIntNumberBetween(int From, int To,string Massge = "Number is not with in range , try agin") {
		int Number = ReadIntNumber();
		while (!IsNumberBetween(Number, From, To)) {
			cout << Massge << endl;
			Number = ReadIntNumber();
		}

		return Number;

	}

	static double ReadDoubleNumber(string Massge= "Number is Not Valid ,Enter Agin") {
		double Number = 0;

		while ((!(cin >> Number))) {

			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << Massge << endl;
		}
		return Number;

	}

	static double ReadDoubleNumberBetween(double From, double To, string Massge = "Number is not with in range , try agin") {
		
		double Number = ReadDoubleNumber();
		while (!IsNumberBetween(Number, From, To)) {
			cout << Massge << endl;
			Number = ReadDoubleNumber();
		}

		return Number;
	}

	static bool IsVaildeDate(clsDate Date) {
		return clsDate::ValidateDate(Date);
	}





};

