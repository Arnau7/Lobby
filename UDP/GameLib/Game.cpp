#include "Game.h"



Game::Game()
{
}
Game::Game(int _id, int _maxPlayers, string _gameName) {
	gameID = _id;
	maxPlayers = _maxPlayers;
	gameName = _gameName;
}


Game::~Game()
{

}
