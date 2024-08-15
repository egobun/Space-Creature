#include "Timer.h"

string Timer::getStringForDrawing(int number) const {
    string temporaryString = "";
    if (number >= 100)
    {
        temporaryString.append(countsString[number % 10]);
        number = (number - number % 10) / 10;

        temporaryString.append(countsString[number % 10]);
        number = (number - number % 10) / 10;

        temporaryString.append(countsString[number % 10]);
    }
    else if (number >= 10 and number <= 99)
    {
        temporaryString.append(countsString[number % 10]);
        number = (number - number % 10) / 10;

        temporaryString.append(countsString[number % 10]);
    }
    else
    {
        temporaryString.append(countsString[number]);
    }
    reverse(temporaryString.begin(), temporaryString.end());
    return ("Time: " + temporaryString);
}

int Timer::getLimitOfCycles() const {
    return this->limitOfCycles;
}

string Timer::getDvoetochie() {
    return this->countsString[10];
}

void Timer::setCountOfCycles(int newCountOfCycles) {
    this->countOfCycles = newCountOfCycles;
}

int Timer::getCountOfCycles() const {
    return this->countOfCycles;
}

void Timer::decrementSeconds() {
    this->seconds--;
}

int Timer::getSeconds() const {
    return this->seconds;
}

void Timer::incrementCountOfCycles() {
    this->countOfCycles++;
}
