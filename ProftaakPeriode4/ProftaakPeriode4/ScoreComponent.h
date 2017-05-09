#pragma once
#include <type_traits>
#include "Component.h"
#include <string>

class ScoreComponent : Component
{
    public:

        unsigned int _score;
        std::string _name;

        ScoreComponent();

        virtual ~ScoreComponent()
        {
        }

        void changeScore(int);
        void changeName(std::string name);

        std::string returnName();
        int returnScore();

        void Update(int deltaTime) override;
        void LateUpdate(int deltaTime) override;

        bool operator > (const ScoreComponent& temp) const
        {
            return (_score > temp._score);
        }
};
