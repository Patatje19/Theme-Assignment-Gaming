#ifndef FUEL_H
#define FUEL_H

#include <SFML/Graphics.hpp>
#include <vector>

#include "../../definitions.h"
#include "../../game_engine/game.h"

/// @file

namespace academy {
	/// \brief
	/// Add fuel
	/// \details
	/// Class for adding a fuel to game state
	class fuel {
	private:
		game_data_ref _data;

		std::vector<sf::Sprite> _fuel_sprites;

		int _fuel_spawn_y_offset {};

	public:
		/// \brief
		/// Default contstructor of the fuel class
		fuel(game_data_ref data);

		/// \brief
		/// Spawn fuels
		/// \details
		/// Spawns fuels in game state
		void spawn_fuels();

		/// \brief
		/// Move fuels
		/// \details
		/// Move fuels in game state
		void move_fuels(float dt , int score);

		/// \brief
		/// Draw fuels
		/// \details
		/// Draw fuels in game state
		void draw_fuels();

		/// \brief
		/// Randomise fuels
		/// \details
		/// Randomise fuels in game state
		void randomise_fuels_offset();

		/// \brief
		/// Get fuel sprites
		/// \details
		/// Get fuel sprites in game state
		std::vector<sf::Sprite> &get_sprites();

	};

}

#endif //fuel.h
