#include "tic_tac_toe.h"

int main() 
{
	bool playAgain = true;
	string first_player;
	char again;

	while(playAgain)
	{
		TicTacToe game;

		cout << "Enter the first player (X or O): ";
		cin >> first_player;

		while (first_player != "X" && first_player != "O")
		{
			cout << "Invalid input. Enter X or O: ";
			cin >> first_player; 
		}
		game.start_game(first_player);

		int position;
		while (!game.game_over())
		{
			cout << "Player " << game.get_player() << " enter a position (1-9): ";
			cin >> position;

			while(position < 1 || position > 9 || game.get_pegs()[position - 1] != " ")
				{
					cout << "Invalid input or position already taken. Enter a position";
					cin >> position;
				}
			game.mark_board(position);
			game.display_board();
		}
		
		cout << "Winner: " << game.get_winner() << "\n";

		cout << "Play again? (y/n): ";
		cin >> again;

		if (again != 'y' && again != 'Y')
		{
			playAgain = false;
		}
	}
	return 0;
}