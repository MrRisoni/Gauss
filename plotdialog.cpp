#include "plotdialog.h"
#include "ui_plotdialog.h"

PlotDialog::PlotDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PlotDialog)
{
    ui->setupUi(this);
    //https://www.youtube.com/watch?v=xWGEvlDWokQ
    makePlot();


}

PlotDialog::~PlotDialog()
{
    delete ui;
}



void PlotDialog::makePlot() {


    // set locale to english, so we get english month names:
      ui->myPlot->setLocale(QLocale(QLocale::English, QLocale::UnitedKingdom));
      // seconds of current time, we'll use it as starting point in time for data:
      double now = QDateTime::currentDateTime().toTime_t();
      srand(8); // set the random seed, so we always get the same random data
      // create multiple graphs:
      for (int gi=0; gi<5; ++gi)
      {
        ui->myPlot->addGraph();
        QPen pen;
        pen.setColor(QColor(0, 0, 255, 200));
        ui->myPlot->graph()->setLineStyle(QCPGraph::lsLine);
        ui->myPlot->graph()->setPen(pen);
        ui->myPlot->graph()->setBrush(QBrush(QColor(255/4.0*gi,160,50,150)));
        // generate random walk data:
        QVector<double> time(250), value(250);
        for (int i=0; i<250; ++i)
        {
          time[i] = now + 24*3600*i;
          if (i == 0)
            value[i] = (i/50.0+1)*(rand()/(double)RAND_MAX-0.5);
          else
            value[i] = fabs(value[i-1])*(1+0.02/4.0*(4-gi)) + (i/50.0+1)*(rand()/(double)RAND_MAX-0.5);
        }
        ui->myPlot->graph()->setData(time, value);
      }
      // configure bottom axis to show date and time instead of number:
      ui->myPlot->xAxis->setTickLabelType(QCPAxis::ltDateTime);
      ui->myPlot->xAxis->setDateTimeFormat("MMMM\nyyyy");
      // set a more compact font size for bottom and left axis tick labels:
      ui->myPlot->xAxis->setTickLabelFont(QFont(QFont().family(), 8));
      ui->myPlot->yAxis->setTickLabelFont(QFont(QFont().family(), 8));
      // set a fixed tick-step to one tick per month:
      ui->myPlot->xAxis->setAutoTickStep(false);
      ui->myPlot->xAxis->setTickStep(2628000); // one month in seconds
      ui->myPlot->xAxis->setSubTickCount(3);
      // apply manual tick and tick label for left axis:
      ui->myPlot->yAxis->setAutoTicks(false);
      ui->myPlot->yAxis->setAutoTickLabels(false);
      ui->myPlot->yAxis->setTickVector(QVector<double>() << 5 << 55);
      ui->myPlot->yAxis->setTickVectorLabels(QVector<QString>() << "Not so\nhigh" << "Very\nhigh");
      // set axis labels:
      ui->myPlot->xAxis->setLabel("Date");
      ui->myPlot->yAxis->setLabel("Random wobbly lines value");
      // make top and right axes visible but without ticks and labels:
      ui->myPlot->xAxis2->setVisible(true);
      ui->myPlot->yAxis2->setVisible(true);
      ui->myPlot->xAxis2->setTicks(false);
      ui->myPlot->yAxis2->setTicks(false);
      ui->myPlot->xAxis2->setTickLabels(false);
      ui->myPlot->yAxis2->setTickLabels(false);
      // set axis ranges to show all data:
      ui->myPlot->xAxis->setRange(now, now+24*3600*249);
      ui->myPlot->yAxis->setRange(0, 60);
      // show legend:
      ui->myPlot->legend->setVisible(true);


}
