//******************************************************************************
// チュートリアルポリゴン [tutorial_polygon.h]
// Author : 管原　司
//******************************************************************************
#ifndef _TUTORIAL_POLYGON_H_
#define _TUTORIAL_POLYGON_H_
//******************************************************************************
// インクルードファイル
//******************************************************************************
#include "polygon.h"
//******************************************************************************
// クラス
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