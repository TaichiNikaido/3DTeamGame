//******************************************************************************
// �`���[�g���A���|���S�� [tutorial_polygon.h]
// Author : �ǌ��@�i
//******************************************************************************
#ifndef _TUTORIAL_POLYGON_H_
#define _TUTORIAL_POLYGON_H_
//******************************************************************************
// �C���N���[�h�t�@�C��
//******************************************************************************
#include "polygon.h"
//******************************************************************************
// �N���X
//******************************************************************************
class CTutorial_Polygon : public CPolygon
{
public:
	CTutorial_Polygon(int nPriority = 0);
	~CTutorial_Polygon();
	static CTutorial_Polygon *Create(D3DXVECTOR3 pos);
	HRESULT Init();
	void Uninit(void);
	void Update(void);
	void Draw(void);
private:

};
#endif