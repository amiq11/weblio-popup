#ifndef POPUPWIDGET_H
#define POPUPWIDGET_H

#include <QxtGlobalShortcut>
#include <QMenu>
#include <QShortcut>
#include <QSystemTrayIcon>
#include <QUrl>
#include <QWidget>

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
    void focusSearchLineEdit();
    void search(QString word);
    void search();
    void enableToggle() { canToggle = true; }
    void disableToggle() { canToggle = false; }

    void on_webView_loadProgress(int progress);

    void on_webView_loadStarted();

    void on_actionSearch_triggered();

private:
    Ui::PopupWidget   *ui;
    QxtGlobalShortcut *shortcut;
    QShortcut         *lineEditShortcut;
    QSystemTrayIcon   *trayIcon;
    QMenu             *trayMenu;
    QAction           *quitAction;
    bool               isScrolled;
    static const int   weblioPosition;
    bool               canToggle;
    QByteArray         prevGeometry;

    void setupTray();
    void setupTrayMenu();
};

#endif // POPUPWIDGET_H
