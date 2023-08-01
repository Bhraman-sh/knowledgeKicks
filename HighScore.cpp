#include "HighScore.h"

HighScore::HighScore(sf::RenderWindow* window, std::stack<State*>* states)
	: State( window , states)
{
	this->font.loadFromFile("Fonts/ALGER.ttf");
	this->initText();
}

HighScore::~HighScore()
{

}

void HighScore::initText()
{
	this->text.setFont(this->font);
	this->text.setString("Read HighScore from file");
	this->text.setCharacterSize(30);
	this->text.setFillColor(sf::Color::White);
	this->text.setPosition(300, 300);

	this->text1.setFont(this->font);
	this->text1.setString("Press Escape to exit");
	this->text1.setCharacterSize(15);
	this->text1.setFillColor(sf::Color::White);
	this->text1.setPosition(10, 10);
}

void HighScore::renderText(sf::RenderTarget * target)
{
	this->window->draw(this->text);
	this->window->draw(this->text1);
}

void HighScore::endState()
{
}

void HighScore::updateInput(const float& dt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		this->states->pop();
	}
}

void HighScore::update(const float& dt)
{
	this->updateInput(dt);
}

void HighScore::render(sf::RenderTarget* target)
{
	this->renderText(target);
}
