#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "tic_tac_toe.h"
#include "tic_tac_toe_manager.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Verify game over function")
{
	TicTacToe game;
	game.start_game("X");

	game.mark_board(1);
	REQUIRE(game.game_over() == false);

	game.mark_board(9);
	REQUIRE(game.game_over() == false);

	game.mark_board(8);
	REQUIRE(game.game_over() == false);

	game.mark_board(2);
	REQUIRE(game.game_over() == false);

	game.mark_board(3);
	REQUIRE(game.game_over() == false);

	game.mark_board(7);
	REQUIRE(game.game_over() == false);

	game.mark_board(4);
	REQUIRE(game.game_over() == false);

	game.mark_board(6);
	REQUIRE(game.game_over() == false);

	game.mark_board(5);
	REQUIRE(game.game_over() == true);
	REQUIRE(game.get_winner() == "C");
}

TEST_CASE("Test first player set to X")
{
	TicTacToe game;
	game.start_game("X");
	REQUIRE(game.get_player() == "X");
}

TEST_CASE("Test first player set to O")
{
TicTacToe game;
	game.start_game("O");
	REQUIRE(game.get_player() == "O");
}

TEST_CASE("Test win by first column")
{
TicTacToe game;
	game.start_game("X");
	game.mark_board(1);
	game.mark_board(2);
	game.mark_board(4);
	game.mark_board(3);
	game.mark_board(7);
	REQUIRE(game.game_over() == true);
	REQUIRE(game.get_winner() == "X");
}

TEST_CASE("Test win by second column")
{
TicTacToe game;
	game.start_game("X");
	game.mark_board(2);
	game.mark_board(1);
	game.mark_board(5);
	game.mark_board(3);
	game.mark_board(8);
	REQUIRE(game.game_over() == true);
	REQUIRE(game.get_winner() == "X");
}

TEST_CASE("Test win by third column")
{
TicTacToe game;
	game.start_game("X");
	game.mark_board(3);
	game.mark_board(2);
	game.mark_board(6);
	game.mark_board(1);
	game.mark_board(9);
	REQUIRE(game.game_over() == true);
	REQUIRE(game.get_winner() == "X");
}

TEST_CASE("Test win by first row")
{
TicTacToe game;
	game.start_game("X");
	game.mark_board(1);
	game.mark_board(4);
	game.mark_board(2);
	game.mark_board(5);
	game.mark_board(3);
	REQUIRE(game.game_over() == true);
	REQUIRE(game.get_winner() == "X");
}

TEST_CASE("Test win by second row")
{
	TicTacToe game;
	game.start_game("X");
	game.mark_board(4);
	game.mark_board(2);
	game.mark_board(5);
	game.mark_board(3);
	game.mark_board(6);
	REQUIRE(game.game_over() == true);
	REQUIRE(game.get_winner() == "X");
}

TEST_CASE("Test win by third row")
{
	TicTacToe game;
	game.start_game("X");
	game.mark_board(7);
	game.mark_board(2);
	game.mark_board(8);
	game.mark_board(3);
	game.mark_board(9);
	REQUIRE(game.game_over() == true);
	REQUIRE(game.get_winner() == "X");
}

TEST_CASE("Test win diagonally from top left")
{
TicTacToe game;
	game.start_game("X");
	game.mark_board(1);
	game.mark_board(2);
	game.mark_board(5);
	game.mark_board(3);
	game.mark_board(9);
	REQUIRE(game.game_over() == true);
	REQUIRE(game.get_winner() == "X");
}

TEST_CASE("Test win diagonally from bottom left")
{
TicTacToe game;
	game.start_game("X");
	game.mark_board(7);
	game.mark_board(2);
	game.mark_board(5);
	game.mark_board(4);
	game.mark_board(3);
	REQUIRE(game.game_over() == true);
	REQUIRE(game.get_winner() == "X");
}

TEST_CASE("Test TicTacToeManager get_winner_total")
{
TicTacToeManager manager;
TicTacToe game;
	game.start_game("O");
	game.mark_board(1);
	game.mark_board(5);
	game.mark_board(2);
	game.mark_board(4);
	game.mark_board(3);
	REQUIRE(game.game_over() == true);
	REQUIRE(game.get_winner() == "O");
	manager.save_game(game);

	TicTacToe game2;
	game2.start_game("X");
	game2.mark_board(1);
	game2.mark_board(2);
	game2.mark_board(5);
	game2.mark_board(3);
	game2.mark_board(9);
	REQUIRE(game2.game_over() == true);
	REQUIRE(game2.get_winner() == "X");
	manager.save_game(game2);

	TicTacToe game3;
	game3.start_game("X");
	game3.mark_board(1);
	game3.mark_board(9);
	game3.mark_board(8);
	game3.mark_board(2);
	game3.mark_board(3);
	game3.mark_board(7);
	game3.mark_board(4);
	game3.mark_board(6);
	game3.mark_board(5);
	REQUIRE(game3.game_over() == true);
	REQUIRE(game3.get_winner() == "C");
	manager.save_game(game3);

	int x_win, o_win, ties;
	manager.get_winner_total(x_win, o_win, ties);
	REQUIRE(x_win == 1);
	REQUIRE(o_win == 1);
	REQUIRE(ties == 1);
}