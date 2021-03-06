//=============================================================================
//
// リザルトモード [mode_result.h]
// Author : 二階堂汰一
//
//=============================================================================
#ifndef _MODE_RESULT_H_
#define _MODE_RESULT_H_

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
class CScore;

//*****************************************************************************
// クラス定義
//*****************************************************************************
class CResultMode : CScene
{
public:
	CResultMode();
	~CResultMode();
	static CResultMode * Create();
	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);
	static CScore *GetScore(void) { return m_pScore; }
private:
	void CreateAll(void);
	static CScore *m_pScore;					// スコアのポインタ
};
#endif
