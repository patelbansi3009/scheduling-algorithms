//17BCP061D
#include<stdio.h>
int main()
{
int n_p;
printf("Enter Number of Process=");
scanf("%d",&n_p);
int a_t[n_p],priority[n_p],status[n_p],b_t[n_p],c_t[n_p],tat[n_p],w_t[n_p],r_t[n_p],c=0,base=0,head=1000;
printf("Enter Arrival Time, Priority and Burst Time=\n");
for(int i=0;i<n_p;i++)
	{
	scanf("%d",&a_t[i]);
	scanf("%d",&priority[i]);
	scanf("%d",&b_t[i]);
	}
base=base+a_t[0];
for(int i=0;i<n_p;i++)
{
status[i]=0;
}
while(c<n_p){
head=1000;
for(int i=0;i<n_p;i++)
	{
		if(a_t[i]<=base && status[i]==0 && i<n_p)
		{
			if(head==1000)
			{
			head=i;
			continue;
			}
			if(priority[head]>=priority[i])
			{
			head=head;
			}
			else
			{
			head=i;
			}
		}
		else
		{
		continue;		
		}
	}
if(head!=1000)
{
int g=head;
r_t[g]=base;
base=base+b_t[g];
status[g]=1;
c_t[g]=base;
tat[g]=c_t[g]-a_t[g];
w_t[g]=tat[g]-b_t[g];
c++;
}
else
{
base=base+1;
}
continue;
}
printf("A.T\t B.T\t Prio\t C.T\t TAT\t W.T\t R.T\t\n");
for(int i=0;i<n_p;i++)
{
printf("%d\t %d\t %d\t %d\t %d\t %d\t %d\t\n",a_t[i],b_t[i],priority[i],c_t[i],tat[i],w_t[i],r_t[i]);
}
return 0;
}
