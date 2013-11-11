#include "popupwidget.h"
#include "ui_popupwidget.h"
#include <QDebug>
#include <QCloseEvent>
#include <QWebFrame>
#include <QTimer>

const int PopupWidget::weblioPosition = 330;

PopupWidget::PopupWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PopupWidget)
{
    ui->setupUi(this);

    isScrolled = false;
    canToggle  = true;
    shortcut = new QxtGlobalShortcut(this);
    if (!shortcut->setShortcut(QKeySequence("Ctrl+F12"))) {
        qWarning() << "Ctrl+12 is already assigned!";
    } else {
        connect(shortcut, SIGNAL(activated()),
                this,     SLOT(toggleShowUp()));\
        setupTray();
    }
}

PopupWidget::~PopupWidget()
{
    delete shortcut;
    delete quitAction;
    delete trayMenu;
    delete trayIcon;
    delete ui;
}

void PopupWidget::toggleShowUp()
{
    if (!canToggle) return;

    if (isVisible()) {
        // Hide Window
        prevGeometry = saveGeometry();
        hide();
        canToggle = false;
        QTimer::singleShot(500, this, SLOT(enableToggle()));
    } else {
        // Open Window
        setWindowFlags(Qt::WindowStaysOnTopHint);
        activateWindow(); //qApp->setActiveWindow()も必要
        qApp->setActiveWindow(this); //activateWindow()も必要
        restoreGeometry(prevGeometry);
        showNormal();

        ui->lineEdit->setFocus();
        canToggle = false;
        QTimer::singleShot(500, this, SLOT(enableToggle()));
    }
}

void PopupWidget::setupTray()
{
    setupTrayMenu();
    trayIcon = new QSystemTrayIcon(this);
    trayIcon->setContextMenu(trayMenu);
    trayIcon->setIcon(QIcon(":/img/icon.svg"));
    trayIcon->show();
}

void PopupWidget::setupTrayMenu()
{
    quitAction = new QAction(tr("&Quit"), this);
    connect(quitAction, SIGNAL(triggered()), qApp, SLOT(quit()));
    trayMenu = new QMenu(this);
    trayMenu->addAction(quitAction);
}

void PopupWidget::closeEvent(QCloseEvent *event)
{
    if (trayIcon->isVisible()) {
        prevGeometry = saveGeometry();
        hide();
        event->ignore();
    }
}

void PopupWidget::search(QString word)
{
    QUrl url = QUrl(QString("http://ejje.weblio.jp/content/") + word);
    ui->webView->load(url);
    emit urlChanged(url);
}

void PopupWidget::search()
{
    QString word = ui->lineEdit->text();
    QUrl url = QUrl(QString("http://ejje.weblio.jp/content/") + word);
    ui->webView->load(url);
    emit urlChanged(url);
}

void PopupWidget::on_webView_loadProgress(int progress)
{
    Q_UNUSED(progress)
    if (!isScrolled) {
        QWebFrame *frame = ui->webView->page()->mainFrame();
        int max = frame->scrollBarMaximum(Qt::Vertical);
        if (max > weblioPosition) {
            frame->setScrollBarValue(Qt::Vertical, weblioPosition);
            isScrolled = true;
        }
    }
}

void PopupWidget::on_webView_loadStarted()
{
    isScrolled = false;
}

void PopupWidget::on_actionSearch_triggered()
{
    search();
}

