#include "collision.h"

namespace academy {
	bool collision::check_sprite_collision(sf::Sprite sprite0, sf::Sprite sprite1) {
		sf::Rect<float> rect0 = sprite0.getGlobalBounds();
		sf::Rect<float> rect1 = sprite1.getGlobalBounds();

		if (rect0.intersects(rect1)) {
			return true;

		}

		else {
			return false;
		
		}

	}

	bool collision::check_sprite_collision(sf::Sprite sprite0, float scale0, sf::Sprite sprite1, float scale1) {
		sprite0.setScale(scale0, scale0);
		sprite1.setScale(scale1, scale1);

		sf::Rect<float> rect0 = sprite0.getGlobalBounds();
		sf::Rect<float> rect1 = sprite1.getGlobalBounds();

		if (rect0.intersects(rect1)) {
			return true;

		}

		else {
			return false;
		
		}

	}

	sf::Vector2f collision::get_position(sf::Sprite spritebullet) {
		return spritebullet.getPosition();

	}

}
