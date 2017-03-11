
#include "oct_pad_window.h"

oct_pad_window::oct_pad_window()
{
    height_per_octave = (double)_movable_pad_height / _n_octaves;
    width_per_note = (double)_modable_pad_width / _n_notes;
    _oct_pad_box_size = sf::Vector2f(width_per_note, height_per_octave);
}

sf::Vector2i
oct_pad_window::_mouse_loc()
{
    return sf::Mouse::getPosition(_window);
}

void oct_pad_window::draw()
{
    _setup_window();
    _mouse_state_to_action();
}

bool oct_pad_window::_is_mouse_in_window()
{
    auto loc = _mouse_loc();
    // Function to decide whether or not the is inside the window.
    if (
        loc.x<0 | loc.y<0 | loc.x> _window_height | loc.y> _window_width)
    {
        return false;
    }

    return true;
}

std::pair<int, int>
oct_pad_window::_coords_to_box(int x, int y)
{
    // From a position on the screen, return a pair
    // containing the octave and note-number.
    return std::make_pair<int, int>(
        (int)(_n_octaves * y / (float)_movable_pad_height),
        (int)(_n_notes * x / (float)_modable_pad_width));
}

std::pair<int, int>
oct_pad_window::_coords_to_box(sf::Vector2i loc)
{
    return _coords_to_box(loc.x, loc.y);
}

std::pair<int, int>
oct_pad_window::_coords_to_box()
{
    return _coords_to_box(_mouse_loc());
}

sf::Color
oct_pad_window::_oct_note_to_colour(OCTNOTE octnote)
{
    return sf::Color(octnote.first * 255 / _n_octaves, (octnote.second - 1) * 255 / _n_notes, 0);
}


sf::Color
oct_pad_window::_oct_note_to_colour(OCTNOTE octnote, OCTNOTE selected)
{
    if ((octnote.first == selected.first) && (octnote.second == selected.second + 1))
    {
        return sf::Color::Blue;
    }
    else
    {
        return _oct_note_to_colour(octnote);
    }
}


sf::Vector2i
oct_pad_window::_oct_note_to_position(OCTNOTE octnote)
{
    return sf::Vector2i((octnote.second - 1) * width_per_note, octnote.first * height_per_octave);
}

void oct_pad_window::_setup_window()
{

    _window.create(sf::VideoMode(_window_width, _window_height),
                   "Window");

    _mouse_state.locate(_window);

    for (int octave = 0; octave <= _n_octaves; octave++)
    {
        for (int note = 1; note <= _n_notes; note++)
        {
            auto octnote = OCTNOTE(octave, note);
            sf::RectangleShape rectangle;
            rectangle.setSize(_oct_pad_box_size);
            rectangle.setOutlineColor(sf::Color::Black);
            rectangle.setOutlineThickness(2);
            rectangle.setFillColor(_oct_note_to_colour(octnote));
            auto pos = _oct_note_to_position(octnote);
            rectangle.setPosition(pos.x, pos.y);
            _window.draw(rectangle);
        }
    }
    _window.display();
}

void oct_pad_window::_mouse_state_to_action()
{

    while (_window.isOpen())
    {
        _mouse_state.locate(_window);
        if (_is_mouse_in_window())
        {

            if (_mouse_state.moved_box())
            {
                _draw(_coords_to_box());
            }
            
        }
        
    }
}

void oct_pad_window::_draw(std::pair<int, int> selected)
{
    for (int octave = 0; octave <= _n_octaves; octave++)
    {
        for (int note = 1; note <= _n_notes; note++)
        {
            auto octnote = OCTNOTE(octave, note);

            sf::RectangleShape rectangle;
            rectangle.setSize(_oct_pad_box_size);
            rectangle.setOutlineColor(sf::Color::Black);
            rectangle.setOutlineThickness(2);
            rectangle.setFillColor(_oct_note_to_colour(octnote, selected));
            auto pos = _oct_note_to_position(octnote);
            rectangle.setPosition(pos.x, pos.y);
            _window.draw(rectangle);
        }
    }
    _window.display();
}