/* Отсутствует проверка даты месяца и года на корректность
 * дата не должна быть 59 или 99 или 199 и тд. Тоже самое
 * и с месяцем
 */                        

#include <iostream>
#define THISMONTH 4
#define THISYEAR 2022
#define NUMBEROBJINARR 5

class Date
{
private:
	int day = 0, month = 0, year = 0;
public:
	Date(char strDate[])
	{
		
		char c;
		int i = 0, dotcx = 0;
		for(c = 0; (c = strDate[i]) != '\0'; i++)
		{	
			if(c == '.') dotcx++;
			else
			{
				switch(dotcx)
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

	int getMonth()
	{
		return month;
	}
};


void isItSpring(Date dateArr[]);

int main()
{
	char dateBuffer[] = "10.6.2021";
	Date* dateArr = (Date*)malloc(sizeof(Date) * NUMBEROBJINARR);
	dateArr[0] = Date();
	dateArr[1] = Date(2);
	dateArr[2] = Date(29,4,2007);
	dateArr[3] = Date(14,5,2003);
	dateArr[4] = Date(dateBuffer);

	isItSpring(dateArr);

	return 0;
}

void isItSpring(Date dateArr[])
{
	for(int i = 0; i < NUMBEROBJINARR; i++)
	{
		int month = dateArr[i].getMonth();
		if(month >= 3 && month <= 5)
		{	
			printf("It is Spring --> ");
			dateArr[i].printDate();
		}
		else
			dateArr[i].printDate();
	}
}
