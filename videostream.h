#ifndef VIDEOSTREAM_H
#define VIDEOSTREAM_H

#include <QWidget>
#include <QTimer>

#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

QT_BEGIN_NAMESPACE
namespace Ui { class VideoStream; }
QT_END_NAMESPACE

class VideoStream : public QWidget
{
    Q_OBJECT

public:
    VideoStream(QWidget *parent = nullptr);
    ~VideoStream();

private:
    Ui::VideoStream *ui;

    cv::VideoCapture webcam; ///< instance to capture the webcam instance
    cv::Mat matoriginal; ///< Mat image instance for original image from webcam

    QImage imgOriginal;///< QImage instance for original image
    QTimer *m_pTimer;///< QTimer instance to show continous picture frames from webcam

private slots:
    /**
     * @brief processAndUpdateGui - timout slot to set image from webcam
     */
    void processAndUpdateGui();

    void on_btn_start_clicked();
    void on_btn_stop_clicked();
    void on_slider_brightness_sliderMoved(int position);
    void on_slider_contrast_sliderMoved(int position);
};
#endif // VIDEOSTREAM_H
