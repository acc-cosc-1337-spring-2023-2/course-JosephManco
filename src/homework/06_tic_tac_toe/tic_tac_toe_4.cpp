#include "tic_tac_toe_4.h"

bool TicTacToe4 :: check_column_win()
{
     if (pegs[0] != " " && pegs[0] == pegs[4] && pegs[4] == pegs[8] && pegs[8] == pegs[12])
    {
        return true;
    }
    else if (pegs[1] != " " && pegs[1] == pegs[5] && pegs[5] == pegs[9] && pegs[9] == pegs[13])
    {
        return true;
    }
    else if (pegs[2] != " " && pegs[2] == pegs[6] && pegs[6] == pegs[10] && pegs[10] == pegs[14])
    {
        return true;
    }
    else if (pegs[3] != " " && pegs[3] == pegs[7] && pegs[7] == pegs[11] && pegs[11] == pegs[15])
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool TicTacToe4::check_row_win()
{
        if (pegs[0] != " " && pegs[0] == pegs[1] && pegs[1] == pegs[2] && pegs[2] == pegs[3])
    {
        return true;
    } 
    else if (pegs[4] != " " && pegs[4] == pegs[5] && pegs[5] == pegs[6] && pegs[6] == pegs[7])
    {
        return true;
    }
    else if (pegs[8] != " " && pegs[8] == pegs[9] && pegs[9] == pegs[10] && pegs[10] == pegs[11])
    {
        return true;
    }
    else if (pegs[12] != " " && pegs[12] == pegs[13] && pegs[13] == pegs[14] && pegs[14] == pegs[15])
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool TicTacToe4::check_diagonal_win()
{
        if (pegs[0] != " " && pegs[0] == pegs[5] && pegs[5] == pegs[10] && pegs[10] == pegs[15])
    {
        return true;
    } 
    else if (pegs[3] != " " && pegs[3] == pegs[6] && pegs[6] == pegs[9] && pegs[9] == pegs[12])
    {
        return true;
    }
    else
    {
        return false;
    }
}

