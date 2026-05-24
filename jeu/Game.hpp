#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <optional>
#include "../Personnages/Personnages.hpp"
#include "fonction.hpp"
#include "../Action_Perso/Action_Persos.hpp"
#include "../Action_Automate/Actions_Automate.hpp"
#include <algorithm>



class Game
{

private:
    
    // ATTRIBUTS (PRIVATE)

    sf::RenderWindow window;
    GameData data;
    GameState etat_actuel;
    Character* Perso_Actif;
    int choix;

    sf::Texture tex_g1;
    sf::Texture tex_g2;
    sf::Texture tex_wi1;
    sf::Texture tex_wi2;
    sf::Texture tex_mo1;
    sf::Texture tex_mo2;
    sf::Texture texture_fond;

    sf::Sprite gu1{tex_g1};
    sf::Sprite gu2{tex_g2};
    sf::Sprite wi1{tex_wi1};
    sf::Sprite wi2{tex_wi2};
    sf::Sprite mo1{tex_mo1};
    sf::Sprite mo2{tex_mo2};
    sf::Sprite fond{texture_fond};

    sf::Font ma_police;
    sf::Text t_g2;
    sf::Text t_g1;
    sf::Text t_w2;
    sf::Text t_w1;
    sf::Text t_m2;
    sf::Text t_m1;
    sf::Text victoire;
    sf::Text defaite;

public:

    // CONSTRUCTEUR
    Game();

    //METHODE
    void Run();

    ~Game();

private:

    void TraiterEvenements();              // Pour le clavier
    void MettreAJourStats();               // Pour actualiser les textes
    void AfficherEcran();                  // Pour faire les window.draw()

};