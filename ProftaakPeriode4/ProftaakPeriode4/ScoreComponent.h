#pragma once
#include <type_traits>
#include "Component.h"
#include <string>

class ScoreComponent : public Component
{
    public:

        /*
         * Score can't get below zero
         */
        unsigned int _score;

        /*
         * Name of the person holding the score
         * Template name is Gijs for now
         */
        std::string _name;

        ScoreComponent();

        ~ScoreComponent();

        /*
         * Adds the score you fill in
         * The score can't be below zero 
         */
        void changeScore(int);

        /*
         * Replaces the name of the one holding the score
         */
        void changeName(std::string name);

        /* 
         * Returns the name
         */
        std::string returnName();

        /*
         * Returns the score
         */
        unsigned int returnScore();

        void Update(float deltaTime) override;
        void LateUpdate(float deltaTime) override;
};
