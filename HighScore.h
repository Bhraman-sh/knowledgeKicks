#pragma once
#include "State.h"
class HighScore :
    public State
{
private:
    sf::Text text;
    sf::Text text1;
    sf::Font font;

public:
    HighScore(sf::RenderWindow* window, std::stack<State*>* states);
    virtual ~HighScore();

    //functions
    void initText();
    void renderText(sf::RenderTarget *target);
    void endState();
    void updateInput(const float& dt);
    void update(const float& dt);
    void render(sf::RenderTarget* target = NULL);

};

