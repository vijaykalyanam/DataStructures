#include "queue_array_headers.h"

static bool queueFull(struct queue *q)
{
	if ((q->rear == -1 && q->front == q->size-1) ||
			q->front+1 == q->rear ||
			(q->front == q->size-1 && q->rear == 0))
		return true;
	return false;
}

static int enqueue(struct queue *q, int data)
{
	if (queueFull(q)) {
		printf("Queue Full\n");
		return -1;
	}
	printf("Front :%d Rear :%d size :%d\n", q->front, q->rear, q->size);
	/* This where some error prone, front should point to the next new node. Rear should point to current node. */
	/* Initialize front = 0 and rear to -1 */
//	if (q->front == -1)
//		q->rear++;
	if (q->front == -1) {
		q->rear = 0;
		q->front = 0;
	}

	q->data[q->front] = data;

	if (q->front == q->size-1)
		q->front == 0;
	else
		q->front++;
}

static bool queueEmpty(struct queue *q)
{
	return (q->front == 0 && q->rear == q->size -1) || q->rear == q->front || q->front == -1;
}

static int dequeue(struct queue *q)
{
	int data;
	printf("Front :%d Rear :%d size :%d\n", q->front, q->rear, q->size);
	if (!queueEmpty(q)) {
		//return q->data[q->rear--];
		data = q->data[q->rear];
		if (q->rear == q->size-1)
			q->rear = 0; 
		else
			q->rear++;
		return data;
	}
	return -1;
}

static void list(struct queue *q)
{
	int i;
	if (!queueEmpty(q)) {
		i = q->front;
		while (i != q->rear) {
			printf("%d ", q->data[i]);
			i--;
		}
	}
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

                        case 1: ring = createQueue(&q, 128);
				if (ring != -1) {
					printf("Queue of Size %d created with ID :%d\n", 128, ring);
					printf("Front :%d Rear :%d size :%d\n", q->front, q->rear, q->size);
				} else {
					printf("Queue Creation Failed\n");
					break;
				}
				break;
			case 2: destroyQueue(ring); break;
			case 3: printf("Enter data to Enqueue:");
				scanf("%d",&data);
				enqueue(q, data);	
				break;
                        case 4: printf("Dequeue %d\n",dequeue(q)); break;
                                break;
                        case 5: list(q); break; 
                        case 6: if (queueEmpty(q))
                                        printf("Queue is Empty\n");
                                else
                                        printf("Quueue is Not Empty\n");
                                break;
                        case 7: if (queueFull(q))
                                        printf("Queue is Full\n");
                                else
                                        printf("Queue is not Full\n");
                                break;
                        default: return 0;
                }
        } while(1);
}


