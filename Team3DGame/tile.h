//====================================================================
//
// �^�C������ (tile.h)
// Author : ��{��
//
//====================================================================
#ifndef _TILE_H_
#define _TILE_H_

//================================================
// �C���N���[�h�t�@�C��
//================================================
#include "main.h"

//*****************************************************************************
// �}�N����`
//*****************************************************************************
#define TILE_SIZE 200.0f

//================================================
// �N���X�錾
//================================================

// 3D�|���S���N���X
class CTile
{
public:
    CTile();
    ~CTile();

    // �񋓌^�錾 �^�C���̎��
    typedef enum
    {
		TILE_DIRT = 0,
        TILE_GRASS,
		TILE_TREE_DIRT,
		TILE_TREE_GRASS,
		TILE_WODD_DIRT,
		TILE_WOOD_GRASS,
		TILE_MUD,
		TILE_DIA_DIRT,
		TILE_HOLE,
        TILE_MAX
    }TYPE;

    HRESULT Init(TYPE type);
    void Uninit(void);
    void Update(void);
    void Draw(void);
    void SetPos(const D3DXVECTOR3 pos) { m_pos = pos; }		// ���W�ݒ�p
    void SetCol(const D3DXCOLOR col) { m_col = col; };
    void SetRot(const D3DXVECTOR3 rot) { m_rot = rot; }
    void SetScale(const D3DXVECTOR3 scale) { m_scale = scale; }

    void SetTexUV(const float leftX, const float rightX, const float topY, const float bottomY);
    D3DXVECTOR3 GetPosition(void) const { return m_pos; }
    void GetTexUV(float* leftX, float* rightX, float* topY, float* bottomY);

    static HRESULT Load(void);
    static void Unload(void);
private:
    static LPDIRECT3DTEXTURE9		m_apTexture[TILE_MAX];
    D3DXMATRIX						m_mtxWorld;		// ���[���h�}�g���b�N�X
    LPDIRECT3DVERTEXBUFFER9			m_pVtxBuff;
    D3DXVECTOR3						m_pos;			// ���W
    D3DXVECTOR3						m_rot;			// ��]
    D3DXVECTOR3						m_scale;
    D3DXCOLOR						m_col;

    float							m_TexLeftX;
    float							m_TexRightX;
    float							m_TexTopY;
    float							m_TexBottomY;

    TYPE							m_type;
};

#endif