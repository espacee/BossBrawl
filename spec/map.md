The map is a tile map with a fixed grid size.
It has multiple layers that are reorderable.
It loads the tiles from a single tileset located in "res/img/tileset.png".

It can have animated tiles. The animated tiles are described in "res/anims.txt" file.
It has the following format:

    begin framecount, ...

Where

- `begin` is an integer specifying the beginning tile

- `framecount` is an integer specifying the number of tiles in the animation.

Frames of animated tiles are laid out sequentially.
