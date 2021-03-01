#ifndef GAME_OVER_H
#define GAME_OVER_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <sstream>
#include <fstream>

#include "game_state.h"

#include "../definitions.h"
#include "../game_engine/state.h"
#include "../game_engine/game.h"

/// @file

namespace academy {
	/// \brief
	/// Class for game over state
	/// \details
	/// Class to use in the game over state
	class game_over : public state {
	private:
		game_data_ref _data;

		sf::Music _background_music;

		sf::Sprite _background;

		sf::Sprite _game_over_title;
		sf::Sprite _game_over_container;
		sf::Sprite _retry_button;

		sf::Text _score_text;
		sf::Text _high_score_text;

		int _score {};
		int _high_score {};

	protected:
		/// \brief
		/// Method to read high scores from file
		void read_high_score();

	public:
		/// \brief
		/// Default contstructor of the game over class
		game_over(game_data_ref data, int score) : _data(data), _score(score) {};

		/// \brief
		/// Method to initialize game over state
		void init();

		/// \brief
		/// Method to handle game over state input
		void handle_input();

		/// \brief
		/// Method to update game over state 
		void update(float dt) {};

		/// \brief
		/// Method to draw game over state
		void draw(float dt);

	};

}

#endif //game_over.h