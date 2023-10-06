#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "avion.h"

//Propiedades de la ventana
const int ANCHO_VENTANA = 800;
const int ALTO_VENTANA = 750;

//Propiedades del avion
const int ANCHO_AVION = 200;
const int ALTO_AVION = 200;

//Propiedades de la bala
const int ANCHO_BALA = 100;
const int ALTO_BALA = 100;
const int VELOCIDAD_BALA = 5;

int main()
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(ANCHO_VENTANA, ALTO_VENTANA), "Sky Fury");

    // Load a sprite to display
    sf::Texture texture;

    sf::Sprite sprite(texture);

    // Create a graphical text to display
    sf::Font font;

    sf::Text text("Hello SFML", font, 50);

    Avion avion(100, 100, 3, 3);


    // Start the game loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        avion.mover_avion(window);

        window.clear();
        avion.pintar_avion(window);
        window.display();
    }

    return EXIT_SUCCESS;
}