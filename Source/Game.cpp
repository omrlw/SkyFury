
#include "../Include/Graphics_SFML.hpp"

const float Game::VelocidadJugador = 100.f;
const sf::Time Game::TimeFrame = sf::seconds(1.f / 60.f);


Game::Game()
: mVentana(sf::VideoMode(800, 750), "SkyFury", sf::Style::Close)
, mTextura()
, mJugador()
, mEstadisticasTiempo()
, mFuente()
, mTexto()
, mAbajo(false)
, mArriba(false)
, mDerecha(false)
, mIzquierda(false)


{
    if (!mTextura.loadFromFile("../Resources/Images/avion.png")){
//        std::cout<<"NO se encontro"<<std::endl;
    }

    //Dibujo y posicion
    mJugador.setTexture(mTextura);
    mJugador.setScale(0.3f,0.3f);
    mJugador.setPosition(100,100);

    mFuente.loadFromFile("../Resources/Fonts/Halloween Spooky.otf");



    //Propiedades Texto
    mTexto.setFont(mFuente);
    mTexto.setPosition(10,10);
    mTexto.setCharacterSize(50);

}

void Game::run(){

    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    mVentana.setFramerateLimit(60);
    while (mVentana.isOpen())
    {
        sf::Time elapsedTime = clock.restart();
        timeSinceLastUpdate += elapsedTime;
        while (timeSinceLastUpdate > TimeFrame)
        {
            timeSinceLastUpdate -= TimeFrame;

            procesosEvento();
            update(TimeFrame);
        }

        updateRendimiento(elapsedTime);
        render();
    }
}

void Game::procesosEvento() {

    sf::Event event;
    while (mVentana.pollEvent(event))
    {
        switch (event.type)
        {
            case sf::Event::KeyPressed:
                entradaTeclado(event.key.code, true);
                break;

            case sf::Event::KeyReleased:
                entradaTeclado(event.key.code, false);
                break;

            case sf::Event::Closed:
                mVentana.close();
                break;
        }
    }

}


void Game::render() {

    mVentana.clear();
    mVentana.draw(mJugador);
    mVentana.draw(mTexto);
    mVentana.display();
}

void Game::updateRendimiento(sf::Time elapsedTime) {

    mEstadisticasTiempo += elapsedTime;
    mNumFrames += 1;

    if(mEstadisticasTiempo >= sf::seconds(1.0f)){
        mTexto.setString(
            "Frames / Second = " + std::to_string(mNumFrames) + "\n" +
            "Time / Update = " + std::to_string(mEstadisticasTiempo.asMicroseconds() / mNumFrames) + "micro_segundos");

            mEstadisticasTiempo -= sf::seconds(1.0f);
            mNumFrames = 0;

    }

}

void Game::update(sf::Time elapsedTime) {
    sf::Vector2f movement(0.f, 0.f);
    if (mArriba)
        movement.y -= VelocidadJugador;
    if (mAbajo)
        movement.y += VelocidadJugador;
    if (mIzquierda)
        movement.x -= VelocidadJugador;
    if (mDerecha)
        movement.x += VelocidadJugador;

    mJugador.move(movement * elapsedTime.asSeconds());
}

void Game::entradaTeclado(sf::Keyboard::Key key, bool teclaPresionada) {
    if(key == sf::Keyboard::W){
        mArriba = teclaPresionada;
    }
    if(key == sf::Keyboard::A){
        mIzquierda = teclaPresionada;
    }
    if(key == sf::Keyboard::S){
        mAbajo = teclaPresionada;
    }
    if(key == sf::Keyboard::D){
        mDerecha = teclaPresionada;
    }


}




