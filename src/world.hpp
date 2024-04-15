#ifndef WORLD_HPP
#define WORLD_HPP

#include <raylib.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct chunkinfo {
        Vector2 Position;
        uint8_t TextureID;
} chunkinfo;

class World {
    private:
    uint16_t Scale;//how big one texture def=100
    uint16_t ChunkSize;//how many objects in chunk
    chunkinfo *ChunkInfo;
    

    public:
    World(uint16_t Scale, uint16_t ChuckSize);
    ~World();
};

World::World(uint16_t Scale, uint16_t ChuckSize) {
    World::Scale     = Scale;
    World::ChunkSize = ChuckSize;
    World::ChunkInfo = (chunkinfo) malloc(sizeof(chunkinfo) * ChunkSize);

}

World::~World() {
    free(World::ChunkInfo);
}


#endif //!WORLD_HPP