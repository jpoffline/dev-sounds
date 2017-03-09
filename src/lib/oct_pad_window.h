
#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "mouse_state.h"
#include "oct_pad_window_params.h"

class oct_pad_window : public oct_pad_window_params
{

  private:
    double height_per_octave;
    double width_per_note;
    sf::RenderWindow _window;
    void _setup_window();
    bool _is_mouse_in_window();
    sf::Vector2i _mouse_loc();
    std::pair<int, int> _coords_to_box(int x, int y);
    std::pair<int, int> _coords_to_box(sf::Vector2i);
    std::pair<int, int> _coords_to_box();
    sf::Color _oct_note_to_colour(int, int);
    sf::Color _oct_note_to_colour(int, int, int, int);
    sf::Vector2i _oct_note_to_position(int, int);
    mouse_state _mouse_state;    

  public:
    oct_pad_window();

    void draw();
};