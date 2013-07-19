#include "Layer.hpp"

Layer::Layer()
{
    layerID = 9999;
    Resize(1,1);
    Fill(0);
    x_coord = y_coord = 0;
}

Layer::Layer(unsigned int new_layerID)
{
    layerID = new_layerID;
    Resize(1,1);
    Fill(0);
    x_coord = y_coord = 0;
}

void Layer::Resize(unsigned int new_hLength, unsigned int new_vLength)
{
    if(new_hLength>=1 && new_vLength>=1)
    {

        hLength = new_hLength;
        vLength = new_vLength;

        map.resize(new_hLength);

        for(unsigned int i=0; i<new_hLength; i++)
        {
            map[i].resize(new_vLength, 0);
        }

        width = hLength*GRID_SIZE;
        height = vLength*GRID_SIZE;

    }
}

void Layer::SetTile(unsigned int x, unsigned int y, unsigned int id)
{
        map[x][y] = id;
}

unsigned int Layer::GetTile(unsigned int x, unsigned int y) const
{
    if(TileExists(x,y))
    {
        return map[x][y];
    }
    else
    {
        return map[0][0];
    }
}

void Layer::Fill(unsigned int id)
{
    for(unsigned int i=0; i<hLength; i++)
    {
        for(unsigned int j=0; j<vLength; j++)
        {
            map[i][j]=id;
        }
    }
}

void Layer::Move(int x_offset, int y_offset)
{
    x_coord+=x_offset;
    y_coord+=y_offset;
}

void Layer::SetPosition(int new_x_coord, int new_y_coord)
{
    x_coord = new_x_coord;
    y_coord = new_y_coord;
}

unsigned int Layer::GetHLength() const
{
    return hLength;
}

unsigned int Layer::GetVLength() const
{
    return vLength;
}

unsigned int Layer::GetWidth() const
{
    return width;
}

unsigned int Layer::GetHeight() const
{
    return height;
}

bool Layer::TileExists(unsigned int x, unsigned int y) const
{
    return x < hLength && y < vLength;
}
