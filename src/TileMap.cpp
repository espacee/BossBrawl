#include "TileMap.hpp"

TileMap::TileMap()
{
    Resize(1,1);
    Fill(0);
    LoadTiles();
    x_coord = y_coord = 0;
}

void TileMap::LoadTiles()
{
    sprites.push_back(sf::Sprite());

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


void TileMap::Resize(unsigned int new_hLength, unsigned int new_vLength)
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

void TileMap::SetTile(unsigned int x, unsigned int y, unsigned int id)
{
    if(TileExists(x,y) && SpriteExists(id))
    {
        map[x][y] = id;
    }
}

unsigned int TileMap::GetTile(unsigned int x, unsigned int y) const
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

void TileMap::Move(int x_offset, int y_offset)
{
    x_coord+=x_offset;
    y_coord+=y_offset;
}

void TileMap::SetPosition(int new_x_coord, int new_y_coord)
{
    x_coord = new_x_coord;
    y_coord = new_y_coord;
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

                sprites[id].setPosition(x_coord + (int)i*GRID_SIZE,y_coord + (int)j*GRID_SIZE);
                w.draw(sprites[id]);

            }
        }
    }
}

bool TileMap::TileExists(unsigned int x, unsigned int y) const
{
    return x < hLength && y < vLength;
}

bool TileMap::SpriteExists(unsigned int id) const
{
    return id < sprites.size();
}
