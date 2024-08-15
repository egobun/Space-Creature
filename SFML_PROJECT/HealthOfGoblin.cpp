#include "HealthOfGoblin.h"


    void HealthOfGoblin:: BurnGoblin() {
        this->IsBurn = true;
    }
    void HealthOfGoblin::ExtinguishGoblin() {
        this->IsBurn = false;
    }
    bool HealthOfGoblin::IsGoblinBurn() const {
        return this->IsBurn;
    }
    long int HealthOfGoblin::GetDurationOfBurning() const {
        return this->DurationOfBurning;
    }
    void HealthOfGoblin::KillDurationOfBurning() {
        this->DurationOfBurning = 0;
    }
    void HealthOfGoblin::IncreaseDurationOfBurning() {
        this->DurationOfBurning++;
    }
    int HealthOfGoblin::GetNumberOfLives() const {
        return this->NumberOfLives;
    }
    void HealthOfGoblin::DecreaseNumberOfLives() {
        this->NumberOfLives--;
    }
    void HealthOfGoblin::IncreaseNumberOfLives() {
        this->NumberOfLives++;
    }

