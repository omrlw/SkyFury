#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "avion.h"
#include "bala.h"
#include "enemigo.h"

//Propiedades de la ventana
const int ANCHO_VENTANA = 800;
const int ALTO_VENTANA = 750;

int main()
{
    // Creamos la ventana y le damos un título
    // sf::RenderWindow hereda de sf::Window
    sf::RenderWindow window(sf::VideoMode(ANCHO_VENTANA, ALTO_VENTANA), "Sky Fury");
    // Limitamos la tasa de actualiazcion de la ventana
    window.setFramerateLimit(60);


    Avion avion(100, 100, 3, 3);
    Bala bala (100,110,1,10);

    // Bucle principal del juego
    while (window.isOpen()) {
        sf::Event event{}; //Inicializar el objetos tipo Evento
        while (window.pollEvent(event)) { //Verificar si hay eventos en la ventana
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
}