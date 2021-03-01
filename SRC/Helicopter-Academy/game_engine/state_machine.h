#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H

#include <memory>
#include <stack>

#include "state.h"

/// @file

namespace academy {
	typedef std::unique_ptr<state> state_ref;

	/// \brief
	/// Game engine state machine
	/// \details
	/// Class to add, remove and process game states
	class state_machine {
	private:
		std::stack<state_ref> _states;

		state_ref _new_state;

		bool _is_removing {};
		bool _is_adding {};
		bool _is_replacing {};

	public:
		/// \brief
		/// Default contstructor of the state machine class
		state_machine() {};

		/// \brief
		/// Add state
		/// \details
		/// Add state to stack
		void add_state(state_ref new_state, bool is_replacing = true);

		/// \brief
		/// Remove state
		/// \details
		/// Remove state from stack
		void remove_state();

		/// \brief
		/// Process changes
		/// \details
		/// Run at start of each loop in game.cpp;
		/// Process state changes from stack
		void process_state_changes();

		/// \brief
		/// Get active state
		state_ref &get_active_state();

	};

}

#endif //state_machine.h
