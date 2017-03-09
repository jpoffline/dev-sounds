#include "mouse_state.h"

void box_rep_cache::update(std::pair<int, int> test_rep)
{
    if ((test_rep.first != _box_rep_cache.first) || (test_rep.second != _box_rep_cache.second))
    {
        _box_rep_cache = test_rep;
        _updated = true;
    }
    else
    {
        _updated = false;
    }
}

bool box_rep_cache::changed()
{
    return _updated;
}

mouse_state::mouse_state()
{
}

std::pair<int, int> mouse_state::_position_to_box(sf::Vector2i loc)
{
return std::make_pair<int, int>(
        (int)(_n_octaves * loc.y / (float)_window_height),
        (int)(_n_notes * loc.x / (float)_window_width));
    
}


void mouse_state::locate(sf::RenderWindow& where)
{
    _update_box_rep(_position_to_box(sf::Mouse::getPosition(where)));
}

void mouse_state::_update_box_rep(std::pair<int, int> test_rep)
{
    _box_rep.update(test_rep);
}


bool mouse_state::moved_box()
{
    return _box_rep.changed();
}