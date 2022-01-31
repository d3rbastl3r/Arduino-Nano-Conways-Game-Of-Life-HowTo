#include <unity.h>
#include <stdint.h>

#include "GameOfLife.cpp"

void GameOfLifeConstructor_should_set_visual_data_ptr_correctly() {
    // given
    uint8_t colorPos = 0;
    uint8_t data[3][16][16/8] = {};

    // when
    GameOfLife<16, 16> gameOfLife(data[colorPos]);
    data[colorPos][2][1] = 0b00110011;

    // then
    TEST_ASSERT_EQUAL(gameOfLife.visualData[2][1], data[colorPos][2][1]);
}

void getVisualDataBit_should_return_bit_from_given_position() {
    // given
    uint8_t colorPos = 0;
    uint8_t data[3][16][16/8] = {};
    data[colorPos][2][0] = 0b00110011;
    data[colorPos][3][1] = 0b11001100;
    GameOfLife<16, 16> gameOfLife(data[colorPos]);

    // when
    bool result1 = gameOfLife.getVisualDataBit(2, 2);
    bool result2 = gameOfLife.getVisualDataBit(2, 4);
    bool result3 = gameOfLife.getVisualDataBit(3, 12);

    // then
    TEST_ASSERT_EQUAL(result1, 1);
    TEST_ASSERT_EQUAL(result2, 0);
    TEST_ASSERT_EQUAL(result3, 1);
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

void countNeighbors_should_return_amount_of_neighbors_from_center_pos() {
    // given
    uint8_t data[8][1] = {
        {0b01010000},
        {0b00000100},
        {0b00101000},
        {0b01001000},
        {0b00010000},
        {0b01000000},
        {0b00001000},
        {0b01000000}
    };
    GameOfLife<8, 8> gameOfLife(data);

    // when
    uint8_t neighborsResult = gameOfLife.countNeighbors(3, 3);

    // then
    TEST_ASSERT_EQUAL(neighborsResult, 4);
}

void countNeighbors_should_return_amount_of_neighbors_from_n_pos() {
    // given
    uint8_t data[8][1] = {
        {0b01010000},
        {0b00000100},
        {0b00101000},
        {0b01001000},
        {0b00010000},
        {0b01000000},
        {0b00001000},
        {0b01001000}
    };
    GameOfLife<8, 8> gameOfLife(data);

    // when
    uint8_t neighborsResult = gameOfLife.countNeighbors(0, 3);

    // then
    TEST_ASSERT_EQUAL(neighborsResult, 1);
}

void countNeighbors_should_return_amount_of_neighbors_from_e_pos() {
    // given
    uint8_t data[8][1] = {
        {0b01010000},
        {0b10000100},
        {0b10101000},
        {0b01001001},
        {0b00010000},
        {0b01000000},
        {0b00001000},
        {0b01001000}
    };
    GameOfLife<8, 8> gameOfLife(data);

    // when
    uint8_t neighborsResult = gameOfLife.countNeighbors(2, 7);

    // then
    TEST_ASSERT_EQUAL(neighborsResult, 3);
}

void countNeighbors_should_return_amount_of_neighbors_from_s_pos() {
    // given
    uint8_t data[8][1] = {
        {0b01010000},
        {0b10000100},
        {0b10101000},
        {0b01001001},
        {0b00010000},
        {0b01000000},
        {0b00001000},
        {0b01001000}
    };
    GameOfLife<8, 8> gameOfLife(data);

    // when
    uint8_t neighborsResult = gameOfLife.countNeighbors(7, 2);

    // then
    TEST_ASSERT_EQUAL(neighborsResult, 3);
}

void countNeighbors_should_return_amount_of_neighbors_from_w_pos() {
    // given
    uint8_t data[8][1] = {
        {0b01010000},
        {0b10000100},
        {0b10101000},
        {0b01001001},
        {0b00010000},
        {0b01000000},
        {0b00001000},
        {0b01001000}
    };
    GameOfLife<8, 8> gameOfLife(data);

    // when
    uint8_t neighborsResult = gameOfLife.countNeighbors(3, 0);

    // then
    TEST_ASSERT_EQUAL(neighborsResult, 3);
}

void countNeighbors_should_return_amount_of_neighbors_from_ne_pos() {
    // given
    uint8_t data[8][1] = {
        {0b01010010},
        {0b10000100},
        {0b10101000},
        {0b01001001},
        {0b00010000},
        {0b01000000},
        {0b00001000},
        {0b01001001}
    };
    GameOfLife<8, 8> gameOfLife(data);

    // when
    uint8_t neighborsResult = gameOfLife.countNeighbors(0, 7);

    // then
    TEST_ASSERT_EQUAL(neighborsResult, 3);
}

void countNeighbors_should_return_amount_of_neighbors_from_se_pos() {
    // given
    uint8_t data[8][1] = {
        {0b01010010},
        {0b10000100},
        {0b10101000},
        {0b01001001},
        {0b00010000},
        {0b01000000},
        {0b00001000},
        {0b01001001}
    };
    GameOfLife<8, 8> gameOfLife(data);

    // when
    uint8_t neighborsResult = gameOfLife.countNeighbors(7, 7);

    // then
    TEST_ASSERT_EQUAL(neighborsResult, 1);
}

void countNeighbors_should_return_amount_of_neighbors_from_nw_pos() {
    // given
    uint8_t data[8][1] = {
        {0b01010010},
        {0b10000100},
        {0b10101000},
        {0b01001001},
        {0b00010000},
        {0b01000000},
        {0b00001000},
        {0b01001001}
    };
    GameOfLife<8, 8> gameOfLife(data);

    // when
    uint8_t neighborsResult = gameOfLife.countNeighbors(0, 0);

    // then
    TEST_ASSERT_EQUAL(neighborsResult, 4);
}

void countNeighbors_should_return_amount_of_neighbors_from_sw_pos() {
    // given
    uint8_t data[8][1] = {
        {0b01010010},
        {0b10000100},
        {0b10101000},
        {0b01001001},
        {0b00010000},
        {0b01000000},
        {0b00001000},
        {0b01001001}
    };
    GameOfLife<8, 8> gameOfLife(data);

    // when
    uint8_t neighborsResult = gameOfLife.countNeighbors(7, 0);

    // then
    TEST_ASSERT_EQUAL(neighborsResult, 3);
}

int main(int argc, char **argv) {
    UNITY_BEGIN();

    RUN_TEST(GameOfLifeConstructor_should_set_visual_data_ptr_correctly);

    RUN_TEST(getVisualDataBit_should_return_bit_from_given_position);

    RUN_TEST(setNextGenBit_should_set_given_value_on_the_given_position);

    RUN_TEST(countNeighbors_should_return_amount_of_neighbors_from_center_pos);
    RUN_TEST(countNeighbors_should_return_amount_of_neighbors_from_n_pos);
    RUN_TEST(countNeighbors_should_return_amount_of_neighbors_from_e_pos);
    RUN_TEST(countNeighbors_should_return_amount_of_neighbors_from_s_pos);
    RUN_TEST(countNeighbors_should_return_amount_of_neighbors_from_w_pos);
    RUN_TEST(countNeighbors_should_return_amount_of_neighbors_from_ne_pos);
    RUN_TEST(countNeighbors_should_return_amount_of_neighbors_from_se_pos);
    RUN_TEST(countNeighbors_should_return_amount_of_neighbors_from_nw_pos);
    RUN_TEST(countNeighbors_should_return_amount_of_neighbors_from_sw_pos);
    
    UNITY_END();

    return 0;
}