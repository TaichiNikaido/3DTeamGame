//================================================
//
// ダイヤの所持数処理 [Daiya.h]
// Author : 佐藤颯紀
//
//================================================

#ifndef _DAIYA_H_
#define _DAIYA_H_

//================================================
//インクルードファイル
//================================================
#include "main.h"
#include "scene.h"
#include "number.h"

//================================================
//マクロ定義
//================================================
#define DAIYA_MAX_DIGITS	(2)			// 最大桁数
#define DAIYA_NUMBER_POS_X	(1790.0f)	// ダイヤの所持数のX座標
#define DAIYA_NUMBER_POS_Y	(250.0f)	// ダイヤの所持数のY座標
#define DAIYA_NUMBER_SIZE	(40.0f)		// ダイヤの所持数のサイズ

//================================================
//クラス宣言
//================================================
class CDaiya : public CScene
{
public:
	CDaiya(int nPriority = OBJTYPE_DEFAULT);
	~CDaiya();

	static CDaiya *Create();

	HRESULT Init();
	void Uninit(void);
	void Update(void);
	void Draw(void);

	void AddDaiya(int nValue);		// ダイヤの加算
	static int GetDaiya(void) { return m_nDaiya; }	// ダイヤの取得

private:
	CNumber *m_apNumber[DAIYA_MAX_DIGITS];	// 桁数
	static int m_nDaiya;			// ダイヤ
};

#endif // ! _UI_NUMBER_H_
