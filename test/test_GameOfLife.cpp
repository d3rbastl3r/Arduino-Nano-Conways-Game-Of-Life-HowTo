#include <unity.h>
#include <stdint.h>

#include "GameOfLife.cpp"

void test_getNumber_should_return_number_seven() {
    // given
    GameOfLife gameOfLife;

    // when
    uint8_t result = gameOfLife.getNumber();

    // then
    TEST_ASSERT_EQUAL(result, 7);
}

int main(int argc, char **argv) {
    UNITY_BEGIN();

    RUN_TEST(test_getNumber_should_return_number_seven);
    
    UNITY_END();

    return 0;
}