#ifndef __QUEQE_H__
#define __QUEUE_H__




struct Queue {
	char** element;
	int size;	/*	size_t used because size and count cant be < 0*/
	int count;
};

typedef struct Queue Queue;

struct activation_stask
{
	char * name;
	int offset;
	Queue q;
};

struct activation_stask as[999];



void queue_init(Queue* queue)
{
	queue->element = NULL;
	queue->size = 0;
	queue->count = 0;
}

void queue_push(Queue* queue, const char* str)
{
	if (queue->size == 0) {
		queue->size = 20;
		queue->element = (char**)malloc(sizeof(char*) * queue->size);
		int i = 0;
		for (; i < queue->size; i++)
			queue->element[i] = (char*) malloc(256 * sizeof(char));
	}
 
	if (queue->size == queue->count) {
		queue->size *= 2;
		queue->element = (char**)realloc(queue->element, sizeof(char*) * queue->size);
		int i = queue->size/2;
		for (; i < queue->size; i++)
			queue->element[i] = (char*) malloc(256 * sizeof(char));
	}

	strcpy(queue->element[queue->count], str);
	queue->count++;
}

char* queue_pop(Queue* queue)
{
	if (queue->count > 0) {
		char* top = queue->element[queue->count - 1];
		queue->count--;
		return top;
	}
	
	return 0;
}

char* queue_top(Queue* queue)
{
	if (queue->count > 0) {
		return queue->element[queue->count - 1];
	}
 
	return 0;
}
 


void queue_free(Queue* queue)
{
	free(queue->element);
}



void activate(char *name, int arg)
{
arg--;
as[arg].name = name;
as[arg].offset = arg;
queue_init(&as[arg].q);
}
void deactivate(int arg)
{
arg--;
queue_free(&as[arg].q);
}

void add_para_to_as(int arg, char *para)
{
arg--;
queue_push(&as[arg].q, para);
}

#endif
