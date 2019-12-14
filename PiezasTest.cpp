/**
 * Unit Tests for Piezas
**/

#include <gtest/gtest.h>
#include "Piezas.h"
 
class PiezasTest : public ::testing::Test
{
	protected:
		PiezasTest(){} //constructor runs before each test
		virtual ~PiezasTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

TEST(PiezasTest, sanityCheck)
{
	Piezas new_game;

	ASSERT_TRUE(true);
}



TEST(PiezasTest, checkEmpty)
{
	Piezas new_game;

	ASSERT_EQ(new_game.pieceAt(0, 0), Blank);
}




TEST(PiezasTest, placeFirstPiece)
{
	Piezas new_game;

	Piece result = new_game.dropPiece(0);

	ASSERT_EQ(result, X);
}



TEST(PiezasTest, checkTurnChange)
{
	Piezas new_game;

	new_game.dropPiece(0);

	ASSERT_EQ(new_game.dropPiece(0), O);
}




TEST(PiezasTest, checkFullColumn)
{
	Piezas new_game;

	new_game.dropPiece(0);
	new_game.dropPiece(0);
	new_game.dropPiece(0);

	ASSERT_EQ(new_game.dropPiece(0), Blank);
}




TEST(PiezasTest, checkPiecePlaced)
{
	Piezas new_game;

	new_game.dropPiece(0);

	ASSERT_EQ(new_game.pieceAt(2, 0), X);
}




TEST(PiezasTest, checkPieceplaceSecond)
{
	Piezas new_game;

	new_game.dropPiece(0);
	new_game.dropPiece(0);

	ASSERT_EQ(new_game.pieceAt(2, 0), X);
}




TEST(PiezasTest, checkOutOfBoundsRow)
{
	Piezas new_game;

	ASSERT_EQ(new_game.pieceAt(-1, 0), Invalid);
}




TEST(PiezasTest, checkOutOfBoundsColumn)
{
	Piezas new_game;

	ASSERT_EQ(new_game.pieceAt(0, -1), Invalid);
}




TEST(PiezasTest, checkOutOfBoundsBoth)
{
	Piezas new_game;

	ASSERT_EQ(new_game.pieceAt(-1, -1), Invalid);
}




TEST(PiezasTest, checkReset)
{
	Piezas new_game;

	new_game.dropPiece(0);
	new_game.reset();

	ASSERT_EQ(new_game.dropPiece(0), X);
}



TEST(PiezasTest, checkSecondTurn)
{
	Piezas new_game;

	new_game.dropPiece(0);

	ASSERT_EQ(new_game.dropPiece(0), O);
}




TEST(PiezasTest, checkdropPieceOutOfBoundsLower)
{
	Piezas new_game;

	ASSERT_EQ(new_game.dropPiece(-1), Invalid);
}




TEST(PiezasTest, checkdropPieceOutOfBoundsUpper)
{
	Piezas new_game;

	ASSERT_EQ(new_game.dropPiece(7), Invalid );
}




TEST(PiezasTest, checkGameUnfinished)
{
	Piezas new_game;

	ASSERT_EQ(new_game.gameState(), Invalid);
}




TEST(PiezasTest, checkGameUnFinishedAndTie)
{
	Piezas new_game;

	for(int y = 0; y < 3; y++)
	{
		for(int x = 0; x < 4; x++)
		{
			new_game.dropPiece(x);
		}
	}

	ASSERT_EQ(new_game.gameState(), Blank);
}




TEST(PiezasTest, checkGamefinishedTieGreatestOne)
{
	Piezas new_game;

	for(int x = 0; x < 4; x++)
	{
		for(int y = 0; y < 3; y++)
		{
			new_game.dropPiece(x);
		}
	}

	ASSERT_EQ(new_game.gameState(), Blank);
}




TEST(PiezasTest, checkGameFinishedXWin)
{
	Piezas new_game;

	new_game.dropPiece(0);
	new_game.dropPiece(0);

	new_game.dropPiece(0);
	new_game.dropPiece(1);

	new_game.dropPiece(2);
	new_game.dropPiece(2);

	new_game.dropPiece(3);
	new_game.dropPiece(3);

	new_game.dropPiece(3);
	new_game.dropPiece(1);

	new_game.dropPiece(2);
	new_game.dropPiece(1);

	ASSERT_EQ(new_game.gameState(), X);
}




TEST(PiezasTest, checkGameFinishedOWin)
{
	Piezas new_game;

	new_game.dropPiece(0);
	new_game.dropPiece(1);

	new_game.dropPiece(1);
	new_game.dropPiece(2);

	new_game.dropPiece(2);
	new_game.dropPiece(3);

	new_game.dropPiece(3);
	new_game.dropPiece(3);

	new_game.dropPiece(0);
	new_game.dropPiece(2);

	new_game.dropPiece(0);
	new_game.dropPiece(1);

	ASSERT_EQ(new_game.gameState(), O);
}




TEST(PiezasTest, checkGameFinishedXWinVert)
{
	Piezas new_game;

	new_game.dropPiece(0);
	new_game.dropPiece(1);

	new_game.dropPiece(2);
	new_game.dropPiece(3);

	new_game.dropPiece(0);
	new_game.dropPiece(2);

	new_game.dropPiece(3);
	new_game.dropPiece(3);

	new_game.dropPiece(0);
	new_game.dropPiece(1);

	new_game.dropPiece(1);
	new_game.dropPiece(2);

	ASSERT_EQ(new_game.gameState(), X);
}




TEST(PiezasTest, checkGameFinishedOWinVert)
{
	Piezas new_game;

	new_game.dropPiece(1);
	new_game.dropPiece(0);

	new_game.dropPiece(2);
	new_game.dropPiece(0);

	new_game.dropPiece(2);
	new_game.dropPiece(0);

	new_game.dropPiece(3);
	new_game.dropPiece(3);

	new_game.dropPiece(3);
	new_game.dropPiece(2);

	new_game.dropPiece(1);
	new_game.dropPiece(1);

	ASSERT_EQ(new_game.gameState(), O);
}