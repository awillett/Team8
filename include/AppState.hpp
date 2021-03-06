////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// AppState.hpp
// Robert M. Baker | Created : 11MAR12 | Last Modified : 11MAR12 by Robert M. Baker
// Version : 1.0.0
// This is a header file for 'Game'; it defines the interface for an application state class.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
  * @file
  * @author  Robert M. Baker
  * @date    Created : 11MAR12
  * @date    Last Modified : 11MAR12 by Robert M. Baker
  * @version 1.0.0
  *
  * @brief This header file defines the interface for an application state class.
  *
  * @section Description
  *
  * This header file defines the interface for an application state class.
  */

#ifndef __QMX_GAME_APPSTATE_HPP_
#define __QMX_GAME_APPSTATE_HPP_

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Header Files
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "Base.hpp"

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Start of the 'Game' Namespace
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace Game
{

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// The 'AppState' Class
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
  * @class AppState AppState.hpp "include/AppState.hpp"
  *
  * @brief This class defines application state algorithms.
  *
  * These algorithms are useful when it is necessary to break an application into discrete states.
  *
  * Platform Independent     : Yes
  * Architecture Independent : Yes
  * Thread-Safe              : No
  */

class AppState
{
public:

	// Public Constructors

		/**
		  * @brief This is the default constructor.
		  */

		AppState()
		{
			// Do nothing.
		}

	// Destructor

		/**
		  * @brief This is the destructor.
		  */

		virtual ~AppState() noexcept
		{
			// Do nothing.
		}

	// Public Methods

		/**
		  * @brief This method performs necessary state initialization.
		  */

		void Enter()
		{
			// Perform necessary state initialization.

				EnterImp();
		}

		/**
		  * @brief This method performs necessary state cleanup.
		  */

		void Exit()
		{
			// Perform necessary state cleanup.

				ExitImp();
		}

		/**
		  * @brief This method performs state pause logic.
		  */

		void Pause()
		{
			// Perform state pause logic.

				PauseImp();
		}

		/**
		  * @brief This method performs state resume logic.
		  */

		void Resume()
		{
			// Perform state resume logic.

				ResumeImp();
		}

		/**
		  * @brief This method performs state frame logic.
		  */

		void Logic()
		{
			// Perform state frame logic.

				LogicImp();
		}

private:

	// Private Methods

		/**
		  * @brief This is the overridable implementation for the 'Enter' method.
		  */

		virtual void EnterImp() = PURE_VIRTUAL;

		/**
		  * @brief This is the overridable implementation for the 'Exit' method.
		  */

		virtual void ExitImp() = PURE_VIRTUAL;

		/**
		  * @brief This is the overridable implementation for the 'Pause' method.
		  */

		virtual void PauseImp() = PURE_VIRTUAL;

		/**
		  * @brief This is the overridable implementation for the 'Resume' method.
		  */

		virtual void ResumeImp() = PURE_VIRTUAL;

		/**
		  * @brief This is the overridable implementation for the 'Logic' method.
		  */

		virtual void LogicImp() = PURE_VIRTUAL;
};

} // 'Game' Namespace

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// End of the 'Game' Namespace
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif // __QMX_GAME_APPSTATE_HPP_

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// End of 'AppState.hpp'
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
