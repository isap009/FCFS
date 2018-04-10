#include<stdio.h>
#include<pthread.h>
struct process
{
int process_name[5];
int priority;
int burst_time;
int arrival_time;
int waiting_time;
int remaining_time;
int turnaroundtime;
};
struct process q[30],r[3][10];
struct process temp;
struct process q_one[10];
struct process q_two[10];
struct process q_three[10];
int size_one=0,size_two=0,size_three=0,n,quant=4,quant1=10,rem,num1,num,time=0,remain=3;
void execution();
void assign(struct process *m,struct process *n)
{
	*m=*n;
}
void swap(struct process *m,struct process *n)
{
	temp=*n;
	*n=*m;
	*m=temp;
}

void fcfs()
{
	int a,i,j;
	a=time;
//fcfs for queue1
	num=size_one;
	for(i=1;i<num;i++)
	{
		for(j=0;j<num-i;j++)
		{
			if(q_one[j].arrival_time>q_one[j+1].arrival_time)
			{
				swap(&q_one[j],&q_one[j+1]);
			}
		}
	}
	for(i=0;i<num;i++)
	{
		while(q_one[i].remaining_time!=0)
		{
			time++;
            q_one[i].remaining_time--;
            if(time-a==10)
            {
            	return;
			}
		}
	}
	remain--;
}
void priorsched()
{
	int b,i,j;
	b=time;
//priority for queue2
num1=size_two;
	for(i=1;i<num1;i++)
	{
		for(j=0;j<num1-i;j++)
		{
			if(q_two[j].arrival_time>q_two[j+1].arrival_time)
			{
				swap(&q_two[j],&q_two[j+1]);
			}
		}
	}

	for(i=1;i<num1;i++)
	{
		for(j=0;j<n-i;j++)
		{
	     if((q_two[j].arrival_time==q_two[j+1].arrival_time)&&(q_two[j].priority<q_two[j+1].priority))
	     {
	  	    swap(&q_two[j],&q_two[j+1]);
	     }
        }
    }
    for(i=0;i<num1;i++)
   {
	    while(q_two[i].remaining_time!=0)
	   {
			while(q_two[i].remaining_time!=0)
			{
				time++;
				q_two[i].remaining_time--;
			   if(time-b==10)
               {
            	  return;
			   }
			}
	    }
    }
	remain--;
	
}
void roundrobin()
{
	int c,k,i,j;
	c=time;

void execution()
{
	int i=0;
	while(remain>0) {
		for(i=0; i<3; i++)
		{
			switch(i)
			{
				case 0:
					fcfs();
					break;
				case 1:
					priorsched();
					break;
				case 2:
					roundrobin();
					break;
			}
		}
		printf("1");
	}
}
int main()
{
	int i,j;
	printf("\nEnter the number of process:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\nEnter the name of the process");
		fflush(stdin);
		scanf("%s",&q[i].process_name);
		printf("\nEnter the priority of the process");
		scanf("%d",&q[i].priority);
		printf("\nEnter the burst time");
		scanf("%d",&q[i].burst_time);
		printf("\nEnter the arrival time");
		scanf("%d",&q[i].arrival_time);
		q[i].remaining_time=q[i].burst_time;
		q[i].waiting_time=0;
		if(q[i].priority==1||q[i].priority==2)
		{
		    assign(&q_one[size_one],&q[i]);	
			size_one++;
		}
		else if(q[i].priority==3||q[i].priority==4)
		{
			assign(&q_two[size_two],&q[i]);	
			size_two++;
		}
		else if(q[i].priority==5||q[i].priority==6)
		{
			assign(&q_three[size_three],&q[i]);	
			size_three++;
		}
		else
		{
			printf("\nEnter valid number");
		}
	}
	execution();
	for(j=0;j<size_one;j++)
	{
		q_one[j].waiting_time=time-q_one[j].burst_time-q_one[j].arrival_time;
		q_one[j].turnaroundtime=q_one[j].waiting_time+q_one[j].burst_time;
		printf("\n--------%s-------\n",q_one[j].process_name);
		printf("WaitingTime:%d\n",q_one[j].waiting_time);
		printf("TurnAroundTime:%d",q_one[j].turnaroundtime);
	}
	for(j=0;j<size_two;j++)
	{
		q_two[j].waiting_time=time-q_two[j].burst_time-q_two[j].arrival_time;
		q_two[j].turnaroundtime=q_two[j].waiting_time+q_two[j].burst_time;	
		printf("\n--------%s-------\n",q_two[j].process_name);
		printf("WaitingTime:%d\n",q_two[j].waiting_time);
		printf("TurnAroundTime:%d",q_two[j].turnaroundtime);
	}
	for(j=0;j<size_three;j++)
	{
		q_three[j].waiting_time=time-q_three[j].burst_time-q_three[j].arrival_time;
		q_three[j].turnaroundtime=q_three[j].waiting_time+q_three[j].burst_time;
		printf("\n---------%s----------\n:",q_three[j].process_name);
		printf("WaitingTime:%d\n",q_three[j].waiting_time);
		printf("TurnAroundTime:%d\n",q_three[j].turnaroundtime);
	}
}
