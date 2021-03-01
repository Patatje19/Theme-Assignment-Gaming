#ifndef FUEL_BAR_H
#define FUEL_BAR_H

#include <SFML/Graphics.hpp>
#include <vector>

#include "../../definitions.h"
#include "../../game_engine/game.h"

/// @file

namespace academy {
	/// \brief
	/// Add fuel bar
	/// \details
	/// Class for adding a fuel bar to game state
	class fuel_bar {
	private:
		game_data_ref _data;

		sf::Vector2f position = sf::Vector2f(3.0, 3.0);

		sf::Sprite sprite_green, sprite_gray;
		sf::Texture texture_green, texture_gray;

		int fuel_percentage {};

		/// \brief
		/// Update green bar
		/// \details
		/// Update green bar in game state
		void update_green_bar();

		/// \brief
		/// Calls update green bar
		void update();

	public:
		/// \brief
		/// Default contstructor of the fuel bar class
		fuel_bar(game_data_ref data);

		/// \brief
		/// Set fuel percentage
		/// \details
		/// Set fuel percentage in game state
		void set_fuel_percentage(int n);

		/// \brief
		/// Draw fuels
		/// \details
		/// Draw fuel bar in game state
		void draw();

	};

}

#endif //fuel_bar.h
