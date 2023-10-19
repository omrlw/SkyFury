#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

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

    // Bucle principal del juego
    while (window.isOpen()) {
        sf::Event event{}; //Inicializar el objetos tipo Evento
        while (window.pollEvent(event)) { //Verificar si hay eventos en la ventana
            if (event.type == sf::Event::Closed) {
                window.close();
                }
            }

        window.clear(); //Limpiar la ventana para borrar el contenido anterior.

        window.display(); //Mostrar la ventana para que el jugador pueda ver el resultado.



    }

    return EXIT_SUCCESS;
}