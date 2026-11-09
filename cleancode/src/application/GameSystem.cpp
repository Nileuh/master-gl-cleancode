#include "application/GameSystem.h"

#include "factory/CharacterFactory.h"

//la centralisation de la logique de création et le découplage
std::string GameSystem::RunTurn(CharacterType Type) const
{
	// TODO EXERCICE 2 : avec ICharacter demander à la frabrique de créer un personnage et appeler Attack()
	// sans connaitre les classes concretes.
	(void)Type;

	// si pas de personnage créé, retourner une chaîne vide
	return {};
}
