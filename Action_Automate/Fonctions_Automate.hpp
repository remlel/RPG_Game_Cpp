#pragma once
#include <vector>
#include "../Personnages/character.hpp"

Character* Choix_IA_Attack(std::vector<Character*>& Team);

void Attack(Character* Perso, Character* Target);