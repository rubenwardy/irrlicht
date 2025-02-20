// Copyright (C) 2002-2012 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

// 07.10.2005 - Multicolor-Listbox addet by A. Buschhueter (Acki)
//                                          A_Buschhueter@gmx.de

#ifndef __C_GUI_TABLE_BAR_H_INCLUDED__
#define __C_GUI_TABLE_BAR_H_INCLUDED__

#include "IrrCompileConfig.h"
#ifdef _IRR_COMPILE_WITH_GUI_

#include "IGUITable.h"
#include "irrArray.h"

namespace irr
{
namespace gui
{

	class IGUIFont;
	class IGUIScrollBar;

	class CGUITable : public IGUITable
	{
	public:
		//! constructor
		CGUITable(IGUIEnvironment* environment, IGUIElement* parent,
			s32 id, const core::rect<s32>& rectangle, bool clip=true,
			bool drawBack=false, bool moveOverSelect=true);

		//! destructor
		~CGUITable();

		//! Adds a column
		//! If columnIndex is outside the current range, do push new column at the end
		virtual void addColumn(const wchar_t* caption, s32 columnIndex=-1) _IRR_OVERRIDE_;

		//! remove a column from the table
		virtual void removeColumn(u32 columnIndex) _IRR_OVERRIDE_;

		//! Returns the number of columns in the table control
		virtual s32 getColumnCount() const _IRR_OVERRIDE_;

		//! Makes a column active. This will trigger an ordering process.
		/** \param idx: The id of the column to make active.
		\return True if successful. */
		virtual bool setActiveColumn(s32 columnIndex, bool doOrder=false) _IRR_OVERRIDE_;

		//! Returns which header is currently active
		virtual s32 getActiveColumn() const _IRR_OVERRIDE_;

		//! Returns the ordering used by the currently active column
		virtual EGUI_ORDERING_MODE getActiveColumnOrdering() const _IRR_OVERRIDE_;

		//! set a column width
		virtual void setColumnWidth(u32 columnIndex, u32 width) _IRR_OVERRIDE_;

		//! Get the width of a column
		virtual u32 getColumnWidth(u32 columnIndex) const _IRR_OVERRIDE_;

		//! columns can be resized by drag 'n drop
		virtual void setResizableColumns(bool resizable) _IRR_OVERRIDE_;

		//! can columns be resized by drag 'n drop?
		virtual bool hasResizableColumns() const _IRR_OVERRIDE_;

		//! This tells the table control which ordering mode should be used when
		//! a column header is clicked.
		/** \param columnIndex: The index of the column header.
		\param state: If true, a EGET_TABLE_HEADER_CHANGED message will be sent and you can order the table data as you whish.*/
		//! \param mode: One of the modes defined in EGUI_COLUMN_ORDERING
		virtual void setColumnOrdering(u32 columnIndex, EGUI_COLUMN_ORDERING mode) _IRR_OVERRIDE_;

		//! Returns which row is currently selected
		virtual s32 getSelected() const _IRR_OVERRIDE_;

		//! set currently selected row
		virtual void setSelected( s32 index ) _IRR_OVERRIDE_;

		//! Returns amount of rows in the tab control
		virtual s32 getRowCount() const _IRR_OVERRIDE_;

		//! adds a row to the table
		/** \param rowIndex: zero based index of rows. The row will be
			inserted at this position. If a row already exists
			there, it will be placed after it. If the row is larger
			than the actual number of rows by more than one, it
			won't be created. Note that if you create a row that is
			not at the end, there might be performance issues*/
		virtual u32 addRow(u32 rowIndex) _IRR_OVERRIDE_;

		//! Remove a row from the table
		virtual void removeRow(u32 rowIndex) _IRR_OVERRIDE_;

		//! clear the table rows, but keep the columns intact
		virtual void clearRows() _IRR_OVERRIDE_;

		//! Swap two row positions. This is useful for a custom ordering algo.
		virtual void swapRows(u32 rowIndexA, u32 rowIndexB) _IRR_OVERRIDE_;

		//! This tells the table to start ordering all the rows. You
		//! need to explicitly tell the table to reorder the rows when
		//! a new row is added or the cells data is changed. This makes
		//! the system more flexible and doesn't make you pay the cost
		//! of ordering when adding a lot of rows.
		//! \param columnIndex: When set to -1 the active column is used.
		virtual void orderRows(s32 columnIndex=-1, EGUI_ORDERING_MODE mode=EGOM_NONE) _IRR_OVERRIDE_;


		//! Set the text of a cell
		virtual void setCellText(u32 rowIndex, u32 columnIndex, const core::stringw& text) _IRR_OVERRIDE_;

		//! Set the text of a cell, and set a color of this cell.
		virtual void setCellText(u32 rowIndex, u32 columnIndex, const core::stringw& text, video::SColor color) _IRR_OVERRIDE_;

		//! Set the data of a cell
		//! data will not be serialized.
		virtual void setCellData(u32 rowIndex, u32 columnIndex, void *data) _IRR_OVERRIDE_;

		//! Set the color of a cell text
		virtual void setCellColor(u32 rowIndex, u32 columnIndex, video::SColor color) _IRR_OVERRIDE_;

		//! Get the text of a cell
		virtual const wchar_t* getCellText(u32 rowIndex, u32 columnIndex ) const _IRR_OVERRIDE_;

		//! Get the data of a cell
		virtual void* getCellData(u32 rowIndex, u32 columnIndex ) const _IRR_OVERRIDE_;

		//! clears the table, deletes all items in the table
		virtual void clear() _IRR_OVERRIDE_;

		//! called if an event happened.
		virtual bool OnEvent(const SEvent &event) _IRR_OVERRIDE_;

		//! draws the element and its children
		virtual void draw() _IRR_OVERRIDE_;

		//! Set flags, as defined in EGUI_TABLE_DRAW_FLAGS, which influence the layout
		virtual void setDrawFlags(s32 flags) _IRR_OVERRIDE_;

		//! Get the flags, as defined in EGUI_TABLE_DRAW_FLAGS, which influence the layout
		virtual s32 getDrawFlags() const _IRR_OVERRIDE_;

		//! Sets another skin independent font.
		virtual void setOverrideFont(IGUIFont* font=0) _IRR_OVERRIDE_;

		//! Gets the override font (if any)
		virtual IGUIFont* getOverrideFont() const _IRR_OVERRIDE_;

		//! Get the font which is used right now for drawing
		virtual IGUIFont* getActiveFont() const _IRR_OVERRIDE_;

		//! Get the height of items/rows
		virtual s32 getItemHeight() const _IRR_OVERRIDE_;

		//! Access the vertical scrollbar
		virtual IGUIScrollBar* getVerticalScrollBar() const _IRR_OVERRIDE_;

		//! Access the horizontal scrollbar
		virtual IGUIScrollBar* getHorizontalScrollBar() const _IRR_OVERRIDE_;

		//! Sets whether to draw the background.
		virtual void setDrawBackground(bool draw) _IRR_OVERRIDE_;

		//! Checks if background drawing is enabled
		/** \return true if background drawing is enabled, false otherwise */
		virtual bool isDrawBackgroundEnabled() const _IRR_OVERRIDE_;

	protected:
		void refreshControls();
		void checkScrollbars();

	private:

		struct Cell
		{
			Cell() : IsOverrideColor(false), Data(0) {}

			core::stringw Text;
			core::stringw BrokenText;
			bool IsOverrideColor;
			video::SColor Color;
			void *Data;
		};

		struct Row
		{
			Row() {}

			core::array<Cell> Items;
		};

		struct Column
		{
			Column() : Width(0), OrderingMode(EGCO_NONE) {}

			core::stringw Name;
			u32 Width;
			EGUI_COLUMN_ORDERING OrderingMode;
		};

		void breakText(const core::stringw &text, core::stringw & brokenText, u32 cellWidth);
		void selectNew(s32 ypos, bool onlyHover=false);
		bool selectColumnHeader(s32 xpos, s32 ypos);
		bool dragColumnStart(s32 xpos, s32 ypos);
		bool dragColumnUpdate(s32 xpos);
		void recalculateHeights();
		void recalculateWidths();

		core::array< Column > Columns;
		core::array< Row > Rows;
		gui::IGUIScrollBar* VerticalScrollBar;
		gui::IGUIScrollBar* HorizontalScrollBar;
		bool Clip;
		bool DrawBack;
		bool MoveOverSelect;
		bool Selecting;
		s32  CurrentResizedColumn;
		s32  ResizeStart;
		bool ResizableColumns;

		s32 ItemHeight;
		s32 TotalItemHeight;
		s32 TotalItemWidth;
		s32 Selected;
		s32 CellHeightPadding;
		s32 CellWidthPadding;
		s32 ActiveTab;
		EGUI_ORDERING_MODE CurrentOrdering;
		s32 DrawFlags;
		s32 ScrollBarSize;

		gui::IGUIFont* OverrideFont;
	};

} // end namespace gui
} // end namespace irr

#endif // _IRR_COMPILE_WITH_GUI_

#endif

