#ifndef ANIMATION_H
#define ANIMATION_H

#include <SFML/Graphics.hpp>

#include "../../definitions.h"
#include "../../game_engine/game.h"

/// @file

namespace academy {
	/// \brief
	/// Add game animation
	/// \details
	/// Class for adding a game animation to game state
	class animation {
	private:
		game_data_ref _data;

		std::vector<sf::IntRect> frames;

		sf::Sprite sprite;
		sf::Texture t;

		int n {};

	public:
		sf::Vector2f position;

		bool show {};
		
		float frame {};
		float speed {};

		/// \brief
		/// Default contstructor of the animation class
		animation(game_data_ref data, std::string s, float x, float y, float w, float h, int count, float Speed);

		/// \brief
		/// Draw animations
		/// \details
		/// Draw animations in game state
		void draw(sf::Vector2f pos);

		/// \brief
		/// Update animations
		/// \details
		/// Update animations in game state
		void update();

		/// \brief
		/// If animation ends
		bool isEnd();

	};

}

#endif //animation.h
