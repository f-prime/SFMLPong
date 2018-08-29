#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Paddle {
    private:        
        sf::RectangleShape rectangle;
        sf::RenderWindow &window; 
    public:
        int pos_x;
        int pos_y;
        
        int height;
        int width;
        void setPos(int x, int y);
        
        void setSize(int height, int width);
        void render();
        Paddle(sf::RenderWindow &window);
};
