/*!
 * \file AnimatedSprite.h
 * \author iSma
 */

#ifndef ANIMATEDSPRITE_H_
#define ANIMATEDSPRITE_H_

#include <SFML/Graphics.hpp>

/*!
 * \class AnimatedSprite
 * \brief Class modeling an animated sprite
 */
class AnimatedSprite : public sf::Sprite
{
    public:
        float framesPerSecond;

        AnimatedSprite(const std::string& data);
        virtual ~AnimatedSprite();

        virtual void Update();

        void SetAnimation(const std::string& name);
        std::string& GetAnimation();

        void SetFrame(float frame);
        float GetFrame();

    protected:
        /*!
         * \struct Animation
         * \brief Struct which models an animation : name, number of the row and duration
         */
        struct Animation
        {
                std::string name;
                int row, duration;
        };

        typedef std::map < std::string, Animation > AnimationMap;

        float currentFrame; //!< The actual frame of the animation
        Animation* currentAnimation; //!< The currently printed animation
        AnimationMap animations; //!< All the animations of the sprite

        sf::IntRect boundingBox, frameSize;
};

#endif /* ANIMATEDSPRITE_H_ */
