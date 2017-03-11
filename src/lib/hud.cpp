#include "hud.h"

void hud::setup_hud()
{
    _hud.create(sf::VideoMode(_hud_width, _hud_height),
                _hud_title);
    _hud.setPosition(sf::Vector2i(_hud_window_loc_init_x,_hud_window_loc_init_y));                   
    _hud.clear(sf::Color(100,100,100));

   
    if (!_hud_font.loadFromFile( "src/lib/fonts/sansation.ttf")) {
        std::cerr << "ERR font\n";
    }
    write_to_hud("Hello");
    _hud.display();   

}


void hud::write_to_hud(std::string msg)
{
    _hud.clear(sf::Color(100,100,100));

    sf::Text text(msg, _hud_font, 50);
    text.setFillColor(sf::Color::Black);
    _hud.draw(text);
    _hud.display();
}
