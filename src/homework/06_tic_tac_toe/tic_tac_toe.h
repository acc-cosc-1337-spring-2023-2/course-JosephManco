#include <iostream>
#include <string>
#include <vector>
#include <memory>

using std::cout; using std::cin; using std::string; using std::vector; using std::istream; using std::ostream;

#ifndef TICTACTOE_H
#define TICTACTOE_H
class TicTacToe
{
    public:
        bool game_over();
        void start_game(string first_player);
        void mark_board(int position);
        string get_player() const;
        string get_winner() const;
        vector<string> get_pegs() const;
        friend istream& operator>>(istream& in, TicTacToe& game);
        friend ostream & operator<<(ostream& out, const TicTacToe& game);

    private:
        void set_next_player();
        bool check_board_full();
        void clear_board();
        void set_winner();
        bool check_column_win();
        bool check_row_win();
        bool check_diagonal_win();

        string player;
        vector<string> pegs = {" ", " ", " ", " ", " ", " ", " ", " ", " "};
        string winner;

};
#endif