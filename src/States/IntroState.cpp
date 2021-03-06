////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// IntroState.cpp
// Robert M. Baker | Created : 11MAR12 | Last Modified : 12MAR12 by Robert M. Baker
// Version : 1.0.0
// This is a source file for 'Game'; it defines the implementation for an application intro state class.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
  * @file
  * @author  Robert M. Baker
  * @date    Created : 11MAR12
  * @date    Last Modified : 12MAR12 by Robert M. Baker
  * @version 1.0.0
  *
  * @brief This source file defines the implementation for an application intro state class.
  *
  * @section Description
  *
  * This source file defines the implementation for an application intro state class.
  */

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Header Files
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <States/IntroState.hpp>

using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Start of the 'Game' Namespace
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace Game
{

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Static Field Initializers for the 'IntroState' Class
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<> IntroState* Singleton< IntroState >::SingletonInstance = nullptr;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Public Methods for the 'IntroState' Class
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

IntroState::IntroState()
{
	// Do nothing.
}

IntroState::~IntroState() noexcept
{
	// Do nothing.
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Private Methods for the 'IntroState' Class
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void IntroState::EnterImp()
{
	// Perform necessary state initialization.

		VIDEOMANAGER.LoadTexture( "Background", "./resources/video/textures/background.png" );
}

void IntroState::ExitImp()
{
	// Perform necessary state cleanup.

		VIDEOMANAGER.UnloadTexture( "Background" );
}

void IntroState::PauseImp()
{
	// Perform state pause logic.

		//
}

void IntroState::ResumeImp()
{
	// Perform state resume logic.

		//
}

void IntroState::LogicImp()
{
	// Create local variables.

		static uint8_t State = 0;
		static double BaseTime = Null;
		static uint32_t Alpha = 0x00000000;

	// Perform state frame logic.

		switch( State )
		{
			case 0:
			{
				if( Alpha < 255 )
					Alpha += 1;
				else
				{
					State++;
					BaseTime = glfwGetTime();
				}

				break;
			}

			case 1:
			{
				if( ( glfwGetTime() - BaseTime ) >= 5.0 )
					State++;

				break;
			}

			case 2:
			{
				if( Alpha > 0 )
					Alpha -= 1;
				else
					State++;

				break;
			}

			case 3:
			{
				//

				break;
			}
		}

		VIDEOMANAGER.QueueQuad( 0, "Background", { 0, 0, VIDEOMANAGER.GetScreenWidth(), VIDEOMANAGER.GetScreenHeight(), ( 0xFFFFFF00 | Alpha ), 0.0f, 1.0f, 1.0f, 0.0f } );
}

} // 'Game' Namespace

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// End of the 'Game' Namespace
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// End of 'IntroState.cpp'
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
