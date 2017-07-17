
#ifndef OpenGLScreenH
#define OpenGLScreenH

#include "OpenGLHeader.h"
#include "ComplexRect.h"

class tTVPOpenGLScreen {
	void* NativeHandle;
	//EGLNativeWindowType mNativeWindow;

	EGLConfig mConfig;
	EGLDisplay mDisplay;
	EGLSurface mSurface;
	EGLContext mContext;
	EGLint mSwapInterval;

	int mRedBits;
	int mGreenBits;
	int mBlueBits;
	int mAlphaBits;
	int mDepthBits;
	int mStencilBits;
	int mMinSwapInterval;
	int mMaxSwapInterval;
	bool mMultisample;

	GLint mDefaultFrameBufferId;
#ifdef WIN32
	//EGLNativeWindowType mParentWindow;	// HWND
	//EGLNativeWindowType mNativeWindow;	// HWND
	EGLNativeDisplayType mNativeDisplay;// HDC
#endif
public:
	tTVPOpenGLScreen( void* nativeHandle );

	bool Initialize();
	void Destroy();
	bool IsInitialized() const;

	void Swap() { eglSwapBuffers( mDisplay, mSurface ); }
	EGLConfig GetConfig() const { return mConfig; }
	EGLDisplay GetDisplay() const { return mDisplay; }
	EGLSurface GetSurface() const { return mSurface; }
	EGLContext GetContext() const { return mContext; }

	EGLint GetSurfaceWidth() const;
	EGLint GetSurfaceHeight() const;

	static bool CheckEGLErrorAndLog();

	void SetScissorRect( const tTVPRect& rect );
	void DisableScissorRect();

	GLint GetDefaultFrameBufferId() const { return mDefaultFrameBufferId; }

	void SetWaitVSync( bool b );
};
#endif
