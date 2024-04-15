#include <iostream>
#include <raylib.h>
#include <raymath.h>
#include "player.hpp"

#define Vector2_Zero (Vector2){0,0}

#define p720X 1280
#define p720Y 720


float GetDelta() {return GetFrameTime()*GetFPS();}


int main() {
  InitWindow(p720X,p720Y,"Walker");
  
  Player player((Vector2){1280/2,720/2},(Camera2D){0,0,0,0,0,1.0f},(Vector2){50,50},RED);
  player.Camera.offset = (Vector2){p720X/2,p720Y/2};

  while (!WindowShouldClose()) {
    float Delta = GetDelta();

    player.Move(Delta);
    player.Camera.target.x = Lerp(player.Camera.target.x,player.Position.x,0.001 * Delta);
    player.Camera.target.y = Lerp(player.Camera.target.y,player.Position.y,0.001 * Delta);    

    BeginDrawing();
    ClearBackground(BLACK);
    BeginMode2D(player.Camera);

    DrawLineEx(Vector2_Zero, (Vector2){350,350},10,YELLOW);
    player.Draw();

    EndMode2D();
    EndDrawing();
  }

  return 0;
}