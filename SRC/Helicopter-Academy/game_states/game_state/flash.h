#ifndef FLASH_H
#define FLASH_H

#include <SFML/Graphics.hpp>

#include "../../definitions.h"
#include "../../game_engine/game.h"

/// @file

namespace academy {
	/// \brief
	/// Add flash screen
	/// \details
	/// Class for adding flash screen to game state
	class flash {
	private:
		game_data_ref _data;

		sf::RectangleShape _shape;

		float _alpha {};

		bool _flash_on {};

	public:
		/// \brief
		/// Default contstructor of the flash class
		flash(game_data_ref data);

		/// \brief
		/// Showing flash
		/// \details
		/// Shows a flash screen in game state
		void show(float dt);

		/// \brief
		/// Drawing flash
		/// \details
		/// Draws a flash screen in game state
		void draw();

	};

}

#endif //flash.h
