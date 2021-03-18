//******************************************************************************
// �|���S�� [polygon.h]
// Author : �ǌ��@�i
//******************************************************************************
#ifndef _POLYGON_H_
#define _POLYGON_H_
//******************************************************************************
// �C���N���[�h�t�@�C��
//******************************************************************************
#include "scene2d.h"
//******************************************************************************
// �N���X
//******************************************************************************
class CPolygon : public CScene2d
{
public:
	// �e�N�X�`�����
	typedef enum
	{
		TEX_TYPE_NONE = -1,
		TEX_TYPE_TITLE,			// �^�C�g���p�摜
		TEX_TYPE_TUTRIAL,		// �`���[�g���A���摜
		TEX_TYPE_RESULT,		// ���U���g�摜
		TEX_TYPE_MAX
	}TEX_TYPE;

	CPolygon(int nPriority = 0);
	~CPolygon();
	static HRESULT Load(void);
	static void Unload(void);
	HRESULT Init();
	void Uninit(void);
	void Update(void);
	void Draw(void);
	void SetPolygon(D3DXVECTOR3 pos, D3DXVECTOR3 size, D3DXCOLOR col, TEX_TYPE textype);
private:
	static LPDIRECT3DTEXTURE9 m_apTexture[TEX_TYPE_MAX];		// �e�N�X�`��
	TEX_TYPE m_TexType;											// �e�N�X�`���̎��
};
#endif