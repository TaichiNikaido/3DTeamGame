//=============================================================================
//
// コンティニューロゴ [continue_logo.cpp]
// Author : 二階堂汰一
//
//=============================================================================

//*****************************************************************************
// ヘッダファイルのインクルード
//*****************************************************************************
#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include "manager.h"
#include "mode_game.h"
#include "renderer.h"
#include "scene2d.h"
#include "continue_logo.h"

//*****************************************************************************
// マクロ定義
//*****************************************************************************
#define TEXTURE ("Data/Texture/CONTINUE.png")										//テクスチャ
#define SIZE (D3DXVECTOR3(700.0f,250.0f,0.0f))										//サイズ
#define POSITION (D3DXVECTOR3(SCREEN_WIDTH / 2,SCREEN_HEIGHT - SIZE.y * 3.0,0.0f))	//位置
#define FLAME (0)																	//フレーム

//*****************************************************************************
// 静的メンバ変数の初期化
//*****************************************************************************
LPDIRECT3DTEXTURE9 CContinueLogo::m_pTexture = NULL;	//テクスチャへのポインタ

//=============================================================================
// コンストラクタ
//=============================================================================
CContinueLogo::CContinueLogo()
{
}

//=============================================================================
// デストラクタ
//=============================================================================
CContinueLogo::~CContinueLogo()
{
}

//=============================================================================
// テクスチャ読み込み関数
//=============================================================================
HRESULT CContinueLogo::TextureLoad(void)
{
	//レンダラーの取得
	CRenderer *pRenderer = CManager::GetRenderer();
	//デバイスの取得
	LPDIRECT3DDEVICE9 pDevice = pRenderer->GetDevice();
	// テクスチャの生成
	D3DXCreateTextureFromFile(pDevice,	// デバイスへのポインタ
		TEXTURE,						// ファイルの名前
		&m_pTexture);					// 読み込むメモリー
	return S_OK;
}

//=============================================================================
// テクスチャ破棄関数
//=============================================================================
void CContinueLogo::TextureUnload(void)
{
	//もしテクスチャがNULLじゃない場合
	if (m_pTexture != NULL)
	{
		//テクスチャの破棄処理関数呼び出し
		m_pTexture->Release();
		//テクスチャをNULLにする
		m_pTexture = NULL;
	}
}

//=============================================================================
// 生成処理関数
//=============================================================================
CContinueLogo * CContinueLogo::Create(void)
{
	//コンティニューロゴのポインタ
	CContinueLogo * pContinueLogo = NULL;
	//もしコンティニューロゴのポインタがNULLの場合
	if (pContinueLogo == NULL)
	{
		//コンティニューロゴのメモリ確保
		pContinueLogo = new CContinueLogo;
		//もしコンティニューロゴがNULLじゃない場合
		if (pContinueLogo != NULL)
		{
			//初期化処理関数呼び出し
			pContinueLogo->Init();
			//位置を設定する
			pContinueLogo->SetPosition(POSITION);
			//サイズを設定する
			pContinueLogo->SetSize(SIZE);
		}
	}
	//コンティニューロゴのポインタを返す
	return pContinueLogo;
}

//=============================================================================
// 初期化処理関数
//=============================================================================
HRESULT CContinueLogo::Init(void)
{
	//テクスチャのUV座標の設定
	D3DXVECTOR2 aTexture[NUM_VERTEX];
	aTexture[0] = D3DXVECTOR2(0.0f, 0.0f);
	aTexture[1] = D3DXVECTOR2(1.0f, 0.0f);
	aTexture[2] = D3DXVECTOR2(0.0f, 1.0f);
	aTexture[3] = D3DXVECTOR2(1.0f, 1.0f);
	//シーン2Dの初期化処理関数呼び出し
	CScene2d::Init();
	//テクスチャの設定
	SetTexture(aTexture);
	//テクスチャの割り当て
	BindTexture(m_pTexture);
	return S_OK;
}

//=============================================================================
// 終了処理関数
//=============================================================================
void CContinueLogo::Uninit(void)
{
	//シーン2Dの終了処理関数呼び出し
	CScene2d::Uninit();
}

//=============================================================================
// 更新処理関数
//=============================================================================
void CContinueLogo::Update(void)
{
	//シーン2Dの更新処理関数呼び出し
	CScene2d::Update();
}

//=============================================================================
// 描画処理関数
//=============================================================================
void CContinueLogo::Draw(void)
{
	//シーン2Dの描画処理関数呼び出し
	CScene2d::Draw();
}
