//=============================================================================
//
// �v���C���[���� [player.cpp]
// Author : ��K������
//
//=============================================================================

//*****************************************************************************
// �C���N���[�h�t�@�C��
//*****************************************************************************
#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include "manager.h"
#include "mode_game.h"
#include "renderer.h"
#include "sound.h"
#include "keyboard.h"
#include "joystick.h"
#include "player.h"
#include "camera.h"
#include "item_meat.h"

//*****************************************************************************
// �}�N����`
//*****************************************************************************
#define SCRIPT_PASS ("Data")
#define INITIAL_POSITION (D3DXVECTOR3(0.0f,0.0f,0.0f))			//�ʒu�̏����l
#define INITIAL_SIZE (D3DXVECTOR3(0.0f,0.0f,0.0f))				//�T�C�Y�̏����l
#define INITIAL_COLLISIION_SIZE (D3DXVECTOR3(0.0f,0.0f,0.0f))	//�Փ˔���p�T�C�Y�̏����l
#define INITIAL_ROTATION (D3DXVECTOR3(0.0f,0.0f,0.0f))			//��]�̏����l
#define INITIAL_MOVE (D3DXVECTOR3(0.0f,0.0f,0.0f))				//�ړ��ʂ̏����l
#define MINIMUM_MEAT (0)										//���̍ŏ���
#define MINIMUM_DIAMOND (0)										//�_�C�A�����h�̍ŏ���
#define MINIMUM_STAN_TIME (0)									//�X�^�����Ԃ̍ŏ��l
#define INITIAL_MOVE_SPEED (0.0f)								//�ړ����x�̏����l							
#define INITIAL_JUMP_POWER (0.0f)								//�W�����v�͂̏����l

//*****************************************************************************
// �ÓI�����o�ϐ��錾
//*****************************************************************************
LPDIRECT3DTEXTURE9 CPlayer::m_pTexture = NULL;
LPD3DXMESH CPlayer::m_pMesh[PARTS_MAX] = {};
LPD3DXBUFFER CPlayer::m_pBuffMat[PARTS_MAX] = {};
DWORD CPlayer::m_nNumMat[PARTS_MAX] = {};

//=============================================================================
// �R���X�g���N�^
//=============================================================================
CPlayer::CPlayer()
{
	m_Size = INITIAL_SIZE;											//�T�C�Y
	m_Move = INITIAL_MOVE;											//�ړ���
	m_nMeat = MINIMUM_MEAT;											//���̏�����
	m_nMaxMeat = MINIMUM_MEAT;										//���̍ő吔
	m_nDiamond = MINIMUM_DIAMOND;									//�_�C�A�����h�̏�����
	m_nStunTime = MINIMUM_STAN_TIME;								//�X�^������
	m_nStunTimeCount = MINIMUM_STAN_TIME;							//�X�^�����Ԃ̃J�E���g
	m_fAutoRunSpeed = INITIAL_MOVE_SPEED;							//�ړ����x
	m_fLeftRightSpeed = INITIAL_MOVE_SPEED;							//���E�ړ����x
	m_fJumpPower = INITIAL_JUMP_POWER;								//�W�����v��
	m_bHit = false;													//�q�b�g������
	m_State = STATE_NONE;											//���
	m_Input = INPUT_NONE;											//���͏��
}

//=============================================================================
// �f�X�g���N�^
//=============================================================================
CPlayer::~CPlayer()
{
}

//=============================================================================
// ���f���ǂݍ��݊֐�
//=============================================================================
HRESULT CPlayer::Load(void)
{
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

	// �v���C���[1
	D3DXLoadMeshFromX(LPCSTR("./data/model/LBX/00_waist.x"), D3DXMESH_SYSTEMMEM, pDevice, NULL, &m_pBuffMat[PARTS_HIP], NULL, &m_nNumMat[PARTS_HIP], &m_pMesh[PARTS_HIP]);
	D3DXLoadMeshFromX(LPCSTR("./data/model/LBX/01_body.x"), D3DXMESH_SYSTEMMEM, pDevice, NULL, &m_pBuffMat[PARTS_BODY], NULL, &m_nNumMat[PARTS_BODY], &m_pMesh[PARTS_BODY]);
	D3DXLoadMeshFromX(LPCSTR("./data/model/LBX/02_head.x"), D3DXMESH_SYSTEMMEM, pDevice, NULL, &m_pBuffMat[PARTS_HEAD], NULL, &m_nNumMat[PARTS_HEAD], &m_pMesh[PARTS_HEAD]);
	D3DXLoadMeshFromX(LPCSTR("./data/model/LBX/03_rightshoulder.x"), D3DXMESH_SYSTEMMEM, pDevice, NULL, &m_pBuffMat[PARTS_RSHOULDER], NULL, &m_nNumMat[PARTS_RSHOULDER], &m_pMesh[PARTS_RSHOULDER]);
	D3DXLoadMeshFromX(LPCSTR("./data/model/LBX/04_rightUpperArm.x"), D3DXMESH_SYSTEMMEM, pDevice, NULL, &m_pBuffMat[PARTS_RARM], NULL, &m_nNumMat[PARTS_RARM], &m_pMesh[PARTS_RARM]);
	D3DXLoadMeshFromX(LPCSTR("./data/model/LBX/05_rightarm.x"), D3DXMESH_SYSTEMMEM, pDevice, NULL, &m_pBuffMat[PARTS_RHAND], NULL, &m_nNumMat[PARTS_RHAND], &m_pMesh[PARTS_RHAND]);
	D3DXLoadMeshFromX(LPCSTR("./data/model/LBX/06_rightHand.x"), D3DXMESH_SYSTEMMEM, pDevice, NULL, &m_pBuffMat[PARTS_LSHOULDER], NULL, &m_nNumMat[PARTS_LSHOULDER], &m_pMesh[PARTS_LSHOULDER]);
	D3DXLoadMeshFromX(LPCSTR("./data/model/LBX/07_leftshoulder.x"), D3DXMESH_SYSTEMMEM, pDevice, NULL, &m_pBuffMat[PARTS_LARM], NULL, &m_nNumMat[PARTS_LARM], &m_pMesh[PARTS_LARM]);
	D3DXLoadMeshFromX(LPCSTR("./data/model/LBX/08_leftUpperArm.x"), D3DXMESH_SYSTEMMEM, pDevice, NULL, &m_pBuffMat[PARTS_LHAND], NULL, &m_nNumMat[PARTS_LHAND], &m_pMesh[PARTS_LHAND]);
	D3DXLoadMeshFromX(LPCSTR("./data/model/LBX/09_leftarm.x"), D3DXMESH_SYSTEMMEM, pDevice, NULL, &m_pBuffMat[PARTS_RTHIGH], NULL, &m_nNumMat[PARTS_RTHIGH], &m_pMesh[PARTS_RTHIGH]);
	D3DXLoadMeshFromX(LPCSTR("./data/model/LBX/10_rightThighs.x"), D3DXMESH_SYSTEMMEM, pDevice, NULL, &m_pBuffMat[PARTS_RLEG], NULL, &m_nNumMat[PARTS_RLEG], &m_pMesh[PARTS_RLEG]);
	D3DXLoadMeshFromX(LPCSTR("./data/model/LBX/11_rightshin.x"), D3DXMESH_SYSTEMMEM, pDevice, NULL, &m_pBuffMat[PARTS_RFOOT], NULL, &m_nNumMat[PARTS_RFOOT], &m_pMesh[PARTS_RFOOT]);
	D3DXLoadMeshFromX(LPCSTR("./data/model/LBX/12_rightshoe.x"), D3DXMESH_SYSTEMMEM, pDevice, NULL, &m_pBuffMat[PARTS_LTHIGH], NULL, &m_nNumMat[PARTS_LTHIGH], &m_pMesh[PARTS_LTHIGH]);
	D3DXLoadMeshFromX(LPCSTR("./data/model/LBX/13_leftThighs.x"), D3DXMESH_SYSTEMMEM, pDevice, NULL, &m_pBuffMat[PARTS_LLEG], NULL, &m_nNumMat[PARTS_LLEG], &m_pMesh[PARTS_LLEG]);
	D3DXLoadMeshFromX(LPCSTR("./data/model/LBX/14_leftshin.x"), D3DXMESH_SYSTEMMEM, pDevice, NULL, &m_pBuffMat[PARTS_LFOOT], NULL, &m_nNumMat[PARTS_LFOOT], &m_pMesh[PARTS_LFOOT]);
	D3DXLoadMeshFromX(LPCSTR("./data/model/LBX/15_leftshoe.x"), D3DXMESH_SYSTEMMEM, pDevice, NULL, &m_pBuffMat[PARTS_LSHOE], NULL, &m_nNumMat[PARTS_LSHOE], &m_pMesh[PARTS_LSHOE]);

	return S_OK;
}

//=============================================================================
// �e�N�X�`���j���֐�
//=============================================================================
void CPlayer::Unload(void)
{
	if (m_pTexture != NULL)
	{
		m_pTexture->Release();
		m_pTexture = NULL;
	}
}
//=============================================================================
// ���������֐�
//=============================================================================
CPlayer * CPlayer::Create(void)
{
	//�v���C���[�̃|�C���^
	CPlayer * pPlayer = NULL;
	//�v���C���[�̃|�C���^��NULL�̏ꍇ
	if (pPlayer == NULL)
	{
		//�v���C���[�̃������m��
		pPlayer = new CPlayer;
		//�v���C���[�̃|�C���^��NULL�ł͂Ȃ��ꍇ
		if (pPlayer != NULL)
		{
			//�v���C���[�̏����������֐��Ăяo��
			pPlayer->Init();
		}
	}
	//�v���C���[�̃|�C���^��Ԃ�
	return pPlayer;
}

//=============================================================================
// ����������
//=============================================================================
HRESULT CPlayer::Init(void)
{
	// �p�[�c����ݒ�
	SetPartNum(PARTS_MAX);

	for (int nCount = 0; nCount < PARTS_MAX; nCount++)
	{
		BindMesh(CAnimation::TYPE_HUMAN, nCount, m_pMesh[nCount], m_pBuffMat[nCount], m_nNumMat[nCount]);
	}

	// ���W�E�e�q�֌W�̓ǂݍ���
	LoadModelData("./data/text/motion_LBX.txt");
	//�f�[�^�ǂݍ��݊֐��Ăяo��
	DataLoad();
	//�L�����N�^�[�̏����������֐��Ăяo��
	CCharacter::Init();
	return S_OK;
}

//=============================================================================
// �I������
//=============================================================================
void CPlayer::Uninit()
{
	CCharacter::Uninit();
}

//=============================================================================
// �X�V����
//=============================================================================
void CPlayer::Update()
{
	CCharacter::Update();
}

//=============================================================================
// �`�揈��
//=============================================================================
void CPlayer::Draw()
{
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

	CCharacter::Draw();
}

//=============================================================================
// ���͏����֐�
//=============================================================================
void CPlayer::Input(void)
{
	//�L�[�{�[�h�̎擾
	CKeyboard * pKeyboard = CManager::GetKeyboard();
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
	//�Q�[�����[�h�̎擾
	CGameMode * pGameMode = CManager::GetGameMode();
	//�v���C���[���ړ����Ă��Ȃ��Ƃ�
	m_Move = INITIAL_MOVE;
	//���ړ�����
	if (pKeyboard->GetKeyboardPress(DIK_A) || lpDIDevice != NULL &&js.lX == -1000)
	{
		//���̓L�[�������ɂ���
		m_Input = INPUT_LEFT;
		//�ړ������֐��Ăяo��
		Move();
	}
	//�E�ړ�����
	if (pKeyboard->GetKeyboardPress(DIK_D) || lpDIDevice != NULL &&js.lX == 1000)
	{
		//���̓L�[�����E�ɂ���
		m_Input = INPUT_RIGHT;
		//�ړ������֐��Ăяo��
		Move();
	}
	//�W�����v�����֐�
	if (pKeyboard->GetKeyboardTrigger(DIK_SPACE) || pJoystick->GetJoystickTrigger(JS_X))
	{
		//���̓L�[�����X�y�[�X�ɂ���
		m_Input = INPUT_SPACE;
		//�ړ������֐��Ăяo��
		Move();
	}
}

//=============================================================================
// �ړ������֐�
//=============================================================================
void CPlayer::Move(void)
{
	//�ʒu���擾����
	D3DXVECTOR3 Position = GetPos();
	//�������S��Ԃ���Ȃ��Ƃ�
	if (m_State != STATE_DEATH)
	{
		switch (m_Input)
		{
			//�������͏�񂪍��̏ꍇ
		case INPUT_LEFT:
			m_Move.x = -m_fLeftRightSpeed;
			break;
			//�������͏�񂪉E�̏ꍇ
		case INPUT_RIGHT:
			m_Move.x = m_fLeftRightSpeed;
			break;
			//�������͏�񂪃X�y�[�X�̏ꍇ
		case INPUT_SPACE:
			break;
		default:
			break;
		}
	}
	//�ʒu�X�V
	Position += m_Move;
	//�ʒu��ݒ肷��
	SetPos(Position);
}

//=============================================================================
// �q�b�g�����֐�
//=============================================================================
void CPlayer::Hit(void)
{
	//�ʒu���擾����
	D3DXVECTOR3 Position = GetPos();
	//���̏����������Z����
	m_nMeat--;
	//���𐶐�����
	CMeat::Create(Position);
	//�q�b�g������
	m_bHit = true;
}

//=============================================================================
// ���S�����֐�
//=============================================================================
void CPlayer::Death(void)
{
	//�_�C�A�����h�̏�������0�ɂ���
	m_nDiamond = MINIMUM_DIAMOND;
	//���̏��������}�b�N�X�ɂ���
	m_nMeat = m_nMaxMeat;
}

//=============================================================================
// �f�[�^�ǂݍ��݊֐�
//=============================================================================
void CPlayer::DataLoad(void)
{
	D3DXVECTOR3 Position = INITIAL_POSITION;	//�ʒu
	D3DXVECTOR3 CollisionSize = INITIAL_SIZE;	//�Փ˔���p�T�C�Y
	D3DXVECTOR3 Rotation = INITIAL_ROTATION;	//��]
	char aReadText[MAX_TEXT];					//�ǂݍ��񂾃e�L�X�g
	char aCurrentText[MAX_TEXT];				//���݂̃e�L�X�g
	char aUnnecessaryText[MAX_TEXT];			//�s�K�v�ȃe�L�X�g
	memset(aReadText, NULL, sizeof(aReadText));
	memset(aCurrentText, NULL, sizeof(aCurrentText));
	memset(aUnnecessaryText, NULL, sizeof(aUnnecessaryText));
	//�t�@�C���̃|�C���^
	FILE *pFile = NULL;
	//�����t�@�C���̃|�C���^��NULL�̏ꍇ
	if (pFile == NULL)
	{
		//�t�@�C���̓ǂݍ���
		pFile = fopen(SCRIPT_PASS, "r");
		//�t�@�C�����J�����Ƃ��ł�����
		if (pFile != NULL)
		{
			//SCRIPT�̕�����������
			while (strcmp(aCurrentText, "SCRIPT") != 0)
			{
				//�ǂݍ��񂾃e�L�X�g���i�[����
				fgets(aReadText, sizeof(aReadText), pFile);
				//�ǂݍ��񂾃e�L�X�g�����݂̃e�L�X�g�Ɋi�[
				sscanf(aReadText, "%s", &aCurrentText);
			}
			//���݂̃e�L�X�g��SCRIPT��������
			if (strcmp(aCurrentText, "SCRIPT") == 0)
			{
				//END_SCRIPT�̕�����������܂œǂ�
				while (strcmp(aCurrentText, "END_SCRIPT") != 0)
				{
					//�ǂݍ��񂾃e�L�X�g���i�[����
					fgets(aReadText, sizeof(aReadText), pFile);
					//�ǂݍ��񂾃e�L�X�g�����݂̃e�L�X�g�Ɋi�[
					sscanf(aReadText, "%s", &aCurrentText);
					//���݂̃e�L�X�g��PARAMETER_SET��������
					if (strcmp(aCurrentText, "PARAMETER_SET") == 0)
					{
						//END_PARAMETER_SET�̕�����������܂œǂ�
						while (strcmp(aCurrentText, "END_PARAMETER_SET") != 0)
						{
							//�ǂݍ��񂾃e�L�X�g���i�[����
							fgets(aReadText, sizeof(aReadText), pFile);
							//�ǂݍ��񂾃e�L�X�g�����݂̃e�L�X�g�Ɋi�[
							sscanf(aReadText, "%s", &aCurrentText);
							//���݂̃e�L�X�g��POS��������
							if (strcmp(aCurrentText, "POS") == 0)
							{
								//�ʒu���̓ǂݍ���
								sscanf(aReadText, "%s %s %f %f %f", &aUnnecessaryText, &aUnnecessaryText, &Position.x, &Position.y, &Position.z);
								//�ʒu��ݒ肷��
								SetPos(Position);
							}
							//���݂̃e�L�X�g��SIZE��������
							if (strcmp(aCurrentText, "SIZE") == 0)
							{
								//�T�C�Y���̓ǂݍ���
								sscanf(aReadText, "%s %s %f %f %f", &aUnnecessaryText, &aUnnecessaryText, &m_Size.x, &m_Size.y, &m_Size.z);
							}
							//���݂̃e�L�X�g��COLLISION_SIZE��������
							if (strcmp(aCurrentText, "COLLISION_SIZE") == 0)
							{
								//�Փ˔���p�̃T�C�Y�̎擾
								sscanf(aReadText, "%s %s %f %f %f", &aUnnecessaryText, &aUnnecessaryText, &CollisionSize.x, &CollisionSize.y, &CollisionSize.z);
							}
							//���݂̃e�L�X�g��ROT��������
							if (strcmp(aCurrentText, "ROT") == 0)
							{
								//��]���̓ǂݍ���
								sscanf(aReadText, "%s %s %f %f %f", &aUnnecessaryText, &aUnnecessaryText, &Rotation.x, &Rotation.y, &Rotation.z);
								//��]��ݒ肷��
								SetRot(Rotation);
							}
							//���݂̃e�L�X�g��Meat��������
							if (strcmp(aCurrentText, "Meat") == 0)
							{
								//�T�C�Y�̐ݒ�
								sscanf(aReadText, "%s %s %d", &aUnnecessaryText, &aUnnecessaryText, &m_nMaxMeat);
								//���̏�������ݒ肷��
								m_nMeat = m_nMaxMeat;
							}
							//���݂̃e�L�X�g��StunTime��������
							if (strcmp(aCurrentText, "StunTime") == 0)
							{
								//�T�C�Y�̐ݒ�
								sscanf(aReadText, "%s %s %d", &aUnnecessaryText, &aUnnecessaryText, &m_nStunTime);
							}
							//���݂̃e�L�X�g��AutoRunSpeed��������
							if (strcmp(aCurrentText, "AutoRunSpeed") == 0)
							{
								//�T�C�Y�̐ݒ�
								sscanf(aReadText, "%s %s %f", &aUnnecessaryText, &aUnnecessaryText, &m_fAutoRunSpeed);
								//�ړ��ʂ̐ݒ�
								m_Move.z = m_fAutoRunSpeed;
							}
							//���݂̃e�L�X�g��LeftRightSpeed��������
							if (strcmp(aCurrentText, "LeftRightSpeed") == 0)
							{
								//�T�C�Y�̐ݒ�
								sscanf(aReadText, "%s %s %f", &aUnnecessaryText, &aUnnecessaryText, &m_fLeftRightSpeed);
							}
							//���݂̃e�L�X�g��JumpPower��������
							if (strcmp(aCurrentText, "JumpPower") == 0)
							{
								//�T�C�Y�̐ݒ�
								sscanf(aReadText, "%s %s %f", &aUnnecessaryText, &aUnnecessaryText, &m_fJumpPower);
							}
						}
					}
				}
			}
			//�t�@�C�������
			fclose(pFile);
		}
	}
}//=============================================================================
// ���͏����֐�
//=============================================================================
void CPlayer::Input(void)
{
	//�L�[�{�[�h�̎擾
	CKeyboard * pKeyboard = CManager::GetKeyboard();
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
	//�Q�[�����[�h�̎擾
	CGameMode * pGameMode = CManager::GetGameMode();
	//�v���C���[���ړ����Ă��Ȃ��Ƃ�
	m_Move = INITIAL_MOVE;
	//���ړ�����
	if (pKeyboard->GetKeyboardPress(DIK_A) || lpDIDevice != NULL &&js.lX == -1000)
	{
		//���̓L�[�������ɂ���
		m_Input = INPUT_LEFT;
		//�ړ������֐��Ăяo��
		Move();
	}
	//�E�ړ�����
	if (pKeyboard->GetKeyboardPress(DIK_D) || lpDIDevice != NULL &&js.lX == 1000)
	{
		//���̓L�[�����E�ɂ���
		m_Input = INPUT_RIGHT;
		//�ړ������֐��Ăяo��
		Move();
	}
	//�W�����v�����֐�
	if (pKeyboard->GetKeyboardTrigger(DIK_SPACE) || pJoystick->GetJoystickTrigger(JS_X))
	{
		//���̓L�[�����X�y�[�X�ɂ���
		m_Input = INPUT_SPACE;
		//�ړ������֐��Ăяo��
		Move();
	}
}

//=============================================================================
// �ړ������֐�
//=============================================================================
void CPlayer::Move(void)
{
	//�ʒu���擾����
	D3DXVECTOR3 Position = GetPos();
	//�������S��Ԃ���Ȃ��Ƃ�
	if (m_State != STATE_DEATH)
	{
		switch (m_Input)
		{
			//�������͏�񂪍��̏ꍇ
		case INPUT_LEFT:
			m_Move.x = -m_fLeftRightSpeed;
			break;
			//�������͏�񂪉E�̏ꍇ
		case INPUT_RIGHT:
			m_Move.x = m_fLeftRightSpeed;
			break;
			//�������͏�񂪃X�y�[�X�̏ꍇ
		case INPUT_SPACE:
			break;
		default:
			break;
		}
	}
	//�ʒu�X�V
	Position += m_Move;
	//�ʒu��ݒ肷��
	SetPos(Position);
}

//=============================================================================
// �q�b�g�����֐�
//=============================================================================
void CPlayer::Hit(void)
{
	//�ʒu���擾����
	D3DXVECTOR3 Position = GetPos();
	//���̏����������Z����
	m_nMeat--;
	//���𐶐�����
	CMeat::Create(Position);
	//�q�b�g������
	m_bHit = true;
}

//=============================================================================
// ���S�����֐�
//=============================================================================
void CPlayer::Death(void)
{
	//�_�C�A�����h�̏�������0�ɂ���
	m_nDiamond = MINIMUM_DIAMOND;
	//���̏��������}�b�N�X�ɂ���
	m_nMeat = m_nMaxMeat;
}

//=============================================================================
// �f�[�^�ǂݍ��݊֐�
//=============================================================================
void CPlayer::DataLoad(void)
{
	D3DXVECTOR3 Position = INITIAL_POSITION;	//�ʒu
	D3DXVECTOR3 CollisionSize = INITIAL_SIZE;	//�Փ˔���p�T�C�Y
	D3DXVECTOR3 Rotation = INITIAL_ROTATION;	//��]
	char aReadText[MAX_TEXT];					//�ǂݍ��񂾃e�L�X�g
	char aCurrentText[MAX_TEXT];				//���݂̃e�L�X�g
	char aUnnecessaryText[MAX_TEXT];			//�s�K�v�ȃe�L�X�g
	memset(aReadText, NULL, sizeof(aReadText));
	memset(aCurrentText, NULL, sizeof(aCurrentText));
	memset(aUnnecessaryText, NULL, sizeof(aUnnecessaryText));
	//�t�@�C���̃|�C���^
	FILE *pFile = NULL;
	//�����t�@�C���̃|�C���^��NULL�̏ꍇ
	if (pFile == NULL)
	{
		//�t�@�C���̓ǂݍ���
		pFile = fopen(SCRIPT_PASS, "r");
		//�t�@�C�����J�����Ƃ��ł�����
		if (pFile != NULL)
		{
			//SCRIPT�̕�����������
			while (strcmp(aCurrentText, "SCRIPT") != 0)
			{
				//�ǂݍ��񂾃e�L�X�g���i�[����
				fgets(aReadText, sizeof(aReadText), pFile);
				//�ǂݍ��񂾃e�L�X�g�����݂̃e�L�X�g�Ɋi�[
				sscanf(aReadText, "%s", &aCurrentText);
			}
			//���݂̃e�L�X�g��SCRIPT��������
			if (strcmp(aCurrentText, "SCRIPT") == 0)
			{
				//END_SCRIPT�̕�����������܂œǂ�
				while (strcmp(aCurrentText, "END_SCRIPT") != 0)
				{
					//�ǂݍ��񂾃e�L�X�g���i�[����
					fgets(aReadText, sizeof(aReadText), pFile);
					//�ǂݍ��񂾃e�L�X�g�����݂̃e�L�X�g�Ɋi�[
					sscanf(aReadText, "%s", &aCurrentText);
					//���݂̃e�L�X�g��PARAMETER_SET��������
					if (strcmp(aCurrentText, "PARAMETER_SET") == 0)
					{
						//END_PARAMETER_SET�̕�����������܂œǂ�
						while (strcmp(aCurrentText, "END_PARAMETER_SET") != 0)
						{
							//�ǂݍ��񂾃e�L�X�g���i�[����
							fgets(aReadText, sizeof(aReadText), pFile);
							//�ǂݍ��񂾃e�L�X�g�����݂̃e�L�X�g�Ɋi�[
							sscanf(aReadText, "%s", &aCurrentText);
							//���݂̃e�L�X�g��POS��������
							if (strcmp(aCurrentText, "POS") == 0)
							{
								//�ʒu���̓ǂݍ���
								sscanf(aReadText, "%s %s %f %f %f", &aUnnecessaryText, &aUnnecessaryText, &Position.x, &Position.y, &Position.z);
								//�ʒu��ݒ肷��
								SetPos(Position);
							}
							//���݂̃e�L�X�g��SIZE��������
							if (strcmp(aCurrentText, "SIZE") == 0)
							{
								//�T�C�Y���̓ǂݍ���
								sscanf(aReadText, "%s %s %f %f %f", &aUnnecessaryText, &aUnnecessaryText, &m_Size.x, &m_Size.y, &m_Size.z);
							}
							//���݂̃e�L�X�g��COLLISION_SIZE��������
							if (strcmp(aCurrentText, "COLLISION_SIZE") == 0)
							{
								//�Փ˔���p�̃T�C�Y�̎擾
								sscanf(aReadText, "%s %s %f %f %f", &aUnnecessaryText, &aUnnecessaryText, &CollisionSize.x, &CollisionSize.y, &CollisionSize.z);
							}
							//���݂̃e�L�X�g��ROT��������
							if (strcmp(aCurrentText, "ROT") == 0)
							{
								//��]���̓ǂݍ���
								sscanf(aReadText, "%s %s %f %f %f", &aUnnecessaryText, &aUnnecessaryText, &Rotation.x, &Rotation.y, &Rotation.z);
								//��]��ݒ肷��
								SetRot(Rotation);
							}
							//���݂̃e�L�X�g��Meat��������
							if (strcmp(aCurrentText, "Meat") == 0)
							{
								//�T�C�Y�̐ݒ�
								sscanf(aReadText, "%s %s %d", &aUnnecessaryText, &aUnnecessaryText, &m_nMaxMeat);
								//���̏�������ݒ肷��
								m_nMeat = m_nMaxMeat;
							}
							//���݂̃e�L�X�g��StunTime��������
							if (strcmp(aCurrentText, "StunTime") == 0)
							{
								//�T�C�Y�̐ݒ�
								sscanf(aReadText, "%s %s %d", &aUnnecessaryText, &aUnnecessaryText, &m_nStunTime);
							}
							//���݂̃e�L�X�g��AutoRunSpeed��������
							if (strcmp(aCurrentText, "AutoRunSpeed") == 0)
							{
								//�T�C�Y�̐ݒ�
								sscanf(aReadText, "%s %s %f", &aUnnecessaryText, &aUnnecessaryText, &m_fAutoRunSpeed);
								//�ړ��ʂ̐ݒ�
								m_Move.z = m_fAutoRunSpeed;
							}
							//���݂̃e�L�X�g��LeftRightSpeed��������
							if (strcmp(aCurrentText, "LeftRightSpeed") == 0)
							{
								//�T�C�Y�̐ݒ�
								sscanf(aReadText, "%s %s %f", &aUnnecessaryText, &aUnnecessaryText, &m_fLeftRightSpeed);
							}
							//���݂̃e�L�X�g��JumpPower��������
							if (strcmp(aCurrentText, "JumpPower") == 0)
							{
								//�T�C�Y�̐ݒ�
								sscanf(aReadText, "%s %s %f", &aUnnecessaryText, &aUnnecessaryText, &m_fJumpPower);
							}
						}
					}
				}
			}
			//�t�@�C�������
			fclose(pFile);
		}
	}
}