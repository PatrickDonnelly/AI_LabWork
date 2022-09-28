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
	void update(sf::Time& t_deltaTime);
	void render(sf::RenderWindow& t_window);
	void wrapScreen();

	sf::Vector2f m_position{ 0.0f, 0.0f };
	sf::Vector2f m_velocity{ 0.0f,0.0f };
	float m_orientation{ 0.0f };
	float m_rotation{ 0.0f };
	float getNewOrientation(float t_currentOrientation, sf::Vector2f t_velocity);
	void kinematicSeek(sf::Vector2f t_targetPosition);
	void kinematicArrive(sf::Vector2f t_targetPosition);
	sf::Vector2f normaliseVector(sf::Vector2f t_vector);
	float magnitudeVector(sf::Vector2f t_vector);

private:

	sf::Texture m_NPCTexture;
	sf::Sprite m_NPC;
	float m_speed = 5.0f;
	sf::Vector2f m_maximumVelocity;



};
