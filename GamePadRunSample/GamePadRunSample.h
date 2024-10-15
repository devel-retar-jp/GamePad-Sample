/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///
///
/// GamePad制御サンプル
/// 
/// Main: GamePadRunSample.h
/// 
/// static std::atomic<DIJOYSTATE2>* GamePadOBJtOutMode = new std::atomic<DIJOYSTATE2>();
/// 結果が入ってくる
/// 
/// 
///	
///   履歴	
///   2024/10/15 V1.00 First
///
///
///                        Copyright(c) 2024, Retar.jp, All Rights Reserved.
///                        http://www.retar.jp/
/// 
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma once
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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
