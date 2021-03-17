//=============================================================================
//
// �v���C���[���� [player.h]
// Author : ��{ ��
//
//=============================================================================

// 2�d�C���N���[�h�h�~�p
#ifndef _PLAYER_H_
#define _PLAYER_H_
//*****************************************************************************
// �C���N���[�h�t�@�C��
//*****************************************************************************
#include "main.h"
#include "character.h"

//*****************************************************************************
// �}�N����`
//*****************************************************************************
#define FRICTION 0.2f		 // ����
#define PLAYER_SEG_X 1.0f	 // �v���C���[�e�N�X�`���̉�������
#define PLAYER_SEG_Y 1.0f	 // �v���C���[�e�N�X�`���̏c������
#define PLAYER_SPEED 10.0f	 // �v���C���[�̈ړ����x
#define PLAYER_GRAVITY -5.0f  // �d�͂̋���
#define FIRE_RATE 10
#define COLLLISION_SIZE D3DXVECTOR3(200.0f, 400.0f, 200.0f)

//*****************************************************************************
// �v���C���[�N���X��`
//*****************************************************************************
class CPlayer :public CCharacter
{
public:
	CPlayer();
	~CPlayer();

	// ���f���̊e�p�[�c
	typedef enum
	{
		PARTS_BODY = 0,
		PARTS_HEAD,
		PARTS_RARM,
		PARTS_RHAND,
		PARTS_LARM,
		PARTS_LHAND,
		PARTS_RLEG,
		PARTS_RFOOT,
		PARTS_LLEG,
		PARTS_LSHOE,
		PARTS_MAX,
	}PARTS;

	HRESULT Init(void);
	void Update(void);
	void Move(void);
	void Draw(void);
	void Uninit(void);
	static HRESULT Load(void);
	static void Unload(void);
	static CPlayer * Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot);
	D3DXVECTOR3 GetMove(void) { return m_move; }
private:
	// �ÓI�����o�ϐ�
	static LPDIRECT3DTEXTURE9		m_pTexture;			// �e�N�X�`���ւ̃|�C���^
	static LPD3DXMESH		m_pMesh[PARTS_MAX];
	static LPD3DXBUFFER		m_pBuffMat[PARTS_MAX];
	static DWORD			m_nNumMat[PARTS_MAX];

	// �����o�ϐ�
	D3DXVECTOR3						m_move;				// �|���S���̈ړ���

};
#endif