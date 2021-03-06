//=============================================================================
//
// ゲームモード [mode_game.h]
// Author : 二階堂汰一
//
//=============================================================================
#ifndef _MODE_GAME_H_
#define _MODE_GAME_H_

//*****************************************************************************
// ヘッダファイルのインクルード
//*****************************************************************************
#include "scene.h"

//*****************************************************************************
// マクロ定義
//*****************************************************************************

//*****************************************************************************
// 前方宣言
//*****************************************************************************
class CLight;
class CCamera;
class CPlayer;
class CEnemy;
class CUi;

//*****************************************************************************
// クラス定義
//*****************************************************************************
class CGameMode : CScene
{
public:
	CGameMode();
	~CGameMode();
	static CGameMode * Create();
	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);
	static CCamera * GetCamera(void) { return m_pCamera; }
	static CPlayer * GetPlayer(void) { return m_pPlayer; }
	static CEnemy * GetEnemy(void) { return m_pEnemy; }
private:
	void InitCreateAll(void);
	void UpdateCreateAll(void);
	static CCamera * m_pCamera;	//カメラのポインタ
	static CPlayer * m_pPlayer;	//プレイヤーのポインタ
	static CEnemy * m_pEnemy;	//敵のポインタ
	static CUi * m_pUi;			//UIのポインタ
	CLight * m_pLight;			//ライトのポインタ
};
#endif
