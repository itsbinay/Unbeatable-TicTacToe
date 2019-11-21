#ifndef _BOARD_H
#define _BOARD_H

#include <stdbool.h>
#include <iostream>
using namespace std;

#define GridSize 3
typedef enum{
    CROSS=0,
    CIRCLE,
    AVAILABLE,
    SELECTED
}GridState;

typedef struct{
    int x,y;
}GridCoord;



class Board{

    private:
        GridState boardMatrix[3][3]={{AVAILABLE,AVAILABLE,AVAILABLE},
                                    {AVAILABLE,AVAILABLE,AVAILABLE},
                                    {AVAILABLE,AVAILABLE,AVAILABLE}};
        int count=0;
    public:
        Board(){
            cout<<"Board Initialised"<<endl;
        }

        bool boardEmpty();
        bool gridEmpty(GridCoord input);
        bool setGrid(GridState input,GridCoord pos);
        bool checkWin();
        bool checkHorzWin();
        bool checkVertWin();
        bool checkDiagWin();
        bool detectSelected();
        void boardPrint();
        char getGridchar(GridState input);
        void restartBoard();
        bool boardFull();
        GridCoord getCurSelected();
};

#endif