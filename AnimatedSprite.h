/*
 * AnimatedSprite.h
 *
 *  Created on: 14 mars 2010
 *      Author: iSma
 */

#ifndef ANIMATEDSPRITE_H_
#define ANIMATEDSPRITE_H_

#include <SFML/Graphics.hpp>

class AnimatedSprite : public sf::Sprite
{
public:
	float framesPerSecond;
	AnimatedSprite(const std::string& data);
	virtual ~AnimatedSprite(void);

	virtual void Update(void);
	void SetAnimation(const std::string& name);
	std::string& GetAnimation(void);
	void SetFrame(float frame);
	float GetFrame(void);

protected:
	struct Animation
	{
		std::string name;
		int row, duration;
	};

	typedef std::map<std::string, Animation> AnimationMap;

	float currentFrame;
	Animation* currentAnimation;
	AnimationMap animations;

	sf::IntRect boundingBox, frameSize;
};

#endif /* ANIMATEDSPRITE_H_ */
