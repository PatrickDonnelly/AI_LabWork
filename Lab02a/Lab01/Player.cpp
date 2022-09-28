#include "Player.h"

Player::Player(sf::Vector2f t_position, unsigned int t_SCREEN_WIDTH, unsigned int t_SCREEN_HEIGHT)
{
	m_velocity = sf::Vector2f(0.0f, 0.0f);
	m_maximumVelocity = sf::Vector2f(7.0f, 7.0f);
	m_screenWidth = t_SCREEN_WIDTH;
	m_screenHeight = t_SCREEN_HEIGHT;


	setUpPlayerSprite(t_position);
	m_player.setOrigin(m_playerTexture.getSize().x / 2.0f, m_playerTexture.getSize().y / 2.0f);
	m_player.setScale(sf::Vector2f{0.5f,0.5f});
	m_player.setRotation(0);
	m_direction.x = -sin((PI / GETRADIANS) * m_player.getRotation());
	m_direction.y = cos((PI / GETRADIANS) * m_player.getRotation());
	
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
		m_velocity -= (m_direction * m_speed) * t_deltaTime.asSeconds();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		m_velocity += (m_direction * m_speed) * t_deltaTime.asSeconds();

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		m_player.rotate(-m_rotationRate);
		m_direction.x = -sin((PI / GETRADIANS) * m_player.getRotation());
		m_direction.y = cos((PI / GETRADIANS) * m_player.getRotation());
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		m_player.rotate(m_rotationRate);
		std::cout << m_player.getRotation() << std::endl;
		m_direction.x = -sin((PI / GETRADIANS) * m_player.getRotation());
		m_direction.y = cos((PI / GETRADIANS) * m_player.getRotation());
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
		m_player.setPosition(m_player.getPosition().x, m_screenHeight + m_player.getGlobalBounds().height);
	}
	else if (m_player.getPosition().y > m_screenHeight + m_player.getGlobalBounds().height)
	{
		m_player.setPosition(m_player.getPosition().x, 0 - m_player.getGlobalBounds().height);
	}
	else if (m_player.getPosition().x < 0 - m_player.getGlobalBounds().width)
	{
		m_player.setPosition(m_screenWidth + m_player.getGlobalBounds().width, m_player.getPosition().y);
	}
	else if (m_player.getPosition().x > m_screenWidth + m_player.getGlobalBounds().width)
	{
		m_player.setPosition(0 - m_player.getGlobalBounds().width, m_player.getPosition().y);
	}
}
