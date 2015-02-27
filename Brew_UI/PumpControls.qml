import QtQuick 2.0
import Material 0.1
    Column{
        anchors.centerIn: parent
        spacing: 40
        Button{
            id: id_openCloseValve
            text: "Open/Close Valve"
            elevation: 1 //Makes a raised button
            onClicked: snackbar.open("Valve Opened")

        }
        Button{
            id: btn_startStopPump
            text: "Start/Stop Pump"
            elevation: 1 //Makes a raised button
            onClicked: snackbar.open("Pump Started")
        }
    }


