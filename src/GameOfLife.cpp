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

    /**
     * Count neighbors (inside visual data) of a cell on given position 
     * 
     * @param yPos row of a cell where neighbors should be counted
     * @param xPos column of a cell where neighbors should be counted
     * @return Amount of neighbors on a given position
     */
    uint8_t countNeighbors(uint8_t yPos, uint8_t xPos) {
        uint8_t neighbors = 0;
        uint8_t tempXPos, tempYPos;
        uint8_t maxXPos = COLUMNS - 1;
        uint8_t maxYPos = ROWS - 1;

        // get NW
        tempYPos = yPos == 0 ? maxYPos : yPos - 1;
        tempXPos = xPos == 0 ? maxXPos : xPos - 1;
        if (getVisualDataBit(tempYPos, tempXPos)) ++neighbors;

        // get N
        tempYPos = yPos == 0 ? maxYPos : yPos - 1;
        tempXPos = xPos;
        if (getVisualDataBit(tempYPos, tempXPos)) ++neighbors;

        // get NE
        tempYPos = yPos == 0 ? maxYPos : yPos - 1;
        tempXPos = xPos == maxXPos ? 0 : xPos + 1;
        if (getVisualDataBit(tempYPos, tempXPos)) ++neighbors;

        // get W
        tempYPos = yPos;
        tempXPos = xPos == 0 ? maxXPos : xPos - 1;
        if (getVisualDataBit(tempYPos, tempXPos)) ++neighbors;

        // get E
        tempYPos = yPos;
        tempXPos = xPos == maxXPos ? 0 : xPos + 1;
        if (getVisualDataBit(tempYPos, tempXPos)) ++neighbors;

        // get SW
        tempYPos = yPos == maxYPos ? 0 : yPos + 1;
        tempXPos = xPos == 0 ? maxXPos : xPos - 1;
        if (getVisualDataBit(tempYPos, tempXPos)) ++neighbors;

        // get S
        tempYPos = yPos == maxYPos ? 0 : yPos + 1;
        tempXPos = xPos;
        if (getVisualDataBit(tempYPos, tempXPos)) ++neighbors;

        // get SE
        tempYPos = yPos == maxYPos ? 0 : yPos + 1;
        tempXPos = xPos == maxXPos ? 0 : xPos + 1;
        if (getVisualDataBit(tempYPos, tempXPos)) ++neighbors;

        return neighbors;
    }
};

#endif