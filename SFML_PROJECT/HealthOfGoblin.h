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

class HealthOfGoblin {
private:
    int NumberOfLives = 5;

    bool IsBurn = false;

    long int DurationOfBurning = 0;

public:
    void BurnGoblin();

    void ExtinguishGoblin();

    bool IsGoblinBurn() const;

    long int GetDurationOfBurning() const;

    void KillDurationOfBurning();

    void IncreaseDurationOfBurning();

    int GetNumberOfLives() const;

    void DecreaseNumberOfLives();

    void IncreaseNumberOfLives();

};

