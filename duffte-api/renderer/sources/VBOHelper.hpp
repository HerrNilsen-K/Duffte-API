#ifndef __VBOHELPER_H__
#define __VBOHELPER_H__

namespace duffte
{
    struct vertPos
    {
        float x, y, z;
    };
    struct texPos
    {
        float x, y;
    };

    struct vboCoords
    {
        vertPos m_vertPos;
        texPos m_texPos;
    };

} // namespace duffte

#endif // __VBOHELPER_H__