#pragma once
#include <QObject>

class MainView;
class InfoTab;
class Ins;
class Tomasulo;
class QStandardItemModel;
class QFile;

class ViewModel : public QObject
{
    Q_OBJECT
public:
    explicit ViewModel(MainView &mainView, InfoTab &infoTab, std::vector<Ins> &inss, Tomasulo &tomasulo);

public slots:
    void onNotifyLoadInst(const QFile &fileName);
    void onNotifyStep();
    void onNotifyClear();

signals:
    void NotifyLoadInstError(const std::vector<int> &lineNums);

private:
    MainView &m_mainView;
    InfoTab &m_infoTab;
    std::vector<Ins> &m_inss;
    Tomasulo &m_tomasulo;

    QStandardItemModel &m_instModel;    // 指令序列
    QStandardItemModel &m_rsModel;      // 保留站
    QStandardItemModel &m_regsModel;    // 寄存器信息
    QStandardItemModel &m_loadModel;      // Load缓冲
    QStandardItemModel &m_storeModel;      // Store缓冲

    explicit ViewModel(const ViewModel& rhs) = delete;
    ViewModel& operator= (const ViewModel& rhs) = delete;
    void initModel();
    void initInstModel();
    void initRsModel();
    void initRegsModel();
    void initLoadModel();
    void initStoreModel();
    void ConnectActions();
    void updateView();
    void updateInst();
    void updateStatus();
    void updateRS();
    void updateRegs();
    void updateLoad();
    void updateStore();
};


