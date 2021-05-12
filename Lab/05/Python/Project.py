from PySide6.QtCore import *
from PySide6.QtGui import *
from PySide6.QtWidgets import *


class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        if not MainWindow.objectName():
            MainWindow.setObjectName(u"MainWindow")
        MainWindow.resize(320, 328)
        MainWindow.setMinimumSize(QSize(320, 328))
        MainWindow.setMaximumSize(QSize(320, 328))
        self.centralwidget = QWidget(MainWindow)
        self.centralwidget.setObjectName(u"centralwidget")
        self.label = QLabel(self.centralwidget)
        self.label.setObjectName(u"label")
        self.label.setGeometry(QRect(10, 170, 301, 31))
        self.label.setFrameShape(QFrame.Box)
        self.label.setAlignment(Qt.AlignRight|Qt.AlignTrailing|Qt.AlignVCenter)
        self.plainTextEdit = QPlainTextEdit(self.centralwidget)
        self.plainTextEdit.setObjectName(u"plainTextEdit")
        self.plainTextEdit.setGeometry(QRect(10, 10, 301, 161))
        self.pushButton = QPushButton(self.centralwidget)
        self.pushButton.setObjectName(u"pushButton")
        self.pushButton.setGeometry(QRect(20, 220, 131, 41))
        self.pushButton_2 = QPushButton(self.centralwidget)
        self.pushButton_2.setObjectName(u"pushButton_2")
        self.pushButton_2.setGeometry(QRect(170, 220, 131, 41))
        self.pushButton_3 = QPushButton(self.centralwidget)
        self.pushButton_3.setObjectName(u"pushButton_3")
        self.pushButton_3.setGeometry(QRect(20, 270, 131, 41))
        self.pushButton_4 = QPushButton(self.centralwidget)
        self.pushButton_4.setObjectName(u"pushButton_4")
        self.pushButton_4.setGeometry(QRect(170, 270, 131, 41))
        MainWindow.setCentralWidget(self.centralwidget)

        self.retranslateUi(MainWindow)

        QMetaObject.connectSlotsByName(MainWindow)
    # setupUi

    def retranslateUi(self, MainWindow):
        MainWindow.setWindowTitle(QCoreApplication.translate("MainWindow", u"Cryptograph", None))
        self.label.setText(QCoreApplication.translate("MainWindow", u"<html><head/><body><p align=\"center\"><br/></p></body></html>", None))
        self.plainTextEdit.setPlaceholderText(QCoreApplication.translate("MainWindow", u"\u0412\u0432\u0435\u0434\u0438\u0442\u0435 \u0442\u0435\u043a\u0441\u0442", None))
        self.pushButton.setText(QCoreApplication.translate("MainWindow", u"\u0417\u0430\u0433\u0440\u0443\u0437\u0438\u0442\u044c \u043a\u0430\u0440\u0442\u0438\u043d\u043a\u0443", None))
        self.pushButton_2.setText(QCoreApplication.translate("MainWindow", u"\u0417\u0430\u043a\u043e\u0434\u0438\u0440\u043e\u0432\u0430\u0442\u044c \u0442\u0435\u043a\u0441\u0442", None))
        self.pushButton_3.setText(QCoreApplication.translate("MainWindow", u"\u0421\u043e\u0445\u0440\u0430\u043d\u0438\u0442\u044c \u043a\u0430\u0440\u0442\u0438\u043d\u043a\u0443", None))
        self.pushButton_4.setText(QCoreApplication.translate("MainWindow", u"\u0414\u0435\u043a\u043e\u0434\u0438\u0440\u043e\u0432\u0430\u0442\u044c \u0442\u0435\u043a\u0441\u0442", None))

class MainWindow(QMainWindow):
    def __init__(self):
        super(MainWindow, self).__init__()
        self.ui = Ui_MainWindow()
        self.ui.setupUi(self)
        self.image = QImage()
        self.ui.pushButton.clicked.connect(self.loadImage)
        self.ui.pushButton_3.clicked.connect(self.saveImage)
        self.ui.pushButton_4.clicked.connect(self.decodeMsg)
        self.ui.pushButton_2.clicked.connect(self.encodeMsg)
        self.ui.plainTextEdit.textChanged.connect(self.msgChanged)
        
        
    @Slot()
    def loadImage(self):
        fileName, _ = QFileDialog.getOpenFileName(self, "Открыть изображение", "", "Допустимые форматы (*.png)")
        if self.image.load(fileName):
            self.image.convertTo(QImage.Format_ARGB32)
            self.ui.label.setText("<html><head/><body><p align=\"center\"><span style=\" font-size:12pt; font-weight:600; color:#00aa00;\">Изображение успешно загружено</span></p></body></html>")
        else:
            self.ui.label.setText("<html><head/><body><p align=\"center\"><span style=\" font-size:12pt; font-weight:600; color:#ff0000;\">Изображение не загружено</span></p></body></html>")

    @Slot()
    def saveImage(self):
        fileName, _ = QFileDialog.getSaveFileName(self, "Сохранить изображение", "", "Допустимые форматы (*.png)")
        if self.image.save(fileName):
            self.ui.label.setText("<html><head/><body><p align=\"center\"><span style=\" font-size:12pt; font-weight:600; color:#00aa00;\">Изображение успешно сохранено</span></p></body></html>")
        else:
            self.ui.label.setText("<html><head/><body><p align=\"center\"><span style=\" font-size:12pt; font-weight:600; color:#ff0000;\">Изображение не сохранено</span></p></body></html>")

    @Slot()
    def decodeMsg(self):
        bits = ''
        arr = []
        
        for y in range(self.image.height()):
            for x in range(self.image.width()):
                arr.append(self.image.pixelColor(x,y))
        for i in range(len(arr)):
            if arr[i].red()%2 != 0:
                bits += '1'
            else:
                bits += '0'
            if arr[i].green()%2 != 0:
                bits += '1'
            else:
                bits += '0'
            if arr[i].blue()%2 != 0:
                bits += '1'
            else:
                bits += '0'
        
        if bits[:24] == "111000101001110110100100":
            size = int.from_bytes(int(bits[24:56], 2).to_bytes(4, byteorder='big'), byteorder='big')
            self.ui.plainTextEdit.setPlainText(int(bits[56:(56+size*8)],2).to_bytes(int(len(bits[56:(56+size*8)])/8), byteorder='big').decode('utf-8'))
            self.ui.label.setText("<html><head/><body><p align=\"center\"><span style=\" font-size:12pt; font-weight:600; color:#00aa00;\">Размер сообщения %s байт</span></p></body></html>" % size)
        else:
            self.ui.label.setText("<html><head/><body><p align=\"center\"><span style=\" font-size:12pt; font-weight:600; color:#ff0000;\">Метка не найдена!</span></p></body></html>")

    @Slot()
    def encodeMsg(self):
        s = bin(int(self.ui.plainTextEdit.toPlainText().encode('utf-8').hex(), base=16))[2:].zfill(8)
        if (len(s)%2 != 0):
            s = '0' + s
        bits = '111000101001110110100100'
        bits += bin(int(hex(len(self.ui.plainTextEdit.toPlainText().encode('utf-8'))).split('x')[-1], base=16))[2:].zfill(32)
        bits += s
        
        if (self.image.sizeInBytes()/4*3/8) < (len(bits)/8):
           self.ui.label.setText("<html><head/><body><p align=\"center\"><span style=\" font-size:12pt; font-weight:600; color:#ff0000;\">Ошибка! Недостаточно места.</span></p></body></html>")
        else:
            lenn = 0
            for y in range(self.image.height()):
                if lenn > len(bits):
                    break
                for x in range(self.image.width()):
                    p = QColor()
                    if lenn < len(bits):
                        if self.image.pixelColor(x, y).red()%2 != 0:
                            p.setRed(self.image.pixelColor(x, y).red()-1+int(bits[lenn]))
                        else: p.setRed(self.image.pixelColor(x, y).red()+int(bits[lenn]))
                    else: p.setRed(self.image.pixelColor(x, y).red())
                    
                    lenn += 1
                    if lenn < len(bits):
                        if self.image.pixelColor(x, y).green()%2 != 0:
                            p.setGreen(self.image.pixelColor(x, y).green()-1+int(bits[lenn]))
                        else: p.setGreen(self.image.pixelColor(x, y).green()+int(bits[lenn]))
                    else: p.setGreen(self.image.pixelColor(x, y).green())
                    
                    lenn += 1
                    if lenn < len(bits):
                        if self.image.pixelColor(x, y).blue()%2 != 0:
                            p.setBlue(self.image.pixelColor(x, y).blue()-1+int(bits[lenn]))
                        else: p.setBlue(self.image.pixelColor(x, y).blue()+int(bits[lenn]))
                    else: p.setBlue(self.image.pixelColor(x, y).blue())
                    
                    self.image.setPixelColor(x, y, p)
                    lenn += 1
                    if lenn > len(bits):
                        break
            self.ui.label.setText("<html><head/><body><p align=\"center\"><span style=\" font-size:12pt; font-weight:600; color:#00aa00;\">Сообщение добавлено в картинку!</span></p></body></html>");

    @Slot()
    def msgChanged(self):
        limit = (self.image.sizeInBytes()/4*3/8) - (len(self.ui.plainTextEdit.toPlainText().encode('utf-8')) + 3 + 4)
        if self.image.isNull():
            self.ui.label.setText("<html><head/><body><p align=\"center\"><span style=\" font-size:12pt; font-weight:600; color:#ff0000;\">Отсутствует изображение!</span></p></body></html>")
        else:
            if int(limit) >= 0:
                self.ui.label.setText("<html><head/><body><p align=\"center\"><span style=\" font-size:12pt; font-weight:600; color:#00aa00;\">Ещё можно ввести: %s байт!</span></p></body></html>" % int(limit))
            else:
                self.ui.label.setText("<html><head/><body><p align=\"center\"><span style=\" font-size:12pt; font-weight:600; color:#ff0000;\">Превышен размер сообщения!</span></p></body></html>")

if __name__ == "__main__":
    import sys
    app = QApplication(sys.argv)
  
    window = MainWindow()
    window.show()
  
    sys.exit(app.exec_())