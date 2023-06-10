#include "Debug/debug.h"
#include "OSAPI/osapi.h"

int main()
{
    int soc1 = makesock();
    bindsock(soc1, 11111, "127.0.0.1");

    // let's multithread this.
    int soc2 = othersock(soc1);
    char * name  = pullsock(soc2);
    pushsock(soc2, "Proceed.", 10);
    void * vp = pullsock(soc2);
    int kind = *(char *)vp - '0';
    pushsock(soc2, "Proceed.", 10);
    vp = pullsock(soc2);
    printf("%s\n", (char *)vp);
    switch(kind){
        case ARGS: note(name, ARGS, vp);
        break;
        case HEAP: note(name, HEAP, vp);
        break;
        case SAMPLE: note(name, SAMPLE, vp);
        break;
        case FLOW: note(name, FLOW, vp);
        break;
        case CHECKPOINT: note(name, CHECKPOINT, vp);
        break;
        default: break;
    }

}