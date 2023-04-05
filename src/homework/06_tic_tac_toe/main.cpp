#include "tic_tac_toe.h"
#include "tic_tac_toe_manager.h"

int main() 
{
	bool playAgain = true;
	string first_player;
	char again;

	TicTacToeManager manager;

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
			cout << game;
		}
		
		cout << "Winner: " << game.get_winner() << "\n";

		manager.save_game(game);

		cout << "Play again? (y/n): ";
		cin >> again;

		if (again != 'y' && again != 'Y')
		{
			playAgain = false;
		}
	}

	int x_win, o_win, ties;
	manager.get_winner_total(x_win, o_win, ties);
	cout << "X wins: " << x_win << "\nO wins: " << o_win << "\nTies: " << ties <<"\n";

	cout << manager;

	return 0;
}