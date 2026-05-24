#pragma once
#include <SFML/Window.hpp>
#include "../Personnages/guerrier.hpp"

int Action_Guerrier(guerrier& guerrier, std::vector<Character*>& Team1, std::vector<Character*>& Team2, const sf::Event::KeyPressed* keyPress, int status, int choix);