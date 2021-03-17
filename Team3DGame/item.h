//=============================================================================
//
// アイテム [item.h]
// Author : 二階堂汰一
//
//=============================================================================
#ifndef _ITEM_H_
#define _ITEM_H_

//*****************************************************************************
// ヘッダファイルのインクルード
//*****************************************************************************
#include "scene.h"
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
class CItem : public CScene
{
public:
	CItem();
	~CItem();
	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);
	bool bCollision(D3DXVECTOR3 TargetPositon, D3DXVECTOR3 TargetSize);
	void SetPosition(D3DXVECTOR3 Position) { m_Position = Position; }
	void SetSize(D3DXVECTOR3 Size) { m_Size = Size; }
	void SetCollisionSize(D3DXVECTOR3 CollisionSize) { m_CollisionSize = CollisionSize; }
	void SetRotation(D3DXVECTOR3 Rotation) { m_Rotation = Rotation; }
	void SetScriptPass(char * pDataPass) { m_apScriptPass[0] = pDataPass; }
	D3DXVECTOR3 GetPosition(void) { return m_Position; }
	D3DXVECTOR3 GetCollisionSize(void) { return m_CollisionSize; }
private:
	void DataLoad(void);
	D3DXVECTOR3 m_Position;									//位置
	D3DXVECTOR3 m_PositionOld;								//前の位置
	D3DXVECTOR3 m_Size;										//サイズ
	D3DXVECTOR3 m_CollisionSize;							//当たり判定用サイズ
	D3DXVECTOR3 m_Rotation;									//回転
	const char * m_apScriptPass[MAX_PASS_LETTER];			//データスクリプトのパス
};
#endif
