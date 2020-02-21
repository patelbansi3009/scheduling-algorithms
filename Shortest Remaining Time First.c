//17BCP061D
#include<stdio.h>
int min(int max,int b_t[])
{
int m=0;
	for(int i=1;i<max;i++)
	{
		if(b_t[m]==0)
		{
		m=i;
		}
		if(b_t[m]>b_t[i] && b_t[i]!=0)
		{
		m=i;
		}
	}
return m;
}
int main()
{
int n_p,base=0,st=1,ptr=0,count=0,hp;

float tput;
printf("Enter Number of process\n");
scanf("%d",&n_p);
int a_t[n_p],b_t[n_p],ss[n_p],temp[n_p],c_t[n_p],tat[n_p],w_t[n_p],r_t[n_p],status[n_p],heap[1];
printf("Enter A.T and B.T for every process respectively\n");
for(int i=0;i<n_p;i++)
{
scanf("%d",&a_t[i]);
scanf("%d",&b_t[i]);

}
for(int i=0;i<n_p;i++)
{
temp[i]=b_t[i];
ss[i]=0;
}
base=base+a_t[ptr];
int pcc=n_p;
while(1)
{
int k=0;
int exe=0;
ptr=base;
	for(int i=0;i<n_p;i++)
	{
		if(a_t[i]<=base)
		{
		k++;	
		}
	}
	if(k>1)
	{
	exe=min(k,b_t);
	}
	if(ss[exe]==0)
	{
	r_t[exe]=base;
	ss[exe]=1;
	}
	base=base+1;
	b_t[exe]=b_t[exe]-1;
	if(b_t[exe]==0)
	{
	c_t[exe]=base;
	tat[exe]=c_t[exe]-a_t[exe];
	w_t[exe]=tat[exe]-temp[exe];
	pcc--;
	}
	if(pcc==0)
	{
	tput=((float)n_p)/base;
	break;
	}
	continue;
}
float avgwt=0,avgtat=0,avgr=0;
printf("A.T\t B.T\t C.T\t TAT\t W.T\t R.T\t\n");
for(int i=0;i<n_p;i++)
{
printf("%d\t %d\t %d\t %d\t %d\t %d\t\n",a_t[i],temp[i],c_t[i],tat[i],w_t[i],r_t[i]);
}
for(int i=0;i<n_p;i++)
{
avgwt=avgwt+w_t[i];
avgtat=avgtat+tat[i];
avgr=avgr+r_t[i];
}
printf("\nThrouhput %f",tput);

printf("\nAvg Waiting %f",avgwt/n_p);

printf("\nAvg Turn Around Time %f",avgtat/n_p);

printf("\nAvg Response Time %f",avgr/n_p);

return 0;
}
