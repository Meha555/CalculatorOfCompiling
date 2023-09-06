#include <QFileDialog>
#include <QScrollBar>
#include <QTime>
#include "error.h"
#include "interlang.h"
#include "mainwindow.h"
#include "parser.h"
#include "token.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    setWindowOpacity(0.95);
    ui->btn_pre->setDisabled(true);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::sleep(unsigned int msec) {
    QTime dieTime = QTime::currentTime().addMSecs(msec);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

/* 以下是数字按键 */
void MainWindow::on_btn_0_clicked() {
    QString curInputString = ui->lineEdit->text();  // 获取当前文本框内的输入串
    if (curInputString == "0")
        curInputString.clear();
    QString inputText = ui->btn_0->text();
    curInputString += inputText;
    ui->lineEdit->setText(curInputString);
}

void MainWindow::on_btn_1_clicked() {
    QString curInputString = ui->lineEdit->text();  // 获取当前文本框内的输入串
    if (curInputString == "0")
        curInputString.clear();
    QString inputText = ui->btn_1->text();
    curInputString += inputText;
    ui->lineEdit->setText(curInputString);
}

void MainWindow::on_btn_2_clicked() {
    QString curInputString = ui->lineEdit->text();  // 获取当前文本框内的输入串
    if (curInputString == "0")
        curInputString.clear();
    QString inputText = ui->btn_2->text();
    curInputString += inputText;
    ui->lineEdit->setText(curInputString);
}

void MainWindow::on_btn_3_clicked() {
    QString curInputString = ui->lineEdit->text();  // 获取当前文本框内的输入串
    if (curInputString == "0")
        curInputString.clear();
    QString inputText = ui->btn_3->text();
    curInputString += inputText;
    ui->lineEdit->setText(curInputString);
}

void MainWindow::on_btn_4_clicked() {
    QString curInputString = ui->lineEdit->text();  // 获取当前文本框内的输入串
    if (curInputString == "0")
        curInputString.clear();
    QString inputText = ui->btn_4->text();
    curInputString += inputText;
    ui->lineEdit->setText(curInputString);
}

void MainWindow::on_btn_5_clicked() {
    QString curInputString = ui->lineEdit->text();  // 获取当前文本框内的输入串
    if (curInputString == "0")
        curInputString.clear();
    QString inputText = ui->btn_5->text();
    curInputString += inputText;
    ui->lineEdit->setText(curInputString);
}

void MainWindow::on_btn_6_clicked() {
    QString curInputString = ui->lineEdit->text();  // 获取当前文本框内的输入串
    if (curInputString == "0")
        curInputString.clear();
    QString inputText = ui->btn_6->text();
    curInputString += inputText;
    ui->lineEdit->setText(curInputString);
}

void MainWindow::on_btn_7_clicked() {
    QString curInputString = ui->lineEdit->text();  // 获取当前文本框内的输入串
    if (curInputString == "0")
        curInputString.clear();
    QString inputText = ui->btn_7->text();
    curInputString += inputText;
    ui->lineEdit->setText(curInputString);
}

void MainWindow::on_btn_8_clicked() {
    QString curInputString = ui->lineEdit->text();  // 获取当前文本框内的输入串
    if (curInputString == "0")
        curInputString.clear();
    QString inputText = ui->btn_8->text();
    curInputString += inputText;
    ui->lineEdit->setText(curInputString);
}

void MainWindow::on_btn_9_clicked() {
    QString curInputString = ui->lineEdit->text();  // 获取当前文本框内的输入串
    if (curInputString == "0")
        curInputString.clear();
    QString inputText = ui->btn_9->text();
    curInputString += inputText;
    ui->lineEdit->setText(curInputString);
}

void MainWindow::on_btn_pi_clicked() {
    QString curInputString = ui->lineEdit->text();  // 获取当前文本框内的输入串
    if (curInputString == "0")
        curInputString.clear();
    QString inputText = ui->btn_pi->text();
    curInputString += inputText;
    ui->lineEdit->setText(curInputString);
}

void MainWindow::on_btn_e_clicked() {
    QString curInputString = ui->lineEdit->text();  // 获取当前文本框内的输入串
    if (curInputString == "0")
        curInputString.clear();
    QString inputText = ui->btn_e->text();
    curInputString += inputText;
    ui->lineEdit->setText(curInputString);
}

/* 以下是符号按键 */
void MainWindow::on_btn_dot_clicked() {
    QString curInputString = ui->lineEdit->text();  // 获取当前文本框内的输入串
    QString inputText = ui->btn_dot->text();
    curInputString += inputText;
    ui->lineEdit->setText(curInputString);
}

void MainWindow::on_btn_plus_clicked() {
    QString curInputString = ui->lineEdit->text();  // 获取当前文本框内的输入串
    QString inputText = ui->btn_plus->text();
    curInputString += inputText;
    ui->lineEdit->setText(curInputString);
}

void MainWindow::on_btn_minus_clicked() {
    QString curInputString = ui->lineEdit->text();  // 获取当前文本框内的输入串
    QString inputText = ui->btn_minus->text();
    curInputString += inputText;
    ui->lineEdit->setText(curInputString);
}

void MainWindow::on_btn_mul_clicked() {
    QString curInputString = ui->lineEdit->text();  // 获取当前文本框内的输入串
    QString inputText = ui->btn_mul->text();
    curInputString += inputText;
    ui->lineEdit->setText(curInputString);
}

void MainWindow::on_btn_div_clicked() {
    QString curInputString = ui->lineEdit->text();  // 获取当前文本框内的输入串
    QString inputText = ui->btn_div->text();
    curInputString += inputText;
    ui->lineEdit->setText(curInputString);
}

void MainWindow::on_btn_mod_clicked() {
    QString curInputString = ui->lineEdit->text();  // 获取当前文本框内的输入串
    QString inputText = "%";
    curInputString += inputText;
    ui->lineEdit->setText(curInputString);
}

void MainWindow::on_btn_lp_clicked() {
    QString curInputString = ui->lineEdit->text();  // 获取当前文本框内的输入串
    if (curInputString == "0")
        curInputString.clear();
    QString inputText = ui->btn_lp->text();
    curInputString += inputText;
    ui->lineEdit->setText(curInputString);
}

void MainWindow::on_btn_rp_clicked() {
    QString curInputString = ui->lineEdit->text();  // 获取当前文本框内的输入串
    if (curInputString == "0")
        curInputString.clear();
    QString inputText = ui->btn_rp->text();
    curInputString += inputText;
    ui->lineEdit->setText(curInputString);
}

/* 以下是函数按键 */
void MainWindow::on_btn_log_clicked() {
    QString curInputString = ui->lineEdit->text();  // 获取当前文本框内的输入串
    if (curInputString == "0")
        curInputString.clear();
    QString inputText = ui->btn_log->text() + "(";
    curInputString += inputText;
    ui->lineEdit->setText(curInputString);
}

void MainWindow::on_btn_tan_clicked() {
    QString curInputString = ui->lineEdit->text();  // 获取当前文本框内的输入串
    if (curInputString == "0")
        curInputString.clear();
    QString inputText = ui->btn_tan->text() + "(";
    curInputString += inputText;
    ui->lineEdit->setText(curInputString);
}

//void MainWindow::on_btn_abs_clicked() {
//    QString curInputString = ui->lineEdit->text();  // 获取当前文本框内的输入串
//    if (curInputString == "0")
//        curInputString.clear();
//    QString inputText = ui->btn_abs->text() + "(";
//    curInputString += inputText;
//    ui->lineEdit->setText(curInputString);
//}

void MainWindow::on_btn_sin_clicked() {
    QString curInputString = ui->lineEdit->text();  // 获取当前文本框内的输入串
    if (curInputString == "0")
        curInputString.clear();
    QString inputText = ui->btn_sin->text() + "(";
    curInputString += inputText;
    ui->lineEdit->setText(curInputString);
}

void MainWindow::on_btn_pow_clicked() {
    QString curInputString = ui->lineEdit->text();  // 获取当前文本框内的输入串
    if (curInputString == "0")
        curInputString.clear();
    QString inputText = ui->btn_pow->text() + "(";
    curInputString += inputText;
    ui->lineEdit->setText(curInputString);
}

void MainWindow::on_btn_cos_clicked() {
    QString curInputString = ui->lineEdit->text();  // 获取当前文本框内的输入串
    if (curInputString == "0")
        curInputString.clear();
    QString inputText = ui->btn_cos->text() + "(";
    curInputString += inputText;
    ui->lineEdit->setText(curInputString);
}

void MainWindow::on_btn_ln_clicked() {
    QString curInputString = ui->lineEdit->text();  // 获取当前文本框内的输入串
    if (curInputString == "0")
        curInputString.clear();
    QString inputText = ui->btn_ln->text() + "(";
    curInputString += inputText;
    ui->lineEdit->setText(curInputString);
}

void MainWindow::on_btn_sqrt_clicked() {
    QString curInputString = ui->lineEdit->text();  // 获取当前文本框内的输入串
    if (curInputString == "0")
        curInputString.clear();
    QString inputText = ui->btn_sqrt->text() + "(";
    curInputString += inputText;
    ui->lineEdit->setText(curInputString);
}

/* 以下为功能按键 */
void MainWindow::on_btn_back_clicked() {
    QString curInputString = ui->lineEdit->text();
    if (curInputString != "") {
        curInputString.remove(curInputString.length() - 1, 1);
    }
    if (curInputString == "") {
        curInputString = "0";
    }
    ui->lineEdit->setText(curInputString);
}

void MainWindow::on_btn_clear_clicked() {
    ui->lineEdit->setText("0");
    InterLang::rPolishExpress = "";
    InterLang::PolishExpress = "";
    ui->rExpress->clear();
    ui->pExpress->clear();
    ui->plainTextEdit->clear();
    InterLang::rPolishList.clear();
    while(!InterLang::TACStack.empty()) InterLang::TACStack.pop();
    std::vector<InterLang::TAC>().swap(InterLang::TACList);
    lp_left_is_Num = false;
    rp_right_is_Num = false;
    errNum = 0;
}

void MainWindow::on_btn_pre_clicked() {
    ui->lineEdit->setText(preInputString);
    InterLang::rPolishExpress = "";
    InterLang::PolishExpress = "";
    ui->rExpress->clear();
    ui->pExpress->clear();
    ui->plainTextEdit->clear();
    InterLang::rPolishList.clear();
    while(!InterLang::TACStack.empty()) InterLang::TACStack.pop();
    std::vector<InterLang::TAC>().swap(InterLang::TACList);
    lp_left_is_Num = false;
    rp_right_is_Num = false;
    errNum = 0;
}

void MainWindow::on_btn_eq_clicked() {
    QString curInputString = ui->lineEdit->text();
    preInputString = curInputString;
    int count_lp = 0;  // 统计'('的个数
    int count_rp = 0;  // 统计')'的个数
    for (int i = 0; i < curInputString.length(); i++) {
        if (curInputString[i] == '(') {
            count_lp++;
            if (i > 0 && ('0' <= curInputString[i - 1] && curInputString[i - 1] <= '9'))
                lp_left_is_Num = true;
        }
        if (curInputString[i] == ')') {
            count_rp++;
            if (i + 1 < curInputString.length() && ('0' <= curInputString[i + 1] && curInputString[i + 1] <= '9'))
                rp_right_is_Num = true;
        }
    }
    try {
        if (count_lp != count_rp) {  // 左右括号数目不等
            error(10);
        }
        if (lp_left_is_Num == true) error(2); //"("左侧不能直接跟数字
        if (rp_right_is_Num == true) error(3); //")"右侧不能直接跟数字
        auto [ans, res] = parseExpress(curInputString.toUtf8().data());  // QString对象不能直接转为string对象
        qDebug() << "mainwindow->parseExpress: " << QString::fromStdString(res);
        curInputString = QString::number(ans);
        ui->lineEdit->setText(curInputString);
        if (errNum == 0) {
            InterLang::constructTAC();
            ui->pExpress->setText(QString::fromStdString(InterLang::PolishExpress));
            ui->rExpress->setText(QString::fromStdString(InterLang::rPolishExpress));
            disPlayLogText(InterLang::TACList);
            if(haveCaled == false) {
                ui->btn_pre->setEnabled(true);
                haveCaled = true;
            }
        }
    } catch (std::exception& e) {
        curInputString = e.what();
        ui->lineEdit->setText(curInputString);
    }
}

//打印三地址码
void MainWindow::disPlayLogText(std::vector<InterLang::TAC>& TACList) {
    // 设置光标到文本末尾
    ui->plainTextEdit->moveCursor(QTextCursor::End, QTextCursor::MoveAnchor);
    for (auto& ele : TACList) {
        ui->plainTextEdit->insertPlainText(InterLang::getTACtext(ele) + "\n");
        sleep(200);
        QScrollBar* scrollbar = ui->plainTextEdit->verticalScrollBar();
        if (scrollbar) {// 移动滚动条到底部
            scrollbar->setSliderPosition(scrollbar->maximum());
        }
    }
}

void MainWindow::on_actOpenFile_triggered() {
    ui->lineEdit->setText("0");
    InterLang::rPolishExpress = "";
    InterLang::PolishExpress = "";
    ui->rExpress->clear();
    ui->pExpress->clear();
    ui->plainTextEdit->clear();
    InterLang::rPolishList.clear();
    while(!InterLang::TACStack.empty()) InterLang::TACStack.pop();
    std::vector<InterLang::TAC>().swap(InterLang::TACList);
    lp_left_is_Num = false;
    rp_right_is_Num = false;
    errNum = 0;
    QString fileName = QFileDialog::getOpenFileName(this, tr("选择表达式文件"), "", tr("TXT(*.txt)"));  //选择文件路径
    if (fileName.isEmpty()) // 如果未选择文件便确认，即返回
        return;
    QFile file(fileName);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream ts(&file);
        QString inputString;
        ts >> inputString;
        ui->lineEdit->setText(inputString.trimmed());
        file.close();
    }
}

void MainWindow::on_actSaveFile_triggered() {
    QString fileName = QFileDialog::getSaveFileName(this, tr("选择保存路径"), "", tr("TXT(*.txt)"));  //选择保存路径
    QFile file(fileName);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) { // 只写方式，如果文件不存在则会自动创建文件
        QTextStream ts(&file);
        ts << "算式：\n" + preInputString + " = " + ui->lineEdit->text();
        ts << '\n';
        ts << "波兰式（前缀表达式）：\n" + ui->pExpress->text();
        ts << '\n';
        ts << "逆波兰式（后缀表达式）：\n" + ui->rExpress->text();
        ts << '\n';
        ts << "三地址码：\n" + ui->plainTextEdit->toPlainText();
        file.close();
    }
}

void MainWindow::on_actDockFloat_triggered(bool checked) {
    ui->dockWidget->setFloating(checked);
}

void MainWindow::on_dockWidget_topLevelChanged(bool topLevel) {
    ui->actDockFloat->setChecked(topLevel);
}

void MainWindow::on_dockWidget_visibilityChanged(bool visible) {
    ui->actDockVisible->setChecked(visible);
}

void MainWindow::on_actDockVisible_toggled(bool arg1) {
    ui->dockWidget->setVisible(arg1);
}
