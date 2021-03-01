#include "fuel.h"

namespace academy {
	fuel::fuel(game_data_ref data) : _data(data) {
		_fuel_spawn_y_offset = 0;

	}

	void fuel::spawn_fuels() {
		sf::Sprite sprite(this->_data->assets.get_texture("fuels"));

		sprite.setPosition
		((float)this->_data->window.getSize().x,
		this->_data->window.getSize().y - sprite.getLocalBounds().height - _fuel_spawn_y_offset - 250);

		_fuel_sprites.push_back(sprite);

	}

	void fuel::move_fuels(float dt , int score) {
		for (unsigned short int i = 0; i < _fuel_sprites.size(); i++) {
			if (_fuel_sprites.at(i).getPosition().x < 0 - _fuel_sprites.at(i).getLocalBounds().width) {
				_fuel_sprites.erase(_fuel_sprites.begin() + i);

			}

			else {
				if (score < 20) {
					float movement = LAND_MOVEMENT_SPEED * dt;

					_fuel_sprites.at(i).move(-movement, 0);

				}

				else {
					float movement = LAND_MOVEMENT_SPEED * dt * (float)1.7;

					_fuel_sprites.at(i).move(-movement, 0);

				}

			}

		}
	}

	void fuel::draw_fuels() {
		for (unsigned short int i = 0; i < _fuel_sprites.size(); i++) {
			this->_data->window.draw(_fuel_sprites.at(i));

		}

	}

	void fuel::randomise_fuels_offset() {
		_fuel_spawn_y_offset = rand() % ( 400);

	}

	std::vector<sf::Sprite>& fuel::get_sprites() {
		return _fuel_sprites;

	}

}
