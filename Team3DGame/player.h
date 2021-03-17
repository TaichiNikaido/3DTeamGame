//=============================================================================
//
// �v���C���[ [player.h]
// Author : ��K������
//
//=============================================================================

#ifndef _PLAYER_H_
#define _PLAYER_H_

//*****************************************************************************
// �w�b�_�t�@�C���̃C���N���[�h
//*****************************************************************************
#include "main.h"
#include "character.h"

//*****************************************************************************
// �}�N����`
//*****************************************************************************

//*****************************************************************************
// �O���錾
//*****************************************************************************

//*****************************************************************************
// �v���C���[�N���X��`
//*****************************************************************************
class CPlayer :public CCharacter
{
public:
	// ���f���̊e�p�[�c
	typedef enum
	{
		PARTS_HIP = 0,
		PARTS_BODY,
		PARTS_HEAD,
		PARTS_RSHOULDER,
		PARTS_RARM,
		PARTS_RHAND,
		PARTS_LSHOULDER,
		PARTS_LARM,
		PARTS_LHAND,
		PARTS_RTHIGH,
		PARTS_RLEG,
		PARTS_RFOOT,
		PARTS_LTHIGH,
		PARTS_LLEG,
		PARTS_LFOOT,
		PARTS_LSHOE,
		PARTS_MAX,
	}PARTS;
	typedef enum
	{
		STATE_NONE = -1,
		STATE_LIVE,
		STATE_DEATH,
		STATE_MAX
	}STATE;
	typedef enum
	{
		INPUT_NONE = -1,
		INPUT_LEFT,
		INPUT_RIGHT,
		INPUT_SPACE,
		INPUT_MAX
	}INPUT;
	CPlayer();
	~CPlayer();
	static HRESULT Load(void);
	static void Unload(void);
	static CPlayer * Create(void);
	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);
	void Hit(void);
	void AddDiamond(int nValue) { m_nDiamond += nValue; }
	int GetMeat(void) { return m_nMeat; }
	int GetDiamond(void) { return m_nDiamond; }
	STATE GetState(void) { return m_State; }
private:
	void Input(void);
	void Move(void);
	void Death(void);
	void DataLoad(void);
	static LPDIRECT3DTEXTURE9 m_pTexture;
	static LPD3DXMESH m_pMesh[PARTS_MAX];
	static LPD3DXBUFFER	m_pBuffMat[PARTS_MAX];
	static DWORD m_nNumMat[PARTS_MAX];
	D3DXVECTOR3 m_Size;										//�T�C�Y
	D3DXVECTOR3 m_Move;										//�ړ���
	int m_nMeat;											//���̏�����
	int m_nMaxMeat;											//���̍ő吔
	int m_nDiamond;											//�_�C�������h�̏�����
	int m_nStunTime;										//�X�^������
	int m_nStunTimeCount;									//�X�^�����Ԃ̃J�E���g
	float m_fAutoRunSpeed;									//�I�[�g�����̑��x
	float m_fLeftRightSpeed;								//���E�ړ����x
	float m_fJumpPower;										//�W�����v��
	bool m_bHit;											//�q�b�g������
	STATE m_State;											//���
	INPUT m_Input;											//����
};
#endif