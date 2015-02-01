import QtQuick 2.2
import QtQuick.Controls 1.1

ApplicationWindow {
    visible: true
    width: 800
    height: 480
    title: qsTr("Hello World")

    menuBar: MenuBar {
        Menu {
            title: qsTr("File")
            MenuItem {
                text: qsTr("&Open")
                onTriggered: console.log("Open action triggered");
            }
            MenuItem {
                text: qsTr("Exit")
                onTriggered: Qt.quit();
            }
        }
    }

    Row {
        id: rowStages
        x: 0
        y: 0
        width: 800
        height: 71
        transformOrigin: Item.Center
        layoutDirection: Qt.RightToLeft
        spacing: 121
        z: 0

        Text {
            id: text6
            text: qsTr("Chill")
            verticalAlignment: Text.AlignTop
            horizontalAlignment: Text.AlignLeft
            z: 2
            font.pixelSize: 12
        }

        Text {
            id: text5
            text: qsTr("Boil")
            z: 2
            font.pixelSize: 12
        }

Text {
    id: text4
    text: qsTr("Sparge")
    z: 2
    font.pixelSize: 12
}

Text {
    id: text3
        text: qsTr("Mash")
        z: 2
        font.pixelSize: 12
}

Text {
    id: text2
    text: qsTr("Prep")
    z: 2
    font.pixelSize: 12
}

Text {
    id: text1
    text: qsTr("Recipe")
    z: 2
    font.pixelSize: 12
    }





    }

    Grid {
        id: gridRecipe
        x: 0
        y: 72
        width: 800
        height: 408
    }
}
