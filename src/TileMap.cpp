#include "TileMap.hpp"

TileMap::TileMap()
{
    Resize(1,1);
    Fill(0);
    LoadTiles();
}

void TileMap::LoadTiles()
{
    if(tileSet.loadFromFile("res/img/tileset.png"))
    {
        int ts_width = tileSet.getSize().x;
        int ts_height = tileSet.getSize().y;

        for(int j=0; j<ts_height; j+=GRID_SIZE)
        {
            for(int i=0; i<ts_width; i+=GRID_SIZE)
            {
                sprites.push_back(sf::Sprite(tileSet, sf::IntRect(i, j, GRID_SIZE, GRID_SIZE)));
            }
        }
    }
}


void TileMap::Resize(unsigned int new_hLength, uint new_vLength)
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

void TileMap::SetTile(unsigned int x, uint y, uint id)
{
    if(TileExists(x,y) && SpriteExists(id))
    {
        map[x][y] = id;
    }
}

unsigned int TileMap::GetTile(uint x, uint y) const
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

void TileMap::Fill(unsigned int id)
{
    if (id == 0)
    {
        return;
    }

    if(SpriteExists(id))
    {
        for(unsigned int i=0; i<hLength; i++)
        {
            for(unsigned int j=0; j<vLength; j++)
            {
                map[i][j]=id;
            }
        }
    }
}

unsigned int TileMap::GetHLength() const
{
    return hLength;
}

unsigned int TileMap::GetVLength() const
{
    return vLength;
}

unsigned int TileMap::GetWidth() const
{
    return width;
}

unsigned int TileMap::GetHeight() const
{
    return height;
}

void TileMap::Draw(sf::RenderWindow &w)
{
    for(unsigned int i=0; i<hLength; i++)
    {
        for(unsigned int j=0; j<vLength; j++)
        {
            const int id = map[i][j];

            if (id)
            {
                sprites[id].setPosition(i*GRID_SIZE,j*GRID_SIZE);
                w.draw(sprites[id]);
            }
        }
    }
}

bool TileMap::TileExists(unsigned int x, uint y) const
{
    return x < hLength && y < vLength;
}

bool TileMap::SpriteExists(unsigned int id) const
{
    return id < sprites.size();
}
