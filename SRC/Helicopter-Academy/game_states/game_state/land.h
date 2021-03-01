#ifndef LAND_H
#define LAND_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

#include "../../definitions.h"
#include "../../game_engine/game.h"

/// @file

namespace academy {
	/// \brief
	/// Add land
	/// \details
	/// Class for adding land to game state
	class land {
	private:
		game_data_ref _data;

		std::vector<sf::Sprite> _land_sprites;

		int _land_spawn_y_offset {};

	public:
		/// \brief
		/// Default contstructor of the land class
		land(game_data_ref data);

		/// \brief
		/// Spawn low land
		/// \details
		/// Spawn low land in game state
		void spawn_land_low(std::string land);

		/// \brief
		/// Spawn high land
		/// \details
		/// Spawn high land in game state
		void spawn_land_high(std::string land);

		/// \brief
		/// Move land
		/// \details
		/// Move land in game state
		void move_land(float dt , int score);

		/// \brief
		/// Draw land
		/// \details
		/// Draw land in game state
		void draw_land();

		/// \brief
		/// Randomise land
		/// \details
		/// Randomise land in game state
		void randomise_land_offset();

		/// \brief
		/// Get land sprites
		/// \details
		/// Get land sprites in game state
		const std::vector<sf::Sprite>& get_sprites() const;

	};

}

#endif //land.h
