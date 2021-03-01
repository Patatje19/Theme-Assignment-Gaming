#include "splash_state.h"

namespace academy {
	void splash_state::init() {
		this->_data->assets.load_texture("splash_state_background", SPLASH_SCENE_BACKGROUND_FILEPATH);

		_background.setTexture(this->_data->assets.get_texture("splash_state_background"));

	}

	void splash_state::handle_input() {
		sf::Event event;

		while (this->_data->window.pollEvent(event)) {
			if (sf::Event::Closed == event.type) {
				this->_data->window.close();

			}

		}

	}

	void splash_state::update(float dt) {
		if (this->_clock.getElapsedTime().asSeconds() > SPLASH_STATE_SHOW_TIME) {
			this->_data->machine.add_state(state_ref(new main_menu_state(_data)), true);

		}

	}

	void splash_state::draw(float dt) {
		this->_data->window.clear(sf::Color::Red);

		this->_data->window.draw(this->_background);

		this->_data->window.display();

	}

}
