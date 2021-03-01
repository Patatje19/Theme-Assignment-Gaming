#ifndef GAME_STATE_H
#define GAME_STATE_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "game_over.h"

#include "../definitions.h"
#include "../game_engine/state.h"
#include "../game_engine/game.h"

#include "game_state/wall.h"
#include "game_state/land.h"
#include "game_state/helicopter.h"
#include "game_state/collision.h"
#include "game_state/flash.h"
#include "game_state/score_display.h"
#include "game_state/fuel.h"
#include "game_state/fuel_bar.h"
#include "game_state/bullet.h"
#include "game_state/enemy.h"
#include "game_state/animation.h"

/// @file

namespace academy {
	/// \brief
	/// Class for game state
	/// \details
	/// Class to use in the game state
	class game_state : public state {
	private:
		game_data_ref _data;
		
		int _game_state {};
		int _score {};
		int _fuelnum {};
		
		int _turn_background {};
		int _turn_land {};

		bool _change_background = true;
		bool _change_land = true;

		sf::Sprite _background_0;
		sf::Sprite _background_1;

		sf::Clock clock;
		sf::Clock clock1;
		sf::Clock clock2;
		sf::Clock clock3;
		sf::Clock clock4;
		sf::Clock clock5;
		sf::Clock clock6;
	
		sf::Music _background_music;

		sf::SoundBuffer _hit_sound_buffer;
		sf::SoundBuffer _wing_sound_buffer;
		sf::SoundBuffer _point_sound_buffer;

		sf::Sound _hit_sound;
		sf::Sound _wing_sound;
		sf::Sound _point_sound;

		wall* _wall {};
		land* _land {};
		helicopter* _helicopter {};
		flash* _flash {};
		fuel* _fuel {};
		fuel_bar* _fuel_bar {};
		bullet* _bullet {};
		enemy* _enemy {};
		animation* _enemy_die {};
		animation* _explosion {};

		score_display* _score_display {};

		collision _collision {};
		
	public:
		/// \brief
		/// Default contstructor of the game state class
		game_state(game_data_ref data) : _data(data) {};

		/// \brief
		/// Method to initialize game state
		void init();

		/// \brief
		/// Method to handle game state input
		void handle_input();

		/// \brief
		/// Method to update game state 
		void update(float dt);

		/// \brief
		/// Method to draw game state
		void draw(float dt);

	};

}

#endif //game_state.h