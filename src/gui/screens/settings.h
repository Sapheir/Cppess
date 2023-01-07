// Created by Catalin
#pragma once
#include "../../model/domain/pieces/colors.h"

enum screens {
    main_menu = 0,
    single_player_options = 1,
    multiplayer_options = 2,
    single_player_game = 3,
    multiplayer_server = 4,
    multiplayer_client = 5
};

struct settings {
    colors color;
    std::string joinString;
};