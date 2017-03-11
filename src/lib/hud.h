#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "oct_pad_window_params.h"
#include "equaliser.h"



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
