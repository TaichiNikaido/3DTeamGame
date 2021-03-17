//=============================================================================
//
// �v���C���[���� [enemy.cpp]
// Author : 
//
//=============================================================================

//*****************************************************************************
// �C���N���[�h�t�@�C��
//*****************************************************************************
#include "enemy.h"
#include "manager.h"
#include "renderer.h"
#include "scene3d.h"

//*****************************************************************************
// �}�N����`
//*****************************************************************************
#define INITIAL_POSITION (D3DXVECTOR3(0.0f,0.0f,0.0f))

//*****************************************************************************
// �ÓI�����o�ϐ��錾
//*****************************************************************************
LPDIRECT3DTEXTURE9 CEnemy::m_pTexture = NULL;
LPD3DXMESH CEnemy::m_pMesh[PARTS_MAX] = {};
LPD3DXBUFFER CEnemy::m_pBuffMat[PARTS_MAX] = {};
DWORD CEnemy::m_nNumMat[PARTS_MAX] = {};

//=============================================================================
// �R���X�g���N�^
//=============================================================================
CEnemy::CEnemy()
{
	// �����o�ϐ�
	m_move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);		// �v���C���[�̈ړ���
	m_fGravDest = ENEMY_GRAVITY;
	m_bHit = false;
}

//=============================================================================
// �f�X�g���N�^
//=============================================================================
CEnemy::~CEnemy()
{
}

//=============================================================================
// ����������
//=============================================================================
HRESULT CEnemy::Init(void)
{
	// �p�[�c����ݒ�
	SetPartNum(PARTS_MAX);

	for (int nCount = 0; nCount < PARTS_MAX; nCount++)
	{
		BindMesh(CAnimation::TYPE_ENEMY, nCount, m_pMesh[nCount], m_pBuffMat[nCount], m_nNumMat[nCount]);
	}

	// ���W�E�e�q�֌W�̓ǂݍ���
	LoadModelData("./data/text/motion_enemy.txt");

	CCharacter::Init();

	SetPos(INITIAL_POSITION);


	return S_OK;
}

//=============================================================================
// �X�V����
//=============================================================================
void CEnemy::Update()
{
	// ���쏈��
	Move();

	CCharacter::Update();
}

//=============================================================================
// �v���C���[���쏈��
//=============================================================================
void CEnemy::Move(void)
{
	// �v���C���[�����擾
	D3DXVECTOR3 pos, rot;

	pos = GetPos();
	rot = GetRot();

	// 1F�O�̈ʒu���L��
	SetPosOld(pos);


	// �����̌v�Z
	m_move.x += (0.0f - m_move.x) * FRICTION;
	m_move.y += (0.0f - m_move.y) * FRICTION;
	m_move.z += (0.0f - m_move.z) * FRICTION;

	// �ʒu�̈ړ�
	pos += m_move;

	SetPos(pos);
	SetRot(rot);
}

//=============================================================================
// �`�揈��
//=============================================================================
void CEnemy::Draw()
{
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

	CCharacter::Draw();
}

//=============================================================================
// �I������
//=============================================================================
void CEnemy::Uninit()
{
	CCharacter::Uninit();
}

//=============================================================================
// �e�N�X�`���ǂݍ��ݏ���
//=============================================================================
HRESULT CEnemy::Load(void)
{
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

	// �v���C���[1
	D3DXLoadMeshFromX(LPCSTR("./data/enemy/00_Waist.x"), D3DXMESH_SYSTEMMEM, pDevice, NULL, &m_pBuffMat[PARTS_WAIST], NULL, &m_nNumMat[PARTS_WAIST], &m_pMesh[PARTS_WAIST]);
	D3DXLoadMeshFromX(LPCSTR("./data/enemy/01_Body.x"), D3DXMESH_SYSTEMMEM, pDevice, NULL, &m_pBuffMat[PARTS_BODY], NULL, &m_nNumMat[PARTS_BODY], &m_pMesh[PARTS_BODY]);
	D3DXLoadMeshFromX(LPCSTR("./data/enemy/02_Head.x"), D3DXMESH_SYSTEMMEM, pDevice, NULL, &m_pBuffMat[PARTS_HEAD], NULL, &m_nNumMat[PARTS_HEAD], &m_pMesh[PARTS_HEAD]);
	D3DXLoadMeshFromX(LPCSTR("./data/enemy/03_RightArm.x"), D3DXMESH_SYSTEMMEM, pDevice, NULL, &m_pBuffMat[PARTS_RARM], NULL, &m_nNumMat[PARTS_RARM], &m_pMesh[PARTS_RARM]);
	D3DXLoadMeshFromX(LPCSTR("./data/enemy/04_LeftArm.x"), D3DXMESH_SYSTEMMEM, pDevice, NULL, &m_pBuffMat[PARTS_LARM], NULL, &m_nNumMat[PARTS_LARM], &m_pMesh[PARTS_LARM]);
	D3DXLoadMeshFromX(LPCSTR("./data/enemy/05_RightLeg.x"), D3DXMESH_SYSTEMMEM, pDevice, NULL, &m_pBuffMat[PARTS_RLEG], NULL, &m_nNumMat[PARTS_RLEG], &m_pMesh[PARTS_RLEG]);
	D3DXLoadMeshFromX(LPCSTR("./data/enemy/06_RightShoe.x"), D3DXMESH_SYSTEMMEM, pDevice, NULL, &m_pBuffMat[PARTS_RSHOE], NULL, &m_nNumMat[PARTS_RSHOE], &m_pMesh[PARTS_RSHOE]);
	D3DXLoadMeshFromX(LPCSTR("./data/enemy/07_LeftLeg.x"), D3DXMESH_SYSTEMMEM, pDevice, NULL, &m_pBuffMat[PARTS_LLEG], NULL, &m_nNumMat[PARTS_LLEG], &m_pMesh[PARTS_LLEG]);
	D3DXLoadMeshFromX(LPCSTR("./data/enemy/08_LeftShoe.x"), D3DXMESH_SYSTEMMEM, pDevice, NULL, &m_pBuffMat[PARTS_LSHOE], NULL, &m_nNumMat[PARTS_LSHOE], &m_pMesh[PARTS_LSHOE]);
	D3DXLoadMeshFromX(LPCSTR("./data/enemy/09_MainTail.x"), D3DXMESH_SYSTEMMEM, pDevice, NULL, &m_pBuffMat[PARTS_MAINTAIL], NULL, &m_nNumMat[PARTS_MAINTAIL], &m_pMesh[PARTS_MAINTAIL]);
	D3DXLoadMeshFromX(LPCSTR("./data/enemy/10_SubTail.x"), D3DXMESH_SYSTEMMEM, pDevice, NULL, &m_pBuffMat[PARTS_SUBTAIL], NULL, &m_nNumMat[PARTS_SUBTAIL], &m_pMesh[PARTS_SUBTAIL]);
	D3DXLoadMeshFromX(LPCSTR("./data/enemy/11_EndTail.x"), D3DXMESH_SYSTEMMEM, pDevice, NULL, &m_pBuffMat[PARTS_ENDTAIL], NULL, &m_nNumMat[PARTS_ENDTAIL], &m_pMesh[PARTS_ENDTAIL]);
	D3DXLoadMeshFromX(LPCSTR("./data/enemy/12_Chin.x"), D3DXMESH_SYSTEMMEM, pDevice, NULL, &m_pBuffMat[PARTS_CHIN], NULL, &m_nNumMat[PARTS_CHIN], &m_pMesh[PARTS_CHIN]);
	return S_OK;
}

//=============================================================================
// �e�N�X�`���j������
//=============================================================================
void CEnemy::Unload(void)
{
	if (m_pTexture != NULL)
	{
		m_pTexture->Release();
		m_pTexture = NULL;
	}
}

//=============================================================================
// �C���X�^���X��������
//=============================================================================
CEnemy * CEnemy::Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot)
{
	CEnemy *pEnemy;
	pEnemy = new CEnemy;
	pEnemy->SetObjType(OBJTYPE_ENEMY);
	pEnemy->Init();
	pEnemy->SetPos(pos);
	return pEnemy;
}