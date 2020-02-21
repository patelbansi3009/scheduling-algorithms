//17BCP061D
#include<stdio.h>

void insertsort(int arr[], int n,int p[], int burst[]) 
{ 
    int i, key,key1,key2, j; 
    for (i = 1; i < n; i++) { 
        key = arr[i]; 
        key1=p[i];
        key2=burst[i];
        j = i - 1; 
  
        while (j >= 0 && burst[j] > key2) { 
            arr[j + 1] = arr[j]; 
            p[j + 1] = p[j]; 
            burst[j + 1] = burst[j]; 
            j = j - 1; 
        } 
        arr[j + 1] = key;
        p[j + 1] = key1;
        burst[j + 1] = key2; 
    }
    
 }   
    
void print(int arr[], int n) 
{ 
    int i; 
    for (i = 0; i < n; i++) 
        printf("%d ", arr[i]); 
    printf("\n"); 

} 


void avg(int n, int arr[])
{
	int i;
	float sum = 0;
	for(i =0; i<n; i++)
	{
		sum = sum + arr[i];
	}

	float a = sum / n;
	
	printf("%f \n", a);

}
void WT(int n, int t[], int b[])
{
	int i;
	int w[n];
	
	for(i=0; i<n; i++)
	{
		w[i] = t[i] - b[i] ;
	}
	
	printf("The waiting time of the processes are : \n");
	print(w, n);
	
	printf("The average waiting time is : \n");
	avg(n, w);
}


void TAT(int n, int c[], int a[], int b[])
{
	int i;
	int t[n];
	
	for(i=0; i<n; i++)
	{
		t[i] = c[i] - a[i] ;
	}
	
	printf("The turn around time of the processes are : \n");
	print(t, n);

	printf("The average Turn around time is : \n");
	avg(n, t);
	
	WT(n, t, b);
}


void completion(int arr[],int burst[],int n,int p[],int temp[])
{
	int comp[n] ,i=0, total=0,x=0,count=0;
	
	for(i=0;i<n;i++)
		comp[i]=0;
		
	while(x<n)
	{
		if(arr[x]<=total && burst[x]>0)
		{
			 total+=burst[x];
			 burst[x]=0;
			 comp[x]=total;
			 count++;
			 x=0;
		}
		else if(arr[x]>total)
		{
			total+=arr[x];
		}
		else
			x++;	
	}
	printf("\n");
	printf("\nCompletion times for:");print(p,n);
	printf("\nis :");
	print(comp,n);
	

	TAT(n, comp, arr, temp);
	
	float y = comp[n-1];
	float tp;
	tp = n/y;
	
	printf("The throughput of the processes is : \n");
	printf("%f \n", tp);
	
	
} 
int main()
{
		int n,i,q,x;
	printf("Enter the number of processes:\n");
	scanf("%d",&n);
	int p[n],arr[n],burst[n],temp[n];
	
	printf("Enter the process IDs of each respectively\n");
	for(i=0;i<n;i++)
		scanf("%d",&p[i]);
		
	printf("Enter the arrival times of each respectively\n");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
		
	printf("Enter the burst times of each respectively\n");
	for(i=0;i<n;i++)
		scanf("%d",&burst[i]);
		
	insertsort(arr,n,p,burst);
	for (x=0;x<n;x++)
		temp[x]=burst[x];

	printf("Process ID:     ");print(p,n);
	printf("Arrival time:   ");print(arr,n);
	printf("Burst time:     ");print(burst,n);
	completion(arr,burst,n,p,temp);
}
