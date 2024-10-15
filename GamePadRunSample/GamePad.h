/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///
///
/// GamePad����
/// 
/// Main: GamePad.cpp
/// 
///
/// 
/// 
///	
///   ����	
///   2024/10/14 V1.00 First
///
///
///                        Copyright(c) 2024, Retar.jp, All Rights Reserved.
///                        http://www.retar.jp/
/// 
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma once
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Windows �w�b�_�[ �t�@�C��
//#define WIN32_LEAN_AND_MEAN										// Windows �w�b�_�[����قƂ�ǎg�p����Ă��Ȃ����������O����
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
//#include <Xinput.h>			//�Â�PS2�Q�[���R���g���[���[�炵��
#include <dinput.h>				//HID�Q�[���R���g���[���[�p
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//// GamePad�֐�
class GanePadOBJ
{
public:
	//�R���g���N�^
	GanePadOBJ(
		std::atomic<bool>* e
		, int i
		, std::atomic<DIJOYSTATE2>* t
	) :  eFlag(e), renewTime(i), toMode(t) {}
	//�f�C�X�g���N�^
	~GanePadOBJ();
	// ���ۂ̏������s�����\�b�h
	void InputThread();
	//�Q�[���R���g���[���[
	void initGamePad();
	void deinitGamePad();
	//�Q�[���R���g���[���[ Stats
	BOOLEAN getGamePadStats(void) { return *eFlag; }
private:
	std::atomic<bool>* eFlag;
	int renewTime = 5;
	std::atomic<DIJOYSTATE2>* toMode;
	//
	//�Q�[���R���g���[���[
	IDirectInput8* gameInput = {};
	IDirectInputDevice8* gameJoystick = {};
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
