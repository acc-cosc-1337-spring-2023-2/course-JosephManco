#ifndef TICTACTOE3_H
#define TICTACTOE3_H

#include "tic_tac_toe.h"

class TicTacToe3 : public TicTacToe
{
    public:
        TicTacToe3() : TicTacToe(3) {}
        TicTacToe3(vector<string> p, string winner) : TicTacToe(p, winner){}

    private:
        bool check_column_win();
        bool check_row_win();
        bool check_diagonal_win();
};

#endif