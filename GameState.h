#pragma once
#include "State.h"
#include "Button.h"
class GameState :
    public State
{
protected:
    sf::Text text, text1;
    sf::Font font;

    std::map<std::string, Button*> buttons;


    //function


public:
    GameState(sf::RenderWindow* window, std::stack<State*>* states);
    virtual ~GameState();

    //function
    void initButtons();
    void updateButtons();
    void renderButtons(sf::RenderTarget* target);
    void initText();
    void renderText(sf::RenderTarget* target);
    void endstate();
    void updateInput(const float& dt);
    void update(const float &dt);
    void render(sf::RenderTarget *target = NULL);
};

