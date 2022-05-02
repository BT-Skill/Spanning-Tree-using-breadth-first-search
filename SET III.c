/*
 * C Program to Implement Queue Data Structure using Linked List
 */
#include <stdio.h>
#include <stdlib.h>
 
struct node
{
    int info;
    struct node *ptr;
}*front,*rear,*temp,*front1;
 
int frontelement();
void enq(int data);
void deq();
void empty();
void display();
void create();
void queuesize();
 
int count = 0;
 /*
 * Main Funcation 
 */
 
int main()
{
     create();
    while (1)
    {
    	int no, ch, e;
    	printf("\n");
printf("**************************************************");
    printf("\n Press 1 : Insert Element to Queue(Enqueue)");
    printf("\n Press 2 : Delete Element from Queue(Dqueue)");
    printf("\n Press 3 : Display Front Element");
    printf("\n Press 4 : Check Queue is Empty or NOT ");
    printf("\n Press 5 : Exit");
    printf("\n Press 6 : Display All Element in Queue");
    printf("\n Press 7 : Total Queue size\n");
printf("**************************************************");    
   
    
        printf("\n Enter choice : ");
        scanf("%d", &ch);
 printf("**************************************************"); 
 printf("\n");      
        switch (ch)
        {
        case 1:
            printf("Enter data : ");
            scanf("%d", &no);
            enq(no);
            break;
            
        case 2:
            deq();
            break;
        case 3:
            e = frontelement();
            if (e != 0)
                printf("Front element : %d", e);
            else
                printf("\n No front element in Queue as queue is empty\n\n");
            break;
        case 4:
            empty();
            break;
        case 5:
            exit(0);
        case 6:
        	printf("All Element in Queue : ");
            display();
            
			
            break;
        case 7:
            queuesize();
            break;
        default:
            printf("Wrong choice, Please enter correct choice  ");
            break;
        }
    }
    return 0;
}
 
/* Create an empty queue */
void create()
{
    front = rear = NULL;
}
 

/* Enqueing the queue */
void enq(int data)  // Enqueqe Funaction 
{
	printf("**************************************************");
	printf("\n");
    if (rear == NULL)
    {
        rear = (struct node *)malloc(1*sizeof(struct node));
        rear->ptr = NULL;
        rear->info = data;
        front = rear;
    }
    else
    {
        temp=(struct node *)malloc(1*sizeof(struct node));
        rear->ptr = temp;
        temp->info = data;
        temp->ptr = NULL;
 
        rear = temp;
    }
    count++;
}
 
 /* Dequeing the queue */
void deq() // DeQuque Function
{
	printf("**************************************************");
	printf("\n");
    front1 = front;
 
    if (front1 == NULL)
    {
        printf("\n Error: Trying to display elements from empty queue");
        return;
    }
    else
        if (front1->ptr != NULL)
        {
            front1 = front1->ptr;
            printf("\n Dequed value : %d", front->info);
            free(front);
            front = front1;
        }
        else
        {
            printf("\n Dequed value : %d", front->info);
            free(front);
            front = NULL;
            rear = NULL;
        }
        count--;
}


/* Returns the front element of queue */
int frontelement() //Front element Function
{
	printf("**************************************************");
	printf("\n");
    if ((front != NULL) && (rear != NULL))
        return(front->info);
    else
        return 0;
}

/* Display if queue is empty or not */
void empty() // Empty Function
{
	printf("**************************************************");
	printf("\n");
     if ((front == NULL) && (rear == NULL))
        printf("\n Queue empty");
    else
       printf("Queue not empty");
}

/* Displaying the queue elements */
void display() // Dispaly Function 
{

    front1 = front;
 
    if ((front1 == NULL) && (rear == NULL))
    {
        printf("Queue is empty");
        return;
    }
    while (front1 != rear)
    {
        printf("%d ", front1->info);
        front1 = front1->ptr;
    }
    if (front1 == rear)
        printf("%d", front1->info);
}
 

/* Returns queue size */
void queuesize() // Queue size Function
{
	printf("**************************************************");
	printf("\n");
    printf("\n Queue size : %d", count);
    printf("\n");
    printf("**************************************************"); 
    printf("\n");   
}
