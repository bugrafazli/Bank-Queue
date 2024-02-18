#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "queue.h"

struct queue *create(int capacity) 
{
struct queue* q = (struct queue*)malloc(sizeof(struct queue));
if(q == NULL){
    return NULL ;
}
q->capacity = capacity ;
q->front = -1;
q->rear = -1 ;
q->size = 0 ;
q->people = (struct person *)malloc(capacity * sizeof(struct person));
if (q->people == NULL) {
        free(q);
        return NULL;
    }
return q ;
}


bool is_full(struct queue *q) 
{
return q->size == q->capacity;
}


bool is_empty(struct queue *q) 
{
return q->front == -1 || q->rear == -1;
}

void add(struct queue *q, struct person k) 
{
        if (is_full(q)) {
        printf("Queue is full, failed to add person.\n");
        return;
    } else {
        if (is_empty(q)) {
            q->front = 0;
        }
        q->size++;
        q->rear++;
        q->people[q->rear] = k;
    }
}

struct person remove_person(struct queue *q) {
    struct person willremove;
    
    if (is_empty(q)) {
        printf("Queue is empty, cannot be removed.\n");
        return willremove;
    } 
    else {
        willremove = q->people[q->front];
        for (int i = q->front; i < q->rear; i++) {
            q->people[i] = q->people[i + 1];
        }
        q->rear--;
        q->size--;

        if (q->front > q->rear) {
            q->front = -1;
            q->rear = -1;
        }

        return willremove;
    }
}


void shift_all(struct queue *q) 
{
    if(is_empty(q)){
       printf("Queue is empty, cannot be shifted.\n");
       return ;
    }
    if(is_full(q)){
       printf("Queue is full, cannot be shifted.\n"); 
       return ;  
    }
        int i = q->rear;
        while (i >= q->front) {
            q->people[i + 1] = q->people[i];
            i--;
        }
        q->rear++;
        q->front++;

}


void add_customer(struct queue *q, struct person k) 
{
    if (is_full(q) || !k.isClient) {
    printf("Queue is full or the person is not a customer, failed to add person.\n");
    return;
    }
    else {
    shift_all(q);
    q->size++ ;
    q->people[q->front -1] = k ;
    q->front-- ;
    }
}


void display_all(struct queue *q) 
{
if(is_empty(q)){
   printf("Queue is empty.\n");
   return ;
}
printf("Queue Status:\n");
int i = q->front ;
for(;i<=q->rear;i++){
    printf("Is Client: %s, Money: %.2f\n", q->people[i].isClient ? "Yes" : "No", q->people[i].money);
}
}

