#include "BoardManager.h"

using namespace std;
using namespace sf;


BoardManager::BoardManager()
{
}

BoardManager::~BoardManager()
{
}

void BoardManager::setupBoard(RenderWindow& window)
{
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			_playerBoard[i][j].setPosition(100.f + j * 125.f, 850.f - i * 125.f);

			if (i >= 1 && i <= 5 && j == 0) {

				_playerBoard[i][j].setReserved(true);
				_leftReserve.push_back(_playerBoard[i][j]);
			}
			else if(i >= 1 && i <= 5 && j == 6){
				
				_playerBoard[i][j].setReserved(true);
				_rightReserve.push_back(_playerBoard[i][j]);
			}

			_playerBoard[i][j].draw(window);
		}
	}
}

void BoardManager::resetBoard()
{
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++){

			_playerBoard[i][j].setReserved(false);
			
			_playerBoard[i][j].setEmpty(true);
		}
	}

}
