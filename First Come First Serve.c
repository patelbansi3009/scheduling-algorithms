//17BCP061D
#include<stdio.h>

void main()
{
	int n;

	printf("Enter Total Number of processes=");
	scanf("%d",&n);

	int a[n][7];

	for(int i=0;i<n;i++)
	{
		a[i][0]=i+1;
		printf("Enter Arrival Time for %d :=",a[i][0]);
		scanf("%d",&a[i][1]);
		printf("Enter Burst Time for %d :=",a[i][0]);
		scanf("%d",&a[i][2]);
	}		

	for(int i=0; i<n; i++)
	{
		for(int k=i+1; k<n; k++)
		{
			if( a[i][1] > a[k][1] )
			{	
				int temp = a[i][0];
				a[i][0] = a[k][0];	
				a[k][0] = temp;

				temp = a[i][1];
				a[i][1] = a[k][1];
				a[k][1] = temp;
	
				temp = a[i][2];
				a[i][2] = a[k][2];
				a[k][2] = temp;
			}
		}
	}

	a[0][3]=a[0][1]+a[0][2];
	
	for(int i=1; i<n; i++)
	{
		if(a[i][1]>a[i-1][3])
			a[i][3]=a[i][1]+a[i][2];
		else
			a[i][3]=a[i-1][3]+a[i][2];
	}

	for(int i=0; i<n; i++)
	{
		a[i][4]=a[i][3]-a[i][1];
		a[i][5]=a[i][4]-a[i][2];
		a[i][6]=a[i][5];
	}
	
	printf("\n\nScheduling Table\n\nPID\tA.T\tB.T\tC.T\tT.A.T\tW.T.\tR.T\t\n");
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<7;j++)
		{
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}	

	float tat=0,wt=0,tp=0;
	
	for(int i=0;i<n;i++)
	{
		tat=tat+a[i][4];
		wt=wt+a[i][5];
	}

	tat=tat/n;
	wt=wt/n;
	tp=(float)n/a[n-1][3];

	printf("\nAverage Turn Around Time = %f\n",tat);
	printf("Average Waiting Time = %f\n",wt);
	printf("Throughput = %f\n",tp);
}

