/*
** Odin 2 Synthesizer Plugin
** Copyright (C) 2020 - 2021 TheWaveWarden
**
** Odin 2 is free software: you can redistribute it and/or modify
** it under the terms of the GNU General Public License as published by
** the Free Software Foundation, either version 3 of the License, or
** (at your option) any later version.
**
** Odin 2 is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
*/

#pragma once

#include "../GlobalIncludes.h"
#include "../JuceLibraryCode/JuceHeader.h"
#include "Knob.h"
#include "OdinControlAttachments.h"
#include "XYPadComponent.h"

#define MODX_POS_X (264 - 150)
#define MODX_POS_Y (564 - 502)
#define MODY_POS_X (264 - 150)
#define MODY_POS_Y (521 - 502)

#define XY_PAD_POSIITON_Y 4

class XYSectionComponent : public Component {
public:
	XYSectionComponent(AudioProcessorValueTreeState &vts, const std::string &p_section_name);
	~XYSectionComponent();

	void paint(Graphics &) override;

	void setGUIBig();
	void setGUISmall();

private:
	bool m_GUI_big = true;

	std::string m_section_name;
	AudioProcessorValueTreeState &m_value_tree;

	Knob m_modx;
	Knob m_mody;

	std::unique_ptr<OdinKnobAttachment> m_x_attach;
	std::unique_ptr<OdinKnobAttachment> m_y_attach;

	XYPadComponent m_xy_pad;

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(XYSectionComponent)
};
