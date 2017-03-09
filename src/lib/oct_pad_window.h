
#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

class oct_pad_window
{

    private:

        int _window_width;
        int _window_height;
        int _n_octaves;
        int _n_notes;
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
    public:
        oct_pad_window();
        oct_pad_window(int, int);
        
        void nOctaves(int);
        void nNotes(int);
        void draw();


};