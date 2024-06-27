#include "IceWizard.h"
#include"Cell.h"
#include"MapManager.h"
#include"Direction.h"

IceWizard::IceWizard(ENTITY_TYPE type, std::string renderString, COLOR color, int attackTime, int attackRange, int damage, int price)
{
	_type = type;
	_renderString = renderString;
	_color = color;
	_attackTime = attackTime;
	_attackRange = attackRange;
	_damage = damage;
	_price = price;
}

IceWizard::~IceWizard()
{
}

vector<Enemy*> IceWizard::defineTargets()
{
	vector<Enemy*> targetVec;
	Enemy* target = nullptr;
	int x = _currentPos.x - _attackRange / 2;
	int y = _currentPos.y - _attackRange / 2;
	for (int i = y; i < y + _attackRange; i++)
	{
		for (int j = x; j < x + _attackRange; j++)
		{
			Vector2 pos = Vector2(j, i);
			if (pos.x < 0 || pos.y < 0) continue;
			Cell* cell = GET_SINGLETON(MapManager)->getCell(pos);
			if (cell->type == MAP_TYPE::ROAD)
			{
				vector<Enemy*> vec = cell->getEntities<Enemy>(ENTITY_TYPE::ENEMY);
				for (auto i : vec)
				{
					if (target == nullptr)
					{
						target = i;
						continue;
					}
					if (target->getMoveCount() < i->getMoveCount())
					{
						target = i;
					}
				}
			}
		}
	}
	if (target != nullptr)
	{
		targetVec.push_back(target);
		target->getSlow(5000, 12000);
	}
	return targetVec;
}
