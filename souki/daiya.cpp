//================================================
//
// ui_number���� [ui_number.h]
// Author : �����D�I
//
//================================================

//================================================
// �C���N���[�h�t�@�C��
//================================================
#include "daiya.h"
#include "number.h"
#include "manager.h"

#include "Keyboard.h"
//================================================
// �ÓI�����o�ϐ��錾
//================================================
int CDaiya::m_nDaiya = NULL;

//================================================
// �N���G�C�g����
//================================================
CDaiya *CDaiya::Create()
{
	CDaiya *pDaiya;
	pDaiya = new CDaiya;
	pDaiya->Init();

	return pDaiya;
}

//====================================================
// �R���X�g���N�^
//====================================================
CDaiya::CDaiya(int nPriority) : CScene(nPriority)
{

}

//====================================================
// �f�X�g���N�^
//====================================================
CDaiya::~CDaiya()
{

}

//================================================
// ����������
//================================================
HRESULT CDaiya::Init()
{
	m_nDaiya = 0;		// �_�C���̏����l

	for (int nCount = 0; nCount < DAIYA_MAX_DIGITS; nCount++)
	{
		// �����̐���
		m_apNumber[nCount] = CNumber::Create(D3DXVECTOR3(DAIYA_NUMBER_POS_X + nCount*DAIYA_NUMBER_SIZE, DAIYA_NUMBER_POS_Y, 0.0f),
			D3DXVECTOR3(DAIYA_NUMBER_SIZE, DAIYA_NUMBER_SIZE, 0.0f),
			CNumber::NUMBERTYPE_DAIYA);
	}

	// ���Z
	AddDaiya(0);

	return S_OK;
}

//================================================
// �I������
//================================================
void CDaiya::Uninit(void)
{
	for (int nCount = 0; nCount < DAIYA_MAX_DIGITS; nCount++)
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
void CDaiya::Update(void)
{
	for (int nCount = 0; nCount < DAIYA_MAX_DIGITS; nCount++)
	{
		// �X�V����
		m_apNumber[nCount]->Update();
	}

	CKeyboard *pKeyboard = CManager::GetKeyboard();

	if (pKeyboard->GetKeyboardTrigger(DIK_A) == TRUE)
	{
		AddDaiya(1);
	}
}

//================================================
// �`�揈��
//================================================
void CDaiya::Draw(void)
{
	for (int nCount = 0; nCount < DAIYA_MAX_DIGITS; nCount++)
	{
		// �`�揈��
		m_apNumber[nCount]->Draw();
	}

}

//================================================
// �_�C���̉��Z
//================================================
void CDaiya::AddDaiya(int nValue)
{
	// �Ăяo���ꂽ����Z����
	m_nDaiya += nValue;

	for (int nCount = 0; nCount < DAIYA_MAX_DIGITS; nCount++)
	{
		// �\�����Ă鐔���ɉ��Z������
		m_apNumber[nCount]->SetNumber(m_nDaiya % (int)powf(10, DAIYA_MAX_DIGITS - nCount) / powf(10, DAIYA_MAX_DIGITS - nCount - 1));
	}
}