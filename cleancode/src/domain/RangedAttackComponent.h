#pragma once

class RangedAttackComponent
{
public:
	explicit RangedAttackComponent(float MaxRange)
		: maxRange(MaxRange)
	{
	}

	bool CanHit(float Distance) const
	{
		// TODO EXERCICE 3 : valider distance et portee maximale.
		return false;
	}

	float GetMaxRange() const
	{
		return maxRange;
	}

private:
	float maxRange;
};
