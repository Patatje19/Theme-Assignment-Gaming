#ifndef ENEMY_H
#define ENEMY_H

#include <SFML/Graphics.hpp>
#include <vector>

#include "../../definitions.h"
#include "../../game_engine/game.h"

/// @file

namespace academy {
	/// \brief
	/// Add enemy
	/// \details
	/// Class for adding a enemys to game state
	class enemy {
	private:
		game_data_ref _data;

		std::vector<sf::Sprite> _enemy_sprites;

		int _enemy_spawn_y_offset {};

		float _upspeed {};

	public:
		/// \brief
		/// Default contstructor of the enemy class
		enemy(game_data_ref data);

		/// \brief
		/// Spawn enemys
		/// \details
		/// Spawns enemys in game state
		void spawn_enemys();

		/// \brief
		/// Move enemys
		/// \details
		/// Move enemys in game state
		void move_enemys(float dt , int score );

		/// \brief
		/// Draw enemys
		/// \details
		/// Draw enemys in game state
		void draw_enemys();

		/// \brief
		/// Randomise enemys
		/// \details
		/// Randomise enemys in game state
		void randomise_enemys_offset();

		/// \brief
		/// Set upspeed
		/// \details
		/// Set upspeed in game state
		void set_upspeed(float a);

		/// \brief
		/// Get upspeed
		/// \details
		/// Get upspeed in game state
		int get_upspeed();

		/// \brief
		/// Get enemy sprites
		/// \details
		/// Get enemy sprites in game state
		std::vector<sf::Sprite>& get_sprites();

	};

}

#endif //enemy.h
