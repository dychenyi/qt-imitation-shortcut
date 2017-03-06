/*
 * dbzhang800 2011.04.05
*/

#include <QtGui>
#include "qxtglobalshortcut.h"

class Window:public QLabel
{
    Q_OBJECT
public:
    Window(QWidget *parent=NULL)
    {
        setText("Press Ctrl+Alt+T to show/hide the windows.\n\n"
                "Double click me if you want to quit!");
        resize(300, 200);

        QxtGlobalShortcut * sc = new QxtGlobalShortcut(QKeySequence("Ctrl+Alt+T"), this);
        connect(sc, SIGNAL(activated()),this, SLOT(toggle()));
    }
protected:
    void closeEvent(QCloseEvent *evt)
    {
        hide();
        evt->ignore();
    }

    void mouseDoubleClickEvent(QMouseEvent *evt)
    {
        qApp->quit();
    }
private slots:
    void toggle()
    {
        setVisible(!isVisible());
    }
};

#include "main.moc"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QApplication::setQuitOnLastWindowClosed(false);
    Window window;
    window.show();
    return app.exec();
}
