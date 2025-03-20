
#include "../debug.h"
#include "../../../utils/U64.h"
#include "../../../utils/assert.h"
#include "../../../utils/test_revert.h"
#include "../../../utils/clu/header.h"



void test_example_hello(bool show)
{
    printf("\n\t%s\t\t", __func__);

    if(show) printf("\n\t\t%s 1\t\t", __func__);
    example_debug();

    if(show) printf("\n\t\t%s 2\t\t", __func__);
    example_hello();
}

void test_example_malloc(bool show)
{
    printf("\n\t%s", __func__);

    if(show) printf("\n\t\t%s 1\t\t", __func__);
    handler_p h = example_malloc();

    /* Uncomment next line to see the assertion fail */
    // assert(clu_mem_empty());

    if(show) printf("\n\t\t%s 2\t\t", __func__);
    printf("\n\nThis prints the current allocated pointers in short form\n");
    clu_mem_report("TAG");

    if(show) printf("\n\t\t%s 3\t\t", __func__);
    printf("\n\nThis prints the current allocated pointers in long form\n");
    clu_mem_report_full("TAG");

    if(show) printf("\n\t\t%s 4\t\t", __func__);
    printf("\n\nThis prints the current allocated pointers in long form\n");
    clu_mem_report_full("TAG");

    if(show) printf("\n\t\t%s 5\t\t", __func__);
    uint64_t i_max = clu_get_max_i();
    printf("\n\nThis is the number of different tags still allocated: %lu\n", i_max);

    if(show) printf("\n\t\t%s 6\t\t", __func__);
    uint64_t j_max = clu_get_max_j(0);
    printf("\n\nThis is the number of pointers still allocated in the first tag: %lu\n", j_max);

    if(show) printf("\n\t\t%s 7\t\t", __func__);
    handler_p h_leaked = clu_get_handler(0, 0);
    printf("\n\nThis is the handler still alocated in corrdinates (0, 0): %p", h_leaked);
    printf("\nand the content of the pointer: %lx\n", *(uint64_t*)h_leaked);

    if(show) printf("\n\t\t%s h\t\t", __func__);
    printf("\n\nThis tests if a given pointer is not dangling");
    CLU_IS_SAFE(h);
    printf("\nCan be used anywhere in the code");
    printf("\nOnly adds overhead if compiled in debug mode");

    free(h);

    /* Uncomment next line to see the assertion fail */
    // CLU_IS_SAFE(h);

    assert(clu_mem_empty());
}

void test_example_revert(bool show)
{
    printf("\n\t%s", __func__);

    if(show) printf("\n\t\t%s 1\t\t", __func__);
    example_revert(false);

    if(show) printf("\n\t\t%s 2\t\t", __func__);
    TEST_REVERT_OPEN
    example_revert(true);
    TEST_REVERT_CLOSE

    if(show) printf("\n\t\t%s 3\t\t", __func__);
    uint64_t *a = NULL;
    TEST_REVERT_OPEN
    *a = 1;
    TEST_REVERT_CLOSE

    assert(clu_mem_empty());
} 



void test_example()
{
    printf("\n%s", __func__);

    bool show = true;

    test_example_hello(show);
    test_example_malloc(show);
    test_example_revert(show);

    assert(clu_mem_empty());
}



int main()
{
    setbuf(stdout, NULL);
    test_example();
    printf("\n\n\tTest successful\n\n");
    return 0;
}
