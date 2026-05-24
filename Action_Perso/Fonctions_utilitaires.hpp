#pragma once
#include <vector>
#include <SFML/Window.hpp>
#include "../Personnages/character.hpp"


int Choix_Player(int max, const sf::Event::KeyPressed* keyPress);

Character* ChoixCible(std::vector<Character*>& Team, const sf::Event::KeyPressed* keyPress);

int Attaque(std::vector<Character*>& Team, Character* perso, const sf::Event::KeyPressed* keyPress);

void Affichage_Attaque(std::vector<Character*>& Team);



