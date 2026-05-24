#include "Game.hpp"
#include <iostream>

// CONSTRUCTEUR

Game::Game()
    :
    window(sf::VideoMode({1200, 1000}), "Jeu RPG !"),
    data(Création_Equipe()),
    etat_actuel(CALCUL_TOUR),
    Perso_Actif(nullptr),
    choix(-1),

    t_g2(ma_police), t_g1(ma_police),
    t_w2(ma_police), t_w1(ma_police),
    t_m2(ma_police), t_m1(ma_police),
    victoire(ma_police), defaite(ma_police)

{
    window.setKeyRepeatEnabled(false);    


    // GUERRIER 1
    if (!tex_g1.loadFromFile("Upload/guerrier1.png")) {
        std::cout << "Erreur chargement image guerrier1" << std::endl;
    }
    gu1.setTexture(tex_g1, true);
    sf::Vector2u tailleg1 = tex_g1.getSize();
    gu1.setOrigin({
        tailleg1.x / 2.f,
        tailleg1.y / 2.f
    });
    gu1.setScale({
        180.f / tailleg1.x,
        180.f / tailleg1.y
    });
    gu1.setPosition({350.f, 700.f});

    // GUERRIER 2
    if (!tex_g2.loadFromFile("Upload/guerrier2.png")) {
        std::cout << "Erreur chargement image guerrier1" << std::endl;
    }
    gu2.setTexture(tex_g2, true);
    sf::Vector2u tailleg2 = tex_g2.getSize();
    gu2.setOrigin({
        tailleg2.x / 2.f,
        tailleg2.y / 2.f
    });
    gu2.setScale({
        180.f / tailleg2.x,
        180.f / tailleg2.y
    });
    gu2.setPosition({350.f, 320.f});

    // MAGE 1
    if (!tex_wi1.loadFromFile("Upload/wizard1.png")) {
        std::cout << "Erreur chargement image wizard1" << std::endl;
    }
    wi1.setTexture(tex_wi1, true);
    sf::Vector2u taillew1 = tex_wi1.getSize();
    wi1.setOrigin({
        taillew1.x / 2.f,
        taillew1.y / 2.f
    });
    wi1.setScale({
        180.f / taillew1.x,
        180.f / taillew1.y
    });
    wi1.setPosition({580.f, 700.f});

    // MAGE 2
    if (!tex_wi2.loadFromFile("Upload/wizard2.png")) {
        std::cout << "Erreur chargement image wizard1" << std::endl;
    }
    wi2.setTexture(tex_wi2, true);
    sf::Vector2u taillew2 = tex_wi2.getSize();
    wi2.setOrigin({
        taillew2.x / 2.f,
        taillew2.y / 2.f
    });
    wi2.setScale({
        180.f / taillew2.x,
        180.f / taillew2.y
    });
    wi2.setPosition({580.f, 320.f});

    // MOINE 1
    if (!tex_mo1.loadFromFile("Upload/monk1.png")) {
        std::cout << "Erreur chargement image monk1" << std::endl;
    }
    mo1.setTexture(tex_mo1, true);
    sf::Vector2u taillemo1 = tex_mo1.getSize();
    mo1.setOrigin({
        taillemo1.x / 2.f,
        taillemo1.y / 2.f
    });
    mo1.setScale({
        180.f / taillemo1.x,
        180.f / taillemo1.y
    });
    mo1.setPosition({850.f, 700.f});

    // MOINE 2
    if (!tex_mo2.loadFromFile("Upload/monk2.png")) {
        std::cout << "Erreur chargement image monk1" << std::endl;
    }
    mo2.setTexture(tex_mo2, true);
    sf::Vector2u taillemo2 = tex_mo2.getSize();
    mo2.setOrigin({
        taillemo2.x / 2.f,
        taillemo2.y / 2.f
    });
    mo2.setScale({
        180.f / taillemo2.x,
        180.f / taillemo2.y
    });
    mo2.setPosition({850.f, 320.f});


    // Chargement police d'écriture
    if (!ma_police.openFromFile("Upload/ALGER.TTF")) 
    {
        std::cout << "ERREUR POLICE !" << std::endl;
    }
    ma_police.setSmooth(true);
    int taille_police = 18;

    // Chargement fond d'écran
    if (!texture_fond.loadFromFile("Upload/arene1.png")) {
        std::cout << "Erreur chargement image fond" << std::endl;
    }
    fond.setTexture(texture_fond, true);

    // SCALE DU FOND 
    sf::Vector2u windowSize = window.getSize();
    sf::Vector2u textureSize = texture_fond.getSize();

    fond.setScale(
        sf::Vector2f(
            float(windowSize.x) / float(textureSize.x),
            float(windowSize.y) / float(textureSize.y)
        )
    );

    // Récupération des pointeurs spécifiques 
    guerrier* g1 = dynamic_cast<guerrier*>(data.Team1[0]);
    mage* w1 = dynamic_cast<mage*>(data.Team1[1]);
    moine* m1 = dynamic_cast<moine*>(data.Team1[2]);
    
    guerrier* g2 = dynamic_cast<guerrier*>(data.Team2[0]);
    mage* w2 = dynamic_cast<mage*>(data.Team2[1]);
    moine* m2 = dynamic_cast<moine*>(data.Team2[2]);

    t_g2.setString("Guerrier 2\nPV : " + std::to_string(g2->getPV()) + 
                   "\nPA : " + std::to_string(g2->getPointsAction()) + 
                   "\nCharges : " + std::to_string(g2->getCharge()) + 
                   "\nBoucliers : " + std::to_string(g2->getCapaBouclier()));
    t_g2.setCharacterSize(taille_police);
    t_g2.setFillColor(sf::Color::White);
    t_g2.setOrigin({t_g2.getLocalBounds().size.x / 2.f, 0.f}); 
    t_g2.setPosition({350.f, 80.f});
    t_g2.setStyle(sf::Text::Bold);

    t_w2.setString("Mage 2\nPV : " + std::to_string(w2->getPV()) + 
                   "\nPA : " + std::to_string(w2->getPointsAction()) + 
                   "\nMana : " + std::to_string(w2->getMana()) + " / " + std::to_string(w2->getMinMana()));
    t_w2.setCharacterSize(taille_police);
    t_w2.setFillColor(sf::Color::White);
    t_w2.setOrigin({t_w2.getLocalBounds().size.x / 2.f, 0.f});
    t_w2.setPosition({600.f, 80.f});
    t_w2.setStyle(sf::Text::Bold);

    t_m2.setString("Moine 2\nPV : " + std::to_string(m2->getPV()) + 
                   "\nPA : " + std::to_string(m2->getPointsAction()) + 
                   "\nSoin : " + std::to_string(m2->getHealingPV()));
    t_m2.setCharacterSize(taille_police);
    t_m2.setFillColor(sf::Color::White);
    t_m2.setOrigin({t_m2.getLocalBounds().size.x / 2.f, 0.f});
    t_m2.setPosition({850.f, 80.f});
    t_m2.setStyle(sf::Text::Bold);

    t_g1.setString("Guerrier 1\nPV : " + std::to_string(g1->getPV()) + 
                   "\nPA : " + std::to_string(g1->getPointsAction()) + 
                   "\nCharges : " + std::to_string(g1->getCharge()) + 
                   "\nBoucliers : " + std::to_string(g1->getCapaBouclier()));
    t_g1.setCharacterSize(taille_police);
    t_g1.setFillColor(sf::Color::White);
    t_g1.setOrigin({t_g1.getLocalBounds().size.x / 2.f, 0.f});
    t_g1.setPosition({350.f, 820.f});
    t_g1.setStyle(sf::Text::Bold);

    t_w1.setString("Mage 1\nPV : " + std::to_string(w1->getPV()) + 
                   "\nPA : " + std::to_string(w1->getPointsAction()) + 
                   "\nMana : " + std::to_string(w1->getMana()) + " / " + std::to_string(w1->getMinMana()));
    t_w1.setCharacterSize(taille_police);
    t_w1.setFillColor(sf::Color::White);
    t_w1.setOrigin({t_w1.getLocalBounds().size.x / 2.f, 0.f});
    t_w1.setPosition({600.f, 820.f});
    t_w1.setStyle(sf::Text::Bold);
    
    t_m1.setString("Moine 1\nPV : " + std::to_string(m1->getPV()) + 
                   "\nPA : " + std::to_string(m1->getPointsAction()) + 
                   "\nSoin : " + std::to_string(m1->getHealingPV()));
    t_m1.setCharacterSize(taille_police);
    t_m1.setFillColor(sf::Color::White);
    t_m1.setOrigin({t_m1.getLocalBounds().size.x / 2.f, 0.f});
    t_m1.setPosition({850.f, 820.f});
    t_m1.setStyle(sf::Text::Bold);

    victoire.setString("Victoire !");
    victoire.setCharacterSize(100);
    victoire.setFillColor(sf::Color::Green);
    victoire.setOrigin({victoire.getLocalBounds().size.x / 2.f, victoire.getLocalBounds().size.y / 2.f});
    victoire.setPosition({600.f, 500.f});

    defaite.setString("Defaite...");
    defaite.setCharacterSize(100);
    defaite.setFillColor(sf::Color::Red);
    defaite.setOrigin({defaite.getLocalBounds().size.x / 2.f, defaite.getLocalBounds().size.y / 2.f});
    defaite.setPosition({600.f, 500.f});

}

// DESTRUCTEUR

Game::~Game()
{
    // Delete de tous les Personnages
    for (Character* c : data.Team1)
    {
        delete c;
    }
    for (Character* c : data.Team2)
    {
        delete c;
    }
}

// METHODES

void Game::Run()
{

    while (window.isOpen())
    {
        TraiterEvenements();
        
        if (!IsTeamAlive(data.Team1) || !IsTeamAlive(data.Team2)) 
        {
            etat_actuel = FIN_PARTIE;
        }

        if (etat_actuel == CALCUL_TOUR) 
        {
            if (Perso_Actif != nullptr)
            {
                int NewPA = Perso_Actif->getPointsAction() - SEUIL;
                Perso_Actif->setPointsAction(NewPA);
            }

            // Annoncer les morts
            for (Character* Perso : data.AllCharacters)
            {
                if (!Perso->IsAlive())
                {
                    std::cout << Perso->getName() << " est mort !" << std::endl;
                }
            }

            //Mettre à jour AllCharacters
            data.AllCharacters.erase(
                std::remove_if(data.AllCharacters.begin(), data.AllCharacters.end(), [](Character* c) 
                { 
                    return !c->IsAlive(); 
                }
            ),
            data.AllCharacters.end()
            );

            //Mettre à jours les points d'actions 
            for (Character* Perso : data.AllCharacters)
            {
                int NewPA = Perso->getPointsAction() + Perso->getVitesse();
                Perso->setPointsAction(NewPA);
            }

            // Détermination du personnage dont c'est le tour
            std::vector<Character*> Perso_MaxPoints = Liste_Persos_Actifs(data.AllCharacters);
            Perso_Actif = Tour_Character(Perso_MaxPoints);

            if (std::find(data.Team2.begin(), data.Team2.end(), Perso_Actif) != data.Team2.end())
            {
                etat_actuel = TOUR_IA;
            }

            else if (std::find(data.Team1.begin(), data.Team1.end(), Perso_Actif) != data.Team1.end())
            {
                etat_actuel = TOUR_JOUEUR_CHOIX_ACTION;
                
                std::cout << "\n=====================================" << std::endl;
                std::cout << "[Ton Tour] Action de " << Perso_Actif->getName() << " :" << std::endl;
                std::cout << "=====================================\n" << std::endl;

                Actions_Possibles(Perso_Actif, data.Team1);
            }
        }

        

        else if (etat_actuel == TOUR_IA) 
        {
            std::cout << "\n-------------------------------------" << std::endl;
            std::cout << "[Tour de l'adversaire] Action de " << Perso_Actif->getName() << " :" << std::endl;
            std::cout << "-------------------------------------\n" << std::endl;

            // Action du Guerrier
            if (guerrier* warrior = dynamic_cast<guerrier*>(Perso_Actif))
            {
                Automate_Guerrier(*warrior, data.Team1, data.Team2);
            }
            
            // Action du Mage
            if (mage* wizard = dynamic_cast<mage*>(Perso_Actif))
            {
                wizard->setMana(wizard->getMana() + wizard->getIQ());
                Automate_Mage(*wizard, data.Team1);
            }

            // // Action du Moine
            if (moine* monk = dynamic_cast<moine*>(Perso_Actif))
            {
                Automate_Moine(*monk, data.Team1, data.Team2);
            }

            // Désactivation du Bouclier de l'équipe 1 à la fin du tour de l'équipe 2
            for (Character* Membre : data.Team1)
            {
                Membre->setDefenseBonus(0);
            }

            etat_actuel = CALCUL_TOUR;
        }

        else if (etat_actuel == TOUR_JOUEUR_CHOIX_ACTION || etat_actuel == TOUR_JOUEUR_CHOIX_CIBLE)
        {

        }

        AfficherEcran();
    }

}

void Game::TraiterEvenements()
{
    while (const std::optional<sf::Event> event = window.pollEvent())
    {
        if (event->is<sf::Event::Closed>())
            {
                window.close(); // Ferme la fenêtre si on clique sur la croix
            }

            if (etat_actuel == TOUR_JOUEUR_CHOIX_ACTION)
            {
                if (const auto* keyPress = event->getIf<sf::Event::KeyPressed>())
                { 
                    // Action du Guerrier
                    if (guerrier* warrior = dynamic_cast<guerrier*>(Perso_Actif))
                    { 
                        choix = Action_Guerrier(*warrior, data.Team1, data.Team2, keyPress, 0, 0);
                    }
            
                    // Action du Mage
                    if (mage* wizard = dynamic_cast<mage*>(Perso_Actif))
                    {
                        wizard->setMana(wizard->getMana() + wizard->getIQ());
                        choix = Action_Mage(*wizard, data.Team2, keyPress, 0, 0);
                    }

                    // Action du Moine
                    if (moine* monk = dynamic_cast<moine*>(Perso_Actif))
                    {
                        choix = Action_Moine(*monk, data.Team1, data.Team2, keyPress, 0, 0);
                    }

                    if (choix != -1) 
                    {
                        etat_actuel = TOUR_JOUEUR_CHOIX_CIBLE;
                    } 
                }
            }

            else if (etat_actuel == TOUR_JOUEUR_CHOIX_CIBLE)
            {
                if (const auto* keyPress = event->getIf<sf::Event::KeyPressed>())
                {
                    int result_A = 1;

                    // Action du Guerrier
                    if (guerrier* warrior = dynamic_cast<guerrier*>(Perso_Actif))
                    {
                        result_A = Action_Guerrier(*warrior, data.Team1, data.Team2, keyPress, 1, choix);
                    }
            
                    // Action du Mage
                    if (mage* wizard = dynamic_cast<mage*>(Perso_Actif))
                    {
                        wizard->setMana(wizard->getMana() + wizard->getIQ());
                        result_A = Action_Mage(*wizard, data.Team2, keyPress, 1, choix);
                    }

                    // Action du Moine
                    if (moine* monk = dynamic_cast<moine*>(Perso_Actif))
                    {
                        result_A = Action_Moine(*monk, data.Team1, data.Team2, keyPress, 1, choix);
                    }

                    
                    // Désactivation du Bouclier de l'équipe 2 à la fin du tour de l'équipe 1
                    for (Character* Membre : data.Team2)
                    {
                        Membre->setDefenseBonus(0);
                    }

                    if (result_A == 0)
                    {
                        etat_actuel = CALCUL_TOUR;
                    }
                }
            }
    }
}
     

void Game::MettreAJourStats()
{
    // Récupération des pointeurs spécifiques 
    guerrier* g1 = dynamic_cast<guerrier*>(data.Team1[0]);
    mage* w1 = dynamic_cast<mage*>(data.Team1[1]);
    moine* m1 = dynamic_cast<moine*>(data.Team1[2]);
    
    guerrier* g2 = dynamic_cast<guerrier*>(data.Team2[0]);
    mage* w2 = dynamic_cast<mage*>(data.Team2[1]);
    moine* m2 = dynamic_cast<moine*>(data.Team2[2]);

    t_g2.setString("Guerrier 2\nPV : " + std::to_string(g2->getPV()) + "\nPA : " + std::to_string(g2->getPointsAction()) + 
                   "\nCharges : " + std::to_string(g2->getCharge()) + "\nBoucliers : " + std::to_string(g2->getCapaBouclier()));
    t_w2.setString("Mage 2\nPV : " + std::to_string(w2->getPV()) + "\nPA : " + std::to_string(w2->getPointsAction()) + 
                   "\nMana : " + std::to_string(w2->getMana()) + " / " + std::to_string(w2->getMinMana()));
    t_m2.setString("Moine 2\nPV : " + std::to_string(m2->getPV()) + "\nPA : " + std::to_string(m2->getPointsAction()) + 
                   "\nSoin : " + std::to_string(m2->getHealingPV()));

    t_g1.setString("Guerrier 1\nPV : " + std::to_string(g1->getPV()) + "\nPA : " + std::to_string(g1->getPointsAction()) + 
                   "\nCharges : " + std::to_string(g1->getCharge()) + "\nBoucliers : " + std::to_string(g1->getCapaBouclier()));
    t_w1.setString("Mage 1\nPV : " + std::to_string(w1->getPV()) + "\nPA : " + std::to_string(w1->getPointsAction()) + 
                   "\nMana : " + std::to_string(w1->getMana()) + " / " + std::to_string(w1->getMinMana()));
    t_m1.setString("Moine 1\nPV : " + std::to_string(m1->getPV()) + "\nPA : " + std::to_string(m1->getPointsAction()) + 
                   "\nSoin : " + std::to_string(m1->getHealingPV()));
}  

void Game::AfficherEcran()
{
    window.clear();
    window.draw(fond);
    
    if (etat_actuel == FIN_PARTIE)
    {
        
            if(!IsTeamAlive(data.Team2))
            {
                window.draw(victoire);
            }
            else
            {
                window.draw(defaite);
            }
            
    }

    else
    {
        MettreAJourStats();

        // Equipe 2
        window.draw(gu2);
        window.draw(wi2);
        window.draw(mo2);
        window.draw(t_g2);
        window.draw(t_w2);
        window.draw(t_m2);

        // Equipe 1
        window.draw(gu1);
        window.draw(wi1);
        window.draw(mo1);
        window.draw(t_g1);
        window.draw(t_w1);
        window.draw(t_m1);
    }
    
    window.display();
}