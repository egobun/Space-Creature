#include "Heart.h"


    Heart::Heart(int width, int height) {
        heart.loadFromFile("heart.png");
        spriteh.setTexture(heart);
        this->width = width;
        this->height = height;
    }

    Sprite Heart::getSprite() {
        return this->spriteh;
    }

    int Heart::getWidth() const {
        return this->width;
    }

    void Heart::setPositionOfHeart(float xPos, float yPos) {
        spriteh.setPosition(xPos, yPos);
    }
