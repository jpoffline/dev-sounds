#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "oct_pad_window_params.h"

class hud  : public oct_pad_window_params
{
  private:
    sf::RenderWindow _hud;
    sf::Font _hud_font;
  public:
    void setup_hud();
    void write_to_hud(std::string);
};
