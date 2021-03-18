//=============================================================================
//
// コンティニューロゴ [continue_logo.h]
// Author : 二階堂汰一
//
//=============================================================================
#ifndef _CONTINUE_LOGO_H_
#define _CONTINUE_LOGO_H_

//*****************************************************************************
// ヘッダファイルのインクルード
//*****************************************************************************
#include "scene2d.h"

//*****************************************************************************
// マクロ定義
//*****************************************************************************

//*****************************************************************************
// 前方宣言
//*****************************************************************************

//*****************************************************************************
// 構造体定義
//*****************************************************************************

//*****************************************************************************
// クラス定義
//*****************************************************************************
class CContinueLogo :public CScene2d
{
public:
	CContinueLogo();
	~CContinueLogo();
	static HRESULT TextureLoad(void);
	static void TextureUnload(void);
	static CContinueLogo * Create(void);
	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);
private:
	static LPDIRECT3DTEXTURE9 m_pTexture;	//テクスチャへのポインタ
};
#endif