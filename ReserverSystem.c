#include<stdio.h>

// this array contain all reserve and non reserve 
static int reserve[2][5] = {0};

void check()
{
	int i=0,j=0;
	printf("\n\n");
	printf("------------------------------------\n");
	printf("|Days                1  2  3  4  5 |\n");
	for(i=0;i<2;i++)
	{
		if(i==0)
		{
			printf("------------------------------------\n");
			printf("|MORNING SESSION    ");
		}
		else
		{
			printf("------------------------------------\n");
			printf("|AFTERNOON SESSION  ");
		}
		for(j=0;j<5;j++)
		{
			printf(" %d ",reserve[i][j]);
		}
		printf("|\n");
	}
	printf("------------------------------------\n");
	printf("\n\n");
}

void  delete()
{
	int d,se;
	char s;
	printf("please enter the day to reserv your seat[1 to 5] = \n");
	scanf("%d",&d);
	printf("please select the session either morning or afternoon by pressing M for morning and A for afternoon\n");
	scanf("\n");
	scanf("%c",&s);
	if(s=='M')
	{
		se=0;
	}
	else if(s=='A')
	{
		se=1;
	}
	if(reserve[se][d-1]==1)
	{
		reserve[se][d-1]==0;
		printf("THANK YOU, YOUR SEAT HAS BEEN REMOVED\n");
	}
	else
	{
		printf("SEAT IS ALREADY EMPTY\n");
	}
}
void calculate()
{
	int i=0,j=0,count=0;
	for(i=0;i<2;i++)
	{
		for(j=0;j<5;j++)
		{
			if(reserve[i][j]==1)
			{
				count++;
			}
		}
	}
	printf("TOTAL INCOME = %d\n",count*4000);
}
void book()
{
	int d,se=-1;
	char s;
	printf("please enter the day to reserve your seat[1 to 5]\n\n");
	scanf("%d",&d);
	//please enter the charcter in capital letter!
	printf("please select the session[case sensitive] by  pressing M for morning and A for afternoon\n\n");
	//below scanf will get any new line character if any in memeory, please  don't delete it
	scanf("\n");
	scanf("%c",&s);
	if(s=='M')
	{
		se=0;
	}
	else if(s=='A')
	{
		se=1;
	}
	if(reserve[se][d-1] == 0)
	{
		reserve[se][d-1] = 1;
		printf("THANK YOU YOUR SEAT HAS BEEN BOOKED ON DAY %d\n\n",d);
	}
	else
	{
		printf("SORRY SEAT IS NOT AVAILABLE AS PER YOUR REQUIRED DAY AND SESSION\nWould you like to choose another days??\n\n");
	}
}
int main()
{
	char c; 
	do
	{
		
		printf("****************** WELCOME TO NAT RESERVATION SYSTEM ******************\n");
		printf("BOOK THE THEATER : Press A\n");
		printf("CHECK RESERVATION : Press B\n");
		printf("REMOVE THE RESERVATION : Press C\n");
		printf("CALCULATE INCOME : Press D\n");
		printf("FOR EXIT : Press E\n");
		scanf("\n");
		// you can enter either small a or capital A
		scanf("%c",&c);
		if(!(c>=65 && c<=90))
		{
			c=c-32;
		}
		
		switch(c)
		{
			case 'A':
				book();
				break;
			case 'B':
				check();
				break;
			case 'C':
				delete();
				break;
			case 'D':
				calculate();
				break;
			case 'E':
				c='E';
				break;
			default:
				printf("INVALID OPTION\n\n");
		}
	}while(c!=5);
	return 0;
}
