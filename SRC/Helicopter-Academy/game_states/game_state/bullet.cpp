#include "bullet.h"

namespace academy {
	void bullet::spawn_bullets(sf::Vector2f new_position) {
		sf::Sprite sprite(this->_data->assets.get_texture("bullet"));

		sprite.setPosition(new_position);

		_bullet_sprites.push_back(sprite);

	}

	void bullet::move_bullets(float dt) {
		for (unsigned short int i = 0; i < _bullet_sprites.size(); i++) {
			if (_bullet_sprites.at(i).getPosition().x < 0 - _bullet_sprites.at(i).getLocalBounds().width) {
				_bullet_sprites.erase(_bullet_sprites.begin() + i);

			}

			else {
				float movement = BULLET_MOVEMENT_SPEED * dt;

				_bullet_sprites.at(i).move(-movement, 0);

			}

		}

	}

	void bullet::draw_bullets() {
		for (unsigned short int i = 0; i < _bullet_sprites.size(); i++) {
			this->_data->window.draw(_bullet_sprites.at(i));

		}

	}

	std::vector<sf::Sprite>& bullet::get_sprites() {
		return _bullet_sprites;

	}

}
