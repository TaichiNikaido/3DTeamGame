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
class CResultlogo;
class CTitlelogo;
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

	static CResultMode *GetLogo(int nCount) { return m_pResultlogo; }
	static CTitlelogo *GetLogo(void) { return m_pTitlelogo; }
	static CScore *GetScore(void) { return m_pScore; }

private:
	void InitCreateAll(void);

	static CResultMode *m_pResultlogo;			// タイトルロゴのポインタ
	static CTitlelogo *m_pTitlelogo;			// タイトルロゴのポインタ
	static CScore *m_pScore;					// スコアのポインタ
};
#endif
