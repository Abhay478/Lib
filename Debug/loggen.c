#include "debug.h"

void fn_call(char * name, char * function, int status)
{
    char * logname = calloc(strlen(name) + 5, sizeof(char));
    sprintf(logname, "%s.log", name);
    FILE * f = fopen(logname, "a+");
    char * ee = status?"Enter":"Exit";
    fprintf(f, "%s: %s [%s]\n", name, ee, function);
    fclose(f);
}

void note(char * name, int sort, void * text)
{
    char * logname = calloc(strlen(name) + 5, sizeof(char));
    sprintf(logname, "%s.log", name);
    FILE * f = fopen(logname, "a+");
    long * pair;
    char ** twins;
    switch(sort){
        case ARGS:
            fprintf(f, "args:\n%s\n", (char *)text);
            break;
        case HEAP:
            pair = (long *)text;
            fprintf(f, "Allocated %ld bytes at %p.\n", pair[0], pair[1]);
            break;
        // problem. Only pointers received, not data
        case SAMPLE:
            twins = (char **)text;
            fprintf(f, "Sampling %s = %s\n", twins[0], twins[1]);
            break;
        // problem. Only pointers received, not data
        case FLOW:
            twins = (char **)text;
            fprintf(f, "Entered branch %s -> arm %s\n", twins[0], twins[1]);
            break;
        case CHECKPOINT:
            fprintf(f, "Failure of call: %s\n", (char *)text);
            break;
        default: fprintf(f, "Unknown category: %s\n", (char *)text);
    }
    fclose(f);
    free(logname);
}

void * prepare_heap(int bytes, void * ptr)
{
    long * out = calloc(2, sizeof(void *));
    out[0] = bytes;
    out[1] = ptr;

    return (void *)out;
}

void * prepare_sample(char * var_name, void * value)
{
    char ** out = calloc(2, sizeof(void *));
    out[0] = var_name;
    out[1] = value;

    return (void *)out;
}

void * prepare_flow(char * branch, char * arm)
{
    char ** out = calloc(2, sizeof(void *));
    out[0] = branch;
    out[1] = arm;

    return (void *)out;
}

bool checkpoint(int val){
    if(val == -1){
        printf("%s\n", strerror(errno));
        return false;
    }
    else return true;
}

void clear(char * name)
{
    char * logname = calloc(strlen(name) + 5, sizeof(char));
    sprintf(logname, "%s.log", name);
    FILE * f = fopen(logname, "w");
    fclose(f);
}