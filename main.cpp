#include <iostream>
#include <unistd.h>
#include <string>
#include "board.h"

using namespace std;

GridCoord curGrid={1,1};

void up(){
    curGrid.x--;
    if(curGrid.x<0)curGrid.x+=GridSize;
}
void down(){
    curGrid.x++;
    curGrid.x%=GridSize;
}
void left(){
    curGrid.y--;
    if(curGrid.y<0)curGrid.y+=GridSize;
}
void right(){
    curGrid.y++;
    curGrid.y%=GridSize;
}
int main(){
	Board tictactoe;
    

    tictactoe.setGrid(SELECTED,curGrid);
    char keyPress='X';
    int turnChanger = 0 ;
    while(!tictactoe.checkWin()){
        system("clear");
        if(tictactoe.boardFull()){
            tictactoe.restartBoard();
            curGrid.x=1;
            curGrid.y=1;
            //cout<<"Board is full"<<endl;
        }
        tictactoe.boardPrint();
        //cout<<keyPress<<tictactoe.getCurSelected().x<<tictactoe.getCurSelected().y<<endl;
        //cout<<curGrid.x<<curGrid.y<<endl;
        cin>>keyPress;
        

        switch(keyPress){
            case 'W':
            case 'w':
                up();
                if(tictactoe.detectSelected()){
                    tictactoe.setGrid(AVAILABLE,tictactoe.getCurSelected());
                    tictactoe.setGrid(SELECTED,curGrid);
                }else{
                    tictactoe.setGrid(SELECTED,curGrid);
                }
                break;
            case 'S':
            case 's':
                down();
                if(tictactoe.detectSelected()){
                    tictactoe.setGrid(AVAILABLE,tictactoe.getCurSelected());
                    tictactoe.setGrid(SELECTED,curGrid);
                }else{
                    tictactoe.setGrid(SELECTED,curGrid);
                }
                break;
            case 'A':
            case 'a':
                left();
                if(tictactoe.detectSelected()){
                    tictactoe.setGrid(AVAILABLE,tictactoe.getCurSelected());
                    tictactoe.setGrid(SELECTED,curGrid);
                }else{
                    tictactoe.setGrid(SELECTED,curGrid);
                }
                break;
            case 'D':
            case 'd':
                right();
                if(tictactoe.detectSelected()){
                    tictactoe.setGrid(AVAILABLE,tictactoe.getCurSelected());
                    tictactoe.setGrid(SELECTED,curGrid);
                }else{
                    tictactoe.setGrid(SELECTED,curGrid);
                }
                break;
            case 'C':
            case 'c':
                if(tictactoe.detectSelected()){
                    if(turnChanger==0){
                        tictactoe.setGrid(CROSS,tictactoe.getCurSelected());
                    }
                    else{
                        tictactoe.setGrid(CIRCLE,tictactoe.getCurSelected());
                    }
                    turnChanger=!turnChanger;
                }
                break;
            case 'V':
            case 'v':
                if(tictactoe.detectSelected()){
                    tictactoe.setGrid(CIRCLE,tictactoe.getCurSelected());
                }
                break;
        }

    }
    cout<<"GameOver! "<<((turnChanger==0)?("Circle Wins"):("Cross Wins"));
    cout<<endl;
    
    /*
    while (!tictactoe.checkWin()) {
        tictactoe.boardPrint();
        switch(a=getch()){

        }
    }*/

	return 0;
}