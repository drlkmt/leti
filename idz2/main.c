#include <iostream>
#include <time.h>
#define MINRANDNUM 1
#define MAXRANDNUM 10

class Array
{
private:
	int *pArr = NULL;
	int nArr = 0;
public:
	Array(int local_nArr)
	{
		nArr = local_nArr;
		pArr = (int*)malloc(sizeof(int) * nArr);
		for(int i = 0; i < nArr; i++) pArr[i] = MINRANDNUM + rand() % MAXRANDNUM;
	}

	int* pGetArr()
	{
		return pArr;
	}

	void printArr()
	{
		for(int i = 0; i < nArr; i++) printf("%d ", pArr[i]);
	}

	void printArrC(char c)
	{
		printArr();
		printf("%c",c);
	}

	int getNarr()
	{
		return nArr;
	}
};

void arrMultiply(Array, Array);

int main()
{
	srand(time(0));
	Array A(5);
	Array B(5);
	
	printf("Src array A: "); A.printArrC('\n');
	printf("Src array B: "); B.printArrC('\n');
	printf("\n");

	arrMultiply(A, B);

	return 0;
}

void arrMultiply(Array firstArr, Array secArr)
{
	int firstCx = 0;
	int secCx = 0;
	
	for(int i = 0; i < firstArr.getNarr(); i++) if(firstArr.pGetArr()[i] % 3 == 0) firstCx++;
	for(int i = 0; i < secArr.getNarr(); i++) if(secArr.pGetArr()[i] % 3 == 0) secCx++;

	if(firstCx > secCx) 
	{
		printf("A array have %d divisors by 3: ", firstCx); 
		firstArr.printArrC('\n');
		printf("B array have %d divisors by 3: ", secCx); 
		secArr.printArrC('\n');
		 
	}
	else if(firstCx == secCx) printf("Oops, eror ._.\n");
	else
	{
		printf("B array have %d divisors by 3: ", secCx); 
		secArr.printArrC('\n');
		printf("A array have %d divisors by 3: ", firstCx); 
		firstArr.printArrC('\n');
	}
}


