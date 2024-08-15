#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>
#include <cmath>
#include <chrono>
#include<thread>
 
using namespace sf;
using namespace std;

class Goblin {
private:
    Texture goblin1;
    float x;
    float y;
    float width;
    float height;
public:
    double dy;

    Sprite spriteg1;

    Goblin(int setx, int sety);

    Sprite& getSprite();

    Texture getTexture();

    float getWidth();

    float getHeight();

    float getX();

    float getY();
    
    void setPosition(float a, float b);
};
