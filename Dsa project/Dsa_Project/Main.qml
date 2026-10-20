import QtQuick
import QtQuick.Layouts
import QtQuick.Controls.Basic

ApplicationWindow {
    visible: true
    width: 500
    height: 500
    color: "#1f1f1f"
    title: 'First dsa project'

    ColumnLayout {
        anchors.centerIn: parent
        spacing: 20

        Text {
            text: qsTr("Counter application")
            color: "#fff"
            font.pixelSize: 20
            font.bold: true
            Layout.alignment: Qt.AlignHCenter
        }

        Text {
            // value এর বদলে count প্রপার্টি ব্যবহার করা হলো
            text: backendCount.count
            color: "#fff"
            font.pixelSize: 24
            font.bold: true
            Layout.alignment: Qt.AlignHCenter
        }

        Button {
            id: countBtn
            text: qsTr("+")
            Layout.alignment: Qt.AlignHCenter
            background: Rectangle {
                implicitWidth: 100
                implicitHeight: 40
                color: "#774baa"
                radius: 10
            }
            onClicked: {
                backendCount.increment();
            }
        }
    }
}