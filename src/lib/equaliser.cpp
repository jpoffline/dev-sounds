#include "equaliser.h"

equaliser::equaliser()
{

    _calc_freq_width_per_channel();
    _calc_npixels_per_channel();
    _eq_blocks.resize(nchannels);
    _print_eq_settings(std::cout);
}


/// Calculate the width of each equaliser channel (in frequency/Hz).
void equaliser::_calc_freq_width_per_channel()
{
    float freq_range_min = ftones.get(0, 1);
    float freq_range_max = ftones.get(_n_octaves, _n_notes);
    freq_width_per_channel = (freq_range_max - freq_range_min) / nchannels;
}


/// Print the equaliser settings.
void equaliser::_print_eq_settings(std::ostream& out)
{
    out << " * number of channels: " << nchannels << "\n";
    out << " * delta freq per channel: " << freq_width_per_channel << "\n";
    out << " * number of pixels per channel " << width_per_channel << "\n";

}

/// Calculate the width (in pixels) of each equaliser channel.
void equaliser::_calc_npixels_per_channel()
{
    width_per_channel = (float)_hud_width / (float)nchannels;
}

/// Map a magnitude to a size of the equaliser block.
sf::Vector2f equaliser::_mag_to_size(float magnitude)
{
    return sf::Vector2f(width_per_channel, magnitude);
}

/// Add a channel to the equaliser.
void equaliser::add(int channel, float magnitude)
{
    add(CHANNEL(channel, magnitude));
}

/// Add a frequecy-magnitude pair to the equaliser.
void equaliser::add(std::pair<float, float> freq_amp)
{
    std::cout << "freq: " << freq_amp.first << std::endl;
    std::cout << "hash: " << _frequency_to_channel_idx(freq_amp.first) << std::endl;
    add(CHANNEL(_frequency_to_channel_idx(freq_amp.first), freq_amp.second));
}

/// Map a frequency to a channel index.
int equaliser::_frequency_to_channel_idx(float frequency)
{
    return (int)(frequency * freq_width_per_channel / nchannels);
}

/// Add a set of channels to the equaliser.
void equaliser::add(CHANNELS &channels)
{
    for (auto &c : channels)
    {
        add(c.first, c.second);
    }
}

/// Map a channel index to a location on the screen.
sf::Vector2f equaliser::_channel_to_location(int channel)
{
    float loc_x = channel * (float)_hud_width / (float)nchannels;
    std::cout << loc_x << std::endl;
    float loc_y = origin_pos_y;
    return sf::Vector2f(loc_x, loc_y);
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

void equaliser::_draw_blocks(sf::RenderWindow &display)
{
    for (auto &block : _eq_blocks)
    {
        display.draw(block);
    }
}