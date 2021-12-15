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


    public:
        tttgame(int,int); //set computer & player id
        int move(int,int);
        int gameResultCheck();
        int playerMove();

        void computerInitMove(); //random move
        void computerMove();
        void computerCalculateMove();
        void computerClearCaculatedMoves();

        void consoleLog();

};

int computerId=0;
int playerId=0;
int roundCounter=0;

int tttgame::playerMove()
{
    //return 0 means player move were successfully complete.
    cout << endl;

    cout << "Your turn: enter cell id between 1-9: ";
    int firstMove = 0;
    cin >> firstMove;

    while(firstMove == 0 || firstMove >= 10)
    {
        firstMove = 0;
        cout << "Your turn: enter cell id between 1-9: ";
        cin >> firstMove;
    }

    if(firstMove > 0 && firstMove <=9)
    {
        int resultMove = move(playerId,firstMove);
        while(resultMove)
        {
            cout << "Your turn: enter cell id: ";
            cin >> firstMove;
            if(firstMove > 0 && firstMove <=9)
            {
                resultMove = move(playerId,firstMove);
            }
        }
        return 0;
    }


    return 1;
}

void tttgame::computerInitMove()
{
    //later can add some algorithms with priorities for first moves
    srand (time(NULL));
    int random_number = rand() % 9 + 1;
    int result_move = move(computerId,random_number);

    while(result_move)
    {
        cout << "[LOG] the random cell were full, i'll try again find another cell." <<endl;
        int random_number2 = rand() % 9 + 1;
        result_move = move(computerId,random_number2);
    }
}

void tttgame::computerClearCaculatedMoves()
{
    queue<int> emptyqueue;
    swap( computerX, emptyqueue );swap( computerY, emptyqueue );swap( computerZ, emptyqueue );
    swap( playerX, emptyqueue );swap( playerY, emptyqueue );swap( playerZ, emptyqueue );
}

void tttgame::computerCalculateMove()
{
    computerClearCaculatedMoves();

    //own X cells
    if(x[0] == x[1] && x[1] != 0 && x[2] == 0 && x[0] == computerId)    computerX.push(2);
    if(x[0] == x[2] && x[2] != 0 && x[1] == 0 && x[0] == computerId)    computerX.push(1);
    if(x[1] == x[2] && x[2] != 0 && x[0] == 0 && x[1] == computerId)    computerX.push(0);

    //own Y cells
    if(y[0] == y[1] && y[1] != 0 && y[2] == 0 && y[0] == computerId)    computerY.push(2);
    if(y[0] == y[2] && y[2] != 0 && y[1] == 0 && y[0] == computerId)    computerY.push(1);
    if(y[1] == y[2] && y[2] != 0 && y[0] == 0 && y[1] == computerId)    computerY.push(0);

    //own Z cells
    if(z[0] == z[1] && z[1] != 0 && z[2] == 0 && z[0] == computerId)    computerZ.push(2);
    if(z[0] == z[2] && z[2] != 0 && z[1] == 0 && z[0] == computerId)    computerZ.push(1);
    if(z[1] == z[2] && z[2] != 0 && z[0] == 0 && z[1] == computerId)    computerZ.push(0);

    //own XYZ1 cells
    if(x[0] == y[0] && y[0] != 0 && z[0] == 0 && x[0] == computerId)    computerZ.push(0);
    if(x[0] == z[0] && z[0] != 0 && y[0] == 0 && x[0] == computerId)    computerY.push(0);
    if(y[0] == z[0] && z[0] != 0 && x[0] == 0 && y[0] == computerId)    computerX.push(0);

    //own XYZ2 cells
    if(x[1] == y[1] && y[1] != 0 && z[1] == 0 && x[1] == computerId)    computerZ.push(1);
    if(x[1] == z[1] && z[1] != 0 && y[1] == 0 && x[1] == computerId)    computerY.push(1);
    if(y[1] == z[1] && z[1] != 0 && x[1] == 0 && y[1] == computerId)    computerX.push(1);

    //own XYZ3 cells
    if(x[2] == y[2] && y[2] != 0 && z[2] == 0 && x[2] == computerId)    computerZ.push(2);
    if(x[2] == z[2] && z[2] != 0 && y[2] == 0 && x[2] == computerId)    computerY.push(2);
    if(y[2] == z[2] && z[2] != 0 && x[2] == 0 && y[2] == computerId)    computerX.push(2);

    //own XYZ159 cells
    if(x[0] == y[1] && y[1] != 0 && z[2] == 0 && x[0] == computerId)    computerZ.push(2);
    if(x[0] == z[2] && z[2] != 0 && y[1] == 0 && x[0] == computerId)    computerY.push(1);
    if(y[1] == z[2] && z[2] != 0 && x[0] == 0 && y[1] == computerId)    computerX.push(0);

    //own XYZ357 cells
    if(x[2] == y[1] && y[1] != 0 && z[0] == 0 && x[2] == computerId)    computerZ.push(0);
    if(x[2] == z[0] && z[0] != 0 && y[1] == 0 && x[2] == computerId)    computerY.push(1);
    if(y[1] == z[0] && z[0] != 0 && x[2] == 0 && y[1] == computerId)    computerX.push(2);




    //enemy X cells
    if(x[0] == x[1] && x[1] != 0 && x[2] == 0 && x[0] == playerId)    playerX.push(2);
    if(x[0] == x[2] && x[2] != 0 && x[1] == 0 && x[0] == playerId)    playerX.push(1);
    if(x[1] == x[2] && x[2] != 0 && x[0] == 0 && x[1] == playerId)    playerX.push(0);

    //enemy Y cells
    if(y[0] == y[1] && y[1] != 0 && y[2] == 0 && y[0] == playerId)    playerY.push(2);
    if(y[0] == y[2] && y[2] != 0 && y[1] == 0 && y[0] == playerId)    playerY.push(1);
    if(y[1] == y[2] && y[2] != 0 && y[0] == 0 && y[1] == playerId)    playerY.push(0);

    //enemy Z cells
    if(z[0] == z[1] && z[1] != 0 && z[2] == 0 && z[0] == playerId)    playerZ.push(2);
    if(z[0] == z[2] && z[2] != 0 && z[1] == 0 && z[0] == playerId)    playerZ.push(1);
    if(z[1] == z[2] && z[2] != 0 && z[0] == 0 && z[1] == playerId)    playerZ.push(0);

    //enemy XYZ1 cells
    if(x[0] == y[0] && y[0] != 0 && z[0] == 0 && x[0] == playerId)    playerZ.push(0);
    if(x[0] == z[0] && z[0] != 0 && y[0] == 0 && x[0] == playerId)    playerY.push(0);
    if(y[0] == z[0] && z[0] != 0 && x[0] == 0 && y[0] == playerId)    playerX.push(0);

    //enemy XYZ2 cells
    if(x[1] == y[1] && y[1] != 0 && z[1] == 0 && x[1] == playerId)    playerZ.push(1);
    if(x[1] == z[1] && z[1] != 0 && y[1] == 0 && x[1] == playerId)    playerY.push(1);
    if(y[1] == z[1] && z[1] != 0 && x[1] == 0 && y[1] == playerId)    playerX.push(1);

    //enemy XYZ3 cells
    if(x[2] == y[2] && y[2] != 0 && z[2] == 0 && x[2] == playerId)    playerZ.push(2);
    if(x[2] == z[2] && z[2] != 0 && y[2] == 0 && x[2] == playerId)    playerY.push(2);
    if(y[2] == z[2] && z[2] != 0 && x[2] == 0 && y[2] == playerId)    playerX.push(2);

    //enemy XYZ159 cells
    if(x[0] == y[1] && y[1] != 0 && z[2] == 0 && x[0] == playerId)    playerZ.push(2);
    if(x[0] == z[2] && z[2] != 0 && y[1] == 0 && x[0] == playerId)    playerY.push(1);
    if(y[1] == z[2] && z[2] != 0 && x[0] == 0 && y[1] == playerId)    playerX.push(0);

    //enemy XYZ357 cells
    if(x[2] == y[1] && y[1] != 0 && z[0] == 0 && x[2] == playerId)    playerZ.push(0);
    if(x[2] == z[0] && z[0] != 0 && y[1] == 0 && x[2] == playerId)    playerY.push(1);
    if(y[1] == z[0] && z[0] != 0 && x[2] == 0 && y[1] == playerId)    playerX.push(2);
}

void tttgame::computerMove()
{
    computerCalculateMove();

    //sort move cells
    //make new queue
    //insert popular cell ids in head of the queue
    //send move receive resultMove
    //check resultMove if its ok done if not ok
    //pick another move
    //if all moves were full call inital moves


}

tttgame::tttgame(int playerid,int computerid)
{
    playerId = playerid;
    computerId = computerid;


    x[0] = x[1] = x[2] =
    y[0] = y[1] = y[2] =
    z[0] = z[1] = z[2] = 0;


    if(playerId)
    {
        playerMove();
    }
    else
    {
        computerMove();
    }
}

int tttgame::move(int playerid,int cellid)
{
    //return 1 means error was occurapted
    if(playerid>2 || playerid<1)
    {
        cout << "[INVALID INPUT] player id is invalid." << endl;
        return 1;
    }
    if(roundCounter>=10)
    {
        cout << "[GAME INFO] Max rounds is 9, the game is end player " << playerid << " can't move cell " << cellid << "." << endl;
        return 1;
    }


    switch (cellid)
    {
            case 1:
            {
                if(!x[0])
                    x[0] = playerid;
                else
                {
                    cout <<"[DUPLICATE INPUT] the x0 cell is full."<<endl;
                    return 1;
                }
            }break;


            case 2:
            {
                if(!x[1])
                    x[1] = playerid;
                else
                {
                    cout <<"[DUPLICATE INPUT] the x1 cell is full."<<endl;
                    return 1;
                }
            }break;



            case 3:
            {
                if(!x[2])
                    x[2] = playerid;
                else
                {
                    cout <<"[DUPLICATE INPUT] the x2 cell is full."<<endl;
                    return 1;
                }
            }break;


            case 4:
            {
                if(!y[0])
                    y[0] = playerid;
                else
                {
                    cout <<"[DUPLICATE INPUT] the y0 cell is full."<<endl;
                    return 1;
                }
            }break;


            case 5:
            {
                if(!y[1])
                    y[1] = playerid;
                else
                {
                    cout <<"[DUPLICATE INPUT] the y1 cell is full."<<endl;
                    return 1;
                }
            }break;


            case 6:
            {
                if(!y[2])
                    y[2] = playerid;
                else
                {
                    cout <<"[DUPLICATE INPUT] the y2 cell is full."<<endl;
                    return 1;
                }
            }break;


            case 7:
            {
                if(!z[0])
                    z[0] = playerid;
                else
                {
                    cout <<"[DUPLICATE INPUT] the z0 cell is full."<<endl;
                    return 1;
                }
            }break;


            case 8:
            {
                if(!z[1])
                    z[1] = playerid;
                else
                {
                    cout <<"[DUPLICATE INPUT] the z1 cell is full."<<endl;
                    return 1;
                }
            }break;


            case 9:
            {
                if(!z[2])
                    z[2] = playerid;
                else
                {
                    cout <<"[DUPLICATE INPUT] the z2 cell is full."<<endl;
                    return 1;
                }
            }break;


            default:
            {
                cout <<"[INVALID INPUT] cell id is invalid."<<endl;
                return 1;
            }break;
    }

    int resultMove = gameResultCheck();
    if(!resultMove)
        roundCounter++;
    else
        roundCounter = 10;

    return 0;
}

int tttgame::gameResultCheck()
{
    /*returns:
        0 means continue.
        1 means player one won.
        2 means player two won.
        3 means game is draw.
    */


    //three horizontals
    if(x[0] == x[1] && x[1] == x[2] && x[2] !=0)
    {
        cout<<"player "<< x[0] <<" won by raw x"<<endl;
        return x[0];
    }

    else if(y[0] == y[1] && y[1] == y[2] && y[2] !=0)
    {
        cout<<"player "<< y[0] <<" won by raw y"<<endl;
        return y[0];
    }

    else if(z[0] == z[1] && z[1] == z[2] && z[2] !=0)
    {
        cout<<"player "<< z[0] <<" won by raw z"<<endl;
        return z[0];
    }


    //three verticals
    else if(x[0] == y[0] && y[0] == z[0] && z[0] !=0)
    {
        cout<<"player "<< x[0] <<" won by raw xyz 0"<<endl;
        return x[0];
    }

    else if(x[1] == y[1] && y[1] == z[1] && z[1] !=0)
    {
        cout<<"player "<< x[1] <<" won by raw xyz 1"<<endl;
        return x[1];
    }

    else if(x[2] == y[2] && y[2] == z[2] && z[2] !=0)
    {
        cout<<"player "<< x[2] <<" won by raw xyz 2"<<endl;
        return x[2];
    }



    //two X
    else if(x[0] == y[1] && y[1] == z[2] && z[2] !=0)
    {
        cout<<"player "<< x[0] <<" won by raw xyz 159"<<endl;
        return x[0];
    }

    else if(x[2] == y[1] && y[1] == z[0] && z[0] !=0)
    {
        cout<<"player "<< x[2] <<" won by raw xyz 357"<<endl;
        return x[2];
    }


    //game equal
    else if(x[0] && x[1] && x[2] &&
            y[0] && y[1] && y[2] &&
            z[0] && z[1] && z[2] !=0)
    {
        cout << "[GAME END] game is draw." <<endl;
        return 3;
    }

    else
        cout <<"game is continue"<<endl;
    return 0;
}

void tttgame::consoleLog()
{

    cout << "--------------CONSOLE LOG START-------------" << endl;
    cout << "x = ["<< x[0] << "," << x[1] << "," << x[2] << "]" <<endl;
    cout << "y = ["<< y[0] << "," << y[1] << "," << y[2] << "]" <<endl;
    cout << "z = ["<< z[0] << "," << z[1] << "," << z[2] << "]" <<endl;



    //fetch private queues assign to new queue becuse there is need to print all queues for print as log and if use main queues the values inside main queue will be clean it's will be make problem.

    queue<int>
    own2x(computerX),
    own2y(computerY),
    own2z(computerZ),
    enemy2x(playerX),
    enemy2y(playerY),
    enemy2z(playerZ);  //enemy means player , own means computer cells






    cout << "own2x:";
    while(!own2x.empty())
    {
            cout<<" "<<own2x.front();
            own2x.pop();
    }
    cout <<endl;

    cout << "own2y:";
    while(!own2y.empty())
    {
            cout<<" "<<own2y.front();
            own2y.pop();
    }
    cout <<endl;

    cout << "own2z:";
    while(!own2z.empty())
    {
            cout<<" "<<own2z.front();
            own2z.pop();
    }
    cout <<endl;

    cout << "enemy2x:";
    while(!enemy2x.empty())
    {
            cout<<" "<<enemy2x.front();
            enemy2x.pop();
    }
    cout <<endl;

    cout << "enemy2y:";
    while(!enemy2y.empty())
    {
            cout<<" "<<enemy2y.front();
            enemy2y.pop();
    }
    cout <<endl;


    cout << "enemy2z:";
    while(!enemy2z.empty())
    {
            cout<<" "<<enemy2z.front();
            enemy2z.pop();
    }
    cout << "--------------CONSOLE LOG END-------------" << endl;

}





int main()
{
    int playerId = 2 , computerId = 1;


    cout << "do you want player first? y/n";
    char whosTurn; cin >> whosTurn;

    if(whosTurn == 'y' || whosTurn == 'Y')
    {
        playerId=1;
        computerId=2;
    }

    tttgame game(playerId,computerId); //set ids , catch first move

    //NOTE: remove move in doc after playerid=2 its depend to intialer




}













