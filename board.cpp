#include "board.h"

bool Board::boardEmpty(){
    for(int i=0;i<3;i++){
        if(boardMatrix[i][0]!=AVAILABLE ||
        boardMatrix[i][1]!=AVAILABLE ||
        boardMatrix[i][2]!=AVAILABLE)return false;
    }
    return true;
}

bool Board::gridEmpty(GridCoord input){
    if(boardMatrix[input.x][input.y]==AVAILABLE)return true;
    return false;
}

bool Board::setGrid(GridState input,GridCoord pos){
    if(boardMatrix[pos.x][pos.y]!=AVAILABLE && boardMatrix[pos.x][pos.y]!=SELECTED)return false;
    else{
        boardMatrix[pos.x][pos.y]=input;
        return true;
    }
}

bool Board::checkWin(){
    if(checkVertWin() || checkHorzWin() || checkDiagWin())return true;
    return false;
}
bool Board::checkHorzWin(){
    for(int i=0;i<3;i++){
        if(boardMatrix[i][0]==boardMatrix[i][1] && 
        boardMatrix[i][1]==boardMatrix[i][2] && 
        boardMatrix[i][0]!=SELECTED && 
        boardMatrix[i][0]!=AVAILABLE)return true;
    }
    return false;
}
bool Board::checkVertWin(){
    for(int i=0;i<3;i++){
        if(boardMatrix[0][i]==boardMatrix[1][i] && 
        boardMatrix[1][i]==boardMatrix[2][i] && 
        boardMatrix[0][i]!=SELECTED && 
        boardMatrix[0][i]!=AVAILABLE)return true;
    }
    return false;
}
bool Board::checkDiagWin(){
    if(boardMatrix[0][0]==boardMatrix[1][1] && 
        boardMatrix[1][1]==boardMatrix[2][2] && 
        boardMatrix[0][0]!=SELECTED && 
        boardMatrix[0][0]!=AVAILABLE)return true;
    if(boardMatrix[0][2]==boardMatrix[1][1] && 
        boardMatrix[1][1]==boardMatrix[2][0] &&  
        boardMatrix[0][2]!=SELECTED && 
        boardMatrix[0][2]!=AVAILABLE)return true; 
    return false;
}
char Board::getGridchar(GridState input){
    switch(input){
        case CROSS: return 'X';
        case CIRCLE: return 'O';
        case AVAILABLE: return '_';
        case SELECTED: return 'S';
    }
}
void Board::restartBoard(){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            boardMatrix[i][j]=AVAILABLE;
        }
    }
    boardMatrix[0][0]=SELECTED;
}
bool Board::boardFull(){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(boardMatrix[i][j]==SELECTED || boardMatrix[i][j]==AVAILABLE)return false;
        }
    }
    return true;
}
extern GridCoord curGrid;
void Board::boardPrint(){
    //system("clear");    //This will call the "clear" command from the os
    count++;
    //cout<<"count val:"<<count<<endl;
    cout<<"-------------------------------------"<<endl;
    cout<<"--------WELCOME TO TIC-TAC-TOE-------"<<endl;
    cout<<"-------------------------------------"<<endl; //Altogether the line width is 37 char
    cout<<"-----------------W-Up----------------"<<endl;
    cout<<"----------------S-Down---------------"<<endl;
    cout<<"----------------A-Left---------------"<<endl;
    cout<<"---------------S-Right---------------"<<endl;
    cout<<"---------------C-UnSelect------------"<<endl;
    cout<<"--------------V-UnSelect-------------"<<endl;
    cout<<"----------------{"<<curGrid.y<<","<<curGrid.x<<"}----------------"<<endl;

    for(int i=0;i<3;i++){
        int counter=0;
        cout<<i;
        for(int j=0;j<36;j++){
            
            if(j<15){
                cout<<"<";
            }
            else if(j>21){
                cout<<">";
            }
            else if((j-15)%2==0){
                cout<<"|";
            }
            else{
                cout<<getGridchar(boardMatrix[i][(j-16)/2]);
                counter++;
            }
        }
        cout<<endl;
    }
    
}

bool Board::detectSelected(){
    for(int i=0;i<3;i++){
        if(boardMatrix[i][0]==SELECTED 
        || boardMatrix[i][1]==SELECTED 
        || boardMatrix[i][2]==SELECTED)return true;
    }
    return false;
}
GridCoord Board::getCurSelected(){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(boardMatrix[i][j]==SELECTED){
                GridCoord a ={i,j};
                return a;
            }
        }
    }
    return {0,0};
}