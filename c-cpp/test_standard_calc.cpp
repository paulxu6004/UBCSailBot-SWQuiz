#include "stdio.h"
#include "cutest/CuTest.h"
#include "standard_calc.h"

/**************** Tests for bound_to_180() *******************/
void test_bound_basic1(CuTest *tc) {
    CuAssertDblEquals(tc, 0, bound_to_180(0), 0.0001);
}

void test_bound_normal(CuTest *tc) {
    CuAssertDblEquals(tc, 90.0, bound_to_180(90.0), 0.0001);
}

void test_bound_over_180(CuTest *tc) {
    CuAssertDblEquals(tc, -160.0, bound_to_180(200.0), 0.0001);
}

void test_bound_under_minus_180(CuTest *tc) {
    CuAssertDblEquals(tc, 160.0, bound_to_180(-200.0), 0.0001);
}

/**************** Tests for is_angle_between() *******************/
void test_between_basic1(CuTest *tc) {
    CuAssertTrue(tc, is_angle_between(0, 1, 2));
}

void test_between_true(CuTest *tc) {
    CuAssertTrue(tc, is_angle_between(0.0, 1.0, 2.0));
}

void test_between_false(CuTest *tc) {
    CuAssertTrue(tc, !is_angle_between(0.0, 3.0, 2.0));
}

void test_between_wrap(CuTest *tc) {
    CuAssertTrue(tc, is_angle_between(170.0, 180.0, -170.0));
}


int main(int argc, char const *argv[]) {
    CuString *output = CuStringNew();
    CuSuite *suite = CuSuiteNew();

    SUITE_ADD_TEST(suite, test_bound_basic1);
    SUITE_ADD_TEST(suite, test_between_basic1);

    CuSuiteRun(suite);
    CuSuiteSummary(suite, output);
    CuSuiteDetails(suite, output);
    printf("%s\n", output->buffer);

    return suite->failCount > 0 ? 1 : 0;
}
