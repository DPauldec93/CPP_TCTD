#include "videostream.h"
#include "ui_videostream.h"

#include <QDebug>
#include <QString>

#include <map>
#include <iostream>

using namespace std;

VideoStream::VideoStream(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::VideoStream)
{
    ui->setupUi(this);

    webcam.open(0);

    if (!webcam.isOpened())
    {
        qDebug() << "camera not opened";
    }
    else
    {
        m_pTimer = new QTimer(this);
        connect(m_pTimer, SIGNAL(timeout()), this, SLOT(processAndUpdateGui()));
        m_pTimer->start(20);
        ui->btn_start->setDisabled(true);
    }
}

VideoStream::~VideoStream()
{
    delete ui;
}

void VideoStream::processAndUpdateGui()
{
    //credits: https://www.youtube.com/watch?v=0ONxIy8itRA(till line no.45)
    webcam.read(matoriginal);
    if (matoriginal.empty())
    {
        qDebug() << "Empty image";
        return;
    }

    cv::cvtColor(matoriginal, matoriginal, cv::COLOR_BGR2RGB);//setting original image from webcam
    QImage imgOriginal((uchar*)matoriginal.data, matoriginal.cols, matoriginal.rows, matoriginal.step, QImage::Format_RGB888);
    ui->lbl_image->setPixmap(QPixmap::fromImage(imgOriginal));
}

void VideoStream::on_btn_start_clicked()
{
    if (!m_pTimer->isActive())
    {
        m_pTimer->start(20);
    }
    ui->btn_stop->setDisabled(false);
    ui->btn_start->setDisabled(true);
}

void VideoStream::on_btn_stop_clicked()
{
    if (m_pTimer->isActive())
    {
        m_pTimer->stop();
    }
    ui->btn_stop->setDisabled(true);
    ui->btn_start->setDisabled(false);
}

void VideoStream::on_slider_brightness_sliderMoved(int position)
{
    cv::Mat brightImage;
    matoriginal.convertTo(brightImage, -1, 1, position);
    QImage imgOriginal((uchar*)brightImage.data, brightImage.cols, brightImage.rows, brightImage.step, QImage::Format_RGB888);
    ui->lbl_image->setPixmap(QPixmap::fromImage(imgOriginal));
}

void VideoStream::on_slider_contrast_sliderMoved(int position)
{

}
