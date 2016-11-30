#ifndef SERIALREADER_H
#define SERIALREADER_H

#include <QSerialPort>
#include <QObject>
#include <QByteArray>
#include <QList>

class SERIALREADER : public QObject
{
    Q_OBJECT
public:
    SERIALREADER(QObject* parent = nullptr);
    ~SERIALREADER();
    bool open(QSerialPort::OpenMode openmode);
    bool close();
    unsigned long long availableData(QByteArray& data);
    QString selectPort();
    QString portName() const;
private:
    QByteArray* m_data;
    QSerialPort* m_serialPort;
private slots:
    void handleReadyRead();
    void handleError(QSerialPort::SerialPortError error);
signals:
};

#endif // SERIALREADER_H