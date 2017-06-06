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
class Colour
{
public:
	union
	{
		struct
		{
			float red;
			float green;
			float blue;
			float alpha;
		};
		float v[4];
	};
	Colour();
	Colour(const Colour& other);
};

inline Colour::Colour()
{
	red = 1.0f;
	green = 1.0f;
	blue = 1.0f;
	alpha = 1.0f;
}

inline Colour::Colour(const Colour& other)
{
	red = other.red;
	green = other.green;
	blue = other.blue;
	alpha = other.alpha;
}

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
        glEnableClientState(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    }

    /**
     * \brief ends alpha blend
     * Disables the alpha blending
     * Sets the colour back to solid white
     */
    inline void endAlphaBlending()
    {
        glDisableClientState(GL_BLEND);
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
        glColor4fv(c.v);
        gameObject->Draw();
        endAlphaBlending();
    }
}
