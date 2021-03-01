#ifndef SCORE_DISPLAY_H
#define SCORE_DISPLAY_H

#include <SFML/Graphics.hpp>
#include <string>

#include "../../definitions.h"
#include "../../game_engine/game.h"

/// @file

namespace academy {
	/// \brief
	/// Add scoring display
	/// \details
	/// Class for adding a scoring display to game state
	class score_display	{
	private:
		game_data_ref _data;

		sf::Text _score_text;
		sf::Text _fuel_text;

	public:
		/// \brief
		/// Default contstructor of the score display class
		score_display(game_data_ref data);

		/// \brief
		/// Draw score display
		/// \details
		/// Draw score display in game state
		void draw();

		/// \brief
		/// Update score
		/// \details
		/// Update score in game state
		void update_score(int score);

		/// \brief
		/// Update fuel
		/// \details
		/// Update fuel in game state
		void update_fuel(int fuel);

	};

}

#endif //score_display.h
