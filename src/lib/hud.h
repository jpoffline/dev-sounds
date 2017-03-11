#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "oct_pad_window_params.h"

struct equaliser
{

    float max_height = 100;
    int origin_pos_x = 0;
    int origin_pos_y = 50;
    int nchannels = 10;
    
    int width = 20;
    int space = 20;

    float location(int channel)
    {
        return origin_pos_x + channel * (width + space);
    }


    void draw_eq_block(sf::RenderWindow& hud, int channel, float height)
    {
        sf::RectangleShape rectangle;
        rectangle.setSize(sf::Vector2f(width, height));
        rectangle.setOutlineColor(sf::Color::Black);
        rectangle.setOutlineThickness(1);
        rectangle.setFillColor(sf::Color::Blue);
        rectangle.setPosition(location(channel), origin_pos_y);
    
        hud.draw(rectangle);
    }


};



class hud  : public oct_pad_window_params
{
  private:
    sf::RenderWindow _hud;
    sf::Font _hud_font;
    equaliser _eq;
    void _update();
  public:
    void setup_hud();
    void write_to_hud(std::string);
    void draw_equaliser_block(int channel, float height);
    void draw_equaliser_blocks(std::vector<std::pair<int, int>>);
    void update();
    void clean();
};
