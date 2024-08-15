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

class Heart {
private:
    int width;
    int height;
    Texture heart;
    Sprite spriteh;
public:
    Sprite getSprite();
    Heart(int width, int height);
    int getWidth() const;
    void setPositionOfHeart(float xPos, float yPos);
};

