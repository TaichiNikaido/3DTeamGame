//================================================
//
// ui_number処理 [ui_number.h]
// Author : 佐藤颯紀
//
//================================================

//================================================
// インクルードファイル
//================================================
#include "meat.h"
#include "number.h"
#include "manager.h"


#include "Keyboard.h"
//================================================
// 静的メンバ変数宣言
//================================================
int CMeatUI::m_nMeat = NULL;

//================================================
// クリエイト処理
//================================================
CMeatUI *CMeatUI::Create()
{
	CMeatUI *pMeat;
	pMeat = new CMeatUI;
	pMeat->Init();

	return pMeat;
}

//====================================================
// コンストラクタ
//====================================================
CMeatUI::CMeatUI(int nPriority) : CScene(nPriority)
{

}

//====================================================
// デストラクタ
//====================================================
CMeatUI::~CMeatUI()
{

}

//================================================
// 初期化処理
//================================================
HRESULT CMeatUI::Init()
{
	m_nMeat = MEAT_POSSESSION;		// 肉の初期値

	for (int nCount = 0; nCount < MEATE_MAX_DIGITS; nCount++)
	{
		// 数字の生成
		m_apNumber[nCount] = CNumber::Create(D3DXVECTOR3(MEAT_NUMBER_POS_X + nCount*MEAT_NUMBER_SIZE, MEAT_NUMBER_POS_Y, 0.0f),
			D3DXVECTOR3(MEAT_NUMBER_SIZE, MEAT_NUMBER_SIZE, 0.0f),
			CNumber::NUMBERTYPE_MEAT);
	}

	// 加算
	AddMeat(0);

	return S_OK;
}

//================================================
// 終了処理
//================================================
void CMeatUI::Uninit(void)
{
	for (int nCount = 0; nCount < MEATE_MAX_DIGITS; nCount++)
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
void CMeatUI::Update(void)
{
	for (int nCount = 0; nCount < MEATE_MAX_DIGITS; nCount++)
	{
		// 更新処理
		m_apNumber[nCount]->Update();
	}

	CKeyboard *pKeyboard = CManager::GetKeyboard();

	if (pKeyboard->GetKeyboardTrigger(DIK_S) == TRUE)
	{
		AddMeat(1);
	}

	if (pKeyboard->GetKeyboardTrigger(DIK_D) == TRUE)
	{
		AddMeat(-1);
	}
}

//================================================
// 描画処理
//================================================
void CMeatUI::Draw(void)
{
	for (int nCount = 0; nCount < MEATE_MAX_DIGITS; nCount++)
	{
		// 描画処理
		m_apNumber[nCount]->Draw();
	}
}

//================================================
// 肉の加算
//================================================
void CMeatUI::AddMeat(int nValue)
{
	// 呼び出されたら加算する
	m_nMeat += nValue;

	for (int nCount = 0; nCount < MEATE_MAX_DIGITS; nCount++)
	{
		// 表示してる数字に加算させる
		m_apNumber[nCount]->SetNumber(m_nMeat % (int)powf(10, MEATE_MAX_DIGITS - nCount) / powf(10, MEATE_MAX_DIGITS - nCount - 1));
	}
}

