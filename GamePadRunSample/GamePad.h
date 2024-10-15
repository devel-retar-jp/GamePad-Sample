/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///
///
/// GamePad制御
/// 
/// Main: GamePad.cpp
/// 
///
/// 
/// 
///	
///   履歴	
///   2024/10/14 V1.00 First
///
///
///                        Copyright(c) 2024, Retar.jp, All Rights Reserved.
///                        http://www.retar.jp/
/// 
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma once
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Windows ヘッダー ファイル
//#define WIN32_LEAN_AND_MEAN										// Windows ヘッダーからほとんど使用されていない部分を除外する
#include <Windows.h>
#include <thread>
#include <iostream>
#include <string>
#include <time.h>
#include <cstdio>
#include <io.h>
#include <sstream>
#include <fstream>
#include <fcntl.h>
#include <stddef.h>
#include <vector>
#include <iomanip>
#include <shellapi.h>
#include <tchar.h>
#include <mutex>
#include <regex>
#include <algorithm>
#include <random>
//#include <Xinput.h>			//古いPS2ゲームコントローラーらしい
#include <dinput.h>				//HIDゲームコントローラー用
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//// GamePad関数
class GanePadOBJ
{
public:
	//コントラクタ
	GanePadOBJ(
		std::atomic<bool>* e
		, int i
		, std::atomic<DIJOYSTATE2>* t
	) :  eFlag(e), renewTime(i), toMode(t) {}
	//デイストラクタ
	~GanePadOBJ();
	// 実際の処理を行うメソッド
	void InputThread();
	//ゲームコントローラー
	void initGamePad();
	void deinitGamePad();
	//ゲームコントローラー Stats
	BOOLEAN getGamePadStats(void) { return *eFlag; }
private:
	std::atomic<bool>* eFlag;
	int renewTime = 5;
	std::atomic<DIJOYSTATE2>* toMode;
	//
	//ゲームコントローラー
	IDirectInput8* gameInput = {};
	IDirectInputDevice8* gameJoystick = {};
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
