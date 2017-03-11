
#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "mouse_state.h"
#include "oct_pad_window_params.h"

class oct_pad_window : public oct_pad_window_params
{

  typedef std::pair<int, int> OCTNOTE;
  typedef bool OCTSELECTED;
  
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
    sf::Color _oct_note_to_colour(OCTNOTE);
    sf::Color _oct_note_to_colour(OCTNOTE, OCTNOTE);
    sf::Color _oct_note_to_colour(OCTNOTE, OCTSELECTED);
    sf::Vector2i _oct_note_to_position(OCTNOTE);
    mouse_state _mouse_state;    


    sf::Vector2f _oct_pad_box_size;

    void _mouse_state_to_action();

    void _draw(std::pair<int, int>);


    sf::RectangleShape _get_octpad_box(OCTNOTE octnote, OCTSELECTED);

    OCTSELECTED _is_octnote_selected(OCTNOTE, OCTNOTE);


  public:
    oct_pad_window();

    void draw();
};