//================================================
//
// スコア処理 [score.h]
// Author : 佐藤颯紀
//
//================================================

#ifndef _SCORE_H_
#define _SCORE_H_

//================================================
//インクルードファイル
//================================================
#include "main.h"
#include "scene.h"
#include "number.h"

//================================================
//マクロ定義
//================================================
#define MAX_SCORE		(2)			// スコアの最大桁数
#define ADD_SCORE		(1000)		// スコアの増える値
#define SCORE_POS_X		(1000.0f)	// スコアのX座標
#define SCORE_POS_Y		(700.0f)	// スコアのY座標
#define SCORE_SIZE		(50.0f)		// スコアサイズ

//================================================
//クラス宣言
//================================================
class CScore : public CScene
{
public:
	CScore(int nPriority = OBJTYPE_DEFAULT);
	~CScore();

	static CScore *Create();

	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	void AddScore(void);

private:
	CNumber *m_apNumber[MAX_SCORE];	// 桁数
	int m_nDaiya;			// ダイヤの数
	int m_nScore;			// スコア
};

#endif // ! _SCORE_H_
