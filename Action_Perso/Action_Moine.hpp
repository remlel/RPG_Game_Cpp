#pragma once
#include <vector>
#include "../Personnages/moine.hpp"
#include <SFML/Window.hpp>

int Action_Moine(moine& monk, std::vector<Character*>& Team1, std::vector<Character*>& Team2, const sf::Event::KeyPressed* keyPress, int status, int choix);