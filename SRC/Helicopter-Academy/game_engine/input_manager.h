#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H

#include "SFML\Graphics.hpp"

/// @file

namespace academy {
	/// \brief
	/// Game engine input manager
	/// \details
	/// Class to register user inputs
	class input_manager {
	public:
		/// \brief
		/// Default contstructor of the input manager class
		input_manager() {};

		/// \brief
		/// Check if user mouse-clicked a object 
		/// \details
		/// @param object 
		/// @param button 
		/// @param &window
		bool is_sprite_clicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow &window);

		/// \brief
		/// Check if user pressed a keyboard-button 
		/// \details
		/// @param object 
		/// @param button 
		/// @param &window
		bool is_button_pressed(sf::Keyboard::Key button);

		/// \brief
		/// Get mouse position
		/// \details
		/// @param &window
		sf::Vector2i get_mouse_position(sf::RenderWindow &window);

	};

}

#endif //input_manager.h
