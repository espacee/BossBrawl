#include "TileMap.hpp"

TileMap::TileMap()
{
    LoadTiles();
    nb_layers=0;
    lastLayerID=0;
    AddLayer();
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

void TileMap::ResizeLayer(unsigned int layer, unsigned int new_hLength, unsigned int new_vLength)
{
    if(LayerExists(layer))
        layers[layer].Resize(new_hLength, new_vLength);
}

void TileMap::SetTile(unsigned int layer, unsigned int x, unsigned int y, unsigned int id)
{
    if(LayerExists(layer)  && SpriteExists(id))
        layers[layer].SetTile(x,y,id);
}

unsigned int TileMap::GetTile(unsigned int layer, unsigned int x, unsigned int y) const
{
    if(LayerExists(layer))
        return layers[layer].GetTile(x,y);
    else
        return 0;
}

void TileMap::FillLayer(unsigned int layer, unsigned int id)
{
    if(LayerExists(layer) && SpriteExists(id))
    {
        layers[layer].Fill(id);
    }
}

void TileMap::MoveLayer(int x_offset, int y_offset, unsigned int layer)
{
    if(LayerExists(layer))
    {
        layers[layer].Move(x_offset, y_offset);
    }
}

void TileMap::SetLayerPosition(int new_x_coord, int new_y_coord,unsigned int layer)
{
    if(LayerExists(layer))
    {
        layers[layer].SetPosition(new_x_coord, new_y_coord);
    }
}

void TileMap::AddLayer()
{
    nb_layers++;
    lastLayerID++;
    layers.push_back(Layer(lastLayerID));
}

void TileMap::PopLayer()
{
    if(nb_layers>1)
    {
        layers.pop_back();
        nb_layers--;
    }
}

bool TileMap::TileExists(unsigned int x, unsigned int y, unsigned int layer) const
{
    if(LayerExists(layer))
        return layers[layer].TileExists(x,y);
    else
        return false;
}

bool TileMap::SpriteExists(unsigned int id) const
{
    return id < sprites.size();
}

bool TileMap::LayerExists(unsigned int layer) const
{
    return layer < layers.size();
}

void TileMap::Display(sf::RenderWindow &w)
{
    for(unsigned int k=0;k<nb_layers;k++)
    {
        for(unsigned int i=0;i<layers[k].GetHLength();i++)
        {
            for(unsigned int j=0;j<layers[k].GetVLength();j++)
            {
                unsigned int id=layers[k].GetTile(i,j);
                if(id)
                {
                    sprites[id].setPosition(layers[k].GetX()+(int)(i*GRID_SIZE),
                                            layers[k].GetY()+(int)(j*GRID_SIZE));
                    w.draw(sprites[id]);
                }
            }
        }
    }
}
