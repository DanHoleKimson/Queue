#include<stdio.h>
#include<stdlib.h>


typedef int element;

typedef struct QueueNode { //¿¬°áÅ¥
	element data;
	struct QueueNode* link;
}queueNode;

typedef struct LinkedQueue {
	queueNode* front, * rear;
}Queue;

Queue* createQ() {
	Queue* Q = (Queue*)malloc(sizeof(Queue));
	Q->front = NULL;
	Q->rear = NULL;
	return Q;
}



int isEmpty(Queue* Q) {
	return Q->front == NULL;
}

void enqueue(Queue* Q, element x) {
	queueNode* newQueue = (queueNode*)malloc(sizeof(queueNode));
	newQueue->data = x;
	newQueue->link = NULL;

	if (isEmpty(Q)) {
		Q->front = newQueue;
	}
	else {
		Q->rear->link = newQueue;
	}
	Q->rear = newQueue;
}

element dequeue(Queue* Q) {
	queueNode* temp;
	element e;

	if (isEmpty(Q)) {
		printf("[ERROR] Queue is EMPTY!!\n");
		return 0;
	}
	else {
		temp = Q->front;
		e = temp->data;
		Q->front = temp->link;
		free(temp);
		if (Q->front == NULL)
			Q->rear = NULL;
		return e;
	}

}

element peek(Queue* Q) {
	if (isEmpty(Q)) {
		printf("[ERROR] Queue is EMPTY!!\n");
		return 0;
	}
	else {
		return  Q->front->data;
	}
}

void printqueue(Queue* Q) {
	queueNode* temp;
	temp = Q->front;
	while (temp != Q->rear) {
		printf("[ %d ] -> ", temp->data);
		temp = temp->link;
	}
	printf("\n");
}


int main(void) {

	Queue q, * Q;
	Q = &q;
	Q = createQ();
	enqueue(Q, 10);
	enqueue(Q, 20);
	enqueue(Q, 30);
	enqueue(Q, 40);
	enqueue(Q, 50);
	printqueue(Q);

	int a;
	a = dequeue(Q);
	printqueue(Q);
	printf("%d is out!!\n", a);

	return 0;
}