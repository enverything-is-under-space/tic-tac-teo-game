#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <queue>

using namespace std;

class tttgame
{
    private:
        int x[3],y[3],z[3];
        queue<int> computerX,computerY,computerZ,computerXYZ;

        queue<int> playerX,playerY,playerZ,playerXYZ;

        queue<int> emptyqueue;

    public:
        tttgame(int,int); //set computer & player id
        void console_log();
        void clear_queue(); //clear list moves to win
        int move(int,int);

        void computer_rmove(); //random move
        void computer_move();
};

int computerId;
int playerId;
