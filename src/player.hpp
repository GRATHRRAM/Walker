#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <raylib.h>
#include <raymath.h>

class Player {
    public:
    Vector2 Position;
    Camera2D Camera;

    Vector2 Size;
    Color PColor;

    float Speed;

    Player(Vector2 Position,Camera2D Camera,Vector2 Size,Color PColor);
    ~Player();
    void Draw();
    void Move(float Delta);
    void SmoothCamera(float Delta);
};

Player::Player(Vector2 Position,Camera2D Camera,Vector2 Size,Color PColor) {
    Player::Position = Position;
    Player::Camera   = Camera;
    Player::Size     = Size;
    Player::PColor   = PColor; 
    Player::Speed    = 4;
}

Player::~Player() {}

void Player::Draw() {
    DrawRectangleV(Player::Position, Player::Size, Player::PColor);
}

void Player::Move(float Delta) {
    if(IsKeyDown(KEY_A)) Player::Position.x -= Player::Speed * Delta;
    if(IsKeyDown(KEY_D)) Player::Position.x += Player::Speed * Delta;
    if(IsKeyDown(KEY_W)) Player::Position.y -= Player::Speed * Delta;
    if(IsKeyDown(KEY_S)) Player::Position.y += Player::Speed * Delta;
}

void Player::SmoothCamera(float Delta) {
    Player::Camera.target.x = Lerp(Player::Camera.target.x,Player::Position.x,0.05 * Delta);
    Player::Camera.target.y = Lerp(Player::Camera.target.y,Player::Position.y,0.05 * Delta); 
}
#endif //!PLAYER_HPP