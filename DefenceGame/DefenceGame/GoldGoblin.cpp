#include "GoldGoblin.h"
#include "WaveManager.h"
#include "Enemy.h"
#include "Define.h"

GoldGoblin::GoldGoblin(ENTITY_TYPE type, std::string renderString, COLOR color, int hp, int moveTime, int rewardGold)
{
	_type = type;
	_renderString = renderString;
	_color = color;
	_hp = std::round((float)hp * (float)(1 + GET_SINGLETON(WaveManager)->getCurrentWave() / 7.0f));
	_moveTime = moveTime;
	_defaultMoveTime = moveTime;
	_rewardGold = rewardGold;
	_originColor = _color;
}
