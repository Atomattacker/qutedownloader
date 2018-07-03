#ifndef BASEWINDOW_HPP
#define BASEWINDOW_HPP

#include <QWidget>

class QIcon;
class QLabel;
class QPushButton;

class BaseWindow : public QWidget
{
    Q_OBJECT
public:
    explicit BaseWindow(QWidget *parent = nullptr);


    void setLogo(const QIcon &icon);
    void setTitle(const QString &text);

    void setLayout(QLayout *layout);

    void setMinimizeVisible(bool visible);

protected:
    virtual void onClose();
    void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void mouseMoveEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void mouseReleaseEvent(QMouseEvent *event) Q_DECL_OVERRIDE;


private:
    void initComponents();
    void connectSignals();

     void minimize();
     void handleClosed();

private:
    QLabel *lbl_logo;
    QLabel *lbl_title;
    QPushButton *pbtn_minimize;
    QPushButton *pbtn_close;

    QWidget *wdg_title;

    QWidget *wdg_content;

    QPoint distance;
    bool pressed = false;

};

#endif // BASEWINDOW_HPP
