#pragma once
#include <iostream>
#include "PlayerInfo.h"
#include <map>

using namespace std;
using namespace sf;

class Game
{
private:
	int idMatch;
	string gameName;
	int maxPlayers;
	int playersOnline;
	map<int, PlayerInfo> aPlayers;
	sf::Clock clock;
	int wins; // Per al matchmaking
public:
	Game();
	Game(int, int, std::string);
	void AddPlayerToGame(PlayerInfo player);
	void StartGame();
	void Update();
	void SendStart();
	~Game();

};

