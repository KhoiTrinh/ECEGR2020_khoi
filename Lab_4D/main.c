#include <stdio.h>
#include <stdlib.h>

// Data structure to represent a queue
typedef struct Queue
{
	float items;
	struct Queue* next;
} Queue;

Queue* headNode = NULL;
// Utility function to initialize the queue
Queue* newQueue(float in)
{
    Queue* newQ = (Queue*)malloc(sizeof(Queue));
	
	if (newQ != NULL)
	{
		newQ->items = in;
		newQ->next = NULL;
	}
 
    return newQ;
}
 
// Utility function to return the size of the queue
int size() 
{
	Queue* node = headNode;
	int count = 0;
	while(node != NULL)
	{
		count++;
		node = node->next;
	}
    return count;
}
 
// Utility function to check if the queue is empty or not
int isEmpty() {
    return (headNode == NULL);       
}
 
// Utility function to check if the queue is full or not
int isFull() {
    return (malloc(sizeof(Queue)) == NULL);  
}
 
// Utility function to add an element `x` to the queue
int insert(float x)
{
    // check if the queue is already full
    if (isFull())
    {
        printf("Queue Full!\n");
        return -1;
    }
	
	Queue* newNode = newQueue(x);
 
    printf("Inserting %f\n", x);
 
    // add an element to queue
	if(headNode == NULL)
	{
		headNode = newNode;
		return 0;
	}
	Queue* currentNode = headNode;
	while(currentNode->next != NULL)
	{
		currentNode = currentNode->next;
	}
	currentNode->next = newNode;
	newNode->next = NULL;
    
    return 0;
}
 
// Utility function to remove an element from the queue
int removeQueue()
{
    // check for queue underflow
    if (isEmpty())
    {
        printf("Queue Empty!\n");
        return -1;
    }
 
    // remove element decrement queue size by 1
    printf("Removing %f\n", headNode->items);
	Queue* temp = headNode;
	headNode = headNode->next;
	free(temp);
	
    return 0;
}
 
// Utility function to peek at first element from the queue
int peek(float* x)
{
    // check for queue underflow
    if (isEmpty())
    {
        printf("Queue Empty!\n");
        return -1;
    }
 
    // return front of queue value
    *x = headNode->items;
    return 0;
}
 
int main()
{
    // create a queue of capacity 5
    float  value;
 
    insert(1.0);
    insert(2.0);
    insert(3.0);
 
    printf("The queue size is %d\n", size());

    peek(&value);
    printf("Top val on queue is %f\n", value);

    removeQueue();
    removeQueue();
    removeQueue();
 
    if (isEmpty()) {
        printf("The queue is empty\n");
    }
    else {
        printf("The queue is not empty\n");
    }
 
    return 0;
}
