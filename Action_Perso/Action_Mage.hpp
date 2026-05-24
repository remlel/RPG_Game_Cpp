#pragma once
#include "../Personnages/mage.hpp"
#include <SFML/Window.hpp>

int Action_Mage(mage& wizard, std::vector<Character*>& Team2, const sf::Event::KeyPressed* keyPress, int status, int choix);

