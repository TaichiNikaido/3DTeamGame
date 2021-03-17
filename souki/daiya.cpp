//================================================
//
// ui_number処理 [ui_number.h]
// Author : 佐藤颯紀
//
//================================================

//================================================
// インクルードファイル
//================================================
#include "daiya.h"
#include "number.h"
#include "manager.h"

#include "Keyboard.h"
//================================================
// 静的メンバ変数宣言
//================================================
int CDaiya::m_nDaiya = NULL;

//================================================
// クリエイト処理
//================================================
CDaiya *CDaiya::Create()
{
	CDaiya *pDaiya;
	pDaiya = new CDaiya;
	pDaiya->Init();

	return pDaiya;
}

//====================================================
// コンストラクタ
//====================================================
CDaiya::CDaiya(int nPriority) : CScene(nPriority)
{

}

//====================================================
// デストラクタ
//====================================================
CDaiya::~CDaiya()
{

}

//================================================
// 初期化処理
//================================================
HRESULT CDaiya::Init()
{
	m_nDaiya = 0;		// ダイヤの初期値

	for (int nCount = 0; nCount < DAIYA_MAX_DIGITS; nCount++)
	{
		// 数字の生成
		m_apNumber[nCount] = CNumber::Create(D3DXVECTOR3(DAIYA_NUMBER_POS_X + nCount*DAIYA_NUMBER_SIZE, DAIYA_NUMBER_POS_Y, 0.0f),
			D3DXVECTOR3(DAIYA_NUMBER_SIZE, DAIYA_NUMBER_SIZE, 0.0f),
			CNumber::NUMBERTYPE_DAIYA);
	}

	// 加算
	AddDaiya(0);

	return S_OK;
}

//================================================
// 終了処理
//================================================
void CDaiya::Uninit(void)
{
	for (int nCount = 0; nCount < DAIYA_MAX_DIGITS; nCount++)
	{
		//ナンバー処理の終了と開放
		if (m_apNumber[nCount] != NULL)
		{
			// 終了処理
			m_apNumber[nCount]->Uninit();
			m_apNumber[nCount] = NULL;
		}
	}
	// 開放
	Release();
}

//================================================
// 更新処理
//================================================
void CDaiya::Update(void)
{
	for (int nCount = 0; nCount < DAIYA_MAX_DIGITS; nCount++)
	{
		// 更新処理
		m_apNumber[nCount]->Update();
	}

	CKeyboard *pKeyboard = CManager::GetKeyboard();

	if (pKeyboard->GetKeyboardTrigger(DIK_A) == TRUE)
	{
		AddDaiya(1);
	}
}

//================================================
// 描画処理
//================================================
void CDaiya::Draw(void)
{
	for (int nCount = 0; nCount < DAIYA_MAX_DIGITS; nCount++)
	{
		// 描画処理
		m_apNumber[nCount]->Draw();
	}

}

//================================================
// ダイヤの加算
//================================================
void CDaiya::AddDaiya(int nValue)
{
	// 呼び出されたら加算する
	m_nDaiya += nValue;

	for (int nCount = 0; nCount < DAIYA_MAX_DIGITS; nCount++)
	{
		// 表示してる数字に加算させる
		m_apNumber[nCount]->SetNumber(m_nDaiya % (int)powf(10, DAIYA_MAX_DIGITS - nCount) / powf(10, DAIYA_MAX_DIGITS - nCount - 1));
	}
}