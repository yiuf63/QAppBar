#include "appbarwidget.h"

//QLibrary *AppDock::shellLib;
AppBar::AppBar(QWidget *parent) : QWidget(parent)
{
    m_hwnd = (HWND)winId();

    memset(&m_abd, 0, sizeof(APPBARDATA));
    m_abd.cbSize = sizeof(APPBARDATA);
    m_abd.hWnd = m_hwnd;
}

void AppBar::registerAppBar()
{
    m_abd.uCallbackMessage = RegisterWindowMessage(L"AppBarMessage");
    SHAppBarMessage(ABM_NEW, &m_abd);

    //设置应用栏位置和大小
    m_abd.uEdge = ABE_TOP;  // 顶部
    m_abd.rc = {0, 0, GetSystemMetrics(SM_CXSCREEN), 40};  // 高度40像素
    SHAppBarMessage(ABM_SETPOS, &m_abd);

    setGeometry(m_abd.rc.left, m_abd.rc.top,
                m_abd.rc.right - m_abd.rc.left,
                m_abd.rc.bottom - m_abd.rc.top);
}

void AppBar::unregisterAppBar()
{
    SHAppBarMessage(ABM_REMOVE, &m_abd);
}

AppBar::~AppBar()
{
    unregisterAppBar();
}


