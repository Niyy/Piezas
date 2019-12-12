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

	ASSERT_EQ(new_game.dropPiece(0), X);
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

	new_game.dropPiece(0)
	new_game.dropPiece(0)
	new_game.dropPiece(0)

	ASSERT_EQ(new_game.dropPiece(0), Blank);
}




TEST(PiezasTest, checkPiecePlaced)
{
	Piezas new_game;

	new_game.dropPiece(0)

	ASSERT_EQ(new_game.pieceAt(2, 0), X);
}




TEST(PiezasTest, checkPieceplaceSecond)
{
	Piezas new_game;

	new_game.dropPiece(0)
	new_game.dropPiece(0)

	ASSERT_EQ(new_game.pieceAt(2, 0), X);
}




TEST(PiezasTest, checkOutOfBoundsRow)
{
	Piezas new_game;

	ASSERT_EQ(new_game.pieceAt(-1, 0), X);
}




TEST(PiezasTest, checkOutOfBoundsColumn)
{
	Piezas new_game;

	ASSERT_EQ(new_game.pieceAt(0, -1), X);
}




TEST(PiezasTest, checkOutOfBoundsBoth)
{
	Piezas new_game;

	ASSERT_EQ(new_game.pieceAt(-1, -1), X);
}