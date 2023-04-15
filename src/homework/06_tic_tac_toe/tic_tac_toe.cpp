//cpp
#include "tic_tac_toe.h"

TicTacToe::TicTacToe(int size) : pegs(size * size, " ")
{

}

bool TicTacToe::game_over()
{
    if (check_row_win() || check_column_win() || check_diagonal_win())
    {
        set_winner();
        return true;
    }
    else if (check_board_full())
    {
        winner = "C";
        return true;
    }
    else
    {
        return false;
    }
}

void TicTacToe::start_game(string first_player)
{
    player = first_player;
    clear_board();
}

void TicTacToe::mark_board(int position)
{
    pegs[position - 1] = player;
    set_next_player();
}

string TicTacToe::get_player() const
{
    return player;
}

string TicTacToe::get_winner() const
{
    return winner;
}
vector<string>TicTacToe::get_pegs()const
{
    return pegs;
}


bool TicTacToe::check_column_win()
{
    return false;
}

bool TicTacToe::check_row_win()
{
     return false;
}

bool TicTacToe::check_diagonal_win()
{
    return false;
}

void TicTacToe::set_winner()
{
    if (player == "X")
    {
        winner = "O";
    }
    else
    {
        winner = "X";
    }
}

void TicTacToe::set_next_player()
{
    player = (player == "X") ? "O" : "X";
}

bool TicTacToe::check_board_full()
{
    for(auto peg : pegs)
    {
        if (peg == " ")
        {
            return false;
        }
    }
    return true;
}

void TicTacToe::clear_board()
{
    for (auto& peg : pegs)
    {
        peg = " ";
    }
}

ostream& operator<<(ostream& out, const TicTacToe& game)
{
    out << "Board: \n";
    if(game.pegs.size() == 9)
    {
        for(int i = 0; i < 3; i++)
        {
        out << game.pegs[i*3] << "|" << game.pegs[i*3+1] << "|" << game.pegs[i*3+2] << "\n";
        }
    }
    else if(game.pegs.size() == 16)
    {
        for(int i=0; i<4; i++)
        {
            out << game.pegs[i*4] << "|" << game.pegs[i*4+1] << "|" << game.pegs[i*4+2] << "|" << game.pegs[i*4+3] << "\n";
        }
    }
    out << "\n";
    return out;
}

istream& operator>>(istream& in, TicTacToe& game)
{
    int position;
    int max_position = game.pegs.size();
    do
    {
        cout << " Enter position(1-" << max_position << "): ";
        in>> position;
    } while (position < 1 || position > max_position);
    game.mark_board(position);
    return in;
}