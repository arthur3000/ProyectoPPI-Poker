#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#define ALTURA_PANTALLA 720
#define ANCHURA_PANTALLA 1280
#define POSICION_X_TITULO 450
#define POSICION_Y_TITULO 50
#define POSICION_X_BOTON_JUGAR 565
#define POSICION_Y_BOTON_JUGAR 550
#define POSICION_X_LABEL 300
#define POSICION_Y_LABEL 550
#define POSICION_X_NICKNAME 550
#define POSICION_Y_NICKNAME 550

using namespace std;
int main()
{
    string str;
    //sf::Window window(sf::VideoMode(800, 600), "My window");
   // sf::RenderWindow windows(sf::VodeoMode(800,600),"Mi windows ");
    sf::RenderWindow window(sf::VideoMode(ANCHURA_PANTALLA, ALTURA_PANTALLA), "Texas Hold'em"); // La resolucion puede cambiar, pero se necesitaria cambiar tambien las imagenes.
    // Todas las texturas que utilizara el juego y los sprites
    sf::Texture fondo;  // Imagen de fondo
    sf::Texture titulo; // Imagen con las letras
    sf::Texture botonJugar;  // Imagen con el boton jugar
    sf::Sprite spriteTitulo;
    sf::Sprite background;
    sf::Sprite spriteBotonJugar;

    // run the program as long as the window is open

    // Etiqueta de Texto nombre jugador
    sf::Font font;
    font.loadFromFile("Chancery.ttf");

    sf::Text labelNick("Nickname",font,50);
    labelNick.setPosition(POSICION_X_LABEL,POSICION_Y_LABEL);

    // String donde se mostrara el nickname

    sf::Text entradaNick("",font,50);
    entradaNick.setPosition(POSICION_X_NICKNAME,POSICION_Y_NICKNAME);

    titulo.loadFromFile("titulo.png");
    botonJugar.loadFromFile("botonJugar.png");
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
            else if(event.type == sf::Event::KeyPressed){ // Evento para darle enter e iniciar el juego
                if(event.key.code == sf::Keyboard::Return){
                    cout << str <<endl;;
                }
            }
            else if(event.type == sf::Event::TextEntered){ // Este evento es para que el jugador ponga su nickName
                // Handle ASCII characters only
                if (event.text.unicode < 128){ // Se ponen simbolos de que no reconoce si se escribe otra letra, corregir.
                    str += static_cast<char>(event.text.unicode);
                    entradaNick.setString(str);
                }
            }
        }
        if(!fondo.loadFromFile("pokerTable3.png")){
            window.clear(sf::Color::Black);
        }
        else{
            background.setTexture(fondo);

            spriteTitulo.setTexture(titulo);
            spriteTitulo.setPosition(POSICION_X_TITULO,POSICION_Y_TITULO);

            spriteBotonJugar.setTexture(botonJugar);
            spriteBotonJugar.setPosition(POSICION_X_BOTON_JUGAR,POSICION_Y_BOTON_JUGAR);

            window.draw(background); // TIenes que poner el background antes que todo.
            window.draw(spriteTitulo);
            //window.draw(spriteBotonJugar);
            window.draw(labelNick); // Etiqueta nickname
            window.draw(entradaNick);   // Aqui poco a poco se va a insertar el nombre;


        }

        window.display();
    }

    return 0;
}
