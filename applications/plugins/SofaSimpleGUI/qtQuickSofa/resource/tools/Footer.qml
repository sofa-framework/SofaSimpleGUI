import QtQuick 2.0
import QtQuick.Controls 1.0
import QtQuick.Layouts 1.0

Rectangle {
    id: base

    gradient: Gradient {
        GradientStop {position: 0.0; color: "lightgrey"}
        GradientStop {position: 1.0; color: "white"}
    }

    RowLayout {
        anchors.fill: parent

        Rectangle {
            color: Qt.rgba(0.0, 0.0, 0.0, 0.0)
            Layout.fillWidth: true
            Layout.fillHeight: true
            width: 10

            Label {
                anchors.centerIn: parent
                horizontalAlignment: Text.AlignHCenter
                text: "FPS"
            }
        }

        Rectangle {
            color: Qt.rgba(0.75, 0.75, 0.75, 1.0)
            Layout.fillHeight: true
            width: 5
        }

        Rectangle {
            color: Qt.rgba(0.0, 0.0, 0.0, 0.0)
            Layout.fillWidth: true
            Layout.fillHeight: true
            width: 10

            Label {
                anchors.centerIn: parent
                horizontalAlignment: Text.AlignHCenter
                text: "Time"
            }
        }

        Rectangle {
            color: Qt.rgba(0.75, 0.75, 0.75, 1.0)
            Layout.fillHeight: true
            width: 5
        }

        Rectangle {
            color: Qt.rgba(0.0, 0.0, 0.0, 0.0)
            Layout.fillWidth: true
            Layout.fillHeight: true
            width: 80
        }
    }
}
