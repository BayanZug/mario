#pragma once
#include "Utilities.h"
#include "Resources.h"
#include "StaticObjects.h"

//-----------------------------------------------------------------
//This is  Extra Accesorios Class where there the control
// of all about the Accesorios thing. 	
//-----------------------------------------------------------------
class ExtraAccesorios:public StaticObjects <extraAccesorios_type_t> 
{
public:
	ExtraAccesorios(sf::Vector2f& location, extraAccesorios_type_t eat, int worldNum) : StaticObjects(location, eat, worldNum) 
	{
		m_sprite.setTexture(Resources::loadResources().getWorldTexture(worldNum));
		m_sprite.setTextureRect(Resources::loadResources().getExtraAccesorios(worldNum)[(int)eat]);
		location.y += 7;
		m_sprite.setPosition(location);
		m_sprite.setOrigin(m_sprite.getTextureRect().width / 2.0f, m_sprite.getTextureRect().height/ 2.0f);
		setLocation(m_sprite.getPosition());
		int randomSide = rand() % 2;
		if (randomSide == 0)
			m_sprite.setScale(-1, 1);
		else m_sprite.setScale(1, 1);
	}
	~ExtraAccesorios() = default;
	virtual void animation(float deltaTime) override {}
	virtual void move(float deltaTime) override {}
};