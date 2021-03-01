#include "wall.h"

namespace academy {
	wall::wall(game_data_ref data) : _data(data) {
		_wall_spawn_y_offset = 0;

	}

	void wall::spawn_walls() {
		sf::Sprite sprite(this->_data->assets.get_texture("walls"));

		sprite.setPosition
		((float)this->_data->window.getSize().x, (float)_wall_spawn_y_offset + 200);

		_wall_sprites.push_back(sprite);

	}

	void wall::move_walls(float dt , int score) {
		for (unsigned short int i = 0; i < _wall_sprites.size(); i++) {
			if (_wall_sprites.at(i).getPosition().x < 0 - _wall_sprites.at(i).getLocalBounds().width) {
				_wall_sprites.erase(_wall_sprites.begin() + i);

			}

			else {
				if (score < 20) {
					float movement = WALL_MOVEMENT_SPEED * dt;

					_wall_sprites.at(i).move(-movement, 0);

				}

				else {
					float movement = WALL_MOVEMENT_SPEED * dt * (float)1.7;

					_wall_sprites.at(i).move(-movement, 0);

				}

			}

		}

	}

	void wall::draw_walls() {
		for (unsigned short int i = 0; i < _wall_sprites.size(); i++) {
			this->_data->window.draw(_wall_sprites.at(i));

		}

	}

	void wall::randomise_walls_offset() {
		_wall_spawn_y_offset = rand() % (200);

	}

	std::vector<sf::Sprite>& wall::get_sprites() {
		return _wall_sprites;

	}

}
