#ifndef COUNTER_H
#define COUNTER_H

#include <QObject>

class Counter : public QObject {
    Q_OBJECT
    // টাইপ 'type' এর বদলে 'int' এবং সিগন্যালের সঠিক নাম দেওয়া হলো
    Q_PROPERTY(int count READ count WRITE setCount NOTIFY countChanged FINAL)

private:
    int m_value = 0; // ইনিশিয়াল ভ্যালু 0 রাখা ভালো

public:
    explicit Counter(QObject *parent = nullptr) : QObject(parent) {}

    // Getter ফাংশন
    int count() const {
        return m_value;
    }

    // Setter ফাংশন
    void setCount(int value) {
        if (m_value != value) {
            m_value = value;
            emit countChanged();
        }
    }

    // QML থেকে কল করার জন্য ফাংশন
    Q_INVOKABLE void increment() {
        m_value += 1;
        emit countChanged(); // সঠিক সিগন্যাল কল করা হলো
    }

signals:
    void countChanged();
};

#endif // COUNTER_H