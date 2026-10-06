#include "findarchive.h"

findArchive::findArchive() {}
#include "findarchive.h"
#include <QWidget>
#include <QLineEdit>
#include <QFileDialog>
#include <QMessageBox>
#include <QStandardPaths>
#include <QFileInfo>
#include <QDir>

namespace FileUtils
{
    bool selectArchivePair(QWidget *parent, QLineEdit *arhEdit, QLineEdit *ardEdit)
    {
        QString file = QFileDialog::getOpenFileName(
            parent,
            "Add the .ard / .arh path",
            QStandardPaths::writableLocation(QStandardPaths::HomeLocation),
            "Archives (*.ard *.arh)"
            );

        if (file.isEmpty()) return false;

        QFileInfo fileInfo(file);
        QString baseName = fileInfo.baseName();
        QString absolutePath = fileInfo.absolutePath();

        QString arhPath = QDir(absolutePath).filePath(baseName + ".arh");
        QString ardPath = QDir(absolutePath).filePath(baseName + ".ard");

        if (!QFileInfo::exists(arhPath)) {
            QMessageBox::warning(parent, "Missing file", ".arh file is missing");
            return false;
        }
        if (!QFileInfo::exists(ardPath)) {
            QMessageBox::warning(parent, "Missing file", ".ard file is missing");
            return false;
        }

        arhEdit->setText(arhPath);
        ardEdit->setText(ardPath);
        return true;
    }

    bool selectOutputDirectory(QWidget *parent, QLineEdit *outputEdit)
    {
        QString outputFolder = QFileDialog::getExistingDirectory(
            parent,
            "Choose output directory",
            QStandardPaths::writableLocation(QStandardPaths::HomeLocation)
            );

        if (outputFolder.isEmpty()) {
            QMessageBox::warning(parent, "Missing argument", "No folder selected");
            return false;
        }

        if (!QDir(outputFolder).isEmpty()) {
            auto res = QMessageBox::question(
                parent, "Advice",
                "The folder isn't empty, are you sure to dump your archive here?",
                QMessageBox::Yes | QMessageBox::No
                );
            if (res != QMessageBox::Yes) return false;
        }

        outputEdit->setText(outputFolder);
        return true;
    }
}
