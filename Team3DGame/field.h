//=============================================================================
//
// 背景処理 [wall.h]
// Author : 樋宮 匠
//
//=============================================================================

// 2重インクルード防止用
#ifndef _WALL_H_
#define _WALL_H_
//*****************************************************************************
// インクルードファイル
//*****************************************************************************
#include "main.h"
#include "scene.h"
#include "tile.h"

//*****************************************************************************
// マクロ定義
//*****************************************************************************
#define FIELD_SIZE 2000
#define FIELD_WIDTH  10
#define FIELD_HEIGHT 10
#define FIELD_NUM 2
#define MAX_TILE_LINE 80   // 一列のタイルの最大数

//*****************************************************************************
// プレイヤークラス定義
//*****************************************************************************
class CField : public CScene
{
public:
	CField();
	~CField();

	typedef enum
	{
		FLOOR = 0,
		CEILING,
	}TYPE;

	HRESULT Init(void);
	void Update();
	void Draw();
	void Uninit();
	void LoadMapData(TYPE type, int nWidth, int nDepth);
	static CField *Create(TYPE type = FLOOR, int nWidth = FIELD_WIDTH, int nDepth = FIELD_HEIGHT);
	void SetField(int nWidth, int nDepth);
private:
	// メンバ変数
	CTile						*m_apTile[MAX_TILE_LINE][MAX_TILE_LINE];			// 3Dポリゴンへのポインタ
	int							m_aGround[MAX_TILE_LINE][MAX_TILE_LINE];
};
#endif