#ifndef APPBARWIDGET_H
#define APPBARWIDGET_H

#include <QWidget>
#include <windows.h> // 包含Windows API
#include <shellapi.h>


class AppBar : public QWidget
{
    Q_OBJECT
public:
    explicit AppBar(QWidget *parent = nullptr);
    ~AppBar();

    void registerAppBar();
    void unregisterAppBar();

private:
    HWND m_hwnd;
    APPBARDATA m_abd;
};




#endif // APPBARWIDGET_H
