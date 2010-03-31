/*!
 * \file AnimatedSprite.cpp
 * \author iSma
 */

#include <sstream>

#include "AnimatedSprite.h"
#include "ImageManager.h"
#include "Game.h"

/*!
 * \brief The constructor of AnimatedSprite
 * \param data The string to parse
 * \return
 */
AnimatedSprite::AnimatedSprite(const std::string& data)
{
    std::istringstream stream(data, std::ios::in);
    Animation newAnim;
    int i = 0, max = 0;

    stream >> newAnim.name;

    SetImage(ImageManager::Get(newAnim.name));

    while (!stream.eof())
    {
        stream >> newAnim.name >> newAnim.duration;
        newAnim.row = i++;
        animations[newAnim.name] = newAnim;
        max = newAnim.duration > max ? newAnim.duration : max;
    }

    frameSize = sf::IntRect(0, 0, 0, 0);
    frameSize.Bottom = GetImage()->GetHeight() / i;
    frameSize.Right = GetImage()->GetWidth() / max;
    currentAnimation = &animations[newAnim.name];
}

/*!
 * \brief The destructor of AnimatedSprite
 * \return
 */
AnimatedSprite::~AnimatedSprite()
{
}

/*!
 * \brief Updates the sprite so that it will go to the next frame if needed.
 */
void AnimatedSprite::Update(void)
{
    SetFrame(currentFrame + framesPerSecond / Game::framerate);
}

/*!
 * \brief Sets the actual animation to the animation named {name}
 * \param name the new animation to play
 */
void AnimatedSprite::SetAnimation(const std::string& name)
{
    AnimationMap::iterator anim = animations.find(name);

    if (anim != animations.end())
    {
        currentAnimation = &(anim->second);
        SetFrame(0);
    }
}

/*!
 * \return The name of the current animation
 */
std::string& AnimatedSprite::GetAnimation(void)
{
    return currentAnimation->name;
}

/*!
 * \brief Goes directly to the frame {frame} of the actual animation
 * \param frame The new frame to print
 */
void AnimatedSprite::SetFrame(float frame)
{
    currentFrame = fmod(frame, currentAnimation->duration);
    sf::IntRect subRect(frameSize);
    subRect.Offset((int) currentFrame * frameSize.GetWidth(),
                   (int) currentAnimation->row * frameSize.GetHeight());
    SetSubRect(subRect);
}

/*!
 * \return The number of the currently printed frame
 */
float AnimatedSprite::GetFrame(void)
{
    return currentFrame;
}
