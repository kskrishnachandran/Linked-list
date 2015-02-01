/*File Name:insert_to_head.c
  Author:K.S.Krishna Chandran
  Description:Program to insert numbers to the head of a linked list
  Date:01-02-15*/


#include<stdio.h>

struct node
{
	int number;
	struct node *link;
}*head=NULL;



int add_at_head();
int display(); 

int main()
{
	system("clear");
	add_at_head(); 
	display();
	printf("\n\n");
	return 0;
} 


int add_at_head()
{
	char ch;
	do
	{
		struct node *new;
		new=(struct node *)malloc(sizeof(struct node));
		printf("\n\nEnter the number to the head    ");
		scanf("%d",&new->number);
		new->link=NULL;
		if(head==NULL)
		{
			head=new;
		}
		else
		{
			new->link=head;
			head=new;
		}
		printf("\n\nDo you want to enter more numbers (Y/N)");
		scanf(" %c",&ch);
	}while(ch=='Y'||ch=='y');
}

int display()
{
	struct node *disp;
	disp=head;
	printf("\n\nThe numers in the list are \n");
	while(disp!=NULL)
	{
		printf("%d <-- ",disp->number);
		disp=disp->link;
	}
	printf("NULL");
}
		
		
		
			
	
	
	
	
