
#include "../debug.h"
#include "../../../utils/U64.h"
#include "../../../utils/assert.h"
#include "../../../utils/test_revert.h"
#include "../../../utils/clu/header.h"



void test_example_hello(bool show)
{
    printf("\n\t%s\t\t", __func__);

    printf("\n\t\t%s 1\t\t", __func__);
    example_debug();

    printf("\n\t\t%s 2\t\t", __func__);
    example_hello();
}

void test_example_malloc(bool show)
{
    printf("\n\t%s", __func__);

    printf("\n\t\t%s 1\t\t", __func__);
    handler_p h = example_malloc();

    /* Uncomment next line to see the assertion fail */
    // assert(clu_mem_empty());

    printf("\n\t\t%s 2\t\t", __func__);
    printf("\nThis prints the current allocated pointers");
    printf("\n");
    clu_mem_report("TAG");

    free(h);

    assert(clu_mem_empty());
}

void test_example_revert(bool show)
{
    printf("\n\t%s", __func__);

    printf("\n\t\t%s 1\t\t", __func__);
    example_revert(false);

    printf("\n\t\t%s 2\t\t", __func__);
    TEST_REVERT_OPEN
    example_revert(true);
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
