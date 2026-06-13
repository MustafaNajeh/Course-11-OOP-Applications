#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class clsString
{

private:
	string _Value;
public:
	clsString() {
		_Value = "";
	}

	clsString(string Value) {
		_Value = Value;
	}

	void setValue(string value) {
		_Value = value;
	}

	string getValue() {
		return _Value;
	}

	__declspec(property(get = getValue, put = setValue))string Value;

	static short PrintEachWordInString(string S) {

		string delim = " ";
		short pos = 0;
		short counter = 0;
		string word;



		while ((pos = S.find(delim)) != std::string::npos) {

			word = S.substr(0, pos);
			if (word != "")
			{
				counter++;
			}

			S.erase(0, pos + delim.length());

		}
		if (S != "")
		{
			counter++;
		}

		return counter;
	}

	 short PrintEachWordInString() {
		return PrintEachWordInString(_Value);
	 }

	static void PrintFirstLetter(string S) {

		 bool IsFirst = true;

		 for (int i = 0; i <= S.length(); i++) {

			 if (S[i] != ' ' && IsFirst)
			 {
				 cout << S[i] << endl;
			 }


			 IsFirst = (S[i] == ' ' ? true : false);

		 }

	 }

	 void PrintFirstLetter() {
		return PrintFirstLetter(_Value);
	 }

	static string UpperFirstLetter(string S) {

		 bool IsFirst = true;

		 for (int i = 0; i <= S.length(); i++) {

			 if (S[i] != ' ' && IsFirst)
			 {
				 S[i] = toupper(S[i]);

			 }



			 IsFirst = (S[i] == ' ' ? true : false);

		 }
		 return S;
	 }

	void UpperFirstLetter() {
		_Value = UpperFirstLetter(_Value);
	}

	static string LowerFirstLetter(string S) {

		 bool IsFirst = true;

		 for (int i = 0; i <= S.length(); i++) {

			 if (S[i] != ' ' && IsFirst)
			 {
				 S[i] = tolower(S[i]);

			 }



			 IsFirst = (S[i] == ' ' ? true : false);

		 }
		 return S;
	 }

	void LowerFirstLetter() {
		_Value = LowerFirstLetter(_Value);
	}

	static string UpperAllLetters(string S) {

		 for (int i = 0; i <= S.length(); i++) {

			 S[i] = toupper(S[i]);

		 }
		 return S;
	 }
	
	void UpperAllLetters() {
		_Value = UpperAllLetters(_Value);
	}

	static string LowerAllLetters(string S) {


		 for (int i = 0; i <= S.length(); i++) {


			 S[i] = tolower(S[i]);

		 }
		 return S;
	 }
	
	void LowerAllLetters() {
		_Value = LowerAllLetters(_Value);
	}

	static char InvertChar(char S) {

		 return isupper(S) ? (tolower(S)) : toupper(S);

	 }

	static string InvertString(string S) {

		 for (int i = 0; i <= S.length(); i++)
		 {

			 S[i] = InvertChar(S[i]);

		 }
		 return S;
	 }

	void InvertString() {
		_Value = InvertString(_Value);
	}

	static char ReadChar() {
		 char Text = ' ';

		 cout << "please enter your char?" << endl;
		 cin >> Text;
		 return Text;
	 }

	static string ReadString() {
		 string Text = "";

		 cout << "please enter your string ?" << endl;
		 getline(cin, Text);
		 return Text;
	 }

	static short CountCharYouWant(string S, char C) {
		 int counter = 0;
		 for (int i = 0; i < S.length(); i++)
		 {
			 if (S[i] == C)
			 {
				 counter++;
			 }

		 }
		 return counter;
	 }

	short CountCharYouWant(char C) {
		return CountCharYouWant(_Value,C);
	}

	static int CountCapital(string S) {
		 int counter = 0;
		 for (int i = 0; i < S.length(); i++)
		 {

			 if (isupper(S[i])) {

				 counter++;


			 }

		 }
		 return counter;
	 }

	int CountCapital() {
		return CountCapital(_Value);
	}

	static int CountSmall(string S) {
		 int counter = 0;
		 for (int i = 0; i < S.length(); i++)
		 {

			 if (islower(S[i])) {

				 counter++;


			 }

		 }
		 return counter;
	 }

	int CountSmall() {
		return CountSmall(_Value);
	}

	static short CountChar(string S, char C, bool MachCase = true) {
		 int counter = 0;
		 for (int i = 0; i < S.length(); i++)
		 {

			 if (MachCase) {
				 if (S[i] == C)
				 {
					 counter++;
				 }
			 }

			 else
			 {

				 if (tolower(S[i]) == tolower(C))
					 counter++;
			 }

		 }
		 return counter;

	 }

	short CountChar(char C, bool MachCase = true) {
		return CountChar(_Value,C);
	}

	static bool CheakIfVowel(char C) {

		 C = tolower(C);
		 return ((C == 'a') || (C == 'o') || (C == 'e') || (C == 'i') || (C == 'u'));

	 }

	static short CountOfVowels(string S) {

		 int counter = 0;
		 for (int i = 0; i < S.length(); i++) {

			 if (CheakIfVowel(S[i]))
				 counter++;
		 }
		 return counter;
	 }

	short CountOfVowels() {
		return CountOfVowels(_Value);
	}

	static void PrintAllVowels(string S) {

		 cout << "All vowels are : " << endl;
		 for (int i = 0; i < S.length(); i++) {

			 if (CheakIfVowel(S[i]))
				 cout << S[i] << "   ";
		 }

	 }

	void PrintAllVowels() {
		 PrintAllVowels(_Value);
	}

	static void PrintEachWordInLine(string S) {

		 string delim = " ";
		 short pos = 0;
		 string word;

		 while ((pos = S.find(delim)) != std::string::npos) {

			 word = S.substr(0, pos);
			 if (word != "")
			 {
				 cout << word << endl;
			 }

			 S.erase(0, pos + delim.length());

		 }
		 if (S != "")
			 cout << S << endl;
	 }
	
	void PrintEachWordInLine() {
		 PrintEachWordInLine(_Value);
	}

	static vector <string> Split(string S, string delim) {


		 short pos = 0;
		 string Word;
		 vector <string> vWord;


		 while ((pos = S.find(delim)) != std::string::npos) {

			 Word = S.substr(0, pos);
			 
			 
				 vWord.push_back(Word);

			 

			 S.erase(0, pos + delim.length());

		 }
		 if (S != "")
		 {
			 vWord.push_back(S);
		 }
		 return vWord;

	 }

	vector <string> Split(string delim) {
		return Split(_Value,delim);
	}

	static string TrimLeft(string S) {




		 for (int i = 0; i < S.length(); i++) {

			 if (S[i] != ' ') {

				 return S.substr(i, S.length() - i);

			 }

		 }
		 return "";
	 }

	 void TrimLeft() {
		 _Value = TrimLeft(_Value);
	}

	static string TrimRight(string S) {

		 for (int i = S.length() - 1; i >= 0; i--) {

			 if (S[i] != ' ') {

				 return S.substr(0, i + 1);

			 }

		 }
		 return "";
	 }

	void TrimRight() {
		_Value = TrimRight(_Value);
	}

	static string Trim(string S) {

		 return TrimLeft(TrimRight(S));

	 }
	
	void Trim() {
		_Value = Trim(_Value);
	}

	static string JoinVector(vector <string> vS, string delim) {

		 string S1 = "";

		 for (string& S : vS) {

			 S1 += S + delim;
			 // mohammed,   
		 }

		 return S1.substr(0, S1.length() - delim.length());


	 }

	static string JoinVector(string arr[], int arrlength, string delim) {

		 string S1 = "";
		 for (int i = 0; i < arrlength; i++) {

			 S1 += arr[i] + delim;

		 }
		 return S1.substr(0, S1.length() - delim.length());


	 }

	static string ReversString(string S) {

		 string S2 = "";

		 vector <string> vString;

		 vString = Split(S, " ");

		 vector <string>::iterator itr = vString.end();

		 while (itr != vString.begin())
		 {


			 itr--;
			 S2 += *itr + " ";



		 }

		 return S2.substr(0, S2.length() - 1);

	 }

	void ReversString() {
		_Value = ReversString(_Value);
	}

	static string ReplaceWordsInString(string S, string STR, string SRT) {
		 short pos = S.find(STR);

		 while (pos != std::string::npos) {

			 S = S.replace(pos, STR.length(), SRT);

			 pos = S.find(STR);
		 }

		 return S;

	 }

	static string ReplaceWordsInString(string S, string StringToReplace, string StringReplaceTo, bool MachCase = true) {

		 vector <string> vString = Split(S, " ");

		 for (string& s : vString) {

			 if (MachCase) {

				 if (s == StringToReplace) {

					 s = StringReplaceTo;

				 }

			 }
			 else if (LowerAllLetters(s) == LowerAllLetters(StringToReplace)) {

				 s = StringReplaceTo;

			 }

		 }
		 return JoinVector(vString, " ");
	 }

	string ReplaceWordsInString(string StringToReplace, string StringReplaceTo, bool MachCase = true) {

		return ReplaceWordsInString(_Value, StringToReplace, StringReplaceTo, MachCase = true);

	}

	static string RemovePunctuations(string S) {

		 string S2;

		 for (int i = 0; i < S.length(); i++)
		 {
			 if (!ispunct(S[i])) {

				 S2 += S[i];


			 }
		 }
		 return S2;
	 }

	void RemovePunctuations() {
		_Value = RemovePunctuations(_Value);
	}

};

