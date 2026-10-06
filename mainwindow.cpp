#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    centralWidget(new QWidget(this))
{
    bold.setBold(true);
    italic.setItalic(true);
    bolditalic.setBold(true);
    bolditalic.setItalic(true);

    setCentralWidget(centralWidget);

    QStackedLayout *stack = new QStackedLayout(centralWidget); //stock all the menus
    QWidget *home = new QWidget();
    QGridLayout *gridLayout = new QGridLayout(home);
        QLabel *choiceGame = new QLabel("Choose game :", this);

        xb1 = new QPushButton("Xenoblade 1", this);
        connect(xb1, &QPushButton::clicked, this, [this, stack]()
        {
            commandGame = "xb1";
            ExtractArchive->setEnabled(false);
            ReplaceArchive->setEnabled(false);
            stack->setCurrentIndex(1);
            CSGedit->setText("Current selected game : " + commandGame);
        });

        xb1de = new QPushButton("Xenoblade 1 DE", this);
        connect(xb1de, &QPushButton::clicked, this, [this, stack]()
        {
            commandGame = "xb1de";
            ExtractArchive->setEnabled(false);
            ReplaceArchive->setEnabled(false);
            GenerateDropTables->setEnabled(true);
            stack->setCurrentIndex(1);
            CSGedit->setText("Current selected game : " + commandGame);
        });

        xb2 = new QPushButton("Xenoblade 2", this);
        connect(xb2, &QPushButton::clicked, this, [this, stack]()
        {
            commandGame = "xb2";
            archiveName = "bf2";
            CreateBlade->setEnabled(true);
            ReadSave->setEnabled(true);
            DecompressIraSave->setEnabled(true);
            stack->setCurrentIndex(1);
            CSGedit->setText("Current selected game : " + commandGame);
        });

        xb3 = new QPushButton("Xenoblade 3", this);
        connect(xb3, &QPushButton::clicked, this, [this, stack]()
        {
            commandGame = "xb3";
            archiveName = "bf3";
            stack->setCurrentIndex(1);
            CSGedit->setText("Current selected game : " + commandGame);
        });

        xbx = new QPushButton("Xenoblade X", this);
        connect(xbx, &QPushButton::clicked, this, [this, stack]()
        {
            commandGame = "xbx";
            stack->setCurrentIndex(1);
            CSGedit->setText("Current selected game : " + commandGame);
        });

        xbxde = new QPushButton("Xenoblade X DE", this);
        connect(xbxde, &QPushButton::clicked, this, [this, stack]()
        {
            commandGame = "xbxde";
            archiveName = "sts";
            stack->setCurrentIndex(1);
            CSGedit->setText("Current selected game : " + commandGame);
        });

        xb1   ->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        xb1de ->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        xb2   ->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        xb3   ->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        xbx   ->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        xbxde ->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

        gridLayout->addWidget(choiceGame, 0, 0, 1, 2);
        gridLayout->addWidget(xb1,        1, 0);
        gridLayout->addWidget(xb1de,      1, 1);
        gridLayout->addWidget(xb2,        2, 0);
        gridLayout->addWidget(xb3,        2, 1);
        gridLayout->addWidget(xbx,        3, 0);
        gridLayout->addWidget(xbxde,      3, 1);

    stack->addWidget(home);

    QWidget *task = new QWidget();
    QGridLayout *taskGridLayout = new QGridLayout(task);
        // CSG mean Current Selected Game
        CSGedit = new QLabel("Current selected game : ...", this);
            taskGridLayout->addWidget(CSGedit, 0, 0);

        QPushButton *backToGameList = new QPushButton("Back");
            backToGameList->setMaximumWidth(60);
            connect(backToGameList, &QPushButton::clicked, this, [this, stack]()
            {
                commandGame = "";
                archiveName = "";
                stack->setCurrentIndex(0);
            });
            taskGridLayout->addWidget(backToGameList, 0, 1, 2, 1);

        QLabel *choiceTask = new QLabel("Choose task :", this);
            choiceTask->setFont(bold);
            taskGridLayout->addWidget(choiceTask, 1, 0);

        QLabel *archive = new QLabel("Archive", this);
            ExtractArchive = new QPushButton("Extract Archive", this);
            connect(ExtractArchive, &QPushButton::clicked, this, [this]()
            {
                commandTask = "ExtractArchive";
                ExtractArchiveDialog();
            });

            ReplaceArchive = new QPushButton("Replace Archive", this);
            connect(ReplaceArchive, &QPushButton::clicked, this, [this]()
            {
                //QMessageBox::information(this, "WIP", "This task isn't implemented yet.");
                commandTask = "ReplaceArchive";
                ReplaceArchiveDialog();
            });

            ExtractArchive->setMinimumWidth(200);
            ReplaceArchive->setMinimumWidth(200);

        taskGridLayout->addWidget(archive, 2, 0);
            taskGridLayout->addWidget(ExtractArchive, 3, 0);
            taskGridLayout->addWidget(ReplaceArchive, 4, 0);

        QLabel *bdat = new QLabel("BDAT", this);
            DecryptBdat = new QPushButton("Decrypt Bdat", this);
            connect(DecryptBdat, &QPushButton::clicked, this, [this]()
            {
                commandTask = "DecryptBdat";
                DecryptBdatDialog();
            });

            BdatCodeGen = new QPushButton("Bdat code generator", this);

            Bdat2Html = new QPushButton("Bdat to HTML", this);

            Bdat2Json = new QPushButton("Bdat to JSON", this);

            Bdat2Psql = new QPushButton("Bdat to PSQL", this);

            GenerateData = new QPushButton("Generate Data", this);

            taskGridLayout ->addWidget(bdat,         2, 1);
            taskGridLayout ->addWidget(DecryptBdat,  3, 1);
            taskGridLayout ->addWidget(BdatCodeGen,  4, 1);
            taskGridLayout ->addWidget(Bdat2Html,    5, 1);
            taskGridLayout ->addWidget(Bdat2Json,    6, 1);
            taskGridLayout ->addWidget(Bdat2Psql,    7, 1);
            taskGridLayout ->addWidget(GenerateData, 8, 1);

            DecryptBdat    ->setMinimumWidth(200);
            BdatCodeGen    ->setMinimumWidth(200);
            Bdat2Html      ->setMinimumWidth(200);
            Bdat2Json      ->setMinimumWidth(200);
            Bdat2Psql      ->setMinimumWidth(200);
            GenerateData   ->setMinimumWidth(200);

        QLabel *other = new QLabel("Other", this);
            DescrambleScript = new QPushButton("Descramble Script", this);

            ExtractWilay = new QPushButton("Extract Wilay", this);

            DescrambleScript->setMinimumWidth(200);
            ExtractWilay->setMinimumWidth(200);

        taskGridLayout->addWidget(other, 2, 2);
            taskGridLayout->addWidget(DescrambleScript, 3, 2);
            taskGridLayout->addWidget(ExtractWilay, 4, 2);

        QLabel *xb2only = new QLabel("Xenoblade 2 only", this);
            CreateBlade= new QPushButton("Create Blade", this);
                CreateBlade->setEnabled(false);

            ReadSave = new QPushButton("Read Save", this);
                ReadSave->setEnabled(false);

            DecompressIraSave  = new QPushButton("Decompress Ira Save", this);
                DecompressIraSave->setEnabled(false);

        taskGridLayout->addWidget(xb2only, 2, 3);
            taskGridLayout->addWidget(CreateBlade, 3, 3);
            taskGridLayout->addWidget(ReadSave, 4, 3);
            taskGridLayout->addWidget(DecompressIraSave, 5, 3);

            CreateBlade->setMinimumWidth(200);
            ReadSave->setMinimumWidth(200);
            DecompressIraSave->setMinimumWidth(200);

        QLabel *xb1DEonly = new QLabel("Xenoblade DE only", this);
            GenerateDropTables = new QPushButton("Generate Drop Tables", this);
                GenerateDropTables->setEnabled(false);

            GenerateDropTables->setMinimumWidth(200);

        taskGridLayout->addWidget(xb1DEonly, 2, 4);
            taskGridLayout->addWidget(GenerateDropTables, 3, 4);

        archive->setFont(italic);
        bdat->setFont(italic);
        other->setFont(italic);
        xb2only->setFont(italic);
        xb1DEonly->setFont(italic);

    stack->addWidget(task);
    stack->setCurrentIndex(0);

    setFixedSize(sizeHint());
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect screenRect = screen->availableGeometry();
    this->move(screenRect.center() - this->rect().center());
}

void MainWindow::ExtractArchiveDialog()
{
    QDialog dialog(this);
    dialog.setWindowTitle("Extract Archive");
    dialog.setMinimumWidth(750);
    dialog.setMaximumWidth(900);

    QLabel *arhlabel = new QLabel("ARH path:");
    QLabel *ardlabel = new QLabel("ARD path:");
    QLabel *outputArchiveLabel = new QLabel("Output directory :");

    QLineEdit *arhPathEdit = new QLineEdit();
    QLineEdit *ardPathEdit = new QLineEdit();
    QLineEdit *outputArchiveEdit = new QLineEdit();

    QPushButton *inputArchiveBrowse = new QPushButton("Set archive (.ard && .arh) location");
    QPushButton *outputArchiveBrowse = new QPushButton ("Set output directory");
    QPushButton *okButton = new QPushButton("OK");
    QPushButton *cancelButton = new QPushButton("Cancel");

    arhPathEdit->setReadOnly(true);
    ardPathEdit->setReadOnly(true);
    outputArchiveEdit->setReadOnly(true);

    QGridLayout *gridDialog = new QGridLayout(&dialog);
        gridDialog->addWidget(arhlabel,            0, 0);
        gridDialog->addWidget(ardlabel,            1, 0);
        gridDialog->addWidget(outputArchiveLabel,  2, 0);

        gridDialog->addWidget(arhPathEdit,         0, 1, 1, 4);
        gridDialog->addWidget(ardPathEdit,         1, 1, 1, 4);
        gridDialog->addWidget(outputArchiveEdit,   2, 1, 1, 4);

        gridDialog->addWidget(inputArchiveBrowse,  0, 5, 2, 2);
        gridDialog->addWidget(outputArchiveBrowse, 2, 5, 1, 2);

        gridDialog->addWidget(okButton,            4, 5);
        gridDialog->addWidget(cancelButton,        4, 6);

        arhPathEdit         ->setMinimumWidth(400);
        ardPathEdit         ->setMinimumWidth(400);
        outputArchiveEdit   ->setMinimumWidth(400);

        inputArchiveBrowse  ->setMinimumWidth(200);
        outputArchiveBrowse ->setMinimumWidth(200);
        okButton            ->setMinimumWidth(100);
        cancelButton        ->setMinimumWidth(100);

        arhPathEdit         ->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        ardPathEdit         ->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        outputArchiveEdit   ->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        inputArchiveBrowse  ->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        outputArchiveBrowse ->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        okButton            ->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        cancelButton        ->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    QFileDialog fileDialog(&dialog);
    fileDialog.setWindowTitle("Add the .ard / .arh path");
    fileDialog.setViewMode(QFileDialog::Detail);
    fileDialog.setFileMode(QFileDialog::ExistingFile);
    fileDialog.setAcceptMode(QFileDialog::AcceptOpen);
    fileDialog.setNameFilters({"Archives (*.ard *.arh)"});
    fileDialog.setDirectory(QStandardPaths::writableLocation(QStandardPaths::HomeLocation));

    connect(inputArchiveBrowse, &QPushButton::clicked, &dialog, [&]()
    {
        if (fileDialog.exec() == QDialog::Accepted)
        {
            QStringList files = fileDialog.selectedFiles();
            if (!files.isEmpty())
            {
                QString inputArchive = files.first();
                QFileInfo fileInfo(inputArchive);               // Get file infos from the selection
                    QString fileName = fileInfo.fileName();         // "exemple.png"
                    QString baseName = fileInfo.baseName();         // "exemple"
                    QString extension = fileInfo.suffix();          // "png"
                    QString absolutePath = fileInfo.absolutePath(); // "/home/user/Documents"

                if (inputArchive.isEmpty())
                    { QMessageBox::warning(&dialog, "Missing files", "No file selected"); }
                else if (!QFileInfo::exists(QDir(absolutePath).filePath(baseName + ".arh")) && QFileInfo::exists(QDir(absolutePath).filePath(baseName + ".arh")))
                    { QMessageBox::warning(&dialog, "Missing file", ".arh missing"); }
                else if (QFileInfo::exists(QDir(absolutePath).filePath(baseName + ".arh")) && !QFileInfo::exists(QDir(absolutePath).filePath(baseName + ".ard")))
                    { QMessageBox::warning(&dialog, "Missing file", ".ard missing"); }
                else if (QFileInfo::exists(QDir(absolutePath).filePath(baseName + ".arh")) && QFileInfo::exists(QDir(absolutePath).filePath(baseName + ".ard")))
                {
                    arhPathEdit->setText(QDir(absolutePath).filePath(baseName + ".arh"));
                    ardPathEdit->setText(QDir(absolutePath).filePath(baseName + ".ard"));
                }
            }
        }
    });

    connect(outputArchiveBrowse, &QPushButton::clicked, &dialog, [&]()
    {
        QString outputFolder = QFileDialog::getExistingDirectory
        (
            &dialog,
            "Choose the directory for the archive's dump",
            QStandardPaths::writableLocation(QStandardPaths::HomeLocation) //Open the dialog at the user's folder
        );
        if (outputFolder.isEmpty())
            { QMessageBox::warning(&dialog, "Missing argument", "No folder selected"); }

        if (QDir(outputFolder).isEmpty()) { outputArchiveEdit->setText(outputFolder); }
        if (!QDir(outputFolder).isEmpty() && QMessageBox::question
        (
            &dialog, "Advice",
            "The folder isn't empty, are you sure to dump your archive here?",
            QMessageBox::Yes | QMessageBox::No
        ) == QMessageBox::Yes) { outputArchiveEdit->setText(outputFolder); }
    });

    connect(okButton, &QPushButton::clicked, &dialog, [&]()
    {
        if(arhPathEdit->text().isEmpty() || ardPathEdit->text().isEmpty() || outputArchiveEdit->text().isEmpty())
            { QMessageBox::warning(this, "Error", "At least one of the argument is empty."); }
        else { dialog.accept(); }
    });

    connect(cancelButton, &QPushButton::clicked, &dialog, &QDialog::reject);

    if (dialog.exec() == QDialog::Accepted)
    {
        if (!QFileInfo::exists(programOGpath))
        {
            QMessageBox::critical(this, "Error", "XbTool.exe not found.");
            return;
        }
        else { qDebug() << "Launching..."; }

        commandUser.clear();
        commandUser << "-g" << commandGame
                    << "-t" << commandTask
                    << "-a" << arhPathEdit->text()
                            << ardPathEdit->text()
                    << "-o" << outputArchiveEdit->text(); //CLI command parsing is different for user and QProcess
        qDebug() << commandUser;
        qDebug().noquote() << commandUser;

        QDialog *progressDialog = new QDialog(this);
            progressDialog->setWindowTitle("XbTool - Extracting");
            progressDialog->setMinimumSize(500, 100);

            QVBoxLayout *layout = new QVBoxLayout(progressDialog);

            QProgressBar *progressBar = new QProgressBar(progressDialog);
                progressBar->setRange(0, 100);
                progressBar->setValue(0);
                layout->addWidget(progressBar);

            QProcess *process = new QProcess(progressDialog);
                QString stdoutBuffer;
                connect(process, &QProcess::readyReadStandardOutput, progressDialog, [=]() mutable
                {
                    stdoutBuffer += QString::fromLocal8Bit(process->readAllStandardOutput());
                    static QRegularExpression re("/.*?(\\d{1,3}(?:[.,]\\d+)?)\\s*%");
                    QRegularExpressionMatchIterator it = re.globalMatch(stdoutBuffer);
                    double lastValue = -1.0;
                    while (it.hasNext())
                    {
                        QRegularExpressionMatch m = it.next();
                        QString num = m.captured(1);
                        num.replace(',', '.');
                        lastValue = num.toDouble();
                    }
                    if (lastValue >= 0.0 && lastValue <= 100.0)
                    {
                        progressBar->setValue(qRound(lastValue));
                        progressBar->setFormat(QString::number(lastValue, 'f', 1) + " %");
                    }
                });

            QPushButton *closeBtn = new QPushButton("Close", progressDialog);
                closeBtn->setEnabled(false);
                layout->addWidget(closeBtn);
                connect(closeBtn, &QPushButton::clicked, progressDialog, &QDialog::accept);

            QPushButton *cancelBtn = new QPushButton("Cancel", progressDialog);
                layout->addWidget(cancelBtn);
                connect(cancelBtn, &QPushButton::clicked, progressDialog, [=]()
                {
                    if (process->state() == QProcess::Running) process->kill();
                    cancelBtn->setEnabled(false);
                    closeBtn->setEnabled(true);
                });

            connect(process, QOverload<int, QProcess::ExitStatus>::of(&QProcess::finished), progressDialog, [=](int, QProcess::ExitStatus)
            {
                progressBar->setValue(100);
                progressBar->setFormat("100 %");
                cancelBtn->setEnabled(false);
                closeBtn->setEnabled(true);
            });

            process->start(programOGpath, commandUser);

        progressDialog->show();
    }
}

void MainWindow::ReplaceArchiveDialog()
{
    QDialog dialog(this);
    dialog.setWindowTitle("Replace Archive");
    dialog.setMinimumWidth(750);
    dialog.setMaximumWidth(900);

    QLabel *arhlabel = new QLabel("ARH path:");
    QLabel *ardlabel = new QLabel("ARD path:");
    QLabel *inputFileLabel = new QLabel("Input file :");
    QLabel *outputPathLabel = new QLabel("Output relative path :");

    QLineEdit *arhPathEdit = new QLineEdit();
    QLineEdit *ardPathEdit = new QLineEdit();
    QLineEdit *inputFileEdit = new QLineEdit();
    QLineEdit *outputPathEdit = new QLineEdit();

    QPushButton *inputArchiveBrowse = new QPushButton("Set archive (.ard && .arh) location");
    QPushButton *inputFileBrowse = new QPushButton ("Set input file");
    QPushButton *okButton = new QPushButton("OK");
    QPushButton *cancelButton = new QPushButton("Cancel");

    arhPathEdit        ->setReadOnly(true);
    ardPathEdit        ->setReadOnly(true);
    inputFileEdit      ->setReadOnly(true);
    outputPathEdit     ->setReadOnly(true);

    QGridLayout *gridDialog = new QGridLayout(&dialog);
        gridDialog->addWidget(arhlabel,           0, 0);
        gridDialog->addWidget(ardlabel,           1, 0);
        gridDialog->addWidget(inputFileLabel,     2, 0);
        gridDialog->addWidget(outputPathLabel,    3, 0);

        gridDialog->addWidget(arhPathEdit,        0, 1, 1, 2);
        gridDialog->addWidget(ardPathEdit,        1, 1, 1, 2);
        gridDialog->addWidget(inputFileEdit,      2, 1, 1, 2);
        gridDialog->addWidget(outputPathEdit,     3, 1, 1, 2);

        gridDialog->addWidget(inputArchiveBrowse, 0, 3, 2, 2);
        gridDialog->addWidget(inputFileBrowse,    2, 3, 1, 2);

        gridDialog->addWidget(okButton,           6, 3);
        gridDialog->addWidget(cancelButton,       6, 4);

    arhPathEdit        ->setMinimumWidth(300);
    ardPathEdit        ->setMinimumWidth(300);
    inputFileEdit      ->setMinimumWidth(300);
    outputPathEdit     ->setMinimumWidth(300);

    inputArchiveBrowse ->setMinimumWidth(200);
    inputFileBrowse    ->setMinimumWidth(200);
    okButton           ->setMinimumWidth(100);
    cancelButton       ->setMinimumWidth(100);

    arhPathEdit        ->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    ardPathEdit        ->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    inputFileEdit      ->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    outputPathEdit     ->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    inputArchiveBrowse ->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    inputFileBrowse    ->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    QFileDialog fileDialog(&dialog);
    fileDialog.setWindowTitle("Add the .ard / .arh path");
    fileDialog.setViewMode(QFileDialog::Detail);
    fileDialog.setFileMode(QFileDialog::ExistingFile);
    fileDialog.setAcceptMode(QFileDialog::AcceptOpen);
    fileDialog.setNameFilters({"Archives (*.ard *.arh)"});
    fileDialog.setDirectory(QStandardPaths::writableLocation(QStandardPaths::HomeLocation));

    connect(inputArchiveBrowse, &QPushButton::clicked, &dialog, [&]()
    {
        if (fileDialog.exec() == QDialog::Accepted)
        {
            QStringList files = fileDialog.selectedFiles();
            if (!files.isEmpty())
            {
                QString inputArchive = files.first();
                QFileInfo fileInfo(inputArchive);               // Get file infos from the selection
                    QString fileName = fileInfo.fileName();         // "exemple.png"
                    QString baseName = fileInfo.baseName();         // "exemple"
                    QString extension = fileInfo.suffix();          // "png"
                    QString absolutePath = fileInfo.absolutePath(); // "/home/user/Documents"

                if (inputArchive.isEmpty())
                    { QMessageBox::warning(&dialog, "Missing files", "No file selected"); }
                else if (!QFileInfo::exists(QDir(absolutePath).filePath(baseName + ".arh")) && QFileInfo::exists(QDir(absolutePath).filePath(baseName + ".arh")))
                    { QMessageBox::warning(&dialog, "Missing file", ".arh missing"); }
                else if (QFileInfo::exists(QDir(absolutePath).filePath(baseName + ".arh")) && !QFileInfo::exists(QDir(absolutePath).filePath(baseName + ".ard")))
                    { QMessageBox::warning(&dialog, "Missing file", ".ard missing"); }
                else if (QFileInfo::exists(QDir(absolutePath).filePath(baseName + ".arh")) && QFileInfo::exists(QDir(absolutePath).filePath(baseName + ".ard")))
                {
                    arhPathEdit->setText(QDir(absolutePath).filePath(baseName + ".arh"));
                    ardPathEdit->setText(QDir(absolutePath).filePath(baseName + ".ard"));
                }
            }
        }
    });

    connect(inputFileBrowse, &QPushButton::clicked, &dialog, [&]()
    {
        // Réécrire pour que ça prenne un fichier au lieu d'un dossier
        QString inputFile = QFileDialog::getOpenFileName
        (
            &dialog,
            "Choose the input file",
            QStandardPaths::writableLocation(QStandardPaths::HomeLocation), //Open the dialog at the user's folder
            "All files (*.*)"
        );
    });

    connect(inputFileBrowse, &QPushButton::clicked, &dialog, [&]()
    {
        QString inputFile = QFileDialog::getOpenFileName
        (
            &dialog,
            "Choose the file you want to add in the archive",
            QStandardPaths::writableLocation(QStandardPaths::HomeLocation) //Open the dialog at the user's folder
        );

        if (inputFile.isEmpty())
            { QMessageBox::warning(&dialog, "Missing argument", "No file selected"); }
        if (QFileInfo::exists(inputFile))
            { inputFileEdit->setText(inputFile); }
    });

    //outputFileEdit->setText(outputFilePath + inputFileName);
    //ask how work the ReplaceArchive task in the WTR or XSW on Discord...

    connect(okButton,     &QPushButton::clicked, &dialog, &QDialog::accept);
    connect(cancelButton, &QPushButton::clicked, &dialog, &QDialog::reject);

    if (dialog.exec() == QDialog::Accepted)
    {
        if (!QFileInfo::exists(programOGpath))
        {
            QMessageBox::critical(this, "Error", "XbTool.exe not found.");
            return;
        }
        else { qDebug() << "Launching..."; }

        commandUser.clear();
        commandUser << "-g" << commandGame
                    << "-t" << commandTask
                    << "-a" << arhPathEdit->text()
                    << ardPathEdit->text()
                    << "-i" << inputFileEdit->text();
                    //<< "-o" << outputFileEdit->text(); //CLI command parsing is different for user and QProcess
        qDebug() << commandUser;
        qDebug().noquote() << commandUser;

        QDialog *progressDialog = new QDialog(this);
        progressDialog->setWindowTitle("XbTool - Extracting");
        progressDialog->setMinimumSize(500, 100);

        QVBoxLayout *layout = new QVBoxLayout(progressDialog);

        QProgressBar *progressBar = new QProgressBar(progressDialog);
        progressBar->setRange(0, 100);
        progressBar->setValue(0);
        layout->addWidget(progressBar);

        QProcess *process = new QProcess(progressDialog);
        QString stdoutBuffer;
        connect(process, &QProcess::readyReadStandardOutput, progressDialog, [=]() mutable
        {
            stdoutBuffer += QString::fromLocal8Bit(process->readAllStandardOutput());
            static QRegularExpression re("/.*?(\\d{1,3}(?:[.,]\\d+)?)\\s*%");
            QRegularExpressionMatchIterator it = re.globalMatch(stdoutBuffer);
            double lastValue = -1.0;
            while (it.hasNext())
            {
                QRegularExpressionMatch m = it.next();
                QString num = m.captured(1);
                num.replace(',', '.');
                lastValue = num.toDouble();
            }
            if (lastValue >= 0.0 && lastValue <= 100.0)
            {
                progressBar->setValue(qRound(lastValue));
                progressBar->setFormat(QString::number(lastValue, 'f', 1) + " %");
            }
        });

        QPushButton *closeBtn = new QPushButton("Close", progressDialog);
        closeBtn->setEnabled(false);
        layout->addWidget(closeBtn);
        connect(closeBtn, &QPushButton::clicked, progressDialog, &QDialog::accept);

        QPushButton *cancelBtn = new QPushButton("Cancel", progressDialog);
        layout->addWidget(cancelBtn);
        connect(cancelBtn, &QPushButton::clicked, progressDialog, [=]()
        {
            if (process->state() == QProcess::Running) process->kill();
            cancelBtn->setEnabled(false);
            closeBtn->setEnabled(true);
        });

        connect(process, QOverload<int, QProcess::ExitStatus>::of(&QProcess::finished), progressDialog, [=](int, QProcess::ExitStatus)
        {
            progressBar->setValue(100);
            progressBar->setFormat("100 %");
            cancelBtn->setEnabled(false);
            closeBtn->setEnabled(true);
        });

        process->start(programOGpath, commandUser);

        progressDialog->show();
    }
}

void MainWindow::DecryptBdatDialog()
{
    QDialog dialog(this);
    dialog.setWindowTitle("Decrypt BDAT");
    dialog.setMinimumWidth(750);
    dialog.setMaximumWidth(900);

    QLabel *inputFileLabel = new QLabel("Input BDAT path :");
    QLabel *outputFileLabel = new QLabel("Output BDAT path :");

    QLineEdit *inputFileEdit = new QLineEdit();
    QLineEdit *outputFileEdit = new QLineEdit();

    QPushButton *inputFileBrowse = new QPushButton("Set input BDAT location");
    QPushButton *outputFileBrowse = new QPushButton ("Set output BDAT location");
    QPushButton *okButton = new QPushButton("OK");
    QPushButton *cancelButton = new QPushButton("Cancel");

    inputFileEdit    ->setReadOnly(true);
    outputFileEdit   ->setReadOnly(true);

    QGridLayout *gridDialog = new QGridLayout(&dialog);
        gridDialog->addWidget(inputFileLabel,   0, 0);
        gridDialog->addWidget(outputFileLabel,  1, 0);

        gridDialog->addWidget(inputFileEdit,    0, 1, 1, 2);
        gridDialog->addWidget(outputFileEdit,   1, 1, 1, 2);

        gridDialog->addWidget(inputFileBrowse,  0, 3, 1, 2);
        gridDialog->addWidget(outputFileBrowse, 1, 3, 1, 2);

        gridDialog->addWidget(okButton,         2, 3);
        gridDialog->addWidget(cancelButton,     2, 4);

    inputFileEdit    ->setMinimumWidth(300);
    outputFileEdit   ->setMinimumWidth(300);

    inputFileBrowse  ->setMinimumWidth(200);
    outputFileBrowse ->setMinimumWidth(200);
    okButton         ->setMinimumWidth(100);
    cancelButton     ->setMinimumWidth(100);

    inputFileEdit    ->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    outputFileEdit   ->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    inputFileBrowse  ->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    outputFileBrowse ->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    connect(inputFileBrowse, &QPushButton::clicked, &dialog, [&]()
    {

    });

    // DecryptBdat - Decrypts a BDAT file or directory
        // DecryptBdat -i <input_file> [-o <output_file>]
        // DecryptBdat -i <input_dir>

    if (dialog.exec() == QDialog::Accepted)
    {
        if (!QFileInfo::exists(programOGpath))
        {
            QMessageBox::critical(this, "Error", "XbTool.exe not found.");
            return;
        }
        else { qDebug() << "Launching..."; }

        commandUser.clear();
        // commandUser << "-g" << commandGame
        //             << "-t" << commandTask
        //             << "-a" << arhPathEdit->text()
        //             << ardPathEdit->text()
        //             << "-o" << outputArchiveEdit->text(); //CLI command parsing is different for user and QProcess
        qDebug() << commandUser;
        qDebug().noquote() << commandUser;
    }
}

MainWindow::~MainWindow(){}
