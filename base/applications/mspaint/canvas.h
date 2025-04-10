/*
 * PROJECT:    PAINT for ReactOS
 * LICENSE:    LGPL-2.0-or-later (https://spdx.org/licenses/LGPL-2.0-or-later)
 * PURPOSE:    Providing the canvas window class
 * COPYRIGHT:  Copyright 2015 Benedikt Freisen <b.freisen@gmx.net>
 */

#pragma once

class CCanvasWindow : public CWindowImpl<CCanvasWindow>
{
public:
    DECLARE_WND_CLASS_EX(_T("ReactOSPaintCanvas"), CS_DBLCLKS | CS_HREDRAW | CS_VREDRAW,
                         COLOR_APPWORKSPACE)

    BEGIN_MSG_MAP(CCanvasWindow)
        MESSAGE_HANDLER(WM_SIZE, OnSize)
        MESSAGE_HANDLER(WM_PAINT, OnPaint)
        MESSAGE_HANDLER(WM_MOUSEMOVE, OnMouseMove)
        MESSAGE_HANDLER(WM_HSCROLL, OnHScroll)
        MESSAGE_HANDLER(WM_VSCROLL, OnVScroll)
        MESSAGE_HANDLER(WM_ERASEBKGND, OnEraseBkgnd)
        MESSAGE_HANDLER(WM_LBUTTONDOWN, OnLButtonDown)
        MESSAGE_HANDLER(WM_RBUTTONDOWN, OnRButtonDown)
        MESSAGE_HANDLER(WM_LBUTTONDBLCLK, OnLButtonDblClk)
        MESSAGE_HANDLER(WM_RBUTTONDBLCLK, OnRButtonDblClk)
        MESSAGE_HANDLER(WM_KEYDOWN, OnKeyDown)
        MESSAGE_HANDLER(WM_LBUTTONUP, OnLButtonUp)
        MESSAGE_HANDLER(WM_RBUTTONUP, OnRButtonUp)
        MESSAGE_HANDLER(WM_SETCURSOR, OnSetCursor)
        MESSAGE_HANDLER(WM_MOUSEWHEEL, OnMouseWheel)
        MESSAGE_HANDLER(WM_CANCELMODE, OnCancelMode)
        MESSAGE_HANDLER(WM_CAPTURECHANGED, OnCaptureChanged)
        MESSAGE_HANDLER(WM_CTLCOLOREDIT, OnCtlColorEdit)
        MESSAGE_HANDLER(WM_PALETTEMODELCOLORCHANGED, OnPaletteModelColorChanged)
    END_MSG_MAP()

    CCanvasWindow();
    virtual ~CCanvasWindow();

    BOOL m_drawing;

    VOID cancelDrawing();
    VOID finishDrawing();
    VOID Update(HWND hwndFrom);

    VOID ImageToCanvas(POINT& pt);
    VOID ImageToCanvas(RECT& rc);
    VOID CanvasToImage(POINT& pt, BOOL bZoomed = FALSE);
    VOID CanvasToImage(RECT& rc, BOOL bZoomed = FALSE);
    VOID GetImageRect(RECT& rc);
    VOID MoveSelection(INT xDelta, INT yDelta);

protected:
    HITTEST m_hitSelection;
    HITTEST m_hitCanvasSizeBox;
    POINT m_ptOrig; // The origin of drag start
    HBITMAP m_ahbmCached[2]; // The cached buffer bitmaps
    CRect m_rcResizing; // Resizing rectagle

    HITTEST CanvasHitTest(POINT pt);
    RECT GetBaseRect();
    VOID DoDraw(HDC hDC, RECT& rcClient, RECT& rcPaint);
    VOID OnHVScroll(WPARAM wParam, INT fnBar);
    VOID drawZoomFrame(INT mouseX, INT mouseY);

    HITTEST SelectionHitTest(POINT ptImage);
    VOID StartSelectionDrag(HITTEST hit, POINT ptImage);
    VOID SelectionDragging(POINT ptImage);
    VOID EndSelectionDrag(POINT ptImage);

    LRESULT OnSize(UINT nMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
    LRESULT OnHScroll(UINT nMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
    LRESULT OnVScroll(UINT nMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
    LRESULT OnEraseBkgnd(UINT nMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
    LRESULT OnPaint(UINT nMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
    LRESULT OnLButtonDown(UINT nMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
    LRESULT OnRButtonDown(UINT nMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
    LRESULT OnLButtonDblClk(UINT nMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
    LRESULT OnRButtonDblClk(UINT nMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
    LRESULT OnMouseMove(UINT nMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
    LRESULT OnKeyDown(UINT nMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
    LRESULT OnLButtonUp(UINT nMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
    LRESULT OnRButtonUp(UINT nMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
    LRESULT OnSetCursor(UINT nMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
    LRESULT OnMouseWheel(UINT nMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
    LRESULT OnCancelMode(UINT nMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
    LRESULT OnCaptureChanged(UINT nMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
    LRESULT OnCtlColorEdit(UINT nMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
    LRESULT OnPaletteModelColorChanged(UINT nMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);

    LRESULT OnLRButtonDown(BOOL bLeftButton, UINT nMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
    LRESULT OnLRButtonDblClk(BOOL bLeftButton, UINT nMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
    LRESULT OnLRButtonUp(BOOL bLeftButton, UINT nMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
};
