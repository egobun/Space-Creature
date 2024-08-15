#include "Fire.h"

Fire::Fire()
{
	fire.loadFromFile("firepro.png");
	spritef.setTexture(fire);
	spritef.setTextureRect(IntRect(0, 0, 72, 72));  
}

Sprite Fire::getSprite()
{
	return this->spritef;
}

float Fire::getX() {
    return this->getSprite().getPosition().x;
}

float Fire::getY() {
    return this->getSprite().getPosition().y;
}

void Fire::setPosition(float a, float b) {
    this->getSprite().setPosition(a, b);
}

Fire::Fire(float x, float y)
{
	fire.loadFromFile("firepro.png");
    spritef.setTexture(fire);
    spritef.setTextureRect(IntRect(0, 0, 72, 72));
    spritef.setPosition(x, y);
}

Fire::Fire(float x, float y, int dirb)
{
    this->dirb = dirb;
    fire.loadFromFile("firepro.png");
    spritef.setTexture(fire);
    spritef.setTextureRect(IntRect(0, 0, 72, 72));

    spritef.setPosition(x, y);
}

void Fire::givefire(vector<Fire> bolls, Sprite sprite, int dir)
{
    Fire b(sprite.getPosition().x + 60, sprite.getPosition().y + 60);
    if (Keyboard::isKeyPressed(Keyboard::Key::RShift)) {
        this_thread::sleep_for(chrono::milliseconds(55));
        if (!(Keyboard::isKeyPressed(Keyboard::Key::RShift))) {
            bolls.push_back(b);
            bolls[bolls.size() - 1].dirb = dir;
        }
    }
}
