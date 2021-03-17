//=============================================================================
//
// アイテム [item.cpp]
// Author : 二階堂汰一
//
//=============================================================================

//*****************************************************************************
// 警告制御
//*****************************************************************************
#define _CRT_SECURE_NO_WARNINGS

//*****************************************************************************
// ヘッダファイルのインクルード
//*****************************************************************************
#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include "manager.h"
#include "mode_game.h"
#include "renderer.h"
#include "item.h"

//*****************************************************************************
// マクロ定義
//*****************************************************************************
#define INITIAL_POSITION (D3DXVECTOR3(0.0f,0.0f,0.0f))			//位置の初期値
#define INITIAL_SIZE (D3DXVECTOR3(0.0f,0.0f,0.0f))				//サイズの初期値
#define INITIAL_COLLISIION_SIZE (D3DXVECTOR3(0.0f,0.0f,0.0f))	//衝突判定用サイズの初期値
#define INITIAL_ROTATION (D3DXVECTOR3(0.0f,0.0f,0.0f))			//回転の初期値
#define INITIAL_MOVE (D3DXVECTOR3(0.0f,0.0f,0.0f))				//移動量の初期値

//*****************************************************************************
// 静的メンバ変数の初期化
//*****************************************************************************

//=============================================================================
// コンストラクタ
//=============================================================================
CItem::CItem()
{
	m_Position = INITIAL_POSITION;							//位置
	m_PositionOld = INITIAL_POSITION;						//前の位置
	m_Size = INITIAL_SIZE;									//サイズ
	m_CollisionSize = INITIAL_SIZE;							//当たり判定用サイズ
	m_Rotation = INITIAL_ROTATION;							//回転
	memset(m_apScriptPass, NULL, sizeof(m_apScriptPass));	//スクリプトパス
}

//=============================================================================
// デストラクタ
//=============================================================================
CItem::~CItem()
{
}

//=============================================================================
// 初期化処理関数
//=============================================================================
HRESULT CItem::Init(void)
{
	return S_OK;
}

//=============================================================================
// 終了処理関数
//=============================================================================
void CItem::Uninit(void)
{
	//破棄処理関数呼び出し
	Release();
}

//=============================================================================
// 更新処理関数
//=============================================================================
void CItem::Update(void)
{
}

//=============================================================================
// 描画処理関数
//=============================================================================
void CItem::Draw(void)
{
}

//=============================================================================
// 衝突処理関数関数
//=============================================================================
bool CItem::bCollision(D3DXVECTOR3 TargetPositon, D3DXVECTOR3 TargetSize)
{
	bool bCollision = false;
	return bCollision;
}

//=============================================================================
// データ読み込み関数
//=============================================================================
void CItem::DataLoad(void)
{
	char aReadText[MAX_TEXT];			//読み込んだテキスト
	char aCurrentText[MAX_TEXT];		//現在のテキスト
	char aUnnecessaryText[MAX_TEXT];	//不必要なテキスト
	memset(aReadText, NULL, sizeof(aReadText));
	memset(aCurrentText, NULL, sizeof(aCurrentText));
	memset(aUnnecessaryText, NULL, sizeof(aUnnecessaryText));
	//ファイルのポインタ
	FILE *pFile = NULL;
	//もしファイルのポインタがNULLの場合
	if (pFile == NULL)
	{
		//ファイルの読み込み
		pFile = fopen(m_apScriptPass[0], "r");
	}
	//ファイルを開くことができたら
	if (pFile != NULL)
	{
		//SCRIPTの文字を見つける
		while (strcmp(aCurrentText, "SCRIPT") != 0)
		{
			//読み込んだテキストを格納する
			fgets(aReadText, sizeof(aReadText), pFile);
			//読み込んだテキストを現在のテキストに格納
			sscanf(aReadText, "%s", &aCurrentText);
		}
		//現在のテキストがSCRIPTだったら
		if (strcmp(aCurrentText, "SCRIPT") == 0)
		{
			//END_SCRIPTの文字が見つかるまで読む
			while (strcmp(aCurrentText, "END_SCRIPT") != 0)
			{
				//読み込んだテキストを格納する
				fgets(aReadText, sizeof(aReadText), pFile);
				//読み込んだテキストを現在のテキストに格納
				sscanf(aReadText, "%s", &aCurrentText);
				//現在のテキストがPARAMETER_SETだったら
				if (strcmp(aCurrentText, "PARAMETER_SET") == 0)
				{
					//END_PARAMETER_SETの文字が見つかるまで読む
					while (strcmp(aCurrentText, "END_PARAMETER_SET") != 0)
					{
						//読み込んだテキストを格納する
						fgets(aReadText, sizeof(aReadText), pFile);
						//読み込んだテキストを現在のテキストに格納
						sscanf(aReadText, "%s", &aCurrentText);
						//現在のテキストがSIZEだったら
						if (strcmp(aCurrentText, "SIZE") == 0)
						{
							//サイズの設定
							sscanf(aReadText, "%s %s %f %f %f", &aUnnecessaryText, &aUnnecessaryText, &m_Size.x, &m_Size.y, &m_Size.z);
						}
						//現在のテキストがCOLLISION_SIZEだったら
						if (strcmp(aCurrentText, "COLLISION_SIZE") == 0)
						{
							//サイズの設定
							sscanf(aReadText, "%s %s %f %f %f", &aUnnecessaryText, &aUnnecessaryText, &m_CollisionSize.x, &m_CollisionSize.y, &m_CollisionSize.z);
						}
						//現在のテキストがROTだったら
						if (strcmp(aCurrentText, "ROT") == 0)
						{
							//回転情報の読み込み
							sscanf(aReadText, "%s %s %f %f %f", &aUnnecessaryText, &aUnnecessaryText, &m_Rotation.x, &m_Rotation.y, &m_Rotation.z);
						}
					}
				}
			}
		}
		//ファイルを閉じる
		fclose(pFile);
	}
}
