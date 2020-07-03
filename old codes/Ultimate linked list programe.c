#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
}*first=NULL;
void insert()
{
	struct node *p,*q;
	p=(struct node*)malloc(sizeof(struct node));
	printf("enter value\n");
	scanf("%d",&p->data);
	p->next=NULL;
	if(first==NULL)
	{
		first=p;
	}
	else
	{
		q=first;
		while(q->next!=NULL)
		{
			q=q->next;
		}
		q->next=p;
	}
}
void insert_beg()
{
	struct node* p,*q;
	p=(struct node*)malloc(sizeof(struct node));
	printf("enter value for the node\n");
	scanf("%d",&p->data);
	q=first;
	p->next=first;
	first=p;
}
void insert_end()
{
	struct node* p,*q;
	p=(struct node*)malloc(sizeof(struct node));
	printf("enter value for the node\n");
	scanf("%d",&p->data);
	p->next=NULL;
	if(first==NULL)
	{
		first=p;
	}
	else
	{
		q=first;
		while(q->next!=NULL)
		{
			q=q->next;
		}
		q->next=p;	
	}
}
void insert_pos()
{
	int pos,val,i;
	struct node *p,*q,*t;
	p=first;
	do
	{
		printf("enter location where you want to insert\n");
		scanf("%d",&pos);
	}while(pos<0 && pos>count(p));
	printf("enter data\n");
	scanf("%d",&val);
	t=(struct node*)malloc(sizeof(struct node));
	t->data=val;
	t->next=NULL;
	if(pos==1)
	{
		t->next=first;
		first=t;
	}
	else
	{
		for(i=0;i<pos-1;i++)
		{
			q=p;
			p=p->next;
		}
		q->next=t;
		t->next=p;
	}
}
void insert_sort()
{
	int  val;
	printf("enter value\n");
	scanf("%d",&val);
	struct node *p,*q,*t;
	p=first;
	t=(struct node*)malloc(sizeof(struct node));
	t->data=val;
	t->next=NULL;
	if(first==NULL)	
	{
			first=t;
	}
	else
	{
		while(p->data<val)
	{
		q=p;
		p=p->next;
	}
	if(first->data>val)
	{
		t->next=first;
		first=t;
	}
	else
	{
	q->next=t;
	t->next=p;
	}
	}	
}
int count()
{
struct node *p=first;
	int count=0;
	while(p!=NULL)
	{
		p=p->next;
		count++;
	}
	printf("total node = %d\n",count);
}
void del_beg()
{
	struct node *q;
	q=first;
	first=first->next;
	free(q);
}
void del_end()
{
	struct node *p,*q;
	p=first;
	while(p!=NULL)
	{
		q=p;
		p=p->next;
	}
	q->next=NULL;
	free(p);
}
void del_pos()
{
	int pos,i;
	label:
	printf("which element do you want to delete? give index\n");
	printf("counting from 1\n");
	scanf("%d",&pos);
	if(pos<=1)
	{
		printf("give higher index\n");
		goto label;
	}
	struct node *p,*q;
	p=first;
	q=NULL;
	for(i=0;i<pos-1&&p!=NULL;i++)
	{
		q=p;
		p=p->next;
	}
	q->next=p->next;
	free(p);
}
void display()
{
	struct node* p=first;
	if(p==NULL)
	printf("! no nodes in the link list (empty)\n");
	while(p!=NULL)
	{
		printf("%d->",p->data);
		p=p->next;
	}
	printf("NULL\n");
}
void chk_sort()
{
	struct node* p;
	int val=INT_MIN;
	p=first;
	if(p==NULL)
    {
    	printf("empty list\n");
    	return;
	}
	else
	while(p!=NULL)
	{
		if(p->data<val)
		{
			printf("link list is not sorted\n");
			return;
		}
		else
		{
			val=p->data;
			p=p->next;
		}	
	}	
	printf("link list is sorted\n");
}
void sum()
{
struct node *p;
    p=first;
	int sum=0;
	while(p!=NULL)
	{
		sum+=p->data;
		p=p->next;
	}
	printf("sum of all nodes vales = %d\n",sum);
}
int min()
{
struct node *p=first;
	int Min=INT_MAX;
	if(p==NULL)
	printf("link-list is empty\n");
	else
	{
		while(p)
	{
		if(Min>p->data)
		{
			Min=p->data;
			p=p->next;
		}
		p=p->next;
    }
	}
	printf("minimum element in the link-list is = %d\n",Min);
}
int max()
{
struct node *p;
    p=first;
	int Max=INT_MIN;
	if(p==NULL)
	printf("link-list is empty\n");
	else
	{
		do
		{
			if(p->data>Max)
			{
				Max=p->data;
				p=p->next;
			}
			p=p->next;
	    }while(p->next!=NULL);
	}
	if(p!=NULL)
	{
	if(p->data>Max)
	Max=p->data;
	}
	
	printf("maximum element in the link-list is = %d\n",Max);
}
void swap(struct node *p,struct node *q)
{
	int tmp;
	tmp=q->data;
	q->data=p->data;
	p->data=tmp;
}
void search()
{
	int key;
	printf("which element do you want to search?\n");
	scanf("%d",&key);
	struct node *p=first;
	int count=1;
	while(p!=NULL)
	{
		if(key==p->data)
		{
			printf("item found !\n");
			printf("%d is %dth node\n",key,count);
			printf("address of that node is %d\n",p);
			return;
		}
		else
		p=p->next;
		count++;
	}
	if(key!=p->data)
	{
		printf("wrong item entered\n");
	}
}
void search_sort()
{
	int key;
	printf("which element do you want to search?\n");
	scanf("%d",&key);
	struct node *p=first;
	int count=1;
	struct node *q=NULL;
	while(p!=NULL)
	{
		if(key==p->data)
		{
		    printf("item found !\n");
		    printf("%d is %dth node\n",key,count);
		    printf("address of that node is %d\n",p);
			q->next=p->next;
			p->next=first;
			first=p;
			return ;
		}
		else
		{
			q=p;
			p=p->next;
			count++;
		}
	}
	if((key!=p->data))
	{
		printf("wrong item entered\n");
	}
}
void search_cng()
{
	int key;
	printf("which element do you want to search?\n");
	scanf("%d",&key);
	struct node *p=first,*q;
	int count=1;
	while(p!=NULL)
	{
		if(key==p->data)
		{
			printf("item found !\n");
			printf("%d is %dth node\n",key,count);
			printf("address of that node is %d\n",p);
			swap(q,p);
			return ;
		}
		else
		q=p;
		p=p->next;
		count++;
	}
	if(key!=p->data)
	{
		printf("wrong item entered\n");
	}
}
void sort()
{
	struct node *p,*q;
	p=first;
	q=p->next;
	while(p!=NULL && q!=NULL)
	{
		if(p->data>q->data)
		{
			swap(p,q);
		    p=first;
		    q=p->next;
		}
		else
		{
			p=q;
			q=p->next;
		}
	}
}
main()
{
	int choice,choice1,choice2,choice3;
	while(1)
	{
		printf("\tULTIMATE LINKED LIST PROGRAMME\n");
		printf("\t--------------MENU--------------\n");
		printf("\t1.Insertion\n");
		printf("\t2.Deletion\n");
		printf("\t3.Utility\n");
		printf("\t4.Display\n");
		printf("\t5.Clear screen\n");
		printf("\t6.Exit\n");
		printf("\t--------------------------------\n");
		printf("your choice ?\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1 :
				printf("\t--------------------INSERTION--------------------\n");
				printf("\t1.Enter values(append)\n");
				printf("\t2.Insert an element at begening of the link-list\n");
				printf("\t3.Insert an element at end of the link-list\n");
				printf("\t4.Insert any element with POS\n");
				printf("\t5.Insert any element in sorted link-list\n");
				printf("\t6.Back to main menu\n");
				printf("\t--------------------------------------------------\n");
			    printf("your choice ?\n");
			    scanf("%d",&choice1);
			    switch(choice1)
			    {
			    	case 1 :
			    		insert();
			    		break;
			    	case 2 :
			    		insert_beg();
			    		break;
			    	case 3 :
			    		insert_end();
			    		break;
			    	case 4 :
			    		insert_pos();
			    		break;
			    	case 5 :
			    		insert_sort();
			    		break;
			    	case 6 :
			    		break;
			    	default :
			    		printf("wrong choice,enter a valid choice\n");
				}
				break;
			case 2 :
				printf("\t---------------------DELETION---------------------\n");
				printf("\t1.Delete first element of the link-list\n");
				printf("\t2.Delete last element of the link-list\n");
				printf("\t3.Delete any element of the link-list with POS\n");
				printf("\t4.Back to main menu\n");
				printf("\t--------------------------------------------------\n");
			    printf("your choice ?\n");
			    scanf("%d",&choice2);
			    switch(choice2)
			    {
			    	case 1 :
			    		del_beg();
			    		break;
			    	case 2 :
			    		del_end();
			    		break;
			    	case 3 :
			    		del_pos();
			    		break;
			    	case 4 :
			    		break;
			    	default :
			    		printf("wrong choice,enter a valid choice\n");
				}
			    break;
		    case 3 :
		    	printf("\t---------------------UTILITY---------------------\n");
				printf("\t1.Check if link-list is sorted\n");
				printf("\t2.Make link-list sorted\n");
				printf("\t3.Check if in link-list there is dublicate element\n");
				printf("\t4.Remove deblicate element from link-list\n");
				printf("\t5.Reverse link-list\n");
				printf("\t6.Maximum element in the link-list\n");
				printf("\t7.Minimum element in the link-list\n");
				printf("\t8.Total nodes in the link-list except head\n");
				printf("\t9.Only search element and find POS\n");
				printf("\t10.Search an element and make it first node\n");
				printf("\t11.Search an element and make it closer to head\n");
				printf("\t12.Sum of all nodes values\n");
				printf("\t13.Back to main menu\n");
				printf("\t--------------------------------------------------\n");
			    printf("your choice ?\n");
			    scanf("%d",&choice1);
			    switch(choice1)
			    {
			    	case 1 :
			    		chk_sort();
			    		break;
			    	case 2 :
			    		sort();
			    		break;
			    	case 3 :
			    		
			    		break;
			    	case 4 :
			    		break;
			    	case 5 :
			    		break;
			    	case 6 :
			    		max();
			    		break;
			    	case 7 :
			    		min();
			    		break;
			    	case 8 :
			    		count();
			           	break;
			    	case 9 :
			    		search();
			    		break;
			    	case 10 :
			    		search_sort();
			    		break;
			    	case 11 :
			    		search_cng();
			    		break;
			    	case 12 :
			    		sum();
			    		break;
			    /*	case 8 :
			    		
			    		break;*/
			    	case 13 :
			    		break;
			    	default :
			    		printf("wrong choice,enter a valid choice\n");
				}
			    break;
			case 4 :
				display();
				break;
			case 5 :
				system("cls");
			    		break;
			case 6 :
				_Exit(10);
			    		break;
			 default :
			    		printf("wrong choice,enter a valid choice\n");   		
		}
	}
}
