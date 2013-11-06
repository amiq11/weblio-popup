#ifndef POPUPWIDGET_H
#define POPUPWIDGET_H

#include <QWidget>
#include <QxtGlobalShortcut>
#include <QSystemTrayIcon>
#include <QMenu>
#include <QUrl>

namespace Ui {
class PopupWidget;
}

class PopupWidget : public QWidget
{
    Q_OBJECT
    
public:
    explicit PopupWidget(QWidget *parent = 0);
    ~PopupWidget();
    
protected:
    void closeEvent(QCloseEvent *);

signals:
    void urlChanged(QUrl url);

private slots:
    void toggleShowUp();
    void search(QString word);
    void search();

    void on_webView_loadProgress(int progress);

    void on_webView_loadStarted();

    void on_actionSearch_triggered();

private:
    Ui::PopupWidget   *ui;
    QxtGlobalShortcut *shortcut;
    QSystemTrayIcon   *trayIcon;
    QMenu             *trayMenu;
    QAction           *quitAction;
    bool               isScrolled;
    static const int   weblioPosition;

    void setupTray();
    void setupTrayMenu();
};

#endif // POPUPWIDGET_H
