//cpp
#include "tic_tac_toe_manager.h"

TicTacToeManager::TicTacToeManager() : data{}, x_win{0}, o_win{0}, ties{0} {}

TicTacToeManager::TicTacToeManager(TicTacToeData& data) : data{data}, x_win{0}, o_win{0}, ties{0}
{
    games = data.get_games();
    for(const auto& game : games)
    {
        update_winner_count(game->get_winner());
    }
}

TicTacToeManager::~TicTacToeManager()
{
    data.save_games(games);
}

void TicTacToeManager::save_game(unique_ptr<TicTacToe>& b)
{
    update_winner_count(b->get_winner());
    games.push_back(std::move(b));
}

void TicTacToeManager::display_history() const
{
    for (size_t i = 0; i < games.size(); ++i)
    {
        cout << "Game " << i + 1 << ":\n";
        cout << *(games[i]) << "\n";
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
    out << "X wins: " << manager.x_win << "\n";
    out << "O wins: " << manager.o_win << "\n";
    out << "Ties: " << manager.ties << "\n";
    return out;
}