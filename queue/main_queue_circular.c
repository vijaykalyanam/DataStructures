#include "queue_circular_headers.h"

#define IsQueueFull(__q)	((__q) ? (__q->head->link == __q->tail) : (0))
#define IsQueueEmpty(__q)	((__q) ? (__q->head == __q->tail) : (0))

static int enqueue(struct queue *q, int data)
{
	if (IsQueueFull(q)) {
		printf("Queue Full\n");
		return -1;
	}
	q->head->data = data;
	q->head = q->head->link;
}

static int dequeue(struct queue *q)
{
	int data;
	if (!IsQueueEmpty(q)) {
		data = q->tail->data;
		q->tail = q->tail->link;
		return data;
	}
	return -1;
}

static void list(struct queue *q)
{
}

int main(int argc, char **argp)
{
    
        unsigned int op;
        int data;

	struct queue *q = NULL;
	unsigned int ring =-1;

        do {     
                printf("\n1.Create 2.Destroy 3.Enqueue 4.Dequeue 5.List 6.isEmpty 7.isFull\n");
                scanf("%d", &op);
 
                switch(op) {

                        case 1: ring = createQueue(&q, 8);
				if (ring = -1) {
					printf("Queue Creation Failed\n");
				}
				break;
			//case 2: destroyQueue(ring); break;
			case 3: printf("Enter data to Enqueue:");
				scanf("%d",&data);
				enqueue(q, data);	
				break;
                        case 4: printf("Dequeue %d\n",dequeue(q)); break;
                                break;
                        case 5: display(q); break; 
                        case 6: if (IsQueueEmpty(q))
                                        printf("Queue is Empty\n");
                                else
                                        printf("Quueue is Not Empty\n");
                                break;
                        case 7: if (IsQueueFull(q))
                                        printf("Queue is Full\n");
                                else
                                        printf("Queue is not Full\n");
                                break;
                        default: return 0;
                }
        } while(1);
}


