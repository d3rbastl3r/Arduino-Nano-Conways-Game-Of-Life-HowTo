#include <unity.h>
#include <stdint.h>

#include "GameOfLife.cpp"

void setNextGenBit_should_set_given_value_on_the_given_position() {
    // given
    GameOfLife gameOfLife;
    gameOfLife.nextGenData[0][0] = 0b00110011;

    // when
    gameOfLife.setNextGenBit(0, 0, 1);
    gameOfLife.setNextGenBit(0, 1, 0);
    gameOfLife.setNextGenBit(0, 2, 1);
    gameOfLife.setNextGenBit(0, 3, 0);
    gameOfLife.setNextGenBit(0, 4, 1);
    gameOfLife.setNextGenBit(0, 5, 0);
    gameOfLife.setNextGenBit(0, 6, 1);
    gameOfLife.setNextGenBit(0, 7, 0);

    // then
    TEST_ASSERT_EQUAL(gameOfLife.nextGenData[0][0], 0b10101010);
}

int main(int argc, char **argv) {
    UNITY_BEGIN();

    RUN_TEST(setNextGenBit_should_set_given_value_on_the_given_position);
    
    UNITY_END();

    return 0;
}