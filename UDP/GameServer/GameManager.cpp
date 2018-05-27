#include "GameManager.h"



GameManager::GameManager()
{
}

int GameManager::MatchPlayer(PlayerInfo player) {
	// Cerca quina de les partides de aGames és la mes adequada (segons el wins) i retorna l'Id de la partida
	// Aqui dins ja enviam tot al player???
}

void GameManager::CreateGame(int idGame, int maxPlayer, std::string gameName) {
	Game tempGame(idGame, maxPlayer, gameName);
	aGames[idGame] = tempGame;
}

void GameManager::AddPlayerToGame(int idGame,PlayerInfo player) {
	aGames[idGame].AddPlayerToGame(player);
}

void GameManager::SendStart(int idGame) {
	aGames[idGame].SendStart();
}

GameManager::~GameManager()
{
}
