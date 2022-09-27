#include "Npc.h"

NPC::NPC(sf::Vector2f t_position)
{
	m_velocity = sf::Vector2f(0.0f, 0.0f);
	m_maximumVelocity = sf::Vector2f(10.0f, 10.0f);
	setUpNPCSprite(t_position);
}

NPC::~NPC()
{

}

// set a maximum velocity here for the player.
void NPC::capNPCVelocity()
{
	if (m_velocity.x > m_maximumVelocity.x) { m_velocity.x = m_maximumVelocity.x; }
	else if (m_velocity.x < -m_maximumVelocity.x) { m_velocity.x = -m_maximumVelocity.x; }
	if (m_velocity.y > m_maximumVelocity.y) { m_velocity.y = m_maximumVelocity.y; }
	else if (m_velocity.y < -m_maximumVelocity.y) { m_velocity.y = -m_maximumVelocity.y; }
}

void NPC::setUpNPCSprite(sf::Vector2f t_position)
{
	if (!m_NPCTexture.loadFromFile("ASSETS\\IMAGES\\NPCSprite.png"))
	{
		// simple error message if previous call fails
		std::cout << "problem loading player texture" << std::endl;
	}
	m_NPC.setTexture(m_NPCTexture);
	m_NPC.setPosition(t_position);
}

void NPC::move(sf::Time& t_deltaTime)
{
		m_velocity.y -= m_speed * t_deltaTime.asSeconds();
}

void NPC::update(sf::Time& t_deltaTime)
{
	move(t_deltaTime);
	capNPCVelocity();
	m_NPC.move(m_velocity);
	wrapScreen();
}

void NPC::render(sf::RenderWindow& t_window)
{
	t_window.draw(m_NPC);
}

void NPC::wrapScreen()
{
	if (m_NPC.getPosition().y < 0 - m_NPC.getGlobalBounds().height)
	{
		m_NPC.setPosition(m_NPC.getPosition().x, 600 + m_NPC.getGlobalBounds().height);
	}
	else if (m_NPC.getPosition().y > 800 + m_NPC.getGlobalBounds().height)
	{
		m_NPC.setPosition(m_NPC.getPosition().x, 0 - m_NPC.getGlobalBounds().height);
	}
}