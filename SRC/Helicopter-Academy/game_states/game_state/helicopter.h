#ifndef HELICOPTER_H
#define HELICOPTER_H

#include <SFML/Graphics.hpp>
#include <vector>

#include "../../definitions.h"
#include "../../game_engine/game.h"

/// @file

namespace academy {
	/// \brief
	/// Add flying helicopter
	/// \details
	/// Class for adding a flying helicopter to game state
	class helicopter {
	private:
		game_data_ref _data;

		sf::Sprite _helicopter_sprite;
		std::vector<sf::Texture> _animation_frames;

		sf::Clock _clock;
		sf::Clock _movement_clock;

		unsigned int _animation_iterator {};

		int _helicopter_state {};

		float _rotation {};

	public:
		/// \brief
		/// Default contstructor of the helicopter class
		helicopter(game_data_ref data);

		/// \brief
		/// Drawing helicopter
		/// \details
		/// Draws a helicopter in game state
		void draw();

		/// \brief
		/// Animating helicopter
		/// \details
		/// Animates a helicopter in game state
		void animate(float dt);

		void set_range();

		/// \brief
		/// Updating helicopter
		/// \details
		/// Updates a helicopter in game state
		void update(float dt);

		/// \brief
		/// Click mouse
		/// \details
		/// If activated helicopter will fly up
		void click_mouse();

		/// \brief
		/// Press button up or W
		/// \details
		/// If activated helicopter will fly up
		void press_button_up();

		/// \brief
		/// Press button down or S
		/// \details
		/// If activated helicopter will fly down
		void press_button_down();

		/// \brief
		/// Press button right or D
		/// \details
		/// If activated helicopter will fly "forward"
		void press_button_right();

		/// \brief
		/// Press button down or S
		/// \details
		/// If activated helicopter will fly "backward"
		void press_button_left();

		/// \brief
		/// Get helicopter sprite
		const sf::Sprite &get_sprite() const;

	};

}

#endif //helicopter.h
