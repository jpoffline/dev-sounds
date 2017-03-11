
#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "oct_pad_window_params.h"

class equaliser
{

    typedef std::pair<int, float> CHANNEL;
    typedef std::vector<std::pair<int, float>> CHANNELS;

  private:
    float max_height = 100;
    int origin_pos_x = 0;
    int origin_pos_y = 50;
    const int nchannels = 10;

    int width = 20;
    int space = 20;

    sf::Vector2f _channel_to_location(int channel);
    sf::Vector2f _mag_to_size(float);
    std::vector<sf::RectangleShape> _eq_blocks;

    void _draw_blocks(sf::RenderWindow &hud);




  public:
    equaliser();

    /// Add a channel to the equaliser.
    void add(int channel, float height);


    /// Add a channel to the equaliser.
    void add(CHANNEL channel);

    /// Add a set of channels to the equaliser.
    void add(CHANNELS& channels);

    /// Update the display with the equaliser.
    void update(sf::RenderWindow &display);
};