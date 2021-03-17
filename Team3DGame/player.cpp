//=============================================================================
//
// プレイヤー処理 [player.cpp]
// Author : 樋宮 匠
//
//=============================================================================

//*****************************************************************************
// インクルードファイル
//*****************************************************************************
#include "player.h"
#include "keyboard.h"
#include "manager.h"
#include "renderer.h"
#include "scene3d.h"

//*****************************************************************************
// マクロ定義
//*****************************************************************************
#define INITIAL_POSITION (D3DXVECTOR3(0.0f,0.0f,0.0f))

//*****************************************************************************
// 静的メンバ変数宣言
//*****************************************************************************
LPDIRECT3DTEXTURE9 CPlayer::m_pTexture = NULL;
LPD3DXMESH CPlayer::m_pMesh[PARTS_MAX] = {};
LPD3DXBUFFER CPlayer::m_pBuffMat[PARTS_MAX] = {};
DWORD CPlayer::m_nNumMat[PARTS_MAX] = {};

//=============================================================================
// コンストラクタ
//=============================================================================
CPlayer::CPlayer()
{
	// メンバ変数
	m_move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);		// プレイヤーの移動量
}

//=============================================================================
// デストラクタ
//=============================================================================
CPlayer::~CPlayer()
{
}

//=============================================================================
// 初期化処理
//=============================================================================
HRESULT CPlayer::Init(void)
{
	// パーツ数を設定
	SetPartNum(PARTS_MAX);

	for (int nCount = 0; nCount < PARTS_MAX; nCount++)
	{
		BindMesh(CAnimation::TYPE_HUMAN, nCount, m_pMesh[nCount], m_pBuffMat[nCount], m_nNumMat[nCount]);
	}

	// 座標・親子関係の読み込み
	LoadModelData("./data/text/motion.txt");

	CCharacter::Init();
	SetPos(INITIAL_POSITION);


	return S_OK;
}

//=============================================================================
// 更新処理
//=============================================================================
void CPlayer::Update()
{
	// 操作処理
	Move();

	CCharacter::Update();
}

//=============================================================================
// プレイヤー操作処理
//=============================================================================
void CPlayer::Move(void)
{
	// プレイヤー情報を取得
	D3DXVECTOR3 pos, rot;

	pos = GetPos();
	rot = GetRot();

	// 1F前の位置を記憶
	SetPosOld(pos);

	CKeyboard * pKeyboard = CManager::GetKeyboard();

	// 左へ移動
	if (pKeyboard->GetKeyboardPress(DIK_LEFT))
	{
		m_move.x = sinf(rot.y - D3DXToRadian(90)) * PLAYER_SPEED;
		m_move.z = cosf(rot.y - D3DXToRadian(90)) * PLAYER_SPEED;
	}
	// 右へ移動
	if (pKeyboard->GetKeyboardPress(DIK_RIGHT))
	{
		m_move.x = sinf(rot.y + D3DXToRadian(90)) * PLAYER_SPEED;
		m_move.z = cosf(rot.y + D3DXToRadian(90)) * PLAYER_SPEED;
	}
	// 前へ移動
	if (pKeyboard->GetKeyboardPress(DIK_UP))
	{
		m_move.x = sinf(rot.y) * PLAYER_SPEED;
		m_move.z = cosf(rot.y) * PLAYER_SPEED;
	}
	// 後ろへ移動
	if (pKeyboard->GetKeyboardPress(DIK_DOWN))
	{
		m_move.x = sinf(rot.y) * -PLAYER_SPEED;
		m_move.z = cosf(rot.y) * -PLAYER_SPEED;
	}
	// 右へ回転
	if (pKeyboard->GetKeyboardPress(DIK_E))
	{
		rot.y += D3DXToRadian(2);
	}
	// 右へ回転
	if (pKeyboard->GetKeyboardPress(DIK_Q))
	{
		rot.y -= D3DXToRadian(2);
	}

	// 慣性の計算
	m_move.x += (0.0f - m_move.x) * FRICTION;
	m_move.y += (0.0f - m_move.y) * FRICTION;
	m_move.z += (0.0f - m_move.z) * FRICTION;

	// 位置の移動
	pos += m_move;

	// 当たり判定
	//CScene3d *pScene3d = NULL;

	//for (int nCount = 0; nCount < MAX_POLYGON; nCount++)
	//{
	//	// オブジェクト取得
	//	CScene *pScene = CScene::GetObj(nCount);

	//	if (pScene != NULL)
	//	{
	//		// 当たり判定用の変数
	//		BLOCK_HIT_INFO blockHitInfo;
	//		blockHitInfo.hitSurface = HIT_SURFACE_NONE;
	//		blockHitInfo.pos = pos;

	//		if (pScene->GetObjType() == CScene::OBJ_TYPE_CUBE)
	//		{
	//			// characterにキャスト
	//			pScene3d = (CScene3d*)pScene;
	//			// 当たり判定の計算
	//	/*		blockHitInfo = BlockCollision3D(&pos, &GetPosOld(), &pScene3d->GetPos(),
	//				&COLLLISION_SIZE, &pScene3d->GetCollisionSize());*/
	//		}

	//		// ブロックの当たり判定で計算した位置を、結びつける
	//		pos = blockHitInfo.pos;

	//	}
	//}

	SetPos(pos);
	SetRot(rot);
}

//=============================================================================
// 描画処理
//=============================================================================
void CPlayer::Draw()
{
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

	CCharacter::Draw();
}

//=============================================================================
// 終了処理
//=============================================================================
void CPlayer::Uninit()
{
	CCharacter::Uninit();
}

//=============================================================================
// テクスチャ読み込み処理
//=============================================================================
HRESULT CPlayer::Load(void)
{
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

	// プレイヤー1
	D3DXLoadMeshFromX(LPCSTR("./data/player/00_Body.x"), D3DXMESH_SYSTEMMEM, pDevice, NULL, &m_pBuffMat[PARTS_BODY], NULL, &m_nNumMat[PARTS_BODY], &m_pMesh[PARTS_BODY]);
	D3DXLoadMeshFromX(LPCSTR("./data/player/01_Head.x"), D3DXMESH_SYSTEMMEM, pDevice, NULL, &m_pBuffMat[PARTS_HEAD], NULL, &m_nNumMat[PARTS_HEAD], &m_pMesh[PARTS_HEAD]);
	D3DXLoadMeshFromX(LPCSTR("./data/player/02_RightArm.x"), D3DXMESH_SYSTEMMEM, pDevice, NULL, &m_pBuffMat[PARTS_RARM], NULL, &m_nNumMat[PARTS_RARM], &m_pMesh[PARTS_RARM]);
	D3DXLoadMeshFromX(LPCSTR("./data/player/03_RightHand.x"), D3DXMESH_SYSTEMMEM, pDevice, NULL, &m_pBuffMat[PARTS_RHAND], NULL, &m_nNumMat[PARTS_RHAND], &m_pMesh[PARTS_RHAND]);
	D3DXLoadMeshFromX(LPCSTR("./data/player/04_LeftArm.x"), D3DXMESH_SYSTEMMEM, pDevice, NULL, &m_pBuffMat[PARTS_LARM], NULL, &m_nNumMat[PARTS_LARM], &m_pMesh[PARTS_LARM]);
	D3DXLoadMeshFromX(LPCSTR("./data/player/05_LeftHand.x"), D3DXMESH_SYSTEMMEM, pDevice, NULL, &m_pBuffMat[PARTS_LHAND], NULL, &m_nNumMat[PARTS_LHAND], &m_pMesh[PARTS_LHAND]);
	D3DXLoadMeshFromX(LPCSTR("./data/player/06_RightLeg.x"), D3DXMESH_SYSTEMMEM, pDevice, NULL, &m_pBuffMat[PARTS_RLEG], NULL, &m_nNumMat[PARTS_RLEG], &m_pMesh[PARTS_RLEG]);
	D3DXLoadMeshFromX(LPCSTR("./data/player/07_RightShoe.x"), D3DXMESH_SYSTEMMEM, pDevice, NULL, &m_pBuffMat[PARTS_RFOOT], NULL, &m_nNumMat[PARTS_RFOOT], &m_pMesh[PARTS_RFOOT]);
	D3DXLoadMeshFromX(LPCSTR("./data/player/08_LeftLeg.x"), D3DXMESH_SYSTEMMEM, pDevice, NULL, &m_pBuffMat[PARTS_LLEG], NULL, &m_nNumMat[PARTS_LLEG], &m_pMesh[PARTS_LLEG]);
	D3DXLoadMeshFromX(LPCSTR("./data/player/09_LeftShoe.x"), D3DXMESH_SYSTEMMEM, pDevice, NULL, &m_pBuffMat[PARTS_LSHOE], NULL, &m_nNumMat[PARTS_LSHOE], &m_pMesh[PARTS_LSHOE]);

	return S_OK;
}

//=============================================================================
// テクスチャ破棄処理
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
// インスタンス生成処理
//=============================================================================
CPlayer * CPlayer::Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot)
{
	CPlayer *pPlayer;
	pPlayer = new CPlayer;
	pPlayer->SetObjType(OBJTYPE_PLAYER);
	pPlayer->Init();
	return pPlayer;
}