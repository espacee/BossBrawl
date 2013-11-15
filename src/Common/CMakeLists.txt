add_library(map
Map/Layer.cpp
Map/Layer.hpp
Map/TileMap.cpp
Map/TileMap.hpp
)

add_library(util
Util/collision.cpp
Util/collision.h
Util/math.hpp
Util/unused.hpp
Util/view.cpp
Util/view.hpp
)

add_library(entities
Entities/DefaultEnemy.cpp
Entities/DefaultEnemy.hpp
Entities/Enemy.cpp
Entities/Enemy.hpp
Entities/Entity.cpp
Entities/Entity.hpp
Entities/EntityContainer.cpp
Entities/EntityContainer.hpp
Entities/Player.cpp
Entities/Player.hpp
)
