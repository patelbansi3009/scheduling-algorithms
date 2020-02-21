//17BCP061D
#include<stdio.h>
#include<stdlib.h>
void insert(int q[],int *f,int *r,int val)
{
  if((*r)+1>=100)
  {
    printf("Queue full");
    exit(-1);
  }
  
  (*r)++;
  q[*r]=val;
  if((*f)==-1);
   (*f)=0;
}


void insertsort(int arr[], int n,int p[], int burst[]) 
{ 
    int i, key,key1,key2, j; 
    for (i = 1; i < n; i++) { 
        key = arr[i]; 
        key1=p[i];
        key2=burst[i];
        j = i - 1; 
  
        while (j >= 0 && arr[j] > key) { 
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



void completion(int arr[],int temp[], int n,int q,int p[])
{
	int RQ[100];
    int F,R;
    F=R=-1;
	
	int i=0,total=0,z=0,count=0,j=0,x;
	int comp[n];

	for(i=0;i<n;i++)
		comp[i]=0;

	insert(RQ,&F,&R,p[0]);

	while(z<=R)
	{
	    x=RQ[z];
    			if(temp[x]<=q && temp[x]>0 )
    			{
    				total+=temp[x];
    				temp[x]=0;
    				comp[x]=total;
    					while(i<n)
                        {
    				    while(j<=R)
    				        {
    				            if(arr[i]<=total)
    				                {
    				                    if(p[i]==RQ[j])
    				                        break;
    				                    else
    				                        if(j<R)
    				                            j++;
    				                        else
    				                        { printf("\nHii: %d\n",p[i]);
    				                            insert(RQ,&F,&R,p[i]);
    				                            j++;
    				                        }

    				                }
    				            else
    				                break;
    				        }
    				        i++;
    				   }
    				   insert(RQ,&F,&R,p[x]);
    				count++;
    
    			}
    			
    			else if (temp[x]>q)
    			{
    				total+=q;
    				temp[x]-=q;
    				i=0;
    				j=0;
    				while(i<n)
    				   {
    				    while(j<=R)
    				        {
    				            if(arr[i]<=total)
    				                {
    				                    if(p[i]==RQ[j])
    				                        break;
    				                    else
    				                        if(j<R)
    				                            j++;
    				                        else
    				                        {
    				                            insert(RQ,&F,&R,p[i]);
    				                            j++;
    				                        }

    				                }
    				            else
    				                break;
    				        }
    				        i++;
    				   }
    				   insert(RQ,&F,&R,p[x]);
    				
    			}
		  
    			
    			z++;
	}
	printf("\n");
	print(comp,n);
}

int main()
{
    
		int n,i,q,x;
	printf("Enter the number of processes:\n");
	scanf("%d",&n);
	int p[n],arr[n],burst[n],temp[n];
	
	for(i=0;i<n;i++)
		p[i]=i;
		
	printf("Enter the arrival times of each respectively\n");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
		
	printf("Enter the burst times of each respectively\n");
	for(i=0;i<n;i++)
		scanf("%d",&burst[i]);
		
	printf("Enter the time quantum:\n");
	scanf("%d",&q);
	
	insertsort(arr,n,p,burst);
	for (x=0;x<n;x++)
		temp[x]=burst[x];
	printf("Process ID:     ");print(p,n);
	printf("Arrival time:   ");print(arr,n);
	printf("Burst time:     ");print(burst,n);
printf("The Completion times for");print(p,n);
    completion(arr,burst,n,q,p);
	

}
