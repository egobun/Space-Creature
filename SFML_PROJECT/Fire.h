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


class Fire
{
private:
    Texture fire;
public:
    
    Sprite spritef;
    int dirb = 0;

    Fire();
    Sprite getSprite();

    Fire(float x, float y);
       
    Fire(float x, float y, int dirb);
        
    void givefire(vector<Fire>bolls, Sprite sprite, int dir);

    float getX();

    float getY();

    void setPosition(float a, float b);
};


