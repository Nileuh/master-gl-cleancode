#include "characters/Warrior.h"

#include <algorithm>

Warrior::Warrior(float MaximumHealth, float Armor)
	: maximumHealth((std::max)(0.0f, MaximumHealth)),
	  health(maximumHealth),
	  armor(Armor)
{
}

std::string Warrior::Attack()
{
	return "Warrior attacks with a sword";
}

std::string Warrior::GetCharacterName() const
{
	return "Warrior";
}

void Warrior::TakeDamage(float RawDamage)
{
	// TODO EXERCICE 1 : remplacer les imbrications par des guard clauses.
	if (health > 0.0f)
	{
		if (RawDamage >= 0.0f)
		{
			// TODO EXERCICE 1 : extraire cette formule dans
			// CombatRules::CalculateDamage et reutiliser cette fonction.
			health -= RawDamage * (1.0f - armor);
			if (health < 0.0f)
			{
				health = 0.0f;
			}
		}
	}
}

float Warrior::GetHealth() const
{
	return health;
}

float Warrior::GetArmor() const
{
	return armor;
}
