//******************************************************************************
// �p�[�e�B�N�� [ particle.h]
// Author : �ǌ� �i
//******************************************************************************
#ifndef _PARTICLE_H_
#define _PARTICLE_H_
//******************************************************************************
// �C���N���[�h�t�@�C��
//******************************************************************************
#include "billboard.h"
//******************************************************************************
// �N���X
//******************************************************************************
class CParticle : public CBillboard
{
public:
	// �e�N�X�`���^�C�v
	typedef enum
	{
		TEX_TYPE_NONE = -1,
		TEX_TYPE_1,
		TEX_TYPE_2,
		TEX_TYPE_MAX,
	}TEX_TYPE;

	CParticle();
	~CParticle();
	static HRESULT Load(void);
	static void Unload(void);
	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);
	void SetParticle(D3DXVECTOR3 pos, D3DXVECTOR3 size, D3DXVECTOR3 rot, D3DXCOLOR col, TEX_TYPE TexType);
private:
	static LPDIRECT3DTEXTURE9 m_apTexture[TEX_TYPE_MAX];	// texture
	TEX_TYPE m_TexType;								// �e�N�X�`���^�C�v
};
#endif