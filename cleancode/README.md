# Clean Code & Clean Architecture C++17

Starter du TP de 1h30, sans Unreal Engine. Le projet utilise CMake et doctest
inclus localement; aucune dependance a telecharger n'est requise pour compiler.
La copie de doctest est la version 2.4.11, distribuee sous sa licence MIT dans
`tests/doctest-LICENSE.txt`.

## Organisation des sources

```text
src/
├── domain/       # Contrats et regles metier independants
├── characters/   # Implementations Warrior, Archer et Mage
├── factory/      # Creation polymorphique des personnages
└── application/  # Orchestration des tours de jeu
tests/            # Tests d'acceptation doctest
```

## Prerequis

- Compilateur C++17 (Visual Studio 2022, GCC ou Clang)
- CMake 3.15 ou plus recent
- Git

## Compiler et lancer les tests

Depuis le dossier `cleancode` :

```sh
cmake -S . -B build
cmake --build build
ctest --test-dir build -C Debug --output-on-failure
```

Le build doit reussir d'emblee. Au depart, les tests des exercices sont rouges.
Ils sont listes sous `Ex1`, `Ex2` et `Ex3` dans la sortie doctest.

## Avec Visual Studio

1. Ouvrir Visual Studio 2022.
2. Choisir **Fichier > Ouvrir > Dossier** et ouvrir le dossier `cleancode`.
3. Visual Studio detecte le `CMakeLists.txt`.
4. Choisir **Générer > Générer tout** (**Build > Build All**).
5. Ouvrir **Test > Explorateur de tests** (**Test > Test Explorer**) pour
   afficher les trois tests unitaires `Ex1`, `Ex2` et `Ex3`. Au depart, ils
   doivent apparaitre en rouge (en échec).

## Exercices

### Exercice 1 - Guard clauses et DRY

Fichiers : `src/characters/Warrior.cpp`, `src/domain/CombatRules.h`.

- Ignorer les degats nuls ou negatifs.
- Ne plus appliquer de degats a un personnage mort.
- Borner l'armure entre 0 et 1.
- Centraliser le calcul dans `CombatRules::CalculateDamage`.
- Remplacer les imbrications par des retours anticipes.

```sh
ctest --test-dir build -C Debug -R Ex1 --output-on-failure
```

### Exercice 2 - Fabrique, polymorphisme et RAII

Fichiers : `src/factory/CharacterFactory.cpp`, `src/application/GameSystem.cpp`.

- Creer un Warrior, Archer ou Mage depuis `CharacterType`.
- Retourner `std::unique_ptr<ICharacter>`.
- Retourner un pointeur vide pour une valeur inconnue.
- Faire appeler `Attack()` a GameSystem sans dependance aux classes concretes.

```sh
ctest --test-dir build -C Debug -R Ex2 --output-on-failure
```

### Exercice 3 - Composition

Fichiers : `src/domain/RangedAttackComponent.h`,
`src/characters/Archer.h/.cpp`, `src/characters/Mage.h/.cpp`.

- Valider les tirs selon la distance et la portee maximale.
- Creer un `RangedAttackComponent` pour Archer et Mage.
- Garder Warrior sans capacite a distance.

```sh
ctest --test-dir build -C Debug -R Ex3 --output-on-failure
```

Ne modifiez pas `tests/TestMain.cpp` ou `tests/doctest.h`. Les tests sont les
criteres d'acceptation. Le cycle attendu est Rouge -> Vert -> Refactor.
