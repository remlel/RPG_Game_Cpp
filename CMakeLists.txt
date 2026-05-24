cmake_minimum_required(VERSION 3.10)
project(MiniRPG)

# CMake récupère tous les fichiers .cpp 
file(GLOB SOURCES 
    "*.cpp" 
    "Personnages/*.cpp" 
    "Action_Perso/*.cpp" 
    "Action_Automate/*.cpp"
    "jeu/*.cpp"
)

# Création de l'exécutable à partir de ces fichiers
add_executable(MiniRPG ${SOURCES})

# CMake récupère la librairie SFML installée
find_package(SFML 3 COMPONENTS Graphics Window System REQUIRED)

# Liaison du jeu avec la SFML
target_link_libraries(MiniRPG PRIVATE SFML::Graphics SFML::Window SFML::System)

file(COPY Upload DESTINATION ${CMAKE_BINARY_DIR})