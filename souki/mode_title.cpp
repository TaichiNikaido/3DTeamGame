//=============================================================================
//
// �^�C�g�����[�h [mode_title.cpp]
// Author : ��K������
//
//=============================================================================

//*****************************************************************************
// �w�b�_�t�@�C���̃C���N���[�h
//*****************************************************************************
#include "main.h"
#include "manager.h"
#include "sound.h"
#include "keyboard.h"
#include "joystick.h"
#include "mode_title.h"
#include "title_logo.h"

//*****************************************************************************
// �}�N����`
//*****************************************************************************

//*****************************************************************************
// �ÓI�����o�ϐ��̏�����
//*****************************************************************************
CTitlelogo *CTitleMode::m_pTitlelogo = {};

//=============================================================================
// �R���X�g���N�^
//=============================================================================
CTitleMode::CTitleMode()
{
}

//=============================================================================
// �f�X�g���N�^
//=============================================================================
CTitleMode::~CTitleMode()
{
}

//=============================================================================
// ���������֐�
//=============================================================================
CTitleMode * CTitleMode::Create()
{
	//�^�C�g�����[�h�̃|�C���^
	CTitleMode * pTitleMode = NULL;
	//�����^�C�g�����[�h�̃|�C���^��NULL�̏ꍇ
	if (pTitleMode == NULL)
	{
		//�^�C�g�����[�h�̃������m��
		pTitleMode = new CTitleMode;
		//�����^�C�g�����[�h�̃|�C���^��NULL����Ȃ��ꍇ
		if (pTitleMode != NULL)
		{
			//�����������֐��Ăяo��
			pTitleMode->Init();
		}
	}
	//�^�C�g�����[�h�̃|�C���^��Ԃ�	
	return pTitleMode;
}

//=============================================================================
// �����������֐�
//=============================================================================
HRESULT CTitleMode::Init(void)
{
	//�����S���������֐��Ăяo��
	InitCreateAll();
	return S_OK;
}

//=============================================================================
// �I�������֐�
//=============================================================================
void CTitleMode::Uninit(void)
{
	// �������S�̃|�C���^���m�t�k�k����Ȃ��ꍇ
	if (m_pTitlelogo != NULL)
	{
		// ���S�̃|�C���^���m�t�k�k�ɂ���
		m_pTitlelogo = NULL;
	}
}

//=============================================================================
// �X�V�����֐�
//=============================================================================
void CTitleMode::Update(void)
{
	//�L�[�{�[�h�̎擾
	CKeyboard *pKeyboard = CManager::GetKeyboard();
	//�T�E���h�̎擾
	CSound * pSound = CManager::GetSound();
	//�W���C�X�e�B�b�N�̎擾
	CJoystick * pJoystick = CManager::GetJoystick();
	LPDIRECTINPUTDEVICE8 lpDIDevice = CJoystick::GetDevice();
	DIJOYSTATE js;
	//�W���C�X�e�B�b�N�̐U���擾
	LPDIRECTINPUTEFFECT pDIEffect = CJoystick::GetEffect();
	if (lpDIDevice != NULL)
	{
		lpDIDevice->Poll();
		lpDIDevice->GetDeviceState(sizeof(DIJOYSTATE), &js);
	}
	//����ENTER��A�{�^�����������Ƃ�
	if (pKeyboard->GetKeyboardTrigger(DIK_RETURN) || lpDIDevice != NULL &&pJoystick->GetJoystickTrigger(JS_A))
	{
		//�T�E���h�̒�~
		pSound->StopSound();
		//�����L���O�Ɉړ�
		CManager::StartFade(CManager::MODE_GAME);
	}
}

//=============================================================================
// �`�揈���֐�
//=============================================================================
void CTitleMode::Draw(void)
{
}

//=============================================================================
// �����S���������֐�
//=============================================================================
void CTitleMode::InitCreateAll(void)
{
	// �^�C�g�����S��NULL�Ȃ�
	if (m_pTitlelogo == NULL)
	{
		// �v���X�G���^�[����
		m_pTitlelogo = CTitlelogo::Create(D3DXVECTOR3(TITLE_PLESS_POS_X, TITLE_PLESS_POS_Y, 0.0f),
			D3DXVECTOR3(TITLE_PLESS_SIZE_X, TITLE_PLESS_SIZE_Y, 0.0f),
			CTitlelogo::LOGOTIPE_PRESS);
	}

}
