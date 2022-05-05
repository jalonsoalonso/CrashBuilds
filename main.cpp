
/*
	Project with several errors on purpose to test the different behaviours of debug and release builds

	Update variable 'test' for the different tests
	TEST1: run from visual studio on debug mode and then on release mode
	TEST2: run from the console debug and release versions and compare printed texts
	TEST3: compare debug and release versions from both visual studio and the console
*/

#include <cstdio>
#include <cstdlib>

void f1(int *v)
{
	printf("Step 0\n");
	for (int i = 0; i < 10; ++i)
	{
		printf("v[%d] = %d\n", i, v[i]);
	}

	printf("Step 1\n");
	v[1] = -33;

	printf("Step 2\n");
	for (int i = 0; i < 10; ++i)
	{
		printf("v[%d] = %d\n", i, v[i]);
	}
	
	printf("Step 3\n");
	v[3] = -66;

	printf("Step 4\n");
}

void f2(int *v)
{
	printf("Step 0\n");
	if (v[0] > 0)
	{
		printf("v[0] not initialized but read it\n");
	}

	printf("Step 1\n");
	printf("%d\n", v[2]);
	v[2] = 0; 

	printf("Step 2\n");
	printf("%d\n", v[2]);

	printf("Step 3\n");
}

int main()
{
	enum { TEST1, TEST2, TEST3 };
	int test = TEST1;

	int vec[2];
	int *p = new int[2];

	switch(test)
	{
		case TEST1:	vec[0] = 33;
					f1(vec);
					break;

		case TEST2:	f2(p);
					break;

		case TEST3:	f2(p);
					delete[] p;
					break;
	}
	
	system("pause");
	return 0;
}