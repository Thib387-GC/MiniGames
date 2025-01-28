#pragma once

#include "Alive.h"
#include "Collidable.h"
#include "IAttacker.h"
#include "Entity.h"


class Character : public Alive, public Collidable, public IAttacker, public Entity
{
public:

	float posX;
	float posY;

	void attack(Alive*);
	virtual void SpaceShipCreate(int NumModule);

};
