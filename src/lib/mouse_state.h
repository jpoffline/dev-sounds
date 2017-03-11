#pragma once

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "oct_pad_window_params.h"

class box_rep_cache
{
    private:
        std::pair<int, int> _box_rep_cache; 
        bool _updated;
    public:
        void update(std::pair<int, int> test_rep);
        bool changed();
};


class mouse_state: public oct_pad_window_params {

    private:
        box_rep_cache _box_rep;
        void _update_box_rep(std::pair<int, int>);
        std::pair<int, int> _position_to_box(sf::Vector2i);

    public:
        mouse_state();
        void locate(sf::RenderWindow&);
        bool moved_box();

};