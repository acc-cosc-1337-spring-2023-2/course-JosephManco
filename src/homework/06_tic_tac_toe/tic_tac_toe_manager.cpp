//cpp
#include "tic_tac_toe_manager.h"

void TicTacToeManager::save_game(TicTacToe game)
{
    games.push_back(game);
    update_winner_count(game.get_winner());
}

void TicTacToeManager::display_history() const
{
    for(auto game : games)
    {
        cout << game;
    }
}

void TicTacToeManager::get_winner_total(int& x, int& o, int& t)
{
    x = x_win;
    o = o_win;
    t = ties;
}

void TicTacToeManager::update_winner_count(string winner)
{
    if (winner == "X")
    {
        x_win++;
    }
    else if (winner == "O")
    {
        o_win++;
    }
    else
    {
        ties++;
    }
}

ostream& operator<<(ostream& out, const TicTacToeManager& manager)
{
    for(auto game : manager.games)
    {
        out << game;
    }
    return out;
}