#include <iostream>
#include <raylib.h>
#include "player.hpp"
#include "world.hpp"

#define Vector2_Zero (Vector2){0,0}

#define p720X 1280
#define p720Y 720


int main() {
  InitWindow(p720X,p720Y,"Walker");
  SetTargetFPS(60);
  
  Player player((Vector2){1280/2,720/2},(Camera2D){0,0,0,0,0,1.0f},(Vector2){50,50},RED);
  player.Camera.offset = (Vector2){p720X/2,p720Y/2};

  World world(1);

  world.Save();

  while (!WindowShouldClose()) {
    float Delta = GetFrameTime()*GetFPS();

    player.Move(Delta);
    player.SmoothCamera(Delta); 

    BeginDrawing();
    ClearBackground(BLACK);
    BeginMode2D(player.Camera);

    world.Draw();

    DrawLineEx(Vector2_Zero, (Vector2){350,350},10,YELLOW);
    player.Draw();

    EndMode2D();

    DrawFPS(0,0);
    EndDrawing();
  }

  return 0;
}