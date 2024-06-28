#include <iostream>
#include <windows.h>
using namespace std;
char arr[9]  {' ',' ',' ',' ',' ',' ',' ',' ',' '}; // array declared
class game
{
private:
    void p()
    {
        cout << endl;
        cout << "     |     |  " << endl; 
        cout <<"  " <<arr[0] << "  |  " << arr[1] << "  |  " << arr[2] << endl;
        cout << "_____|_____|_____" << endl; 
        cout << "     |     |  " << endl; 
        cout <<"  " << arr[3] << "  |  " << arr[4] << "  |  " << arr[5] << endl;
        cout << "_____|_____|_____" << endl; 
        cout << "     |     |  " << endl; 
        cout <<"  " << arr[6] << "  |  " << arr[7] << "  |  " << arr[8] << endl;
        cout << "     |     |  " << endl; 
    }
public:
    void print_board();
    int player_choice();
    int bot_choice ();
    void update_board_player(int num);
    void update_board_bot(int num);
    bool judge();


};
bool game::judge()
{
    if (arr[0] == 'X' && arr[1] == 'X' && arr[2] == 'X')
    {
        cout << "Bot won!" << endl;
        return false;
    }
    else if (arr[3] == 'X' && arr[4] == 'X' && arr[5] == 'X')
    {
        cout << "Bot won!" << endl;
        return false;   
    }
    else if (arr[6] == 'X' && arr[7] == 'X' && arr[8] == 'X')
    {
        cout << "Bot won!" << endl;
        return false;   
    }
    else if (arr[0] == 'O' && arr[1] == 'O' && arr[2] == 'O')
    {
        cout << "You won!" << endl;
        return false;
    }
    else if (arr[3] == 'O' && arr[4] == 'O' && arr[5] == 'O')
    {
        cout << "You won!" << endl;
        return false;   
    }
    else if (arr[6] == 'O' && arr[7] == 'O' && arr[8] == 'O')
    {
        cout << "You won!" << endl;
        return false;   
    }
    //
    else if (arr[0] == 'X' && arr[3] == 'X' && arr[6] == 'X')
    {
        cout << "Bot won!" << endl;
        return false;
    }
    else if (arr[1] == 'X' && arr[4] == 'X' && arr[7] == 'X')
    {
        cout << "Bot won!" << endl;
        return false;   
    }
    else if (arr[2] == 'X' && arr[5] == 'X' && arr[8] == 'X')
    {
        cout << "Bot won!" << endl;
        return false;   
    }
    //
    else if (arr[0] == 'O' && arr[3] == 'O' && arr[6] == 'O')
    {
        cout << "You won!" << endl;
        return false;
    }
    else if (arr[1] == 'O' && arr[4] == 'O' && arr[7] == 'O')
    {
        cout << "You won!" << endl;
        return false;   
    }
    else if (arr[2] == 'O' && arr[5] == 'O' && arr[8] == 'O')
    {
        cout << "You won!" << endl;
        return false;   
    }
    else if (arr[0] == 'O' && arr[4] == 'O' && arr[8] == 'O')
    {
        cout << "You won!" << endl;
        return false;   
    }
    else if (arr[2] == 'O' && arr[4] == 'O' && arr[6] == 'O')
    {
        cout << "You won!" << endl;
        return false;   
    }
    else if (arr[0] == 'X' && arr[4] == 'X' && arr[8] == 'X')
    {
        cout << "Bot won!" << endl;
        return false;   
    }
    else if (arr[2] == 'X' && arr[4] == 'X' && arr[6] == 'X')
    {
        cout << "Bot won!" << endl;
        return false;   
    }
    else
        return true;
}
void game::update_board_bot(int num)
{
    arr[num - 1] = 'X';
}
void game::update_board_player(int num)
{
    arr[num - 1] = 'O';
}
int game::player_choice()
{
    int num;
    do 
    {
        cin >> num;
        cout << "Enter a number (1 - 9)"; 
        if (num > 10 || num < 0)
            cout << "Error! Invalid number";
        if (arr[num - 1] != ' ')
            cout << "The position has already been taken!";

    }while (num > 10 || num < 0 || arr[num - 1] != ' ');

    return num;
}
int game::bot_choice()
{
    int num2;
    do
    {
        srand(time(NULL));
        num2 = (rand() % 9) + 1;

    }while (arr[num2 - 1] != ' ');

    return num2;
}
void game::print_board()
{
    p();
}
int main()
{
    game play;
    play.print_board();
    bool a = true;
    
    while (a)
    {
        int n = play.player_choice();
        play.update_board_player(n);
        system("cls");
        play.print_board();
        n = play.bot_choice();
        play.update_board_bot(n);
        system("cls");
        play.print_board();
        a = play.judge();
    }
    cout << "Thank you for playing!";
return 0;
}
