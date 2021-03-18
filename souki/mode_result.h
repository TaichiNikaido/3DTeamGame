//=============================================================================
//
// ���U���g���[�h [mode_result.h]
// Author : ��K������
//
//=============================================================================
#ifndef _MODE_RESULT_H_
#define _MODE_RESULT_H_

//*****************************************************************************
// �w�b�_�t�@�C���̃C���N���[�h
//*****************************************************************************
#include "scene.h"

//*****************************************************************************
// �}�N����`
//*****************************************************************************

//*****************************************************************************
// �O���錾
//*****************************************************************************
class CResultlogo;
class CTitlelogo;
class CScore;
//*****************************************************************************
// �N���X��`
//*****************************************************************************
class CResultMode : CScene
{
public:
	CResultMode();
	~CResultMode();
	static CResultMode * Create();
	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	static CResultMode *GetLogo(int nCount) { return m_pResultlogo; }
	static CTitlelogo *GetLogo(void) { return m_pTitlelogo; }
	static CScore *GetScore(void) { return m_pScore; }

private:
	void InitCreateAll(void);

	static CResultMode *m_pResultlogo;			// �^�C�g�����S�̃|�C���^
	static CTitlelogo *m_pTitlelogo;			// �^�C�g�����S�̃|�C���^
	static CScore *m_pScore;					// �X�R�A�̃|�C���^
};
#endif
