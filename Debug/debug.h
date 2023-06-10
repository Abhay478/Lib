#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <errno.h>

bool checkpoint(int val);

#define ARGS 0
#define HEAP 1
#define SAMPLE 2
#define FLOW 3
#define CHECKPOINT 4

void trace(char * name, char * function, int status);
void note(char * name, int sort, void * text);
void * prepare_heap(int bytes, void * ptr);
void * prepare_sample(char * var_name, void * value);
void * prepare_flow(char * branch, char * arm);
void clear(char * name);