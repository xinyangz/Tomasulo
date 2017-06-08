#ifndef MAINVIEW_H
#define MAINVIEW_H

#include <QMainWindow>

namespace Ui {
class MainView;
}

class InfoTab;
class MemTab;
class QFile;

class MainView : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainView(QWidget *parent, InfoTab& info, MemTab& mem);
    ~MainView();

public slots:
    void onNotifyLoadInstError(const std::vector<int> &lineNums);

signals:
    void NotifyLoadInst(const QFile &fileName);     // 从文件读指令
    void NotifyStep();                              // 单步前进
    void NotifyClear();                             // 清零
    void NotifyAddInst();                           // 添加指令

private slots:
    void on_actionLoadInst_triggered();
    void on_actionStep_triggered();
    void on_actionClear_triggered();
    void on_actionAddInst_triggered();

private:
    InfoTab& m_infoTab;
    MemTab& m_memTab;
    Ui::MainView *ui;
};

#endif // MAINVIEW_H
