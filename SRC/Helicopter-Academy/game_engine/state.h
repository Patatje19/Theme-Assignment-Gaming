#ifndef STATE_H
#define STATE_H

/// @file

namespace academy {
	/// \brief
	/// Template class for states
	/// \details
	/// A template class to use for the different game states
	class state {
	public:
		/// \brief
		/// Default method to initialize a state
		virtual void init() = 0;

		/// \brief
		/// Default method to handle state input 
		virtual void handle_input() = 0;

		/// \brief
		/// Default method to update a state
		virtual void update( float dt ) = 0;

		/// \brief
		/// Default method to draw a state
		virtual void draw( float dt ) = 0;

		/// \brief
		/// Default method to pause a state
		virtual void pause() {}

		/// \brief
		/// Default method to resume a state
		virtual void resume() {}

	};

}

#endif //state.h
