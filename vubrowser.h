#ifndef VUBROWSER_H
#define VUBROWSER_H

#include <QMainWindow>
#include <QtWebEngineWidgets/QWebEngineView>

QT_BEGIN_NAMESPACE
namespace Ui { class VuBrowser; }
QT_END_NAMESPACE

class VuBrowser : public QMainWindow
{
    Q_OBJECT

public:
    VuBrowser(QWidget *parent = nullptr);
    ~VuBrowser();

private slots:
    void on_addressEdit_returnPressed();

    void on_backButton_pressed();

    void on_forwardButton_pressed();

    void on_helpButton_pressed();

    void on_webView_urlChanged(const QUrl &url);

private:
    Ui::VuBrowser *ui;

    // Add webEngineView programatically
    QWebEngineView *webView;
};
#endif // VUBROWSER_H
