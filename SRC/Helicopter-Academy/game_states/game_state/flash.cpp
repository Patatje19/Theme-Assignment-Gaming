#include "flash.h"

namespace academy {
	flash::flash(game_data_ref data) : _data(data) {
		_shape = sf::RectangleShape(sf::Vector2f((float)_data->window.getSize().x, (float)_data->window.getSize().y));
		_shape.setFillColor(sf::Color(255, 190, 0, 0));

		_flash_on = true;

	}

	void flash::show(float dt) {
		if (_flash_on) {
			_alpha = _shape.getFillColor().a + (FLASH_SPEED * dt);

			if (_alpha >= 255.0f) {
				_alpha    = 255.0f;
				_flash_on = false;

			}

			_shape.setFillColor(sf::Color(255, 190, 0, (sf::Uint8)_alpha));

		}

		else {
			_alpha = _shape.getFillColor().a - (FLASH_SPEED * dt);

			if (_alpha <= 0.0f) {
				_alpha = 0.0f;

			}

			_shape.setFillColor(sf::Color(255, 190, 0, (sf::Uint8)_alpha));

		}

	}

	void flash::draw() {
		_data->window.draw(_shape);

	}

}
