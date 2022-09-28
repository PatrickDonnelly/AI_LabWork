#include "Npc.h"
#include "Math.h"

NPC::NPC(sf::Vector2f t_position)
{
	m_velocity = sf::Vector2f(0.0f, 0.0f);
	m_maximumVelocity = sf::Vector2f(200.0f, 200.0f);
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
	m_NPC.setOrigin(m_NPC.getGlobalBounds().width, m_NPC.getGlobalBounds().height);
	m_NPC.setScale(.4f, .4f);
}

//void NPC::move(sf::Time& t_deltaTime)
//{
//		m_velocity.y -= m_speed * t_deltaTime.asSeconds();
//}

void NPC::update(sf::Time& t_deltaTime)
{
	//move(t_deltaTime);
	//capNPCVelocity();
	//if (m_velocity.x > m_maximumVelocity.x) { m_velocity.x = m_maximumVelocity.x; }
	//if (m_velocity.y > m_maximumVelocity.y) { m_velocity.y = m_maximumVelocity.y; }
	m_NPC.move(m_velocity * t_deltaTime.asSeconds());
	//wrapScreen();
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
void NPC::kinematicSeek(sf::Vector2f t_targetPosition)
{
	if (t_targetPosition != m_NPC.getPosition())
	{
		sf::Vector2f t{ 0.0f,0.0f };
		t = t_targetPosition - m_NPC.getPosition();
		t = normaliseVector(t);
		m_velocity += t * m_speed;
		std::cout << "v x : " << m_velocity.x << " v y : " << m_velocity.y << std::endl;
		if (magnitudeVector(m_velocity) > 0.0f)
		{
		//	m_NPC.setRotation(atan2f(m_velocity.y, m_velocity.x) * (180 / 3.14f));
		}
	}
}

sf::Vector2f NPC::normaliseVector(sf::Vector2f t_vector)
{
	return t_vector / sqrt((t_vector.x * t_vector.x) + (t_vector.y * t_vector.y));
}

float NPC::magnitudeVector(sf::Vector2f t_vector)
{
	return sqrt((t_vector.x * t_vector.x) + (t_vector.y * t_vector.y));
}

void NPC::kinematicArrive(sf::Vector2f t_targetPosition)
{
	float l_stopRadius = 5.0f;
	float l_maxSpeed = 2.0f;
	float l_timeToTarget = 2.0f;
	if (t_targetPosition != m_NPC.getPosition())
	{
		m_velocity = t_targetPosition - m_NPC.getPosition();
		float l_speed = 0;
		float l_distance = magnitudeVector(m_velocity);
		if (l_distance <= l_stopRadius) { l_speed = 0; }
		else 
		{
			m_velocity = m_velocity / l_timeToTarget;
			if (magnitudeVector(m_velocity) > l_maxSpeed)
			{
				normaliseVector(m_velocity);
				m_velocity = m_velocity * l_maxSpeed;
			}
		}
	}
}

float NPC::getNewOrientation(float t_currentOrientation, sf::Vector2f t_velocity)
{
	if (magnitudeVector(t_velocity) > 0.0f) { return atan2f(m_position.y, m_position.x); }
	else { return t_currentOrientation; }
}
