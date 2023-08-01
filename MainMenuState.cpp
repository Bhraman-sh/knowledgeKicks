#include "MainMenuState.h"

void MainMenuState::initFonts()
{
	//if (!this->font.loadFromFile("Fonts/ALGER.ttf"));
	//{
	//	throw("ERROR::COULD NOT LOAD FONTS");
	//}
}

MainMenuState::MainMenuState(sf::RenderWindow* window, std::stack<State*>* states)
	: State(window, states)
{
	
	this->font.loadFromFile("Fonts/ALGER.ttf");
	this->initButtons();
	this->background.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
	this->background.setFillColor(sf::Color::Magenta);
	
}


MainMenuState::~MainMenuState()
{
	auto it = this->buttons.begin();
	for (it = this->buttons.begin(); it != this->buttons.end(); ++it)
	{
		delete it->second;
	}
}



void MainMenuState::initButtons()
{
	this->buttons["Gamestate"] = new Button(100, 100, 150, 50, &this->font, "Start game", sf::Color::Red,
		sf::Color::Blue, sf::Color::White);
	this->buttons["HighScore"] = new Button(100, 400, 150, 50, &this->font, "Highscore", sf::Color::Red,
		sf::Color::Blue, sf::Color::White);
}

void MainMenuState::updateButtons()
{
	//this->gamestate_btn->update(this->mousePosView);
	for (auto& it : buttons)
	{
		it.second->update(this->mousePosView); 
	}
	//quit the state

	if (this->buttons["Gamestate"]->isPressed())
	{
		this->states->push(new GameState(this->window, this->states));
	}
	if (this->buttons["HighScore"]->isPressed())
	{
		this->states->push(new HighScore(this->window, this->states));
	}

}

void MainMenuState::renderButtons(sf::RenderTarget* target)
{
	//this->gamestate_btn->render(target);
	for (auto& it : buttons)
	{
		it.second->render(target);
	}
}

void MainMenuState::endstate()
{
}

void MainMenuState::updateInput(const float& dt)
{
	this->checkForQuit();


	////update inputs of player
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
	//{
	//	this->player.move(dt, -0.1f, 0.f);
	//}
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
	//{
	//	this->player.move(dt, 0.f, -0.1f);
	//}
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
	//{
	//	this->player.move(dt, 0.f, 0.1f);
	//}
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
	//{
	//	this->player.move(dt, 0.1f, 0.f);
	//}
}

void MainMenuState::update(const float& dt)
{
	this->updateInput(dt);
	this->updateMousePosition();

	this->updateButtons();



	//std::cout << this->mousePosWindow.x << " " << mousePosWindow.y << std::endl;
}

void MainMenuState::render(sf::RenderTarget* target)
{
	if (!target)
		target = (this->window);

	target->draw(this->background);

	this->renderButtons(target);

	
}
