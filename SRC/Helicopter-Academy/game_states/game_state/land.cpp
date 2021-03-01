#include "land.h"

namespace academy {
	land::land(game_data_ref data) : _data(data) {
		_land_spawn_y_offset = 0;

	}

	void land::spawn_land_low(std::string land) {
		sf::Sprite sprite(this->_data->assets.get_texture(land));

		sprite.setPosition
		((float)this->_data->window.getSize().x,
		this->_data->window.getSize().y - sprite.getLocalBounds().height - _land_spawn_y_offset + 250);

		_land_sprites.push_back(sprite);

	}

	void land::spawn_land_high(std::string land) {
		sf::Sprite sprite(this->_data->assets.get_texture(land));

		sprite.setPosition
		((float)this->_data->window.getSize().x,
		this->_data->window.getSize().y - sprite.getLocalBounds().height - _land_spawn_y_offset - 500);

		_land_sprites.push_back(sprite);

	}

	void land::move_land(float dt , int score) {
		for (unsigned short int i = 0; i < _land_sprites.size(); i++) {
			if (_land_sprites.at(i).getPosition().x < 0 - _land_sprites.at(i).getLocalBounds().width) {
				_land_sprites.erase(_land_sprites.begin() + i);

			}

			else {
				if (score < 20) {
					float movement = LAND_MOVEMENT_SPEED * dt;

					_land_sprites.at(i).move(-movement, 0);

				}

				else {
					float movement = LAND_MOVEMENT_SPEED * dt * (float)1.7;

					_land_sprites.at(i).move(-movement, 0);

				}

			}

		}
	}

	void land::draw_land() {
		for (unsigned short int i = 0; i < _land_sprites.size(); i++) {
			this->_data->window.draw(_land_sprites.at(i));

		}

	}

	void land::randomise_land_offset() {
		_land_spawn_y_offset = rand() % (150);

	}

	const std::vector<sf::Sprite>& land::get_sprites() const {
		return _land_sprites;

	}

}
