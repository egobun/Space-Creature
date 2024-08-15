#include "Goblin.h"

    Goblin::Goblin(int setx, int sety) {
        goblin1.loadFromFile("goblinpro1.png");
        spriteg1.setTexture(goblin1);
        spriteg1.setTextureRect(IntRect(0, 0, 85, 85));
        this->x = setx;
        this->y = sety;
        spriteg1.setPosition(setx, sety);
        spriteg1.setScale(0.75, 0.75);
        this->width = 63.75;
        this->height = 63.75;
    }

    Sprite& Goblin::getSprite() {
        return this->spriteg1;
    }
    Texture Goblin::getTexture()
    {
        return this->goblin1;
    }
    float Goblin:: getWidth() {
        return this->width;
    }
    float Goblin:: getHeight() {
        return this->height;
    }
    float Goblin::getX() {
        return this->getSprite().getPosition().x;
    }
    float Goblin::getY() {
        return this->getSprite().getPosition().y;
    }
    void Goblin::setPosition(float a, float b) {
        this->getSprite().setPosition(a, b);
    }

