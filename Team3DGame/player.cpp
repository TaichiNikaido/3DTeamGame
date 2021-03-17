//=============================================================================
//
// プレイヤー処理 [player.cpp]
// Author : 二階堂汰一
//
//=============================================================================

//*****************************************************************************
// インクルードファイル
//*****************************************************************************
#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include "manager.h"
#include "mode_game.h"
#include "renderer.h"
#include "sound.h"
#include "keyboard.h"
#include "joystick.h"
#include "player.h"
#include "camera.h"
#include "item_meat.h"

//*****************************************************************************
// マクロ定義
//*****************************************************************************
#define SCRIPT_PASS ("Data")
#define INITIAL_POSITION (D3DXVECTOR3(0.0f,0.0f,0.0f))			//位置の初期値
#define INITIAL_SIZE (D3DXVECTOR3(0.0f,0.0f,0.0f))				//サイズの初期値
#define INITIAL_COLLISIION_SIZE (D3DXVECTOR3(0.0f,0.0f,0.0f))	//衝突判定用サイズの初期値
#define INITIAL_ROTATION (D3DXVECTOR3(0.0f,0.0f,0.0f))			//回転の初期値
#define INITIAL_MOVE (D3DXVECTOR3(0.0f,0.0f,0.0f))				//移動量の初期値
#define MINIMUM_MEAT (0)										//肉の最小数
#define MINIMUM_DIAMOND (0)										//ダイアモンドの最小数
#define MINIMUM_STAN_TIME (0)									//スタン時間の最小値
#define INITIAL_MOVE_SPEED (0.0f)								//移動速度の初期値							
#define INITIAL_JUMP_POWER (0.0f)								//ジャンプ力の初期値

//*****************************************************************************
// 静的メンバ変数宣言
//*****************************************************************************
LPDIRECT3DTEXTURE9 CPlayer::m_pTexture = NULL;
LPD3DXMESH CPlayer::m_pMesh[PARTS_MAX] = {};
LPD3DXBUFFER CPlayer::m_pBuffMat[PARTS_MAX] = {};
DWORD CPlayer::m_nNumMat[PARTS_MAX] = {};

//=============================================================================
// コンストラクタ
//=============================================================================
CPlayer::CPlayer()
{
	m_Size = INITIAL_SIZE;											//サイズ
	m_Move = INITIAL_MOVE;											//移動量
	m_nMeat = MINIMUM_MEAT;											//肉の所持数
	m_nMaxMeat = MINIMUM_MEAT;										//肉の最大数
	m_nDiamond = MINIMUM_DIAMOND;									//ダイアモンドの所持数
	m_nStunTime = MINIMUM_STAN_TIME;								//スタン時間
	m_nStunTimeCount = MINIMUM_STAN_TIME;							//スタン時間のカウント
	m_fAutoRunSpeed = INITIAL_MOVE_SPEED;							//移動速度
	m_fLeftRightSpeed = INITIAL_MOVE_SPEED;							//左右移動速度
	m_fJumpPower = INITIAL_JUMP_POWER;								//ジャンプ力
	m_bHit = false;													//ヒットしたか
	m_State = STATE_NONE;											//状態
	m_Input = INPUT_NONE;											//入力情報
}

//=============================================================================
// デストラクタ
//=============================================================================
CPlayer::~CPlayer()
{
}

//=============================================================================
// モデル読み込み関数
//=============================================================================
HRESULT CPlayer::Load(void)
{
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

	// プレイヤー1
	D3DXLoadMeshFromX(LPCSTR("./data/model/LBX/00_waist.x"), D3DXMESH_SYSTEMMEM, pDevice, NULL, &m_pBuffMat[PARTS_HIP], NULL, &m_nNumMat[PARTS_HIP], &m_pMesh[PARTS_HIP]);
	D3DXLoadMeshFromX(LPCSTR("./data/model/LBX/01_body.x"), D3DXMESH_SYSTEMMEM, pDevice, NULL, &m_pBuffMat[PARTS_BODY], NULL, &m_nNumMat[PARTS_BODY], &m_pMesh[PARTS_BODY]);
	D3DXLoadMeshFromX(LPCSTR("./data/model/LBX/02_head.x"), D3DXMESH_SYSTEMMEM, pDevice, NULL, &m_pBuffMat[PARTS_HEAD], NULL, &m_nNumMat[PARTS_HEAD], &m_pMesh[PARTS_HEAD]);
	D3DXLoadMeshFromX(LPCSTR("./data/model/LBX/03_rightshoulder.x"), D3DXMESH_SYSTEMMEM, pDevice, NULL, &m_pBuffMat[PARTS_RSHOULDER], NULL, &m_nNumMat[PARTS_RSHOULDER], &m_pMesh[PARTS_RSHOULDER]);
	D3DXLoadMeshFromX(LPCSTR("./data/model/LBX/04_rightUpperArm.x"), D3DXMESH_SYSTEMMEM, pDevice, NULL, &m_pBuffMat[PARTS_RARM], NULL, &m_nNumMat[PARTS_RARM], &m_pMesh[PARTS_RARM]);
	D3DXLoadMeshFromX(LPCSTR("./data/model/LBX/05_rightarm.x"), D3DXMESH_SYSTEMMEM, pDevice, NULL, &m_pBuffMat[PARTS_RHAND], NULL, &m_nNumMat[PARTS_RHAND], &m_pMesh[PARTS_RHAND]);
	D3DXLoadMeshFromX(LPCSTR("./data/model/LBX/06_rightHand.x"), D3DXMESH_SYSTEMMEM, pDevice, NULL, &m_pBuffMat[PARTS_LSHOULDER], NULL, &m_nNumMat[PARTS_LSHOULDER], &m_pMesh[PARTS_LSHOULDER]);
	D3DXLoadMeshFromX(LPCSTR("./data/model/LBX/07_leftshoulder.x"), D3DXMESH_SYSTEMMEM, pDevice, NULL, &m_pBuffMat[PARTS_LARM], NULL, &m_nNumMat[PARTS_LARM], &m_pMesh[PARTS_LARM]);
	D3DXLoadMeshFromX(LPCSTR("./data/model/LBX/08_leftUpperArm.x"), D3DXMESH_SYSTEMMEM, pDevice, NULL, &m_pBuffMat[PARTS_LHAND], NULL, &m_nNumMat[PARTS_LHAND], &m_pMesh[PARTS_LHAND]);
	D3DXLoadMeshFromX(LPCSTR("./data/model/LBX/09_leftarm.x"), D3DXMESH_SYSTEMMEM, pDevice, NULL, &m_pBuffMat[PARTS_RTHIGH], NULL, &m_nNumMat[PARTS_RTHIGH], &m_pMesh[PARTS_RTHIGH]);
	D3DXLoadMeshFromX(LPCSTR("./data/model/LBX/10_rightThighs.x"), D3DXMESH_SYSTEMMEM, pDevice, NULL, &m_pBuffMat[PARTS_RLEG], NULL, &m_nNumMat[PARTS_RLEG], &m_pMesh[PARTS_RLEG]);
	D3DXLoadMeshFromX(LPCSTR("./data/model/LBX/11_rightshin.x"), D3DXMESH_SYSTEMMEM, pDevice, NULL, &m_pBuffMat[PARTS_RFOOT], NULL, &m_nNumMat[PARTS_RFOOT], &m_pMesh[PARTS_RFOOT]);
	D3DXLoadMeshFromX(LPCSTR("./data/model/LBX/12_rightshoe.x"), D3DXMESH_SYSTEMMEM, pDevice, NULL, &m_pBuffMat[PARTS_LTHIGH], NULL, &m_nNumMat[PARTS_LTHIGH], &m_pMesh[PARTS_LTHIGH]);
	D3DXLoadMeshFromX(LPCSTR("./data/model/LBX/13_leftThighs.x"), D3DXMESH_SYSTEMMEM, pDevice, NULL, &m_pBuffMat[PARTS_LLEG], NULL, &m_nNumMat[PARTS_LLEG], &m_pMesh[PARTS_LLEG]);
	D3DXLoadMeshFromX(LPCSTR("./data/model/LBX/14_leftshin.x"), D3DXMESH_SYSTEMMEM, pDevice, NULL, &m_pBuffMat[PARTS_LFOOT], NULL, &m_nNumMat[PARTS_LFOOT], &m_pMesh[PARTS_LFOOT]);
	D3DXLoadMeshFromX(LPCSTR("./data/model/LBX/15_leftshoe.x"), D3DXMESH_SYSTEMMEM, pDevice, NULL, &m_pBuffMat[PARTS_LSHOE], NULL, &m_nNumMat[PARTS_LSHOE], &m_pMesh[PARTS_LSHOE]);

	return S_OK;
}

//=============================================================================
// テクスチャ破棄関数
//=============================================================================
void CPlayer::Unload(void)
{
	if (m_pTexture != NULL)
	{
		m_pTexture->Release();
		m_pTexture = NULL;
	}
}
//=============================================================================
// 生成処理関数
//=============================================================================
CPlayer * CPlayer::Create(void)
{
	//プレイヤーのポインタ
	CPlayer * pPlayer = NULL;
	//プレイヤーのポインタがNULLの場合
	if (pPlayer == NULL)
	{
		//プレイヤーのメモリ確保
		pPlayer = new CPlayer;
		//プレイヤーのポインタがNULLではない場合
		if (pPlayer != NULL)
		{
			//プレイヤーの初期化処理関数呼び出し
			pPlayer->Init();
		}
	}
	//プレイヤーのポインタを返す
	return pPlayer;
}

//=============================================================================
// 初期化処理
//=============================================================================
HRESULT CPlayer::Init(void)
{
	// パーツ数を設定
	SetPartNum(PARTS_MAX);

	for (int nCount = 0; nCount < PARTS_MAX; nCount++)
	{
		BindMesh(CAnimation::TYPE_HUMAN, nCount, m_pMesh[nCount], m_pBuffMat[nCount], m_nNumMat[nCount]);
	}

	// 座標・親子関係の読み込み
	LoadModelData("./data/text/motion_LBX.txt");
	//データ読み込み関数呼び出し
	DataLoad();
	//キャラクターの初期化処理関数呼び出し
	CCharacter::Init();
	return S_OK;
}

//=============================================================================
// 終了処理
//=============================================================================
void CPlayer::Uninit()
{
	CCharacter::Uninit();
}

//=============================================================================
// 更新処理
//=============================================================================
void CPlayer::Update()
{
	CCharacter::Update();
}

//=============================================================================
// 描画処理
//=============================================================================
void CPlayer::Draw()
{
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

	CCharacter::Draw();
}

//=============================================================================
// 入力処理関数
//=============================================================================
void CPlayer::Input(void)
{
	//キーボードの取得
	CKeyboard * pKeyboard = CManager::GetKeyboard();
	//ジョイスティックの取得
	CJoystick * pJoystick = CManager::GetJoystick();
	LPDIRECTINPUTDEVICE8 lpDIDevice = CJoystick::GetDevice();
	DIJOYSTATE js;
	//ジョイスティックの振動取得
	LPDIRECTINPUTEFFECT pDIEffect = CJoystick::GetEffect();
	if (lpDIDevice != NULL)
	{
		lpDIDevice->Poll();
		lpDIDevice->GetDeviceState(sizeof(DIJOYSTATE), &js);
	}
	//ゲームモードの取得
	CGameMode * pGameMode = CManager::GetGameMode();
	//プレイヤーが移動していないとき
	m_Move = INITIAL_MOVE;
	//左移動処理
	if (pKeyboard->GetKeyboardPress(DIK_A) || lpDIDevice != NULL &&js.lX == -1000)
	{
		//入力キー情報を左にする
		m_Input = INPUT_LEFT;
		//移動処理関数呼び出し
		Move();
	}
	//右移動処理
	if (pKeyboard->GetKeyboardPress(DIK_D) || lpDIDevice != NULL &&js.lX == 1000)
	{
		//入力キー情報を右にする
		m_Input = INPUT_RIGHT;
		//移動処理関数呼び出し
		Move();
	}
	//ジャンプ処理関数
	if (pKeyboard->GetKeyboardTrigger(DIK_SPACE) || pJoystick->GetJoystickTrigger(JS_X))
	{
		//入力キー情報をスペースにする
		m_Input = INPUT_SPACE;
		//移動処理関数呼び出し
		Move();
	}
}

//=============================================================================
// 移動処理関数
//=============================================================================
void CPlayer::Move(void)
{
	//位置を取得する
	D3DXVECTOR3 Position = GetPos();
	//もし死亡状態じゃないとき
	if (m_State != STATE_DEATH)
	{
		switch (m_Input)
		{
			//もし入力情報が左の場合
		case INPUT_LEFT:
			m_Move.x = -m_fLeftRightSpeed;
			break;
			//もし入力情報が右の場合
		case INPUT_RIGHT:
			m_Move.x = m_fLeftRightSpeed;
			break;
			//もし入力情報がスペースの場合
		case INPUT_SPACE:
			break;
		default:
			break;
		}
	}
	//位置更新
	Position += m_Move;
	//位置を設定する
	SetPos(Position);
}

//=============================================================================
// ヒット処理関数
//=============================================================================
void CPlayer::Hit(void)
{
	//位置を取得する
	D3DXVECTOR3 Position = GetPos();
	//肉の所持数を減算する
	m_nMeat--;
	//肉を生成する
	CMeat::Create(Position);
	//ヒットさせる
	m_bHit = true;
}

//=============================================================================
// 死亡処理関数
//=============================================================================
void CPlayer::Death(void)
{
	//ダイアモンドの所持数を0にする
	m_nDiamond = MINIMUM_DIAMOND;
	//肉の所持数をマックスにする
	m_nMeat = m_nMaxMeat;
}

//=============================================================================
// データ読み込み関数
//=============================================================================
void CPlayer::DataLoad(void)
{
	D3DXVECTOR3 Position = INITIAL_POSITION;	//位置
	D3DXVECTOR3 CollisionSize = INITIAL_SIZE;	//衝突判定用サイズ
	D3DXVECTOR3 Rotation = INITIAL_ROTATION;	//回転
	char aReadText[MAX_TEXT];					//読み込んだテキスト
	char aCurrentText[MAX_TEXT];				//現在のテキスト
	char aUnnecessaryText[MAX_TEXT];			//不必要なテキスト
	memset(aReadText, NULL, sizeof(aReadText));
	memset(aCurrentText, NULL, sizeof(aCurrentText));
	memset(aUnnecessaryText, NULL, sizeof(aUnnecessaryText));
	//ファイルのポインタ
	FILE *pFile = NULL;
	//もしファイルのポインタがNULLの場合
	if (pFile == NULL)
	{
		//ファイルの読み込み
		pFile = fopen(SCRIPT_PASS, "r");
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
							//現在のテキストがPOSだったら
							if (strcmp(aCurrentText, "POS") == 0)
							{
								//位置情報の読み込み
								sscanf(aReadText, "%s %s %f %f %f", &aUnnecessaryText, &aUnnecessaryText, &Position.x, &Position.y, &Position.z);
								//位置を設定する
								SetPos(Position);
							}
							//現在のテキストがSIZEだったら
							if (strcmp(aCurrentText, "SIZE") == 0)
							{
								//サイズ情報の読み込み
								sscanf(aReadText, "%s %s %f %f %f", &aUnnecessaryText, &aUnnecessaryText, &m_Size.x, &m_Size.y, &m_Size.z);
							}
							//現在のテキストがCOLLISION_SIZEだったら
							if (strcmp(aCurrentText, "COLLISION_SIZE") == 0)
							{
								//衝突判定用のサイズの取得
								sscanf(aReadText, "%s %s %f %f %f", &aUnnecessaryText, &aUnnecessaryText, &CollisionSize.x, &CollisionSize.y, &CollisionSize.z);
							}
							//現在のテキストがROTだったら
							if (strcmp(aCurrentText, "ROT") == 0)
							{
								//回転情報の読み込み
								sscanf(aReadText, "%s %s %f %f %f", &aUnnecessaryText, &aUnnecessaryText, &Rotation.x, &Rotation.y, &Rotation.z);
								//回転を設定する
								SetRot(Rotation);
							}
							//現在のテキストがMeatだったら
							if (strcmp(aCurrentText, "Meat") == 0)
							{
								//サイズの設定
								sscanf(aReadText, "%s %s %d", &aUnnecessaryText, &aUnnecessaryText, &m_nMaxMeat);
								//肉の所持数を設定する
								m_nMeat = m_nMaxMeat;
							}
							//現在のテキストがStunTimeだったら
							if (strcmp(aCurrentText, "StunTime") == 0)
							{
								//サイズの設定
								sscanf(aReadText, "%s %s %d", &aUnnecessaryText, &aUnnecessaryText, &m_nStunTime);
							}
							//現在のテキストがAutoRunSpeedだったら
							if (strcmp(aCurrentText, "AutoRunSpeed") == 0)
							{
								//サイズの設定
								sscanf(aReadText, "%s %s %f", &aUnnecessaryText, &aUnnecessaryText, &m_fAutoRunSpeed);
								//移動量の設定
								m_Move.z = m_fAutoRunSpeed;
							}
							//現在のテキストがLeftRightSpeedだったら
							if (strcmp(aCurrentText, "LeftRightSpeed") == 0)
							{
								//サイズの設定
								sscanf(aReadText, "%s %s %f", &aUnnecessaryText, &aUnnecessaryText, &m_fLeftRightSpeed);
							}
							//現在のテキストがJumpPowerだったら
							if (strcmp(aCurrentText, "JumpPower") == 0)
							{
								//サイズの設定
								sscanf(aReadText, "%s %s %f", &aUnnecessaryText, &aUnnecessaryText, &m_fJumpPower);
							}
						}
					}
				}
			}
			//ファイルを閉じる
			fclose(pFile);
		}
	}
}//=============================================================================
// 入力処理関数
//=============================================================================
void CPlayer::Input(void)
{
	//キーボードの取得
	CKeyboard * pKeyboard = CManager::GetKeyboard();
	//ジョイスティックの取得
	CJoystick * pJoystick = CManager::GetJoystick();
	LPDIRECTINPUTDEVICE8 lpDIDevice = CJoystick::GetDevice();
	DIJOYSTATE js;
	//ジョイスティックの振動取得
	LPDIRECTINPUTEFFECT pDIEffect = CJoystick::GetEffect();
	if (lpDIDevice != NULL)
	{
		lpDIDevice->Poll();
		lpDIDevice->GetDeviceState(sizeof(DIJOYSTATE), &js);
	}
	//ゲームモードの取得
	CGameMode * pGameMode = CManager::GetGameMode();
	//プレイヤーが移動していないとき
	m_Move = INITIAL_MOVE;
	//左移動処理
	if (pKeyboard->GetKeyboardPress(DIK_A) || lpDIDevice != NULL &&js.lX == -1000)
	{
		//入力キー情報を左にする
		m_Input = INPUT_LEFT;
		//移動処理関数呼び出し
		Move();
	}
	//右移動処理
	if (pKeyboard->GetKeyboardPress(DIK_D) || lpDIDevice != NULL &&js.lX == 1000)
	{
		//入力キー情報を右にする
		m_Input = INPUT_RIGHT;
		//移動処理関数呼び出し
		Move();
	}
	//ジャンプ処理関数
	if (pKeyboard->GetKeyboardTrigger(DIK_SPACE) || pJoystick->GetJoystickTrigger(JS_X))
	{
		//入力キー情報をスペースにする
		m_Input = INPUT_SPACE;
		//移動処理関数呼び出し
		Move();
	}
}

//=============================================================================
// 移動処理関数
//=============================================================================
void CPlayer::Move(void)
{
	//位置を取得する
	D3DXVECTOR3 Position = GetPos();
	//もし死亡状態じゃないとき
	if (m_State != STATE_DEATH)
	{
		switch (m_Input)
		{
			//もし入力情報が左の場合
		case INPUT_LEFT:
			m_Move.x = -m_fLeftRightSpeed;
			break;
			//もし入力情報が右の場合
		case INPUT_RIGHT:
			m_Move.x = m_fLeftRightSpeed;
			break;
			//もし入力情報がスペースの場合
		case INPUT_SPACE:
			break;
		default:
			break;
		}
	}
	//位置更新
	Position += m_Move;
	//位置を設定する
	SetPos(Position);
}

//=============================================================================
// ヒット処理関数
//=============================================================================
void CPlayer::Hit(void)
{
	//位置を取得する
	D3DXVECTOR3 Position = GetPos();
	//肉の所持数を減算する
	m_nMeat--;
	//肉を生成する
	CMeat::Create(Position);
	//ヒットさせる
	m_bHit = true;
}

//=============================================================================
// 死亡処理関数
//=============================================================================
void CPlayer::Death(void)
{
	//ダイアモンドの所持数を0にする
	m_nDiamond = MINIMUM_DIAMOND;
	//肉の所持数をマックスにする
	m_nMeat = m_nMaxMeat;
}

//=============================================================================
// データ読み込み関数
//=============================================================================
void CPlayer::DataLoad(void)
{
	D3DXVECTOR3 Position = INITIAL_POSITION;	//位置
	D3DXVECTOR3 CollisionSize = INITIAL_SIZE;	//衝突判定用サイズ
	D3DXVECTOR3 Rotation = INITIAL_ROTATION;	//回転
	char aReadText[MAX_TEXT];					//読み込んだテキスト
	char aCurrentText[MAX_TEXT];				//現在のテキスト
	char aUnnecessaryText[MAX_TEXT];			//不必要なテキスト
	memset(aReadText, NULL, sizeof(aReadText));
	memset(aCurrentText, NULL, sizeof(aCurrentText));
	memset(aUnnecessaryText, NULL, sizeof(aUnnecessaryText));
	//ファイルのポインタ
	FILE *pFile = NULL;
	//もしファイルのポインタがNULLの場合
	if (pFile == NULL)
	{
		//ファイルの読み込み
		pFile = fopen(SCRIPT_PASS, "r");
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
							//現在のテキストがPOSだったら
							if (strcmp(aCurrentText, "POS") == 0)
							{
								//位置情報の読み込み
								sscanf(aReadText, "%s %s %f %f %f", &aUnnecessaryText, &aUnnecessaryText, &Position.x, &Position.y, &Position.z);
								//位置を設定する
								SetPos(Position);
							}
							//現在のテキストがSIZEだったら
							if (strcmp(aCurrentText, "SIZE") == 0)
							{
								//サイズ情報の読み込み
								sscanf(aReadText, "%s %s %f %f %f", &aUnnecessaryText, &aUnnecessaryText, &m_Size.x, &m_Size.y, &m_Size.z);
							}
							//現在のテキストがCOLLISION_SIZEだったら
							if (strcmp(aCurrentText, "COLLISION_SIZE") == 0)
							{
								//衝突判定用のサイズの取得
								sscanf(aReadText, "%s %s %f %f %f", &aUnnecessaryText, &aUnnecessaryText, &CollisionSize.x, &CollisionSize.y, &CollisionSize.z);
							}
							//現在のテキストがROTだったら
							if (strcmp(aCurrentText, "ROT") == 0)
							{
								//回転情報の読み込み
								sscanf(aReadText, "%s %s %f %f %f", &aUnnecessaryText, &aUnnecessaryText, &Rotation.x, &Rotation.y, &Rotation.z);
								//回転を設定する
								SetRot(Rotation);
							}
							//現在のテキストがMeatだったら
							if (strcmp(aCurrentText, "Meat") == 0)
							{
								//サイズの設定
								sscanf(aReadText, "%s %s %d", &aUnnecessaryText, &aUnnecessaryText, &m_nMaxMeat);
								//肉の所持数を設定する
								m_nMeat = m_nMaxMeat;
							}
							//現在のテキストがStunTimeだったら
							if (strcmp(aCurrentText, "StunTime") == 0)
							{
								//サイズの設定
								sscanf(aReadText, "%s %s %d", &aUnnecessaryText, &aUnnecessaryText, &m_nStunTime);
							}
							//現在のテキストがAutoRunSpeedだったら
							if (strcmp(aCurrentText, "AutoRunSpeed") == 0)
							{
								//サイズの設定
								sscanf(aReadText, "%s %s %f", &aUnnecessaryText, &aUnnecessaryText, &m_fAutoRunSpeed);
								//移動量の設定
								m_Move.z = m_fAutoRunSpeed;
							}
							//現在のテキストがLeftRightSpeedだったら
							if (strcmp(aCurrentText, "LeftRightSpeed") == 0)
							{
								//サイズの設定
								sscanf(aReadText, "%s %s %f", &aUnnecessaryText, &aUnnecessaryText, &m_fLeftRightSpeed);
							}
							//現在のテキストがJumpPowerだったら
							if (strcmp(aCurrentText, "JumpPower") == 0)
							{
								//サイズの設定
								sscanf(aReadText, "%s %s %f", &aUnnecessaryText, &aUnnecessaryText, &m_fJumpPower);
							}
						}
					}
				}
			}
			//ファイルを閉じる
			fclose(pFile);
		}
	}
}