#pragma once

#include <algorithm>

namespace CombatRules
{
inline float CalculateDamage(float RawDamage, float Armor)
{
	if (RawDamage <= 0.0f)
	{
		return 0.0f;
	}

	// TODO EXERCICE 1 : borner l'armure puis retourner les degats apres armure.
	return RawDamage;
}
}
