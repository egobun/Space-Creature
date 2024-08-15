#include "Block.h"

int dirg1 = 0;
int dirg2 = 0;

Block::Block(int setx, int sety, int number) {
    if (number == 2)
        this->block.loadFromFile("block2.png");
    if (number == 1)
        this->block.loadFromFile("block1.png");
    spriteb.setTexture(block);
    this->spriteb.setPosition(setx, sety);
    this->xValue = 0;
    this->yValue = 0;
}

Block::Block(int setx, int sety, int number, float xScale, float yScale, float xValue, float yValue) {
    this->xScale = xScale;
    this->yScale = yScale;
    this->xValue = xValue;
    this->yValue = yValue;
    if (number == 2)
        this->block.loadFromFile("block2.png");
    if (number == 1)
        this->block.loadFromFile("block1.png");

    spriteb.setTexture(block);
    this->spriteb.setPosition(setx, sety);
    spriteb.setScale(xScale, yScale);
}
    
Texture Block::getTexture() {
    return this->block;
}
Sprite Block::getSprite() {
    return this->spriteb;
}
int Block::getxValue() {
    return xValue;
}
int Block::getyValue() {
    return yValue;
}
float Block::getxScale() {
    return this->xScale;
}
float Block::getyScale() {
    return this->yScale;
}
float Block::getX() {
    return this->getSprite().getPosition().x;
}
float Block::getY() {
    return this->getSprite().getPosition().y;
}

void Block::interfire(Sprite& goblin) {
    if (goblin.getPosition().y >= this->spriteb.getPosition().y && goblin.getPosition().y <= this->spriteb.getPosition().y + 100/*this->getyValue()*/ && goblin.getPosition().x <= this->getX() + this->getxValue()) {
        goblin.setPosition(this->getX() + 100, goblin.getPosition().y);
    }
}


void Block::intergoblin(Goblin& goblin, bool& onGround) {
    if (goblin.getY() + goblin.getHeight() - 20 > this->spriteb.getPosition().y && goblin.getY() < this->spriteb.getPosition().y + this->getyValue() /*this->getTexture().getSize() this->getyValue()*/ && this->getX() + this->getxValue() >= goblin.getX() && this->getX() <= goblin.getX() + goblin.getWidth()) {

        if (dirg1 == 1 && Keyboard::isKeyPressed(Keyboard::Key::A) && Keyboard::isKeyPressed(Keyboard::Key::D)) {
            goblin.getSprite().move(-15, 0);
            return;
        }
        if (dirg1 == 0 && goblin.getY() < this->getY() + this->getyValue() - 15) {
            cout << 0 << endl;
            goblin.setPosition(this->getX() + this->getxValue(), goblin.getY());
        }

        if (dirg1 == 1 && goblin.getY() < this->getY() + this->getyValue() - 15) {
            cout << 1 << endl;
            goblin.setPosition(this->getX() - goblin.getWidth(), goblin.getY());
        }
        if (Keyboard::isKeyPressed(Keyboard::Key::W) && goblin.getY() >= this->getY() + this->getyValue() - 5) {
            goblin.setPosition(goblin.getX(), this->getY() + this->getyValue() - 5);
                
        }
        goblin.getSprite().move(0, 5);
            

    }

    else
        onGround = false;
}

   
void Block::intergoblinjump(Goblin& goblin, bool& onGround, double& dy) {
    if (dy < 0.005 and goblin.getY() < this->getY() + this->getyValue() && goblin.getY() > this->getY() - goblin.getHeight() and goblin.getX() < this->getX() + this->getxValue() && goblin.getX() + goblin.getWidth() > this->getX()) {
        onGround = true;
        dy = 0;
            
    }
    else
        onGround = false;
}

//void Block::fireunderblock(vector<Fire>& bolls, Block& block) {
//    for (int i = 0; i < bolls.size(); i++) {
//        auto fireblock = (this->getSprite().getPosition().x + this->getxValue() / 2 - bolls[i].spritef.getPosition().x) * (this->getSprite().getPosition().x + this->getxValue() / 2 - bolls[i].spritef.getPosition().x) + (this->getSprite().getPosition().y + this->getyValue() / 2 - bolls[i].spritef.getPosition().y) * (this->getSprite().getPosition().y + this->getyValue() / 2 - bolls[i].spritef.getPosition().y);
//        if (fireblock < this->getxValue() * this->getyValue() / 1.7) {
//            bolls[i].spritef.setPosition(10000, 10000);
//        }
//    }
//}

void Block::fireunderblock(vector<Fire>& bolls, Block& block) {
    vector<vector<Fire>::iterator> its;
    for (auto it = bolls.begin(); it != bolls.end(); it++) {
        if ((*it).getX() >= (float)block.getX()
            - ((float)(*it).getSprite().getTextureRect().width / 2) && (*it).getX() +
            ((float)(*it).getSprite().getTextureRect().width / 2) <= (float)block.getX()
            + block.getxValue() && (*it).getY() <=
            (float)block.getY() + block.getyValue()
            - ((float)(*it).getSprite().getTextureRect().height / 2) && (*it).getY()
            >= (float)block.getY() -
            ((float)(*it).getSprite().getTextureRect().height / 2))
        {
            its.push_back(it);
        }
    }
    if (its.size() > 0) {
        for (unsigned i = its.size() - 1;; i--)
        {
            bolls.erase(its[i]);
            if (i == 0) { break; }
        }
    }
}


