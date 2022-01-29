#ifndef __GAME_OF_LIFE__
#define __GAME_OF_LIFE__

#include <stdint.h>

template <uint8_t ROWS=32, uint8_t COLUMNS=64>
class GameOfLife {

    public:
    // Pointer to the data which should be rendered on the display
    uint8_t (*visualData)[COLUMNS/8] = nullptr;

    // Temporary data for the next generation calculation
    uint8_t nextGenData[ROWS][COLUMNS/8] = {};

    GameOfLife(uint8_t (*visualData)[COLUMNS/8]) {
        this->visualData = visualData;
    }

    /**
     * Returns single bit from visual data array on a given position
     * 
     * @param yPos row position of the bit
     * @param xPos column position of the bit
     */
    bool getVisualDataBit(uint8_t yPos, uint8_t xPos) {
        uint8_t xBytePos = xPos / 8;
        uint8_t xBit = xPos % 8;

        return visualData[yPos][xBytePos] & (128 >> xBit);
    }

    /**
     * Set the bit on a given position to given value
     * 
     * @param yPos row position of the bit
     * @param xPos column position of the bit
     * @param value value (true or false) which should be applied on the given position
     */
    void setNextGenBit(uint8_t yPos, uint8_t xPos, bool value) {
        uint8_t xBytePos = xPos / 8;
        uint8_t xBit = xPos % 8;

        if (value) {
            nextGenData[yPos][xBytePos] |= (128 >> xBit);
        } else {
            nextGenData[yPos][xBytePos] &= ~(128 >> xBit);
        }
    }
};

#endif