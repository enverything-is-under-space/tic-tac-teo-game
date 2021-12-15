#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <queue>

using namespace std;

class tttgame
{
    private:
        int x[3] , y[3] , z[3];
        queue<int> own2x,own2y,own2z;
        queue<int> enemy2x,enemy2y,enemy2z;

        queue<int> own2xyz,enemy2xyz;
        queue<int> empty;


    public:
        tttgame();
        void setIds(int,int);
        void setdef();

        void check(); //check the game status is it end? draw? win?
        void get_cell(); //print to conosle
        void clear_lmtw(); //clear list moves to win

        int move(int,int); //player id and cell id

        //ai
        void computer_initial_move(int);
        void computer_cm(); //calculate move
        int computer_move(); //proccess move and return a cell id for move
};





int computer_id;
int player_id;

void tttgame::setIds(int computerid, int playerid)
{
    computer_id = computerid;
    player_id = playerid;
}

void tttgame::setdef()
{
    x[0] = x[1] = x[2] =
            y[0] = y[1] = y[2] =
            z[0] = z[1] = z[2] = 0;
}

tttgame::tttgame()
{
    setdef();
}

void tttgame::clear_lmtw()
{
    swap( own2x, empty );swap( own2y, empty );swap( own2z, empty );
    swap( enemy2y, empty );swap( enemy2y, empty );swap( enemy2z, empty );
}


void tttgame::get_cell()
{
    cout << "x = ["<< x[0] << "," << x[1] << "," << x[2] << "]" <<endl;
    cout << "y = ["<< y[0] << "," << y[1] << "," << y[2] << "]" <<endl;
    cout << "z = ["<< z[0] << "," << z[1] << "," << z[2] << "]" <<endl;
}


void tttgame::check()
{

    get_cell();

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
    cout <<endl;

    //three horizontal
    if(x[0] == x[1] && x[1] == x[2] && x[2] !=0)
        cout<<"player "<< x[0] <<" won by raw x"<<endl;

    else if(y[0] == y[1] && y[1] == y[2] && y[2] !=0)
        cout<<"player "<< y[0] <<" won by raw y"<<endl;

    else if(z[0] == z[1] && z[1] == z[2] && z[2] !=0)
        cout<<"player "<< z[0] <<" won by raw z"<<endl;


    //three vertical
    else if(x[0] == y[0] && y[0] == z[0] && z[0] !=0)
        cout<<"player "<< x[0] <<" won by raw xyz 0"<<endl;

    else if(x[1] == y[1] && y[1] == z[1] && z[1] !=0)
        cout<<"player "<< x[1] <<" won by raw xyz 1"<<endl;

    else if(x[2] == y[2] && y[2] == z[2] && z[2] !=0)
        cout<<"player "<< x[2] <<" won by raw xyz 2"<<endl;



    //two X
    else if(x[0] == y[1] && y[1] == z[2] && z[2] !=0)
        cout<<"player "<< x[0] <<" won by raw xyz 159"<<endl;

    else if(x[2] == y[1] && y[1] == z[0] && z[0] !=0)
        cout<<"player "<< x[2] <<" won by raw xyz 357"<<endl;


    //game equal
    else if(x[0] && x[1] && x[2] &&   y[0] && y[1] && y[2] &&   z[0] && z[1] && z[2] !=0 )
    {
        cout << "game is draw and cells were:" <<endl;
        get_cell();
    }

    else
        cout <<"game is continue"<<endl;

}



int tttgame::move(int player, int cell)
{
        //return 1 means error was occuropted
    cout << "[INFO] player: " << player << " cell: " << cell << " requested to move."<<endl;
    switch (cell)
    {
            case 1:
            {
                if(x[0]==0)
                    x[0] = player;
                else
                {
                    cout <<"[WARN] ------ the x0 cell is full."<<endl;
                    return 1;
                }
                computer_cm();
            }break;


            case 2:
            {
                if(x[1]==0)
                    x[1] = player;
                else
                {
                    cout <<"[WARN] ------ the x1 cell is full."<<endl;
                    return 1;
                }
                computer_cm();
            }break;



            case 3:
            {
                if(x[2]==0)
                    x[2] = player;
                else
                {
                    cout <<"[WARN] ------ the x2 cell is full."<<endl;
                    return 1;
                }
                computer_cm();
            }break;


            case 4:
            {
                if(y[0]==0)
                    y[0] = player;
                else
                {
                    cout <<"[WARN] ------ the y0 cell is full."<<endl;
                    return 1;
                }
                computer_cm();
            }break;


            case 5:
            {
                if(y[1]==0)
                    y[1] = player;
                else
                {
                    cout <<"[WARN] ------ the y1 cell is full."<<endl;
                    return 1;
                }
                computer_cm();
            }break;


            case 6:
            {
                if(y[2]==0)
                    y[2] = player;
                else
                {
                    cout <<"[WARN] ------ the y2 cell is full."<<endl;
                    return 1;
                }
                computer_cm();
            }break;


            case 7:
            {
                if(z[0]==0)
                    z[0] = player;
                else
                {
                    cout <<"[WARN] ------ the z0 cell is full."<<endl;
                    return 1;
                }
                computer_cm();
            }break;


            case 8:
            {
                if(z[1]==0)
                    z[1] = player;
                else
                {
                    cout <<"[WARN] ------ the z1 cell is full."<<endl;
                    return 1;
                }
                computer_cm();
            }break;


            case 9:
            {
                if(z[2]==0)
                    z[2] = player;
                else
                {
                    cout <<"[WARN] ------ the z2 cell is full."<<endl;
                    return 1;
                }
                computer_cm();
            }break;


            default:
            {
                cout <<"[WARN] ------ the cell id is not correct."<<endl;
                computer_cm();
                return 1;
            }break;
    }
    return 0;
}




void tttgame::computer_initial_move(int computerid)
{
    srand (time(NULL));
    int random_number = rand() % 9 + 1;
    cout << "random number is "<< random_number << endl;
    int result_move = move(computerid,random_number);

    while(result_move)
    {
        cout << "the random cell were full, i'll try again find another cell." <<endl;
        int random_number2 = rand() % 9 + 1;
        cout << "random number2 is "<< random_number2 << endl;
        result_move = move(computerid,random_number2);
    }
}






void tttgame::computer_cm()
{

    //own X cells
    if(x[0] == x[1] && x[1] != 0 && x[2] == 0 && x[0] == computer_id)    own2x.push(2);
    if(x[0] == x[2] && x[2] != 0 && x[1] == 0 && x[0] == computer_id)    own2x.push(1);
    if(x[1] == x[2] && x[2] != 0 && x[0] == 0 && x[1] == computer_id)    own2x.push(0);

    //own Y cells
    if(y[0] == y[1] && y[1] != 0 && y[2] == 0 && y[0] == computer_id)    own2y.push(2);
    if(y[0] == y[2] && y[2] != 0 && y[1] == 0 && y[0] == computer_id)    own2y.push(1);
    if(y[1] == y[2] && y[2] != 0 && y[0] == 0 && y[1] == computer_id)    own2y.push(0);

    //own Z cells
    if(z[0] == z[1] && z[1] != 0 && z[2] == 0 && z[0] == computer_id)    own2z.push(2);
    if(z[0] == z[2] && z[2] != 0 && z[1] == 0 && z[0] == computer_id)    own2z.push(1);
    if(z[1] == z[2] && z[2] != 0 && z[0] == 0 && z[1] == computer_id)    own2z.push(0);

    //enemy X cells
    if(x[0] == x[1] && x[1] != 0 && x[2] == 0 && x[0] == player_id)    enemy2x.push(2);
    if(x[0] == x[2] && x[2] != 0 && x[1] == 0 && x[0] == player_id)    enemy2x.push(1);
    if(x[1] == x[2] && x[2] != 0 && x[0] == 0 && x[1] == player_id)    enemy2x.push(0);

    //enemy Y cells
    if(y[0] == y[1] && y[1] != 0 && y[2] == 0 && y[0] == player_id)    enemy2y.push(2);
    if(y[0] == y[2] && y[2] != 0 && y[1] == 0 && y[0] == player_id)    enemy2y.push(1);
    if(y[1] == y[2] && y[2] != 0 && y[0] == 0 && y[1] == player_id)    enemy2y.push(0);

    //enemy Z cells
    if(z[0] == z[1] && z[1] != 0 && z[2] == 0 && z[0] == player_id)    enemy2z.push(2);
    if(z[0] == z[2] && z[2] != 0 && z[1] == 0 && z[0] == player_id)    enemy2z.push(1);
    if(z[1] == z[2] && z[2] != 0 && z[0] == 0 && z[1] == player_id)    enemy2z.push(0);



    //own XYZ1 cells
    if(x[0] == y[0] && y[0] != 0 && z[0] == 0 && x[0] == computer_id)    own2z.push(0);
    if(x[0] == z[0] && z[0] != 0 && y[0] == 0 && x[0] == computer_id)    own2y.push(0);
    if(y[0] == z[0] && z[0] != 0 && x[0] == 0 && y[0] == computer_id)    own2x.push(0);

    //own XYZ2 cells
    if(x[1] == y[1] && y[1] != 0 && z[1] == 0 && x[1] == computer_id)    own2z.push(1);
    if(x[1] == z[1] && z[1] != 0 && y[1] == 0 && x[1] == computer_id)    own2y.push(1);
    if(y[1] == z[1] && z[1] != 0 && x[1] == 0 && y[1] == computer_id)    own2x.push(1);

    //own XYZ3 cells
    if(x[2] == y[2] && y[2] != 0 && z[2] == 0 && x[2] == computer_id)    own2z.push(2);
    if(x[2] == z[2] && z[2] != 0 && y[2] == 0 && x[2] == computer_id)    own2y.push(2);
    if(y[2] == z[2] && z[2] != 0 && x[2] == 0 && y[2] == computer_id)    own2x.push(2);




    //enemy XYZ1 cells
    if(x[0] == y[0] && y[0] != 0 && z[0] == 0 && x[0] == player_id)    enemy2z.push(0);
    if(x[0] == z[0] && z[0] != 0 && y[0] == 0 && x[0] == player_id)    enemy2y.push(0);
    if(y[0] == z[0] && z[0] != 0 && x[0] == 0 && y[0] == player_id)    enemy2x.push(0);

    //enemy XYZ2 cells
    if(x[1] == y[1] && y[1] != 0 && z[1] == 0 && x[1] == player_id)    enemy2z.push(1);
    if(x[1] == z[1] && z[1] != 0 && y[1] == 0 && x[1] == player_id)    enemy2y.push(1);
    if(y[1] == z[1] && z[1] != 0 && x[1] == 0 && y[1] == player_id)    enemy2x.push(1);

    //enemy XYZ3 cells
    if(x[2] == y[2] && y[2] != 0 && z[2] == 0 && x[2] == player_id)    enemy2z.push(2);
    if(x[2] == z[2] && z[2] != 0 && y[2] == 0 && x[2] == player_id)    enemy2y.push(2);
    if(y[2] == z[2] && z[2] != 0 && x[2] == 0 && y[2] == player_id)    enemy2x.push(2);




    //enemy XYZ159 cells
    if(x[0] == y[1] && y[1] != 0 && z[2] == 0 && x[0] == player_id)    enemy2z.push(2);
    if(x[0] == z[2] && z[2] != 0 && y[1] == 0 && x[0] == player_id)    enemy2y.push(1);
    if(y[1] == z[2] && z[2] != 0 && x[0] == 0 && y[1] == player_id)    enemy2x.push(0);

    //enemy XYZ357 cells
    if(x[2] == y[1] && y[1] != 0 && z[0] == 0 && x[2] == player_id)    enemy2z.push(0);
    if(x[2] == z[0] && z[0] != 0 && y[1] == 0 && x[2] == player_id)    enemy2y.push(1);
    if(y[1] == z[0] && z[0] != 0 && x[2] == 0 && y[1] == player_id)    enemy2x.push(2);
//     check();
}



int tttgame::computer_move()
{
    //return 0 means no error
    cout << endl;
    cout << "[INFO] computer move funtion has been started." << endl;

    bool status_move=false; // maybe this is reverse
    computer_cm();


    while (!enemy2x.empty())
    {
        std::cout << enemy2x.front() << "=====================================";
        enemy2x.pop();
    }



//   while(!enemy2x.empty())
//     {
//         if(enemy2x.empty())
//             break;
//         cout << "------------ new info enemy2x is: " << enemy2x.front() << endl;
//         enemy2x.pop();
//     }



//     //Goal is win
//     while(!own2x.empty() && move_not_accepted==true)
//     {
//         move_not_accepted = move(computer_id,own2x.front());
//         cout << "[INFO] status move own2x cell " << own2x.front() << " is accepted? " << move_not_accepted << endl;
//         own2x.pop();
//     }
//
//     if(own2x.empty() && own2y.empty() && own2z.empty() && own2xyz.empty() && enemy2x.empty() &&enemy2y.empty() && enemy2z.empty() && enemy2xyz.empty())
//     {
//         cout << "[INFO] i've no idea so lets move random." << endl;
//         computer_initial_move(computer_id);
//     }
   return 0;
}



 // ---------------------- main



int main()
{

   int computer_id = 2;
   int player_id = 1;
   int avaiable_rounds = 9;

   tttgame b;

   char who_is_first_player;
   cout << "Do you want play first? y/n: ";

   cin >> who_is_first_player;
   if(who_is_first_player =='n')
   {
       cout<<"[INFO] the computer id set to 1."<<endl;
       computer_id = 1;
       player_id = 2;
       b.computer_initial_move(computer_id);
       b.setIds(computer_id,player_id);
       avaiable_rounds--;
   }
   else
   {
       cout<<"[INFO] the computer id set to 2."<<endl;
       b.setIds(computer_id,player_id);
   }

   int player_move;
   while(avaiable_rounds>=0)
   {
       cout << "-------------------------------------------------------------- next " <<endl;
       cout << "[INPUT] please enter your cell to move:";
       cin >> player_move;
       b.move(player_id,player_move);
       avaiable_rounds--;
       b.computer_move();
   }


}
