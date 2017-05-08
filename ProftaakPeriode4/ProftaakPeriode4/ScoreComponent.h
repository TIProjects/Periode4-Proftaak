#pragma once
#include <type_traits>
#include "Component.h"

class ScoreComponent : Component
{
    public:
        ScoreComponent();

    virtual ~ScoreComponent()
    {
    }

    void changeScore(int);
        int returnScore();

        void Update(int deltaTime) override;
        void LateUpdate(int deltaTime) override;
    private:
        unsigned int _score;
};
