//=============================================================================
//
// 敵処理 [enemy.h]
// Author : 二階堂汰一
//
//=============================================================================
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
	typedef enum
	{
		MOTION_NONE = -1,
		MOTION_DUSH,
		MOTION_MEAL,
		MOTION_FALL,
		MOTION_ATTACK
	}MOTIONENEMY;
	static HRESULT Load(void);
	static void Unload(void);
	static CEnemy * Create(void);
	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);
	void Eat(void);
private:
	void AutoRun(void);
	void Attack(void);
	void Death(void);
	void DataLoad(void);
	static LPDIRECT3DTEXTURE9 m_pTexture;			// テクスチャへのポインタ
	static LPD3DXMESH m_pMesh[PARTS_MAX];
	static LPD3DXBUFFER m_pBuffMat[PARTS_MAX];
	static DWORD m_nNumMat[PARTS_MAX];
	D3DXVECTOR3 m_Size;										//サイズ
	D3DXVECTOR3 m_Move;										//移動量
	int m_nMeatEatTime;										//肉を食べる時間
	int m_nMeatEatTimeCount;								//肉を食べる時間のカウント
	int m_nAttackCoolTime;									//攻撃のクールタイム
	int m_nAttackCoolTimeCount;								//攻撃のクールタイムカウント
	float m_fAutoRunSpeed;									//オートランの速度
	bool m_bEat;											//食事をしてるかどうか
	bool m_bAttack;											//攻撃をしたか
};
#endif