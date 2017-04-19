#include "DxLib.h"
#include "../include/Keyboard.h"
#include "../include/PlayerMgr.h"
#include "../include/Graph.h"

int WINAPI WinMain(HINSTANCE,HINSTANCE,LPSTR,int){

	ChangeWindowMode(TRUE),DxLib_Init(),SetDrawScreen(DX_SCREEN_BACK);

	PlayerMgr_Initialize();
	Graph_Initialize();

	while(!ScreenFlip() && !ProcessMessage() && !ClearDrawScreen()){

		Keyboard_Update();
		//Graph_Update();
		PlayerMgr_Update();

		PlayerMgr_Draw();
		Graph_Draw();


		if(Keyboard_Get(KEY_INPUT_ESCAPE) > 0){
			break;
		}

	}
	PlayerMgr_Finalize();

	DxLib_End();

	return 0;
}