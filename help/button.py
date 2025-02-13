import sys
import subprocess
from PyQt5.QtWidgets import QApplication, QWidget, QPushButton, QVBoxLayout
from PyQt5.QtCore import Qt

def run_command(command):
    # Run the system command
    result = subprocess.run(command, capture_output=True, text=True, shell=True)
    print(result.stdout)  # Print the output to the console

class App(QWidget):
    def __init__(self):
        super().__init__()
        
        self.initUI()

    def initUI(self):
        # Create a vertical layout to arrange buttons
        layout = QVBoxLayout()

        # Create the buttons and connect them to commands
        button1 = QPushButton('Hello', self)
        button1.clicked.connect(lambda: run_command('echo "helloo"'))
        
        button2 = QPushButton('make_run', self)
        button2.clicked.connect(lambda: run_command('mkdir build && cd build && cmake .. && make'))

        button3 = QPushButton('run', self)
        button3.clicked.connect(lambda: run_command('cd build && ./wall'))

        button4 = QPushButton('make_del', self)
        button4.clicked.connect(lambda: run_command('rm -rf build'))
        
        button5 = QPushButton('Exit', self)
        button5.clicked.connect(lambda: run_command('exit'))

        # Add buttons to layout
        layout.addWidget(button1)
        layout.addWidget(button2)
        layout.addWidget(button3)
        layout.addWidget(button4)
        layout.addWidget(button5)

        # Set the layout of the main window
        self.setLayout(layout)

        # Set window title and size
        self.setWindowTitle('Run Command Buttons')
        self.setGeometry(100, 100, 200, 200)

        # Set the window to always stay on top
        self.setWindowFlag(Qt.WindowStaysOnTopHint)

    def closeEvent(self, event):
        # Close the application gracefully
        event.accept()

if __name__ == '__main__':
    app = QApplication(sys.argv)
    ex = App()
    ex.show()
    sys.exit(app.exec_())
