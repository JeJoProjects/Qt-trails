#include "Notepad.h"
#include "./ui_Notepad.h"

// C++ headers
#include <utility> // std::move

Notepad::Notepad(QWidget *parent)
    : QMainWindow{ parent }
    , ui{ new Ui::MainWindow }
    , mCurrentFile{""}
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);
}

Notepad::~Notepad()
{
    delete ui;
}


void Notepad::on_actionNew_triggered()
{
    mCurrentFile.clear();
    this->ui->textEdit->setText({});
}

void Notepad::on_actionOpen_triggered()
{
    mCurrentFile = QFileDialog::getOpenFileName(this, "Open the File");
    QFile file{mCurrentFile, this};

    if(!file.open(QIODevice::ReadOnly | QFile::Text))
    {
        QMessageBox::warning(this, "Warnig!!!",
                    "Can not open the file: " + file.errorString());
        return;
    }
    this->setWindowTitle(mCurrentFile);
    QTextStream inTextStream{ &file };
    this->ui->textEdit->setText(inTextStream.readAll());
    file.close();
}

void Notepad::on_actionSave_triggered()
{

}

void Notepad::on_actionSave_As_triggered()
{
    const QString fileName{QFileDialog::getSaveFileName(this, "Save As")};
    QFile file{fileName, this};
    if(!file.open(QFile::WriteOnly | QFile::Text))
    {
        QMessageBox::warning(this, "Warning!!!",
                    "Cannot save the file: " + file.errorString());
        return;
    }
    mCurrentFile = std::move(fileName);
    this->setWindowTitle(mCurrentFile);

    QTextStream outTextStream{ &file };
    outTextStream << (this->ui->textEdit->toPlainText());
    file.close();
}

void Notepad::on_actionPrint_triggered()
{
    QPrinter printer{};
    printer.setPrinterName("Printer Name");

    QPrintDialog  printDialog{&printer, this};
    if(printDialog.exec() == QDialog::Rejected)
    {
        QMessageBox::warning(this, "Warning!!!", "Can not access any printers");
        return;
    }

    this->ui->textEdit->print(&printer);
}

void Notepad::on_actionExit_triggered()
{
    QApplication::quit();
}

