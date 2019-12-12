#include "Piezas.h"
#include <vector>
/** CLASS Piezas
 * Class for representing a Piezas vertical board, which is roughly based
 * on the game "Connect Four" where pieces are placed in a column and 
 * fall to the bottom of the column, or on top of other pieces already in
 * that column. For an illustration of the board, see:
 *  https://en.wikipedia.org/wiki/Connect_Four
 *
 * Board coordinates [row,col] should match with:
 * [2,0][2,1][2,2][2,3]
 * [1,0][1,1][1,2][1,3]
 * [0,0][0,1][0,2][0,3]
 * So that a piece dropped in column 2 should take [0,2] and the next one
 * dropped in column 2 should take [1,2].
**/


/**
 * Constructor sets an empty board (default 3 rows, 4 columns) and 
 * specifies it is X's turn first
**/
Piezas::Piezas()
{
    for(int y = 0; y < 3; y++)
    {
        std::vector<Piece> next_row;
        for(unsigned x = 0; x < 4; x++)
        {
            next_row.push_back(Blank);
        }

        board.push_back(next_row);
    }

    turn = X;
}

/**
 * Resets each board location to the Blank Piece value, with a board of the
 * same size as previously specified
**/
void Piezas::reset()
{
    for(unsigned y = 0; y < board.size(); y++)
    {
        for(unsigned x = 0; x < board[y].size(); x++)
        {
            board[y][x] = Blank;
        }
    }

    turn = X;
}

/**
 * Places a piece of the current turn on the board, returns what
 * piece is placed, and toggles which Piece's turn it is. dropPiece does 
 * NOT allow to place a piece in a location where a column is full.
 * In that case, placePiece returns Piece Blank value 
 * Out of bounds coordinates return the Piece Invalid value
 * Trying to drop a piece where it cannot be placed loses the player's turn
**/ 
Piece Piezas::dropPiece(int column)
{
    Piece to_return = Invalid;

    if(0 <= column && (unsigned)column < board[0].size())
    {
        if(pieceAt(0, column) == Blank)
        {
            for(unsigned y = 0; y < board.size(); y++)
            {
                if(y + 1 < board.size())
                {
                    if(pieceAt(y+1, column) != Blank)
                    {
                        to_return = board[y][column] = turn;
                        if(turn == X)
                        {
                            turn = O;
                        }
                        else
                        {
                            turn = X;
                        }

                        return to_return;
                    }
                    else if(pieceAt(y+1, column) == Invalid)
                    {
                        return to_return;
                    }
                }
            }
        }
        else
        {
            return Blank;
        }
    }

    return to_return;
}

/**
 * Returns what piece is at the provided coordinates, or Blank if there
 * are no pieces there, or Invalid if the coordinates are out of bounds
**/
Piece Piezas::pieceAt(int row, int column)
{
    if(0 <= row && row < board.size() &&
    0 <= column && column < board[row].size())
    {
        return board[row][column];
    }

    return Invalid;
}

/**
 * Returns which Piece has won, if there is a winner, Invalid if the game
 * is not over, or Blank if the board is filled and no one has won ("tie").
 * For a game to be over, all locations on the board must be filled with X's 
 * and O's (i.e. no remaining Blank spaces). The winner is which player has
 * the most adjacent pieces in a single line. Lines can go either vertically
 * or horizontally. If both X's and O's have the same max number of pieces in a
 * line, it is a tie.
**/
Piece Piezas::gameState()
{
    Piece current_piece;
    int vertical_count = 0;
    int horizontal_count = 0;
    int x_max = 0;
    int o_max = 0;

    for(unsigned y = 0; y < board.size(); y++)
    {
        for(unsigned x = 0; x < board[y].size(); x++)
        {
            if(pieceAt(y, x) == current_piece)
            {

            }
            else
            {
                if(pieceAt(y, x) == X)
                {
                    if(vertical_count > x_max)
                    {
                        if(vertical_count > horizontal_count)
                        {
                            x_max = vertical_count;
                        }
                        else
                        {
                            x_max = horizontal_count;
                        }
                    }
                    else if(horizontal_count > x_max)
                    {
                        x_max = horizontal_count;
                    }

                    current_piece = O;
                }
                else if(pieceAt(y, x) == O)
                {
                    if(vertical_count > o_max)
                    {
                        if(vertical_count > horizontal_count)
                        {
                            o_max = vertical_count;
                        }
                        else
                        {
                            o_max = horizontal_count;
                        }
                    }
                    else if(horizontal_count > o_max)
                    {
                        o_max = horizontal_count;
                    }

                    current_piece =X;
                }
                else
                {
                    return Blank;
                }

                vertical_count = 0;
                horizontal_count = 0;
            }
        }
    }

    if(x_max > o_max)
    {
        return X;
    }
    else
    {
        return O;
    }

    return Invalid;
}