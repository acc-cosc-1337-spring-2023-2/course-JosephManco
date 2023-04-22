#include "tic_tac_toe_data.h"

void TicTacToeData::save_games(const vector<unique_ptr<TicTacToe>>& games)
{
    std::ofstream file(file_name);

    if(file)
    {
        for(const auto& game : games)
        {
            for(const auto& peg : game->get_pegs())
            {
                file << peg;
            }
            file << game->get_winner() << "\n";
        }
    }
    file.close();
}

vector<unique_ptr<TicTacToe>> TicTacToeData::get_games()
{
    vector<unique_ptr<TicTacToe>> boards;
    std::ifstream file(file_name);

    if(file)
    {
        string line;

        while(getline(file, line))
        {
            vector<string> pegs;
            for(size_t i = 0; i < line.size() - 1; i++)
            {
                pegs.push_back(string(1, line[i]));
            }

            string winner{ line[line.size() - 1]};
            unique_ptr<TicTacToe> board{ nullptr };

            if (pegs.size() == 9)
            {
                board = make_unique<TicTacToe3>(pegs, winner); 
            }
            else if (pegs.size() == 16)
            {
                board = make_unique<TicTacToe4>(pegs, winner);
            }
            boards.push_back(std::move(board));
        }
    }
    file.close();
    return boards;
}