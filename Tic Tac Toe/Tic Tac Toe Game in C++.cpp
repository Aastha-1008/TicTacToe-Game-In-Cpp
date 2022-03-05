#include<iostream>
#include <cstdlib>
using namespace std;

char board[3][3];
char current_marker;
int current_player;

void initialize () 
{
    board[0][0] = '1';
    board[0][1] = '2';
    board[0][2] = '3';
    board[1][0] = '4';
    board[1][1] = '5';
    board[1][2] = '6';
    board[2][0] = '7';
    board[2][1] = '8';
    board[2][2] = '9';

}

void main_board()
{
    cout<<"\n----------------------------------------------------\n";

    cout<<"\t\t\t   "<<board[0][0]<<" | "<<board[0][1]<<" | "<<board[0][2]<<endl;

    cout<<"\t\t\t----------------\n";

    cout<<"\t\t\t   "<<board[1][0]<<" | "<<board[1][1]<<" | "<<board[1][2]<<endl;

    cout<<"\t\t\t----------------\n";

    cout<<" \t\t\t   "<<board[2][0]<<" | "<<board[2][1]<<" | "<<board[2][2]<<endl;

    cout<<"\n";

    cout<<"---------------------------------------------------------\n";

}
bool placeMarker(int slot){

    int row = slot / 3;
    int col = 2 ;

    if(slot % 3 == 0 )
    {
        row = row - 1;
        col = 2 ; 
    }

    else col = (  slot % 3 )- 1;

    if(board[row][col] != 'X' && board[row][col] != 'O' )  
    {
        board[row][col] = current_marker;
        return true;
    }

    return false;
}

int winner(){
    for(int i = 0 ; i<3 ;i++)
    {
        if( board[i][0]  == board[i][1] && board[i][1] == board[i][2] ){
            for(int k = 0 ; k <3 ; k++){
                for(int s = 0 ; s<3 ; s++){
                    if(k!= i){
                        board[k][s] = ' ';
                    }
                }
            }
            cout<<"Winner board is : \n";
            main_board();
            return current_player;
        }    

        if( board[0][i]  == board[1][i] && board[1][i] == board[2][i] ){
            for(int k = 0 ; k <3 ; k++){
                for(int s = 0 ; s<3 ; s++){
                    if(s!= i){
                        board[k][s] = ' ';
                    }
                }
            }
            cout<<"Winner board is : \n";
            main_board();
            return current_player;
        }
    }
    if( board[0][0]  == board[1][1] && board[1][1] == board[2][2] )
    {
        board[0][1] = ' ';
        board[0][2] = ' ';
        board[1][2] = ' ';
        board[1][0] = ' ';
        board[2][1] = ' ';
        board[2][0] = ' ';
        cout<<"Winner board is : \n";
        main_board();
        return current_player;
    }
    if( board[0][2]  == board[1][1] && board[1][1] == board[2][0] ){
        board[0][1] = ' ';
        board[0][0] = ' ';
        board[1][2] = ' ';
        board[1][0] = ' ';
        board[2][1] = ' ';
        board[2][2] = ' ';
        cout<<"Winner board is : \n";
        main_board();
        return current_player;
    }
    return 0 ; 
}

void swap_player_add_marker () {

    if(current_marker=='X') current_marker = 'O' ;
    else current_marker = 'X';

    if(current_player == 1 )current_player = 2;
    else current_player = 1;

}

void game()
{
    cout<<"Player one , choose your symbol : ";

    char marker_p1;
    cin>>marker_p1;

    current_player = 1;
    current_marker  = marker_p1;

    main_board();

    int player_won;

    for(int i = 0 ; i<9 ; i++ )
    {
        cout<<"It's player "<<current_player<<"'s turn. Enter your slot: ";

        int slot;
        cin>>slot;

        if(slot < 1 || slot > 9 )
        {
            cout<<"That slot is invalid! Try another slot! ";

            i--;
            continue;
        }

        bool status = placeMarker(slot);

        if(!status)
        {
            cout<<"That slot occupied! Try another slot. ";

            i--;
            continue;
        }

        main_board();

        player_won = winner() ;

        if (player_won == 1 ) 
        {
            cout << "Player 1 won! Congratulations ! ";

            break;
        }

        if (player_won == 2 ) 
        {
            cout << "Player 2 won! Congratulations ! ";
            break;
        }

        swap_player_add_marker();

    }

    if(player_won == 0 ) cout<<"That is a tie game! ";
}

int main(){
    while(1)
    {
        initialize();
        main_board();
        game();
        int c;
        cout<<"\n Do you want to play again: ";
        cout<<"\n\tEnter 1 if Yes else enter 0 : ";
        cin>>c;
        if(c!=1)
        {
            break;
        }
    }

    return 0; 
}