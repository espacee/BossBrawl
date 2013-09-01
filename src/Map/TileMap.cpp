#include "Map/TileMap.hpp"

#include <fstream>

TileMap::TileMap()
{
    loadTileset();
}

TileMap::~TileMap()
{
    for (auto l : layers)
    {
        delete l;
    }
}

void TileMap::loadTileset()
{
    sprites.push_back(sf::Sprite());

    if (tileSet.loadFromFile("res/img/tileset.png"))
    {
        int ts_width = tileSet.getSize().x;
        int ts_height = tileSet.getSize().y;

        for (int j = 0; j < ts_height; j += GRID_SIZE)
        {
            for (int i = 0; i < ts_width; i += GRID_SIZE)
            {
                sprites.push_back(sf::Sprite(tileSet, sf::IntRect(i, j, GRID_SIZE, GRID_SIZE)));
            }
        }
    }
}

bool TileMap::loadFromFile(const std::string &filename)
{
    std::ifstream file(filename);

    if (!file)
        return false;

    // How many layers
    int nLayers;
    file >> nLayers;

    layers.resize(nLayers);

    for (int i = 0; i < nLayers; ++i)
    {
        // Name
        std::string name;
        file.get(); // Discard newline character
        std::getline(file, name);

        Layer* l = new Layer(name);

        // Visibility
        file >> l->m_visible;
        // Grid color
        int r, g, b, a;
        file >> r >> g >> b >> a;
        l->m_gridColor = sf::Color(r, g, b, a);
        // x/y offsets
        file >> l->m_x >> l->m_y;
        // Depth index
        file >> l->m_depthIndex;
        // Number of columns, rows
        int columns, rows;
        file >> columns >> rows;

        auto& map = l->m_tiles;
        map.resize(columns);

        // Fetch the tile data
        for (int x = 0; x < columns; ++x)
        {
            map[x].resize(rows);

            for (int y = 0; y < rows; ++y)
            {
                file >> map[x][y];
            }
        }

        layers[i] = l;

        if (!file) {
            return false;
        }
    }

    return true;
}

bool TileMap::saveToFile(const std::string &filename)
{
    std::ofstream file(filename);

    if (!file)
        return false;

    // How many layers
    file << layers.size() << '\n';

    for (const Layer * layer : layers)
    {
        const Layer& l = *layer;
        // Name
        file << l.m_name << '\n';
        // Visibility
        file << l.m_visible << '\n';
        // Grid color
        const sf::Color& gc = l.m_gridColor;
        file << (int) gc.r << ' ' << (int) gc.g << ' ' << (int) gc.b << ' ' << (int) gc.a << '\n';
        // x/y offsets
        file << l.m_x << ' ' << l.m_y << '\n';
        // Depth index
        file << l.m_depthIndex << '\n';
        // Number of columns, rows
        file << l.getHLength() << ' ' << l.getVLength() << '\n';

        // Dump the tile data
        for (int x = 0; x < l.getHLength(); ++x)
        {
            for (int y = 0; y < l.getVLength(); ++y)
            {
                file << ' ' << l.m_tiles[x][y];
            }
        }

        file << '\n';
    }

    return true;
}

void TileMap::addLayer(int pos)
{
    if (layers.size() == 0)
    {
        layers.push_back(new Layer("Layer 0"));
    }
    else
    {
        layers.insert(layers.begin() + pos, new Layer("Layer " + std::to_string(pos)));
    }
}

void TileMap::removeLayer(int pos)
{
    if (layerExists(pos))
        layers.erase(layers.begin() + pos);
}

void TileMap::moveLayerBackground(int pos)
{
    Layer* temp = layers[pos];
    layers[pos] = layers[pos - 1];
    layers[pos - 1] = temp;
}

void TileMap::moveLayerForeground(int pos)
{
    Layer* temp = layers[pos];
    layers[pos] = layers[pos + 1];
    layers[pos + 1] = temp;
}

int TileMap::size()
{
    return layers.size();
}

bool TileMap::tileExists(unsigned int x, unsigned int y, unsigned int layer) const
{
    if (layerExists(layer))
        return layers[layer]->tileExists(x, y);
    else
        return false;
}
bool TileMap::spriteExists(unsigned int id) const
{
    return id < sprites.size();
}

bool TileMap::layerExists(unsigned int layer) const
{
    return layer < layers.size();
}

void TileMap::draw(sf::RenderWindow &target, unsigned int drawGridForLayer)
{

    sf::View saveCamera = target.getView();
    sf::View camera = saveCamera;

    for (unsigned int k = 0; k < layers.size(); k++)
    {

        if (layers[k]->isVisible())
        {
            camera.setCenter((saveCamera.getCenter().x * layers[k]->getDepthIndex() - layers[k]->getPosition().x),
                             (saveCamera.getCenter().y * layers[k]->getDepthIndex() - layers[k]->getPosition().y));

            target.setView(camera);

            int xmin = (int)(camera.getCenter().x - camera.getSize().x / 2) / GRID_SIZE;
            int ymin = (int)(camera.getCenter().y - camera.getSize().y / 2) / GRID_SIZE;

            int xmax = (int)(camera.getCenter().x + camera.getSize().x / 2) / GRID_SIZE + 1;
            int ymax = (int)(camera.getCenter().y + camera.getSize().y / 2) / GRID_SIZE + 1;

            if (xmin < 0) xmin = 0;

            if (ymin < 0) ymin = 0;

            if (xmax < 0) xmax = 0;

            if (ymax < 0) ymax = 0;

            if (xmin > (layers[k]->getHLength())) xmin = layers[k]->getHLength();

            if (ymin > (layers[k]->getVLength())) ymin = layers[k]->getVLength();

            if (xmax > (layers[k]->getHLength())) xmax = layers[k]->getHLength();

            if (ymax > (layers[k]->getVLength())) ymax = layers[k]->getVLength();

            if (drawGridForLayer == k)
            {
                sf::RectangleShape layerBackground(sf::Vector2f(layers[k]->getWidth(), layers[k]->getHeight()));
                sf::Color temp = layers[k]->getGridColor();
                temp.a /= 2;
                layerBackground.setFillColor(temp);
                target.draw(layerBackground);
            }

            for (int i = xmin; i <= xmax; i++)
            {
                for (int j = ymin; j <= ymax; j++)
                {
                    if (!tileExists(i, j, k))
                        continue;

                    unsigned int id = (*layers[k])(i, j);

                    if (id)
                    {
                        sprites[id].setPosition((i * GRID_SIZE),
                                                (j * GRID_SIZE));
                        target.draw(sprites[id]);
                    }

                    if (drawGridForLayer == k)
                    {
                        sf::Vertex hLine[] =
                        {
                            sf::Vertex(sf::Vector2f(xmin * GRID_SIZE, j * GRID_SIZE), layers[k]->getGridColor()),
                            sf::Vertex(sf::Vector2f((xmax)*GRID_SIZE, j * GRID_SIZE), layers[k]->getGridColor())
                        };
                        target.draw(hLine, 2, sf::Lines);
                    }
                }

                if (drawGridForLayer == k)
                {
                    sf::Vertex vLine[] =
                    {
                        sf::Vertex(sf::Vector2f(i * GRID_SIZE, ymin * GRID_SIZE), layers[k]->getGridColor()),
                        sf::Vertex(sf::Vector2f(i * GRID_SIZE, (ymax)*GRID_SIZE), layers[k]->getGridColor())
                    };
                    target.draw(vLine, 2, sf::Lines);
                }
            }
        }
    }

    target.setView(saveCamera);
}
