#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "clsString.h"
#include <fstream>
using namespace std;

class clsCurrency
{
private:

	enum enMode {
		EmpytMode = 1, UpdateMode = 2
	};
	enMode _Mode;

	string _Country;
	string _CurrencyCode;
	string _CurrencyName;
	float _Rate;
	
	static clsCurrency _GetEmptyCurrencyObject(){
		return clsCurrency(enMode::EmpytMode, "", "", "", 0);
	}

	static string _ConvertCurrencyRecordToLine(clsCurrency Currency, string delim = "//##//") {

		string sRecord;

		sRecord += Currency.Country() + delim;
		sRecord += Currency.CurrencyCode() + delim;
		sRecord += Currency.CurrencyName() + delim;
		sRecord += to_string(Currency.Rate());

		return sRecord;

	}

	static clsCurrency _ConvertCurrencyLineToRecordObject(string Line, string Seperator = "//##//") {

		vector <string> vCurrency;
		vCurrency = clsString::Split(Line, Seperator);

		return clsCurrency(enMode::UpdateMode, vCurrency[0],vCurrency[1],vCurrency[2], stof(vCurrency[3]));
	}

	static vector <clsCurrency> _LoadFileContentCurrencyToVector() {
		vector <clsCurrency> vCurrency;
		fstream MyFile;

		MyFile.open("Currencies.txt", ios::in);

		if (MyFile.is_open()) {

			string Line;

			while (getline(MyFile, Line)) {


				clsCurrency Currency = _ConvertCurrencyLineToRecordObject(Line);

				vCurrency.push_back(Currency);

			}

			MyFile.close();
		}
		return vCurrency;
	}

	static vector <clsCurrency> _SaveDataCurrencyToFile(vector<clsCurrency>& vCurrency) {

		fstream MyFile;

		MyFile.open("Currencies.txt", ios::out);
		string Line;
		if (MyFile.is_open()) {



			for (clsCurrency& C : vCurrency) {
					Line = _ConvertCurrencyRecordToLine(C);
					MyFile << Line << endl;
			}

			MyFile.close();
		}
		return vCurrency;
	}

	void _Update() {
		vector <clsCurrency> _vUser;
		_vUser = _LoadFileContentCurrencyToVector();

		for (clsCurrency& C : _vUser) {
			if (C.Country() == Country()) {

				C = *this;
				break;
			}
		}

		_SaveDataCurrencyToFile(_vUser);


	}

public :
	clsCurrency(enMode Mode,string Country, string CurrencyCode, string CurrencyName, float Rate) {

		_Mode = Mode;
		_Country = Country;
		_CurrencyCode = CurrencyCode;
		_CurrencyName = CurrencyName;
		_Rate = Rate;

	}

	bool IsEmpty() {
		return (_Mode == enMode::EmpytMode);
	}

	string Country() {
		return _Country;
	}

	string CurrencyCode() {
		return _CurrencyCode;
	}

	string CurrencyName() {
		return _CurrencyName;
	}

	 void UpdateRate(float Rate) {
		_Rate = Rate;
		_Update();
	}

	float Rate() {
		return _Rate;
	}

	static clsCurrency FindCountry(string Country) {

		Country = clsString::UpperAllLetters(Country);

		fstream MyFile;

		MyFile.open("Currencies.txt", ios::in);

		if (MyFile.is_open()) {

			string Line;

			while (getline(MyFile, Line)) {

				clsCurrency Currency = _ConvertCurrencyLineToRecordObject(Line);
				if (clsString::UpperAllLetters(Currency.Country()) == Country) {
					MyFile.close();
					return Currency;
				}


			}


		}
		return _GetEmptyCurrencyObject();
	}

	static clsCurrency FindCurrencyCode(string CurrencyCode) {

		CurrencyCode = clsString::UpperAllLetters(CurrencyCode);

		fstream MyFile;

		MyFile.open("Currencies.txt", ios::in);

		if (MyFile.is_open()) {

			string Line;

			while (getline(MyFile, Line)) {

				clsCurrency Currency = _ConvertCurrencyLineToRecordObject(Line);
				if (Currency.CurrencyCode() == CurrencyCode) {
					MyFile.close();
					return Currency;
				}


			}


		}
		return _GetEmptyCurrencyObject();
	}

	static bool IsCurrencyExistByCurrencyCode(string CurrencyCode) {

		clsCurrency Client = clsCurrency::FindCurrencyCode(CurrencyCode);
		return (!Client.IsEmpty());

	}

	static bool IsCurrencyExistByCountry(string Country) {

		clsCurrency Client = clsCurrency::FindCountry(Country);
		return (!Client.IsEmpty());

	}

	static vector<clsCurrency> GetListCurrency() {
		return _LoadFileContentCurrencyToVector();
	}

	float ConvertToUSD(float Amount) {
		return float(Amount / Rate());
	}

	float ConvertToAnoutherCurrency(float Amount, clsCurrency Currency2) {

		float FirstConvert = ConvertToUSD(Amount);
		if (Currency2.CurrencyCode() == "USD") {
			return FirstConvert;
		}

		return float (FirstConvert * Currency2.Rate());

	}





};

