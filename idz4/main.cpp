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
		char* pNewStr = (char*)malloc(sizeof(char) * MAXLENSTR);
		int cxOld = 0;
		int cxNew = 0;
		if(this->getStrLen() % 2 != 0)
		{
			while(pStr[cxOld] != '\0')
			{
				if(pStr[cxOld] != ' ')
				{
					pNewStr[cxNew] = pStr[cxOld];
					cxOld++;
					cxNew++;
				}
				else
					cxOld++;
			}
			pNewStr[cxNew] = '\0';
			delete(pStr);
			pStr = pNewStr;
		}
		else
		{
			while(pStr[cxOld] != '\0')
			{
				if((cxOld+1) % 3 != 0)
				{
			 		pNewStr[cxNew] = pStr[cxOld];
					cxOld++;
					cxNew++;
				}
				else
					cxOld++;
			}	
			pNewStr[cxNew] = '\0';
			delete(pStr);
			pStr = pNewStr;
		}
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
