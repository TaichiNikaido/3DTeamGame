//================================================
//
// ui���� [ui.cpp]
// Author : �����D�I
//
//================================================

//================================================
// �C���N���[�h
//================================================
#include "ui.h"
#include "manager.h"
#include "renderer.h"
#include "mode_game.h"

//================================================
// �ÓI�����o�ϐ��錾
//================================================
LPDIRECT3DTEXTURE9 CUi::m_apTexture[UI_TYPE] = {};

//================================================
// �N���G�C�g����
//================================================
CUi* CUi::Create(D3DXVECTOR3 pos, D3DXVECTOR3 size, UITYPE type)
{
	CUi* pUi = NULL;

	// ���I�m��
	pUi = new CUi;

	// ����������
	pUi->Init(pos, size, type);

	return pUi;
}

//================================================
// ���[�h����
//================================================
HRESULT CUi::Load(void)
{
	LPDIRECT3DDEVICE9 pDevice;
	// �f�o�C�X���̎擾
	pDevice = CManager::GetRenderer()->GetDevice();

	// �e�N�X�`���̓ǂݍ���

	// �_�C��
	D3DXCreateTextureFromFile(pDevice,
		"data/Texture/Daiya.png", //�t�@�C���̓ǂݍ���
		&m_apTexture[UITYPE_DAIYA]);

	// ��
	D3DXCreateTextureFromFile(pDevice,
		"data/Texture/Meat.png", //�t�@�C���̓ǂݍ���
		&m_apTexture[UITYPE_MEAT]);

	// �x��
	D3DXCreateTextureFromFile(pDevice,
		"data/Texture/WinMark.png", //�t�@�C���̓ǂݍ���
		&m_apTexture[UITYPE_WARNING]);

	return S_OK;
}

//================================================
// ���[�h�̏I��
//================================================
void CUi::Unload(void)
{
	for (int nCount = 0; nCount < UI_TYPE; nCount++)
	{
		//�e�N�X�`���̊J��
		if (m_apTexture[nCount] != NULL)
		{
			m_apTexture[nCount]->Release();
			m_apTexture[nCount] = NULL;
		}
	}
}

//================================================
//�R���X�g���N�^
//================================================
CUi::CUi(int nPriority) :CScene2d(nPriority)
{
	m_pos = (D3DXVECTOR3(0.0f, 0.0f, 0.0f));		// ���W
	m_move = (D3DXVECTOR3(0.0f, 0.0f, 0.0f));		// �ړ���
	m_size = (D3DXVECTOR3(0.0f, 0.0f, 0.0f));		// �T�C�Y
	m_col = (D3DXCOLOR(0.0f, 0.0f, 0.0f, 0.0f));	// �J���[
	m_type = UITYPE_NONE;							// �^�C�v
	m_nColCounter = 0;									// �J�E���^�[
	m_nEraseCounter = 0;									// �g�p���Ă��邩�ǂ���
}

//================================================
//�f�X�g���N�^
//================================================
CUi::~CUi()
{

}

//================================================
//����������
//================================================
HRESULT CUi::Init(D3DXVECTOR3 pos, D3DXVECTOR3 size, UITYPE type)
{
	m_pos = pos;	// �ʒu���
	m_size = size;	// �T�C�Y
	m_type = type;	// �^�C�v

	//������
	CScene2d::Init();

	// �ʒu���
	CScene2d::SetPosition(D3DXVECTOR3(m_pos.x, m_pos.y, m_pos.z));

	// �T�C�Y
	CScene2d::SetSize(D3DXVECTOR3(m_size.x, m_size.y, m_size.z));

	// �J���[
	CScene2d::SetColor(D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));

	// �e�N�X�`���[
	D3DXVECTOR2 texture[4];
	texture[0] = D3DXVECTOR2(0.0f, 0.0f);
	texture[1] = D3DXVECTOR2(1.0f, 0.0f);
	texture[2] = D3DXVECTOR2(0.0f, 1.0f);
	texture[3] = D3DXVECTOR2(1.0f, 1.0f);

	// �e�N�X�`���[�̐ݒ�
	CScene2d::SetTexture(texture);

	// �e�N�X�`���[�̊m��
	CScene2d::BindTexture(m_apTexture[type]);

	return S_OK;
}

//================================================
// �I������
//================================================
void CUi::Uninit(void)
{
	// �I������
	CScene2d::Uninit();
}

//================================================
// �X�V����
//================================================
void CUi::Update(void)
{
	// �X�V����
	CScene2d::Update();

	// WARNING��_�ł����鏈��
	Flashing();
}

//================================================
// �`�揈��
//================================================
void CUi::Draw(void)
{
	// �`�揈��
	CScene2d::Draw();
}

//================================================
// �_�ł����鏈��
//================================================
void CUi::Flashing(void)
{
	D3DXCOLOR col = GetColor();

	if (m_type == UITYPE_WARNING)
	{
		// ���t���[�����ƂɃJ�E���^�[�𑝂₷
		m_nColCounter++;
		// ���t���[�����ƂɃJ�E���^�[�𑝂₷
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

		// �J�E���^�[�����l�ɒB�����
		if (m_nEraseCounter == WARNING_ERASE)
		{
			// �J�E���^�[���O�ɂ���
			m_nEraseCounter = 0;
			// �I������
			Uninit();
			return;
		}
	}

	// �F�̐ݒ�
	SetColor(col);
}