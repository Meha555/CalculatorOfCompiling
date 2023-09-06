#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <vector>
#include "interlang.h"



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btn_0_clicked();

    void on_btn_1_clicked();

    void on_btn_2_clicked();

    void on_btn_3_clicked();

    void on_btn_4_clicked();

    void on_btn_5_clicked();

    void on_btn_6_clicked();

    void on_btn_7_clicked();

    void on_btn_8_clicked();

    void on_btn_9_clicked();

    void on_btn_dot_clicked();

    void on_btn_plus_clicked();

    void on_btn_minus_clicked();

    void on_btn_mul_clicked();

    void on_btn_div_clicked();

    void on_btn_pi_clicked();

    void on_btn_e_clicked();

    void on_btn_lp_clicked();

    void on_btn_rp_clicked();

    void on_btn_log_clicked();

    void on_btn_tan_clicked();

    void on_btn_ln_clicked();

    void on_btn_sin_clicked();

    void on_btn_mod_clicked();

    void on_btn_cos_clicked();

    void on_btn_pow_clicked();

    void on_btn_sqrt_clicked();

    void on_btn_back_clicked();

    void on_btn_clear_clicked();

    void on_btn_eq_clicked();

    void on_btn_pre_clicked();

    void disPlayLogText(std::vector<InterLang::TAC>&);

    void sleep(unsigned int);

    void on_actOpenFile_triggered();

    void on_actSaveFile_triggered();

    void on_actDockFloat_triggered(bool checked);

    void on_dockWidget_topLevelChanged(bool topLevel);

    void on_dockWidget_visibilityChanged(bool visible);

    void on_actDockVisible_toggled(bool arg1);

private:
    Ui::MainWindow *ui;

    QString preInputString = "";

    bool haveCaled = false;
};
#endif // MAINWINDOW_H
