#include <iostream>
#define MAXSYMBOLINSTR 79

class String
{
private:
	char *strArr = NULL;
public:
	String()
	{
		if(!(strArr = (char*)malloc(sizeof(char) * MAXSYMBOLINSTR + 1)))
		{
			printf("Memory error!");
			exit(1);
		}

	}

	void Set()
	{
		int cx = 0;
		char c;
		while((c = getchar()) != '\n' && c != EOF)
		{
			strArr[cx] = c;
			cx++;
		}
		strArr[cx] = '\0';
	}

	void voidprint()
	{
		printf("%s", strArr);
	}

	char* getPstrArr()
	{
		return strArr;
	}

	String& operator=(String str)
	{
		strArr = str.getPstrArr();
		return *this;
	}
};

int main()
{
	String S1;
	S1.Set();
	
	printf("Str1 print: ");
	S1.voidprint();
	putchar('\n');

	String S2 = S1;
	printf("Str2 copyed print: ");
	S2.voidprint();
	putchar('\n');	
	
	return 0;
}
