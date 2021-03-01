#ifndef MAIN_MENU_STATE_H
#define MAIN_MENU_STATE_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <sstream>

#include "../definitions.h"
#include "../game_engine/state.h"
#include "../game_engine/game.h"

#include "game_state.h"

/// @file

namespace academy {
	/// \brief
	/// Class for main menu state
	/// \details
	/// Class to use in the main menu state
	class main_menu_state : public state {
	private:
		game_data_ref _data;

		sf::Music _background_music;

		sf::Sprite _background;
		sf::Sprite _title;
		sf::Sprite _play_button;

	public:
		/// \brief
		/// Default contstructor of the main menu state class
		main_menu_state(game_data_ref data) : _data(data) {};

		/// \brief
		/// Method to initialize main menu state
		void init();

		/// \brief
		/// Method to handle main menu state input
		void handle_input();

		/// \brief
		/// Method to update main menu state
		void update(float dt) {};

		/// \brief
		/// Method to draw main menu state
		void draw(float dt);

	};

}

#endif //main_menu_state.h
