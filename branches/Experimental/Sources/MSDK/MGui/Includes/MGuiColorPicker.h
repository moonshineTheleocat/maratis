/////////////////////////////////////////////////////////////////////////////////////////////////////////
// MGui
// MGuiColorPicker.h
/////////////////////////////////////////////////////////////////////////////////////////////////////////

//========================================================================
// Copyright (c) 2012-2013 Anael Seghezzi <www.maratis3d.com>
//
// This software is provided 'as-is', without any express or implied
// warranty. In no event will the authors be held liable for any damages
// arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it
// freely, subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented; you must not
//    claim that you wrote the original software. If you use this software
//    in a product, an acknowledgment in the product documentation would
//    be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such, and must not
//    be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source
//    distribution.
//
//========================================================================

#ifndef _M_GUI_COLOR_PICKER_H
#define _M_GUI_COLOR_PICKER_H


class M_GUI_EXPORT MGuiColorPicker
{
private:
	
	MGuiWindow * m_window;
	MGuiButton * m_parentButton;
	MGuiButton * m_colorSel;
	MGuiButton * m_tintSel;
	MGuiImage * m_colorTarget;
	MGuiImage * m_tintTarget;
	
	MVector3 m_HSVColor;

	MFontRef * m_font;
	
	float * m_R;
	float * m_G;
	float * m_B;
	float * m_A;
	
	void updateTargets(void);
	void updateRGBColor(void);
	void updateHSVColor(void);
	static void onValueEvents(MGuiEditText * editText, MGUI_EVENT_TYPE event);
	static void winColorEvents(MGuiWindow * window, MGUI_EVENT_TYPE event);
	static void winColorDraw(MGuiWindow * window);
	
	void addValue(MGuiWindow * window, MVector2 * position, const char * name, MFontRef * font, M_VARIABLE_TYPE varType, void * pointer, void (* eventCallback)(MGuiEditText * editText, MGUI_EVENT_TYPE event));
	
public:
	
	MGuiColorPicker(MWindow * rootWindow, MFontRef * font);
	~MGuiColorPicker(void);
	
	void open(MGuiButton * parentButton, float * R, float * G, float * B, float * A);
	void close(void);
	
	void draw(MGuiWindow * window);
};

#endif