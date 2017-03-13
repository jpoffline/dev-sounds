
#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "oct_pad_window_params.h"
#include "fundamental_tones.h"

class equaliser : public oct_pad_window_params
{

    typedef std::pair<int, float> CHANNEL;
    typedef std::vector<std::pair<int, float>> CHANNELS;

  private:
    float max_height = 100;
    int origin_pos_x = 0;
    int origin_pos_y = 50;
    const int nchannels = 100;

    float width_per_channel;
    float freq_width_per_channel;
    int space = 2;

    float width_total_npixels = (float)_modable_pad_width;

    sf::Vector2f _channel_to_location(int channel);
    sf::Vector2f _mag_to_size(float);
    std::vector<sf::RectangleShape> _eq_blocks;

    void _draw_blocks(sf::RenderWindow &hud);


    FUNDAMENTAL_TONES ftones;

    int _frequency_to_channel_idx(float);

    void _calc_npixels_per_channel();
    void _calc_freq_width_per_channel();


    void _print_eq_settings(std::ostream&);

  public:
    equaliser();

    /// Add a channel to the equaliser.
    void add(int channel, float height);


    void add(std::pair<float, float>);

    /// Add a channel to the equaliser.
    void add(CHANNEL channel);

    /// Add a set of channels to the equaliser.
    void add(CHANNELS& channels);

    /// Update the display with the equaliser.
    void update(sf::RenderWindow &display);
};