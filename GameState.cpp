#include "GameState.h"



GameState::GameState(sf::RenderWindow* window, std::stack<State*>* states)
	: State(window, states)
{
	this->font.loadFromFile("Fonts/ALGER.ttf");
	this->initText();
	//buttons
	this->initButtons();
}

GameState::~GameState()
{
	auto it = this->buttons.begin();
	for (it = this->buttons.begin(); it != this->buttons.end(); ++it)
	{
		delete it->second;
	}
}

void GameState::initButtons()
{
	this->buttons["MainMenu"] = new Button(100, 100, 150, 50, &this->font, "MainMenu", sf::Color::Red,
		sf::Color::Blue, sf::Color::White);
}

void GameState::updateButtons()
{
	for (auto& it : buttons)
	{
		it.second->update(this->mousePosView);
	}
	//if (this->buttons["MainMenu"]->isPressed())
	//{
	//	this->states->pop();
	//}
}

void GameState::renderButtons(sf::RenderTarget* target)
{
	for (auto& it : buttons)
	{
		it.second->render(target);
	}
}

void GameState::initText()
{
	this->text.setFont(this->font);
	this->text.setString("Load qn from file");
	this->text.setCharacterSize(30);
	this->text.setPosition(200, 300);
	this->text.setFillColor(sf::Color::White);

	this->text1.setFont(this->font);
	this->text1.setString("Press esc to exit");
	this->text1.setCharacterSize(15);
	this->text1.setPosition(10, 100);
	this->text1.setFillColor(sf::Color::White);
}

void GameState::renderText(sf::RenderTarget* target)
{
	target->draw(this->text);
	target->draw(this->text1);
}

void GameState::endstate()
{
}

void GameState::updateInput(const float& dt)
{
	this->checkForQuit();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
	{
		this->states->pop();
	}
	//update inputs of player
}

void GameState::update(const float& dt)
{
	this->updateInput(dt);
	this->updateMousePosition();

	this->updateButtons();
}

void GameState::render(sf::RenderTarget* target)
{
	if (!target)
	target = (this->window);
	
	this->renderText(target);
	//this->renderButtons(target);
}
