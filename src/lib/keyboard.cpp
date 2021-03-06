#include "keyboard.h"

KEYBOARD::KEYBOARD()
{
    _gen_key_mappings();
    _gen_keyboard_samples();
}

void KEYBOARD::play_pad()
{
    play_via_key = false;
}

void KEYBOARD::play()
{

    std::vector<sf::Sound> sounds;
    std::vector<sf::SoundBuffer> buffers(_keyboard_samples.size());
    sounds.resize(buffers.size());
    auto nsounds = _keyboard_samples.size();
    for (int i = 0; i < nsounds; i++)
    {
        buffers[i].loadFromSamples(&_keyboard_samples[i][0], _keyboard_samples[i].size(), 1, 44100);
        sounds[i].setBuffer(buffers[i]);
    }

    sf::Window window(sf::VideoMode(_window_width, _window_height), "My window");
    while (!SFk::isKeyPressed(SFk::Key::Escape))
    {
        if (play_via_key)
        {
            for (auto &k : _keys)
            {
                if (SFk::isKeyPressed(k.first))
                {
                    if (sounds[k.second].getStatus() != sf::Sound::Status::Playing)
                    {
                        sounds[k.second].play();
                    }
                }
            }
        }
        else
        {
            auto loc = sf::Mouse::getPosition(window);
            if (_is_mouse_in_window(loc))
            {
                int idx = (int)(nsounds * loc.x / (float)_window_width);
                int idy = (int)(nsounds * loc.y / (float)_window_height);
                std::cout << idx << " " << idy << std::endl;
                if (sounds[idx].getStatus() != sf::Sound::Status::Playing)
                {
                    sounds[idx].play();
                }
            }
        }
    }
}

sf::Vector2f
KEYBOARD::_get_mouse_loc_frac(const sf::Vector2i loc)
{
    sf::Vector2f result;
    result.x = loc.y / (float)_window_width;
    result.y = loc.x / (float)_window_height;
    return result;
}

bool KEYBOARD::_is_mouse_in_window(const sf::Vector2i loc)
{
    // Function to decide whether or not a vector is inside the window.
    if (
        loc.x<0 | loc.y<0 | loc.x> _window_height | loc.y> _window_width)
    {
        return false;
    }

    return true;
}

void KEYBOARD::play_octPad()
{
    sf::RenderWindow window(sf::VideoMode(_window_width, _window_height), "My window");

    // Divide window into nOctaves x nNotes squares

    auto height_per_octave = (double)_window_height / nOctaves;
    auto width_per_note = (double)_window_width / nNotes;

    for (int octave = 0; octave <= nOctaves; octave++)
    {
        for (int note = 1; note <= nNotes; note++)
        {
            sf::RectangleShape rectangle;
            rectangle.setSize(sf::Vector2f(width_per_note, height_per_octave));
            rectangle.setOutlineColor(sf::Color::Black);
            rectangle.setOutlineThickness(2);
            rectangle.setFillColor(sf::Color(octave * 255 / nOctaves, (note - 1) * 255 / nNotes, 0));
            rectangle.setPosition((note - 1) * width_per_note, octave * height_per_octave);
            window.draw(rectangle);
        }
    }
    window.display();

    std::cout << "* window prepared" << std::endl;

    std::vector<std::vector<SAMPLES>> keyboard_samples;
    std::vector<std::vector<sf::Sound>> sounds;
    std::vector<std::vector<sf::SoundBuffer>> buffers;

    keyboard_samples.resize(nOctaves + 1);
    sounds.resize(nOctaves + 1);
    buffers.resize(nOctaves + 1);
    for (int o = 0; o < keyboard_samples.size(); o++)
    {
        keyboard_samples[o].resize(nNotes + 1);
        sounds[o].resize(nNotes + 1);
        buffers[o].resize(nNotes + 1);
    }
    std::cout << "* data structures prepared" << std::endl;

    // Generate the samples.
    /*JP_sound::EnvelopeParams eps(nsamples);
    eps.sustainLevel = 0.8;
    eps.releaseRate = 0.01;
    eps.releaseTime = 0.2;
    auto envelope = JP_sound::Envelopes(eps);
    */
    for (int octave = 0; octave <= nOctaves; octave++)
    {
        for (int note = 1; note <= nNotes; note++)
        {
            short smple(0), smple_prev(0);
            auto freq = ftones.get(octave, note);
            for (int sample = 0; ; sample++)
            {
                smple_prev = smple;                
                smple = JP_sound::PianoTone(sample,freq);
                if (sample >= nsamples)
                {
                    if ((smple > 0 && smple_prev < 0))
                    {
                        smple = (smple + smple_prev) / 2.0;
                        //keyboard_samples[octave][note - 1].push_back(smple);
                        break;
                    }
                }

                keyboard_samples[octave][note - 1].push_back(smple);
                


            }
        }
    }
    
    tests::dump_samples_loop(keyboard_samples[2][1]);

    std::cout << "* samples generated" << std::endl;

    // Dump the samples into the buffer.
    for (int oct = 0; oct <= nOctaves; oct++)
    {
        for (int note = 0; note < nNotes; note++)
        {
            buffers[oct][note].loadFromSamples(
                &keyboard_samples[oct][note][0],
                keyboard_samples[oct][note].size(),
                1,
                keyboard_samples[oct][note].size());
            sounds[oct][note].setBuffer(buffers[oct][note]);
        }
    }
    std::cout << "* buffers prepared" << std::endl;
    std::cout << "* ready to play" << std::endl;
    std::cout << "   press P to enable/disable play" << std::endl;

    bool paused = false;

    // Main loop.
    while (!SFk::isKeyPressed(SFk::Key::Escape))
    {
        // Check to see if PAUSE button pressed.
        if (SFk::isKeyPressed(SFk::P))
        {
            if (paused)
            {
                paused = false;
            }
            else
            {
                paused = true;
            }
            sf::sleep(sf::milliseconds(1000));
        }

        if (!paused)
        {
            auto loc = sf::Mouse::getPosition(window);
            // Use the mouse location to determine which sound buffer to play.
            if (_is_mouse_in_window(loc))
            {
                auto pp = _get_oct_note(loc.x, loc.y);
                // Only play buffer if current buffer not playing.
                if (sounds[pp.first][pp.second].getStatus() != sf::Sound::Status::Playing)
                {
                    sounds[pp.first][pp.second].play();
                    auto octaveT = pp.first;
                    auto noteT = pp.second;
                    for (int octave = 0; octave <= nOctaves; octave++)
                    {
                        for (int note = 1; note <= nNotes; note++)
                        {
                            sf::RectangleShape rectangle;
                            rectangle.setSize(sf::Vector2f(width_per_note, height_per_octave));
                            rectangle.setOutlineColor(sf::Color::Black);
                            rectangle.setOutlineThickness(2);
                            if(((note-1) == noteT) && (octave == octaveT))
                            {
                                rectangle.setFillColor(sf::Color::Blue);
                            }
                            else
                            {
                                rectangle.setFillColor(sf::Color(octave * 255 / nOctaves, (note - 1) * 255 / nNotes, 0));
                                
                            }
                            rectangle.setPosition((note - 1) * width_per_note, octave * height_per_octave);
                            window.draw(rectangle);
                        }
                    }
                    window.display();
                }
            }
        }
    }
}

std::pair<int, int>
KEYBOARD::_get_oct_note(float x, float y)
{
    // From a position on the screen, return a pair
    // containing the octave and note-number.
    return std::make_pair<int, int>(
        (int)(nOctaves * y / (float)_window_height),
        (int)(nNotes * x / (float)_window_width));
}

void KEYBOARD::_gen_keyboard_samples()
{

    auto frequencies = ftones.get_octave_middle();
    _keyboard_samples.resize(frequencies.size());

    JP_sound::EnvelopeParams eps(nsamples);
    eps.sustainLevel = 0.3;
    eps.releaseRate = 0.01;
    eps.releaseTime = 0.1;
    auto envelope = JP_sound::Envelopes(eps);

    for (int i = 0; i < nsamples; i++)
    {
        for (int f = 0; f < frequencies.size(); f++)
        {
            _keyboard_samples[f].push_back(
                envelope.get(i) * JP_sound::PianoTone(i, frequencies[f]));
        }
    }
}

void KEYBOARD::_gen_key_mappings()
{
    // Map the key-pressed to indices of the frequencies.
    //  TODO: map to note names.
    _keys[SFk::Key::A] = 0;
    _keys[SFk::Key::S] = 1;
    _keys[SFk::Key::D] = 2;
    _keys[SFk::Key::F] = 3;
    _keys[SFk::Key::G] = 4;
    _keys[SFk::Key::H] = 5;
    _keys[SFk::Key::J] = 6;
    _keys[SFk::Key::K] = 7;
    _keys[SFk::Key::L] = 8;
    _keys[SFk::Key::Z] = 9;
    _keys[SFk::Key::X] = 10;
    _keys[SFk::Key::C] = 11;
}
