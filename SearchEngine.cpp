#include <QtWidgets>
#include <QtWebKitWidgets>
//minimal constants of searching machine
class Browser : public QMainWindow {
public:
    Browser(QWidget *parent = 0);
    void search(QString query);

private:
    QLineEdit *searchBar;
    QWebView *webView;
};

Browser::Browser(QWidget *parent) : QMainWindow(parent) {
    searchBar = new QLineEdit(this);
    connect(searchBar, SIGNAL(returnPressed()), this, SLOT(search()));

    webView = new QWebView(this);
    setCentralWidget(webView);
}

void Browser::search(QString query) {
    QString url = "https://www.google.com/search?q=" + query;
    webView->load(url);
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    Browser browser;
    browser.showMaximized();
    return app.exec();
}
