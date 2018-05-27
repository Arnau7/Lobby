#pragma once
#include <map>
#include "Game.h"
#include <string>
#include "PlayerInfo.h"

class GameManager
{
public:
	map<int, Game> aGames;
	vector<PlayerInfo> inactivePlayers; //Si un jugador està més de X seg inactiu, el ficam aqui i les ajuntam quan basti per fer una partida
	// Podem fer-ho que el jugador mateix, te el clock d'inacctivitat i si detecta que no fa res en X seg, envia un missatge al server de: Estic inactiu
	// Aixi el server no ha de comprovar toooots els jugadors de totes les partides, cada iteració (Que menja bastant aixo)
	GameManager();
	int MatchPlayer(PlayerInfo);
	void CreateGame(int, int, std::string);
	void AddPlayerToGame(int, PlayerInfo);
	void SendStart(int);
	~GameManager();
};

