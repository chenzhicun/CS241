#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(OpenFile()));
}

void MainWindow::OpenFile()
{
    QFileDialog* fd = new QFileDialog(this);
    QString fileName=fd->getOpenFileName(this,tr("Open a CSV file"),"",tr("CSV file(*.csv)"));

    QDir dir=QDir::current();
    QFile file(dir.filePath(fileName));
    if(!file.open(QIODevice::ReadOnly))
        qDebug()<<"OPEN FILE FAILED!";

    QFileInfo OpenFileInfo;
    OpenFileInfo=QFileInfo(fileName);
    QString filePath=OpenFileInfo.filePath();
    QString name=OpenFileInfo.fileName();
    ui->lineEdit->setText(filePath);

    QTextStream *out=new QTextStream(&file);
    QStringList tempOption=out->readAll().split("\n");
    QVector<double> population;
    QVector<QString> countryname;
    double total=0;
    for(int i=0;i<tempOption.count();i++)
    {
        QStringList tempbar=tempOption.at(i).split(",");
        countryname.append(tempbar.at(0));
        population.append(tempbar.at(1).toDouble());
        total+=tempbar.at(1).toDouble();
    }
    QPieSeries *series = new QPieSeries();
    for(int i=1;i<population.count();i++)
    {
        population[i]=(population[i]/total)*100;
        QString tmp=countryname[i]+' '+QString::number(population[i],'f',2)+'%';
        series->append(tmp,population[i]);
    }
    series->setLabelsVisible();
    file.close();

    ui->chartView->setRenderHint(QPainter::Antialiasing);
    ui->chartView->chart()->setTitle("Pie Chart of "+name);
    ui->chartView->chart()->removeAllSeries();
    ui->chartView->chart()->addSeries(series);
    ui->chartView->chart()->setTheme(QChart::ChartThemeQt);
    ui->chartView->chart()->setAnimationOptions(QChart::AllAnimations);
    ui->chartView->chart()->legend()->setAlignment(Qt::AlignBottom);
    ui->chartView->chart()->legend()->setFont(QFont("Arial",7));

}

MainWindow::~MainWindow()
{
    delete ui;
}

