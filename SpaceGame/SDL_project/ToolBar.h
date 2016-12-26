#pragma once
#include "GUI.h"
#include "Level.h"
#include "RoomDesign.h"
#include "Hydroponics.h"


class ToolBar : public GUI
{
public:
	ToolBar();
	~ToolBar();
	
	//! Function that renders the toolbar
	void ToolBar::RenderToolbar(SDL_Renderer* renderer, int WINDOW_WIDTH, int WINDOW_HEIGHT, int mouseX, int mouseY);

	void ToolBar::ToolBarFunctionality(Level& room, RoomDesign& designroom,SDL_Renderer* renderer, int mouseX, int mouseY);

	//! The getters and setters for the toolbar selection
	int getToolbarSelection() const { return toolbarSelection; }
	int setToolbarSelection(int newToolbarSelection) { return toolbarSelection = newToolbarSelection; }

	bool ToolBar::isMouseInToolBar();
	

	//! Is the texture for the toolbar background
	Texture toolBarBackground;
	//! Is the texture for the room cell
	Texture roomCell;
	//! Is the texture for teh empty cell
	Texture emptyCell;
	//! Is the texture for the empty cell icon
	Texture emptyCellIcon;
	//! Is the texture for the door
	Texture DoorTexture;
	//! Is the texture for the door
	Texture HydroponicsIconTexture;

	// IconSize
	int toolbarIconSize = 50;

	// How much they increase in size when mouseover
	int mouseOverSizeIncrease = 10;

	int numberOfItem1 = 5;
	int numberOfItem2 = 5;
	int numberOfItem3 = 5;
	int numberOfItem4 = 5;


private:
	int toolbarSelection = 1;

};

