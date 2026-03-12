#include "queue.h"
#include <stdlib.h>
#include <stdio.h>

Queue *queue_create(void)
{
  Queue *queue = malloc(sizeof(Queue));
  if (queue == NULL) {
    return NULL;
  }
  queue->size = 0;
  queue->capacity = QUEUE_INITIAL_CAPACITY;
  queue->data = malloc(sizeof(double) * queue->capacity);
  if (queue->data == NULL) {
    free(queue);
    return NULL;
  }
  return queue;
}

void push(Queue *queue, double element)
{
  if (queue==NULL)
    perror("invalid input!");
  if (queue->size == queue->capacity)
  {
    int capacity = queue->capacity * 2;

    double *data1 = realloc(queue->data, sizeof(double) * capacity);
    if (data1 == NULL) {
      printf("false");
      return;
  }
    queue->data=data1;
    queue->capacity = capacity;
  }

  int insert_index = queue->size % queue->capacity;
  queue->data[insert_index] = element;
  queue->size++;
}

double back(Queue *queue)
{
  if (queue==NULL)
    perror("invalid input!");
  if (queue->size==0)
    perror("visit empty queue!");
  return queue->data[queue->size - 1];
}

void queue_free(Queue *queue)
{
  if (queue==NULL)
    perror("invalid input!");
  free(queue->data);
  free(queue);
}

