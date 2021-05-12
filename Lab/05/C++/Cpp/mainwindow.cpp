#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::loadImage);
    connect(ui->pushButton_3, &QPushButton::clicked, this, &MainWindow::saveImage);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &MainWindow::encodeMsg);
    connect(ui->pushButton_4, &QPushButton::clicked, this, &MainWindow::decodeMsg);
    connect(ui->plainTextEdit, &QPlainTextEdit::textChanged, this, &MainWindow::msgChanged);
}

void MainWindow::loadImage(){
    QString fileName = QFileDialog::getOpenFileName(this, "Открыть изображение", "", "Допустимые форматы (*.png)");
    if (image.load(fileName)){
        image.convertTo(QImage::Format_ARGB32);
        ui->label->setText("<html><head/><body><p align=\"center\"><span style=\" font-size:12pt; font-weight:600; color:#00aa00;\">Изображение успешно загружено</span></p></body></html>");
    }
    else
        ui->label->setText("<html><head/><body><p align=\"center\"><span style=\" font-size:12pt; font-weight:600; color:#ff0000;\">Изображение не загружено</span></p></body></html>");
}

void MainWindow::saveImage(){
    QString fileName = QFileDialog::getSaveFileName(this, "Сохранить изображение", "", "Допустимые форматы (*.png)");
    if (image.save(fileName)){
        ui->label->setText("<html><head/><body><p align=\"center\"><span style=\" font-size:12pt; font-weight:600; color:#00aa00;\">Изображение успешно сохранено</span></p></body></html>");
    }
    else
        ui->label->setText("<html><head/><body><p align=\"center\"><span style=\" font-size:12pt; font-weight:600; color:#ff0000;\">Изображение не сохранено</span></p></body></html>");
}

void MainWindow::encodeMsg(){
    QString bits = "111000101001110110100100";
    bits += QString("%1").arg(ui->plainTextEdit->toPlainText().toUtf8().size(), 32, 2, QChar('0'));
    for (unsigned char by : (ui->plainTextEdit->toPlainText().toUtf8())) {
        bits += QString("%1").arg(by, 8, 2, QChar('0'));
    };

    if ((image.sizeInBytes()/4*3/8) < (bits.count()/8))
        ui->label->setText("<html><head/><body><p align=\"center\"><span style=\" font-size:12pt; font-weight:600; color:#ff0000;\">Ошибка. Не достаточно места!</span></p></body></html>");
    else{
        int len = 0;
        for (int y = 0; y < image.height(); y++){
            if (len > bits.count()){
                break;
            }
            for (int x = 0; x < image.width(); x++){
                QColor p;
                if (len < bits.count()){
                    if(image.pixelColor(x, y).red()%2 != 0){
                        p.setRed(image.pixelColor(x, y).red()-1+(bits[len].unicode()-48));
                    }
                    else p.setRed(image.pixelColor(x, y).red()+(bits[len].unicode()-48));
                }
                else p.setRed(image.pixelColor(x, y).red());

                len++;
                if (len < bits.count()){
                    if(image.pixelColor(x, y).green()%2 != 0){
                        p.setGreen(image.pixelColor(x, y).green()-1+(bits[len].unicode()-48));
                    }
                    else p.setGreen(image.pixelColor(x, y).green()+(bits[len].unicode()-48));
                }
                else p.setGreen(image.pixelColor(x, y).green());

                len++;
                if (len < bits.count()){
                    if(image.pixelColor(x, y).blue()%2 != 0){
                        p.setBlue(image.pixelColor(x, y).blue()-1+(bits[len].unicode()-48));
                    }
                    else p.setBlue(image.pixelColor(x, y).blue()+(bits[len].unicode()-48));
                }
                else p.setBlue(image.pixelColor(x, y).blue());

                image.setPixelColor(x,y,p);

                len++;

                if (len > bits.count()){
                    break;
                }
            }
        }
        ui->label->setText("<html><head/><body><p align=\"center\"><span style=\" font-size:12pt; font-weight:600; color:#00aa00;\">Сообщение добавлено в картинку!</span></p></body></html>");
    }
}
QByteArray bitsToByte(const QString bits){
   QByteArray byteArray(bits.size()/8, 0);
   bool ok;
   for(int i=0; i<byteArray.size(); i++) {
       byteArray[i] = bits.mid(i*8, 8).toUInt(&ok, 2);
   }
   return byteArray;
}
void MainWindow::decodeMsg(){
    QString bits;
    QVector<QColor> arr;

    for (int y = 0; y < image.height(); y++){
        for (int x = 0; x < image.width(); x++){
            arr.append(image.pixelColor(x,y));
        }
    }
    for (int i = 0; i < arr.length(); i++){
        if(arr[i].red()%2 != 0) bits.append('1');
        else bits.append('0');
        if(arr[i].green()%2 != 0) bits.append('1');
        else bits.append('0');
        if(arr[i].blue()%2 != 0) bits.append('1');
        else bits.append('0');
    }

    if (bits.mid(0, 24) == QString("111000101001110110100100")){
        bool ok;
        auto size = bits.mid(24, 32).toUInt(&ok, 2);
        ui->plainTextEdit->setPlainText(QString::fromUtf8(bitsToByte(bits.mid(24+32, size*8))));
        ui->label->setText(QString("<html><head/><body><p align=\"center\"><span style=\" font-size:12pt; font-weight:600; color:#00aa00;\">Размер сообщения %1 байт</span></p></body></html>").arg(size));
    }else{
        ui->label->setText("<html><head/><body><p align=\"center\"><span style=\" font-size:12pt; font-weight:600; color:#ff0000;\">Метка не найдена!</span></p></body></html>");
    }
}

void MainWindow::msgChanged(){
    int limit = image.sizeInBytes()/4*3/8 - (ui->plainTextEdit->toPlainText().toUtf8().length() + 3 + 4);
    if(image.isNull())
        ui->label->setText("<html><head/><body><p align=\"center\"><span style=\" font-size:12pt; font-weight:600; color:#ff0000;\">Отсутствует изображение!</span></p></body></html>");
    else{
        if (limit >= 0)
            ui->label->setText(QString("<html><head/><body><p align=\"center\"><span style=\" font-size:12pt; font-weight:600; color:#00aa00;\">Ещё можно ввести: %1 байт!</span></p></body></html>").arg(limit));
        else
            ui->label->setText("<html><head/><body><p align=\"center\"><span style=\" font-size:12pt; font-weight:600; color:#ff0000;\">Превышен размер сообщения!</span></p></body></html>");
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

