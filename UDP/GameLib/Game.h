#pragma once
#include <iostream>
#include "PlayerInfo.h"
#include <map>

using namespace std;
using namespace sf;

class Game
{
private:
	string name;
	int maxPlayers;
	int playersOnline;
	map<int, PlayerInfo> aPlayers;
	float coinX, coinY;
	Time clock;
	int gameID;
public:
	Game();
	Game(int, int, std::string);
	void Update();
	~Game();

};

