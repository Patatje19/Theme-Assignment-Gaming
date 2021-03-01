#include "enemy.h"

namespace academy {
	enemy::enemy(game_data_ref data) : _data(data) {
		_enemy_spawn_y_offset = 0;
		_upspeed = 2;

	}

	void enemy::spawn_enemys() {
		sf::Sprite sprite(this->_data->assets.get_texture("enemys"));
		sprite.setPosition
		((float)this->_data->window.getSize().x,
		this->_data->window.getSize().y - sprite.getLocalBounds().height - 250);

		_enemy_sprites.push_back(sprite);

	}

	void enemy::move_enemys(float dt , int score) {
		for (unsigned short int i = 0; i < _enemy_sprites.size(); i++) {
			if (_enemy_sprites.at(i).getPosition().x < 0 - _enemy_sprites.at(i).getLocalBounds().width) {
				_enemy_sprites.erase(_enemy_sprites.begin() + i);

			}

			else {
				if (score < 20) {
					float movement = WALL_MOVEMENT_SPEED * dt;

					_enemy_sprites.at(i).move(-movement, _upspeed);

				}

				else {
					float movement = WALL_MOVEMENT_SPEED * dt * (float)1.7;

					_enemy_sprites.at(i).move(-movement, _upspeed);

				}

			}

		}

	}

	void enemy::draw_enemys() {
		for (unsigned short int i = 0; i < _enemy_sprites.size(); i++) {
			this->_data->window.draw(_enemy_sprites.at(i));

		}

	}

	void enemy::randomise_enemys_offset() {
		_enemy_spawn_y_offset = rand() % (400);

	}

	std::vector<sf::Sprite>& enemy::get_sprites() {
		return _enemy_sprites;

	}

	void enemy::set_upspeed(float a) {
		_upspeed = a;

	}

	int enemy::get_upspeed() {
		return (int)_upspeed;

	}

}
