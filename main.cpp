#include <cstdlib>
#include <ctime>
#include "jeu/Game.hpp"


int main()
{
    // Gestion des accents
    system("chcp 65001 > nul"); 

    // Création de la seed pour toute la partie
    std::srand(std::time(nullptr));

    Game Jeu;

    Jeu.Run();

    return 0;
}


// Compilation :
// Build
// Lancement Jeu :
// cd build
// .\MiniRPG.exe