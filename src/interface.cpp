#include "../include/interface.h"
#include <iostream>

Interface::Interface(CellType display[][DISPLAY_WIDTH])
{
    // Initialize display with given display
    for (size_t i = 0; i < DISPLAY_HEIGHT; i++)
    {
        for (size_t j = 0; j < DISPLAY_WIDTH; j++)
        {
            this->display[i][j] = display[i][j];
        }
    }
}

Interface::Interface()
{
    // Initialize display with AIR_STR
    for (size_t i = 0; i < DISPLAY_HEIGHT; i++)
    {
        for (size_t j = 0; j < DISPLAY_WIDTH; j++)
        {
            display[i][j] = AIR;
        }
    }
}

void Interface::printCell(CellType cell, CellType prevCell)
{
    //std::cout << "\033[32;43mThis text is green on yellow.\033[0m" << std::endl;

    switch (cell)
    {

        case AIR:
            // if (prevCell != AIR)
            // {
            //     system("Color 00");
            // }
            
            std::cout << AIR_STR;
            break;
        case WATER:
            // if (prevCell != WATER)
            // {
            //     system("Color 03");
            // }
            std::cout << "\033[31;34m" << WATER_STR << "\033[0m";
            break;
        case HALF_WATER:
            // if (prevCell != HALF_WATER)
            // {
            //     system("Color 0B");
            // }
            
            std::cout << "\033[1;34m" << HALF_WATER_STR << "\033[0m";
            break;
        case H_WALL:
            // if(prevCell != H_WALL || prevCell != V_WALL || prevCell != CORNER_WALL)
            // {
            //     system("Color 04");
            // }
            std::cout << H_WALL_STR;
            break;
        case V_WALL:
            // if(prevCell != H_WALL || prevCell != V_WALL || prevCell != CORNER_WALL)
            // {
            //     system("Color 04");
            // }
            std::cout << V_WALL_STR ;
            break;
        case CORNER_WALL:
            // if(prevCell != H_WALL || prevCell != V_WALL || prevCell != CORNER_WALL)
            // {
            //     system("Color 04");
            // }
            std::cout << CORNER_STR ;
            break;
        case EMPTY_WALL:
            // if (prevCell != EMPTY_WALL)
            // {
            //     system("Color 08");
            // }
            
            std::cout << EMPTY_WALL_STR;
            break;

        default:
            std::cout << '?';
            break;
    }
}

void Interface::print(body_t* bodies, size_t bodyCount)
{
    for (size_t i = 0; i < bodyCount; i++)
    {
        std::cout<<bodies[i].toString()<<std::endl;
    }

    printf("Display:\n");
    CellType prevCell = INVALID_CELL;
    for (size_t y = 0; y < DISPLAY_HEIGHT; y++)
    {
        for (size_t x = 0; x < DISPLAY_WIDTH; x++)
        {
            printCell(this->display[y][x], prevCell);
            prevCell = this->display[y][x];
        }
        std::cout << std::endl;
    }
}