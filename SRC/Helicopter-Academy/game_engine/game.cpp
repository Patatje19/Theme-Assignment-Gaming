#include "game.h"
#include "../game_states/splash_state.h"

namespace academy {
	game::game(int width, int height, std::string title) {
		srand((unsigned int)time(NULL));

		_data->window.create(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar);
		_data->machine.add_state(state_ref(new splash_state(this->_data)));

		this->run();

	}

	void game::run() {
		float new_time, frame_time, interpolation;

		float current_time = this->_clock.getElapsedTime().asSeconds();
		float accumulator = 0.0f;

		while (this->_data->window.isOpen()) {
			this->_data->machine.process_state_changes();

			new_time = this->_clock.getElapsedTime().asSeconds();
			frame_time = new_time - current_time;

			if (frame_time > 0.25f) {
				frame_time = 0.25f;

			}

			current_time = new_time;
			accumulator += frame_time;

			while (accumulator >= dt) {
				this->_data->machine.get_active_state()->handle_input();
				this->_data->machine.get_active_state()->update(dt);

				accumulator -= dt;

			}

			interpolation = accumulator / dt;
			this->_data->machine.get_active_state()->draw(interpolation);

		}

	}

}
