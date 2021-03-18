//******************************************************************************
// �`���[�g���A���|���S�� [tutrial_polygon.cpp]
// Author : �ǌ��@�i
//******************************************************************************
//******************************************************************************
// �C���N���[�h�t�@�C��
//******************************************************************************
#include "sound.h"
#include "main.h"
#include "manager.h"
#include "renderer.h"
#include "scene.h"
#include "scene2d.h"
#include "polygon.h"
#include "tutorial_polygon.h"
//******************************************************************************
// �}�N����`
//******************************************************************************
#define SIZE	(D3DXVECTOR3(SCREEN_WIDTH / 2,SCREEN_HEIGHT / 2,0.0f))
#define COL		(D3DXCOLOR(1.0f,1.0f,1.0f,1.0f))
//******************************************************************************
// �R���X�g���N�^
//******************************************************************************
CTutorial_Polygon::CTutorial_Polygon(int nPriority) : CPolygon(nPriority)
{
}
//******************************************************************************
// �f�X�g���N�^
//******************************************************************************
CTutorial_Polygon::~CTutorial_Polygon()
{
}
//******************************************************************************
// �����֐�
//******************************************************************************
CTutorial_Polygon * CTutorial_Polygon::Create(D3DXVECTOR3 pos)
{
	//�@CTitle_Polygon�N���X�̃|�C���^
	CTutorial_Polygon *pTutorial_Polygonn;

	// �������m��
	pTutorial_Polygonn = new CTutorial_Polygon;

	// ���ݒ�
	pTutorial_Polygonn->SetPolygon(pos, SIZE, COL, CPolygon::TEX_TYPE_RESULT);

	// ������
	pTutorial_Polygonn->Init();

	// �|�C���^��Ԃ�
	return pTutorial_Polygonn;

}
//******************************************************************************
// �������֐�
//******************************************************************************
HRESULT CTutorial_Polygon::Init()
{
	//�@������
	CPolygon::Init();

	return S_OK;
}
//******************************************************************************
// �I���֐�
//******************************************************************************
void CTutorial_Polygon::Uninit(void)
{
	//�@�I��
	CPolygon::Uninit();
}
//******************************************************************************
// �X�V�֐�
//******************************************************************************
void CTutorial_Polygon::Update(void)
{
	//�@�X�V
	CPolygon::Update();
}
//******************************************************************************
// �`��֐�
//******************************************************************************
void CTutorial_Polygon::Draw(void)
{
	//�@�`��
	CPolygon::Draw();
}