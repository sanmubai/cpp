#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

	time_t tm;

	srand((unsigned int)time(&tm));

	int a[3][4]={1,2,3,4,5,6,7,8,9,10,11,12};

	int (*p)[4]=a;

	for (int i = 0; i < 3; ++i)
	{
		/* code */

		for (int j = 0; j < 4; ++j)
		{
			/* code */

			p[i][j]=rand()%100;
		}
	}

	for(int i=0;i<3;i++){
		for(int j=0;j<4;j++){
			// printf("%4d",p[i][j] );

			printf("%4d",*(*(p+i)+j) );
		}
		printf("\n");
	}

	// printf("%d\n",rand() );

	return 0;
}