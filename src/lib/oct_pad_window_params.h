#pragma once

struct oct_pad_window_params{

    /// Height and width of the full application window
    const int _window_height = 400;
    const int _window_width  = 1200;
    
    /// Number of ocataves
    const int _n_octaves     = 5;

    /// Number of notes
    const int _n_notes       = 10;

    /// Height of the octo-pad
    const int _movable_pad_height = 400;

    /// Width of the octo-pad
    const int _modable_pad_width = 800;


    const int _hud_width = 600;
    const int _hud_height = 400;


    const std::string _hud_title = "OctaPad-HUD";
    const std::string _pad_title = "OctaPad";


    /// Initial locations on the screen.
    const int _pad_window_loc_init_x = 200;
    const int _pad_window_loc_init_y = 200;
    const int _hud_window_loc_init_x = 620;
    const int _hud_window_loc_init_y = 420;

};