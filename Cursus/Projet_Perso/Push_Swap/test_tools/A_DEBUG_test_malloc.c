#include <stdlib.h>

void *test_malloc(size_t size) 
{
    static int call = 0;
    call++;
    
    if (call == 12)
        return NULL;
    return malloc(size);
}