#include "Debug/debug.h"
#include "OSAPI/osapi.h"

int main()
{
    int soc1 = makesock();
    connectsock(soc1, 11111, "127.0.0.1");

    pushsock(soc1, __FILE__, strlen(__FILE__));
    char * proceed = pullsock(soc1);
    printf("%s\n", proceed);

    // char * args = "q = 1\nr = 2\ns = 3\n";
    // pushsock(soc1, "0", 1);
    // proceed = pullsock(soc1); 
    // pushsock(soc1, args, strlen(args));

    // void * p = calloc(1, sizeof(int));
    // long text[] = {5, (long)p};
    // pushsock(soc1, "1", 1);
    // proceed = pullsock(soc1); 
    // pushsock(soc1, text, 20);

    int samp = 10;
    pushsock(soc1, "2", 1);
    char * name = "samp";
    char * value = "10";

    // passes only pointers, not data.
    char * text[] = {name, value};
    pushsock(soc1, text, 20);

    // printf("%s\n", __FILE__);

}