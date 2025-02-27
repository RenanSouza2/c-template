#include "../debug.h"
#include "../../../utils/assert.h"
#include "../../../utils/clu/header.h"



void test_hello(bool show)
{
    char offset[] = "\t";
    printf("\n%s%s\t\t", offset, __func__);

    printf("\n%s\t%s 1\t\t", offset, __func__);
    hello_debug();

    printf("\n%s\t%s 2\t\t", offset, __func__);
    hello_example();
}

void test_malloc(bool show)
{
    char offset[] = "\t";
    printf("\n%s%s", offset, __func__);

    printf("\n%s\t%s 1\t\t", offset, __func__);
    handler_p h = hello_malloc();

    // Uncomment next line to see the assertion fail
    // assert(clu_mem_empty());

    printf("\n%s\t%s 2\t\t", offset, __func__);
    printf("\nThis prints the current allocated pointers");
    printf("\n");
    clu_mem_report("TAG");

    free(h);

    assert(clu_mem_empty());
}

void test_example()
{
    printf("\n%s", __func__);

    bool show = true;

    test_hello(show);
    test_malloc(show);

    assert(clu_mem_empty());
}


int main()
{
    setbuf(stdout, NULL);
    test_example();
    printf("\n\n\tTest successful\n\n");
    return 0;
}
