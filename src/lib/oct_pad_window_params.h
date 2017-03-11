#pragma once

struct oct_pad_window_params{

    /// Height and width of the full application window
    const int _window_height = 400;
    const int _window_width  = 400;
    
    /// Number of ocataves
    const int _n_octaves     = 10;

    /// Number of notes
    const int _n_notes       = 10;

    /// Height of the octo-pad
    const int _movable_pad_height = 400;

    /// Width of the octo-pad
    const int _modable_pad_width = 400;

};