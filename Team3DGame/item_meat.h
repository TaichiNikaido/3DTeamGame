//=============================================================================
//
// 肉 [item_meat.h]
// Author : 二階堂汰一
//
//=============================================================================
#ifndef _ITEM_MEAT_H_
#define _ITEM_MEAT_H_

//*****************************************************************************
// ヘッダファイルのインクルード
//*****************************************************************************
#include "item.h"
#include "model.h"
#include "motion.h"

//*****************************************************************************
// マクロ定義
//*****************************************************************************

//*****************************************************************************
// 前方宣言
//*****************************************************************************

//*****************************************************************************
// クラス定義
//*****************************************************************************
class CMeat : public CItem
{
public:
	CMeat();
	~CMeat();
	static CMeat * Create(D3DXVECTOR3 Position);
	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);
private:
	void Collision(void);
	void Give(void);
};
#endif
