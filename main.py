from mainwindow import MainWindow
import sys
from PyQt5.QtWidgets import *
from PyQt5.QtCore import *
import Resources.Resources_rc

def readQss(style):
    with open(style, 'r') as f:
        return f.read()


if __name__ == "__main__":
    app = QApplication(sys.argv)
    app.setAttribute(Qt.AA_EnableHighDpiScaling, True)
    app.setAttribute(Qt.AA_UseHighDpiPixmaps, True)
    form = MainWindow()
    qss_file = QFile(':/AppIcon/mainTheme.qss')
    qss_file.open(QFile.ReadOnly)
    qss = str(qss_file.readAll(), encoding='utf-8')
    qss_file.close()
    form.setStyleSheet(qss)
    form.show()
    sys.exit(app.exec())