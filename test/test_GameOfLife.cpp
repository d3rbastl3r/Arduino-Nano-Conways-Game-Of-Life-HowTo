#include <unity.h>
#include <stdint.h>

#include "GameOfLife.cpp"

void GameOfLifeConstructor_should_set_visual_data_ptr_correctly() {
    // given
    uint8_t data[3][16][16/8] = {};

    // when
    GameOfLife<16, 16> gameOfLife(data[0]);
    data[0][2][1] = 0b00110011;

    // then
    TEST_ASSERT_EQUAL(gameOfLife.visualData[2][1], data[0][2][1]);
}

void setNextGenBit_should_set_given_value_on_the_given_position() {
    // given
    GameOfLife<> gameOfLife(nullptr);
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

    RUN_TEST(GameOfLifeConstructor_should_set_visual_data_ptr_correctly);

    RUN_TEST(setNextGenBit_should_set_given_value_on_the_given_position);
    
    UNITY_END();

    return 0;
}