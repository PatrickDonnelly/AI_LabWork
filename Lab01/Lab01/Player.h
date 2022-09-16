#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class Player
{
	public:

		Player(sf::Vector2f t_position);
		~Player();

		void capPlayerVelocity();
		void setUpPlayerSprite(sf::Vector2f t_position);
		void move(sf::Time& t_deltaTime);
		void update(sf::Time& t_deltaTime);
		void render(sf::RenderWindow& t_window);
		void wrapScreen();
	
	private:

		sf::Texture m_playerTexture;
		sf::Sprite m_player;
		sf::Vector2f m_velocity;
		float m_speed = 5.0f;
		sf::Vector2f m_maximumVelocity;



};

