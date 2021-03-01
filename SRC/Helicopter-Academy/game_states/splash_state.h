#ifndef SPLASH_STATE_H
#define SPLASH_STATE_H

#include <SFML/Graphics.hpp>
#include <sstream>

#include "../definitions.h"
#include "../game_engine/state.h"
#include "../game_engine/game.h"

#include "main_menu_state.h"

/// @file

namespace academy {
	/// \brief
	/// Class for splash state
	/// \details
	/// Class to use in the splash state 
	class splash_state : public state {
	private:
		game_data_ref _data;

		sf::Clock _clock;

		sf::Sprite  _background;

	public:
		/// \brief
		/// Default contstructor of the splash state class
		splash_state(game_data_ref data) : _data(data) {};

		/// \brief
		/// Method to initialize splash state
		void init();

		/// \brief
		/// Method to handle splash state input
		void handle_input();

		/// \brief
		/// Method to update splash state
		void update(float dt);

		/// \brief
		/// Method to draw splash state
		void draw(float dt);

	};

}

#endif //splash_state.h
