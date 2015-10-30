#include "Game.h"

// コンストラクタ
Game::Game(){
	Game::Init();
	Game::Load();

}


// デストラクタ
Game::~Game(){

	DxLib_End();

}

bool Game::Init(){
	ChangeWindowMode(TRUE);
	SetWindowSizeChangeEnableFlag(TRUE, 1);
	SetGraphMode(WINDOW_W, WINDOW_H, 32);
	if (DxLib_Init() == -1 || SetDrawScreen(DX_SCREEN_BACK) != 0) 
		return false;
	return true;
}

bool Game::Load(){

	srand((unsigned)time(NULL));
	return true;
	
}

void Game::Start(){
	int CircleX, CircleY, Cr, ClickCount = 0;
	Cr = GetColor(255, 255, 255);
	bool ClickFlag = true;

	while (!ProcessMessage()){
		ClearDrawScreen();
		
		if ( ClickFlag == true )
		{
			CircleX = rand() % WINDOW_W - CIRCLE_R + 1;
			CircleY = rand() % WINDOW_H - CIRCLE_R + 1;
			ClickFlag = false;
		}
		
		if (ClickCheck(CircleX, CircleY) == true) {
			ClickFlag = true;
			ClickCount++;
		}

		DrawCircle(CircleX, CircleY, CIRCLE_R, Cr);

		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1)
			break;

		ScreenFlip();
	}

}

// クリックされたか判定
bool Game::ClickCheck(int CircleX,int CircleY)
{
	int ClickX, ClickY, Button;
	if (GetMouseInputLog(&Button, &ClickX, &ClickY, TRUE) == 0)
	{
		if ((Button & MOUSE_INPUT_LEFT) != 0)
		{
			// 座標が取れたのでクリックされたかの判定
			if ((CircleX + CIRCLE_R >= ClickX && CircleX - CIRCLE_R <= ClickX)
			&&  (CircleY + CIRCLE_R >= ClickY && CircleY - CIRCLE_R <= ClickY))
				return true;
		}
	}
	return false;
}