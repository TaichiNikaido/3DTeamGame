//================================================
//
// ui処理 [ui.cpp]
// Author : 佐藤颯紀
//
//================================================

//================================================
// インクルード
//================================================
#include "ui.h"
#include "manager.h"
#include "renderer.h"
#include "mode_game.h"

//================================================
// 静的メンバ変数宣言
//================================================
LPDIRECT3DTEXTURE9 CUi::m_apTexture[UI_TYPE] = {};

//================================================
// クリエイト処理
//================================================
CUi* CUi::Create(D3DXVECTOR3 pos, D3DXVECTOR3 size, UITYPE type)
{
	CUi* pUi = NULL;

	// 動的確保
	pUi = new CUi;

	// 初期化処理
	pUi->Init(pos, size, type);

	return pUi;
}

//================================================
// ロード処理
//================================================
HRESULT CUi::Load(void)
{
	LPDIRECT3DDEVICE9 pDevice;
	// デバイス情報の取得
	pDevice = CManager::GetRenderer()->GetDevice();

	// テクスチャの読み込み

	// ダイヤ
	D3DXCreateTextureFromFile(pDevice,
		"data/Texture/Daiya.png", //ファイルの読み込み
		&m_apTexture[UITYPE_DAIYA]);

	// 肉
	D3DXCreateTextureFromFile(pDevice,
		"data/Texture/Meat.png", //ファイルの読み込み
		&m_apTexture[UITYPE_MEAT]);

	// 警報
	D3DXCreateTextureFromFile(pDevice,
		"data/Texture/WinMark.png", //ファイルの読み込み
		&m_apTexture[UITYPE_WARNING]);

	return S_OK;
}

//================================================
// ロードの終了
//================================================
void CUi::Unload(void)
{
	for (int nCount = 0; nCount < UI_TYPE; nCount++)
	{
		//テクスチャの開放
		if (m_apTexture[nCount] != NULL)
		{
			m_apTexture[nCount]->Release();
			m_apTexture[nCount] = NULL;
		}
	}
}

//================================================
//コンストラクタ
//================================================
CUi::CUi(int nPriority) :CScene2d(nPriority)
{
	m_pos = (D3DXVECTOR3(0.0f, 0.0f, 0.0f));		// 座標
	m_move = (D3DXVECTOR3(0.0f, 0.0f, 0.0f));		// 移動量
	m_size = (D3DXVECTOR3(0.0f, 0.0f, 0.0f));		// サイズ
	m_col = (D3DXCOLOR(0.0f, 0.0f, 0.0f, 0.0f));	// カラー
	m_type = UITYPE_NONE;							// タイプ
	m_nColCounter = 0;									// カウンター
	m_nEraseCounter = 0;									// 使用しているかどうか
}

//================================================
//デストラクタ
//================================================
CUi::~CUi()
{

}

//================================================
//初期化処理
//================================================
HRESULT CUi::Init(D3DXVECTOR3 pos, D3DXVECTOR3 size, UITYPE type)
{
	m_pos = pos;	// 位置情報
	m_size = size;	// サイズ
	m_type = type;	// タイプ

	//初期化
	CScene2d::Init();

	// 位置情報
	CScene2d::SetPosition(D3DXVECTOR3(m_pos.x, m_pos.y, m_pos.z));

	// サイズ
	CScene2d::SetSize(D3DXVECTOR3(m_size.x, m_size.y, m_size.z));

	// カラー
	CScene2d::SetColor(D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));

	// テクスチャー
	D3DXVECTOR2 texture[4];
	texture[0] = D3DXVECTOR2(0.0f, 0.0f);
	texture[1] = D3DXVECTOR2(1.0f, 0.0f);
	texture[2] = D3DXVECTOR2(0.0f, 1.0f);
	texture[3] = D3DXVECTOR2(1.0f, 1.0f);

	// テクスチャーの設定
	CScene2d::SetTexture(texture);

	// テクスチャーの確保
	CScene2d::BindTexture(m_apTexture[type]);

	return S_OK;
}

//================================================
// 終了処理
//================================================
void CUi::Uninit(void)
{
	// 終了処理
	CScene2d::Uninit();
}

//================================================
// 更新処理
//================================================
void CUi::Update(void)
{
	// 更新処理
	CScene2d::Update();

	// WARNINGを点滅させる処理
	Flashing();
}

//================================================
// 描画処理
//================================================
void CUi::Draw(void)
{
	// 描画処理
	CScene2d::Draw();
}

//================================================
// 点滅させる処理
//================================================
void CUi::Flashing(void)
{
	D3DXCOLOR col = GetColor();

	if (m_type == UITYPE_WARNING)
	{
		// 毎フレームごとにカウンターを増やす
		m_nColCounter++;
		// 毎フレームごとにカウンターを増やす
		m_nEraseCounter++;

		if (m_nColCounter == WARNING_COL_IN)
		{
			col.a = 1.0f;
		}
		else if (m_nColCounter == WARNING_COL_OUT)
		{
			col.a = 0.0f;
			m_nColCounter = 0.0f;
		}

		// カウンターが一定値に達すると
		if (m_nEraseCounter == WARNING_ERASE)
		{
			// カウンターを０にする
			m_nEraseCounter = 0;
			// 終了処理
			Uninit();
			return;
		}
	}

	// 色の設定
	SetColor(col);
}
