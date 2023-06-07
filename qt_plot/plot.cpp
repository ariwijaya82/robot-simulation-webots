#include "plot.hpp"

const int MaxDataPoints = 1000;
const double TimeStep = 0.01;
const double UpdateInterval = 500;  // milliseconds

RealTimePlot::RealTimePlot(QWidget* parent) : QWidget(parent) {
    setFixedSize(800, 600);
    setWindowTitle("Real-Time Plot");

    // Create a timer to update the plot
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &RealTimePlot::updatePlot);
    timer->start(UpdateInterval);

    // Start the time counter
    currentTime = 0;

    // Initialize the data array
    // dataPoints.reserve(MaxDataPoints);
}

void RealTimePlot::paintEvent(QPaintEvent*) {
    QPainter painter(this);

    // Clear the background
    painter.fillRect(rect(), Qt::white);

    // Set up the plot area
    int margin = 20;
    int plotWidth = width() - 2 * margin;
    int plotHeight = height() - 2 * margin;
    QRect plotRect(margin, margin, plotWidth, plotHeight);

    // Draw the plot border
    painter.setPen(Qt::black);
    painter.drawRect(plotRect);

    // Set up the plot axes and labels
    painter.setFont(QFont("Arial", 8));
    painter.drawText(plotRect, Qt::AlignBottom | Qt::AlignHCenter, "Time");
    painter.drawText(plotRect, Qt::AlignLeft | Qt::AlignVCenter, "Value");

    // Draw the plot data
    painter.setPen(Qt::blue);
    for (int i = 1; i < dataPoints.size(); ++i) {
      int x1 = plotRect.left() + dataPoints[i - 1].x() * 10;
      int y1 = plotRect.bottom() - dataPoints[i - 1].y() * 10;
      int x2 = plotRect.left() + dataPoints[i].x() * 10;
      int y2 = plotRect.bottom() - dataPoints[i].y() * 10;
      painter.drawLine(x1, y1, x2, y2);
    }
}

void RealTimePlot::updatePlot() {
    update();
}

void RealTimePlot::addData(int x, int y) {
    // Generate new data point
    dataPoints.append(QPointF(x, y));

    // Remove old data if exceeding the maximum number of data points
    // if (dataPoints.size() > MaxDataPoints) {
    //     dataPoints.removeFirst();
    // }
}