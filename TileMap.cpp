#include "TileMap.hpp"

TileMap::TileMap()
{
    Resize(1,1);
    Fill(0);

    LoadTiles();
}

void TileMap::LoadTiles()
{

    sf::Texture* air = new sf::Texture();
    air->create(GRID_SIZE,GRID_SIZE);
    textures.push_back(air);
    sprites.push_back(sf::Sprite(*textures.back()));

    sf::Texture tileSet;
    if(tileSet.loadFromFile("res/img/tileset.png"))
    {
        int ts_width = tileSet.getSize().x;
        int ts_height = tileSet.getSize().y;

        for(int j=0; j<ts_height; j+=GRID_SIZE)
        {
            for(int i=0; i<ts_width; i+=GRID_SIZE)
            {
                sf::Texture* temp = new sf::Texture();
                temp->loadFromFile("res/img/tileset.png", sf::IntRect(i,j, GRID_SIZE, GRID_SIZE));

                textures.push_back(temp);
                sprites.push_back(sf::Sprite(*textures.back()));

            }
        }
    }
}


void TileMap::Resize(uint new_hLength, uint new_vLength)
{
    if(new_hLength>=1 && new_vLength>=1)
    {

        hLength = new_hLength;
        vLength = new_vLength;

        map.resize(new_hLength);

        for(uint i=0; i<new_hLength; i++)
        {
            map[i].resize(new_vLength, 0);
        }

        width = hLength*GRID_SIZE;
        height = vLength*GRID_SIZE;

    }
}

void TileMap::SetTile(uint x, uint y, uint id)
{
    if(TileExist(x,y) && SpriteExist(id))
    {
        map[x][y] = id;
    }
}

uint TileMap::GetTile(uint x, uint y)
{
    if(TileExist(x,y))
    {
        return map[x][y];
    }
    else
    {
        return map[0][0];
    }
}

void TileMap::Fill(uint id)
{
    if(SpriteExist(id))
    {
        for(uint i=0; i<hLength; i++)
        {
            for(uint j=0; j<vLength; j++)
            {
                map[i][j]=id;
            }
        }
    }
}

uint TileMap::GetHLength()
{
    return hLength;
}

uint TileMap::GetVLength()
{
    return vLength;
}

uint TileMap::GetWidth()
{
    return width;
}

uint TileMap::GetHeight()
{
    return height;
}

void TileMap::Draw(sf::RenderWindow &w)
{
    for(uint i=0; i<hLength; i++)
    {
        for(uint j=0; j<vLength; j++)
        {
            sprites[map[i][j]].setPosition(i*GRID_SIZE,j*GRID_SIZE);
            w.draw(sprites[map[i][j]]);
        }
    }
}

bool TileMap::TileExist(uint x, uint y)
{
    if(x<hLength && y<vLength)
        return true;
    else
        return false;
}

bool TileMap::SpriteExist(uint id)
{
    if(id<sprites.size())
        return true;
    else
        return false;
}
