#include "input_manager.h"

namespace academy {
	bool input_manager::is_sprite_clicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow &window) {
		if (sf::Mouse::isButtonPressed(button)) {
			sf::IntRect temp_rect
			((int)object.getPosition().x, (int)object.getPosition().y, 
			(int)object.getGlobalBounds().width, (int)object.getGlobalBounds().height);

			if (temp_rect.contains(sf::Mouse::getPosition(window))) {
				return true;

			}

		}

		return false;

	}

	bool input_manager::is_button_pressed(sf::Keyboard::Key button) {
		return sf::Keyboard::isKeyPressed(button);

	}

	sf::Vector2i input_manager::get_mouse_position(sf::RenderWindow &window) {
		return sf::Mouse::getPosition(window);

	}

}
