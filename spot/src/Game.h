#ifndef GAME_H
#define GAME_H

#include "Define.h"
#include <stdlib.h>
#include <stdio.h>
#include "DxLib.h"
#include <time.h>

class Game
{
public:
	Game::Game();
	Game::~Game();
	static void Start();
	static bool Init();
	static bool Load();
	static bool ClickCheck(int CircleX, int CircleY);

private:

};

#endif



