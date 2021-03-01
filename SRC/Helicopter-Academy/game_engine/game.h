#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <memory>
#include <string>

#include <stdlib.h>
#include <time.h>

#include "state_machine.h"
#include "asset_manager.h"
#include "input_manager.h"

/// @file

namespace academy {
	/// \brief
	/// Game data
	/// \details
	/// Struct with data for the game
	struct game_data {
		sf::RenderWindow window;
		state_machine    machine;
		asset_manager    assets;
		input_manager    input;

	};

	typedef std::shared_ptr<game_data> game_data_ref;

	/// \brief
	/// Game engine
	/// \details
	/// Class to run the game
	class game {
	private:
		const float dt = 1.0f / 60.0f;

		sf::Clock _clock;

		game_data_ref _data = std::make_shared<game_data>();

		/// \brief
		/// Run the game
		/// \details
		/// After the game class is initialized the game will run continuously
		/// until the user closes the window
		void run();

	public:
		/// \brief
		/// Default contstructor of the game class
		/// \details
		/// Create a window, set game state to splash_state and run the 
		/// game continuously
		game(int width, int height, std::string title);

	};

}

#endif //game.h
