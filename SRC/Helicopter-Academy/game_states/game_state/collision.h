#ifndef COLLISION_H
#define COLLISION_H

#include <SFML/Graphics.hpp>

/// @file

namespace academy {
	/// \brief
	/// Add collision
	/// \details
	/// Class for adding collision to game state
	class collision {
	public:
		/// \brief
		/// Default contstructor of the collision class
		collision() {};

		/// \brief
		/// Check sprite collision
		/// \details
		/// Check if sprite is hitting something
		bool check_sprite_collision(sf::Sprite sprite0, sf::Sprite sprite1);

		/// \brief
		/// Check sprite collision (precise)
		/// \details
		/// Check if sprite is hitting something more precisely
		bool check_sprite_collision(sf::Sprite sprite0, float scale0, sf::Sprite sprite1, float scale1);
		
		sf::Vector2f get_position(sf::Sprite spritebullet); 

	};

}

#endif //collision.h
