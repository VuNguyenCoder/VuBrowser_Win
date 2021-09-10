#include "vubrowser.h"
#include "ui_vubrowser.h"
#include <QMessageBox>
#include <QTimer>

VuBrowser::VuBrowser(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::VuBrowser)
{
    ui->setupUi(this);

    // Add webEngineView manually
    webView = new QWebEngineView(ui->view);
    int webViewWidth = ui->view->geometry().width();
    int webViewHeight = ui->view->geometry().height();
    webView->setGeometry(0,0, webViewWidth, webViewHeight);
    webView->load(QUrl("http://google.com"));

    /**
     * @brief Connect Signal & Slot manually
     */
    // If URL of webEngineView changes, the address text changes also
    connect(webView, SIGNAL(urlChanged(const QUrl&)),
            this, SLOT(on_webView_urlChanged(const QUrl&)));

    // If webEngineView crash when loading page, reload it.
    connect(webView, &QWebEngineView::renderProcessTerminated,
                [this](QWebEnginePage::RenderProcessTerminationStatus termStatus, int statusCode) {
               QTimer::singleShot(0, [this] { webView->reload(); });
        });
}

VuBrowser::~VuBrowser()
{
    delete ui;
}


void VuBrowser::on_addressEdit_returnPressed()
{
    webView->load(ui->addressEdit->text());
}


void VuBrowser::on_backButton_pressed()
{
    webView->back();
}


void VuBrowser::on_forwardButton_pressed()
{
    webView->forward();
}


void VuBrowser::on_helpButton_pressed()
{
    QMessageBox* helpBox = new QMessageBox;
    QString message = "Xin chao\n";
    message += "Day la trinh duyet cua VuNguyenCoder \n";
    message += "de xem JAV\n";
    helpBox->setText(message);
    helpBox->exec();
}

void VuBrowser::on_webView_urlChanged(const QUrl &url)
{
    ui->addressEdit->setText(webView->url().toString());
}

