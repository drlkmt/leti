#include <iostream>
#include <malloc.h>
#define MAXLENSTR 79

class String
{
private:
	char* pStr = NULL;
public:

	String()
	{
		pStr = (char *)malloc(sizeof(char) * MAXLENSTR);
		if(pStr == NULL) exit(1);
	}

	void Set()
	{
		char c;
		int cx = 0;
		while((c = getchar()) != '\n' && cx < (MAXLENSTR - 1))
		{
			pStr[cx] = c;
			cx++;
		}
		pStr[cx] = '\0';
	}

	void Print()
	{
		printf("%s", pStr);
	}

	char* pGetStr()
	{
		return pStr;
	}
	
	String* operator=(String obj)
	{
		pStr = obj.pGetStr();
		return this;
	}

	int getStrLen()
	{
		int cx = 0;
		while(pStr[cx] != '\0') cx++;
		return cx;
	}

	void Run()
	{
		char* pNewStr = (char*)malloc((sizeof(char) * (MAXLENSTR+1)) + 4); // +4 для добавления выделения -> <-
		int lastBracketC = 0;
		for(int i = this->getStrLen(); i >= 0; i--)
		{
			if(pStr[i] == '(')
			{
				lastBracketC = i;
				break;
			}
		}
		int lastBracketO = 0;
		for(int i = this->getStrLen(); i >= 0; i--)
		{
			if(pStr[i] == ')')
			{
				lastBracketO = i;
				break;
			}
		}

		if(this->getStrLen() % 5 == 0)
		{
			pNewStr[0] = '-';
			pNewStr[1] = '>';
			int i = 0;
			for(i = 0; i < this->getStrLen() && i < lastBracketC; i++)
			{
				pNewStr[i + 2] = pStr[i];
			}

			pNewStr[i + 2] = '<';
			pNewStr[i + 3] = '-';

			for(i = lastBracketC; i < this->getStrLen(); i++)
				pNewStr[i+4] = pStr[i];
			pNewStr[i+4] = '\0';
		}
		else
		{	
			int i = 0;
			for(i = 0; i < this->getStrLen() && i <= lastBracketO; i++)
				pNewStr[i] = pStr[i];
			pNewStr[i] = '-';
			pNewStr[i+1] = '>';

			for(i = lastBracketO + 3; i < this->getStrLen()+2; i++)
				pNewStr[i] = pStr[i-2];
			pNewStr[i] = '<';
			pNewStr[i+1] = '-';
			pNewStr[i+2] = '\0';
		}
		
		pStr = pNewStr;

	}

};

int main()
{
	String S1;
	printf("Set str: ");
	S1.Set();
	printf("\nString 1 is: "); S1.Print();


	String S2 = S1;
	printf("\nString 2 is: "); S2.Print();
	S2.Run();
	printf("\nEdited String 2 is: "); S2.Print();
	putchar('\n');
	return 0;
}
