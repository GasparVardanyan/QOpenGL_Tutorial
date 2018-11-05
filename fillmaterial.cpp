#include "fillmaterial.h"

FillMaterial::FillMaterial (unsigned char r, unsigned char g, unsigned char b)
{
    QImage img (1, 1, QImage::Format_Indexed8);
    QVector <QRgb> color_table;
    for (int i = 0; i < 256; i++)
        color_table.push_back (qRgb (i, i, i));
    img.setColorTable (color_table);
    img.setColorCount (1);
    img.setColor (0, qRgb (r, g, b));
    img.fill (0);
    init (img);
}
