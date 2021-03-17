//=============================================================================
//
// �v���C���[���� [player.cpp]
// Author : ��{ ��
//
//=============================================================================

//*****************************************************************************
// �C���N���[�h�t�@�C��
//*****************************************************************************
#include "player.h"
#include "keyboard.h"
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
LPDIRECT3DTEXTURE9 CPlayer::m_pTexture = NULL;
LPD3DXMESH CPlayer::m_pMesh[PARTS_MAX] = {};
LPD3DXBUFFER CPlayer::m_pBuffMat[PARTS_MAX] = {};
DWORD CPlayer::m_nNumMat[PARTS_MAX] = {};

//=============================================================================
// �R���X�g���N�^
//=============================================================================
CPlayer::CPlayer()
{
	// �����o�ϐ�
	m_move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);		// �v���C���[�̈ړ���
	m_fGravDest = PLAYER_GRAVITY;
	m_bJump = false;
	m_bShot = false;
	m_bHit = false;
}

//=============================================================================
// �f�X�g���N�^
//=============================================================================
CPlayer::~CPlayer()
{
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

	CCharacter::Init();

	m_bJump = false;
	m_bShot = false;
	m_bHit = false;

	SetPos(INITIAL_POSITION);


	return S_OK;
}

//=============================================================================
// �X�V����
//=============================================================================
void CPlayer::Update()
{
	// ���쏈��
	Move();

	CCharacter::Update();
}

//=============================================================================
// �v���C���[���쏈��
//=============================================================================
void CPlayer::Move(void)
{
	// �v���C���[�����擾
	D3DXVECTOR3 pos, rot;

	pos = GetPos();
	rot = GetRot();

	// 1F�O�̈ʒu���L��
	SetPosOld(pos);

	CKeyboard * pKeyboard = CManager::GetKeyboard();

	// ���ֈړ�
	if (pKeyboard->GetKeyboardPress(DIK_LEFT))
	{
		m_move.x = sinf(rot.y - D3DXToRadian(90)) * PLAYER_SPEED;
		m_move.z = cosf(rot.y - D3DXToRadian(90)) * PLAYER_SPEED;
	}
	// �E�ֈړ�
	if (pKeyboard->GetKeyboardPress(DIK_RIGHT))
	{
		m_move.x = sinf(rot.y + D3DXToRadian(90)) * PLAYER_SPEED;
		m_move.z = cosf(rot.y + D3DXToRadian(90)) * PLAYER_SPEED;
	}
	// �O�ֈړ�
	if (pKeyboard->GetKeyboardPress(DIK_UP))
	{
		m_move.x = sinf(rot.y) * PLAYER_SPEED;
		m_move.z = cosf(rot.y) * PLAYER_SPEED;
	}
	// ���ֈړ�
	if (pKeyboard->GetKeyboardPress(DIK_DOWN))
	{
		m_move.x = sinf(rot.y) * -PLAYER_SPEED;
		m_move.z = cosf(rot.y) * -PLAYER_SPEED;
	}
	// �E�։�]
	if (pKeyboard->GetKeyboardPress(DIK_E))
	{
		rot.y += D3DXToRadian(2);
	}
	// �E�։�]
	if (pKeyboard->GetKeyboardPress(DIK_Q))
	{
		rot.y -= D3DXToRadian(2);
	}

	// �����̌v�Z
	m_move.x += (0.0f - m_move.x) * FRICTION;
	m_move.y += (0.0f - m_move.y) * FRICTION;
	m_move.z += (0.0f - m_move.z) * FRICTION;

	// �ʒu�̈ړ�
	pos += m_move;

	// �����蔻��
	//CScene3d *pScene3d = NULL;

	//for (int nCount = 0; nCount < MAX_POLYGON; nCount++)
	//{
	//	// �I�u�W�F�N�g�擾
	//	CScene *pScene = CScene::GetObj(nCount);

	//	if (pScene != NULL)
	//	{
	//		// �����蔻��p�̕ϐ�
	//		BLOCK_HIT_INFO blockHitInfo;
	//		blockHitInfo.hitSurface = HIT_SURFACE_NONE;
	//		blockHitInfo.pos = pos;

	//		if (pScene->GetObjType() == CScene::OBJ_TYPE_CUBE)
	//		{
	//			// character�ɃL���X�g
	//			pScene3d = (CScene3d*)pScene;
	//			// �����蔻��̌v�Z
	//	/*		blockHitInfo = BlockCollision3D(&pos, &GetPosOld(), &pScene3d->GetPos(),
	//				&COLLLISION_SIZE, &pScene3d->GetCollisionSize());*/
	//		}

	//		// �u���b�N�̓����蔻��Ōv�Z�����ʒu���A���т���
	//		pos = blockHitInfo.pos;

	//	}
	//}

	SetPos(pos);
	SetRot(rot);
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
// �I������
//=============================================================================
void CPlayer::Uninit()
{
	CCharacter::Uninit();
}

//=============================================================================
// �e�N�X�`���ǂݍ��ݏ���
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
// �e�N�X�`���j������
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
// �C���X�^���X��������
//=============================================================================
CPlayer * CPlayer::Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot)
{
	CPlayer *pPlayer;
	pPlayer = new CPlayer;
	pPlayer->SetObjType(OBJTYPE_PLAYER);
	pPlayer->Init();
	return pPlayer;
}