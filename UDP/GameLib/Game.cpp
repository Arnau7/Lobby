#include "Game.h"



Game::Game()
{
}
Game::Game(int _id, int _maxPlayers, string _gameName) {
	idMatch = _id;
	maxPlayers = _maxPlayers;
	gameName = _gameName;
}


Game::~Game()
{

}


void Game::AddPlayerToGame(PlayerInfo player)
{
	aPlayers[player.GetId()] = player;
}

void Game::StartGame()
{
// Start the clock
}

void Game::SendStart() {
	// Send start message to all players
}