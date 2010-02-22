// Flower.cpp
// By Monsieur_JaKy for hypermario project

#include "Flower.h"

Flower::Flower(Map* map) : Enemy(map)
{
    _img.LoadFromFile("media/Enemys/flower.bmp");
    _img.CreateMaskFromColor(sf::Color(208, 214, 226));

    this->SetImage(_img);
    this->Resize(24.f, 48.f);

    _id = FLOWER;
}

Flower::~Flower()
{

}

void Flower::evolue(void)
{
    float time = _clock.GetElapsedTime() ;

    if (time >= 1.f)
    {
        _draw = !_draw;
        _clock.Reset() ;
    }

}
