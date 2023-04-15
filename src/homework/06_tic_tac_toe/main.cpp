#include "tic_tac_toe.h"
#include "tic_tac_toe_manager.h"
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"
#include <iostream>
#include <memory>

int main() 
{
	bool playAgain = true;
	string first_player;
	char again;
	int board_size;

	TicTacToeManager manager;

	while(playAgain)
	{
		std::unique_ptr<TicTacToe> game;

		cout << "Enter the size of the board (3 or 4): ";
		cin >> board_size;

		if(board_size == 3)
		{
			game = std::make_unique<TicTacToe3>();
		}
		else if(board_size == 4)
		{
			game = std::make_unique<TicTacToe4>();
		}
		else
		{
			cout << "Invalid board size. Please choose 3 or 4." << "\n";
			continue;
		}

		cout << "Enter the first player (X or O): ";
		cin >> first_player;

		while (first_player != "X" && first_player != "O")
		{
			cout << "Invalid input. Enter X or O: ";
			cin >> first_player; 
		}
		game->start_game(first_player);

		while (!game->game_over())
		{
			cin >> *game;
			cout << *game;
		}
		
		cout << "Winner: " << game->get_winner() << "\n";

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
