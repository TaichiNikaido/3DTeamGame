//=============================================================================
//
// ���U���g���[�h [mode_result.cpp]
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
#include "mode_result.h"

//*****************************************************************************
// �}�N����`
//*****************************************************************************

//*****************************************************************************
// �ÓI�����o�ϐ��̏�����
//*****************************************************************************

//=============================================================================
// �R���X�g���N�^
//=============================================================================
CResultMode::CResultMode()
{
}

//=============================================================================
// �f�X�g���N�^
//=============================================================================
CResultMode::~CResultMode()
{
}

//=============================================================================
// ���������֐�
//=============================================================================
CResultMode * CResultMode::Create()
{
	//���U���g���[�h�̃|�C���^
	CResultMode * pResultMode = NULL;
	//�������U���g���[�h��NULL�̏ꍇ
	if (pResultMode == NULL)
	{
		//���U���g���[�h�̃������m��
		pResultMode = new CResultMode;
		//�������U���g���[�h��NULL����Ȃ��ꍇ
		if (pResultMode != NULL)
		{
			//�����������֐��Ăяo��
			pResultMode->Init();
		}
	}
	//���U���g���[�h�̃|�C���^
	return pResultMode;
}

//=============================================================================
// �����������֐�
//=============================================================================
HRESULT CResultMode::Init(void)
{
	//�S���������֐��Ăяo��
	CreateAll();
	return S_OK;
}

//=============================================================================
// �I�������֐�
//=============================================================================
void CResultMode::Uninit(void)
{
}

//=============================================================================
// �X�V�����֐�
//=============================================================================
void CResultMode::Update(void)
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
		CManager::StartFade(CManager::MODE_TITLE);
	}
}

//=============================================================================
// �`�揈���֐�
//=============================================================================
void CResultMode::Draw(void)
{
}

//=============================================================================
// �S���������֐�
//=============================================================================
void CResultMode::CreateAll(void)
{
}