#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class Player
{
	public:

		Player(sf::Vector2f t_position, unsigned int t_SCREEN_WIDTH, unsigned int t_SCREEN_HEIGHT);
		~Player();


		void capPlayerVelocity();
		void setUpPlayerSprite(sf::Vector2f t_position);
		void move(sf::Time& t_deltaTime);
		void update(sf::Time& t_deltaTime);
		void render(sf::RenderWindow& t_window);
		void wrapScreen();
	
	private:

		unsigned int m_screenWidth;
		unsigned int m_screenHeight;
		float m_rotationRate = 2.0f;
		const float PI = 3.14159f;
		const float GETRADIANS = 180;
		sf::Texture m_playerTexture;
		sf::Sprite m_player;
		sf::Vector2f m_velocity;
		float m_speed = 5.0f;
		sf::Vector2f m_maximumVelocity;
		sf::Vector2f m_direction;



};

