////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// VideoManager.hpp
// Robert M. Baker | Created : 15FEB12 | Last Modified : 16FEB12 by Robert M. Baker
// Version : 1.0.0
// This is a header file for 'Game'; it defines the interface for a video manager class.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
  * @file
  * @author  Robert M. Baker
  * @date    Created : 15FEB12
  * @date    Last Modified : 16FEB12 by Robert M. Baker
  * @version 1.0.0
  *
  * @brief This header file defines the interface for a video manager class.
  *
  * @section Description
  *
  * This header file defines the interface for a video manager class.
  */

#ifndef __QMX_GAME_VIDEOMANAGER_HPP_
#define __QMX_GAME_VIDEOMANAGER_HPP_

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Header Files
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <exception>
#include <gl/gl.h>
#include <gl/glu.h>
#include <gl/glaux.h>

#include "Base.hpp"
#include "Singleton.hpp"

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Static Macros
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define VIDEO_MANAGER   VideoManager::GetSingleton()
#define VIDEO_MANAGER_P VideoManager::GetSingletonPointer()

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Start of the 'Game' Namespace
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace Game
{

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// The 'VideoManager' Class
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
  * @class VideoManager VideoManager.hpp "include/VideoManager.hpp"
  *
  * @brief This class defines algorithms for a video manager.
  *
  * These algorithms are useful when it is necessary to draw textured polygons to a window.
  *
  * Platform Independent     : Yes
  * Architecture Independent : Yes
  * Thread-Safe              : No
  */

class VideoManager : public Singleton< VideoManager >
{
public:

	// Public Constructors

		/**
		  * @brief This is the default constructor.
		  */

		VideoManager();

	// Destructor

		/**
		  * @brief This is the destructor.
		  */

		virtual ~VideoManager() noexcept;

	// Public Methods

		/**
		  * @brief This method initializes the video manager.
		  *
		  * @param WindowHandle
		  * 	This is a handle to the window to which the video manager will render.
		  *
		  * @param ScreenWidth
		  * 	This is the horizontal resolution of the render window.
		  *
		  * @param ScreenHeight
		  * 	This is the vertical resolution of the render window.
		  *
		  * @exception std::exception
		  * 	If the input manager fails to initialize properly.
		  */

		void Initialize( const HWND WindowHandle, const GLdouble ScreenWidth, const GLdouble ScreenHeight );

		/**
		  * @brief This method shuts down the video system.
		  */

		void Shutdown();

		/**
		  * @brief This method updates the video system.
		  */

		void Update();

		/**
		  * @brief This method begins rendering.
		  */

		void Begin();

		/**
		  * @brief This method ends rendering.
		  */

		void End();

		/**
		  * @brief This method draws a quad at the specified coordinates with the specified dimensions.
		  */

		void DrawQuad( const GLint Left, const GLint Top, const GLint Width, const GLint Height,
		               const GLfloat Red, const GLfloat Green, const GLfloat Blue );

private:

	// Private Fields

		/**
		  * @brief This is the flag used to determine initialization state.
		  */

		bool Initialized;

		/**
		  * @brief This is the handle to the render window.
		  */

		HWND GLWindowHandle;

		/**
		  * @brief This is the device context handle.
		  */

		HDC GLDeviceContext;

		/**
		  * @brief This is the render context handle.
		  */

		HGLRC GLRenderContext;
};

} // 'Game' Namespace

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// End of the 'Game' Namespace
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif // __QMX_GAME_VIDEOMANAGER_HPP_

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// End of 'VideoManager.hpp'
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
