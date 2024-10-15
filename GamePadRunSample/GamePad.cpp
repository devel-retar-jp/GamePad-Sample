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
//
#include "GamePad.h"
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//�f�B�X�g���N�^
GanePadOBJ::~GanePadOBJ()
{
	//�R���g���N�^�͓����񂯂ǁA�f�B�X�g���N�^�͓����I
	// 
	//�Q�[���R���g���[���[���
	deinitGamePad();
	//
	return;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//�Q�[���R���g���[���[������
void GanePadOBJ::initGamePad()
{
	// DirectInput�̏�����
	if (DirectInput8Create(GetModuleHandle(NULL), DIRECTINPUT_VERSION, IID_IDirectInput8, (void**)&gameInput, NULL) != DI_OK) {
		//std::cout << "DirectInput initialization failed." << std::endl;
		*eFlag = FALSE;
		return;
	}

	// �W���C�X�e�B�b�N�̏�����
	if (gameInput->CreateDevice(GUID_Joystick, &gameJoystick, NULL) != DI_OK) {
		//std::cout << "Joystick initialization failed." << std::endl;
		gameInput->Release();
		*eFlag = FALSE;
		return;
	}

	// �f�[�^�t�H�[�}�b�g�̐ݒ�  c_dfDIJoystick -> c_dfDIJoystick2 �E�E�E����I�I�I
	if (gameJoystick->SetDataFormat(&c_dfDIJoystick2) != DI_OK)
	{
		std::cout << "Failed to set joystick data format." << std::endl;
		gameJoystick->Release();
		gameInput->Release();
		*eFlag = FALSE;
		return;
	}

	// �������[�h�̐ݒ�
	if (gameJoystick->SetCooperativeLevel(NULL, DISCL_BACKGROUND | DISCL_NONEXCLUSIVE) != DI_OK) {
		std::cout << "Failed to set cooperative level." << std::endl;
		gameJoystick->Release();
		gameInput->Release();
		*eFlag = FALSE;
		return;
	}

	// �W���C�X�e�B�b�N�̃A�N�Z�X���擾
	if (gameJoystick->Acquire() != DI_OK) {
		std::cout << "Failed to acquire joystick." << std::endl;
		gameJoystick->Release();
		gameInput->Release();
		*eFlag = FALSE;
		return;
	}
	//
	*eFlag = TRUE;
	return;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//�Q�[���R���g���[���[���
void GanePadOBJ::deinitGamePad()
{
	if (*eFlag == TRUE)
	{
		// ���\�[�X�̉��
		gameJoystick->Unacquire();
		gameJoystick->Release();
		gameInput->Release();
		*eFlag = FALSE;
	}
	return;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// ���ۂ̏������s�����\�b�h
void GanePadOBJ::InputThread()
{
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//�Q�[���R���g���[���[������
	initGamePad();
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//�Q�[���p�b�h
	while (*eFlag)
	{
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////
		//�Q�[���p�b�h ���̓f�[�^�̎擾
		DIJOYSTATE2 js = {};
		HRESULT hr = gameJoystick->GetDeviceState(sizeof(DIJOYSTATE2), &js);
		if (hr == DI_OK)
		{
			/////////////////////////////////////////////////////////////////////////////////////////////////////////
			//���^�[���ɓ����
			*toMode = js;
			/////////////////////////////////////////////////////////////////////////////////////////////////////////
			//DEBUG �f�[�^�T���v��
			std::cout << "IX:IY:IZ" << std::endl;
			std::cout
				<< js.lX
				<< ":" << js.lY
				<< ":" << js.lZ
				<< std::endl;
			// X�b�ԃv���O�������~
			std::chrono::milliseconds sleepDuration(500);
			std::this_thread::sleep_for(sleepDuration);
			/////////////////////////////////////////////////////////////////////////////////////////////////////////
		}
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////
		// X�b�ԃv���O�������~
		std::chrono::milliseconds sleepDuration(renewTime);
		std::this_thread::sleep_for(sleepDuration);
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////
	}
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//// X�b�ԃv���O�������~ =>�X���b�h�œ���Ȃ��Ɠd�C�H���ɂȂ�܂�
	deinitGamePad();
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	return;
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
