#pragma once
#include <map>
#include "Game.h"
#include <string>
#include "PlayerInfo.h"

class GameManager
{
public:
	map<int, Game> aGames;
	GameManager();
	int MatchPlayer(PlayerInfo);
	void CreateGame(int, int, std::string);
	void AddPlayerToGame(int, PlayerInfo);
	void SendStart(int);
	~GameManager();
};

