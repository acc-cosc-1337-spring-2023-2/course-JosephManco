//cpp
#include "tic_tac_toe.h"

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

void TicTacToe::display_board() const
{
    cout << pegs[0] << "|" << pegs[1] << "|" << pegs[2] << "\n";
    cout << "-+-+-\n";
    cout << pegs[3] << "|" << pegs[4] << "|" << pegs[5] << "\n";
    cout << "-+-+-\n";
    cout << pegs[6] << "|" << pegs[7] << "|" << pegs[8] << "\n";
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
    if (pegs[0] != " " && pegs[0] == pegs[3] && pegs[3] == pegs[6])
    {
        return true;
    } 
    else if (pegs[1] != " " && pegs[1] == pegs[4] && pegs[4] == pegs[7])
    {
        return true;
    }
    else if (pegs[2] != " " && pegs[2] == pegs[5] && pegs[5] == pegs[8])
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool TicTacToe::check_row_win()
{
    if (pegs[0] != " " && pegs[0] == pegs[1] && pegs[1] == pegs[2])
    {
        return true;
    } 
    else if (pegs[3] != " " && pegs[3] == pegs[4] && pegs[4] == pegs[5])
    {
        return true;
    }
    else if (pegs[6] != " " && pegs[6] == pegs[7] && pegs[7] == pegs[8])
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool TicTacToe::check_diagonal_win()
{
    if (pegs[0]!= " " && pegs[0] == pegs[4] && pegs[4] == pegs[8])
    {
        return true;
    }
    else if(pegs[2] != " " && pegs[2] == pegs[4] && pegs[4] == pegs[6])
    {
        return true;
    }
    else
    {
        return false;
    }
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