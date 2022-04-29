#include <sstream>
#include "word_count.h"
#include "test.h"


static int test_status = EXIT_SUCCESS;
static int test_count = 0;
static int test_passed = 0;


void
test_reduce_report() {
    int* origin;
    int* report;

    auto ss = std::istringstream("The quick brown fox jumps over the lazy dog.\n\n");
    characters_from_stream(ss, origin);
    reduce_report(report, origin);

    EXPECT_EQ_INT(3, report['e' - base_alpha]);
    EXPECT_EQ_INT(100, report['e' - base_alpha]);  // Failure
}



int
main() {
    
    test_reduce_report();

    printf("%d/%d (%3.2f%%) passed\n", test_passed, test_count, test_passed * 100.0 / test_count);

    return test_status;
}
