#include "Player.h"

Player::Player(sf::Vector2f t_position)
{
	m_velocity = sf::Vector2f(0.0f, 0.0f);
	m_maximumVelocity = sf::Vector2f(10.0f, 10.0f);
	setUpPlayerSprite(t_position);
}

Player::~Player()
{

}

// set a maximum velocity here for the player.
void Player::capPlayerVelocity()
{
	if (m_velocity.x > m_maximumVelocity.x) { m_velocity.x = m_maximumVelocity.x; }
	else if (m_velocity.x < -m_maximumVelocity.x) { m_velocity.x = -m_maximumVelocity.x; }
	if (m_velocity.y > m_maximumVelocity.y) { m_velocity.y = m_maximumVelocity.y; }
	else if (m_velocity.y < -m_maximumVelocity.y) { m_velocity.y = -m_maximumVelocity.y; }
}

void Player::setUpPlayerSprite(sf::Vector2f t_position)
{
	if (!m_playerTexture.loadFromFile("ASSETS\\IMAGES\\playerSprite.png"))
	{
		// simple error message if previous call fails
		std::cout << "problem loading player texture" << std::endl;
	}
	m_player.setTexture(m_playerTexture);
	m_player.setPosition(t_position);
}

void Player::move(sf::Time& t_deltaTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		m_velocity.y -= m_speed * t_deltaTime.asSeconds();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		m_velocity.y += m_speed * t_deltaTime.asSeconds();

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		//rotate here
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		//rotate here
	}
}

void Player::update(sf::Time& t_deltaTime)
{
	move(t_deltaTime);
	capPlayerVelocity();
	m_player.move(m_velocity);
	wrapScreen();
}

void Player::render(sf::RenderWindow& t_window)
{
	t_window.draw(m_player);
}

void Player::wrapScreen()
{
	if (m_player.getPosition().y < 0 - m_player.getGlobalBounds().height)
	{
		m_player.setPosition(m_player.getPosition().x, 600 + m_player.getGlobalBounds().height);
	}
	else if (m_player.getPosition().y > 800 + m_player.getGlobalBounds().height)
	{
		m_player.setPosition(m_player.getPosition().x, 0 - m_player.getGlobalBounds().height);
	}
}
