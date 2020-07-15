#include <iostream>

using namespace std;
char square[3][3];

int checkwin();
void board();

int main()
{
	int c=49;
	for(int i=0;i<3;i++){
	for(int j=0;j<3;j++)
		{square[i][j]=(char)c;
		c++;}
	}

	int player = 1,i,choice;
	char mark;
	
	do
	{
		board();
		player=(player%2)?1:2;
		cout << "Player " << player << ", enter a number:  ";
		cin >> choice;
		mark=(player == 1) ? 'X' : 'O';
		if (choice == 1 && square[0][0] == '1')
			square[0][0] = mark;
		else if (choice == 2 && square[0][1] == '2')
			square[0][1] = mark;
		else if (choice == 3 && square[0][2] == '3')
			square[0][2] = mark;
		else if (choice == 4 && square[1][0] == '4')
			square[1][0] = mark;
		else if (choice == 5 && square[1][1] == '5')
			square[1][1] = mark;
		else if (choice == 6 && square[1][2] == '6')
			square[1][2] = mark;
		else if (choice == 7 && square[2][0] == '7')
			square[2][0] = mark;
		else if (choice == 8 && square[2][1] == '8')
			square[2][1] = mark;
		else if (choice == 9 && square[2][2] == '9')
			square[2][2] = mark;
		else
		{
			cout<<"Invalid move ";
			player--;
			cout<<player;
			
			
		}
		i=checkwin();
		player++;
	}while(i==-1);
	board();
	if(i==1)
		cout<<"==>\aPlayer "<<--player<<" win ";
	else
		cout<<"==>\aGame draw";
	
	return 0;
}
/*********************************************
	FUNCTION TO RETURN GAME STATUS
	1 FOR GAME IS OVER WITH RESULT
	-1 FOR GAME IS IN PROGRESS
	O GAME IS OVER AND NO RESULT
**********************************************/

int checkwin()
{
	if (square[0][0] == square[0][1] && square[0][1] == square[0][2])
		return 1;
	else if (square[1][0] == square[1][1] && square[1][1] == square[1][2])
		return 1;
	else if (square[2][0] == square[2][1] && square[2][1] == square[2][2])
		return 1;
	else if (square[0][0] == square[1][0] && square[1][0] == square[2][0])
		return 1;
	else if (square[0][1] == square[1][1] && square[1][1] == square[2][1])
		return 1;
	else if (square[0][2] == square[1][2] && square[1][2] == square[2][2])
		return 1;
	else if (square[0][0] == square[1][1] && square[1][1] == square[2][2])
		return 1;
	else if (square[0][2] == square[1][1] && square[1][1] == square[2][0])
		return 1;
	else if (square[0][0] != '1' && square[0][1] != '2' && square[0][2] != '3' &&
	         square[1][0] != '4' && square[1][1] != '5' && square[1][2] != '6' &&
            square[2][0] != '7' && square[2][1] != '8' && square[2][2] != '9')
		return 0;
	else
		return -1;
}


/*******************************************************************
     FUNCTION TO DRAW BOARD OF TIC TAC TOE WITH PLAYERS MARK
********************************************************************/


void board()
{
	
	cout << "\n\n\tTic Tac Toe\n\n";
	cout << "Player 1 (X)  -  Player 2 (O)" << endl << endl;
	cout << endl;
	cout << "     |     |     " << endl;
	cout << "  " << square[0][0] << "  |  " << square[0][1] << "  |  " << square[0][2] << endl;
	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;
	cout << "  " << square[1][0] << "  |  " << square[1][1] << "  |  " << square[1][2] << endl;
	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;
	cout << "  " << square[2][0] << "  |  " << square[2][1] << "  |  " << square[2][2] << endl;
	cout << "     |     |     " << endl << endl;
}

/*******************************************************************
				END OF PROJECT
********************************************************************/

