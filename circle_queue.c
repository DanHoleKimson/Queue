#include<stdio.h>
#include<stdlib.h>

#define MAX_Q_SIZE 10

typedef int element;

typedef struct CircualrQueue { //원형큐 배열
	element queue[MAX_Q_SIZE];
	int front, rear;
}Queue;

Queue* createQ() {
	Queue* Q = (Queue*)malloc(sizeof(Queue));
	Q->front = 0;
	Q->rear = 0;
	return Q;
}

int isFull(Queue* Q) {
	return (Q->rear + 1) % MAX_Q_SIZE == Q->front;
}

int isEmpty(Queue* Q) {
	return Q->front == Q->rear;
}

void enqueue(Queue* Q, element x) {
	if (isFull(Q)) {
		printf("Queue is FULL\n");
	}
	else {
		Q->rear = (Q->rear + 1) % MAX_Q_SIZE;
		Q->queue[Q->rear] = x;
	}
}

element dequeue(Queue* Q) {
	if (isEmpty(Q)) {
		printf("Queue is EMPTY\n");
	}
	else {
		Q->front = (Q->front + 1) % MAX_Q_SIZE;
		return Q->queue[Q->front];
	}
}

element peek(Queue* Q) {
	if (isEmpty(Q)) {
		printf("Queue is EMPTY\n");
	}
	else {
		return Q->queue[(Q->front + 1) % MAX_Q_SIZE];
	}
}

void printqueue(Queue* Q) {
	int i = Q->front;
	int j = Q->rear;
	while ((i + 1) % MAX_Q_SIZE != (j + 1) % MAX_Q_SIZE) {
		i = (i + 1) % MAX_Q_SIZE;
		printf("-> [ %d ] ", Q->queue[i]);
	}
	printf("-> \n");
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
	enqueue(Q, 60);
	enqueue(Q, 70);
	enqueue(Q, 80);
	enqueue(Q, 90);
	printqueue(Q);

	int a = dequeue(Q);
	printf("%d is out\n", a);

	int b = dequeue(Q);
	printf("%d is out\n", b);

	printqueue(Q);

	enqueue(Q, 25);
	enqueue(Q, 35);
	printqueue(Q);
	enqueue(Q, 45);

	int c = dequeue(Q);
	printf("%d is out\n", c);
	int d = dequeue(Q);
	printf("%d is out\n", d);
	int e = dequeue(Q);
	printf("%d is out\n", e);
	int f = dequeue(Q);
	printf("%d is out\n", f);
	int g = dequeue(Q);
	printf("%d is out\n", g);

	printqueue(Q);

	int h = dequeue(Q);
	printf("%d is out\n", h);
	int i = dequeue(Q);
	printf("%d is out\n", i);
	int j = dequeue(Q);
	printf("%d is out\n", j);
	int k = dequeue(Q);
	printf("%d is out\n", k);
	printqueue(Q);
	int l = dequeue(Q);

	return 0;
}