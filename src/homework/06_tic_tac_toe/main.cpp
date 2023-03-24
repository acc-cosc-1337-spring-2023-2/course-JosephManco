#include "tic_tac_toe.h"

int main() 
{
	string first_player;
	cout << "Enter the first player (X or O): ";
	cin >> first_player;

	TicTacToe game;
	game.start_game(first_player);

	bool play_again = true;
	while(play_again)
	{
		while (!game.game_over())
		{
			game.display_board();

			int position;
			cout << "Enter a position (1-9): ";
			cin >> position;

			game.mark_board(position);
		}
		game.display_board();
		cout << "Game over!\n";

		char choice;
		cout << "Play again? (y/n): ";
		cin >> choice;

		if (choice != 'y' && choice != 'Y')
		{
			play_again = false;
		}
		else
		{
			game.start_game(game.get_player() == "X" ? "O" : "X");
		}
	}

	return 0;
}