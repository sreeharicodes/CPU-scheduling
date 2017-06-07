#include<stdio.h>
#include<string.h>
int n,i,j,k,delay,num;
struct process{
  char name[10];
  int at,bt,tt,wt,status;
}p[15],temp;
struct done{
  char name[10];
  int st,ct;
}d[15];
void read()
{
  printf("\nEnter the number of processes: ");
  scanf("%d",&n );
  printf("\nEnter the details of each process\n");
  for(i=0;i<n;i++)
  {
    printf("\nEnter the name of the process:");
     scanf("%s",&p[i].name);
    printf("\nEnter the arrival time:");
    scanf("%d",&p[i].at);
    printf("\nEnter the burst time:");
    scanf("%d",&p[i].bt);
    p[i].status=0;
  }
  printf("\nThe details of processes you entered are:\n");
  printf("Name\tarrival time\tBurst time\n");
  for(i=0;i<n;i++)
  {
    printf("%s\t\t%d\t\t%d\n",p[i].name,p[i].at,p[i].bt);
  }
}
void sort()
{
  for(i=0;i<n;i++)
  {
    for(j=0;j<(n-1);j++)
    {
      if(p[j].at>p[j+1].at)
      {
        temp=p[j];
        p[j]=p[j+1];
        p[j+1]=temp;
      }
    }
  }
  printf("\nThe details of processes After sorting:\n");
  printf("Name\tarrival time\tBurst time\n");
  for(i=0;i<n;i++)
  {
    printf("%s\t\t%d\t\t%d\n",p[i].name,p[i].at,p[i].bt);
  }
}
void fcfs()
{
  i=0;num=0;int idle=0;
  for(k=0;k<n;)
  {
    if((p[k].at<=i)&&(p[k].status==0))
    {
      if(idle==1)
      {
        d[num].ct=i;
        num++;
        idle=0;
      }
      strcpy(d[num].name,p[k].name);
      d[num].st=i;
      d[num].ct=i+p[k].bt;
      p[k].wt=i-p[k].at;
      p[k].status=1;
      i=i+p[k].bt;
      p[k].tt=p[k].wt+p[k].bt;
      num++;k++;
    }
    else
    {
      if(idle==0)
      {
      idle=1;
      strcpy(d[num].name,"delay");
      d[num].st=i;
      i++;
      }
      else
      {
      i++;
      }
    }
  }
}
void display()
{
  printf("\nname\tat\tbt\twt\ttt\n");
  for(j=0;j<n;j++)
  {
  printf("%s\t%d\t%d\t%d\t%d\n",p[j].name,p[j].at,p[j].bt,p[j].wt,p[j].tt);
  }
  printf("\n\nGantt Chart\n_______________________\n");
	for(i=0;i<num;i++)
	{
		printf("--------");
	}
	printf("\n");
	for(i=0;i<num;i++)
	{
		printf("|%s\t",d[i].name);
	}
	printf("|\n");
	for(i=0;i<num;i++)
	{
		printf("--------");
	}
	printf("\n");
	for(i=0;i<num;i++)
	{
		printf("%d\t",d[i].st);
	}
	printf("%d\n",d[i-1].ct);
  printf("\n");

  /*for(j=0;j<=n;j++)
  {
    printf("______________");
  }
  printf("\n");
  for(j=0;j<n;j++)
  {
    printf("|%s",d[j].name);
  }
  printf("|\n");

  for(j=0;j<=n;j++)
  {
    printf("______________");
  }
  printf("\n");
  for(j=0;j<n;j++)
  {
    printf("%d\t",d[j].st);
  }
  printf("%d",d[j].ct);*/
}
void main()
{
  read();
  sort();
  fcfs();
  display();
}
