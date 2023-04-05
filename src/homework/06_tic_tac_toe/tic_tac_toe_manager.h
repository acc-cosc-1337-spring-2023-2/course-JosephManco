//h
#ifndef TIC_TAC_TOE_MANAGER_H
#define TIC_TAC_TOE_MANAGER_H

#include"tic_tac_toe.h"

class TicTacToeManager
{
    public:
        void save_game(TicTacToe b); 
        friend ostream& operator <<(ostream& out, const TicTacToeManager& manager);
        void get_winner_total(int& o, int & x, int& t);
        void display_history() const;

    private:
        vector<TicTacToe> games;
        int x_win = 0;
        int o_win = 0;
        int ties = 0;
        void update_winner_count(string winner);
};


#endif