/* Отсутствует проверка даты месяца и года на корректность
 * дата не должна быть 59 или 99 или 199 и тд. Тоже самое
 * и с месяцем
 */

#include <iostream>
#define THISMONTH 4
#define THISYEAR 2022
#define NUMBEROBJINARR 5
#define WINTERCODE 0x1
#define SUMMERCODE 0x2
#define AUTUMNCODE 0x3
#define SPRINGCODE 0x4

int monthDate[] = { 31,28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

class Date
{
private:
	int day = 0, month = 0, year = 0;
public:
	Date(char strDate[])
	{

		char c;
		int i = 0, dotcx = 0;
		for (c = 0; (c = strDate[i]) != '\0'; i++)
		{
			if (c == '.') dotcx++;
			else
			{
				switch (dotcx)
				{
				case 0:
					day *= 10;
					day += c - '0';
					break;
				case 1:
					month *= 10;
					month += c - '0';
					break;
				case 2:
					year *= 10;
					year += c - '0';
					break;
				}
			}
		}
	}

	Date(int iDay, int iMonth, int iYear)
	{
		day = iDay;
		month = iMonth;
		year = iYear;
	}

	Date(int iDay)
	{
		day = iDay;
		month = THISMONTH;
		year = THISYEAR;
	}

	Date()
	{
		day = 1;
		month = 1;
		year = 2000;
	}

	void printDate()
	{
		printf("Day is: %d\tMonth is: %d\tYear is:%d\n", day, month, year);
	}

	int getSeason()
	{
		switch (month)
		{
		case 12:
		case 1:
		case 2:
			return WINTERCODE;
			break;

		case 6:
		case 7:
		case 8:
			return SUMMERCODE;
			break;

		case 9:
		case 10:
		case 11:
			return AUTUMNCODE;
			break;

		case 3:
		case 4:
		case 5:
			return SPRINGCODE;
			break;
		}
	}

	int getDayOfWeek()
	{
		return day % 7;
	}

	int getDecade()
	{
		if (day <= 10) return 1;
		else if (day > 10 && day < 20) return 2;
		else return 3;
	}

	bool isItLeapYear()
	{
		if (year % 4 == 0)
		{
			if (year % 100 == 0)
			{
				if (year % 400 == 0) return 1;
				else return 0;
			}
			else return 1;
		}
		else return 0;
	}

	int getNumOfDateMonth()
	{
		if (isItLeapYear())
		{
			monthDate[1] += 1;
			return monthDate[month - 1];
		}
		else return monthDate[month - 1];
	}

};


int main()
{
	char dateBuffer[] = "10.6.2021";
	Date* dateArr = (Date*)malloc(sizeof(Date) * NUMBEROBJINARR);
	dateArr[0] = Date();
	dateArr[1] = Date(2);
	dateArr[2] = Date(29, 4, 2007);
	dateArr[3] = Date(14, 5, 2003);
	dateArr[4] = Date(dateBuffer);

	for (int i = 0; i < NUMBEROBJINARR; i++)
	{
		if (dateArr[i].getSeason() == SPRINGCODE)
		{
			printf("It is Spring --> ");
			dateArr[i].printDate();
		}
		else
		{
			dateArr[i].printDate();
		}
	}


	return 0;
}
