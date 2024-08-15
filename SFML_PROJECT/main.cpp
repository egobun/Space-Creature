#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <math.h>
#include <thread>
#include <chrono>
#include "Fire.h"
#include "Goblin.h"
#include "Block.h"
#include "HealthOfGoblin.h"
#include "Heart.h"
#include "Timer.h"
extern int dirg1;
extern int dirg2;

using namespace sf;
using namespace std;

sf::View viewForGoblin;
View getGoblinCoordinatesForView(Vector2f vec) {
    viewForGoblin.setCenter(vec.x, 500);
    return viewForGoblin;
}

int main()
{
    //все для гоблина
    Goblin goblin(500, 500);
    //все для фаершаров
    vector<Fire> bolls;

    RenderWindow win(VideoMode(1000, 1000), "SFML works!", Style::None);

    viewForGoblin.reset(sf::FloatRect(0, 0, 1000, 1000));

    //все для таймера
    Font font;
    font.loadFromFile("font.ttf");
    Text text("", font, 40);
    //text.setColor(Color::Red);
    text.setStyle(Text::Bold);

    //все для хилинга гоблина
    Font fontForGoblin;
    fontForGoblin.loadFromFile("font.ttf");
    Text textForGoblin("", fontForGoblin, 45);
    textForGoblin.setFillColor(Color::Green);
    textForGoblin.setStyle(Text::Bold);
    int timeOfGoblinHealing = 0;
    int leftSecsOfGoblinHealing = 5;
    vector<string> secsOfGoblinHealing = { "0","1","2","3","4","5" };
    int durationOfSentenceForHealing = 0;
    int checkOutForScroll = 0;

    //все для дракона
    Texture tex;
    tex.loadFromFile("DraconProFile.png");

    Sprite sprite;
    sprite.setTexture(tex);
    sprite.setTextureRect(IntRect(0, 0, 140, 140));
    sprite.setScale(1.25, 1.25);

    int dragonReload = 0;

    float animationState = 0;
    float animationSpeed = 4;
    int dir = 0;
    Clock clcDrive;
    Clock clcAll;

    //все для аудиосопровождения

    Music music;//создаем объект музыки
    music.openFromFile("main_theme.wav");//загружаем файл
    music.play();

    //все для бэкграунда
    Texture cosmos;
    cosmos.loadFromFile("wallhaven.png");

    Sprite spritecosm;
    spritecosm.setTexture(cosmos);

    //все для блоков
    int numberOfBlocks = 15;
    Block block1(1000, 970, 1, 3.125, 3.125, 200, 200);
    Block block2(0, 600, 2, 1.5625, 1.5625, 100, 100);
    Block block3(100, 600, 1, 2, 2, 128, 128);
    Block block4(308, 561, 2, 3, 3, 192, 192);
    Block block5(500, 561, 1, 1.5625, 1.5625, 100, 100);
    Block block6(680, 700, 2, 1.5625, 1.5625, 100, 100);
    Block block7(400, 280, 1, 1.5625, 1.5625, 100, 100);//преграда для дракона
    Block block8(860, 650, 1, 3, 3, 64 * 3, 64 * 3);
    Block block9(620, 950, 2, 1.5625, 1.5625, 64 * 1.5625, 64 * 1.5625);
    Block block10(240, 950, 1, 1.5625, 1.5625, 64 * 1.5625, 64 * 1.5625);
    Block block11(1142, 655, 2, 3, 3, 64 * 3, 64 * 3);
    Block block12(1142 + 192, 655, 1, 1.5625, 1.5625, 100, 100);
    Block block13(1549, 760, 2, 1, 1, 64, 64);
    Block block14(1480, 100, 2, 3, 3, 64 * 3, 64 * 3);
    Block block15(1700, 950, 1, 3, 3, 64 * 3, 64 * 3);
    
     //все для гаме-овера

    Texture gameover;
    gameover.loadFromFile("end.jpg");

    Sprite spritego;
    spritego.setTexture(gameover);
    spritego.setScale(2, 2);

    Music musicgo;//создаем объект музыки
   
    musicgo.openFromFile("game_over_theme.wav"); //загружаем файл
    
    //все для виннинга

    Texture winning;
    winning.loadFromFile("winning.png");

    Sprite spritewi;
    spritewi.setTexture(winning);
    spritewi.setScale(2, 2);

    Music musicwi;//создаем объект музыки
    musicwi.openFromFile("winning_theme.wav");//загружаем файл

    float animationSpeedall = 6;
    float animationStateall = 0;

    win.setFramerateLimit(60);

    Clock clc;
    int circle_speed = 100;
    double dy = 0;
    bool drag = false;
    bool onGround = true;
    Vector2i click_offs;

    HealthOfGoblin gstate;

    getGoblinCoordinatesForView(goblin.getSprite().getPosition());

    Timer timer;

    while (win.isOpen())
    {
        goblin.getSprite().move(0, -dy);

        block1.intergoblin(goblin, onGround);
        block2.intergoblin(goblin, onGround);
        block3.intergoblin(goblin, onGround);
        block4.intergoblin(goblin, onGround);
        block5.intergoblin(goblin, onGround);
        block6.intergoblin(goblin, onGround);
        block7.intergoblin(goblin, onGround);
        block8.intergoblin(goblin, onGround);
        block9.intergoblin(goblin, onGround);
        block10.intergoblin(goblin, onGround);
        block11.intergoblin(goblin, onGround);
        block12.intergoblin(goblin, onGround);
        block13.intergoblin(goblin, onGround);
        block14.intergoblin(goblin, onGround);
        block15.intergoblin(goblin, onGround);

        block1.fireunderblock(bolls, block1);
        block2.fireunderblock(bolls, block2);
        block3.fireunderblock(bolls, block3);
        block4.fireunderblock(bolls, block4);
        block5.fireunderblock(bolls, block5);
        block6.fireunderblock(bolls, block6);
        block7.fireunderblock(bolls, block7);
        block8.fireunderblock(bolls, block8);
        block9.fireunderblock(bolls, block9);
        block10.fireunderblock(bolls, block10);
        block11.fireunderblock(bolls, block11);
        block12.fireunderblock(bolls, block12);
        block13.fireunderblock(bolls, block13);
        block14.fireunderblock(bolls, block14);
        block15.fireunderblock(bolls, block15);

        Event event;
        while (win.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                win.close();
        }

        if (gstate.GetNumberOfLives() > 0 and goblin.getY() <= 1000 and timer.getSeconds() >= 0) {
            auto elapsed = clc.restart().asMilliseconds();

            if (Keyboard::isKeyPressed(Keyboard::Key::D)) {
                goblin.getSprite().move(circle_speed * elapsed / 500, 0);
                dirg1 = 1;
                if (goblin.getX() >= 500 and goblin.getX() <= 1277)
                    getGoblinCoordinatesForView(goblin.getSprite().getPosition());
            }

            if (Keyboard::isKeyPressed(Keyboard::Key::A)) {
                goblin.getSprite().move(-circle_speed * elapsed / 500, 0);
                dirg1 = 0;
                if (goblin.getX() >= 500 and goblin.getX() <= 1277)
                    getGoblinCoordinatesForView(goblin.getSprite().getPosition());
            }

            if (goblin.getY() < 0)
            {
                goblin.setPosition(goblin.getX(), 0);
            }

            if (goblin.getX() < 0)
            {
                goblin.setPosition(0, goblin.getY());
            }


            if (goblin.getX() + goblin.getWidth() > 1777)
            {
                goblin.setPosition(1777 - goblin.getWidth(), goblin.getY());
            }

            //goto !(нельзя)
            block1.intergoblinjump(goblin, onGround, dy);
            if (onGround == true)
                goto linkAfterThisParagraph;
            block2.intergoblinjump(goblin, onGround, dy);
            if (onGround == true)
                goto linkAfterThisParagraph;
            block3.intergoblinjump(goblin, onGround, dy);
            if (onGround == true)
                goto linkAfterThisParagraph;
            block4.intergoblinjump(goblin, onGround, dy);
            if (onGround == true)
                goto linkAfterThisParagraph;
            block5.intergoblinjump(goblin, onGround, dy);
            if (onGround == true)
                goto linkAfterThisParagraph;
            block6.intergoblinjump(goblin, onGround, dy);
            if (onGround == true)
                goto linkAfterThisParagraph;
            block7.intergoblinjump(goblin, onGround, dy);
            if (onGround == true)
                goto linkAfterThisParagraph;
            block8.intergoblinjump(goblin, onGround, dy);
            if (onGround == true)
                goto linkAfterThisParagraph;
            block9.intergoblinjump(goblin, onGround, dy);
            if (onGround == true)
                goto linkAfterThisParagraph;
            block10.intergoblinjump(goblin, onGround, dy);
            if (onGround == true)
                goto linkAfterThisParagraph;
            block11.intergoblinjump(goblin, onGround, dy);
            if (onGround == true)
                goto linkAfterThisParagraph;
            block12.intergoblinjump(goblin, onGround, dy);
            if (onGround == true)
                goto linkAfterThisParagraph;
            block13.intergoblinjump(goblin, onGround, dy);
            if (onGround == true)
                goto linkAfterThisParagraph;
            block14.intergoblinjump(goblin, onGround, dy);
            if (onGround == true)
                goto linkAfterThisParagraph;
            block15.intergoblinjump(goblin, onGround, dy);

        linkAfterThisParagraph:

            if (Keyboard::isKeyPressed(Keyboard::Key::W) && onGround == true) {
                onGround = false;
                dy = 11;
            }

            if (onGround == false) {
                dy -= circle_speed * 0.005;
            }

            if (Keyboard::isKeyPressed(Keyboard::Key::Right)) {
                sprite.move(circle_speed * elapsed / 650, 0);
                dir = 0;
            }

            if (Keyboard::isKeyPressed(Keyboard::Key::Left)) {
                sprite.move(-circle_speed * elapsed / 650, 0);
                dir = 1;
            }

            if (Keyboard::isKeyPressed(Keyboard::Key::Down)) {
                sprite.move(0, circle_speed * elapsed / 650);
            }

            if (Keyboard::isKeyPressed(Keyboard::Key::Up)) {
                sprite.move(0, -circle_speed * elapsed / 650);
            }

            auto elapsed2 = clcDrive.restart().asSeconds();
            if (Keyboard::isKeyPressed(Keyboard::Key::A) || Keyboard::isKeyPressed(Keyboard::Key::D)) {
                animationState += elapsed2 * animationSpeed;
            }

            if (animationState >= 4) {
                animationState -= 4;
            }

            auto elapsedall = clcAll.restart().asSeconds();
            animationStateall += elapsedall * animationSpeedall;

            if (animationStateall >= 4) {
                animationStateall -= 4;
            }

            spritecosm.setPosition(0, 0);
            sprite.setTextureRect(IntRect(floor(animationStateall) * 140, dir * 140, 140, 140));
            goblin.getSprite().setTextureRect(IntRect(floor(animationState) * 85, dirg1 * 85, 85, 85));

            for (int i = 0; i < bolls.size(); i++) {
                bolls[i].spritef.setTextureRect(IntRect(floor(animationStateall) * 72, bolls[i].dirb * 72, 72, 72));
            }

            if (sprite.getPosition().x <= spritecosm.getPosition().x) {
                sprite.setPosition(spritecosm.getPosition().x, sprite.getPosition().y);
            }

            //1,25 - мастшаб дракона
            if (sprite.getPosition().x + (float)sprite.getTextureRect().width * 1.25 >= 1777) {
                sprite.setPosition(1777 - (float)sprite.getTextureRect().width * 1.25, sprite.getPosition().y);
            }

            if (sprite.getPosition().y <= 0) {
                sprite.setPosition(sprite.getPosition().x, 0);
            }

            Fire b(sprite.getPosition().x + 60, sprite.getPosition().y + 60);
            dragonReload++;
            if (Keyboard::isKeyPressed(Keyboard::Key::RShift) && dragonReload == 1) {
                bolls.push_back(b);
                bolls[bolls.size() - 1].dirb = dir;
            }

            if (dragonReload == 10)
            {
                dragonReload = 0;
            }

            win.clear();
            win.draw(spritecosm);

            for (int i = 0; i < bolls.size(); i++) {
                if (bolls[i].dirb == 0) {
                    bolls[i].spritef.move(5, 5);
                }
                if (bolls[i].dirb == 1) {
                    bolls[i].spritef.move(-5, 5);
                }

                win.draw(bolls[i].getSprite());
            }


           /* for (int i = 0; i < bolls.size(); i++) {
                auto distfire = (goblin.getSprite().getPosition().x - bolls[i].spritef.getPosition().x) * (goblin.getSprite().getPosition().x - bolls[i].spritef.getPosition().x) + (goblin.getSprite().getPosition().y - bolls[i].spritef.getPosition().y) * (goblin.getSprite().getPosition().y - bolls[i].spritef.getPosition().y);
                if (distfire < 2500) {
                    gstate.BurnGoblin();
                    gstate.IncreaseDurationOfBurning();
                    bolls[i].spritef.setPosition(goblin.getSprite().getPosition().x, goblin.getSprite().getPosition().y);
                }
            }*/
            for (int i = 0; i < bolls.size(); i++) {
                auto distfire = (goblin.getX() - bolls[i].getX()) * (goblin.getX() - bolls[i].getX()) + (goblin.getY() - bolls[i].getY()) * (goblin.getY() - bolls[i].getY());
                if (distfire < 2500) {
                    gstate.BurnGoblin();
                    gstate.IncreaseDurationOfBurning();
                    bolls[i].spritef.setPosition(goblin.getX(), goblin.getY());
                }
            }

            /*if (gstate.GetDurationOfBurning() > 250 && gstate.IsGoblinBurn()) {
                checkOutForScroll++;
                gstate.DecreaseNumberOfLives();
                gstate.KillDurationOfBurning();
                gstate.ExtinguishGoblin();
                for (int i = 0; i < bolls.size(); i++) {
                    if (bolls[i].spritef.getPosition() == goblin.getSprite().getPosition())
                        bolls[i].spritef.setPosition(1000, 1000);
                }
            }*/

            if (gstate.GetDurationOfBurning() > 250 && gstate.IsGoblinBurn()) {
                checkOutForScroll++;
                gstate.DecreaseNumberOfLives();
                gstate.KillDurationOfBurning();
                gstate.ExtinguishGoblin();
                vector<vector<Fire>::iterator> its;
                for (auto it = bolls.begin(); it != bolls.end(); it++) {
                    if ((*it).spritef.getPosition() == goblin.getSprite().getPosition())
                        its.push_back(it);
                }
                if (its.size() > 0) {
                    for (unsigned i = its.size() - 1;; i--)
                    {
                        bolls.erase(its[i]);
                        if (i == 0) { break; }
                    }
                }
            }

            win.draw(sprite);
            win.draw(goblin.getSprite());
            win.draw(block1.getSprite());
            win.draw(block2.getSprite());
            win.draw(block3.getSprite());
            win.draw(block4.getSprite());
            win.draw(block5.getSprite());
            win.draw(block6.getSprite());
            win.draw(block7.getSprite());
            win.draw(block8.getSprite());
            win.draw(block9.getSprite());
            win.draw(block10.getSprite());
            win.draw(block11.getSprite());
            win.draw(block12.getSprite());
            win.draw(block13.getSprite());
            win.draw(block14.getSprite());
            win.draw(block15.getSprite());

            for (int i = 0; i < gstate.GetNumberOfLives(); i++)
            {
                Heart PixelHeart(50, 47);
                PixelHeart.setPositionOfHeart(viewForGoblin.getCenter().x + 500 - PixelHeart.getWidth() * (i + 1), 5);
                win.draw(PixelHeart.getSprite());
            }

            timer.incrementCountOfCycles();
            text.setString(timer.getStringForDrawing(timer.getSeconds()));
            text.setPosition(viewForGoblin.getCenter().x - 490, viewForGoblin.getCenter().y - 510);
            win.draw(text);

            if (timer.getCountOfCycles() == timer.getLimitOfCycles()) {
                timer.setCountOfCycles(0);
                timer.decrementSeconds();
            }


            if (!(Keyboard::isKeyPressed(Keyboard::Key::D)) && !(Keyboard::isKeyPressed(Keyboard::Key::A)) && !(Keyboard::isKeyPressed(Keyboard::Key::W)))
            {
                if (Keyboard::isKeyPressed(Keyboard::Key::R) && onGround == true)
                {
                    if (leftSecsOfGoblinHealing < 0) {
                        gstate.IncreaseNumberOfLives();
                        leftSecsOfGoblinHealing = 5;
                    }
                    else {
                        timeOfGoblinHealing++;
                        textForGoblin.setString(secsOfGoblinHealing[leftSecsOfGoblinHealing]);
                        textForGoblin.setPosition(goblin.getX() - textForGoblin.getCharacterSize() + goblin.getWidth(), goblin.getY() - goblin.getHeight());
                        win.draw(textForGoblin);
                        if (timeOfGoblinHealing == timer.getLimitOfCycles() and leftSecsOfGoblinHealing >= 0)
                        {
                            timeOfGoblinHealing = 0;
                            leftSecsOfGoblinHealing--;
                        }
                    }
                }
            }

            else
            {
                leftSecsOfGoblinHealing = 5;
            }

            if (gstate.GetNumberOfLives() <= 4 && checkOutForScroll >= 1 && durationOfSentenceForHealing <= 260) {
                durationOfSentenceForHealing++;
            }

            text.setString("Press R to heal a goblin while not moving");
            text.setPosition(viewForGoblin.getCenter().x - 500 + 2 * text.getCharacterSize(), viewForGoblin.getCenter().y + 500 - 2 * text.getCharacterSize());
            
            if (durationOfSentenceForHealing > 0 && durationOfSentenceForHealing < 260) {
                win.draw(text);
            }

            win.setView(viewForGoblin);
            win.display();

            if (Keyboard::isKeyPressed(Keyboard::Key::Escape)) {
                break;
            }
        }

        else if ((gstate.GetNumberOfLives() <= 0 && timer.getSeconds() >= 0) || goblin.getY() > 1000)
        {
            music.pause();
            musicgo.play();
            spritego.setPosition(viewForGoblin.getCenter().x - 180, viewForGoblin.getCenter().y - 200);
            while (true)
            {
                win.clear();
                win.draw(spritecosm);
                win.draw(spritego);

                if (Keyboard::isKeyPressed(Keyboard::Key::Escape)) {
                    break;
                }
                win.display();
            }
            break;
        }

        else {
            music.pause();
            musicwi.play();
            spritewi.setPosition(viewForGoblin.getCenter().x - 420, viewForGoblin.getCenter().y - 450);
            while (true)
            {
                win.clear();
                win.draw(spritecosm);
                win.draw(spritewi);

                if (Keyboard::isKeyPressed(Keyboard::Key::Escape)) {
                    break;
                }
                win.display();
            }
            break;
        }
    }
    return 0;
}
