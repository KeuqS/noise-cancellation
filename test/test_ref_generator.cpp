#include "anc/ref_generator.hpp"
#include "unity.h"

void setUp() {}
void tearDown() {}

namespace {

void test_first_sample_starts_at_zero_phase() {
    anc::RefGenerator generator(8000.0f);
    float sinSample = 0.0f;
    float cosSample = 0.0f;

    generator.next(sinSample, cosSample);

    TEST_ASSERT_FLOAT_WITHIN(1e-6f, 0.0f, sinSample);
    TEST_ASSERT_FLOAT_WITHIN(1e-6f, 1.0f, cosSample);
}

}  // namespace

int main() {
    UNITY_BEGIN();
    RUN_TEST(test_first_sample_starts_at_zero_phase);
    return UNITY_END();
}
