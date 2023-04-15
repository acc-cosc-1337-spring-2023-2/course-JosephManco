#include <iostream>
#include <string>
#include <vector>
#include <memory>

using std::cout; using std::cin; using std::string; using std::vector; using std::istream; using std::ostream;using std::unique_ptr; using std::make_unique;

#ifndef TICTACTOE_H
#define TICTACTOE_H
class TicTacToe
{
    public:
        TicTacToe() = default;
        TicTacToe(int size);
        bool game_over();
        void start_game(string first_player);
        void mark_board(int position);
        string get_player() const;
        string get_winner() const;
        vector<string> get_pegs() const;
        friend istream& operator>>(istream& in, TicTacToe& game);
        friend ostream & operator<<(ostream& out, const TicTacToe& game);

    protected:
        vector<string> pegs;
        virtual bool check_column_win();
        virtual bool check_row_win();
        virtual bool check_diagonal_win();

    private:
        void set_next_player();
        bool check_board_full();
        void clear_board();
        void set_winner();
        string player;
        string winner;
};
#endif