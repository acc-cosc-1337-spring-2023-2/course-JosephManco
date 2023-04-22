#ifndef TICTACTOEDATA_H
#define TICTACTOEDATA_H

#include"tic_tac_toe.h"
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"

class TicTacToeData
{
    public:
        void save_games(const vector<unique_ptr<TicTacToe>>& games);
        vector<unique_ptr<TicTacToe>> get_games();

    private:
        const string file_name{ "tictactoe.dat" };
};



#endif