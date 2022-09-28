#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class NPC
{
public:

	NPC(sf::Vector2f t_position);
	~NPC();

	void capNPCVelocity();
	void setUpNPCSprite(sf::Vector2f t_position);
	void move(sf::Time& t_deltaTime);
	void update(sf::Time& t_deltaTime);
	void render(sf::RenderWindow& t_window);
	void wrapScreen();

private:

	sf::Texture m_NPCTexture;
	sf::Sprite m_NPC;
	sf::Vector2f m_velocity;
	float m_speed = 5.0f;
	sf::Vector2f m_maximumVelocity;



};
