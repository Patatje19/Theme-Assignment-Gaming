#ifndef WALL_H
#define WALL_H

#include <SFML/Graphics.hpp>
#include <vector>

#include "../../definitions.h"
#include "../../game_engine/game.h"

/// @file

namespace academy {
	/// \brief
	/// Add moving walls
	/// \details
	/// Class for adding moving walls to game state
	class wall {
	private:
		game_data_ref _data;

		std::vector<sf::Sprite> _wall_sprites;

		int _wall_spawn_y_offset {};

	public:
		/// \brief
		/// Default contstructor of the wall class
		wall(game_data_ref data);

		/// \brief
		/// Spawning wall
		/// \details
		/// Spawns a wall in game state
		void spawn_walls();

		/// \brief
		/// Move walls
		/// \details
		/// Moves a wall in game state
		void move_walls(float dt , int score);

		/// \brief
		/// Draw walls
		/// \details
		/// Draws a wall in game state
		void draw_walls();

		/// \brief
		/// Randomise wall
		/// \details
		/// Randomise the length of the wall in game state
		void randomise_walls_offset();

		/// \brief
		/// Get wall sprites
		/// \details
		/// Get wall sprites in game state
		std::vector<sf::Sprite>& get_sprites();

	};

}

#endif //wall.h
