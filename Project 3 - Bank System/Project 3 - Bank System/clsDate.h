#pragma once
#pragma warning(disable : 4996)
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class clsDate
{
private :


		short _Year;
		short _Month;
		short _Day;
public:

	clsDate() {

		time_t t = time(0);
		tm* now = localtime(&t);

		_Year = now->tm_year + 1900;
		_Month = now->tm_mon + 1;
		_Day = now->tm_mday;

	}

	clsDate(short Year,short Month,short Day) {

		_Year = Year;
		_Month = Month;
		_Day = Day;
	}

	clsDate(short DaysOfYear,short Year) {

		_Year = Year;
		ConvertTotalDaysToDate(Year, DaysOfYear);


	}

	clsDate(string date) {

		ConvertDateStringToStrictur(date);


	}

	void setDay(short Day) {
		_Day = Day;
	}

	short getDay() {
		return _Day;
	}

	__declspec(property(get = getDay, put = setDay)) short Day;

	void setMonth(short Month) {
		_Month = Month;
	}

	short getMonth() {
		return _Month;
	}

	__declspec(property(get = getMonth, put = setMonth)) short Month;

	void setYear(short Year) {
		_Year = Year;
	}

	short getYear() {
		return _Year;
	}

	__declspec(property(get = getYear, put = setYear)) short Year;

	static clsDate GetSystemDate() {

		time_t t = time(0);
		tm* now = localtime(&t);
		short Year, Month, Day;
		Year = now->tm_year + 1900;
		Month = now->tm_mon + 1;
		Day = now->tm_mday;
		return clsDate(Year, Month, Day);

	}

	void Print() {

		 cout <<DateToString()<<endl;

	}

	string NumbersToText(int num) {

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

	static bool IsLeapYear(short _Year) {

		return (_Year % 4 == 0 && _Year % 100 != 0) || (_Year % 400 == 0);

	}

	bool IsLeapYear() {
		return IsLeapYear(_Year);
	}

	static short NumberOfDaysInMonth(short _Year, short _Month) {

		if (_Month < 1 || _Month > 12) {
			return 0;
		}
		short MonthOfDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
		return _Month == 2 ? (IsLeapYear(_Year) ? 29 : 28) : MonthOfDays[_Month - 1];



	}

	short NumberOfDaysInMonth() {
		return NumberOfDaysInMonth(_Year, _Month);
	}

	static short OrderDay(short _Year, short _Month, short _Day) {

		short a = ((14 - _Month) / 12);
		short y = _Year - a;
		short m = _Month + 12 * a - 2;
		return (_Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;

	}

	short OrderDay() {
		return OrderDay(_Year, _Month, _Day);
	}

	static string DayNameOfTheWeek(short OrderDay) {

		string arrDayName[] = { "Sun","Mon","Tue","Win","Thu","Fri","Sat" };
		return arrDayName[OrderDay];

	}

	string DayNameOfTheWeek()
	{
		return  DayNameOfTheWeek(this->OrderDay());
	}

	static string NameMonthInTheYear(short NumberOfMonth) {

		string arrStringMonth[12] = {
			"Jan","Feb","Mar","Apr"
			,"May","Jun","Jul","Aug"
			,"Sep","Oct","Nov","Dec" };

		return(arrStringMonth[NumberOfMonth - 1]);
	}

	static void PrintMonthCalender(short _Year, short _Month) {

		int NumberOfDays;

		int CurrentDay = OrderDay(_Year, _Month, 1);

		NumberOfDays = NumberOfDaysInMonth(_Year, _Month);

		printf("\n  __________________%s______________\n\n",
			NameMonthInTheYear(_Month).c_str());

		printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");
		int i;
		for (i = 0; i < CurrentDay; i++) {
			printf("     ");
		}

		for (int j = 1; j <= NumberOfDays; j++) {

			printf("%5d", j);
			if (++i == 7) {
				i = 0;
				printf("\n");
			}

		}

		printf("\n  _____________________________________\n");
	}

	void PrintMonthCalender() {
		 PrintMonthCalender( _Year, _Month);
	}

	static void PrintYearCalendar(short _Year) {
		printf("\n  _____________________________________\n\n");
		cout << "\t     Calendar - " << _Year;
		printf("\n\n  _____________________________________\n");
		for (int i = 1; i <= 12; i++) {


			PrintMonthCalender(_Year, i);

		}
	}

	void PrintYearCalendar() {
		PrintYearCalendar(_Year);
	}

	static short TotalDaysFromBeginningYear(short _Year, short _Month, short Days) {
		short TotalDays = 0;

		for (int i = 1; i <= _Month - 1; i++) {

			TotalDays += NumberOfDaysInMonth(_Year, i);

		}
		TotalDays += Days;
		return TotalDays;
	}

	short TotalDaysFromBeginningYear() {
		return TotalDaysFromBeginningYear(_Year,  _Month,_Day);
	}

	void ConvertTotalDaysToDate(short _Year, short TotalDays) {

		
		short RminingDays = TotalDays;
		short MonthDays;

		_Year = _Year;
		_Month = 1;

		while (true) {

			MonthDays = NumberOfDaysInMonth(_Year, _Month);

			if (RminingDays > MonthDays) {

				RminingDays -= MonthDays;
				_Month++;

			}
			else {

				_Day = RminingDays;
				break;


			}

		}
		
	}

	void ConvertTotalDaysToDate(short TotalDays) {

		ConvertTotalDaysToDate(_Year, TotalDays);

	}

	static clsDate AddingDaysIntoTheDate(int DaysToAdd, clsDate& Date) {

		short RminingDays = DaysToAdd + TotalDaysFromBeginningYear(Date._Year, Date._Month, Date._Day);
		short MonthDays;

		Date._Month = 1;

		while (true) {

			MonthDays = NumberOfDaysInMonth(Date._Year, Date._Month);

			if (RminingDays >= MonthDays) {
				RminingDays -= MonthDays;
				Date._Month++;
				if (Date._Month > 12) {
					Date._Year++;
					Date._Month = 1;
				}
			}
			else {

				Date._Day = RminingDays;

				break;
			}


		}
		return Date;
	}

	void AddingDaysIntoTheDate(int DaysToAdd) {
		 AddingDaysIntoTheDate(DaysToAdd, *this);
	}

	static bool ValidateDate(clsDate Date)
	{
		/*return (Date.Month <= 12 && Date.Month >= 1) && (Date.Day <= NumberOfDaysInMonth(Date.Year, Date.Month) && Date.Day >= 1);*/
		//my sultion.

		if (Date._Day < 1 || Date._Day >31)
			return false;

		if (Date._Month < 1 || Date._Month > 12)
			return false;

		if (Date._Month == 2) {

			if (IsLeapYear(Date._Year))
			{

				if (Date._Day > 29)
					return false;

			}
			else {
				if (Date._Day > 28)
					return false;
			}


		}

		short DaysInMonth = NumberOfDaysInMonth(Date._Year, Date._Month);
		if (Date._Day > DaysInMonth)
			return false;

		return true;
	}

	bool ValidateDate() {
		return ValidateDate(*this);
	}

	void ConvertDateStringToStrictur(string DateString) {

		
		vector <string> vDate;
		vDate = SplitEachWordInVector(DateString, "/");

		_Day = stoi(vDate[0]);
		_Month = stoi(vDate[1]);
		_Year = stoi(vDate[2]);

		
	}

	static string DateToString(clsDate Date) {

		string Day = to_string(Date._Day);
		string Month = to_string(Date._Month);
		string Year = to_string(Date._Year);


		return Day + "/" + Month + "/" + Year;

	}

	string DateToString() {
		return DateToString(*this);
	}

	static bool IsDate1BeforDate2(clsDate Date1, clsDate Date2) {

		return Date1._Year < Date2._Year ? true : Date1._Year == Date2._Year ?
			(Date1._Month < Date2._Month) ? true : ((Date1._Month == Date2._Month) ? (Date1._Day < Date2._Day) : false) : false;

	}

	bool IsDate1BeforDate2(clsDate Date2) {
		return IsDate1BeforDate2(*this, Date2);
	}

	static bool IsDate1EqualDate2(clsDate Date1, clsDate Date2) {

		return Date1._Year == Date2._Year ? (Date1._Month == Date2._Month ? (Date1._Day == Date2._Day ? true : false) : false) : false;

	}

	 bool IsDate1EqualDate2(clsDate Date2) {
		return IsDate1EqualDate2(*this, Date2);
	}

	 static bool IsLastDayInAMonth(clsDate Date) {

		return Date._Day == NumberOfDaysInMonth(Date._Year, Date._Month);

	}

	 bool IsLastDayInAMonth() {
		 return  IsLastDayInAMonth(*this);
	 }

	 static bool IsLastMonthInAYear(short _Month) {

		return _Month == 12;

	 }

	 bool IsLastMonthInAYear() {
		 return  IsLastMonthInAYear(_Month);
	 }


	static clsDate IncreaseDateOneDay(clsDate Date) {
		if (IsLastDayInAMonth(Date))
		{
			if (IsLastMonthInAYear(Date._Month))
			{
				Date._Year++;
				Date._Month = 1;
				Date._Day = 1;
			}

			else {
				Date._Month++;
				Date._Day = 1;
			}
		}

		else {
			Date._Day++;
		}
		return Date;
	}
	  
	void IncreaseDateOneDay() {

		*this = IncreaseDateOneDay(*this);

	}

	static void SwapDates(clsDate& Date1, clsDate& Date2) {

		clsDate Temp;

		Temp = Date1;
		Date1 = Date2;
		Date2 = Temp;


	}

	static short CalculateDiffBetwenDate1AndDate2(clsDate Date1, clsDate Date2, bool including = false) {


		int _Day = 0;
		int FalgValue = 1;
		if (!IsDate1BeforDate2(Date1, Date2)) {

			SwapDates(Date1, Date2);
			FalgValue = -1;

		}

		while (IsDate1BeforDate2(Date1, Date2)) {

			_Day++;

			Date1 = IncreaseDateOneDay(Date1);
		}

		return including ? FalgValue * (++_Day) : FalgValue * _Day;

	}

	short CalculateDiffBetwenDate1AndDate2(clsDate Date2, bool including = false) {
		return CalculateDiffBetwenDate1AndDate2(*this, Date2, including = false);
	}

	static short DaysUntilTheEndOfYear(clsDate Date) {

		//short DaysOfYear = IsLeapYear(Date.Year) ? 366 : 365;

		//return DaysOfYear - TotalDaysFromBeginningYear(Date.Year, Date.Month, Date.Day);
		clsDate EndOfYear;
		EndOfYear._Day = 31;
		EndOfYear._Month = 12;
		EndOfYear._Year = Date._Year;

		return CalculateDiffBetwenDate1AndDate2(Date, EndOfYear, true);

	}

	short DaysUntilTheEndOfYear() {
		return DaysUntilTheEndOfYear(*this);
	}

	static short DaysUntilTheEndOfMonth(clsDate Date) {
		//return NumberOfDaysInMonth(Date.Year, Date.Month) - Date.Day;

		clsDate EndOfMonth;
		EndOfMonth._Day = NumberOfDaysInMonth(Date._Year, Date._Month);
		EndOfMonth._Month = Date._Month;
		EndOfMonth._Year = Date._Year;

		return CalculateDiffBetwenDate1AndDate2(Date, EndOfMonth, true);
	}

	short DaysUntilTheEndOfMonth() {
		return  DaysUntilTheEndOfMonth(*this);
	}

	static short DaysUntilTheEndOfWeek(short OrderDay) {

		return 6 - OrderDay;

	}

	static bool IsWeekEnd(short OrderDay) {

		return OrderDay == 5 || OrderDay == 6;

	}

	static vector <string> SplitEachWordInVector(string S, string delim) {


		short pos = 0;
		string Word;
		vector <string> vWord;


		while ((pos = S.find(delim)) != std::string::npos) {

			Word = S.substr(0, pos);
			if (Word != "")
			{
				vWord.push_back(Word);

			}

			S.erase(0, pos + delim.length());

		}
		if (S != "")
		{
			vWord.push_back(S);
		}
		return vWord;

	}

	static bool IsBusinessDay(short OrderDay) {

		return !IsWeekEnd(OrderDay);

	}

	static short OrderDay(clsDate Date) {

		return OrderDay(Date._Year, Date._Month, Date._Day);

	}

	static short ReadVactionPeriod(clsDate Datefrom, clsDate DateTo) {

		int Day = 0;
		while (IsDate1BeforDate2(Datefrom, DateTo)) {
			if (IsBusinessDay(OrderDay(Datefrom)))
				Day++;

			Datefrom = IncreaseDateOneDay(Datefrom);
		}
		return Day;
	}

	short ReadVactionPeriod(clsDate DateTo) {
		return ReadVactionPeriod(*this, DateTo);
	}

	static clsDate ReadVactionPeriodAndRturnDate(clsDate Date, short ReturnDate) {

		short DayWeekEnd = 0;

		while (IsWeekEnd(OrderDay(Date))) {


			Date = IncreaseDateOneDay(Date);

		}


		for (int i = 1; i <= ReturnDate + DayWeekEnd; i++) {

			if (IsWeekEnd(OrderDay(Date))) {
				DayWeekEnd++;
			}


			Date = IncreaseDateOneDay(Date);


		}

		while (IsWeekEnd(OrderDay(Date))) {


			Date = IncreaseDateOneDay(Date);

		}
		return Date;
	}

	void ReadVactionPeriodAndRturnDate(short ReturnDate) {
		*this = ReadVactionPeriodAndRturnDate(*this, ReturnDate);
	}

	static bool IsDate1AfterDate2(clsDate Date1, clsDate Date2) {

		return (!IsDate1BeforDate2(Date1, Date2)) && (!IsDate1EqualDate2(Date1, Date2));

	}

	bool IsDate1AfterDate2(clsDate Date2) {
		return IsDate1AfterDate2(*this, Date2);
	}

	enum enCompareDates { After = 1, befor = -1, equal = 0 };

	static enCompareDates CompareDates(clsDate Date1, clsDate Date2) {

		if (IsDate1AfterDate2(Date1, Date2))
			return enCompareDates::After;

		if (IsDate1BeforDate2(Date1, Date2))
			return enCompareDates::befor;

		return enCompareDates::equal;
	}

	enCompareDates CompareDates(clsDate Date2) {
		return CompareDates(*this, Date2);
	}


	static string GetSystemDateTime() {
		time_t t = time(0);

		tm* now = localtime(&t);
		short Day, Month, Year, Hour, Mint, Sec;
		Year = now->tm_year + 1900l;
		Month =	now->tm_mon + 1;
		Day = now->tm_mday;
		Hour = now->tm_hour;
		Mint = now->tm_min;
		Sec =now->tm_sec;
		
		return to_string(Year) + "/" + to_string(Month) + "/" + to_string(Day) + " - "
			+ to_string(Hour) + ":" + to_string(Mint) + ":" + to_string(Sec);

	}


};