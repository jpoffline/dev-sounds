#include "mouse_state.h"

/// Method to update the location of the box,
/// in terms of the box-representation.
/// If the inputted location matches the
/// cached location, then no update required.
/// Otherwise, update the location.
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

/// Return a boolean dependent upon whether or
/// not the mouse has changed the box representation
/// it lives in.
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
        (int)(_n_octaves * loc.y / (float)_movable_pad_height),
        (int)(_n_notes * loc.x / (float)_modable_pad_width));
}

/// Locate the mouse in the window.
void mouse_state::locate(sf::RenderWindow &where)
{

    _update_box_rep(_position_to_box(sf::Mouse::getPosition(where)));
}

/// Update the mouse location.
void mouse_state::_update_box_rep(std::pair<int, int> test_rep)
{

    _box_rep.update(test_rep);
}

/// Boolean to decide whether the
/// mouse has actually changed the box
/// it lives in.
bool mouse_state::moved_box()
{
    return _box_rep.changed();
}