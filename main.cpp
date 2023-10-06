#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "avion.h"


//Propiedades de la ventana
const int ANCHO_VENTANA = 800;
const int ALTO_VENTANA = 750;

//Propiedades del avion
const int ANCHO_AVION = 10;
const int ALTO_AVION = 10;

//Propiedades de la bala
const int ANCHO_BALA = 100;
const int ALTO_BALA = 100;
const int VELOCIDAD_BALA = 5;

int main()
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(ANCHO_VENTANA, ALTO_VENTANA), "Sky Fury");

    window.setFramerateLimit(60);

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


        avion.mover_avion(window); //Actualizar la lógica del juego
        window.clear(); //Limpiar la ventana para borrar el contenido anterior.
        avion.pintar_avion(window); //Representar los objetos del juego en la ventana.
        window.display(); //Mostrar la ventana para que el jugador pueda ver el resultado.
    }

    return EXIT_SUCCESS;
    return 0;
}