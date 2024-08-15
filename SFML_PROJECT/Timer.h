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

class Timer {
private:
    int limitOfCycles = 50;
    int countOfCycles = 0;
    int seconds = 60;
    vector<string> countsString = { "0","1","2","3","4","5","6","7","8","9", ":" };
public:
    string getStringForDrawing(int number) const;

    int getLimitOfCycles() const;

    string getDvoetochie();

    void setCountOfCycles(int newCountOfCycles);

    int getCountOfCycles() const;

    void decrementSeconds();

    int getSeconds() const;

    void incrementCountOfCycles();
    
};

