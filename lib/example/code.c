#include <stdio.h>
#include <stdlib.h>

#include "../../utils/clu/header.h"
#include "../../utils/assert.h"

#include "debug.h"



#ifdef DEBUG

void example_debug()
{
    printf("\n\nThis function helps to debug");
    printf("\nbut it is not compiled in the final build");
    printf("\n");
}

#endif



void example_hello()
{
    printf("\nHello example library");
}

handler_p example_malloc()
{
    printf("\n\nHello malloc");

    return malloc(4);
}

void example_revert(bool revert)
{
    assert(!revert);
}