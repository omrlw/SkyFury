#ifndef INCLUDE_JUEGO_HPP
#define INCLUDE_JUEGO_HPP

#include <SFML/Graphics.hpp>

class Game : private sf::NonCopyable{
public:
    Game();
    void run();

private:

    //Metodos privados
    void procesosEvento();
    void update(sf::Time elapsedTime);
    void render();

    //Metodos de rendimiento
    void updateRendimiento(sf::Time elapsedTime);
    void entradaTeclado(sf::Keyboard::Key key, bool teclaPresionada);

    //Constantes del juego
    static const float VelocidadJugador;
    static const sf::Time TimeFrame;

    //Variables custom
    sf::RenderWindow mVentana;
    sf::Texture mTextura;
    sf::Sprite mJugador;
    sf::Time mEstadisticasTiempo;
    sf::Font mFuente;
    sf::Text mTexto;

    //Variables de rendimiento
    std::size_t mNumFrames;

    //Variables de movimiento
    bool    mAbajo;
    bool    mArriba;
    bool    mDerecha;
    bool    mIzquierda;


};

#endif