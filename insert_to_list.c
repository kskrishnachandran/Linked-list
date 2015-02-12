/*File Name : insert_to_list.c
  Author Name : K.S.Krishna Chandran 
  Date : 05-01-15*/




/*Description :-
        C program for executing a menu driven program to deal with linked lists.
        The Menu consists of options like 1)Add to head
										  2)Add to tail
										  3)Search an element and modify it
										  4)Display the list
										  5)Delete from the list

		Different user defined functions are used for each opertions.
		 
      
  */


#include<stdio.h>
#include<stdlib.h>

int node_count = 0;
int mi = 0;

struct node                                                 //Structer declaration
{
	int num;                                               //Node elements to store number and address of next node    
	struct node *link;
}*head=NULL;                                              //Structure variable, which is used to store the first node of the list

int display_head();                                      //Function to display the elements from the head
int display_tail();                                      //Function to display the elements from the tail
int insert_at_head();                                    //Function to insert the elements to the head
int insert_at_tail();                                    //Function to insert the elements to the tail
int display();                                           //Function to display the elements in the node
int delete_node();                                       //Function to delete the elements in the node
int search_modify();                                     //Function to search an element and modify the list


//Main function for calling each functions according to the user's choice.
int main() {

	system("clear");
	char ch;
	int n;
	do {
		system("clear");
		printf("\n\nLinked List Menu\n");
		printf("\n1.Insert at head of node\n2.Insert at tail of node\n3.Search and modify that node\n4.Delete Element\n5.Display\n6.Exit\n");
		printf("\nPlease enter an option     ");
		scanf("%d", &n);
		switch(n) {
			case 1 : printf("\n\n**Insert at head**\n");
				     insert_at_head();                                           //Calling function to add elemenets at the head 
				     display_head();
				     break;

			case 2 : printf("\n\n**Insertat tail**\n");
				     insert_at_tail();                                           //Calling function to add elemenets at the tail
				     display_tail();
				     break;

			case 3 : printf("\n\n**Search and modify a node**\n\n");
				     modify_list();
				     display();
				     break;

			case 4 : printf("\n\n");
				     delete_node();
				     display();
				     break;

			case 5 : printf("\n\n**Displaying the list**\n\n");
					 display();
					 break;

			case 6 : printf("\nExiting.... !!!!");
					 exit(0);

			default : printf("\n\nPlease enter a valid option  ");
		}
		printf("\n\nDo you want to continue (Y/N)   ");
		scanf(" %c", &ch);
	} while(ch == 'Y' || ch == 'y');
	printf("\n\n");
	return 0;
}

//Function to insert nodes to the head of the list.
int insert_at_head() {
	char choice1;
	do {
		struct node *head_new;
		head_new = (struct node *)malloc(sizeof(struct node));
		printf("\nEnter the number to add at the heaad of the node        ");
		scanf("%d",&head_new->num);
		head_new->link = NULL;
		if(head == NULL) {
			head = head_new;
		}
		else {
			head_new->link = head;
			head = head_new;
		}
		printf("\n\nDo you want to insert more at head  (Y/N)  ");
		scanf(" %c", &choice1);
	} while(choice1 == 'Y' || choice1 == 'y');

}

//Function to insert nodes to the tail of the list.
int insert_at_tail() {
	char choice2;
	do {
		struct node *tail_new, *temp;
		temp = head;
		tail_new = (struct node *)malloc(sizeof(struct node));
		printf("\nEnter the number to add at the tail of the node         ");
		scanf("%d",&tail_new->num);
		tail_new->link = NULL;
		if(head == NULL) {
			head = tail_new;
		}
		else {
			while(temp->link != NULL) {
				temp = temp->link;
			}
			temp->link = tail_new;
		}
		printf("\nDo you want to insert more at tail  (Y/N)   ");
		scanf(" %c",&choice2);
	} while(choice2 == 'Y' || choice2 == 'y');
	printf("\n\n");
}



//Function to search an elemet from the list an to modify the value if the user wants to.
int modify_list() {
	if(head == NULL) {
		printf("\n\nThe list is empty, search is not possible");
		return 0;
	}
	
	int new_num;
	char moc;                                                        //Character to store the user's choice
	struct node *modify;
	modify = (struct node *)malloc(sizeof(struct node));
	modify = head;
	int nod;
	
	do {
		printf("\nEnter the number to be searched in the list     ");
		scanf("%d",&nod);
		while(modify != NULL) {
			mi++;                                                     //To count the list number
			if(modify->num == nod) {
				printf("\n\n%d is present in the %d list", nod, mi);
				printf("\n\nDo you want to modify this list (Y/N)    ");
				scanf(" %c", &moc);
				if(moc == 'Y' || moc == 'y') {
					system("clear");
					printf("\n\n**Modifying the list**\n");
					printf("\nEnter the new number   ");
					scanf("%d", &new_num);
					modify->num = new_num;
					break;
				}
			}
			modify = modify->link;
		}
		printf("\nDo you want to continue modifynig the lsit (Y/N)   ");
		scanf(" %c",&moc);
	} while(moc == 'Y' || moc == 'y');
}


//Functin to delete nodes from the list according to the user's choice.
int delete_node() {
	if (head == NULL) {
		printf("\n\nList is empty deletion not possible  ");
		return 0;
	}
	int dchoice;                                                    //Variable to store the user's choice in delete list
	printf("\n**Delete Menu**");
	printf("\n1.Delete list at head\n2.Delete list at tail\n3.Delete other lists\n");
	printf("\nPlease enter a choice   ");
	scanf("%d",&dchoice);
	struct node *ctemp;
	ctemp = (struct node *)malloc(sizeof(struct node));
	ctemp = head;
	while(ctemp != NULL) {
		node_count++;
		ctemp = ctemp->link;
	}
	int i;
	switch(dchoice) {
		case 1 : printf("\nDeleting the node at the head of the list !!!");
			head = head->link;
			break;
			
			
		case 2 : printf("\nDeleting the node at the tail of the list !!!");
			struct node *dtemp;
			dtemp = (struct node *)malloc(sizeof(struct node));
			dtemp = head;
			for(i = 1; i < node_count-1; i++) {
				dtemp = dtemp->link;
			}
			dtemp->link = NULL;
			break;
			
			
		case 3 : printf("\n**Deleting the elements from the list**");
			struct node *first_delete;
			struct node *second_delete;
			int no;
			printf("\n\nEnter the node number for deleting from the list    ");
			scanf("%d", &no);
			if(no > node_count)
			{
				printf("\n\nInvalid node number, deletion not possible\n");
				return 0;
			}
			printf("\n**Deleting the %dth node from the list**\n",no);
			first_delete = (struct node *)malloc(sizeof(struct node));
			second_delete = (struct node *)malloc(sizeof(struct node));
			first_delete = head;
			second_delete = head;
			for(i = 1; i < no-1; i++) {
				first_delete = first_delete->link;
			}
			for(i = 1; i < no+1; i++) {
				second_delete = second_delete->link;
			}
			first_delete->link = second_delete;      //Changing the value of link part of the preceding node of the deleted link
			break;
			
			default : printf("\nPlease enter a valid choice ");
				break;
		}
	return 0;
}


//Function to display the list.
int display() {
	system("clear");
	printf("\n\n\n");
	if(head == NULL) {
		printf("List is Empty !!!!\n");
		return 0;
	}
	struct node *t;
	t = head;
	while(t != NULL) {
		printf("%d->",t->num);
		t = t->link;
	}
	printf("NULL");
	printf("\n\n");
	return 0;
}



//Function to display the list starting from it's tail.
int display_tail() {
	system("clear");
	printf("\n\n\n");
	struct node *t;
	t = head;
	while(t != NULL) {
		printf("%d->",t->num);
		t = t->link;
	}
	printf("NULL");
	printf("\n\n");
	return 0;
}


//Function to display the list starting from it's head.
int display_head() {
	system("clear");
	printf("\n\n\n");
	struct node *tm;
	tm = head;
	while(tm != NULL) {
		printf("%d<-",tm->num);
		tm = tm->link;
	}
	printf("NULL");
	printf("\n\n");
	return 0;
}
