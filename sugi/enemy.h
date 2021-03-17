//=============================================================================
//
// プレイヤー処理 [enemy.h]
// Author : 樋宮 匠
//
//=============================================================================

// 2重インクルード防止用
#ifndef _ENEMY_H_
#define _ENEMY_H_
//*****************************************************************************
// インクルードファイル
//*****************************************************************************
#include "main.h"
#include "character.h"

//*****************************************************************************
// マクロ定義
//*****************************************************************************
#define FRICTION 0.2f		 // 慣性
//#define ENEMY_SEG_X 1.0f	 // エネミーテクスチャの横分割数
//#define ENEMY_SEG_Y 1.0f	 // エネミーテクスチャの縦分割数
#define ENEMY_SPEED 10.0f	 // エネミーの移動速度
#define ENEMY_GRAVITY -5.0f  // 重力の強さ
#define FIRE_RATE 10
#define COLLLISION_SIZE D3DXVECTOR3(200.0f, 400.0f, 200.0f)

//*****************************************************************************
// プレイヤークラス定義
//*****************************************************************************
class CEnemy :public CCharacter
{
public:
	CEnemy();
	~CEnemy();

	// モデルの各パーツ
	typedef enum
	{
		PARTS_WAIST = 0,
		PARTS_BODY,
		PARTS_HEAD,
		PARTS_RARM,
		PARTS_LARM,
		PARTS_RLEG,
		PARTS_RSHOE,
		PARTS_LLEG,
		PARTS_LSHOE,
		PARTS_MAINTAIL,
		PARTS_SUBTAIL,
		PARTS_ENDTAIL,
		PARTS_CHIN,
		PARTS_MAX,
	}PARTS;

	HRESULT Init(void);
	void Update(void);
	void Move(void);
	void Draw(void);
	void Uninit(void);
	static HRESULT Load(void);
	static void Unload(void);
	static CEnemy * Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot);
	D3DXVECTOR3 GetMove(void) { return m_move; }
private:
	// 静的メンバ変数
	static LPDIRECT3DTEXTURE9		m_pTexture;			// テクスチャへのポインタ
	static LPD3DXMESH		m_pMesh[PARTS_MAX];
	static LPD3DXBUFFER		m_pBuffMat[PARTS_MAX];
	static DWORD			m_nNumMat[PARTS_MAX];

	// メンバ変数
	D3DXVECTOR3						m_move;				// ポリゴンの移動量

	float							m_fGravDest;
	bool							m_bHit;
};
#endif