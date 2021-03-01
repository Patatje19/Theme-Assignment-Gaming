#ifndef BULLET_H
#define BULLET_H

#include <SFML/Graphics.hpp>
#include <vector>

#include "../../definitions.h"
#include "../../game_engine/game.h"

/// @file

namespace academy {
	/// \brief
	/// Add bullets
	/// \details
	/// Class for adding bullets to game state
	class bullet {
	private:
		game_data_ref _data;

		std::vector<sf::Sprite> _bullet_sprites;

	public:
		/// \brief
		/// Default contstructor of the bullet class
		bullet(game_data_ref data) : _data(data) {};

		/// \brief
		/// Spawn bullets
		/// \details
		/// Spawns bullets in game state
		void spawn_bullets(sf::Vector2f new_position);

		/// \brief
		/// Move bullets
		/// \details
		/// Move bullets in game state
		void move_bullets(float dt);

		/// \brief
		/// Draws bullets
		/// \details
		/// Draws bullets in game state
		void draw_bullets();

		/// \brief
		/// Get bullet sprites
		/// \details
		/// Get bullet sprites in game state
		std::vector<sf::Sprite>& get_sprites();

	};

}

#endif //bullet.h
