#include "fuel_bar.h"

namespace academy {
	fuel_bar::fuel_bar(game_data_ref data) : _data(data) {
		texture_gray.loadFromFile(GRAY_BAR_FILEPATH);
		texture_green.loadFromFile(GREEN_BAR_FILEPATH);

		sprite_gray.setTexture(texture_gray);
		sprite_green.setTexture(texture_green);
		
		sprite_gray.setScale(sf::Vector2f((float)0.4, (float)0.4));
		sprite_green.setScale(sf::Vector2f((float)0.4, (float)0.4));

	}

	void fuel_bar::update_green_bar() {
		sprite_green.setScale(sf::Vector2f((fuel_percentage * (float)0.4)/100, (float)0.4));

	}

	void fuel_bar::update() {
		update_green_bar();

	}

	void fuel_bar::set_fuel_percentage(int n) {
		if (n > 100) {
			fuel_percentage = 100;

		}

		else if (n < 0) {
			fuel_percentage = 0;

		}

		else {
			fuel_percentage = n;

		}

	}

	void fuel_bar::draw() {
		update();

		_data->window.draw(sprite_gray);
		_data->window.draw(sprite_green);

	}

}
