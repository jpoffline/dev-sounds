#include "equaliser.h"

equaliser::equaliser()
{
    _eq_blocks.resize(nchannels);
}


sf::Vector2f equaliser::_mag_to_size(float magnitude)
{
    return sf::Vector2f(width, magnitude);   
}

/// Add a channel to the equaliser.
void equaliser::add(int channel, float magnitude)
{
    add(CHANNEL(channel, magnitude));
}


/// Add a channel to the equaliser.
void equaliser::add(CHANNEL channel)
{
    sf::RectangleShape rectangle;
    rectangle.setSize(_mag_to_size(channel.second));
    rectangle.setOutlineColor(sf::Color::Black);
    rectangle.setOutlineThickness(1);
    rectangle.setFillColor(sf::Color::Blue);
    rectangle.setPosition(_channel_to_location(channel.first));
    _eq_blocks[channel.first] = rectangle;
}

/// Update the given display with the equaliser.
void equaliser::update(sf::RenderWindow &display)
{
    _draw_blocks(display);
}

/// Add a set of channels to the equaliser.
void equaliser::add(CHANNELS& channels)
{
    for(auto& c : channels)
    {
        add(c.first, c.second);
    }
}

void equaliser::_draw_blocks(sf::RenderWindow &display)
{
    for (auto &b : _eq_blocks)
    {
        display.draw(b);
    }
}

sf::Vector2f equaliser::_channel_to_location(int channel)
{
    return sf::Vector2f(origin_pos_x + channel * (width + space), origin_pos_y);
}