#pragma once
#include "Component.h"
#include <GL\freeglut.h>
#include "GameObject.h"

/**
 * \brief colour strcut
 * \param red Amount of red
 * \param green Amount of green
 * \param blue Amount of blue
 * \param alpha The transparentie
 */
struct Colour
{
    float red;
    float green;
    float blue;
    float alpha;
};

namespace AlphaBlending
{
    /**
     * \brief Begins alpha blend
     * Starts alpha blending.
     * You need to set the glColor4f yourself
     * call endAlphaBlending you're done drawing the component that needs this
     */
    inline void beginAlphaBlending()
    {
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    }

    /**
     * \brief ends alpha blend
     * Disables the alpha blending
     * Sets the colour back to solid white
     */
    inline void endAlphaBlending()
    {
        glDisable(GL_BLEND);
        glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
    }

    /**
     * \brief draws a gameobject with choosen alpha blend
     * \param gameObject the gameobject that is being drawn.
     * \param c the colour you want.
     */
    inline void blendGameObject(GameObject* gameObject, Colour c)
    {
        beginAlphaBlending();
        glColor4f(c.red, c.green, c.blue, c.alpha);
        gameObject->Draw();
        endAlphaBlending();
    }
}
