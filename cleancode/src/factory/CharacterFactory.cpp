#include "factory/CharacterFactory.h"

#include "characters/Archer.h"
#include "characters/Mage.h"
#include "characters/Warrior.h"

//C'est le "moteur" de la fabrique. Il fait tout le travail sale de sélection et d'instanciation pour épargner le reste de l'application
std::unique_ptr<ICharacter> CharacterFactory::CreateCharacter(CharacterType Type)
{
	// TODO EXERCICE 2 : creer le type concret demandé.
	(void)Type;
	return nullptr;
}
