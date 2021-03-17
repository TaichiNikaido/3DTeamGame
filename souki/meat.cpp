//================================================
//
// ui_number���� [ui_number.h]
// Author : �����D�I
//
//================================================

//================================================
// �C���N���[�h�t�@�C��
//================================================
#include "meat.h"
#include "number.h"
#include "manager.h"


#include "Keyboard.h"
//================================================
// �ÓI�����o�ϐ��錾
//================================================
int CMeat::m_nMeat = NULL;

//================================================
// �N���G�C�g����
//================================================
CMeat *CMeat::Create()
{
	CMeat *pMeat;
	pMeat = new CMeat;
	pMeat->Init();

	return pMeat;
}

//====================================================
// �R���X�g���N�^
//====================================================
CMeat::CMeat(int nPriority) : CScene(nPriority)
{

}

//====================================================
// �f�X�g���N�^
//====================================================
CMeat::~CMeat()
{

}

//================================================
// ����������
//================================================
HRESULT CMeat::Init()
{
	m_nMeat = MEAT_POSSESSION;		// ���̏����l

	for (int nCount = 0; nCount < MEATE_MAX_DIGITS; nCount++)
	{
		// �����̐���
		m_apNumber[nCount] = CNumber::Create(D3DXVECTOR3(MEAT_NUMBER_POS_X + nCount*MEAT_NUMBER_SIZE, MEAT_NUMBER_POS_Y, 0.0f),
			D3DXVECTOR3(MEAT_NUMBER_SIZE, MEAT_NUMBER_SIZE, 0.0f),
			CNumber::NUMBERTYPE_MEAT);
	}

	// ���Z
	AddMeat(0);

	return S_OK;
}

//================================================
// �I������
//================================================
void CMeat::Uninit(void)
{
	for (int nCount = 0; nCount < MEATE_MAX_DIGITS; nCount++)
	{
		//�i���o�[�����̏I���ƊJ��
		if (m_apNumber[nCount] != NULL)
		{
			// �I������
			m_apNumber[nCount]->Uninit();
			m_apNumber[nCount] = NULL;
		}
	}

	// �J��
	Release();
}

//================================================
// �X�V����
//================================================
void CMeat::Update(void)
{
	for (int nCount = 0; nCount < MEATE_MAX_DIGITS; nCount++)
	{
		// �X�V����
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
// �`�揈��
//================================================
void CMeat::Draw(void)
{
	for (int nCount = 0; nCount < MEATE_MAX_DIGITS; nCount++)
	{
		// �`�揈��
		m_apNumber[nCount]->Draw();
	}
}

//================================================
// ���̉��Z
//================================================
void CMeat::AddMeat(int nValue)
{
	// �Ăяo���ꂽ����Z����
	m_nMeat += nValue;

	for (int nCount = 0; nCount < MEATE_MAX_DIGITS; nCount++)
	{
		// �\�����Ă鐔���ɉ��Z������
		m_apNumber[nCount]->SetNumber(m_nMeat % (int)powf(10, MEATE_MAX_DIGITS - nCount) / powf(10, MEATE_MAX_DIGITS - nCount - 1));
	}
}

