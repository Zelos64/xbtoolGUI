#ifndef FINDARCHIVE_H
#define FINDARCHIVE_H

#include <QString>

class findArchive
{
public:
    findArchive();
};

class QWidget;
class QLineEdit;

namespace FileUtils {
bool selectArchivePair(QWidget *parent, QLineEdit *arhEdit, QLineEdit *ardEdit);
bool selectOutputDirectory(QWidget *parent, QLineEdit *outputEdit);
}
#endif // FINDARCHIVE_H
