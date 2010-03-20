/*
 * AnimatedSprite.cpp
 *
 *  Created on: 14 mars 2010
 *      Author: iSma
 */

#include "AnimatedSprite.h"
#include "ImageManager.h"
#include <sstream>

AnimatedSprite::AnimatedSprite(const std::string& data)
{
	std::istringstream stream(data, std::istringstream::in);
	Animation newAnim;
	int i = 0, max = 0;;

	stream >> newAnim.name;

	SetImage(ImageManager::Get(newAnim.name));

	while(!stream.eof())
	{
		stream >> newAnim.name >> newAnim.duration;
		newAnim.row = i++;
		animations[newAnim.name] = newAnim;
		max = newAnim.duration > max ? newAnim.duration : max;
	}

	frameSize = sf::IntRect(0, 0, 0, 0);
	frameSize.Bottom = GetImage()->GetHeight() / i;
	frameSize.Right  = GetImage()->GetWidth() / max;
	currentAnimation = &newAnim;
}

AnimatedSprite::~AnimatedSprite(void)
{
	// TODO Auto-generated destructor stub
}

void AnimatedSprite::Update(void)
{
	SetFrame(currentFrame + framesPerSecond);
}

void AnimatedSprite::SetAnimation(const std::string& name)
{
	AnimationMap::iterator anim = animations.find(name);

	if(anim != animations.end())
	{
		currentAnimation = &(anim->second);
		SetFrame(0);
	}
}

std::string& AnimatedSprite::GetAnimation(void)
{
	return currentAnimation->name;
}

void AnimatedSprite::SetFrame(float frame)
{
	currentFrame = fmod(frame, currentAnimation->duration);
	sf::IntRect subRect(frameSize);
	subRect.Offset((int)currentFrame * frameSize.GetWidth(), (int)currentAnimation->row * frameSize.GetHeight());
	SetSubRect(subRect);
}

float AnimatedSprite::GetFrame(void)
{
	return currentFrame;
}
