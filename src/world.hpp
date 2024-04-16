#ifndef WORLD_HPP
#define WORLD_HPP

#include <raylib.h>
#include <stdint.h>
#include <stdlib.h>
#include <fstream>

/*Texture id
NULL  - 0
Grass - 1
*/


class World {
    private:
    #define ChunkSizeX 20
    #define ChunkSizeY 20
    #define ChunkSize ChunkSizeX * ChunkSizeY
    #define WorldSize 256

    typedef struct chunkinfo {
        Vector2 Position;
        uint8_t TextureID;
    } chunkinfo;
    
    Vector2 ChunkSavePosition;

    uint16_t Scale;//how big one texture def=100
    chunkinfo *ChunkInfo;

    Texture2D Textures[255];

    void GenChunk();

    public:
    World(uint16_t Scale);
    ~World();

    void Draw();
    void Save();
};

World::World(uint16_t Scale) {
    World::ChunkSavePosition = (Vector2){0,0};

    World::Scale     = Scale;
    World::ChunkInfo = new World::chunkinfo[ChunkSize];
    
    World::GenChunk();

    Textures[0] = LoadTexture("./textures/null.png");
    Textures[1] = LoadTexture("./textures/world_gen/grass.png");
}

World::~World() {
    free(World::ChunkInfo);
}

void World::Draw() {
    Vector2 offset = ChunkSavePosition;

    for(size_t cout = 0; cout < ChunkSize; ++cout) {
        DrawTextureEx(
        Textures[ChunkInfo[cout].TextureID],
        ChunkInfo[cout].Position,0,Scale,
        (Color){255,255,255,255});
    }
}

void World::Save() {
    std::ofstream Save_file;

    Save_file.open("chunks.sav", std::ios_base::app);

    Save_file << '#' << ChunkSavePosition.x << '#' << ChunkSavePosition.y << '\n';

    for(size_t i = 0; i < ChunkSize; ++i) {
        Save_file << ChunkInfo[i].Position.x << ';'
                  << ChunkInfo[i].Position.y << ';'
                  << (int) ChunkInfo[i].TextureID  << ";\n";
    }

    Save_file.close();
}

void World::GenChunk() {
    uint32_t chunkX = 0;
    uint32_t chunkY = 0;

    uint32_t Tx_offset = 100*Scale;

    for(size_t cout = 0; cout < ChunkSize; ++cout) {
        ChunkInfo[cout].Position = (Vector2){(float) chunkX * Tx_offset,(float) chunkY * Tx_offset};
        ChunkInfo[cout].TextureID = 1;
        chunkX++;
        if(chunkX >= ChunkSizeX) {chunkX=0;chunkY++;}
    }
}

#endif //!WORLD_HPP