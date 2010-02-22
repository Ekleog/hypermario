// Game.cpp
// By Monsieur_JaKy for hypermario project

#include "Game.h"

#include <iostream> // std::cout and std::endl
#include <fstream> // std::ifstream and public methodes
#include <algorithm> // std::for_each

using std::cout;
using std::endl;

#include "Goomba.h"
#include "Flower.h"

// See http://www.siteduzero.com/forum-83-488033-p1-appel-de-std-for_each-sur-une-liste-des-pointeurs.html#r4647737
// for the std::mem_fun and std::bind1st functionnement

Game::Game() : sf::RenderWindow(sf::VideoMode(SCREEN_WIDHT, SCREEN_HEIGHT), "Hyper Mario")
{
    _mario = new Mario(&_map);

    this->loadEnemys() ;
}

Game::~Game()
{
    // Mario
    delete _mario;

    // Enemys
    std::for_each(_Enemys.begin(), _Enemys.end(), std::bind1st(std::mem_fun(&Game::_deleteEnemy), this));
}

void Game::loadEnemys(void)
{
    std::ifstream file("media/Enemys/1.enn") ;

    while (file.good())
    {
        Enemy* enn = NULL;
        char c;
        file >> c;

        if (c == 'G')
            enn = new Goomba(&_map);
        else if (c == 'F')
            enn = new Flower(&_map);

        // Set Enemy's position
        int x, y;
        file >> x >> y;
        enn->SetPosition(x, y);
        _Enemys.push_back(enn);
    }
    file.close();
}

void Game::drawAll(void)
{
    // SetView (for scrolling)
    sf::View view;
    view.SetFromRect(_map.getScrolling());

    this->SetView(view);

    // Map
    _map.drawMap(*this);

    // Mario
    Draw(*_mario);

    // Enemys
    std::for_each(_Enemys.begin(), _Enemys.end(), std::bind1st(std::mem_fun(&Game::_drawEnemy), this)) ;
}

void Game::evolue(void)
{
    // Mario
    _mario->evolue(_mario->status());

    // Map
    _map.refreshScrolling(_mario->GetPosition());

    // Enemys
    std::for_each(_Enemys.begin(), _Enemys.end(), std::bind1st(std::mem_fun(&Game::_EnemyEvolue), this)) ;

    // Test collides
    std::list<Enemy *>::iterator it;
    for (it = _Enemys.begin(); it != _Enemys.end(); ++it)
    {
        EFFECT e = _mario->isCollide(*it);
        if (e == MARIO_DEAD)
            puts("AHAHA"), system("cls"); /** Change this **/
        else if (e == ENNEMI_DEAD)
        {
            delete *it;
            _Enemys.erase(it);

            // Mario can't kill 2 Enemys at the same time, so break
            break;
        }
    }
}

void Game::checkEvent(void)
{
    const sf::Input& input = this->GetInput();
    sf::Event Event;
    this->GetEvent(Event);

    // float time = _clock.GetElapsedTime() ;

    // close window
    if (Event.Type == sf::Event::Closed)
        this->Close();

    // direction control
    if (input.IsKeyDown(sf::Key::Up))
        if (_mario->status() == ON_THE_GROUND)
            _mario->status() = JUMP;

    if (input.IsKeyDown(sf::Key::Right))
        _mario->evolue(RIGHT);

    if (input.IsKeyDown(sf::Key::Left))
        _mario->evolue(LEFT);

    if (input.IsKeyDown(sf::Key::A))
        this->SetFramerateLimit(10);
    if (input.IsKeyDown(sf::Key::B))
        this->SetFramerateLimit(60);
}

// Private functions about Enemys (used with std::for_each)

void Game::_drawEnemy(const Enemy* Enemy)
{
    if (Enemy->draw())
        this->Draw(*Enemy) ;
}

void Game::_EnemyEvolue(Enemy* enn)
{
    enn->evolue() ;
}

void Game::_deleteEnemy(Enemy* enn)
{
    delete enn;
}
