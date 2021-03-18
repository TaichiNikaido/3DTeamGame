//=============================================================================
//
// タイトルモード [mode_title.h]
// Author : 二階堂汰一
//
//=============================================================================
#ifndef _MODE_TITLE_H_
#define _MODE_TITLE_H_

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
class CTitlelogo;

//*****************************************************************************
// クラス定義
//*****************************************************************************
class CTitleMode : CScene
{
public:
	CTitleMode();
	~CTitleMode();
	static CTitleMode * Create();
	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);
	static CTitlelogo *GetLogo(void) { return m_pTitlelogo; }
private:
	void Input(void);
	void InitCreateAll(void);
	static CTitlelogo *m_pTitlelogo;			//タイトルロゴのポインタ
};
#endif
